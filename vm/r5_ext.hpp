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
    String* string(State& S, const char* name, int sz);

    Handle allocate_sized(State& S, Class* cls, unsigned bytes);

    template <typename T>
      Handle allocate(State& S, Class* cls) {
        return allocate_sized(S, cls, sizeof(T));
      }

    template <typename T>
      T* unwrap(Handle handle) {
        User* u = handle->as_user();
        return (T*)(u + 1);
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
