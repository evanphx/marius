#ifndef VM_HPP
#define VM_HPP

#include "oop.hpp"
#include "code.hpp"

#include "string_map.hpp"
#include "string_vector.hpp"

namespace marius {
  const static int cInitialStack = 4096;

  class Code;
  class String;
  class Environment;
  class State;
  class Method;

  class VM {
    OOP* stack_;
    bool debug_;

  public:
    VM(bool debug=false);

    OOP run(State& S, Code& code);
    OOP run(State& S, Code& code, OOP* fp);
    OOP run_method(State& S, OOP recv, String& name, int argc, OOP* argv);

    void reorg_args(OOP* fp, Method* meth, ArgMap& keywords);
    OOP run_kw_method(State& S, OOP recv, String& name, int argc, OOP* argv,
                      ArgMap& keywords);
    OOP load_named(State& S, String& name);
  };
}

#endif
