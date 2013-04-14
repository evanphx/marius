#include "gc_allocated.hpp"
#include "state.hpp"

namespace r5 {
  void* GCAllocated::operator new(size_t s, State& S) {
    return S.allocate(s);
  }
}
