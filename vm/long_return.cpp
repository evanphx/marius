#include "long_return.hpp"
#include "state.hpp"
#include "method.hpp"

namespace r5 {
  OOP LongReturn::make(State& S, OOP val, Method* meth) {
    LongReturn* lr = new(S) LongReturn(val, meth->return_to());
    return lr;
  }
}
