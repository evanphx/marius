#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>

#include "oop.hpp"
#include "string_map.hpp"

#include "gc.hpp"

namespace marius {
  class String;
  class Class;
  class State;
  class Module;
  class Closure;

  class Environment {
    Module* top_;
    Closure* globals_;

  public:
    Environment(Module* m=0)
      : top_(m)
      , globals_(0)
    {}

    Closure* globals() {
      return globals_;
    }

    Module* top() {
      return top_;
    }

    OOP lookup(String& name);
    OOP lookup(State& S, const char* str);

    Class* new_class(State& S, const char* name, Class* sup=0);

    void init_ontology(State& S);

    void print();

    void bind(State& S, String& name, OOP val);

  };
}

#endif
