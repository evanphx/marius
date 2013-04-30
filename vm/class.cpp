#include "class.hpp"
#include "method_table.hpp"
#include "method.hpp"
#include "string.hpp"
#include "trait.hpp"
#include "list.hpp"
#include "tuple.hpp"
#include "exception.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "environment.hpp"
#include "user.hpp"
#include "vm.hpp"

namespace r5 {
  Class::Class(State& S, enum Boot, Class* cls, Class* sup, String* name)
    : MemoryObject(cls)
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
    , method_table_(new(S) MethodTable(S))
    , traits_(new(S) List(S))
  {}

  Class::Class(State& S, Class* sup, String* name)
    : MemoryObject(new(S) Class(S, Class::Boot,
                          sup->klass()->klass(),  sup->klass(),
                          Class::metaclass_name(S, name)))
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
    , method_table_(new(S) MethodTable(S))
    , traits_(new(S) List(S))
  {}

  String* Class::metaclass_name(State& S, String* name) {
    return String::internalize(S, std::string("<MetaClass:") + name->c_str() + ">");
  }

  Method* Class::lookup(String* name) {
    option<Method*> meth;

    Class* cls = this;

    while(true) {
      meth = cls->method_table_->lookup(name);
      if(meth.set_p()) return *meth;
      cls = cls->superclass_;
      if(!cls) break;
    }

    return 0;
  }

  void Class::add_method(State& S, const char* name,
                         SimpleFunc func, int arity)
  {
    String* s = String::internalize(S, name);

    Method* meth = new(S) Method(name_, func, arity);

    method_table_->add(S, s, meth);
  }

  void Class::add_native_method(State& S, const char* name, Method* meth) {
    String* s = String::internalize(S, name);

    method_table_->add(S, s, meth);
  }

  void Class::add_class_method(State& S, const char* name,
                               SimpleFunc func, int arity)
  {
    klass()->add_method(S, name, func, arity);
  }

  void Class::add_native_class_method(State& S, const char* name, Method* meth)
  {
    klass()->add_native_method(S, name, meth);
  }

  bool Class::instance_method_p(String* name) {
    return lookup(name) != 0;
  }

  OOP Class::uses_trait(State& S, Trait* trait) {
    MethodTable::Iterator i = trait->iterator();

    while(i.next()) {
      if(!instance_method_p(i.key())) {
        method_table_->add(S, i.key(), i.method());
      }
    }

    traits_->push(S, trait);

    return OOP::nil();
  }

  OOP Class::check_traits(State& S) {
    for(unsigned i = 0; i < traits_->size(); i++) {
      Trait* t = traits_->get(i).as_trait();
      Tuple* s = t->sends();

      for(size_t j = 0; j < s->size(); j++) {
        String* name = s->get(j).as_string();
        if(!instance_method_p(name)) {
          return OOP::make_unwind(
                  Exception::create(S, "TraitError",
                    "Missing required method '%s'", name->c_str()));
        }
      }
    }

    return OOP::nil();
  }

  static Class** base_classes_;

  void Class::init_base(Class** base) {
    base_classes_ = base;
  }

  Class* Class::base_class(int idx) {
    return base_classes_[idx];
  }

  OOP Class::methods(State& S) {
    return method_table_->methods(S);
  }

  namespace {
    Handle class_new_subclass(State& S, Handle recv, Arguments& args) {
      String* name = args[0]->as_string();

      return handle(S, OOP(S.env().new_class(S, name->c_str(), recv->as_class())));
    }

    Handle add_method_m(State& S, Handle recv, Arguments& args) {
      String* name = args[0]->as_string();

      Method* m = args[1]->as_method();

      recv->as_class()->add_native_method(S, name->c_str(), m);

      return handle(S, OOP::nil());
    }

    Handle add_scoped_method(State& S, Handle recv, Arguments& args) {
      String* scope = args[0]->as_string();
      String* name = args[1]->as_string();

      Method* m = args[2]->as_method();

      if(scope->equal("self")) {
        recv->as_class()->add_native_class_method(S, name->c_str(), m);
      } else {
        recv->as_class()->add_native_method(S, name->c_str(), m);
      }

      return handle(S, OOP::nil());
    }

    Handle alias_method(State& S, Handle recv, Arguments& args) {
      String* from = args[0]->as_string();
      String* to = args[1]->as_string();

      Method* m = recv->as_class()->lookup(from);

      check(m);

      recv->as_class()->add_native_method(S, to->c_str(), m);

      return handle(S, OOP::nil());
    }

    Handle uses_trait_m(State& S, Handle recv, Arguments& args) {
      Trait* trait = args[0]->as_trait();

      recv->as_class()->uses_trait(S, trait);

      return handle(S, OOP::nil());
    }

    Handle new_instance(State& S, Handle recv, Arguments& args) {
      Arguments na = args.setup(recv);

      Handle hndl = na.apply(String::internalize(S, "allocate"));
      Handle ret = args.forward(hndl).apply(String::internalize(S, "initialize"));

      if(ret->unwind_p()) return handle(S, ret);
      return hndl;
    }

    Handle alloc_instance(State& S, Handle recv, Arguments& args) {
      Class* cls = recv->as_class();

      return handle(S, OOP(new(S) User(S, cls)));
    }

    Handle run_class_body(State& S, Handle recv, Arguments& args) {
      Class* cls = recv->as_class();
      Method* m =  args[0]->as_method();

      std::string n = m->scope()->c_str();

      m = new(S) Method(
          String::internalize(S, n + "." + cls->name()->c_str()),
          m->code(), m->closure());

      Arguments out_args = args.setup(cls);

      Handle ret = handle(S, S.vm().run(S, m, out_args));

      if(ret->unwind_p()) return ret;

      OOP chk = cls->check_traits(S);

      if(chk.unwind_p()) return handle(S, chk);

      return ret;
    }

    Handle class_tequal(State& S, Handle recv, Arguments& args) {
      Class* cls = args[0]->klass();
      Class* chk = recv->as_class();

      while(cls) {
        if(cls == chk) return handle(S, OOP::true_());
        cls = cls->superclass();
      }

      return handle(S, OOP::false_());
    }

    Handle class_subclass(State& S, Handle recv, Arguments& args) {
      Class* cls = recv->as_class()->superclass();
      Class* chk = args[0]->as_class();

      while(cls) {
        if(cls == chk) return handle(S, OOP::true_());
        cls = cls->superclass();
      }

      return handle(S, OOP::false_());

    }

    Handle class_name(State& S, Handle recv, Arguments& args) {
      Class* cls = recv->as_class();
      return handle(S, cls->name());
    }
  }

  void Class::init(State& S, Class* c) {
    c->add_method(S, "new_subclass", class_new_subclass, 1);
    c->add_method(S, "run_body", run_class_body, 1);

    c->add_method(S, "add_method", add_method_m, 2);
    c->add_method(S, "add_scope_method", add_scoped_method, 3);
    c->add_method(S, "alias_method", alias_method, 2);
    c->add_method(S, "uses", uses_trait_m, 1);
    c->add_method(S, "allocate", alloc_instance, 0);
    c->add_method(S, "new", new_instance, -1);

    c->add_method(S, "<", class_subclass, 1);
    c->add_method(S, "===", class_tequal, 1);
    c->add_method(S, "name", class_name, 0);
  }
}
