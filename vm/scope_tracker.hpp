#ifndef SCOPE_TRACKER_HPP
#define SCOPE_TRACKER_HPP

#include "code.hpp"

namespace r5 {
  class LocalMap;

  namespace ast {
    class Node;
  }

  void calculate_locals(State& S, ast::Node* top, ArgMap& globals, LocalMap& locals);
}

#endif
