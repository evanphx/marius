#include "method.hpp"
#include "vm.hpp"
#include "state.hpp"
#include "closure.hpp"
#include "exception.hpp"
#include "arguments.hpp"
#include "environment.hpp"

namespace r5 {
  Method::Method(String* scope, SimpleFunc func, int arity, Closure* closure)
    : scope_(scope)
    , func_(func)
    , code_(0)
    , arity_(arity)
    , closure_(closure)
  {}

  Method::Method(String* scope, Code* code, Closure* closure)
    : scope_(scope)
    , func_(0)
    , code_(code)
    , arity_(code->arity())
    , closure_(closure)
  {}

  String* Method::name(State& S) {
    if(code_) {
      return code_->name();
    } else {
      return String::internalize(S, "__internal__");
    }
  }

  Closure* Method::return_to() {
    Closure* c = closure_;
    while(!c->return_to_p()) {
      c = c->parent();
      check(c);
    }

    return c;
  }

  OOP Method::closed_over_variable(int depth, int idx) {
    return closure_->get_at_depth(depth, idx);
  }

  void Method::set_closed_over_variable(int depth, int idx, OOP val) {
    closure_->set_at_depth(depth, idx, val);
  }

  OOP Method::run(State& S, Arguments& args) {
    if(arity_ > 0 && args.count() != arity_) {
      return OOP::make_unwind(
        Exception::create(S, "ArgumentError",
                                  "Expected %d, got %d", arity_, args.count()));
    }

    if(func_) {
      HandleScope scope(S);

      return *func_(S, args.self(), args);
    } else if(code_) {
      return S.vm().run(S, this, args);
    }

    return OOP::nil();
  }

  namespace {
    Handle run_code(State& S, Handle recv, Arguments& args) {
      Method* m = recv->as_method();

      Arguments out_args = args.shift();

      return handle(S, S.vm().run(S, m, out_args));
    }

    Handle method_call(State& S, Handle recv, Arguments& args) {
      Method* m = recv->as_method();

      return handle(S, S.vm().run(S, m, args));
    }
  }

  Class* Method::init(State& S, Environment* env) {
    Class* mc = env->new_class(S, "Method");

    mc->add_method(S, "eval", run_code, -1);
    mc->add_method(S, "call", method_call, -1);
    mc->add_method(S, "|", method_call, -1);

    return mc;
  }
}
