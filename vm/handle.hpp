#ifndef HANDLE_HPP
#define HANDLE_HPP

#include "oop.hpp"

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
}

#endif
