#ifndef PARSER_HPP
#define PARSER_HPP

#include "code.hpp"

namespace marius {
  class Parser {
    const char* buffer_;
    const char* end_;
    int size_;

    const char* pos_;

    int value_;

    void* engine_;

    Code* code_;

  public:
    Parser(const char* buf, int sz)
      : buffer_(buf)
      , size_(sz)
      , end_(buf + sz)
      , pos_(buf)
      , value_(0)
      , engine_(0)
      , code_(0)
    {}

    bool parse();

    Code* code() {
      return code_;
    }

  private:
    int next_token();
  };
}

#endif

