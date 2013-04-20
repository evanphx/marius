#ifndef HANDLE_SCOPE_HPP
#define HANDLE_SCOPE_HPP

#include "handle.hpp"

namespace r5 {
  class HandleScope {
    State& S_;
    HandleSet* set_;
    OOP* old_;
    HandleScope* prev_;

  public:
    HandleScope(State& S)
      : S_(S)
      , set_(S.pull_set())
      , old_(set_->pos())
      , prev_(S.set_handles(this))
    {}

    ~HandleScope() {
      set_->reset(old_);
      S_.set_handles(prev_);
    }

    OOP* add(OOP oop) {
      OOP* loc = set_->add(oop);
      if(!loc) {
        set_ = S_.pull_set();
        loc = set_->add(oop);
        check(loc);
      }

      return loc;
    }
      
    Handle handle(OOP v) {
      return Handle(add(v));
    }
  };

  inline Handle handle(State& S, OOP v) {
    return S.handles()->handle(v);
  }

  inline Handle handle(State& S, Handle h) {
    return h;
  }
}

#endif
