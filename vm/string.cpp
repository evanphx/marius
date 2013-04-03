#include "string.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "environment.hpp"
#include "class.hpp"
#include "method.hpp"

#include <map>
#include <string>

namespace marius {

  std::map<std::string, String*> mapping_;

  String& String::internalize(State& S, std::string str) {
    std::map<std::string, String*>::iterator i = mapping_.find(str);
    if(i != mapping_.end()) return *((*i).second);

    String* obj = new(S) String(str.c_str());

    mapping_.insert(mapping_.end(),
        std::map<std::string, String*>::value_type(str, obj));

    return *obj;
  }

  String& String::convert(State& S, OOP obj) {
    if(obj.type() == OOP::eString) {
      return obj.as_string();
    }

    Method* meth = obj.find_method(String::internalize(S, "to_s"));
    check(meth);

    Arguments args(S, 0, S.last_fp);
    OOP ret = meth->run(S, obj, args);
    
    return ret.as_string();
  }

  unsigned String::hash() {
    if(sizeof(void*) == 8) {
      unsigned hv[2];
      MurmurHash3_x64_128(c_str(), bytelen_, bytelen_, hv);
      return hv[0];
    } else {
      unsigned hv;
      MurmurHash3_x86_32(c_str(), bytelen_, bytelen_, &hv);
      return hv;
    }
  }

  bool String::equal(String& o) {
    if(bytelen_ != o.bytelen_) return false;
    return memcmp(c_str(), o.c_str(), bytelen_) == 0;
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

    Handle prefix_p(State& S, Handle recv, Arguments& args) {
      String& s = recv->as_string();
      String& s2 = args[0]->as_string();

      if(strncmp(s.c_str(), s2.c_str(), s2.bytelen()) == 0) {
        return handle(S, OOP::true_());
      } else {
        return handle(S, OOP::false_());
      }
    }
  }

  void String::init(State& S) {
    Class* str = S.env().lookup(S, "String").as_class();

    str->add_method(S, "bytesize", byte_size, 0);
    str->add_method(S, "size", char_size, 0);
    str->add_method(S, "prefix?", prefix_p, 1);
  }
}
