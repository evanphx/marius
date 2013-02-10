#include "module.hpp"
#include "method.hpp"
#include "class.hpp"
#include "environment.hpp"

namespace marius {
  namespace {
    Handle module_add(State& S, Handle recv, Arguments& args) {
      String& name = args[0]->as_string();
      Method* m = args[1]->as_method();

      Module* mod = recv->as_module();

      mod->add_native_method(name.c_str(), m);

      return recv;
    }

    Handle module_access(State& S, Handle recv, Arguments& args) {
      String& name = args[0]->as_string();

      return handle(S, recv->attribute(name, 0));
    }
  }

  Class* Module::init(Environment& env) {
    Class* mod = env.lookup("Module").as_class();
    mod->add_method("add_method", module_add, 2);
    mod->add_method("::", module_access, 1);
    return mod;
  }

  Module::Module(Class* mod, String& name)
    : MemoryObject(new Class(Class::Boot, mod->klass()->klass(), mod, name))
  {}

  Method* Module::lookup(String& name) {
    return klass()->lookup(name);
  }

  void Module::add_method(const char* name, SimpleFunc func, int arity) {
    klass()->add_method(name, func, arity);
  }

  void Module::add_native_method(const char* name, Method* m) {
    klass()->add_native_method(name, m);
  }

}
