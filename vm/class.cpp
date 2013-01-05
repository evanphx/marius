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

  static Class* integer_class_;
  static Class* class_class_;
  static Class* nil_class_;
  static Class* str_class_;
  static Class* code_class_;

  void Class::init_base(Class* i, Class* c, Class* n, Class* s, Class* d) {
    integer_class_ = i;
    class_class_ = c;
    nil_class_ = n;
    str_class_ = s;
    code_class_ = d;
  }

  Class* Class::integer_class() {
    return integer_class_;
  }

  Class* Class::class_class() {
    return class_class_;
  }

  Class* Class::nil_class() {
    return nil_class_;
  }

  Class* Class::string_class() {
    return str_class_;
  }

  Class* Class::code_class() {
    return code_class_;
  }
}
