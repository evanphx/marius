#include "module.hpp"
#include "method.hpp"
#include "class.hpp"
#include "environment.hpp"

namespace marius {
  namespace {
    Handle module_add(State& S, Handle recv, Arguments& args) {
      assert(args.count() == 2);

      String& name = args[0]->as_string();
      Code& code = args[1]->as_code();

      Module* mod = recv->as_module();

      mod->add_native_method(name.c_str(), code);

      return recv;
    }

    Handle module_access(State& S, Handle recv, Arguments& args) {
      assert(args.count() == 1);

      String& name = args[0]->as_string();

      return handle(S, recv->attribute(name, 0));
    }
  }

  Class* Module::init(Environment& env) {
    Class* mod = env.lookup("Module").as_class();
    mod->add_method("add_method", module_add);
    mod->add_method("::", module_access);
    return mod;
  }

  Module::Module(Class* cls, Class* mod, String& name)
    : MemoryObject(new Class(cls, mod, name))
  {}

  Method* Module::lookup(String& name) {
    return klass()->lookup(name);
  }

  void Module::add_method(const char* name, SimpleFunc func) {
    klass()->add_method(name, func);
  }

  void Module::add_native_method(const char* name, Code& code) {
    klass()->add_native_method(name, code);
  }

}
