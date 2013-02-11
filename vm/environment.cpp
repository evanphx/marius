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

  Class* Environment::new_class(const char* name, Class* sup) {
    String& s = String::internalize(name);

    if(!sup) {
      sup = lookup("Class").as_class();
    }

    Class* cls = new Class(sup, s);

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

  static Handle class_new_subclass(State& S, Handle recv, Arguments& args) {
    String& name = args[0]->as_string();

    return handle(S, OOP(S.env().new_class(name.c_str(), recv->as_class())));
  }

  static Handle add_method(State& S, Handle recv, Arguments& args) {
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

  static Handle run_class_body(State& S, Handle recv, Arguments& args) {
    Class* cls = recv->as_class();
    Method* m =  args[0]->as_method();

    std::string n = m->scope().c_str();

    m = new Method(
                  String::internalize(n + "." + cls->name().c_str()),
                  *m->code(), m->closure());

    return handle(S, S.vm().run(S, m, args.frame()));
  }

  static Handle method_call(State& S, Handle recv, Arguments& args) {
    Method* m = recv->as_method();

    OOP* fp = args.frame();

    return handle(S, S.vm().run(S, m, fp));
  }

  static Handle io_puts(State& S, Handle recv, Arguments& args) {
    args[0]->print();
    return handle(S, OOP::nil());
  }

  Class* init_import(State& S);

  void Environment::init_ontology(State& S) {
    assert(!top_);

    String& on = String::internalize("Object");
    Class* o = new Class(Class::Boot, 0, 0, on);

    String& cn = String::internalize("Class");
    Class* c = new Class(Class::Boot, 0, o, cn);

    String& mn = String::internalize("MetaClass");
    Class* m = new Class(Class::Boot, 0, 0, mn);

    Class* mco = new Class(Class::Boot, m, c, Class::metaclass_name(on));
    o->klass_ = mco;

    Class* mcc = new Class(Class::Boot, m, mco, Class::metaclass_name(cn));
    c->klass_ = mcc;

    Class* mcm = new Class(Class::Boot, m, mco, Class::metaclass_name(mn));
    m->klass_ = mcm;

    Class* mod = new Class(o, String::internalize("Module"));

    top_ = new Module(mod, String::internalize("lang"));

    bind(cn, c);
    bind(mn, m);
    bind(String::internalize("Module"), mod);

    c->add_method("new_subclass", class_new_subclass, 1);
    c->add_method("run_body", run_class_body, 1);

    c->add_method("add_method", add_method, 2);
    c->add_method("new", new_instance, 0);

    Class* i = new_class("Integer");
    i->add_method("+", int_plus, 1);

    Class* n = new_class("NilClass");

    Class* s = new_class("String");

    Class* mc = new_class("Method");
    Class* d = new_class("Code");
    mc->add_method("eval", run_code, -1);
    mc->add_method("call", method_call, -1);

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

    Module* io = new Module(mod, io_n);
    io->add_method("puts", io_puts, 1);

    bind(io_n, io);

    Class* importer = init_import(S);

    String::init(S);
  
    globals_ = new Closure(4);
    globals_->set(0, o);
    globals_->set(1, io);
    globals_->set(2, c);
    globals_->set(3, importer);
  }
}
