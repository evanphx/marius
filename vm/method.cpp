#include "method.hpp"
#include "vm.hpp"
#include "state.hpp"

namespace marius {
  Method::Method(SimpleFunc func)
    : func_(func)
    , code_(0)
  {}

  Method::Method(Code& code)
    : func_(0)
    , code_(&code)
  {}

  OOP Method::run(State& S, OOP recv, Arguments& args) {
    if(func_) {
      return func_(S, recv, args);
    } else if(code_) {
      return S.vm().run(S, *code_, args.frame());
    }

    return OOP::nil();
  }
}
