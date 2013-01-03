#ifndef MEMORY_OBJECT_HPP
#define MEMORY_OBJECT_HPP

namespace marius {
  class Class;
  class Environment;

  class MemoryObject {
    Class* klass_;

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
