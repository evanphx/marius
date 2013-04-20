#ifndef STATE_HPP
#define STATE_HPP

#include "handle_sets.hpp"
#include "gc.hpp"
#include "handle.hpp"
#include "simple_func.hpp"

namespace r5 {
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
    GC& gc_;
  public:

    State(VM& vm, Environment& env, Settings& set);

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

    HandleSets& handle_sets() {
      return handle_sets_;
    }

    void* allocate(size_t size) {
      return gc_.allocate(size);
    }

    void pin(void* ptr) {
      gc_.pin(ptr);
    }

    void check();

    Handle new_module(const char* name);
    Handle new_class(Handle mod, const char* name);
    void add_method(Handle mod, const char* name, SimpleFunc ptr, int arity);
  };
}

inline void* operator new(size_t size, r5::State& S) {
  return S.allocate(size);
}

inline void* operator new[](size_t size, r5::State& S) {
  return S.allocate(size);
}

#endif
