#ifndef STRING_MAP_HPP
#define STRING_MAP_HPP

#include <map>

#include "ref.hpp"
#include "string.hpp"

namespace marius {
  template <typename T>
    struct StringMap {
      struct less {
        bool operator()(const ref<String>& a, const ref<String>& b) {
          return a.ptr() < b.ptr();
        }
      };

      typedef std::map<ref<String>, T, less> type;
    };
}

#endif
