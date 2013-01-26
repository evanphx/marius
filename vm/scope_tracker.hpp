#ifndef SCOPE_TRACKER_HPP
#define SCOPE_TRACKER_HPP

#include "code.hpp"

namespace marius {
  class LocalMap;

  namespace ast {
    class Node;
  }

  void calculate_locals(ast::Node* top, ArgMap& globals, LocalMap& locals);
}

#endif
