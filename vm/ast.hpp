#ifndef AST_HPP
#define AST_HPP

#include <vector>

#include "code.hpp"
#include "string.hpp"
#include "local.hpp"

namespace marius {
  class String;

  namespace ast {

    class State;

    class Label {
      int idx_;

    public:
      Label(int idx)
        : idx_(idx)
      {}

      friend class State;
    };

    class State {
      std::vector<Instruction> buffer;
      std::vector<String*> strings;
      std::vector<Code*> codes;
      std::vector<ArgMap> keywords;

      LocalMap& lm_;

    public:
      marius::State& MS;

      State(marius::State& ms, LocalMap& lm)
        : lm_(lm)
        , MS(ms)
      {}

      LocalMap& lm() {
        return lm_;
      }

      void push(Instruction op) {
        buffer.push_back(op);
      }

      int string(String* str) {
        int idx = strings.size();
        strings.push_back(str);
        return idx;
      }

      int string(const char* n) {
        return string(String::internalize(MS, n));
      }

      int code(Code* code) {
        int idx = codes.size();
        codes.push_back(code);
        return idx;
      }

      int keyword(ArgMap kw) {
        int idx = keywords.size();
        keywords.push_back(kw);
        return idx;
      }

      Label label() {
        return Label(buffer.size());
      }

      int pos() {
        return buffer.size();
      }

      void set_label(Label l) {
        buffer[l.idx_] = buffer.size() - l.idx_ - 1;
      }

      void set_label_abs(Label l) {
        buffer[l.idx_] = buffer.size();
      }

      void set_local(Local* l, int t);
      void get_local(Local* l, int t);

      Code* to_code(String* name, ArgMap& args, int cov);

    };

    class Visitor;

    class Node {
    public:
      virtual int drive(State& S, int t) = 0;

      virtual void accept(Visitor* V) = 0;
    };

    class Seq : public Node {
      ast::Node* parent_;
      ast::Node* child_;

    public:
      Seq(ast::Node* p, ast::Node* c)
        : parent_(p)
        , child_(c)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Argument : public Node {
      String* name_;
      Node* cast_;
      int position_;

    public:
      Argument(String* n, int p)
        : name_(n)
        , cast_(0)
        , position_(p)
      {}

      Argument(String* n, Node* c, int p)
        : name_(n)
        , cast_(c)
        , position_(p)
      {}

      String* name() {
        return name_;
      }

      int position() {
        return position_;
      }

      Node* cast() {
        return cast_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    typedef std::vector<Argument*> ArgumentList;

    class Scope : public Node {
      ArgMap locals_;
      ArgMap closed_locals_;
      ArgMap arguments_;

      ArgumentList arg_objs_;

      Argument* self_;

      Node* body_;

    public:
      Scope(ast::Node* body, ArgMap& locals, ast::Argument* self)
        : locals_(locals)
        , self_(self)
        , body_(body)
      {}

      Scope(ast::Node* body, ArgMap& locals, ArgMap args, ArgumentList& ao,
            ast::Argument* self)
        : locals_(locals)
        , arguments_(args)
        , arg_objs_(ao)
        , self_(self)
        , body_(body)
      {}

      ArgMap& locals() {
        return locals_;
      }

      ArgMap& arguments() {
        return arguments_;
      }

      ArgumentList& arg_objs() {
        return arg_objs_;
      }

      ast::Argument* self() {
        return self_;
      }

      int cov() {
        return closed_locals_.size();
      }

      int drive(State& S, int t);
      void accept(Visitor* V);

      void add_local(String* n, int reg) {
        locals_[n] = reg;
      }

      void add_closed_local(String* n, int loc) {
        closed_locals_[n] = loc;
      }
    };

    typedef std::vector<Node*> Nodes;

    struct Arguments {
      Nodes positional;
      ArgMap keywords;

      Arguments(Nodes p, ArgMap k)
        : positional(p)
        , keywords(k)
      {}

      Arguments(Nodes p)
        : positional(p)
      {}

      static Arguments* wrap(ast::Node* n);
    };

    class SendIndirect : public Node {
    protected:
      Node* name_;
      Node* recv_;
      Arguments* args_;

    public:
      SendIndirect(Node* name, Node* recv, Arguments* args=0)
        : name_(name)
        , recv_(recv)
        , args_(args)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Tuple : public Node {
      Arguments* args_;

    public:
      Tuple(Arguments* a)
        : args_(a)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Dictionary : public Node {
      Arguments* args_;

    public:
      Dictionary(Arguments* a)
        : args_(a)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Call : public Node {
    protected:
      String* name_;
      Node* recv_;
      Arguments* args_;

    public:
      Call(String* name, Node* recv, Arguments* args=0)
        : name_(name)
        , recv_(recv)
        , args_(args)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Number : public Node {
      int val_;

    public:
      Number(int v)
        : val_(v)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Named : public Node {
      String* name_;

    public:
      Named(String* n)
        : name_(n)
      {}

      String* name() {
        return name_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Return : public Node {
      Node* val_;

    public:
      Return(Node* n)
        : val_(n)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Class : public Node {
      String* name_;
      Node* super_;
      Scope* body_;

    public:
      Class(String* n, Node* sup, Scope* b)
        : name_(n)
        , super_(sup)
        , body_(b)
      {}

      String* name() {
        return name_;
      }

      Node* super() {
        return super_;
      }

      Scope* body() {
        return body_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Def : public Node {
      String* name_;
      Scope* body_;
      ArgMap args_;

    public:
      Def(String* name, Scope* body, ArgMap args)
        : name_(name)
        , body_(body)
        , args_(args)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class CascadeCall : public Node {
      String* name_;

    public:

      CascadeCall(String* n)
        : name_(n)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Cascade : public Node {
      ast::Node* recv_;
      ast::Nodes messages_;

    public:
      Cascade(ast::Node* n)
        : recv_(n)
      {}

      void push_message(ast::Node* n) {
        messages_.push_back(n);
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class IfCond : public Node {
      ast::Node* recv_;
      ast::Node* body_;

    public:
      IfCond(ast::Node* r, ast::Node* b)
        : recv_(r)
        , body_(b)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Unless : public Node {
      ast::Node* recv_;
      ast::Node* body_;

    public:
      Unless(ast::Node* r, ast::Node* b)
        : recv_(r)
        , body_(b)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class While : public Node {
      ast::Node* cond_;
      ast::Node* body_;

    public:
      While(ast::Node* r, ast::Node* b)
        : cond_(r)
        , body_(b)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Nil : public Node {
    public:
      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class False : public Node {
    public:
      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class True : public Node {
    public:
      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Self : public Node {
    public:
      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Import : public Node {
      String* path_;
      String* name_;

    public:
      Import(marius::State& S, String* n);
      Import(marius::State& S, String* p, String* n);

      String* name() {
        return name_;
      }

      String* path() {
        return path_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Try : public Node {
      Node* body_;
      Node* handler_;

    public:
      Try(Node* b, Node* h)
        : body_(b)
        , handler_(h)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Assign : public Node {
      String* name_;
      Node* value_;

    public:
      Assign(String* n, Node* v)
        : name_(n)
        , value_(v)
      {}

      String* name() {
        return name_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class AssignOp : public Node {
      String* name_;
      String* op_;
      Node* value_;

    public:
      AssignOp(String* n, String* o, Node* v)
        : name_(n)
        , op_(o)
        , value_(v)
      {}

      String* name() {
        return name_;
      }

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class LoadAttr : public Node {
      Node* recv_;
      String* name_;

    public:
      LoadAttr(Node* recv, String* n)
        : recv_(recv)
        , name_(n)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class IvarAssign : public Node {
      String* name_;
      Node* value_;

    public:
      IvarAssign(String* n, Node* v)
        : name_(n)
        , value_(v)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class IvarAssignOp : public Node {
      String* name_;
      String* op_;
      Node* value_;

    public:
      IvarAssignOp(String* n, String* o, Node* v)
        : name_(n)
        , op_(o)
        , value_(v)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class IvarRead : public Node {
      String* name_;

    public:
      IvarRead(String* n)
        : name_(n)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class LiteralString : public Node {
      String* str_;

    public:
      LiteralString(String* n)
        : str_(n)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Lambda : public Node {
      Scope* body_;

    public:
      Lambda(Scope* b)
        : body_(b)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Cast : public Node {
      Node* value_;
      Node* type_;

    public:
      Cast(Node* v, Node* t)
        : value_(v)
        , type_(t)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Raise : public Node {
      Node* value_;

    public:
      Raise(Node* v)
        : value_(v)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Not : public Node {
      Node* value_;

    public:
      Not(Node* v)
        : value_(v)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class And : public Node {
      Node* left_;
      Node* right_;

    public:
      And(Node* a, Node* b)
        : left_(a)
        , right_(b)
      {}

      int drive(State& S, int t);
      void accept(Visitor* V);
    };

    class Visitor {
    public:
      virtual void before_visit(Scope* n) { };
      virtual void before_visit(Class* n) { };

      virtual void visit(Seq* n) { };
      virtual void visit(Scope* n) { };
      virtual void visit(SendIndirect* i) { };
      virtual void visit(Call* n) { };
      virtual void visit(Number* n) { };
      virtual void visit(Named* n) { };
      virtual void visit(Def* n) { };
      virtual void visit(Class* n) { };
      virtual void visit(Return* n) { };
      virtual void visit(Cascade* n) { };
      virtual void visit(CascadeCall* n) { };
      virtual void visit(IfCond* n) { };
      virtual void visit(Unless* n) { };
      virtual void visit(Nil* n) { };
      virtual void visit(True* n) { };
      virtual void visit(False* n) { };
      virtual void visit(Import* n) { };
      virtual void visit(Try* n) { };
      virtual void visit(Assign* n) { };
      virtual void visit(AssignOp* n) { };
      virtual void visit(LoadAttr* n) { };
      virtual void visit(IvarAssign* n) { };
      virtual void visit(IvarAssignOp* n) { };
      virtual void visit(IvarRead* n) { };
      virtual void visit(LiteralString* n) { };
      virtual void visit(Lambda* l) { };
      virtual void visit(Argument* a) {}
      virtual void visit(Self* s) {}
      virtual void visit(Cast* s) {}
      virtual void visit(Raise* r) {}
      virtual void visit(Not* r) {}
      virtual void visit(Tuple* t) {}
      virtual void visit(While* t) {}
      virtual void visit(Dictionary* t) {}
      virtual void visit(And* a) {}
    };

  }
}

#endif
