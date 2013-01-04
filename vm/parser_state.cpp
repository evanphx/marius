#include "parser_state.hpp"
#include <assert.h>

namespace marius {

  Instruction* ParserState::sequence() {
    size_t sz = buffer_.size();
    Instruction* seq = new Instruction[sz];

    for(size_t i = 0; i < sz; i++) {
      seq[i] = buffer_[i];
    }

    return seq;
  }

  int ParserState::bin_op(const char* op, int a, int b) {
    recycle(a, b);

    int target = new_reg();

    push(CALL);
    push(target);
    push(a);
    push(string(op));
    push(b);
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
