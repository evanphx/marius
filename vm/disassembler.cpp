#include "disassembler.hpp"
#include "code.hpp"

#include <iostream>
#include <assert.h>
#include <stdio.h>

namespace marius {

  void Disassembler::print_keywords(ArgMap& kw, int r) {
    for(ArgMap::iterator i = kw.begin();
        i != kw.end();
        ++i) {
      printf("%s=R(%d) ", (*i).first.ptr()->c_str(), r + i->second);
    }
  }


  int Disassembler::print_one(Instruction* seq) {
    printf("%8s | ", InstructionNames[seq[0]]);

    switch(seq[0]) {
    case MOVR:
      printf("R(%d) := R(%d)\n", seq[1], seq[2]);
      return 3;

    case MOVN:
      printf("R(%d) := nil", seq[1]);
      return 2;

    case MOVT:
      printf("R(%d) := true", seq[1]);
      return 2;

    case MOVF:
      printf("R(%d) := false", seq[1]);
      return 2;

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

    case CALL_KW:
      printf("R(%d) := R(%d).%s ",
              seq[1], seq[3],
              code_.string(seq[2]).c_str());

      print_keywords(code_.keywords(seq[5]), seq[3]+1);
      printf("\n");
      return 6;

    case LATTR:
      printf("R(%d) := R(%d)::%s\n", seq[1], seq[3],
             code_.string(seq[2]).c_str());
      return 4;

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

    case JMPF:
      printf("IP += %d\n", seq[1]);
      return 2;

    case JMPB:
      printf("IP -= %d\n", seq[1]);
      return 2;

    case JMPIT:
      printf("IP += %d if R(%d)\n", seq[2], seq[1]);
      return 3;

    case JMPIF:
      printf("IP += %d if !R(%d)\n", seq[2], seq[1]);
      return 3;

    case REGE:
      printf("R(E).push <reg:%d, ip:%d>\n", seq[1], seq[2]);
      return 3;

    case POPE:
      printf("R(E).pop\n");
      return 1;

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
