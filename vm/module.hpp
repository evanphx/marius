#ifndef MODULE_HPP
#define MODULE_HPP

#include "method_table.hpp"
#include "simple_func.hpp"
#include "memory_object.hpp"
#include "attributes.hpp"

namespace marius {
  class GCImpl;

  class Module : public MemoryObject, public Attributes {
    friend class GCImpl;

  public:
    Module(State& S, Class* mod, String& name);

    Method* lookup(String& name);
    void add_method(State& S, const char* name, SimpleFunc func, int arity);
    void add_native_method(State& S, const char* name, Method* m);

    static Class* init(State& S, Environment& env);
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
