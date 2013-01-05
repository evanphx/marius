#ifndef PARSER_HPP
#define PARSER_HPP

#include "code.hpp"

namespace marius {
  class String;

  union ParserToken {
    int i;
    String* s;
  };

  class Parser {
    const char* buffer_;
    int size_;
    const char* end_;

    const char* pos_;

    ParserToken value_;

    void* engine_;

    Code* code_;

  public:
    Parser(const char* buf, int sz=-1)
      : buffer_(buf)
      , size_(sz == -1 ? strlen(buf) : sz)
      , end_(buf + size_)
      , pos_(buf)
      , engine_(0)
      , code_(0)
    {
      value_.i = 0;
    }

    bool parse();

    Code* code() {
      return code_;
    }

  private:
    int next_token();
    int id_match();
    int bigid_match();
    int keyword_match();
  };
}

#endif

