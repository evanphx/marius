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

  class Environment {
    Module* top_;

  public:
    Environment(Module* m=0)
      : top_(m)
    {}

    OOP lookup(String& name);
    OOP lookup(const char* str);

    Class* new_class(const char* name);

    void init_ontology(State& S);

    void print();

    void bind(String& name, OOP val);
  };
}

#endif
