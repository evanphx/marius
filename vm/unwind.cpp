#include "unwind.hpp"
#include "string.hpp"

#include <sstream>

namespace marius {
  OOP Unwind::import_error(State& S, String& name) {
    Unwind* u = new(S) Unwind;
    u->message_ += "Import error: Unable to find '";
    u->message_ += name.c_str();
    u->message_ += "'";

    return u;
  }

  OOP Unwind::arg_error(State& S, int expected, int actual) {
    Unwind* u = new(S) Unwind;

    std::stringstream ss;
    ss << "Argument Error: expected " << expected << ", actual " << actual;

    u->message_ += ss.str();

    return u;
  }

  OOP Unwind::name_error(State& S, String& name) {
    Unwind* u = new(S) Unwind;

    std::stringstream ss;
    ss << "Name Error: Unable to find " << name.c_str();

    u->message_ += ss.str();

    return u;
  }

  OOP Unwind::generic_error(State& S, String& str) {
    Unwind* u = new(S) Unwind;

    std::stringstream ss;
    ss << "Error: " << str.c_str();

    u->message_ += ss.str();

    return u;
  }
}
