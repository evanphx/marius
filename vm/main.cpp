#include "vm.hpp"
#include "environment.hpp"
#include "string.hpp"
#include "code.hpp"
#include "class.hpp"
#include "parser.hpp"
#include "state.hpp"
#include "compiler.hpp"
#include "settings.hpp"
#include "user.hpp"
#include "method.hpp"
#include "invoke_info.hpp"

#include "handle.hpp"
#include "closure.hpp"
#include "exception.hpp"

#include <vector>
#include <iostream>

using namespace marius;

int main(int argc, char** argv) {
  Settings settings;

  bool debug = false;
  bool print = false;
  bool check = false;

  char** opt = argv + 1;

  while(*opt) {
    const char* s = *opt;
    if(s[0] == '-') {
      switch(s[1]) {
      case 'd':
        debug = true;
        break;
      case 'p':
        print = true;
        break;
      case 'c':
        check = true;
        break;
      case 'I':
        if(s[2]) {
          settings.load_path().push_back(s+2);
        } else {
          if(!opt[1]) {
            printf("-I requires an argument\n");
            return 1;
          }
          settings.load_path().push_back(*++opt);
        }

        break;
      default:
        printf("Unknown option: %s\n", s);
        return 1;
      }
    } else {
      break;
    }

    opt++;
  }

  if(!*opt) {
    printf("Require a filename\n");
    return 1;
  }

  VM vm(debug);
  Environment env;

  State S(vm, env, settings);

  HandleScope handles(S);

  env.init_ontology(S);

  S.set_importer(new(S) User(S, env.lookup(S, "Importer").as_class()));

  FILE* file = fopen(*opt, "r");
  if(!file) {
    printf("Unable to open: %s\n", *opt);
    return 1;
  }

  Compiler compiler(debug);

  if(!compiler.compile(S, file)) return 1;

  if(check) {
    printf("syntax ok\n");
    return 0;
  }

  Code& code = *compiler.code();

  Method* top = new(S) Method(String::internalize(S, "__main__"), code, env.globals());

  OOP ret = vm.run(S, top);

  if(ret.unwind_p()) {
    Exception* exc = ret.unwind_value();

    std::cout << "Error at toplevel: "
              << exc->message()->c_str()
              << " (" << exc->klass()->name()->c_str() << ")"
              << std::endl;

    InvokeInfo* i = exc->backtrace();
    if(i) {
      while(i) {
        std::cout << "    "
                  << i->method()->scope()->c_str() << "#"
                  << i->method()->name(S)->c_str()
                  << "+" << i->ip()
                  << std::endl;

        i = i->previous();
      }
    } else {
      std::cout << "< NO BACKTRACE AVAILABLE >" << std::endl;
    }


    return 1;
  }

  if(print) ret.print();
  return 0;
}

