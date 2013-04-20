#ifndef SIMPLE_FUNC_HPP
#define SIMPLE_FUNC_HPP

#include "handle.hpp"

namespace r5 {
  class State;
  class Arguments;

  typedef Handle (*SimpleFunc)(State& S, Handle recv, Arguments& args);
}

#endif
