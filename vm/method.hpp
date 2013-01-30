#ifndef METHOD_HPP
#define METHOD_HPP

#include "oop.hpp"
#include "simple_func.hpp"
#include "memory_object.hpp"

namespace marius {
  class VM;
  class Environment;
  class Code;
  class Closure;

  class Method {
    SimpleFunc func_;
    Code* code_;
    int arity_;
    OOP* closed_over_;
    Closure* closure_;

  public:
    Method(SimpleFunc func, int arity, Closure* closure=0);
    Method(Code& code, Closure* closure=0);

    static Method* wrap(Code& code, Method* meth);

    Code* code() {
      return code_;
    }

    Closure* closure() {
      return closure_;
    }

    OOP closed_over_variable(int depth, int idx);
    void set_closed_over_variable(int depth, int idx, OOP val);

    OOP run(State& S, OOP recv, Arguments& args);
  };
}

#endif
