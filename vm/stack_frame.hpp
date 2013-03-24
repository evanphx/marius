#ifndef STACK_FRAME_HPP
#define STACK_FRAME_HPP

namespace marius {
  class Method;

  struct StackFrame {
    Method* method;
  };
}

#endif
