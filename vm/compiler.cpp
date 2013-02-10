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

    globals[String::internalize("Object")] = 0;
    globals[String::internalize("io")] = 1;
    globals[String::internalize("Class")] = 2;
    globals[String::internalize("Importer")] = 3;

    LocalMap locals;

    calculate_locals(top, globals, locals);

    ast::State S(locals);

    top->drive(S, top->locals().size());

    ArgMap args;

    code_ = S.to_code(args, top->cov());

    if(debug_) code_->print();

    return true;
  }
}
