#ifndef OOP_HPP
#define OOP_HPP

#include <stdint.h>
#include <assert.h>

namespace marius {

  const static uintptr_t cNil = 2;
  const static uintptr_t cFalse = 4;

  class Class;
  class String;
  class Code;
  class MemoryObject;

  class OOP {
  public:
    enum Type {
      eNil, eClass, eInteger, eString, eCode, eUser,
      eTrue, eFalse,
      TotalTypes
    };

  private:
    Type type_;

    union {
      Class* class_;
      String* string_;
      Code* code_;
      MemoryObject* obj_;
      int int_;
    };

  public:
    OOP()
      : type_(eNil)
    {}

    OOP(Class* cls)
      : type_(eClass)
      , class_(cls)
    {}

    OOP(int val)
      : type_(eInteger)
      , int_(val)
    {}

    OOP(String& str)
      : type_(eString)
      , string_(&str)
    {}

    OOP(Code& code)
      : type_(eCode)
      , code_(&code)
    {}

    OOP(MemoryObject* obj)
      : type_(eUser)
      , obj_(obj)
    {}

    static OOP nil() {
      return OOP();
    }

    static OOP integer(int val) {
      return OOP(val);
    }

    static OOP wrap_klass(Class* cls) {
      return OOP(cls);
    }

    int int_value() {
      assert(type_ == eInteger);
      return int_;
    }

    String& as_string() {
      return *string_;
    }

    Class* as_class() {
      assert(type_ == eClass);
      return class_;
    }

    Code& as_code() {
      assert(type_ == eCode);
      return *code_;
    }

    MemoryObject* as_obj() {
      assert(type_ == eUser);
      return obj_;
    }

    bool true_condition_p() {
      return type_ != eFalse;
    }

    Class* klass();

    void print();
  };
}

#endif
