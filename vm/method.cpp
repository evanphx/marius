#include "method.hpp"
#include "vm.hpp"
#include "state.hpp"
#include "closure.hpp"
#include "unwind.hpp"

namespace marius {
  Method::Method(String& scope, SimpleFunc func, int arity, Closure* closure)
    : scope_(scope)
    , func_(func)
    , code_(0)
    , arity_(arity)
    , closure_(closure)
  {}

  Method::Method(String& scope, Code& code, Closure* closure)
    : scope_(scope)
    , func_(0)
    , code_(&code)
    , arity_(code.arity())
    , closure_(closure)
  {}

  String& Method::name(State& S) {
    if(code_) {
      return code_->name();
    } else {
      return String::internalize(S, "__internal__");
    }
  }

  OOP Method::closed_over_variable(int depth, int idx) {
    return closure_->get_at_depth(depth, idx);
  }

  void Method::set_closed_over_variable(int depth, int idx, OOP val) {
    closure_->set_at_depth(depth, idx, val);
  }

  OOP Method::run(State& S, OOP recv, Arguments& args) {
    if(arity_ > 0 && args.count() != arity_) {
      return Unwind::arg_error(S, arity_, args.count());
    }

    if(func_) {
      HandleScope scope(S);

      return *func_(S, handle(S, recv), args);
    } else if(code_) {
      return S.vm().run(S, this, args.frame());
    }

    return OOP::nil();
  }
}
