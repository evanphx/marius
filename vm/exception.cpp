#include "exception.hpp"
#include "state.hpp"
#include "environment.hpp"

namespace marius {
  Exception* Exception::create(State& S, const char* cls,
                               const char* fmt, ...)
  {
    va_list ap;

    va_start(ap, fmt);

    char buf[127];

    vsnprintf(buf, 128, fmt, ap);

    va_end(ap);

    return new(S) Exception(S, 
                    S.env().lookup(S, cls).as_class(),
                    String::internalize(S, buf));
  }
  
  Exception* Exception::wrap(State& S, OOP val) {
    if(val.type() == OOP::eException) {
      return val.exception();
    }

    return new(S) Exception(S, 
                    S.env().lookup(S, "RuntimeError").as_class(),
                    val.as_string());
  }
}
