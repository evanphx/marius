#ifndef STATE_HPP
#define STATE_HPP

namespace marius {
  class Environment;
  class VM;
  class Settings;
  class MemoryObject;

  class State {
    VM& vm_;
    Environment& env_;
    Settings& settings_;
    MemoryObject* importer_;

  public:

    State(VM& vm, Environment& env, Settings& set)
      : vm_(vm)
      , env_(env)
      , settings_(set)
      , importer_(0)
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

    MemoryObject* importer() {
      return importer_;
    }

    void set_importer(MemoryObject* obj) {
      importer_ = obj;
    }
  };
}

#endif
