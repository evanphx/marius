#ifndef TRAIT_HPP
#define TRAIT_HPP

#include "gc_allocated.hpp"
#include "attributes.hpp"
#include "method_table.hpp"
#include "state.hpp"

namespace r5 {
  class String;

  class Trait : public GCAllocated, public Attributes {
    String* name_;
    MethodTable* method_table_;
    Tuple* sends_;

    friend class GCImpl;

  public:
    Trait(State& S, String* name, Tuple* tup)
      : Attributes(S)
      , name_(name)
      , method_table_(new(S) MethodTable(S))
      , sends_(tup)
    {}

    String* name() {
      return name_;
    }

    Tuple* sends() {
      return sends_;
    }

    MethodTable::Iterator iterator() {
      return MethodTable::Iterator(method_table_);
    }

    void add_native_method(State& S, String* name, Method* m);
  };
}

#endif
