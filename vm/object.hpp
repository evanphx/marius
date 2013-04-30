#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace r5 {
  class State;
  class Class;

  class Object {
  public:
    static void init(State& S, Class* o);
  };
}

#endif
