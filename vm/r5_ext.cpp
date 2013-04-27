#include "r5_ext.hpp"

#include "environment.hpp"
#include "user.hpp"
#include "string.hpp"

#include "util/address.hpp"

namespace r5 {
  ExtInitializer* ExtInitializer::first = 0;

  void Environment::init_builtin_extensions(State& S) {
    ExtInitializer* i = ExtInitializer::first;

    while(i) {
      i->init(S);
      i = i->next;
    }
  }

  namespace ext {
    unsigned TagBase = 0;

    String* string(State& S, const char* name, int sz) {
      return String::internalize(S, name, sz);
    }

    String* string(State& S, void* name, int sz) {
      return String::internalize(S, (const char*)name, sz);
    }

    String* string(State& S, char* name) {
      return String::internalize(S, name, strlen(name));
    }

    Handle allocate_sized(State& S, Class* cls, unsigned extra, unsigned tag) {
      memory::Address addr = S.allocate(sizeof(User) + extra);
      User* u = new(addr) User(S, cls);
      unsigned* tl = (unsigned*)(u + 1);
      *tl = tag;
      return handle(S, u);
    }
  }
}
