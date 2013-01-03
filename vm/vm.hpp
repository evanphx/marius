#ifndef VM_HPP
#define VM_HPP

#include "oop.hpp"

namespace marius {
  const static int cInitialStack = 4096;

  class Code;
  class String;
  class Environment;

  class VM {
    OOP* stack_;

  public:
    VM();

    OOP run(Environment& env, Code& code);
    OOP run(Environment& env, Code& code, OOP* fp);
    OOP run_method(Environment& env, OOP recv, String& name, int argc, OOP* argv);
    OOP load_named(Environment& env, String& name);
  };
}

#endif
