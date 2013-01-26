#ifndef CLOSURE_HPP
#define CLOSURE_HPP

#include "oop.hpp"

namespace marius {
  class Closure {
    Closure* parent_;
    int size_;
    OOP* values_;

  public:
    Closure(int size, Closure* parent=0)
      : parent_(parent)
      , size_(size)
      , values_(new OOP[size])
    {}

    OOP get(unsigned int idx) {
      if(idx >= size_) return OOP::nil();
      return values_[idx];
    }

    OOP get_at_depth(unsigned int idx, unsigned int dep) {
      Closure* c = this;

      while(dep-- > 0) {
        c = c->parent_;
        if(!c) return OOP::nil();
      }

      return c->get(idx);
    }

    void set(unsigned int idx, OOP val) {
      if(idx >= size_) return;

      values_[idx] = val;
    }

    void set_at_depth(unsigned int idx, unsigned int dep, OOP val) {
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
