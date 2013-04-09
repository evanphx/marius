#include "bindings.hpp"
#include "string.hpp"
#include "state.hpp"
#include "tuple.hpp"

namespace marius {

  Bindings::Bindings(State& S)
    : entries_(new(S) Entry*[cDefaultCapa])
    , capa_(cDefaultCapa)
    , size_(0)
  {
    for(unsigned i = 0; i < capa_; i++) {
      entries_[i] = 0;
    }
  }

  option<OOP> Bindings::find(String* name) {
    unsigned h = name->hash();

    Entry* e = entries_[h % capa_];

    while(e) {
      if(e->key->equal(name)) return e->val;
      e = e->next;
    }

    return option<OOP>();
  }

  void Bindings::set(State& S, String* name, OOP val) {
    unsigned h = name->hash();

    unsigned idx = h % capa_;

    Entry* e = entries_[idx];

    if(e) {
      for(;;) {
        if(e->key->equal(name)) {
          e->val = val;
          return;
        }

        if(e->next) {
          e = e->next;
        } else {
          e->next = new(S) Entry(name, val);
          size_++;
          return;
        }
      }
    } else {
      entries_[idx] = new(S) Entry(name, val);
      size_++;
    }
  }

  OOP Bindings::keys(State& S) {
    Tuple* tup = new(S) Tuple(S, size_);

    int idx = 0;

    for(unsigned i = 0; i < capa_; i++) {
      Entry* e = entries_[i];

      while(e) {
        tup->set(idx++, OOP(e->key));
        e = e->next;
      }
    }

    return OOP(tup);
  }

  OOP Bindings::values(State& S) {
    Tuple* tup = new(S) Tuple(S, size_);

    int idx = 0;

    for(unsigned i = 0; i < capa_; i++) {
      Entry* e = entries_[i];

      while(e) {
        tup->set(idx++, e->val);
        e = e->next;
      }
    }

    return OOP(tup);
  }
}
