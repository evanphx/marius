#include "compiler.hpp"
#include "parser.hpp"
#include "ast.hpp"

namespace marius {
  bool Compiler::compile(FILE* f) {
    Parser parser(f);

    if(!parser.parse(debug_)) return false;

    ast::Scope* top = parser.top();

    if(!top) return false;

    ArgMap args;

    ast::State S(args, top->locals());

    top->drive(S, top->locals().size());

    code_ = S.to_code();

    if(debug_) code_->print();

    return true;
  }
}
