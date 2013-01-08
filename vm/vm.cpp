#include "vm.hpp"
#include "code.hpp"
#include "method.hpp"
#include "class.hpp"
#include "environment.hpp"
#include "state.hpp"
#include "disassembler.hpp"

#define TRACE

namespace marius {

  VM::VM(bool debug)
    : debug_(debug)
  {
    stack_ = new OOP[cInitialStack];
  }

  OOP VM::run(State& S, Code& code) {
    return run(S, code, stack_);
  }

  OOP VM::run(State& S, Code& code, OOP* fp) {
    Instruction* seq = code.code();
    Instruction* end = seq + code.size();

#ifdef TRACE
    Disassembler dis(code);
#endif

    while(seq < end) {
#ifdef TRACE
      if(debug_) {
        printf("[%04ld] ", seq - code.code());
        dis.print_one(seq);
      }
#endif

      switch(*seq++) {
      case MOVI8:
        fp[seq[0]] = OOP::integer(seq[1]);
        seq += 2;
        break;
      case MOVI32:
        fp[seq[0]] = OOP::integer(*((int*)seq));
        seq += 5;
        break;
      case MOVR:
        fp[seq[0]] = fp[seq[1]];
        seq += 2;
        break;

      case MOVN:
        fp[seq[0]] = OOP(OOP::eNil);
        seq += 1;
        break;
      case MOVT:
        fp[seq[0]] = OOP(OOP::eTrue);
        seq += 1;
        break;
      case MOVF:
        fp[seq[0]] = OOP(OOP::eFalse);
        seq += 1;
        break;

      case CALL:
        fp[seq[0]] = run_method(S,
                                fp[seq[2]], code.string(seq[1]),
                                seq[3],     fp + (seq[2] + 1));

        seq += 4;
        break;
      case CALL_KW:
        fp[seq[0]] = run_kw_method(S,
                                   fp[seq[2]], code.string(seq[1]),
                                   seq[3],     fp + (seq[2] + 1),
                                   code.keywords(seq[4]));

        seq += 5;
        break;

      case LOADN:
        fp[seq[0]] = load_named(S, code.string(seq[1]));

        seq += 2;
        break;
      case LOADS:
        fp[seq[0]] = OOP(code.string(seq[1]));

        seq += 2;
        break;

      case LOADC:
        fp[seq[0]] = OOP(code.code(seq[1]));

        seq += 2;
        break;

      case SELF:
        fp[seq[0]] = fp[-1];

        seq += 1;
        break;

      case RET:
        return fp[*seq++];

      case JMPF:
        seq += (seq[0] + 1);
        break;

      case JMPB:
        seq -= (seq[0] + 1);
        break;

      case JMPIT:
        if(fp[seq[0]].true_condition_p()) {
          seq += (seq[1] + 1);
        } else {
          seq += 2;
        }

      case JMPIF:
        if(!fp[seq[0]].true_condition_p()) {
          seq += (seq[1] + 1);
        } else {
          seq += 2;
        }
      }
    }

    return OOP::nil();
  }

  OOP VM::run_method(State& S,
                     OOP recv, String& name, int argc, OOP* fp)
  {
    Method* meth = recv.find_method(name);

    if(!meth) {
      printf("NO METHOD :%s\n", name.c_str());
      return OOP::nil();
    }

    Arguments args(argc, fp);

    return meth->run(S, recv, args);
  }

  void VM::reorg_args(OOP* fp, Method* meth, ArgMap& keywords) {
    Code* code = meth->code();
    assert(code);

    ArgMap& args = code->args();

    OOP* temp = fp + args.size();

    for(ArgMap::iterator i = args.begin();
        i != args.end();
        ++i) {
      int req = (*i).second;

      ArgMap::iterator f = keywords.find((*i).first);

      if(f == keywords.end()) {
        temp[req] = fp[req];
      } else {
        int is   = (*f).second;
        temp[req] = fp[is];
      }
    }

    for(int i = 0; i < args.size(); i++) {
      fp[i] = temp[i];
    }
  }

  OOP VM::run_kw_method(State& S,
                        OOP recv, String& name, int argc, OOP* fp,
                        ArgMap& keywords)
  {
    Method* meth = recv.find_method(name);

    if(!meth) {
      printf("NO METHOD :%s\n", name.c_str());
      return OOP::nil();
    }

    reorg_args(fp, meth, keywords);

    Arguments args(argc, fp);

    return meth->run(S, recv, args);
  }

  OOP VM::load_named(State& S, String& name) {
    return S.env().lookup(name);
  }
}
