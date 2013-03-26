#ifndef UNWIND_HPP
#define UNWIND_HPP

#include "oop.hpp"
#include "unwind.hpp"

#include <string>

namespace marius {
  class Unwind {
    std::string message_;

  public:

    std::string& message() {
      return message_;
    }

    static OOP import_error(String& n);
    static OOP arg_error(int expected, int actual);
    static OOP name_error(String& name);
    static OOP generic_error(String& str);
  };
}

#endif
