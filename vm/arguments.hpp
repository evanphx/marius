#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "state.hpp"
#include "handle.hpp"

namespace marius {
  class Arguments {
    State& S_;
    OOP* fp_;
    int argc_;

  public:

    Arguments(State& S, int argc, OOP* fp)
      : S_(S)
      , fp_(fp)
      , argc_(argc)
    {}

    OOP* frame() {
      return fp_;
    }

    int count() {
      return argc_;
    }

    Handle self() {
      return handle(S_, fp_[-1]);
    }

    Handle operator[](int idx) {
      check(idx < argc_);
      return handle(S_, fp_[idx]);
    }
  };
}

#endif
