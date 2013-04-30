#include "integer.hpp"
#include "state.hpp"
#include "class.hpp"
#include "module.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "environment.hpp"

namespace r5 {
  namespace {
    Handle int_cast(State& S, Handle recv, Arguments& args) {
      Handle obj = args[0];

      if(obj->type() == OOP::eInteger) return obj;

      Handle ret = args.setup(obj).apply(String::internalize(S, "to_s"));

      check(ret->type() == OOP::eInteger);

      return ret;
    }

    Handle int_plus(State& S, Handle recv, Arguments& args) {
      if(args.count() == 0) return handle(S, OOP::nil());

      int val = recv->int_value() + args[0]->int_value();
      return handle(S, OOP::integer(val));
    }

    Handle int_minus(State& S, Handle recv, Arguments& args) {
      if(args.count() == 0) return handle(S, OOP::nil());

      int val = recv->int_value() - args[0]->int_value();
      return handle(S, OOP::integer(val));
    }

    Handle int_to_s(State& S, Handle recv, Arguments& args) {
      char buf[128];

      snprintf(buf, sizeof(buf), "%d", recv->int_value());
      return handle(S, String::internalize(S, buf));
    }

    Handle int_equal(State& S, Handle recv, Arguments& args) {
      bool q = recv->int_value() == args[0]->int_value();
      return handle(S, q ? OOP::true_() : OOP::false_());
    }

    Handle int_lt(State& S, Handle recv, Arguments& args) {
      bool q = recv->int_value() < args[0]->int_value();
      return handle(S, q ? OOP::true_() : OOP::false_());
    }

    Handle int_gt(State& S, Handle recv, Arguments& args) {
      bool q = recv->int_value() > args[0]->int_value();
      return handle(S, q ? OOP::true_() : OOP::false_());
    }
  }

  Class* Integer::init(State& S, Environment* env) {
    Class* i = env->new_class(S, "Integer");
    i->add_class_method(S, "cast", int_cast, 1);
    i->add_method(S, "+", int_plus, 1);
    i->add_method(S, "-", int_minus, 1);
    i->add_method(S, "to_s", int_to_s, 0);
    i->add_method(S, "==", int_equal, 1);
    i->add_method(S, "<", int_lt, 1);
    i->add_method(S, ">", int_gt, 1);

    return i;
  }
}
