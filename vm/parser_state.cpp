#include "parser_state.hpp"
#include <assert.h>

namespace marius {

  Instruction* ParserState::sequence() {
    size_t sz = context_->buffer.size();
    Instruction* seq = new Instruction[sz];

    for(size_t i = 0; i < sz; i++) {
      seq[i] = context_->buffer[i];
    }

    return seq;
  }

  void ParserState::set_top(ast::Node* b) {
    ast::Argument* a = new ast::Argument(String::internalize(S, "self"), -1);

    top_ = new ast::Scope(b, context_->local_names, a);
  }

  ast::Node* ParserState::seq(ast::Node* l, ast::Node* r) {
    return new ast::Seq(l, r);
  }

  ast::Node* ParserState::ast_class(String* name, ast::Node* super,
                                    ast::Node* body)
  {
    ast::Argument* a = new ast::Argument(String::internalize(S, "self"), -1);

    if(!super) {
      super = named(String::internalize(S, "Object"));
    }

    ast::Node* n = new ast::Class(name, super,
                     new ast::Scope(body, context_->local_names, a));

    delete context_;

    context_ = stack_.back();
    stack_.pop_back();

    return n;
  }

  ast::Node* ParserState::trait(String* name, ast::Node* body) {
    ast::Argument* a = new ast::Argument(String::internalize(S, "self"), -1);

    ast::Node* n = new ast::Trait(name,
                     new ast::Scope(body, context_->local_names, a));

    delete context_;

    context_ = stack_.back();
    stack_.pop_back();

    return n;
  }

  void ParserState::start_def() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  ast::Node* ParserState::ast_def(String* name, ast::Node* b) {
    ast::Argument* a = new ast::Argument(String::internalize(S, "self"), -1);

    ast::Node* n = new ast::Def(name, 
                     new ast::Scope(b, context_->local_names,
                        context_->args, context_->arg_objs, a),
                     context_->args);
    delete context_;

    context_ = stack_.back();
    stack_.pop_back();

    return n;
  }

  void ParserState::def_arg(String* name) {
    int num = context_->args.size();

    context_->args[name] = num;
    context_->arg_objs.push_back(new ast::Argument(name, num));
  }

  void ParserState::def_arg_cast(String* name, ast::Node* c) {
    int num = context_->args.size();

    context_->args[name] = num;
    context_->arg_objs.push_back(new ast::Argument(name, c, num));
  }

  ast::Node* ParserState::call(ast::Node* recv, String* n) {
    return new ast::Call(n, recv);
  }

  ast::Node* ParserState::self_call(String* n) {
    return new ast::Call(n, self(), 0, true);
  }

  ast::Node* ParserState::send_indirect(ast::Node* recv, ast::Node* n) {
    return new ast::SendIndirect(n, recv);
  }

  ast::Node* ParserState::send_indirect_args(ast::Node* recv, ast::Node* name) {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);

    n = new ast::SendIndirect(name, recv, args);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    return n;
  }

  ast::Node* ParserState::dcolon(ast::Node* recv, String* n, String* a) {
    return new ast::Call(n, recv, ast::Arguments::wrap(new ast::LiteralString(a)));
  }

  ast::Node* ParserState::lit_str(String* n) {
    return new ast::LiteralString(n);
  }

  ast::Node* ParserState::attr(ast::Node* r, String* n) {
    return new ast::LoadAttr(r, n);
  }

  ast::Node* ParserState::named(String* s) {
    return new ast::Named(s);
  }

  void ParserState::start_class() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  void ParserState::start_trait() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  ast::Call* ParserState::ast_call(String* name, ast::Node* r, ast::Nodes args) {
    return new ast::Call(name, r, new ast::Arguments(args));
  }

  ast::Call* ParserState::ast_binop(const char* s, ast::Node* a, ast::Node* b) {
    return new ast::Call(String::internalize(S, s), a, ast::Arguments::wrap(b));
  }

  ast::Call* ParserState::ast_binop(String* op, ast::Node* a, ast::Node* b) {
    return new ast::Call(op, a, ast::Arguments::wrap(b));
  }

  ast::Node* ParserState::number(int a) {
    return new ast::Number(a);
  }

  ast::Node* ParserState::ret(ast::Node* n) {
    return new ast::Return(n);
  }

  void ParserState::start_cascade(ast::Node* recv) {
    cascades_.push_back(new ast::Cascade(recv));
  }

  void ParserState::cascade(String* name) {
    cascades_.back()->push_message(new ast::CascadeCall(name));
  }

  ast::Node* ParserState::end_cascade() {
    ast::Node* n = cascades_.back();
    cascades_.pop_back();

    return n;
  }

  void ParserState::start_arg_list() {
    arg_infos_.push_back(arg_info_);

    arg_info_ = ArgInfo();
  }

  void ParserState::add_arg(ast::Node* a) {
    arg_info_.nodes.push_back(a);
  }

  void ParserState::add_kw_arg(String* name, ast::Node* a) {
    arg_info_.keywords[name] = arg_info_.nodes.size();
    arg_info_.nodes.push_back(a);
  }

  ast::Node* ParserState::call_args(ast::Node* recv, String* id) {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);

    n = new ast::Call(id, recv, args);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    assert(n);

    return n;
  }

  ast::Node* ParserState::self_call_args(String* id) {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);

    n = new ast::Call(id, self(), args, true);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    assert(n);

    return n;
  }

  ast::Node* ParserState::call_args(ast::Node* recv, const char* id) {
    return call_args(recv, String::internalize(S, id));
  }

  ast::Node* ParserState::tuple() {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);

    n = new ast::Tuple(args);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    assert(n);

    return n;
  }

  ast::Node* ParserState::list() {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);

    n = new ast::List(args);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    assert(n);

    return n;
  }

  ast::Node* ParserState::dict() {
    ast::Node* n = 0;

    ast::Arguments* args = new ast::Arguments(arg_info_.nodes, arg_info_.keywords);
    n = new ast::Dictionary(args);

    arg_info_ = arg_infos_.back();
    arg_infos_.pop_back();

    assert(n);

    return n;
  }

  ast::Node* ParserState::if_cond(ast::Node* cond, ast::Node* body) {
    return new ast::IfCond(cond, body);
  }

  ast::Node* ParserState::if_else(ast::Node* cond, ast::Node* body,
                                  ast::Node* ebody)
  {
    return new ast::IfCond(cond, body, ebody);
  }

  ast::Node* ParserState::unless(ast::Node* cond, ast::Node* body) {
    return new ast::Unless(cond, body);
  }

  ast::Node* ParserState::while_(ast::Node* cond, ast::Node* body) {
    return new ast::While(cond, body);
  }

  ast::Node* ParserState::ast_nil() {
    return new ast::Nil();
  }

  ast::Node* ParserState::ast_true() {
    return new ast::True();
  }

  ast::Node* ParserState::ast_false() {
    return new ast::False();
  }

  ast::Node* ParserState::self() {
    return new ast::Self();
  }

  ast::Node* ParserState::import(String* name) {
    return new ast::Import(S, name);
  }

  ast::Node* ParserState::import(String* path, String* name) {
    return new ast::Import(S, path, name);
  }

  ast::Node* ParserState::ast_try(ast::Node* b, ast::Node* h) {
    return new ast::Try(b, h);
  }

  ast::Node* ParserState::ast_try(ast::Node* b, String* id, ast::Node* t,
                                  ast::Node* h)
  {
    return new ast::Try(b, h, id, t);
  }

  ast::Node* ParserState::assign(String* name, ast::Node* n) {
    return new ast::Assign(name, n);
  }

  ast::Node* ParserState::ivar_assign(String* name, ast::Node* v) {
    return new ast::IvarAssign(name, v);
  }

  ast::Node* ParserState::assign_op(String* name, String* op, ast::Node* n) {
    return new ast::AssignOp(name, op, n);
  }

  ast::Node* ParserState::ivar_assign_op(String* name, String* op, ast::Node* n) {
    return new ast::IvarAssignOp(name, op, n);
  }

  ast::Node* ParserState::ivar_read(String* name) {
    return new ast::IvarRead(name);
  }

  void ParserState::start_lambda() {
    stack_.push_back(context_);

    context_ = new Context();
  }

  ast::Node* ParserState::lambda(ast::Node* b) {
    ast::Scope* sc = new ast::Scope(b, context_->local_names,
                        context_->args, context_->arg_objs, 0);

    ast::Node* n = new ast::Lambda(sc);

    delete context_;

    context_ = stack_.back();
    stack_.pop_back();

    return n;
  }

  ast::Node* ParserState::cast(ast::Node* e, ast::Node* type) {
    return new ast::Cast(e, type);
  }

  ast::Node* ParserState::raise(ast::Node* v) {
    return new ast::Raise(v);
  }

  ast::Node* ParserState::not_(ast::Node* v) {
    return new ast::Not(v);
  }

  ast::Node* ParserState::and_(ast::Node* a, ast::Node* b) {
    return new ast::And(a, b);
  }

  /*
  int ParserState::start_cond(int c) {
    push(GOTO_IF_FALSE);
    push(c);

    int l = buffer_.size();
    push(0);

    return l;
  }

  int ParserState::end_cond(int b, int l) {

  }
  */

}
