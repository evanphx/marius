
#include <string>
#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <ctype.h>
#include <cxxabi.h>

#include <execinfo.h>
namespace r5 {

  static void squeeze_space(std::string& str) {
    std::string ws = "    ";

    std::string::size_type pos = str.find(ws);
    if(pos == std::string::npos) return;

    std::string::size_type i = pos + 4;
    while(std::isspace(str[i])) i++;
    str.erase(pos + 2, i - pos - 2);
  }

  static void print_demangle(std::string s) {
    squeeze_space(s);
    const char* str = s.c_str();
    const char* pos = strstr(str, " _Z");
    /* Found a mangle. */
    if(pos) {
      size_t sz = 1024;
      char *cpp_name = 0;
      char* name = strdup(pos + 1);
      char* end = strstr(name, " + ");
      *end = 0;

      int status;
      cpp_name = abi::__cxa_demangle(name, cpp_name, &sz, &status);

      if(!status) {
        std::string full_cpp = std::string(str, pos - str) + " " + cpp_name +
          " " + (++end);
        s = full_cpp;
      }
      if(cpp_name) free(cpp_name);
      free(name);
    }

    printf("%s\n", s.c_str());
  }

  void print_backtrace(unsigned skip, unsigned max_depth) {
    unsigned stack_depth;
    char **stack_strings;

    void **stack_addrs = (void **) calloc(max_depth, sizeof(void*));

    stack_depth = backtrace(stack_addrs, max_depth);
    stack_strings = backtrace_symbols(stack_addrs, stack_depth);

    for (unsigned i = skip; i < stack_depth; i++) {
      print_demangle(std::string(stack_strings[i]));
    }
    free(stack_strings); // malloc()ed by backtrace_symbols
    free(stack_addrs);
  }
}
