#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <stdint.h>
#include <unistd.h>

#include "oop.hpp"

namespace marius {
  class Tuple {
    OOP* data_;
    size_t size_;

  public:
    Tuple(size_t size);

    size_t size() {
      return size_;
    }

    void set(size_t idx, OOP val);
    OOP get(size_t idx);
  };
}

#endif
