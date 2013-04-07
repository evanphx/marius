#ifndef BINDINGS_HPP
#define BINDINGS_HPP

#include "util/option.hpp"

#include "oop.hpp"

#include "gc_allocated.hpp"

namespace marius {
  class String;
  class State;
  class GCImpl;

  class Bindings {
    struct Entry : public GCAllocated {
      String* key;
      OOP val;
      Entry* next;

      Entry(String* k, OOP v)
        : key(k)
        , val(v)
        , next(0)
      {}
    };

    friend class GCImpl;

    Entry** entries_;
    unsigned capa_;
    unsigned size_;

    static const unsigned cDefaultCapa = 8;

  public:
    Bindings(State& S);
    option<OOP> find(String* name);
    void set(State& S, String* name, OOP val);
  };
}

#endif
