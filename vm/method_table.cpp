#include "method_table.hpp"
#include "string.hpp"
#include "tuple.hpp"

#include "state.hpp"

#include "util/option.hpp"

#include <iostream>

namespace marius {
  MethodTable::MethodTable(State& S)
    : entries_(new(S) Entry*[cDefaultCapa])
    , capa_(cDefaultCapa)
    , size_(0)
  {
    for(unsigned i = 0; i < size_; i++) {
      entries_[i] = 0;
    }
  }

  option<Method*> MethodTable::lookup(String* name) {
    unsigned h = name->hash();

    Entry* e = entries_[h % capa_];

    while(e) {
      if(e->key->equal(name)) return e->method;
      e = e->next;
    }

    return option<Method*>();
  }

  void MethodTable::add(State& S, String* name, Method* val) {
    unsigned h = name->hash();

    unsigned idx = h % capa_;

    Entry* e = entries_[idx];

    if(e) {
      for(;;) {
        if(e->key->equal(name)) {
          e->method = val;
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

  OOP MethodTable::methods(State& S) {
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
}
