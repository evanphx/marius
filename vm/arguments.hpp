#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "state.hpp"
#include "handle.hpp"
#include "handle_scope.hpp"
#include "code.hpp"
#include "util/option.hpp"

namespace r5 {
  class Arguments {
    State& S_;
    OOP* fp_;
    int argc_;
    option<STuple*> keywords_;

  public:

    Arguments(State& S, int argc, OOP* fp, option<STuple*> keys)
      : S_(S)
      , fp_(fp)
      , argc_(argc)
      , keywords_(keys)
    {}

    Arguments(State& S, int argc, OOP* fp)
      : S_(S)
      , fp_(fp)
      , argc_(argc)
    {}

    OOP* frame() {
      return fp_;
    }

    OOP* rest() {
      return fp_ + argc_;
    }

    int count() {
      return argc_;
    }

    Handle self() {
      return handle(S_, fp_[-1]);
    }

    option<STuple*>& keywords() {
      return keywords_;
    }

    Handle operator[](int idx) {
      check(idx < argc_);
      return handle(S_, fp_[idx]);
    }

    Arguments shift() {
      return Arguments(S_, argc_-1, fp_+1);
    }

    Arguments& forward(OOP recv) {
      fp_[-1] = recv;
      return *this;
    }

    Arguments& forward(Handle recv) {
      fp_[-1] = *recv;
      return *this;
    }

    Arguments setup(OOP recv) {
      OOP* fp = rest();
      fp[0] = recv;

      return Arguments(S_, 0, fp+1);
    }

    Arguments setup(OOP recv, OOP arg) {
      OOP* fp = rest();
      fp[0] = recv;
      fp[1] = arg;

      return Arguments(S_, 1, fp+1);
    }

    Arguments setup(Handle recv) {
      OOP* fp = rest();
      fp[0] = *recv;

      return Arguments(S_, 0, fp+1);
    }

    Handle apply(String* name);
  };
}

#endif
