#ifndef PARSER_HPP
#define PARSER_HPP

#include "code.hpp"

namespace marius {
  class String;

  namespace ast {
    class Node;
  }

  union ParserToken {
    long i;
    String* s;
    ast::Node* a;
  };

  class Parser {
    const char* buffer_;
    int size_;
    const char* end_;

    int left_;

    const char* pos_;

    FILE* file_;

    ParserToken value_;

    void* engine_;
    int column_;
    int line_;

    ast::Node* top_;

    Code* code_;

  public:
    Parser(const char* buf, int sz=-1)
      : buffer_(buf)
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

    ast::Node* top() {
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

  private:
    char next_c();
    const char* next_str(int count);

    int next_token();
    int id_match();
    int bigid_match();
    int keyword_match();
  };
}

#endif
