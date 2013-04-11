#ifndef CLASS_HPP
#define CLASS_HPP

#include "oop.hpp"
#include "simple_func.hpp"
#include "method_table.hpp"
#include "memory_object.hpp"
#include "attributes.hpp"

namespace marius {
  class Method;
  class String;
  class MethodTable;
  class GCImpl;
  class Trait;

  class Class : public MemoryObject, public Attributes {
    String* name_;
    Class* superclass_;
    MethodTable* method_table_;

    friend class GCImpl;

  public:
    enum Boot { Boot };
    Class(State& S, Class* sup, String* name);
    Class(State& S, enum Boot, Class* cls, Class* sup, String* name);

    String* name() {
      return name_;
    }

    Class* superclass() {
      return superclass_;
    }

    static void init_base(Class** tbl);

    static Class* base_class(int idx);

    static String* metaclass_name(State& S, String* name);

    Method* lookup(String* name);
    void add_method(State& S, const char* name, SimpleFunc func, int arity);
    void add_native_method(State& S, const char* name, Method* meth);

    void add_class_method(State& S, const char* name, SimpleFunc func, int arity);
    OOP uses_trait(State& S, Trait* t);

    OOP methods(State& S);
  };
}

#endif
