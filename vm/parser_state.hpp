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

      int next_reg;

      Context()
        : next_reg(0)
      {}
    };

    struct ArgInfo {
      ast::Nodes nodes;
      ArgMap keywords;
    };

    Parser& parser_;
    Context* context_;
    ArgInfo arg_info_;

    std::vector<Context*> stack_;
    std::vector<ast::Cascade*> cascades_;
    std::vector<ArgInfo> arg_infos_;

    bool syntax_error_;

    ast::Node* top_;

  public:

    ParserState(Parser& parse)
      : parser_(parse)
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

    ast::Node* top() {
      return top_;
    }

    void set_top(ast::Node* n) {
      top_ = n;
    }

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
      context_->strings.push_back(&String::internalize(str));
      return idx;
    }

    int line() {
      return parser_.line();
    }

    int column() {
      return parser_.column();
    }

    void start_def(String& s);

    int bin_op(const char* op, int a, int b);
    int minus(int a, int b);
    int plus(int a, int b);
    int times(int a, int b);
    int divide(int a, int b);

    ast::Node* ret(ast::Node* n);

    ast::Node* seq(ast::Node* parent, ast::Node* child);
    ast::Node* ast_class(String& name, ast::Node* body);

    void start_class();
    int new_class(String& s);

    void start_def();
    void def_arg(String& s);
    ast::Node* ast_def(String& name, ast::Node* b);

    ast::Node* call(ast::Node* recv, String& id);

    void start_cascade(ast::Node* n);
    void cascade(String& name);
    ast::Node* end_cascade();

    void start_arg_list();
    void add_arg(ast::Node* n);
    void add_kw_arg(String& id, ast::Node* n);
    ast::Node* call_args(ast::Node* n, String& id);
    ast::Node* call_kw_args(ast::Node* n, String& id);

    // AST
    ast::Node* named(String& s);
    ast::Node* number(int a);
    ast::Call* ast_call(String& name, ast::Node* r, ast::Nodes args);
    ast::Call* ast_binop(const char* s, ast::Node* a, ast::Node* b);
    ast::Node* if_cond(ast::Node* cond, ast::Node* body);

    ast::Node* ast_nil();
    ast::Node* ast_true();
    ast::Node* ast_false();

    ast::Node* import(String& name);

    ast::Node* ast_try(ast::Node* b, ast::Node* h);
  };
}

#endif
