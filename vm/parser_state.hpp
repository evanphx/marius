#ifndef PARSER_STATE_HPP
#define PARSER_STATE_HPP

#include <vector>

#include "code.hpp"
#include "parser.hpp"
#include "string_map.hpp"
#include "string_vector.hpp"

#include "ast.hpp"

namespace marius {
  class Parser;

  class ParserState {
    struct Context {
      std::vector<Instruction> buffer;
      std::vector<String*> strings;
      std::vector<Code*> codes;
      std::vector<ArgMap> keywords;

      ArgMap args; 
      ArgMap local_names;

      ast::ArgumentList arg_objs;

      int next_reg;

      int locals;

      Context()
        : next_reg(0)
        , locals(0)
      {}
    };

    struct ArgInfo {
      ast::Nodes nodes;
      ArgMap keywords;
    };

    State& S;
    Parser& parser_;
    Context* context_;
    ArgInfo arg_info_;

    std::vector<Context*> stack_;
    std::vector<ast::Cascade*> cascades_;
    std::vector<ArgInfo> arg_infos_;

    bool syntax_error_;

    ast::Scope* top_;

  public:

    ParserState(State& S, Parser& parse)
      : S(S)
      , parser_(parse)
      , context_(new Context)
      , syntax_error_(false)
      , top_(0)
    {}

    bool syntax_error_p() {
      return syntax_error_;
    }

    void set_syntax_error() {
      syntax_error_ = true;
    }

    ast::Scope* top() {
      return top_;
    }

    void set_top(ast::Node* n);

    Instruction* sequence();

    int sequence_size() {
      return context_->buffer.size();
    }

    std::vector<String*>* strings() {
      return new std::vector<String*>(context_->strings);
    }

    std::vector<Code*>* codes() {
      return new std::vector<Code*>(context_->codes);
    }

    void recycle(int a, int b) {
      if(a == b - 1) {
        context_->next_reg = a;
      }
    }

    void recycle(int a) {
      context_->next_reg = a;
    }

    int new_reg() {
      return context_->next_reg++;
    }

    void push(Instruction op) {
      context_->buffer.push_back(op);
    }

    int string(const char* str) {
      int idx = context_->strings.size();
      context_->strings.push_back(String::internalize(S, str));
      return idx;
    }

    int line() {
      return parser_.line();
    }

    int column() {
      return parser_.column();
    }

    int new_local() {
      return context_->locals++;
    }

    int locals() {
      return context_->locals;
    }

    void start_def(String* s);

    int bin_op(const char* op, int a, int b);
    int minus(int a, int b);
    int plus(int a, int b);
    int times(int a, int b);
    int divide(int a, int b);

    ast::Node* ret(ast::Node* n);

    ast::Node* seq(ast::Node* parent, ast::Node* child);
    ast::Node* ast_class(String* name, ast::Node* super, ast::Node* body);

    void start_class();
    int new_class(String* s);

    void start_def();
    void def_arg(String* s);
    void def_arg_cast(String* s, ast::Node* c);
    ast::Node* ast_def(String* name, ast::Node* b);

    ast::Node* send_indirect(ast::Node* recv, ast::Node* n);
    ast::Node* send_indirect_args(ast::Node* recv, ast::Node* n);

    ast::Node* call(ast::Node* recv, String* id);
    ast::Node* attr(ast::Node* recv, String* id);

    void start_cascade(ast::Node* n);
    void cascade(String* name);
    ast::Node* end_cascade();

    void start_arg_list();
    void add_arg(ast::Node* n);
    void add_kw_arg(String* id, ast::Node* n);
    ast::Node* call_args(ast::Node* n, String* id);
    ast::Node* call_args(ast::Node* n, const char* id);
    ast::Node* call_kw_args(ast::Node* n, String* id);

    ast::Node* dcolon(ast::Node* r, String* id, String* arg);
    ast::Node* lit_str(String* s);

    // AST
    ast::Node* named(String* s);
    ast::Node* number(int a);
    ast::Call* ast_call(String* name, ast::Node* r, ast::Nodes args);
    ast::Call* ast_binop(const char* s, ast::Node* a, ast::Node* b);
    ast::Call* ast_binop(String* op, ast::Node* a, ast::Node* b);
    ast::Node* if_cond(ast::Node* cond, ast::Node* body);
    ast::Node* unless(ast::Node* cond, ast::Node* body);
    ast::Node* while_(ast::Node* cond, ast::Node* body);

    ast::Node* ast_nil();
    ast::Node* ast_true();
    ast::Node* ast_false();
    ast::Node* self();

    ast::Node* import(String* name);

    ast::Node* ast_try(ast::Node* b, ast::Node* h);
    ast::Node* assign(String* name, ast::Node* n);
    ast::Node* ivar_assign(String* name, ast::Node* n);
    ast::Node* ivar_read(String* name);

    ast::Node* assign_op(String* name, String* op, ast::Node* n);
    ast::Node* ivar_assign_op(String* name, String* op, ast::Node* n);

    void start_lambda();
    ast::Node* lambda(ast::Node* b);

    ast::Node* cast(ast::Node* e, ast::Node* type);
    ast::Node* raise(ast::Node* v);

    ast::Node* not_(ast::Node* v);
    ast::Node* tuple();
    ast::Node* dict();
  };
}

#endif
