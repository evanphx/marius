#include "attributes.hpp"

namespace marius {
  OOP Attributes::attribute(String* name, bool* found) {
    option<OOP> v = attributes_.find(name);
    if(v.set_p()) {
      if(found) *found = true;
      return *v;
    }

    if(found) *found = false;
    return OOP::nil();
  }

  void Attributes::set_attribute(State& S, String* name, OOP val) {
    attributes_.set(S, name, val);
  }
}
