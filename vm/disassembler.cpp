#include "disassembler.hpp"
#include "code.hpp"

#include <iostream>
#include <assert.h>

namespace marius {
  void Disassembler::print() {
    static const char* names[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "CALL",
      "RET",
      "LOADN",
      "LOADS",
      "LOADC"
    };

    Instruction* seq = code_.code();

    for(int ip = 0; ip < code_.size();) {
      printf("[%02d] %6s ", ip, names[seq[ip]]);

      switch(seq[ip]) {
      case MOVR:
      case MOVI8:
      case LOADC:
        printf("%d %d\n", seq[ip+1], seq[ip+2]);
        ip += 3;
        break;
      case MOVI32:
        printf("%d %d\n", seq[ip+1], (*(int*)(&seq[ip+2])));
        ip += 6;
        break;
      case CALL:
        printf("%d %d :%s (%d) %d %d\n",
                seq[ip+1], seq[ip+2],
                code_.string(seq[ip+3]).c_str(),
                seq[ip+3], seq[ip+4], seq[ip+5]);
        ip += 6;
        break;

      case LOADN:
      case LOADS:
        printf("%d :%s (%d)\n",
                  seq[ip+1],
                  code_.string(seq[ip+2]).c_str(),
                  seq[ip+2]);
        ip += 3;
        break;
      case RET:
        printf("%d\n", seq[ip+1]);
        ip += 2;
        break;
      default:
        assert(0);
      }
    }
  }
}
