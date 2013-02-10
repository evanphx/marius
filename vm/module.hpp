#ifndef MODULE_HPP
#define MODULE_HPP

#include "method_table.hpp"
#include "simple_func.hpp"
#include "memory_object.hpp"
#include "attributes.hpp"

namespace marius {
  class Module : public MemoryObject, public Attributes {
    typedef StringMap<OOP>::type Bindings;
    Bindings attributes_;

  public:
    Module(Class* mod, String& name);

    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func, int arity);
    void add_native_method(const char* name, Method* m);

    static Class* init(Environment& env);
  };

  class ModuleBuilder {
    Module* module_;

  public:
    ModuleBuilder(Module* mod)
      : module_(mod)
    {}

    Module* module() {
      return module_;
    }
  };
}

#endif
