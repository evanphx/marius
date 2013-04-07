#include "oop.hpp"
#include "class.hpp"
#include "string.hpp"
#include "module.hpp"
#include "attributes.hpp"
#include "user.hpp"

#include <stdio.h>

namespace marius {
  Class* OOP::klass() {
    switch(type_) {
    case eUser:
      return user_->klass();
    case eClass:
      return class_->klass();
    default:
      return Class::base_class(type_);
    }
  }


  Method* OOP::find_method(String* name) {
    if(type_ == eModule) {
      return module_->lookup(name);
    } else {
      return klass()->lookup(name);
    }
  }

  void OOP::print() {
    switch(type_) {
    case eInteger:
      printf("%d\n", int_);
      return;
    case eClass:
      printf("%s\n", class_->name()->c_str());
      return;
    case eNil:
      printf("nil\n");
      return;
    case eString:
      printf("\"%s\"\n", string_->c_str());
      return;
    case eUser:
      printf("<%s:%p>\n", user_->klass()->name()->c_str(), user_);
      return;
    case eCode:
      printf("<Code:%p>\n", user_);
      return;
    case eMethod:
      printf("<Method:%p>\n", method_);
      return;
    case eClosure:
      printf("<Closure:%p>\n", closure_);
      return;
    case eTrue:
      printf("true\n");
      return;
    case eFalse:
      printf("false\n");
      return;
    case eModule:
      printf("<Module:%p>\n", module_);
      return;
    case eUnwind:
      printf("<Unwind:%p>\n", unwind_);
      return;
    case eTuple:
      printf("<Tuple>\n");
      return;
    case eRaw:
      printf("<raw>\n");
      return;
    case eDictionary:
      printf("<dict>\n");
      return;
    case TotalTypes:
      check(false);
    }
  }

  Attributes* OOP::as_attributes() {
    switch(type_) {
    case eModule:
      return module_;
    case eClass:
      return class_;
    case eUser:
      return user_;
    default:
      return 0;
    }
  }

  OOP OOP::set_attribute(State& S, String* name, OOP val) {
    if(Attributes* attrs = as_attributes()) {
      attrs->set_attribute(S, name, val);
    }

    return val;
  }

  OOP OOP::attribute(String* name, bool* found) {
    if(Attributes* attrs = as_attributes()) {
      return attrs->attribute(name, found);
    } else {
      if(found) *found = false;
      return OOP::nil();
    }
  }
}
