#include "parser_state.hpp"
#include <assert.h>

namespace marius {

  Instruction* ParserState::sequence() {
    size_t sz = context_->buffer.size();
    Instruction* seq = new Instruction[sz];

    for(size_t i = 0; i < sz; i++) {
      seq[i] = context_->buffer[i];
    }

    return seq;
  }

  Code* ParserState::to_code() {
    return new Code(sequence(), sequence_size(), *strings(), *codes());
  }

  void ParserState::start_def() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  int ParserState::end_def(String& name) {
    Code* code = to_code();

    context_ = stack_.back();
    stack_.pop_back();

    int s = new_reg();
    push(SELF);
    push(s);

    push(LOADS);
    push(s+1);
    push(string(name.c_str()));

    int c = context_->codes.size();
    context_->codes.push_back(code);

    push(LOADC);
    push(s+2);
    push(c);

    push(CALL);
    push(s);
    push(string("add_method"));
    push(s);
    push(2);

    return s;
  }

  int ParserState::call(int recv, String& n) {
    int t = new_reg();

    push(CALL);
    push(t);
    push(string(n.c_str()));
    push(recv);
    push(0);

    return t;
  }

  int ParserState::named(String& s) {
    int t = new_reg();

    push(LOADN);
    push(t);
    push(string(s.c_str()));

    return t;
  }

  void ParserState::start_class() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  int ParserState::new_class(String& s) {
    Code* code = to_code();

    context_ = stack_.back();
    stack_.pop_back();

    int c = new_reg();
    push(LOADN);
    push(c);
    push(string("Class"));

    push(LOADS);
    push(c+1);
    push(string(s.c_str()));

    push(CALL);
    push(c);
    push(string("new"));
    push(c);
    push(1);

    int ci = context_->codes.size();
    context_->codes.push_back(code);

    push(MOVR);
    push(c+1);
    push(c);

    push(LOADC);
    push(c);
    push(ci);

    push(CALL);
    push(c);
    push(string("eval"));
    push(c);
    push(1);

    return c;
  }
  int ParserState::bin_op(const char* op, int a, int b) {
    assert(a + 1 == b);

    recycle(a, b);

    int target = new_reg();

    push(CALL);
    push(target);
    push(string(op));
    push(a);
    push(1);

    return target;
  }

  int ParserState::minus(int a, int b) {
    return bin_op("-", a, b);
  }

  int ParserState::plus(int a, int b) {
    return bin_op("+", a, b);
  }

  int ParserState::times(int a, int b) {
    return bin_op("*", a, b);
  }

  int ParserState::divide(int a, int b) {
    return bin_op("/", a, b);
  }

  int ParserState::number(int a) {
    int target = new_reg();

    push(MOVI8);
    push(target);
    push(a);

    return target;
  }

  void ParserState::ret(int a) {
    push(RET);
    push(a);
  }

}
