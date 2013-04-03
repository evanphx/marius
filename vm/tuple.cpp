#include "tuple.hpp"
#include "state.hpp"

namespace marius {
  Tuple::Tuple(State& S, size_t size)
    : data_(new(S) OOP[size])
    , size_(size)
  {}

  Tuple* Tuple::make(State& S, OOP* e, unsigned size) {
    Tuple* t = new(S) Tuple(S, size);
    for(unsigned i = 0; i < size; i++) {
      t->set(i, e[i]);
    }

    return t;
  }

  void Tuple::set(size_t idx, OOP val) {
    if(idx < size_) {
      data_[idx] = val;
    }
  }

  OOP Tuple::get(size_t idx) {
    if(idx < size_) {
      return data_[idx];
    }

    return OOP::nil();
  }
};
