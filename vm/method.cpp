#include "method.hpp"
#include "vm.hpp"

namespace marius {
  Method::Method(SimpleFunc func)
    : func_(func)
    , code_(0)
  {}

  Method::Method(Code& code)
    : func_(0)
    , code_(&code)
  {}

  OOP Method::run(Environment& env, VM* vm, OOP recv, int argc, OOP* fp) {
    if(func_) {
      return func_(env, recv, argc, fp);
    } else if(code_) {
      return vm->run(env, *code_, fp);
    }

    return OOP::nil();
  }
}
