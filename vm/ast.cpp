#include "ast.hpp"

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

  int Seq::drive(State& S, int t) {
    parent_->drive(S, t);
    return child_->drive(S, t);
  }

  int Scope::drive(State& S, int t) {
    body_->drive(S, t);

    return t;
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

  int Number::drive(State& S, int t) {
    S.push(MOVI8);
    S.push(t);
    S.push(val_);

    return t;
  }

  int Named::drive(State& S, int t) {
    int reg = S.find_local(name_);
    if(reg >= 0) {
      S.push(MOVR);
      S.push(t);
      S.push(reg);
    } else {
      S.push(LOADN);
      S.push(t);
      S.push(S.string(name_));
    }

    return t;
  }

  int Def::drive(State& S, int t) {
    S.push(SELF);
    S.push(t);

    S.push(LOADS);
    S.push(t+1);
    S.push(S.string(name_));

    ast::State subS(args_, body_->locals());

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

  int Class::drive(State& S, int t) {
    S.push(LOADN);
    S.push(t);
    S.push(S.string(String::internalize("Class")));

    S.push(LOADS);
    S.push(t+1);
    S.push(S.string(name_));

    S.push(CALL);
    S.push(t);
    S.push(S.string(String::internalize("new")));
    S.push(t);
    S.push(1);

    ArgMap locals;
    ArgMap args;

    ast::State subS(args, body_->locals());
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

  int Return::drive(State& S, int t) {
    val_->drive(S, t);

    S.push(RET);
    S.push(t);

    return t;
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

  int CascadeCall::drive(State& S, int t) {
    S.push(CALL);
    S.push(t+1);
    S.push(S.string(name_));
    S.push(t);
    S.push(0);

    return t;
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

  int Nil::drive(State& S, int t) {
    S.push(MOVN);
    S.push(t);

    return t;
  }

  int True::drive(State& S, int t) {
    S.push(MOVT);
    S.push(t);

    return t;
  }

  int False::drive(State& S, int t) {
    S.push(MOVF);
    S.push(t);

    return t;
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

    return t;
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

  int Assign::drive(State& S, int t) {
    value_->drive(S, t);
    S.push(MOVR);
    S.push(reg_);
    S.push(t);

    return t;
  }
}}
