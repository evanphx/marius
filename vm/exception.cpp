#include "exception.hpp"
#include "state.hpp"
#include "environment.hpp"
#include "vm.hpp"
#include "invoke_info.hpp"
#include "method.hpp"

#include <stdarg.h>
#include <stdio.h>

#include <iostream>

namespace r5 {
  Exception* Exception::create(State& S, const char* cls,
                               const char* fmt, ...)
  {
    va_list ap;

    va_start(ap, fmt);

    char buf[128];
    buf[0] = 0;

    vsnprintf(buf, 127, fmt, ap);

    va_end(ap);

    return new(S) Exception(S, 
                    S.env().lookup(S, cls).as_class(),
                    String::internalize(S, buf), S.vm().invoke_info(S));
  }
  
  Exception* Exception::wrap(State& S, OOP val) {
    if(val.type() == OOP::eException) {
      return val.exception();
    }

    return new(S) Exception(S, 
                    S.env().lookup(S, "RuntimeError").as_class(),
                    val.as_string(), S.vm().invoke_info(S));
  }

  void Exception::show(State& S, const char* context) {
    std::cout << context
              << message()->c_str()
              << " (" << klass()->name()->c_str() << ")"
              << std::endl;

    InvokeInfo* i = backtrace();
    if(i) {
      while(i) {
        std::cout << "    "
                  << i->method()->scope()->c_str() << "#"
                  << i->method()->name(S)->c_str()
                  << "+" << i->ip()
                  << std::endl;

        i = i->previous();
      }
    }
  }
}
