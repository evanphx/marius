#ifndef PARSER_HPP
#define PARSER_HPP

#include "code.hpp"

#include <string.h>

namespace marius {
  class String;

  namespace ast {
    class Node;
    class Scope;
  }

  union ParserToken {
    long i;
    String* s;
    ast::Node* a;
  };

  class Parser {
    char* buffer_;
    int size_;
    char* end_;

    int left_;

    char* pos_;

    FILE* file_;

    ParserToken value_;

    void* engine_;
    int column_;
    int line_;

    ast::Scope* top_;

    Code* code_;

  public:
    Parser(char* buf, int sz=-1)
      : buffer_(strdup(buf))
      , size_(sz == -1 ? strlen(buf) : sz)
      , end_(buf + size_)
      , left_(sz)
      , pos_(buf)
      , file_(0)
      , engine_(0)
      , column_(1)
      , line_(1)
      , code_(0)
    {
      value_.i = 0;
    }

    Parser(FILE* file)
      : buffer_(0)
      , size_(0)
      , end_(0)
      , left_(0)
      , pos_(0)
      , file_(file)
      , engine_(0)
      , column_(1)
      , line_(1)
      , code_(0)
    {
      value_.i = 0;
    }

    Code* code() {
      return code_;
    }

    ast::Scope* top() {
      return top_;
    }

    void advance(int count) {
      pos_ += count;
      column_ += count;
    }

    int line() {
      return line_;
    }

    int column() {
      return column_;
    }

    bool parse(bool debug=false);
    static void init_keywords();

  private:
    char next_c();
    const char* next_str(int count);

    int next_token();
    int id_match(int tk);
    int keyword_match();
  };
}

#endif

