#include "compiler.hpp"
#include "parser.hpp"
#include "ast.hpp"

#include "scope_tracker.hpp"
#include "local.hpp"

#include <iostream>

namespace marius {
  bool Compiler::compile(State& S, FILE* f) {
    Parser parser(S, f);

    if(!parser.parse(debug_)) return false;

    ast::Scope* top = parser.top();

    if(!top) return false;

    ArgMap globals;

    globals[String::internalize(S, "Object")] = 0;
    globals[String::internalize(S, "io")] = 1;
    globals[String::internalize(S, "Class")] = 2;
    globals[String::internalize(S, "Importer")] = 3;
    globals[String::internalize(S, "Dictionary")] = 4;
    globals[String::internalize(S, "Integer")] = 5;
    globals[String::internalize(S, "sys")] = 6;
    globals[String::internalize(S, "Trait")] = 7;
    globals[String::internalize(S, "ArgumentError")] = 8;
    globals[String::internalize(S, "NoMethodError")] = 9;
    globals[String::internalize(S, "Exception")] = 10;
    globals[String::internalize(S, "List")] = 11;

    LocalMap locals;

    calculate_locals(S, top, globals, locals);

    ast::State AS(S, locals);

    top->drive(AS, top->locals().size());

    ArgMap args;

    code_ = AS.to_code(String::internalize(S, "__main__"), args, 0, top->cov());

    if(debug_) code_->print();

    return true;
  }

  static int insn_len(InstructionTypes op) {
    switch(op) {
    case MOVR:
      return 3;

    case MOVN:
      return 2;

    case MOVT:
      return 2;

    case MOVF:
      return 2;

    case MOVI8:
      return 3;

    case LOADC:
      return 3;

    case MOVI32:
      return 6;

    case SENDI:
      return 5;

    case SENDI_KW:
      return 6;

    case CALL:
      return 5;

    case CALL_KW:
      return 6;

    case IVA:
      return 3;

    case IVR:
      return 3;

    case LATTR:
      return 4;

    case LOADS:
      return 3;

    case LRET:
    case RET:
      return 2;

    case SELF:
      return 2;

    case JMPF:
      return 2;

    case JMPB:
      return 2;

    case JMPIF:
    case JMPIT:
    case JMPHA:
      return 3;

    case REGE:
      return 3;

    case POPE:
      return 1;

    case LVAR:
      return 4;

    case SVAR:
      return 4;

    case RAISE:
      return 2;

    case NOT:
      return 3;

    case TUPLE:
      return 4;

    case LIST:
      return 4;

    case TotalInstructions:
      assert(0);
    }
  }

  void Compiler::optimize() {
    int size = code_->size();
    Instruction* insns = code_->code();

    int ip = 0;
    int out_ip = 0;

    Instruction* out = new Instruction[size];

    bool skip_next = false;

    while(ip < size) {
      InstructionTypes op = (InstructionTypes)insns[ip];

      bool skip = skip_next;
      skip_next = false;

      switch(op) {
      case MOVR:
        {
          int to   = insns[ip+1];
          int from = insns[ip+2];

          if(insns[ip+3] == MOVR &&
             insns[ip+4] == from &&
             insns[ip+5] == to) {
            skip_next = true;
          }
        }
        break;
      default:
        skip = false;
      }

      int len = insn_len(op);

      if(!skip) {
        for(int i = 0; i < insn_len(op); i++) {
          out[out_ip++] = insns[ip++];
        }
      } else {
        ip += len;
      }
    }

    code_->update(out, out_ip);

    delete insns;
  }
}
