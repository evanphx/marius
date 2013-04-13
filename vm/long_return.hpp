#ifndef LONG_RETURN_HPP
#define LONG_RETURN_HPP

#include "oop.hpp"

namespace marius {
  class Method;
  class Closure;

  class LongReturn {
    OOP val_;
    Closure* target_;

    friend class GCImpl;
  public:
    LongReturn(OOP v, Closure* t)
      : val_(v)
      , target_(t)
    {}

    OOP val() {
      return val_;
    }

    Closure* target() {
      return target_;
    }

    static OOP make(State& S, OOP val, Method* meth);
  };
}

#endif
