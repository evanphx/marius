#ifndef SIMPLE_FUNC_HPP
#define SIMPLE_FUNC_HPP

#include "oop.hpp"
#include "arguments.hpp"
#include "handle.hpp"

namespace marius {
  class State;

  typedef Handle (*SimpleFunc)(State& S, Handle recv, Arguments& args);
}

#endif
