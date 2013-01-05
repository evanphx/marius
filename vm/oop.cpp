#include "oop.hpp"
#include "class.hpp"
#include "string.hpp"

namespace marius {
  Class* OOP::klass() {
    switch(type_) {
    case eInteger:
      return Class::integer_class();
    case eClass:
      return class_->klass();
    case eNil:
      return Class::nil_class();
    case eString:
      return Class::string_class();
    case eUser:
      return obj_->klass();
    case eCode:
      return Class::code_class();
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
    }

  }
}
