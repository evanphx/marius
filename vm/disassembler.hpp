#ifndef DISASSEMBLER_HPP
#define DISASSEMBLER_HPP

#include "code.hpp"

namespace r5 {
  class Code;

  class Disassembler {
    Code* code_;

  public:
    Disassembler(Code* code)
      : code_(code)
    {}

    void print_keywords(STuple* kw, int r);
    void print(int indent=0);

    int print_one(Instruction* seq);
  };
}

#endif
