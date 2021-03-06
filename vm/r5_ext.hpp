#ifndef EXT_HPP
#define EXT_HPP

#include "handle.hpp"
#include "state.hpp"
#include "string.hpp"
#include "arguments.hpp"
#include "simple_func.hpp"
#include "user.hpp"

namespace r5 {
  class State;

  class ExtInitializer {
  public:
    typedef void (*InitFunc)(State& S);
    InitFunc init;
    ExtInitializer* next;

    static ExtInitializer* first;

    ExtInitializer(InitFunc func)
      : init(func)
      , next(first)
    {
      first = this;
    }
  };

  namespace ext {

    extern unsigned TagBase;

    template <typename T>
    struct Tag {
      static unsigned id() {
        static unsigned i = 0;
        static bool set = false;

        if(!set) {
          set = true;
          i = ++TagBase;
        }

        return i;
      }
    };

    String* string(State& S, const char* name, int sz);
    String* string(State& S, void* ptr, int sz);
    String* string(State& S, char* ptr);

    Handle allocate_sized(State& S, Class* cls, unsigned bytes, unsigned tag);

    inline Handle wrap(State& S, int val) {
      return handle(S, OOP::integer(val));
    }

    template <typename T>
    inline T clamp(State&, T v, T m) {
      if(v > m) return m;
      return v;
    }

    template <typename T>
      inline T* ptr(State&, T& o) {
        return &o;
      }

    inline Handle to_bool(State& S, bool v) {
      return handle(S, v ? OOP::true_() : OOP::false_());
    }

    template <typename T>
      Handle allocate(State& S, Class* cls) {
        return allocate_sized(S, cls, sizeof(T), Tag<T>::id());
      }

    template <typename T>
      T* unwrap(Handle handle) {
        User* u = handle->as_user();
        unsigned* tl = (unsigned*)(u + 1);
        check(*tl == Tag<T>::id());
        return (T*)(tl + 1);
      }

    template <typename C>
      inline C* cast(Handle handle) {
        check(0);
        return 0;
      }

    template <>
      inline String* cast<String>(Handle handle) {
        return handle->as_string();
      }
  }
}

#endif
