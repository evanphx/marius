#include "oop.hpp"
#include "class.hpp"
#include "string.hpp"
#include "module.hpp"

#include <stdio.h>

namespace marius {
  Class* OOP::klass() {
    switch(type_) {
    case eUser:
      return obj_->klass();
    case eClass:
      return class_->klass();
    default:
      return Class::base_class(type_);
    }
  }

  Method* OOP::find_method(String& name) {
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
      printf("%s\n", class_->name().c_str());
      return;
    case eNil:
      printf("nil\n");
      return;
    case eString:
      printf("\"%s\"\n", string_->c_str());
      return;
    case eUser:
      printf("<%s:%p>\n", obj_->klass()->name().c_str(), obj_);
      return;
    case eCode:
      printf("<Code:%p>\n", obj_);
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
    case TotalTypes:
      assert(false);
    }
  }

  OOP OOP::attribute(String& name, bool* found) {
    switch(type_) {
    case eModule:
      return as_module()->attribute(name, found);
    default:
      if(found) *found = false;
      return OOP::nil();
    }
  }
}
