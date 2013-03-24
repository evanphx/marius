#include "tuple.hpp"

namespace marius {
  Tuple::Tuple(size_t size)
    : data_(new OOP[size])
    , size_(size)
  {}

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
