#include "trait.hpp"

namespace marius {
  void Trait::add_native_method(State& S, String* name, Method* m) {
    method_table_->add(S, name, m);
  }
}
