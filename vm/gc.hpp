#ifndef GC_HPP
#define GC_HPP

#include "util/address.hpp"

namespace marius {
  class GCImpl;
  class State;

  class GC {
    GCImpl* impl_;

  public:
    GC();
    memory::Address allocate(unsigned bytes);
    void collect(State& S);

    bool gc_soon();
  };
}

#endif
