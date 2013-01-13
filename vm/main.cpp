#include "vm.hpp"
#include "environment.hpp"
#include "string.hpp"
#include "code.hpp"
#include "class.hpp"
#include "parser.hpp"
#include "state.hpp"
#include "compiler.hpp"
#include "settings.hpp"
#include "unwind.hpp"

#include <vector>
#include <iostream>

using namespace marius;

int main(int argc, char** argv) {
  Settings settings;

  bool debug = false;
  bool print = false;

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

  State state(vm, env, settings);

  env.init_ontology();

  FILE* file = fopen(*opt, "r");
  if(!file) {
    printf("Unable to open: %s\n", *opt);
    return 1;
  }

  Compiler compiler(debug);

  if(!compiler.compile(file)) return 1;

  OOP ret = vm.run(state, *compiler.code());

  if(ret.unwind_p()) {
    std::cout << "Unwind error at toplevel: "
              << ret.unwind_value()->message()
              << std::endl;

    return 1;
  }

  if(print) ret.print();
  return 0;
}

