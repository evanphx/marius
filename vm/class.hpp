#ifndef CLASS_HPP
#define CLASS_HPP

#include "oop.hpp"
#include "simple_func.hpp"
#include "method_table.hpp"
#include "memory_object.hpp"

namespace marius {
  class Method;
  class String;
  class MethodTable;

  class Class : public MemoryObject {
    String& name_;
    Class* superclass_;
    MethodTable method_table_;

  public:
    Class(Class* cls, String& name);

    String& name() {
      return name_;
    }

    static void init_base(Class* i, Class* c, Class* n, Class* s);
    static Class* integer_class();
    static Class* class_class();
    static Class* nil_class();
    static Class* string_class();

    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func);
    void add_native_method(const char* name, Code& code);

  };
}

#endif
