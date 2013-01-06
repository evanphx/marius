#include "compiler.hpp"
#include "parser.hpp"
#include "ast.hpp"

namespace marius {
  bool Compiler::compile(FILE* f) {
    Parser parser(f);

    if(!parser.parse()) return false;

    ast::Node* top = parser.top();

    if(!top) return false;

    ArgMap args;

    ast::State S(args);

    top->drive(S, 0);

    code_ = S.to_code();

    if(debug_) code_->print();

    return true;
  }
}