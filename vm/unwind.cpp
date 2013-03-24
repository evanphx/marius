#include "unwind.hpp"
#include "string.hpp"

#include <sstream>

namespace marius {
  OOP Unwind::import_error(String& name) {
    Unwind* u = new Unwind;
    u->message_ += "Import error: Unable to find '";
    u->message_ += name.c_str();
    u->message_ += "'";

    return u;
  }

  OOP Unwind::arg_error(int expected, int actual) {
    Unwind* u = new Unwind;

    std::stringstream ss;
    ss << "Argument Error: expected " << expected << ", actual " << actual;

    u->message_ += ss.str();

    return u;
  }

  OOP Unwind::name_error(String& name) {
    Unwind* u = new Unwind;

    std::stringstream ss;
    ss << "Name Error: Unable to find " << name.c_str();

    u->message_ += ss.str();

    return u;
  }
}
