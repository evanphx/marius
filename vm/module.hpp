#ifndef MODULE_HPP
#define MODULE_HPP

#include "method_table.hpp"
#include "simple_func.hpp"
#include "memory_object.hpp"

namespace marius {
  class Module : public MemoryObject {
  public:
    Module(Class* cls, Class* mod, String& name);

    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func);
    void add_native_method(const char* name, Code& code);

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
