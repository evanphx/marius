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
    const char* cs;
  };

  class Parser {
    State& S;
    char* buffer_;
    int size_;
    char* end_;

    char* pos_;

    FILE* file_;

    ParserToken value_;

    void* engine_;
    int column_;
    int line_;

    ast::Scope* top_;

    Code* code_;

    bool import_name_;

  public:
    Parser(State& S, char* buf, int sz=-1)
      : S(S)
      , buffer_(strdup(buf))
      , size_(sz == -1 ? strlen(buf) : sz)
      , end_(buf + size_)
      , pos_(buf)
      , file_(0)
      , engine_(0)
      , column_(1)
      , line_(1)
      , code_(0)
      , import_name_(false)
    {
      value_.i = 0;
    }

    Parser(State& S, FILE* file)
      : S(S)
      , buffer_(0)
      , size_(0)
      , end_(0)
      , pos_(0)
      , file_(file)
      , engine_(0)
      , column_(1)
      , line_(1)
      , code_(0)
      , import_name_(false)
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

    void import_start();
    void import_end();

  private:
    char next_c();
    const char* next_str(int count);

    int next_token();
    int id_match(int tk);
    int keyword_match();
    int str_match();
    int sym_match();
    bool match_operator();

    int import_name_match();
  };
}

#endif

