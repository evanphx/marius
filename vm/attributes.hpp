#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include "oop.hpp"
#include "string_map.hpp"

namespace marius {
  class Attributes {
    typedef StringMap<OOP>::type Bindings;
    Bindings attributes_;

  public:
    OOP attribute(String& name, bool* found=0);
    void set_attribute(String& name, OOP val);
  };
}

#endif
