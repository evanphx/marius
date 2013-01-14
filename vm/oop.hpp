#ifndef OOP_HPP
#define OOP_HPP

#include <stdint.h>
#include <assert.h>

namespace marius {

  const static uintptr_t cNil = 2;
  const static uintptr_t cFalse = 4;

  class Class;
  class Module;
  class String;
  class Code;
  class MemoryObject;
  class Method;
  class Unwind;

  class OOP {
  public:
    enum Type {
      eNil, eClass, eInteger, eString, eCode, eUser,
      eTrue, eFalse, eModule, eUnwind,
      TotalTypes
    };

  private:
    Type type_;

    union {
      Class* class_;
      Module* module_;
      String* string_;
      Code* code_;
      MemoryObject* obj_;
      Unwind* unwind_;
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

    OOP(Module* mod)
      : type_(eModule)
      , module_(mod)
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

    OOP(Unwind* u)
      : type_(eUnwind)
      , unwind_(u)
    {}

    Type type() {
      return type_;
    }

    static OOP nil() {
      return OOP();
    }

    static OOP integer(int val) {
      return OOP(val);
    }

    static OOP wrap_klass(Class* cls) {
      return OOP(cls);
    }

    static OOP unwind() {
      return OOP(eUnwind);
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

    Module* as_module() {
      assert(type_ == eModule);
      return module_;
    }

    MemoryObject* as_obj() {
      assert(type_ == eUser);
      return obj_;
    }

    bool true_condition_p() {
      return type_ != eFalse;
    }

    bool unwind_p() {
      return type_ == eUnwind;
    }

    Unwind* unwind_value() {
      assert(type_ == eUnwind);
      return unwind_;
    }

    // template <typename T>
      // class Caster {
        // static T cast(OOP val) {
          // assert(false);
        // }
      // };

    // template <>
      // class Caster<int> {
        // static int cast(OOP val) {
          // assert(val.type_ == eInteger);
          // return val.int_;
        // }
      // }

    // template <typename T>
      // T as() {
        // return Caster<T>::cast(*this);
      // }

    template <typename T>
      T as() {
        assert(false);
      }

    Class* klass();

    Method* find_method(String& name);
    OOP attribute(String& name, bool* found=0);

    void print();
  };

#define SPEC(T, E, V) template <> inline T OOP::as<T>() { assert(type_ == E); return V; }

  SPEC(Class*, eClass, class_);
  SPEC(Module*, eModule, module_);
  SPEC(String*, eString, string_);
  SPEC(Code*, eCode, code_);
  SPEC(MemoryObject*, eUser, obj_);
  SPEC(Unwind*, eUnwind, unwind_);
  SPEC(int, eInteger, int_);

#undef SPEC

}

#endif
