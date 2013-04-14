#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <stdint.h>
#include <unistd.h>

#include "oop.hpp"

#include "gc_allocated.hpp"

#include "handle.hpp"

namespace r5 {
  class GCImpl;

  class Tuple : public GCAllocated {
    OOP* data_;
    size_t size_;

    friend class GCImpl;

  public:
    Tuple(State& S, size_t size);

    size_t size() {
      return size_;
    }

    static Tuple* make(State& S, OOP* e, unsigned size);
    void set(size_t idx, OOP val);
    OOP get(size_t idx);
  };

  typedef TypedHandle<Tuple, OOP::eTuple> HTuple;
}

#endif
