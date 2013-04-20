#ifndef GC_ALLOCATED_HPP
#define GC_ALLOCATED_HPP

#include <stddef.h>
#include "util/address.hpp"

namespace r5 {
  class State;

  class GCAllocated {
    void* operator new(size_t size);

  public:
    void* operator new(size_t size, State& S);

    inline void* operator new(size_t size, memory::Address addr) {
      return addr.ptr();
    }
  };
}

#endif
