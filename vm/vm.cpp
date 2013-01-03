#include "vm.hpp"
#include "code.hpp"
#include "method.hpp"
#include "class.hpp"
#include "environment.hpp"

namespace marius {

  VM::VM() {
    stack_ = new OOP[cInitialStack];
  }

  OOP VM::run(Environment& env, Code& code) {
    return run(env, code, stack_);
  }

  OOP VM::run(Environment& env, Code& code, OOP* fp) {
    Instruction* seq = code.code();
    Instruction* end = seq + code.size();

    while(seq < end) {
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
        fp[seq[0]] = run_method(env, 
                                fp[seq[1]], code.string(seq[2]),
                                seq[3],     fp + seq[4]);

        seq += 5;
        break;
      case LOADN:
        fp[seq[0]] = load_named(env, code.string(seq[1]));

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
      case RET:
        return fp[*seq++];
      }
    }

    return OOP::nil();
  }

  OOP VM::run_method(Environment& env,
                     OOP recv, String& name, int argc, OOP* fp)
  {
    Class*  cls  = recv.klass();
    Method* meth = cls->lookup(name);

    if(!meth) {
      printf("NO METHOD :%s\n", name.c_str());
      return OOP::nil();
    }

    return meth->run(env, this, recv, argc, fp);
  }

  OOP VM::load_named(Environment& env, String& name) {
    return env.lookup(name);
  }
}
