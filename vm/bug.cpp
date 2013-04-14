#include "backtrace.hpp"

#include <iostream>

#include <stdlib.h>

namespace r5 {
  static bool hard_abort = true;

  void abort() {
    std::cout << "Abort!" << std::endl;
    print_backtrace();
    if(hard_abort) ::abort();
  }

  void bug(const char* message) {
    std::cerr << "[BUG: " << message << "]\n";
    print_backtrace();
    ::abort();
  }

  void bug(const char* message, const char* arg) {
    std::cerr << "[BUG: " << message
              << ": " << arg
              << "]\n";
    print_backtrace();
    ::abort();
  }

  void warn(const char* message) {
    std::cerr << "[WARNING: " << message << "]\n";
    print_backtrace();
  }

}
