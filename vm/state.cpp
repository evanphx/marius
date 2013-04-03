#include "state.hpp"

#include "vm.hpp"

namespace marius {
  State::State(VM& vm, Environment& env, Settings& set)
    : vm_(vm)
    , env_(env)
    , settings_(set)
    , importer_(0)
    , handles_(0)
    , gc_(vm.gc())
    , last_fp(0)
  {}

  void State::check() {
    if(vm_.gc().gc_soon()) {
      vm_.gc().collect(*this);
    }
  }
}
