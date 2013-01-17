#ifndef USER_HPP
#define USER_HPP

#include "memory_object.hpp"
#include "attributes.hpp"
#include "class.hpp"

namespace marius {
  class User : public MemoryObject, public Attributes {
  public:
    User(Class* cls)
      : MemoryObject(cls)
    {}
  };
}

#endif
