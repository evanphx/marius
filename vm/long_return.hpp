#ifndef LONG_RETURN_HPP
#define LONG_RETURN_HPP

#include "oop.hpp"

namespace marius {
  class Method;

  class LongReturn {
    OOP val_;

    friend class GCImpl;
  public:
    LongReturn(OOP v)
      : val_(v)
    {}

    OOP val() {
      return val_;
    }

    static OOP make(State& S, OOP val, Method* meth);
  };
}

#endif
