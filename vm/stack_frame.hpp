#ifndef STACK_FRAME_HPP
#define STACK_FRAME_HPP

namespace r5 {
  class Method;

  struct StackFrame {
    int ip;
    Method* method;
    Closure* closure;
  };
}

#endif
