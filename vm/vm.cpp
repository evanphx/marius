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
      if(debug_) dis.print_one(seq);
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
      }
    }

    return OOP::nil();
  }

  OOP VM::run_method(State& S,
                     OOP recv, String& name, int argc, OOP* fp)
  {
    Class*  cls  = recv.klass();
    Method* meth = cls->lookup(name);

    if(!meth) {
      printf("NO METHOD :%s\n", name.c_str());
      return OOP::nil();
    }

    return meth->run(S, recv, argc, fp);
  }

  void VM::reorg_args(OOP* fp, Method* meth, ArgMap& keywords) {
    Code* code = meth->code();
    assert(code);

    ArgMap& args = code->args();

    OOP temp[10];

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
    Class*  cls  = recv.klass();
    Method* meth = cls->lookup(name);

    if(!meth) {
      printf("NO METHOD :%s\n", name.c_str());
      return OOP::nil();
    }

    reorg_args(fp, meth, keywords);

    return meth->run(S, recv, argc, fp);
  }

  OOP VM::load_named(State& S, String& name) {
    return S.env().lookup(name);
  }
}
