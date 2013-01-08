#ifndef SIMPLE_FUNC_HPP
#define SIMPLE_FUNC_HPP

#include "oop.hpp"
#include "arguments.hpp"

namespace marius {
  class State;

  typedef OOP (*SimpleFunc)(State& S, OOP recv, Arguments& args);
}

#endif
