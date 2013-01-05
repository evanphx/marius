#include "string.hpp"

#include <map>
#include <string>

namespace marius {

  std::map<std::string, String> mapping_;

  String& String::internalize(std::string str) {
    std::map<std::string, String>::iterator i = mapping_.find(str);
    if(i != mapping_.end()) return (*i).second;

    mapping_.insert(mapping_.end(),
        std::map<std::string, String>::value_type(str, String(str.c_str())));

    String& s = mapping_.at(str);

    return s;
  }
}
