#ifndef GC_HPP
#define GC_HPP

#include "util/address.hpp"

namespace r5 {
  class GCImpl;
  class State;

  class GC {
    GCImpl* impl_;

  public:
    GC();
    memory::Address allocate(unsigned bytes);
    unsigned size(memory::Address addr);
    void pin(memory::Address);
    void collect(State& S);

    bool gc_soon();
  };
}

#endif
