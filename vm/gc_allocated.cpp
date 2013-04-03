#include "gc_allocated.hpp"
#include "state.hpp"

namespace marius {
  void* GCAllocated::operator new(size_t s, State& S) {
    return S.allocate(s);
  }
}
