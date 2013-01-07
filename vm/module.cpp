#include "module.hpp"
#include "method.hpp"

namespace marius {
  Method* Module::lookup(String& name) {
    return method_table_.lookup(name);
  }

  void Module::add_method(const char* name, SimpleFunc func) {
    Method* meth = new Method(func);

    String& s = String::internalize(name);

    method_table_.add(s, meth);
  }


}
