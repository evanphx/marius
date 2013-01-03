#include "oop.hpp"
#include "class.hpp"

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
    default:
      assert(0);
    }
  }
}
