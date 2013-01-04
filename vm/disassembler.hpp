#ifndef DISASSEMBLER_HPP
#define DISASSEMBLER_HPP

namespace marius {
  class Code;

  class Disassembler {
    Code& code_;

  public:
    Disassembler(Code& code)
      : code_(code)
    {}

    void print();
  };
}

#endif
