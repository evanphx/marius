#include "environment.hpp"
#include "string.hpp"
#include "class.hpp"
#include "code.hpp"
#include "state.hpp"
#include "vm.hpp"
#include "module.hpp"

#include <iostream>

namespace marius {
  OOP Environment::lookup(String& name) {
    Environment* env = this;

    while(env) {
      Bindings::iterator i = binding_.find(name);

      if(i != binding_.end()) return (*i).second;
      env = env->parent_;
    }

    return OOP::nil();
  }

  OOP Environment::lookup(const char* name) {
    return lookup(String::internalize(name));
  }

  Class* Environment::new_class(const char* name) {
    String& s = String::internalize(name);

    Class* obj = binding_[String::internalize("Class")].as_class();

    Class* cls = new Class(obj, s);

    binding_[s] = OOP(cls);

    return cls;
  }

  void Environment::print() {
    for(Bindings::iterator i = binding_.begin();
        i != binding_.end();
        ++i) {
      std::cout << (*i).first.val().c_str() << " => ";
      (*i).second.print();
    }
  }

  static OOP int_plus(State& S, OOP recv, Arguments& args) {
    if(args.count() == 0) return OOP::nil();

    int val = recv.int_value() + args[0].int_value();
    return OOP::integer(val);
  }

  static OOP class_new(State& S, OOP recv, Arguments& args) {
    assert(args.count() == 1);

    String& name = args[0].as_string();

    return OOP(S.env().new_class(name.c_str()));
  }

  static OOP add_method(State& S, OOP recv, Arguments& args) {
    assert(args.count() == 2);

    String& name = args[0].as_string();
    Code& code = args[1].as_code();

    recv.as_class()->add_native_method(name.c_str(), code);

    return OOP::nil();
  }

  static OOP new_instance(State& S, OOP recv, Arguments& args) {
    Class* cls = recv.as_class();

    return OOP(new MemoryObject(cls));
  }

  static OOP run_code(State& S, OOP recv, Arguments& args) {
    Code& code = recv.as_code();

    return S.vm().run(S, code, args.frame() + 1);
  }

  static OOP io_puts(State& S, OOP recv, Arguments& args) {
    assert(args.count() == 1);
    args[0].print();
    return OOP::nil();
  }

  void init_import(Environment& env, Class** tbl);

  void Environment::init_ontology() {
    String& mn = String::internalize("MetaClass");
    String& cn = String::internalize("Class");

    Class* m = new Class(0, mn);
    binding_[mn] = m;

    Class* c = new Class(m, cn);
    m->klass_ = c;
    binding_[cn] = c;

    m->add_method("new", class_new);

    c->add_method("add_method", add_method);
    c->add_method("new", new_instance);

    Class* i = new_class("Integer");
    i->add_method("+", int_plus);

    Class* n = new_class("NilClass");

    Class* s = new_class("String");

    Class* d = new_class("Code");
    d->add_method("eval", run_code);

    Class* t = new_class("TrueClass");
    Class* f = new_class("FalseClass");

    Class** tbl = new Class*[OOP::TotalTypes];

    tbl[OOP::eNil] = n;
    tbl[OOP::eClass] = c;
    tbl[OOP::eInteger] = i;
    tbl[OOP::eString] = s;
    tbl[OOP::eCode] = d;
    tbl[OOP::eUser] = 0;
    tbl[OOP::eTrue] = t;
    tbl[OOP::eFalse] = f;
    tbl[OOP::eUnwind] = new_class("Unwind");

    Class::init_base(tbl);

    Class* mod = Module::init(*this);

    String& io_n = String::internalize("io");

    Module* io = new Module(c, mod, io_n);
    io->add_method("puts", io_puts);

    binding_[io_n] = io;

    init_import(*this, tbl);
  }
}
