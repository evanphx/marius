#ifndef STATE_HPP
#define STATE_HPP

namespace marius {
  class Environment;
  class VM;
  class Settings;

  class State {
    VM& vm_;
    Environment& env_;
    Settings& settings_;

  public:

    State(VM& vm, Environment& env, Settings& set)
      : vm_(vm)
      , env_(env)
      , settings_(set)
    {}

    VM& vm() {
      return vm_;
    }

    Environment& env() {
      return env_;
    }

    Settings& settings() {
      return settings_;
    }
  };
}

#endif
