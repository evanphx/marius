#include "state.hpp"

#include "vm.hpp"
#include "environment.hpp"
#include "module.hpp"
#include "class.hpp"
#include "handle_scope.hpp"
#include "dictionary.hpp"

namespace r5 {
  State::State(VM& vm, Environment& env, Settings& set)
    : vm_(vm)
    , env_(env)
    , settings_(set)
    , importer_(0)
    , handles_(0)
    , gc_(vm.gc())
  {}

  void State::check() {
    if(vm_.gc().gc_soon()) {
      vm_.gc().collect(*this);
    }
  }

  Handle State::new_module(const char* c_name) {
    String* name = String::internalize(*this, c_name);

    option<OOP> val = env().modules()->get(name);
    if(val.set_p()) {
      return handle(*this, *val);
    }

    Class* cls = env_.lookup(*this, "Module").as_class();
    Module* m = new(*this) Module(*this, cls, name);

    env().modules()->set(*this, name, m);

    return handle(*this, m);
  }

  Handle State::new_class(Handle mod, const char* name) {
    String* s = String::internalize(*this, name);

    Class* sup = env_.lookup(*this, "Object").as_class();
    Class* cls = new(*this) Class(*this, sup, s);

    mod->as_module()->set_attribute(*this, s, cls);

    return handle(*this, cls);
  }

  void State::add_method(Handle cls, const char* name, SimpleFunc ptr,
                         int arity)
  {
    cls->as_class()->add_method(*this, name, ptr, arity);
  }

  void State::add_class_method(Handle cls, const char* name, SimpleFunc ptr,
                               int arity)
  {
    cls->as_class()->add_class_method(*this, name, ptr, arity);
  }
}
