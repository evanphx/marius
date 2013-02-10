#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>

#include "oop.hpp"
#include "string_map.hpp"

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

    OOP lookup(String& name);
    OOP lookup(const char* str);

    Class* new_class(const char* name, Class* sup=0);

    void init_ontology(State& S);

    void print();

    void bind(String& name, OOP val);
  };
}

#endif
