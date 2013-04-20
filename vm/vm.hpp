#ifndef VM_HPP
#define VM_HPP

#include "oop.hpp"
#include "code.hpp"

#include "string_map.hpp"
#include "string_vector.hpp"
#include "handle.hpp"

namespace r5 {
  const static int cInitialStack = 4096;

  class Code;
  class String;
  class Environment;
  class State;
  class Method;
  struct StackFrame;
  class FrameTracker;
  class Arguments;

  class VM {
    unsigned stack_size_;
    OOP* stack_;
    unsigned frames_size_;
    StackFrame* frames_;
    StackFrame* top_frame_;
    bool debug_;
    GC gc_;

    friend class GCImpl;

  public:
    VM(bool debug=false);

    GC& gc() {
      return gc_;
    }

    OOP* stack() {
      return stack_;
    }

    OOP run(State& S, Method* meth, Arguments& args);
    OOP run(State& S, Method* meth, OOP* fp, Arguments& args);
    OOP run_method(State& S, OOP recv,
                           String* name, int argc, OOP* argv);

    void reorg_args(OOP* fp, Method* meth, STuple* keywords);
    OOP run_kw_method(State& S, OOP recv,
                              String* name, int argc, OOP* argv,
                              STuple* keywords);
    OOP load_named(State& S, String* name);
    OOP load_attr(State& S, String* name, OOP recv, OOP* fp);

    String* as_string(OOP val);
    void print_call_stack(State& S);
    InvokeInfo* invoke_info(State& S);

    friend class FrameTracker;
  };
}

#endif
