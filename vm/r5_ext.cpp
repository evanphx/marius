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
    String* string(State& S, const char* name, int sz) {
      return String::internalize(S, name, sz);
    }

    String* string(State& S, void* name, int sz) {
      return String::internalize(S, (const char*)name, sz);
    }

    Handle allocate_sized(State& S, Class* cls, unsigned extra) {
      memory::Address addr = S.allocate(sizeof(User) + extra);
      User* u = new(addr) User(S, cls);
      return handle(S, u);
    }
  }
}
