#include "vm.hpp"
#include "environment.hpp"
#include "string.hpp"
#include "code.hpp"
#include "class.hpp"
#include "parser.hpp"
#include "state.hpp"

#include <vector>
#include <iostream>

using namespace marius;

int main(int argc, char** argv) {

  bool debug = false;
  char** opt = argv + 1;

  while(*opt) {
    if(**opt == '-') {
      switch(*opt[1]) {
      case 'd':
        debug = false;
        break;
      default:
        printf("Unknown option: %s\n", *opt);
        return 1;
      }
    } else {
      break;
    }
  }

  if(!*opt) {
    printf("Require a filename\n");
    return 1;
  }

  VM vm(debug);
  Environment env;

  State state(vm, env);

  env.init_ontology();

  FILE* file = fopen(*opt, "r");
  if(!file) {
    printf("Unable to open: %s\n", *opt);
    return 1;
  }

  Parser parser(file);

  parser.parse();

  if(debug) parser.code()->print();

  OOP ret = vm.run(state, *parser.code());

  ret.print();
  return 0;
}

/*
int man_main(int argc, char** argv) {
  VM vm;
  Environment env;

  env.init_ontology();

  std::vector<String*> strings;
  std::vector<Code*> codes;

  strings.push_back(&String::internalize("+"));

  Instruction seq[] = {
    MOVI8, 0, 3,
    MOVI8, 1, 4,
    CALL, 0, 0, 0, 1, 1,
    RET, 0
  };

  Code code(seq, sizeof(seq), strings, codes);

  code.print();

  OOP ret = vm.run(env, code);

  std::cout << "ret = " << ret.int_value() << "\n";

  std::vector<String*> strings2;
  std::vector<Code*> codes2;

  strings2.push_back(&String::internalize("Class"));
  strings2.push_back(&String::internalize("Blah"));
  strings2.push_back(&String::internalize("new"));
  strings2.push_back(&String::internalize("foo"));
  strings2.push_back(&String::internalize("add_method"));

  Instruction seq2[] = {
    LOADN, 0, 0,
    LOADS, 1, 1,
    CALL, 0, 0, 2, 1, 1,
    LOADS, 1, 3,
    LOADC, 2, 0,
    CALL, 1, 0, 4, 2, 1,
    CALL, 0, 0, 2, 0, 0,
    CALL, 0, 0, 3, 0, 0,
    RET, 0
  };

  codes2.push_back(new Code(seq, sizeof(seq), strings, codes));

  Code code2(seq2, sizeof(seq2), strings2, codes2);

  OOP ret2 = vm.run(env, code2);

  std::cout << "ret = " << ret2.int_value() << "\n";
  // std::cout << "ret = " << ret2.as_class()->name().c_str() << "\n";

  return 0;
}
*/
