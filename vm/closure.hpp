#ifndef CLOSURE_HPP
#define CLOSURE_HPP

#include "oop.hpp"

#include "gc_allocated.hpp"

namespace marius {
  class GCImpl;

  class Closure : public GCAllocated {
    Closure* parent_;
    int size_;
    OOP* values_;

    friend class GCImpl;

  public:
    Closure(int size, Closure* parent=0)
      : parent_(parent)
      , size_(size)
      , values_(new OOP[size])
    {}

    OOP get(unsigned int idx) {
      check(idx < size_);

      return values_[idx];
    }

    OOP get_at_depth(unsigned int dep, unsigned int idx) {
      Closure* c = this;

      while(dep-- > 0) {
        c = c->parent_;
        if(!c) return OOP::nil();
      }

      return c->get(idx);
    }

    void set(unsigned int idx, OOP val) {
      check(idx < size_);

      values_[idx] = val;
    }

    void set_at_depth(unsigned int dep, unsigned int idx, OOP val) {
      Closure* c = this;

      while(dep-- > 0) {
        c = c->parent_;
        if(!c) return;
      }

      c->set(idx, val);
    }
  };
}

#endif
