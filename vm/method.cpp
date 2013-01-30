#include "method.hpp"
#include "vm.hpp"
#include "state.hpp"
#include "closure.hpp"
#include "unwind.hpp"

namespace marius {
  Method::Method(SimpleFunc func, int arity, Closure* closure)
    : func_(func)
    , code_(0)
    , arity_(arity)
    , closed_over_(0)
    , closure_(closure)
  {}

  Method::Method(Code& code, Closure* closure)
    : func_(0)
    , code_(&code)
    , arity_(code.arity())
    , closure_(closure)
  {
    if(code.closed_over_vars() == 0) {
      closed_over_ = 0;
    } else {
      closed_over_ = new OOP[code.closed_over_vars()];
    }
  }

  Method* Method::wrap(Code& code, Method* meth) {
    Closure* c = new Closure(code.closed_over_vars(), meth->closure_);
    return new Method(code, c);
  }

  OOP Method::closed_over_variable(int depth, int idx) {
    return closure_->get_at_depth(depth, idx);
  }

  void Method::set_closed_over_variable(int depth, int idx, OOP val) {
    closure_->set_at_depth(depth, idx, val);
  }

  OOP Method::run(State& S, OOP recv, Arguments& args) {
    if(arity_ > 0 && args.count() != arity_) {
      return Unwind::arg_error(arity_, args.count());
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
