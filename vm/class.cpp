#include "class.hpp"
#include "method_table.hpp"
#include "method.hpp"
#include "string.hpp"

namespace marius {
  Class::Class(Class* cls, String& name)
    : MemoryObject(cls)
    , name_(name)
    , superclass_(0)
  {}

  Method* Class::lookup(String& name) {
    Method* meth;

    Class* cls = this;

    while(true) {
      meth = cls->method_table_.lookup(name);
      if(meth) return meth;
      if(!superclass_) break;
      cls = superclass_;
    }

    return 0;
  }

  void Class::add_method(const char* name, SimpleFunc func) {
    Method* meth = new Method(func);

    String& s = String::internalize(name);

    method_table_.add(s, meth);
  }

  void Class::add_native_method(const char* name, Code& code) {
    Method* meth = new Method(code);

    String& s = String::internalize(name);

    method_table_.add(s, meth);
  }

  static Class** base_classes_;

  void Class::init_base(Class** base) {
    base_classes_ = base;
  }

  Class* Class::base_class(int idx) {
    return base_classes_[idx];
  }
}
