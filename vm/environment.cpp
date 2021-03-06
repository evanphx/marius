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
#include "trait.hpp"
#include "exception.hpp"
#include "compiler.hpp"
#include "arguments.hpp"
#include "integer.hpp"
#include "object.hpp"

#include <iostream>
#include <stdio.h>

namespace r5 {
  bool Environment::cDefaultDev = false;

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

  static Handle io_puts(State& S, Handle recv, Arguments& args) {
    puts(String::convert(S, args, args[0])->c_str());
    return handle(S, OOP::nil());
  }

  static Handle io_print(State& S, Handle recv, Arguments& args) {
    printf("%s", String::convert(S, args, args[0])->c_str());
    return handle(S, OOP::nil());
  }

  static Handle exc_message(State& S, Handle recv, Arguments& args) {
    Exception* exc = recv->exception();

    return handle(S, exc->message());
  }

  static Handle exc_show(State& S, Handle recv, Arguments& args) {
    Exception* exc = recv->exception();

    exc->show(S, "Error has occured: ");

    return recv;
  }

  static Handle true_to_s(State& S, Handle recv, Arguments& args) {
    return handle(S, String::internalize(S, "true"));
  }

  static Handle false_to_s(State& S, Handle recv, Arguments& args) {
    return handle(S, String::internalize(S, "false"));
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

    Class::init(S, c);
    Object::init(S, o);

    Class* trait = Trait::init(S, this);

    Class* i = Integer::init(S, this);

    Class* n = new_class(S, "NilClass");

    Class* s = new_class(S, "String");

    Class* d = new_class(S, "Code");
    Class* mc = Method::init(S, this);

    Class* t = new_class(S, "TrueClass");
    t->add_method(S, "to_s", true_to_s, 0);

    Class* f = new_class(S, "FalseClass");
    f->add_method(S, "to_s", false_to_s, 0);

    Class* tuple = Tuple::init(S, this);

    Class* dict = new_class(S, "Dictionary");
    Class* list = new_class(S, "List");

    modules_ = new(S) Dictionary(S);
    args_ = new(S) List(S);

    sys_ = new(S) Dictionary(S);

    sys_->set(S, String::internalize(S, "modules"), modules_);
    sys_->set(S, String::internalize(S, "args"), args_);

    Class* exc = new_class(S, "Exception");

    Class* rte = new_class(S, "RuntimeError", exc);
    Class* arg_err = new_class(S, "ArgumentError", rte);
    new_class(S, "ImportError", rte);
    Class* nme = new_class(S, "NoMethodError", rte);

    exc->add_method(S, "message", exc_message, 0);
    exc->add_method(S, "show", exc_show, 0);

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
    tbl[OOP::eTrait] = trait;

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

    globals_ = new(S) Closure(14);
    globals_->set(0, o);
    globals_->set(1, io);
    globals_->set(2, c);
    globals_->set(3, importer);
    globals_->set(4, dict);
    globals_->set(5, i);
    globals_->set(6, sys_);
    globals_->set(7, trait);
    globals_->set(8, arg_err);
    globals_->set(9, nme);
    globals_->set(10, exc);
    globals_->set(11, list);

    Code* enum_code = 0;

    if(dev_) {
      FILE* file = fopen("kernel/enumerable.mr", "r");
      check(file);

      Compiler compiler;

      check(compiler.compile(S,
             String::internalize(S, "kernel/enumerable.mr"), file));

      enum_code = compiler.code();
      fclose(file);
    } else {
      enum_code = frozen_enumerable(S);
    }

    run_top_code(S, enum_code);
    Trait* enum_ = lookup(S, "Enumerable").as_trait();

    tuple->uses_trait(S, enum_);

    init_builtin_extensions(S);

    S.set_importer(new(S) User(S, lookup(S, "Importer").as_class()));

    run_top_code(S, frozen_dir(S));

    {
#include "kernel/moment.mrc"
      run_top_code(S, Code::load_raw(S, (unsigned char*)data, data_size));
    }

    globals_->set(12, lookup(S, "Dir"));
    globals_->set(13, lookup(S, "Moment"));
  }

  void Environment::run_top_code(State& S, Code* code) {
    OOP* fp = S.vm().stack();
    fp[0] = top_;

    Method* mtop = new(S) Method(String::internalize(S, "__init__"),
                                 code, S.env().globals());

    Arguments args(S, 1, fp + 1);
    S.vm().run(S, mtop, args);
  }

  void Environment::import_args(State& S, char** args, int count) {
    for(int i = 0; i < count; i++) {
      args_->push(S, String::internalize(S, args[i]));
    }
  }

  Code* Environment::frozen_enumerable(State& S) {
#include "kernel/enumerable.mrc"
    return Code::load_raw(S, (unsigned char*)data, data_size);
  }

  Code* Environment::frozen_dir(State& S) {
#include "kernel/dir.mrc"
    return Code::load_raw(S, (unsigned char*)data, data_size);
  }
}
