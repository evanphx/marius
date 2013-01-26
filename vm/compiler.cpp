#include "compiler.hpp"
#include "parser.hpp"
#include "ast.hpp"

#include "scope_tracker.hpp"
#include "local.hpp"

namespace marius {
  bool Compiler::compile(FILE* f) {
    Parser parser(f);

    if(!parser.parse(debug_)) return false;

    ast::Scope* top = parser.top();

    if(!top) return false;

    ArgMap globals;

    globals[String::internalize("io")] = 0;

    LocalMap locals;

    calculate_locals(top, globals, locals);

    ArgMap args;

    ast::State S(args, top->locals(), locals);

    top->drive(S, top->locals().size());

    code_ = S.to_code(top->cov());

    if(debug_) code_->print();

    return true;
  }
}
