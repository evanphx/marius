#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>

#include "oop.hpp"
#include "string_map.hpp"

namespace marius {
  class String;
  class Class;

  class Environment {
    Environment* parent_;

    typedef StringMap<OOP>::type Bindings;
    Bindings binding_;

  public:
    Environment()
      : parent_(0)
    {}

    OOP lookup(String& name);

    Class* new_class(const char* name);
    void init_ontology();

    void print();

    void bind(String& name, OOP val) {
      binding_[name] = val;
    }
  };
}

#endif
