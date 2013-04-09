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

#include "bug.hpp"

#include <vector>
#include <iostream>

#include <sys/stat.h>

using namespace marius;

int main(int argc, char** argv) {
  Settings settings;

  bool debug = false;
  bool print = false;
  bool check = false;

  char** opt = argv + 1;
  char** fin = argv + argc;

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

  const char* script = *opt++;
  env.import_args(S, opt, fin - opt); 

  OOP ret;

  struct stat s;
  stat(script, &s);

  if(S_ISREG(s.st_mode) || S_ISLNK(s.st_mode)) {
    FILE* file = fopen(script, "r");
    marius::check(file);

    Compiler compiler(debug);

    if(!compiler.compile(S, file)) return 1;

    if(check) {
      printf("syntax ok\n");
      return 0;
    }

    Code& code = *compiler.code();

    Method* top = new(S) Method(String::internalize(S, "__main__"), code, env.globals());

    ret = vm.run(S, top);
  } else {
    char buf[128];
    buf[0] = 0;
    strcat(buf, "bin/");
    strcat(buf, script);

    OOP bin_path_o = String::internalize(S, buf);
    ret = OOP(S.importer()).call(S, String::internalize(S, "import"),
                                 &bin_path_o, 1);
  }

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

