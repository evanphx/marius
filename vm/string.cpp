#include "string.hpp"

#include <map>

namespace marius {

  std::map<const char*, String> mapping_;

  String& String::internalize(const char* str) {
    std::map<const char*, String>::iterator i = mapping_.find(str);
    if(i != mapping_.end()) return (*i).second;

    mapping_.insert(mapping_.end(),
        std::map<const char*, String>::value_type(str, String(str)));

    return mapping_.at(str);
  }
}
