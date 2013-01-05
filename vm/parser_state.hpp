#ifndef PARSER_STATE_HPP
#define PARSER_STATE_HPP

#include <vector>

#include "code.hpp"
#include "parser.hpp"

namespace marius {
  class Parser;

  class ParserState {
    struct Context {
      std::vector<Instruction> buffer;
      std::vector<String*> strings;
      std::vector<Code*> codes;

      int next_reg;

      Context()
        : next_reg(0)
      {}
    };

    Parser& parser_;
    Context* context_;
    std::vector<Context*> stack_;
    std::vector<int> cascades_;

  public:

    ParserState(Parser& parse)
      : parser_(parse)
      , context_(new Context)
    {}

    Instruction* sequence();

    int sequence_size() {
      return context_->buffer.size();
    }

    std::vector<String*>* strings() {
      return new std::vector<String*>(context_->strings);
    }

    std::vector<Code*>* codes() {
      return new std::vector<Code*>(context_->codes);
    }

    void recycle(int a, int b) {
      if(a == b - 1) {
        context_->next_reg = a;
      }
    }

    void recycle(int a) {
      context_->next_reg = a;
    }

    int new_reg() {
      return context_->next_reg++;
    }

    void push(Instruction op) {
      context_->buffer.push_back(op);
    }

    int string(const char* str) {
      int idx = context_->strings.size();
      context_->strings.push_back(&String::internalize(str));
      return idx;
    }

    int line() {
      return parser_.line();
    }

    int column() {
      return parser_.column();
    }

    void start_def(String& s);
    Code& end_def();

    int bin_op(const char* op, int a, int b);
    int minus(int a, int b);
    int plus(int a, int b);
    int times(int a, int b);
    int divide(int a, int b);
    int number(int a);

    void ret(int a);

    void start_class();
    int new_class(String& s);

    void start_def();
    int end_def(String& s);

    int call(int recv, String& id);
    int named(String& s);

    void start_cascade(int a);
    int cascade(String& name);
    void end_cascade();

    Code* to_code();
  };
}

#endif
