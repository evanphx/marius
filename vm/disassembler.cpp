#include "disassembler.hpp"
#include "code.hpp"

#include <iostream>
#include <assert.h>

namespace marius {

  int Disassembler::print_one(Instruction* seq) {
    static const char* names[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "CALL",
      "RET",
      "LOADN",
      "LOADS",
      "LOADC",
      "SELF"
    };

    printf("%6s | ", names[seq[0]]);

    switch(seq[0]) {
    case MOVR:
      printf("R(%d) := R(%d)\n", seq[1], seq[2]);
      return 3;

    case MOVI8:
      printf("R(%d) := %d\n", seq[1], seq[2]);
      return 3;

    case LOADC:
      printf("R(%d) := CODE[%d]\n", seq[1], seq[2]);
      return 3;

    case MOVI32:
      printf("R(%d) := %d\n", seq[1], (*(int*)(&seq[2])));
      return 6;

    case CALL:
      switch(seq[4]) {
      case 0:
        printf("R(%d) := R(%d).%s\n",
                seq[1], seq[3],
                code_.string(seq[2]).c_str());
        break;

      case 1:
        printf("R(%d) := R(%d).%s R(%d)\n",
                seq[1], seq[3],
                code_.string(seq[2]).c_str(),
                seq[3] + 1);

        break;
      default:
        printf("R(%d) := R(%d).%s R(%d)..R(%d)\n",
                seq[1], seq[3],
                code_.string(seq[2]).c_str(),
                seq[3] + 1, seq[3] + seq[4]);
      }
      return 5;

    case LOADS:
      printf("R(%d) := \"%s\"\n",
                seq[1],
                code_.string(seq[2]).c_str());
      return 3;

    case LOADN:
      printf("R(%d) := ENV[:%s]\n",
                seq[1],
                code_.string(seq[2]).c_str());
      return 3;

    case RET:
      printf("<- R(%d)\n", seq[1]);
      return 2;

    case SELF:
      printf("R(%d) := R(-1)\n", seq[1]);
      return 2;

    default:
      assert(0);
    }

    return -1;
  }

  void Disassembler::print(int indent) {
    Instruction* seq = code_.code();

    for(int ip = 0; ip < code_.size();) {
      for(int j = 0; j < indent; j++) printf(" ");

      printf("[%02d] ", ip);

      ip += print_one(seq + ip);
    }

    indent += 4;

    for(int i = 0; i < code_.codes_size(); i++) {
      printf("\n");
      for(int j = 0; j < indent; j++) printf(" ");
      printf("== CODE[%d] ==\n", i);

      Disassembler dis(code_.code(i));
      dis.print(indent);
    }
  }
}
