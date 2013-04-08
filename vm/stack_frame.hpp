#ifndef STACK_FRAME_HPP
#define STACK_FRAME_HPP

namespace marius {
  class Method;

  struct StackFrame {
    int ip;
    Method* method;
    Closure* closure;
  };
}

#endif
