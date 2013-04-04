#ifndef UNWIND_HPP
#define UNWIND_HPP

#include "oop.hpp"
#include "unwind.hpp"

#include "gc_allocated.hpp"

#include <string>

namespace marius {
  class Unwind : public GCAllocated {
    std::string message_;

  public:

    std::string& message() {
      return message_;
    }

    static OOP import_error(State& S, String* n);
    static OOP arg_error(State& S, int expected, int actual);
    static OOP name_error(State& S, String* name);
    static OOP generic_error(State& S, String* str);
  };
}

#endif
