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
#include "handle_scope.hpp"

#include "arguments.hpp"
#include "bug.hpp"
#include "module.hpp"

#include <vector>
#include <iostream>

#include <sys/stat.h>

using namespace r5;

int main(int argc, char** argv) {
  Settings settings;

  bool debug = false;
  bool print = false;
  bool check = false;
  bool write_bc = false;
  bool write_bc_as_c = false;
  bool write_cimple = false;

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
      case 'b':
        write_bc = true;
        write_bc_as_c = (s[2] == 'c');
        break;
      case 'C':
        write_cimple = true;
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

  const char* script = *opt++;
  env.import_args(S, opt, fin - opt); 

  Arguments root_args(S, 0, vm.stack());

  OOP ret;

  struct stat s;
  stat(script, &s);

  if(S_ISREG(s.st_mode) || S_ISLNK(s.st_mode)) {
    if(write_cimple) {
      FILE* file = fopen(script, "r");
      r5::check(file);

      Compiler compiler(debug);

      const char* name = *opt++;

      if(!name) {
        printf("specify a package name\n");
        return 1;
      }

      const char* output = *opt;

      if(!output) output = ".";

      if(!compiler.cimple(S, file, name, output)) return 1;
      return 0;
    }

    Code* code = Code::load_file(S, script);

    if(!code) {
      FILE* file = fopen(script, "r");
      r5::check(file);

      Compiler compiler(debug);

      if(!compiler.compile(S, String::internalize(S, script), file)) return 1;

      if(check) {
        printf("syntax ok\n");
        return 0;
      }

      code = compiler.code();

      if(write_bc) {
        char buf[1024];
        buf[0] = 0;
        strcat(buf, script);
        strcat(buf, "c");

        code->save(buf, write_bc_as_c);
        return 0;
      }
    }

    Module* m = new(S) Module(S,
        S.env().lookup(S, "Module").as_class(),
        String::internalize(S, "__main__"));

    Method* top = new(S) Method(String::internalize(S, "__main__"), code, env.globals());

    Arguments args = root_args.setup(m);
    ret = vm.run(S, top, args);
  } else {
    char buf[128];
    buf[0] = 0;
    strcat(buf, "bin/");
    strcat(buf, script);

    OOP bin_path_o = String::internalize(S, buf);

    Arguments args = root_args.setup(S.importer(), bin_path_o);
      
    ret = *args.apply(String::internalize(S, "import"));
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
        int line = i->method()->code()->line(i->ip());

        if(line <= 0) {
          std::cout << "    "
                    << i->method()->scope()->c_str() << "#"
                    << i->method()->name(S)->c_str() << " at "
                    << i->method()->code()->file()->c_str()
                    << "+" << i->ip()
                    << std::endl;
        } else {
          std::cout << "    "
                    << i->method()->scope()->c_str() << "#"
                    << i->method()->name(S)->c_str() << " at "
                    << i->method()->code()->file()->c_str()
                    << ":" << line
                    << std::endl;

        }

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

