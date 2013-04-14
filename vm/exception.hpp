#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "memory_object.hpp"
#include "attributes.hpp"
#include "class.hpp"

namespace r5 {
  class String;
  class InvokeInfo;
  class VM;

  class Exception : public MemoryObject, public Attributes {
    Exception* parent_;
    String* message_;
    InvokeInfo* backtrace_;

    friend class GCImpl;
  public:

    Exception(State& S, Class* cls, String* msg)
      : MemoryObject(cls)
      , Attributes(S)
      , parent_(0)
      , message_(msg)
      , backtrace_(0)
    {}

    Exception(State& S, Class* cls, String* msg, InvokeInfo* bt)
      : MemoryObject(cls)
      , Attributes(S)
      , parent_(0)
      , message_(msg)
      , backtrace_(bt)
    {}

    String* message() {
      return message_;
    }

    InvokeInfo* backtrace() {
      return backtrace_;
    }

    static Exception* create(State& S, const char* cls, const char* fmt, ...);
    static Exception* wrap(State& S, OOP val);
  
    void show(State& S, const char* context);
  };
}

#endif
