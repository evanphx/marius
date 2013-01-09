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
  };
}

#endif
