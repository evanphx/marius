#include "code.hpp"
#include "disassembler.hpp"

namespace marius {
  const char* InstructionNames[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "CALL",
      "CALL_KW",
      "RET",
      "LOADN",
      "LOADS",
      "LOADC",
      "SELF"
    };

  void Code::print() {
    Disassembler dis(*this);
    dis.print();
  }
}
