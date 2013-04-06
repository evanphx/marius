#ifndef STRING_MAP_HPP
#define STRING_MAP_HPP

#include <map>

#include "string.hpp"

namespace marius {
  template <typename T>
    struct StringMap {
      struct less {
        bool operator()(const String* a, const String* b) {
          return a->compare(b) < 0;
        }
      };

      typedef std::map<String*, T, less> type;
    };
}

#endif
