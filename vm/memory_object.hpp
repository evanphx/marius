#ifndef MEMORY_OBJECT_HPP
#define MEMORY_OBJECT_HPP

#include "gc_allocated.hpp"

namespace r5 {
  class Class;
  class Environment;
  class GCImpl;

  class MemoryObject : public GCAllocated {
    Class* klass_;

    friend class GCImpl;

  public:
    MemoryObject(Class* cls)
      : klass_(cls)
    {}

    Class* klass() {
      return klass_;
    }

    friend class Environment;
  };
}

#endif
