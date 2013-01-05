#ifndef SIMPLE_FUNC_HPP
#define SIMPLE_FUNC_HPP

#include "oop.hpp"

namespace marius {
  class State;

  typedef OOP (*SimpleFunc)(State& S, OOP recv, int argc, OOP* fp);
}

#endif
