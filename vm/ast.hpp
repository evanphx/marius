#ifndef AST_HPP
#define AST_HPP

#include <vector>

#include "code.hpp"
#include "string.hpp"

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

      ArgMap args_;
      ArgMap locals_;

      int next_reg;

    public:
      State(ArgMap args, ArgMap locals)
        : args_(args)
        , locals_(locals)
        , next_reg(args.size())
      {}

      int new_reg() {
        return next_reg++;
      }

      void recycle(int p) {
        next_reg = p;
      }

      void reserve(int c) {
        next_reg = c;
      }

      void push(Instruction op) {
        buffer.push_back(op);
      }

      int string(String& str) {
        int idx = strings.size();
        strings.push_back(&str);
        return idx;
      }

      int string(const char* n) {
        return string(String::internalize(n));
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

      void set_label(Label l) {
        buffer[l.idx_] = buffer.size() - l.idx_ - 1;
      }

      void set_label_abs(Label l) {
        buffer[l.idx_] = buffer.size();
      }

      Code* to_code();
      int find_local(String& name);

    };

    class Node {
    public:
      virtual int drive(State& S, int t) = 0;
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
    };

    class Top : public Node {
      ArgMap locals_;
      Node* body_;

    public:
      Top(ast::Node* body, ArgMap& locals)
        : locals_(locals)
        , body_(body)
      {}

      ArgMap& locals() {
        return locals_;
      }

      int drive(State& S, int t);
    };

    typedef std::vector<Node*> Nodes;

    class Call : public Node {
    protected:
      String& name_;
      Node* recv_;
      Nodes args_;

    public:
      Call(String& name, Node* recv, Nodes args)
        : name_(name)
        , recv_(recv)
        , args_(args)
      {}

      int drive(State& S, int t);
    };

    class CallWithKeywords : public Call {
      ArgMap keywords_;

    public:
      CallWithKeywords(String& name, Node* recv, Nodes args, ArgMap keys)
        : Call(name, recv, args)
        , keywords_(keys)
      {}

      int drive(State& S, int t);
    };

    class Number : public Node {
      int val_;

    public:
      Number(int v)
        : val_(v)
      {}

      int drive(State& S, int t);
    };

    class Named : public Node {
      String& name_;

    public:
      Named(String& n)
        : name_(n)
      {}

      int drive(State& S, int t);
    };

    class Return : public Node {
      Node* val_;

    public:
      Return(Node* n)
        : val_(n)
      {}

      int drive(State& S, int t);
    };

    class Class : public Node {
      String& name_;
      Node* body_;

    public:
      Class(String& n, Node* b)
        : name_(n)
        , body_(b)
      {}

      int drive(State& S, int t);
    };

    class Def : public Node {
      String& name_;
      Node* body_;
      ArgMap args_;

    public:
      Def(String& name, Node* body, ArgMap args)
        : name_(name)
        , body_(body)
        , args_(args)
      {}

      int drive(State& S, int t);
    };

    class CascadeCall : public Node {
      String& name_;

    public:

      CascadeCall(String& n)
        : name_(n)
      {}

      int drive(State& S, int t);
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
    };

    class Nil : public Node {
    public:
      int drive(State& S, int t);
    };

    class False : public Node {
    public:
      int drive(State& S, int t);
    };

    class True : public Node {
    public:
      int drive(State& S, int t);
    };

    class Import : public Node {
      String& name_;

    public:
      Import(String& n)
        : name_(n)
      {}

      int drive(State& S, int t);
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
    };

    class Assign : public Node {
      String& name_;
      int reg_;
      Node* value_;

    public:
      Assign(String& n, int r, Node* v)
        : name_(n)
        , reg_(r)
        , value_(v)
      {}

      int drive(State& S, int t);
    };
  }
}

#endif
