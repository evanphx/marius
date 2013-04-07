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
      "NOT",
      "TUPLE"
    };

  void Code::print() {
    Disassembler dis(*this);
    dis.print();
  }
}
