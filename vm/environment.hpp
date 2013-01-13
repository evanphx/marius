#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>

#include "oop.hpp"
#include "string_map.hpp"

namespace marius {
  class String;
  class Class;
  class State;

  class Environment {
    Environment* parent_;

    typedef StringMap<OOP>::type Bindings;
    Bindings binding_;

  public:
    Environment()
      : parent_(0)
    {}

    OOP lookup(String& name);
    OOP lookup(const char* str);

    Class* new_class(const char* name);
    void init_ontology(State& S);

    void print();

    void bind(String& name, OOP val) {
      binding_[name] = val;
    }
  };
}

#endif
