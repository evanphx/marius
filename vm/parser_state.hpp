#ifndef PARSER_STATE_HPP
#define PARSER_STATE_HPP

#include <vector>

#include "code.hpp"

namespace marius {
  class ParserState {
    std::vector<Instruction> buffer_;
    std::vector<String*> strings_;

    int next_reg_;

  public:

    ParserState()
      : next_reg_(0)
    {}

    Instruction* sequence();

    int sequence_size() {
      return buffer_.size();
    }

    std::vector<String*>* strings() {
      return new std::vector<String*>(strings_);
    }

    std::vector<Code*>* codes() {
      return new std::vector<Code*>();
    }

    void recycle(int a, int b) {
      if(a == b - 1) {
        next_reg_ = a;
      }
    }

    int new_reg() {
      return next_reg_++;
    }

    void push(Instruction op) {
      buffer_.push_back(op);
    }

    int string(const char* str) {
      int idx = strings_.size();
      strings_.push_back(&String::internalize(str));
      return idx;
    }

    int bin_op(const char* op, int a, int b);
    int minus(int a, int b);
    int plus(int a, int b);
    int times(int a, int b);
    int divide(int a, int b);
    int number(int a);

    void ret(int a);
  };
}

#endif
