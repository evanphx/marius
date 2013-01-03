#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>
#include "oop.hpp"

namespace marius {
  class String;
  class Class;

  class Environment {
    Environment* parent_;
    std::map<String*, OOP> binding_;

  public:
    Environment()
      : parent_(0)
    {}

    OOP lookup(String& name);

    Class* new_class(const char* name);
    void init_ontology();
  };
}

#endif
