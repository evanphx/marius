#ifndef HANDLE_HPP
#define HANDLE_HPP

#include "state.hpp"

namespace marius {
  class Handle {
    OOP* loc_;

  private:
    Handle(OOP* loc)
      : loc_(loc)
    {}

    Handle()
      : loc_(0)
    {}

  public:
    OOP operator*() const {
      return *loc_;
    }

    OOP* operator->() const {
      return loc_;
    }

    OOP* indirection() {
      return loc_;
    }

    friend class HandleScope;
  };

  template <typename T, int type>
  class TypedHandle {
    OOP* loc_;

  public:
    TypedHandle(Handle hndl)
      : loc_(hndl.indirection())
    {}

    T* operator->() const {
      check(loc_->type() == type);
      return (T*)(loc_->heap_address());
    }
  };

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
}

#endif
