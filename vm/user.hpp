#ifndef USER_HPP
#define USER_HPP

#include "memory_object.hpp"
#include "attributes.hpp"
#include "class.hpp"

namespace r5 {
  class GCImpl;

  class User : public MemoryObject, public Attributes {
    friend class GCImpl;

  public:
    User(State& S, Class* cls)
      : MemoryObject(cls)
      , Attributes(S)
    {}
  };
}

#endif
