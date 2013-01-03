#ifndef SIMPLE_FUNC_HPP
#define SIMPLE_FUNC_HPP

#include "oop.hpp"

namespace marius {
  class Environment;

  typedef OOP (*SimpleFunc)(Environment& env, OOP recv, int argc, OOP* fp);
}

#endif
