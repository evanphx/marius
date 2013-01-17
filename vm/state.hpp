#ifndef STATE_HPP
#define STATE_HPP

#include "handle_sets.hpp"

namespace marius {
  class Environment;
  class VM;
  class Settings;
  class User;
  class HandleScope;

  class State {
    VM& vm_;
    Environment& env_;
    Settings& settings_;
    User* importer_;
    HandleScope* handles_;
    HandleSets handle_sets_;

  public:

    State(VM& vm, Environment& env, Settings& set)
      : vm_(vm)
      , env_(env)
      , settings_(set)
      , importer_(0)
      , handles_(0)
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

    User* importer() {
      return importer_;
    }

    HandleSet* pull_set() {
      return handle_sets_.pull();
    }

    void set_importer(User* obj) {
      importer_ = obj;
    }

    HandleScope* set_handles(HandleScope* scope) {
      HandleScope* cur = handles_;
      handles_ = scope;
      return cur;
    }

    HandleScope* handles() {
      return handles_;
    }

  };
}

#endif
