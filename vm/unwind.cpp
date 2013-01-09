#include "unwind.hpp"
#include "string.hpp"

namespace marius {
  OOP Unwind::import_error(String& name) {
    Unwind* u = new Unwind;
    u->message_ += "Import error: Unable to find '";
    u->message_ += name.c_str();
    u->message_ += "'";

    return u;
  }
}
