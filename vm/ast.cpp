#include "ast.hpp"
#include <assert.h>

namespace marius {
namespace ast {

  Arguments* Arguments::wrap(ast::Node* n) {
    ast::Nodes nodes;
    nodes.push_back(n);

    return new Arguments(nodes);
  }

  Code* State::to_code(String& name, ArgMap& args, int cov) {
    size_t sz = buffer.size();
    Instruction* seq = new Instruction[sz];

    for(size_t i = 0; i < sz; i++) {
      seq[i] = buffer[i];
    }

    return new(MS) Code(name, seq, buffer.size(), strings, codes,
                    args, keywords, cov);
  }

  void State::set_local(Local* l, int t) {
    if(l->reg_p()) {
      push(MOVR);
      push(l->idx());
      push(t);
    } else {
      push(SVAR);
      push(l->depth());
      push(l->idx());
      push(t);
    }
  }

  void State::get_local(Local* l, int t) {
    if(l->reg_p()) {
      if(l->idx() == -1) {
        push(SELF);
        push(t);
      } else {
        push(MOVR);
        push(t);
        push(l->idx());
      }
    } else {
      push(LVAR);
      push(t);
      push(l->depth());
      push(l->idx());
    }
  }

  int Seq::drive(State& S, int t) {
    parent_->drive(S, t);
    return child_->drive(S, t);
  }
  
  void Seq::accept(Visitor* V) {
    parent_->accept(V);
    child_->accept(V);
    V->visit(this);
  }

  int Scope::drive(State& S, int t) {
    if(self_) self_->drive(S, t);

    for(ArgumentList::iterator i = arg_objs_.begin();
        i != arg_objs_.end();
        ++i) {
      Argument* a = *i;
      a->drive(S, t);
    }

    body_->drive(S, t);

    return t;
  }

  void Scope::accept(Visitor* V) {
    V->before_visit(this);
    body_->accept(V);
    V->visit(this);
  }

  int SendIndirect::drive(State& S, int t) {
    name_->drive(S, t);
    recv_->drive(S, t+1);

    int j = t+2;

    int count = 0;

    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->drive(S,j++);
      }

      count = args_->positional.size();
    }

    S.push(SENDI);
    S.push(t);
    S.push(t);
    S.push(t+1);
    S.push(count);

    return t;
  }

  void SendIndirect::accept(Visitor* V) {
    recv_->accept(V);
    name_->accept(V);

    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->accept(V);
      }
    }

    V->visit(this);
  }

  int Cast::drive(State& S, int t) {
    type_->drive(S, t);
    value_->drive(S, t+1);

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize(S.MS, "cast")));
    S.push(t);
    S.push(1);

    return t;
  }

  void Cast::accept(Visitor* V) {
    type_->accept(V);
    value_->accept(V);

    V->visit(this);
  }

  int Tuple::drive(State& S, int t) {
    int count = 0;

    int j = t;

    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->drive(S,j++);
      }

      count = args_->positional.size();
    }

    S.push(TUPLE);
    S.push(t);
    S.push(t);
    S.push(count);

    return t;
  }

  void Tuple::accept(Visitor* V) {
    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->accept(V);
      }
    }

    V->visit(this);
  }

  int Call::drive(State& S, int t) {
    recv_->drive(S, t);

    int j = t+1;

    int count = 0;
    bool kw = false;

    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->drive(S,j++);
      }

      count = args_->positional.size();
      kw = args_->keywords.size() > 0;
    }

    S.push(kw ? CALL_KW : CALL);
    S.push(t);
    S.push(S.string(name_));
    S.push(t);
    S.push(count);

    if(kw) {
      S.push(S.keyword(args_->keywords));
    }


    return t;
  }

  void Call::accept(Visitor* V) {
    recv_->accept(V);

    if(args_) {
      for(Nodes::iterator i = args_->positional.begin();
          i != args_->positional.end();
          ++i) {
        (*i)->accept(V);
      }
    }

    V->visit(this);
  }

  int Number::drive(State& S, int t) {
    S.push(MOVI8);
    S.push(t);
    S.push(val_);

    return t;
  }

  void Number::accept(Visitor* V) {
    V->visit(this);
  }

  int Named::drive(State& S, int t) {
    Local* l = S.lm().get(this);

    if(l) {
      S.get_local(l, t);
    } else {
      S.push(LOADN);
      S.push(t);
      S.push(S.string(name_));
    }

    return t;
  }

  void Named::accept(Visitor* V) {
    V->visit(this);
  }

  void Argument::accept(Visitor* V) {
    V->visit(this);
  }

  int Argument::drive(State& S, int t) {
    Local* l = S.lm().get(this);

    // We don't have to do anything, it's there already.
    if(l->reg_p()) return t;

    S.set_local(l, position_);

    return t;
  }

  int Def::drive(State& S, int t) {
    S.push(SELF);
    S.push(t);

    S.push(LOADS);
    S.push(t+1);
    S.push(S.string(name_));

    ast::State subS(S.MS, S.lm());

    int r = body_->drive(subS, args_.size() + body_->locals().size());
    subS.push(RET);
    subS.push(r);

    S.push(LOADC);
    S.push(t+2);
    S.push(S.code(subS.to_code(name_, args_, body_->cov())));

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize(S.MS, "add_method")));
    S.push(t);
    S.push(2);

    return t;
  }

  void Def::accept(Visitor* V) {
    body_->accept(V);
    V->visit(this);
  }

  int Class::drive(State& S, int t) {
    super_->drive(S, t);

    int si = S.string(name_);

    S.push(LOADS);
    S.push(t+1);
    S.push(si);

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize(S.MS, "new_subclass")));
    S.push(t);
    S.push(1);

    S.push(IVA);
    S.push(si);
    S.push(t);

    Local* l = S.lm().get(body_);
    assert(l);

    S.set_local(l, t);

    ast::State subS(S.MS, S.lm());
    int r = body_->drive(subS, body_->locals().size());
    subS.push(RET);
    subS.push(r);

    ArgMap args;

    S.push(LOADC);
    S.push(t+1);
    S.push(S.code(subS.to_code(String::internalize(S.MS, "__body__"),
                               args, body_->cov())));

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize(S.MS, "run_body")));
    S.push(t);
    S.push(1);

    return t;
  }

  void Class::accept(Visitor* V) {
    V->before_visit(this);
    if(super_) super_->accept(V);
    body_->accept(V);
    V->visit(this);
  }

  int Return::drive(State& S, int t) {
    val_->drive(S, t);

    S.push(RET);
    S.push(t);

    return t;
  }

  void Return::accept(Visitor* V) {
    val_->accept(V);
    V->visit(this);
  }

  int Cascade::drive(State& S, int t) {
    recv_->drive(S, t);

    for(ast::Nodes::iterator i = messages_.begin();
        i != messages_.end();
        ++i) {
      (*i)->drive(S, t);
    }

    S.push(MOVR);
    S.push(t);
    S.push(t+1);

    return t;
  }

  void Cascade::accept(Visitor* V) {
    recv_->accept(V);

    for(ast::Nodes::iterator i = messages_.begin();
        i != messages_.end();
        ++i) {
      (*i)->accept(V);
    }

    V->visit(this);
  }

  int CascadeCall::drive(State& S, int t) {
    S.push(CALL);
    S.push(t+1);
    S.push(S.string(name_));
    S.push(t);
    S.push(0);

    return t;
  }

  void CascadeCall::accept(Visitor* V) {
    V->visit(this);
  }

  int While::drive(State& S, int t) {
    int top = S.pos();

    cond_->drive(S, t);
    S.push(JMPIF);
    S.push(t);

    Label l = S.label();
    S.push(0);

    body_->drive(S, t);

    S.push(JMPB);
    S.push(S.pos() - top - 1);

    S.set_label(l);

    return t;
  }

  void While::accept(Visitor* V) {
    cond_->accept(V);
    body_->accept(V);

    V->visit(this);
  }

  int IfCond::drive(State& S, int t) {
    recv_->drive(S, t);
    S.push(JMPIF);
    S.push(t);

    Label l = S.label();
    S.push(0);

    body_->drive(S, t);

    S.set_label(l);

    return t;
  }

  void IfCond::accept(Visitor* V) {
    recv_->accept(V);
    body_->accept(V);

    V->visit(this);
  }

  int Unless::drive(State& S, int t) {
    recv_->drive(S, t);
    S.push(JMPIT);
    S.push(t);

    Label l = S.label();
    S.push(0);

    body_->drive(S, t);

    S.set_label(l);

    return t;
  }

  void Unless::accept(Visitor* V) {
    recv_->accept(V);
    body_->accept(V);

    V->visit(this);
  }

  int Nil::drive(State& S, int t) {
    S.push(MOVN);
    S.push(t);

    return t;
  }

  void Nil::accept(Visitor* V) {
    V->visit(this);
  }

  int True::drive(State& S, int t) {
    S.push(MOVT);
    S.push(t);

    return t;
  }

  void True::accept(Visitor* V) {
    V->visit(this);
  }

  int False::drive(State& S, int t) {
    S.push(MOVF);
    S.push(t);

    return t;
  }

  void False::accept(Visitor* V) {
    V->visit(this);
  }

  int Self::drive(State& S, int t) {
    Local* l = S.lm().get(this);

    assert(l);

    S.get_local(l, t);

    return t;
  }

  void Self::accept(Visitor* V) {
    V->visit(this);
  }

  int Import::drive(State& S, int t) {
    Local* l = S.lm().get(this);
    assert(l);

    S.get_local(l->extra(), t);

    S.push(CALL);
    S.push(t);
    S.push(S.string("current"));
    S.push(t);
    S.push(0);

    S.push(LOADS);
    S.push(t+1);
    S.push(S.string(name_));

    S.push(CALL);
    S.push(t);
    S.push(S.string("import"));
    S.push(t);
    S.push(1);

    S.set_local(l, t);

    return t;
  }

  void Import::accept(Visitor* V) {
    V->visit(this);
  }

  int Try::drive(State& S, int t) {
    S.push(REGE);
    S.push(t);

    Label h = S.label();
    S.push(0);

    body_->drive(S, t);

    S.push(POPE);

    S.push(JMPF);

    Label b = S.label();
    S.push(0);

    S.set_label_abs(h);

    handler_->drive(S, t);

    S.set_label(b);

    return t;
  }

  void Try::accept(Visitor* V) {
    body_->accept(V);
    handler_->accept(V);

    V->visit(this);
  }

  int Assign::drive(State& S, int t) {
    value_->drive(S, t);

    Local* l = S.lm().get(this);
    assert(l);

    S.set_local(l, t);

    return t;
  }

  void Assign::accept(Visitor* V) {
    value_->accept(V);

    V->visit(this);
  }

  int LoadAttr::drive(State& S, int t) {
    recv_->drive(S, t);
    S.push(LATTR);
    S.push(t);
    S.push(S.string(name_));
    S.push(t);

    return t;
  }

  void LoadAttr::accept(Visitor* V) {
    recv_->accept(V);
    V->visit(this);
  }

  int IvarAssign::drive(State& S, int t) {
    value_->drive(S, t);
    S.push(IVA);
    S.push(S.string(name_));
    S.push(t);

    return t;
  }

  void IvarAssign::accept(Visitor* V) {
    value_->accept(V);
    V->visit(this);
  }

  int IvarRead::drive(State& S, int t) {
    S.push(IVR);
    S.push(t);
    S.push(S.string(name_));

    return t;
  }

  void IvarRead::accept(Visitor* V) {
    V->visit(this);
  }

  int LiteralString::drive(State& S, int t) {
    S.push(LOADS);
    S.push(t);
    S.push(S.string(str_));

    return t;
  }

  void LiteralString::accept(Visitor* V) {
    V->visit(this);
  }

  int Lambda::drive(State& S, int t) {
    ast::State subS(S.MS, S.lm());

    int r = body_->drive(subS, body_->locals().size());

    subS.push(RET);
    subS.push(r);

    ArgMap args;

    S.push(LOADC);
    S.push(t);
    S.push(S.code(subS.to_code(String::internalize(S.MS, "__lambda__"),
                               args, body_->cov())));

    return t;
  }

  void Lambda::accept(Visitor* V) {
    body_->accept(V);
    V->visit(this);
  }

  int Raise::drive(State& S, int t) {
    value_->drive(S, t);
    S.push(RAISE);
    S.push(t);

    return t;
  }

  void Raise::accept(Visitor* V) {
    value_->accept(V);
    V->visit(this);
  }

  int Not::drive(State& S, int t) {
    value_->drive(S, t);
    S.push(NOT);
    S.push(t);
    S.push(t);

    return t;
  }

  void Not::accept(Visitor* V) {
    value_->accept(V);
    V->visit(this);
  }
}}
