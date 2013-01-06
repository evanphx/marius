#ifndef AST_HPP
#define AST_HPP

#include <vector>

#include "code.hpp"
#include "string.hpp"

namespace marius {
  class String;

  namespace ast {
    class State {
      std::vector<Instruction> buffer;
      std::vector<String*> strings;
      std::vector<Code*> codes;
      std::vector<ArgMap> keywords;

      ArgMap args_;

      int next_reg;
    public:
      State(ArgMap args)
        : args_(args)
        , next_reg(args.size())
      {}

      int new_reg() {
        return next_reg++;
      }

      void recycle(int p) {
        next_reg = p;
      }

      void push(Instruction op) {
        buffer.push_back(op);
      }

      int string(String& str) {
        int idx = strings.size();
        strings.push_back(&str);
        return idx;
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

      Code* to_code();
      int find_arg(String& name);

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

  }
}

#endif