#include "environment.hpp"
#include "string.hpp"
#include "class.hpp"
#include "code.hpp"
#include "state.hpp"
#include "vm.hpp"
#include "module.hpp"
#include "user.hpp"
#include "method.hpp"
#include "closure.hpp"

#include <iostream>

namespace marius {
  OOP Environment::lookup(String& name) {
    return top_->attribute(name);
  }

  OOP Environment::lookup(const char* name) {
    return lookup(String::internalize(name));
  }

  Class* Environment::new_class(const char* name) {
    String& s = String::internalize(name);

    Class* obj = lookup("Class").as_class();

    Class* cls = new Class(obj, s);

    bind(s, cls);

    return cls;
  }

  void Environment::bind(String& name, OOP val) {
    top_->set_attribute(name, val);
  }

  static Handle int_plus(State& S, Handle recv, Arguments& args) {
    if(args.count() == 0) return handle(S, OOP::nil());

    int val = recv->int_value() + args[0]->int_value();
    return handle(S, OOP::integer(val));
  }

  static Handle class_new(State& S, Handle recv, Arguments& args) {
    assert(args.count() == 1);

    String& name = args[0]->as_string();

    return handle(S, OOP(S.env().new_class(name.c_str())));
  }

  static Handle add_method(State& S, Handle recv, Arguments& args) {
    assert(args.count() == 2);

    String& name = args[0]->as_string();

    Method* m = args[1]->as_method();

    recv->as_class()->add_native_method(name.c_str(), m);

    return handle(S, OOP::nil());
  }

  static Handle new_instance(State& S, Handle recv, Arguments& args) {
    Class* cls = recv->as_class();

    return handle(S, OOP(new User(cls)));
  }

  static Handle run_code(State& S, Handle recv, Arguments& args) {
    Method* m = recv->as_method();

    return handle(S, S.vm().run(S, m, args.frame() + 1));
  }

  static Handle io_puts(State& S, Handle recv, Arguments& args) {
    assert(args.count() == 1);
    args[0]->print();
    return handle(S, OOP::nil());
  }

  void init_import(State& S);

  void Environment::init_ontology(State& S) {
    assert(!top_);

    String& mn = String::internalize("MetaClass");
    String& cn = String::internalize("Class");

    Class* m = new Class(0, mn);

    Class* c = new Class(m, cn);
    m->klass_ = c;

    Class* mod = new Class(c, String::internalize("Module"));

    top_ = new Module(c, mod, String::internalize("lang"));

    bind(cn, c);
    bind(mn, m);
    bind(String::internalize("Module"), mod);

    m->add_method("new", class_new);

    c->add_method("add_method", add_method);
    c->add_method("new", new_instance);

    Class* i = new_class("Integer");
    i->add_method("+", int_plus);

    Class* n = new_class("NilClass");

    Class* s = new_class("String");

    Class* mc = new_class("Method");
    Class* d = new_class("Code");
    mc->add_method("eval", run_code);

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
    tbl[OOP::eMethod] = mc;

    Class::init_base(tbl);

    Module::init(*this);

    String& io_n = String::internalize("io");

    Module* io = new Module(c, mod, io_n);
    io->add_method("puts", io_puts);

    bind(io_n, io);

    init_import(S);
  
    globals_ = new Closure(1);
    globals_->set(0, io);
  }
}
