#ifndef METHOD_HPP
#define METHOD_HPP

#include "oop.hpp"
#include "simple_func.hpp"

namespace marius {
  class VM;
  class Environment;
  class Code;

  class Method {
    SimpleFunc func_;
    Code* code_;

  public:
    Method(SimpleFunc func);
    Method(Code& code);

    OOP run(Environment& env, VM* vm, OOP recv, int argc, OOP* fp);
  };
}

#endif
