#ifndef HANDLE_HPP
#define HANDLE_HPP

#include "state.hpp"

namespace r5 {
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

    OOP* indirection() const {
      return loc_;
    }

    friend class HandleScope;
  };

  template <typename T, int type>
  class TypedHandle {
    Handle hndl_;

    OOP* loc() const {
      return hndl_.indirection();
    }

  public:
    TypedHandle(Handle hndl)
      : hndl_(hndl)
    {
      check(loc()->type() == type);
    }

    T* operator->() const {
      return (T*)(loc()->heap_address());
    }

    T* operator*() const {
      return (T*)loc()->heap_address();
    }

    operator Handle() {
      return hndl_;
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
