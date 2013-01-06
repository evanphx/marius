#ifndef STRING_VECTOR_HPP
#define STRING_VECTOR_HPP

#include <vector>

#include "ref.hpp"

namespace marius {
  typedef std::vector<ref<String> > StringVector;
}

#endif
