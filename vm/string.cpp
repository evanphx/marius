#include "string.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "environment.hpp"
#include "class.hpp"

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

  namespace {
    Handle byte_size(State& S, Handle recv, Arguments& args) {
      String& s = recv->as_string();
      return handle(S, OOP::integer(s.bytelen()));
    }

    Handle char_size(State& S, Handle recv, Arguments& args) {
      String& s = recv->as_string();
      return handle(S, OOP::integer(s.charlen()));
    }
  }

  void String::init(State& S) {
    Class* str = S.env().lookup("String").as_class();

    str->add_method("bytesize", byte_size);
    str->add_method("size", char_size);
  }
}
