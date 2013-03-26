#include "code.hpp"
#include "disassembler.hpp"

namespace marius {
  const char* InstructionNames[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "MOVN",
      "MOVT",
      "MOVF",
      "CALL",
      "CALL_KW",
      "LATTR",
      "IVA",
      "IVR",
      "RET",
      "LOADN",
      "LOADS",
      "LOADC",
      "SELF",
      "JMPF",
      "JMPB",
      "JMPIT",
      "JMPIF",
      "REGE",
      "POPE",
      "LVAR",
      "SVAR",
      "LAMBDA",
      "SENDI",
      "RAISE",
      "NOT"
    };

  void Code::print() {
    Disassembler dis(*this);
    dis.print();
  }
}
