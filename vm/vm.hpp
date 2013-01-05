#ifndef VM_HPP
#define VM_HPP

#include "oop.hpp"

namespace marius {
  const static int cInitialStack = 4096;

  class Code;
  class String;
  class Environment;
  class State;

  class VM {
    OOP* stack_;
    bool debug_;

  public:
    VM(bool debug=false);

    OOP run(State& S, Code& code);
    OOP run(State& S, Code& code, OOP* fp);
    OOP run_method(State& S, OOP recv, String& name, int argc, OOP* argv);
    OOP load_named(State& S, String& name);
  };
}

#endif
