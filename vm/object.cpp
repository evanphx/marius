#include "object.hpp"
#include "state.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "class.hpp"

namespace r5 {

  namespace {
    Handle object_methods(State& S, Handle recv, Arguments& args) {
      return handle(S, recv->klass()->methods(S));
    }

    Handle object_print(State& S, Handle recv, Arguments& args) {
      (*recv).print();
      return recv;
    }

    Handle object_equal(State& S, Handle recv, Arguments& args) {
      return handle(S, recv->equal(*args[0]) ? OOP::true_() : OOP::false_());
    }

    Handle object_kind_of(State& S, Handle recv, Arguments& args) {
      Class* chk = args[0]->as_class();
      Class* cls = recv->klass();

      while(cls) {
        if(cls == chk) return handle(S, OOP::true_());
        cls = cls->superclass();
      }

      return handle(S, OOP::false_());
    }

    Handle object_to_s(State& S, Handle recv, Arguments& args) {
      char buf[512];
      buf[0] = 0;
      sprintf(buf, "#<%s>", recv->klass()->name()->c_str());

      return handle(S, String::internalize(S, buf));
    }

    Handle init_instance(State& S, Handle recv, Arguments& args) {
      return recv;
    }

  }

  void Object::init(State& S, Class* o) {
    o->add_method(S, "print", object_print, 0);
    o->add_method(S, "kind_of?", object_kind_of, 1);
    o->add_method(S, "==", object_equal, 1);
    o->add_method(S, "to_s", object_to_s, 0);

    o->add_method(S, "initialize", init_instance, -1);
    o->add_method(S, "methods", object_methods, 0);
  }
}
