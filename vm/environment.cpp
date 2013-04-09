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
#include "tuple.hpp"
#include "dictionary.hpp"
#include "list.hpp"

#include <iostream>
#include <stdio.h>

namespace marius {
  OOP Environment::lookup(String* name) {
    return top_->attribute(name);
  }

  OOP Environment::lookup(State& S, const char* name) {
    return lookup(String::internalize(S, name));
  }

  Class* Environment::new_class(State& S, const char* name, Class* sup) {
    String* s = String::internalize(S, name);

    if(!sup) {
      sup = lookup(S, "Object").as_class();
    }

    Class* cls = new(S) Class(S, sup, s);

    bind(S, s, cls);

    return cls;
  }

  void Environment::bind(State& S, String* name, OOP val) {
    top_->set_attribute(S, name, val);
  }

  static Handle int_cast(State& S, Handle recv, Arguments& args) {
    Handle obj = args[0];

    if(obj->type() == OOP::eInteger) return obj;

    Method* meth = obj->find_method(String::internalize(S, "to_s"));
    check(meth);

    Arguments out_args(S, 0, S.last_fp);
    OOP ret = meth->run(S, *obj, out_args);

    check(ret.type() == OOP::eInteger);

    return handle(S, ret);
  }

  static Handle int_plus(State& S, Handle recv, Arguments& args) {
    if(args.count() == 0) return handle(S, OOP::nil());

    int val = recv->int_value() + args[0]->int_value();
    return handle(S, OOP::integer(val));
  }

  static Handle int_to_s(State& S, Handle recv, Arguments& args) {
    char buf[128];

    snprintf(buf, sizeof(buf), "%d", recv->int_value());
    return handle(S, String::internalize(S, buf));
  }

  static Handle int_equal(State& S, Handle recv, Arguments& args) {
    bool q = recv->int_value() == args[0]->int_value();
    return handle(S, q ? OOP::true_() : OOP::false_());
  }

  static Handle class_new_subclass(State& S, Handle recv, Arguments& args) {
    String* name = args[0]->as_string();

    return handle(S, OOP(S.env().new_class(S, name->c_str(), recv->as_class())));
  }

  static Handle add_method(State& S, Handle recv, Arguments& args) {
    String* name = args[0]->as_string();

    Method* m = args[1]->as_method();

    recv->as_class()->add_native_method(S, name->c_str(), m);

    return handle(S, OOP::nil());
  }

  static Handle new_instance(State& S, Handle recv, Arguments& args) {
    Class* cls = recv->as_class();

    return handle(S, OOP(new(S) User(S, cls)));
  }

  static Handle class_subclass(State& S, Handle recv, Arguments& args) {
    Class* cls = recv->as_class()->superclass();
    Class* chk = args[0]->as_class();

    while(cls) {
      if(cls == chk) return handle(S, OOP::true_());
      cls = cls->superclass();
    }

    return handle(S, OOP::false_());

  }

  static Handle run_code(State& S, Handle recv, Arguments& args) {
    Method* m = recv->as_method();

    return handle(S, S.vm().run(S, m, args.frame() + 1));
  }

  static Handle run_class_body(State& S, Handle recv, Arguments& args) {
    Class* cls = recv->as_class();
    Method* m =  args[0]->as_method();

    std::string n = m->scope()->c_str();

    m = new(S) Method(
                  String::internalize(S, n + "." + cls->name()->c_str()),
                  *m->code(), m->closure());

    return handle(S, S.vm().run(S, m, args.frame()));
  }

  static Handle method_call(State& S, Handle recv, Arguments& args) {
    Method* m = recv->as_method();

    OOP* fp = args.frame();

    return handle(S, S.vm().run(S, m, fp));
  }

  static Handle io_puts(State& S, Handle recv, Arguments& args) {
    Handle arg = args[0];
    puts(String::convert(S, *arg)->c_str());
    return handle(S, OOP::nil());
  }

  static Handle io_print(State& S, Handle recv, Arguments& args) {
    Handle arg = args[0];
    printf("%s", String::convert(S, *arg)->c_str());
    return handle(S, OOP::nil());
  }

  static Handle object_methods(State& S, Handle recv, Arguments& args) {
    return handle(S, recv->klass()->methods(S));
  }

  static Handle tuple_find_all(State& S, Handle recv, Arguments& args) {
    Tuple* tup = recv->as_tuple();
    Method* m = args[0]->as_method();

    OOP* fp = args.frame() + 1;
    fp[-1] = OOP(m);

    std::vector<OOP> found;

    for(size_t i = 0; i < tup->size(); i++) {
      fp[0] = tup->get(i);
      OOP t = S.vm().run(S, m, fp);

      if(t.unwind_p()) {
        return handle(S, t);
      }

      if(t.true_condition_p()) {
        found.push_back(fp[0]);
      }
    }

    Tuple* out = new(S) Tuple(S, found.size());
    for(size_t i = 0; i < found.size(); i++) {
      out->set(i, found[i]);
    }

    return handle(S, OOP(out));
  }

  static Handle tuple_each(State& S, Handle recv, Arguments& args) {
    Tuple* tup = recv->as_tuple();
    Method* m = args[0]->as_method();

    OOP* fp = args.frame() + 1;
    fp[-1] = OOP(m);

    for(size_t i = 0; i < tup->size(); i++) {
      fp[0] = tup->get(i);
      S.vm().run(S, m, fp);
    }

    return recv;
  }

  static Handle tuple_equal(State& S, Handle recv, Arguments& args) {
    HTuple tup(recv);
    HTuple o(args[0]);

    if(tup->size() != o->size()) {
      return handle(S, OOP::false_());
    }

    size_t tot = tup->size();

    for(size_t i = 0; i < tot; i++) {
      OOP v = o->get(i);
      OOP ret = tup->get(i).call(S, String::internalize(S, "=="), &v, 1);
      if(!ret.true_condition_p()) return handle(S, OOP::false_());
    }

    return handle(S, OOP::true_());
  }

  static Handle object_print(State& S, Handle recv, Arguments& args) {
    (*recv).print();
    return recv;
  }

  static Handle object_kind_of(State& S, Handle recv, Arguments& args) {
    Class* chk = args[0]->as_class();
    Class* cls = recv->klass();

    while(cls) {
      if(cls == chk) return handle(S, OOP::true_());
      cls = cls->superclass();
    }

    return handle(S, OOP::false_());
  }

  Class* init_import(State& S);

  void Environment::init_ontology(State& S) {
    check(!top_);

    String* on = String::internalize(S, "Object");
    Class* o = new(S) Class(S, Class::Boot, 0, 0, on);

    String* cn = String::internalize(S, "Class");
    Class* c = new(S) Class(S, Class::Boot, 0, o, cn);

    String* mn = String::internalize(S, "MetaClass");
    Class* m = new(S) Class(S, Class::Boot, 0, 0, mn);

    Class* mco = new(S) Class(S, Class::Boot, m, c,
                              Class::metaclass_name(S, on));
    o->klass_ = mco;

    Class* mcc = new(S) Class(S, Class::Boot, m, mco,
                              Class::metaclass_name(S, cn));
    c->klass_ = mcc;

    Class* mcm = new(S) Class(S, Class::Boot, m, mco,
                              Class::metaclass_name(S, mn));
    m->klass_ = mcm;

    Class* mod = new(S) Class(S, o, String::internalize(S, "Module"));

    top_ = new(S) Module(S, mod, String::internalize(S, "lang"));

    bind(S, on, o);
    bind(S, cn, c);
    bind(S, mn, m);
    bind(S, String::internalize(S, "Module"), mod);

    o->add_method(S, "print", object_print, 0);
    o->add_method(S, "kind_of?", object_kind_of, 1);

    c->add_method(S, "new_subclass", class_new_subclass, 1);
    c->add_method(S, "run_body", run_class_body, 1);

    c->add_method(S, "add_method", add_method, 2);
    c->add_method(S, "new", new_instance, 0);

    c->add_method(S, "<", class_subclass, 1);

    o->add_method(S, "methods", object_methods, 0);

    Class* i = new_class(S, "Integer");
    i->add_class_method(S, "cast", int_cast, 1);
    i->add_method(S, "+", int_plus, 1);
    i->add_method(S, "to_s", int_to_s, 0);
    i->add_method(S, "==", int_equal, 1);

    Class* n = new_class(S, "NilClass");

    Class* s = new_class(S, "String");

    Class* mc = new_class(S, "Method");
    Class* d = new_class(S, "Code");
    mc->add_method(S, "eval", run_code, -1);
    mc->add_method(S, "call", method_call, -1);

    Class* t = new_class(S, "TrueClass");
    Class* f = new_class(S, "FalseClass");

    Class* tuple = new_class(S, "Tuple");
    tuple->add_method(S, "find_all", tuple_find_all, 1);
    tuple->add_method(S, "detect", tuple_find_all, 1);
    tuple->add_method(S, "each", tuple_each, 1);
    tuple->add_method(S, "==", tuple_equal, 1);

    Class* dict = new_class(S, "Dictionary");
    Class* list = new_class(S, "List");

    modules_ = new(S) Dictionary(S);
    args_ = new(S) List(S);

    sys_ = new(S) Dictionary(S);

    sys_->set(S, String::internalize(S, "modules"), modules_);
    sys_->set(S, String::internalize(S, "args"), args_);

    new_class(S, "ArgumentError");
    new_class(S, "RuntimeError");
    new_class(S, "ImportError");
    new_class(S, "NoMethodError");

    Class** tbl = new(S) Class*[OOP::TotalTypes];

    tbl[OOP::eNil] = n;
    tbl[OOP::eClass] = c;
    tbl[OOP::eInteger] = i;
    tbl[OOP::eString] = s;
    tbl[OOP::eCode] = d;
    tbl[OOP::eUser] = 0;
    tbl[OOP::eTrue] = t;
    tbl[OOP::eFalse] = f;
    tbl[OOP::eUnwind] = new_class(S, "Unwind");
    tbl[OOP::eMethod] = mc;
    tbl[OOP::eTuple] = tuple;
    tbl[OOP::eDictionary] = dict;
    tbl[OOP::eList] = list;

    Class::init_base(tbl);

    Module::init(S, *this);

    String* io_n = String::internalize(S, "io");

    Module* io = new(S) Module(S, mod, io_n);
    io->add_method(S, "puts", io_puts, 1);
    io->add_method(S, "print", io_print, 1);

    bind(S, io_n, io);

    Class* importer = init_import(S);

    String::init(S);

    Dictionary::init(S, dict);
    List::init(S, list);
  
    globals_ = new(S) Closure(7);
    globals_->set(0, o);
    globals_->set(1, io);
    globals_->set(2, c);
    globals_->set(3, importer);
    globals_->set(4, dict);
    globals_->set(5, i);
    globals_->set(6, sys_);
  }

  void Environment::import_args(State& S, char** args, int count) {
    for(int i = 0; i < count; i++) {
      args_->push(S, String::internalize(S, args[i]));
    }
  }
}
