#include "ast.hpp"
#include <assert.h>

namespace marius {
namespace ast {

  Code* State::to_code() {
    size_t sz = buffer.size();
    Instruction* seq = new Instruction[sz];

    for(size_t i = 0; i < sz; i++) {
      seq[i] = buffer[i];
    }

    return new Code(seq, buffer.size(), strings, codes,
                    args_, keywords);
  }

  int State::find_local(String& name) {
    ArgMap::iterator i = args_.find(name);
    if(i != args_.end()) return i->second;

    i = locals_.find(name);
    if(i != locals_.end()) return i->second;

    return -1;
  }

  bool State::find_local_at_depth(String& name, int* depth, int* idx) {
    return false;

    ArgMap::iterator i = args_.find(name);
    if(i != args_.end()) return i->second;

    i = locals_.find(name);
    if(i != locals_.end()) return i->second;

    return -1;
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
    body_->drive(S, t);

    return t;
  }

  void Scope::accept(Visitor* V) {
    V->before_visit(this);
    body_->accept(V);
    V->visit(this);
  }

  int Call::drive(State& S, int t) {
    recv_->drive(S, t);

    int j = t+1;

    for(Nodes::iterator i = args_.begin();
        i != args_.end();
        ++i) {
      (*i)->drive(S,j++);
    }

    S.push(CALL);
    S.push(t);
    S.push(S.string(name_));
    S.push(t);
    S.push(args_.size());

    return t;
  }

  void Call::accept(Visitor* V) {
    recv_->accept(V);

    for(Nodes::iterator i = args_.begin();
        i != args_.end();
        ++i) {
      (*i)->accept(V);
    }

    V->visit(this);
  }

  int CallWithKeywords::drive(State& S, int t) {
    recv_->drive(S, t);

    int j = t+1;

    for(Nodes::iterator i = args_.begin();
        i != args_.end();
        ++i) {
      (*i)->drive(S,j++);
    }

    S.push(CALL_KW);
    S.push(t);
    S.push(S.string(name_));
    S.push(t);
    S.push(args_.size());
    S.push(S.keyword(keywords_));

    return t;
  }

  void CallWithKeywords::accept(Visitor* V) {
    recv_->accept(V);

    for(Nodes::iterator i = args_.begin();
        i != args_.end();
        ++i) {
      (*i)->accept(V);
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
      if(l->reg_p()) {
        S.push(MOVR);
        S.push(t);
        S.push(l->idx());
      } else {
        S.push(LVAR);
        S.push(t);
        S.push(l->depth());
        S.push(l->idx());
      }
    } else {
      S.push(LOADN);
      S.push(t);
      S.push(S.string(name_));
    }

    return t;

    int reg = S.find_local(name_);
    if(reg >= 0) {
      S.push(MOVR);
      S.push(t);
      S.push(reg);
    } else {
      int depth;

      if(S.find_local_at_depth(name_, &depth, &reg)) {
        S.push(LVAR);
        S.push(t);
        S.push(depth);
        S.push(reg);
      } else {
        S.push(LOADN);
        S.push(t);
        S.push(S.string(name_));
      }
    }

    return t;
  }

  void Named::accept(Visitor* V) {
    V->visit(this);
  }

  int Def::drive(State& S, int t) {
    S.push(SELF);
    S.push(t);

    S.push(LOADS);
    S.push(t+1);
    S.push(S.string(name_));

    ast::State subS(args_, body_->locals(), S.lm());

    int r = body_->drive(subS, args_.size() + body_->locals().size());
    subS.push(RET);
    subS.push(r);

    S.push(LOADC);
    S.push(t+2);
    S.push(S.code(subS.to_code()));

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize("add_method")));
    S.push(t);
    S.push(2);

    return t;
  }

  void Def::accept(Visitor* V) {
    body_->accept(V);
    V->visit(this);
  }

  int Class::drive(State& S, int t) {
    S.push(LOADN);
    S.push(t);
    S.push(S.string(String::internalize("Class")));

    int si = S.string(name_);

    S.push(LOADS);
    S.push(t+1);
    S.push(si);

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize("new")));
    S.push(t);
    S.push(1);

    S.push(IVA);
    S.push(t);
    S.push(si);
    S.push(t);

    int reg = S.find_local(name_);
    assert(reg >= 0);

    S.push(MOVR);
    S.push(reg);
    S.push(t);

    ArgMap locals;
    ArgMap args;

    ast::State subS(args, body_->locals(), S.lm());
    int r = body_->drive(subS, body_->locals().size());
    subS.push(RET);
    subS.push(r);

    S.push(MOVR);
    S.push(t+1);
    S.push(t);

    S.push(LOADC);
    S.push(t);
    S.push(S.code(subS.to_code()));

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize("eval")));
    S.push(t);
    S.push(1);

    return t;
  }

  void Class::accept(Visitor* V) {
    V->before_visit(this);
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

  int Import::drive(State& S, int t) {
    S.push(LOADN);
    S.push(t);
    S.push(S.string(String::internalize("Importer")));
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

    S.push(MOVR);
    S.push(reg_);
    S.push(t);

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

    if(l->reg_p()) {
      S.push(MOVR);
      S.push(l->idx());
      S.push(t);
    } else {
      S.push(SVAR);
      S.push(l->depth());
      S.push(l->idx());
      S.push(t);
    }

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
    S.push(t);
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

}}
