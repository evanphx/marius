#include "oop.hpp"
#include "class.hpp"
#include "string.hpp"
#include "module.hpp"

namespace marius {
  Class* OOP::klass() {
    switch(type_) {
    case eInteger:
      return Class::base_class(eInteger);
    case eClass:
      return class_->klass();
    case eModule:
      assert(false);
      return class_->klass();
    case eNil:
      return Class::base_class(eNil);
    case eString:
      return Class::base_class(eString);
    case eUser:
      return obj_->klass();
    case eCode:
      return Class::base_class(eCode);
    case eTrue:
      return Class::base_class(eTrue);
    case eFalse:
      return Class::base_class(eFalse);
    case TotalTypes:
      assert(false);
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
    case TotalTypes:
      assert(false);
    }

  }
}
