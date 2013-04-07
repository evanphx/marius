#ifndef METHOD_TABLE_HPP
#define METHOD_TABLE_HPP

#include <map>

#include "string_map.hpp"
#include "oop.hpp"

#include "util/option.hpp"

namespace marius {
  class String;
  class Method;

  class MethodTable {
    struct Entry : public GCAllocated {
      String* key;
      Method* method;
      Entry* next;

      Entry(String* k, Method* v)
        : key(k)
        , method(v)
        , next(0)
      {}
    };

    friend class GCImpl;

    Entry** entries_;
    unsigned capa_;
    unsigned size_;

    static const int cDefaultCapa = 8;

  public:
    MethodTable(State& S);
    option<Method*> lookup(String* name);
    void add(State& S, String* name, Method* m);

    OOP methods(State& S);
  };
}

#endif
