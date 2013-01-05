#ifndef STATE_HPP
#define STATE_HPP

namespace marius {
  class Environment;
  class VM;

  class State {
    VM& vm_;
    Environment& env_;

  public:

    State(VM& vm, Environment& env)
      : vm_(vm)
      , env_(env)
    {}

    VM& vm() {
      return vm_;
    }
    Environment& env() {
      return env_;
    }
  };
}

#endif
