#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>

#include "oop.hpp"
#include "string_map.hpp"

#include "gc.hpp"

namespace r5 {
  class String;
  class Class;
  class State;
  class Module;
  class Closure;
  class GCImpl;
  class Dictionary;
  class List;

  class Environment {
    Module* top_;
    Closure* globals_;
    Dictionary* modules_;
    List* args_;
    Dictionary* sys_;

    static bool cDefaultDev;
    bool dev_;

    friend class GCImpl;
  public:
    Environment(Module* m=0, bool d=cDefaultDev)
      : top_(m)
      , globals_(0)
      , dev_(d)
    {}

    Closure* globals() {
      return globals_;
    }

    Module* top() {
      return top_;
    }

    Dictionary* modules() {
      return modules_;
    }

    List* args() {
      return args_;
    }

    OOP lookup(String* name);
    OOP lookup(State& S, const char* str);

    Class* new_class(State& S, const char* name, Class* sup=0);

    void init_ontology(State& S);

    void print();

    void bind(State& S, String* name, OOP val);

    void import_args(State& S, char** args, int count);
    Code* frozen_enumerable(State& S);

    void init_builtin_extensions(State& S);
  };
}

#endif
