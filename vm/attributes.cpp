#include "attributes.hpp"

namespace marius {
  OOP Attributes::attribute(String& name, bool* found) {
    Bindings::iterator i = attributes_.find(name);
    if(i == attributes_.end()) {
      if(found) *found = false;
      return OOP::nil();
    }

    if(found) *found = true;
    return i->second;
  }

  void Attributes::set_attribute(String& name, OOP val) {
    attributes_[name] = val;
  }
}
