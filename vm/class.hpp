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

    static void init_base(Class** tbl);

    static Class* base_class(int idx);

    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func);
    void add_native_method(const char* name, Code& code);

  };
}

#endif
