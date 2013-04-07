#include "ast.hpp"
#include "string_map.hpp"
#include "local.hpp"

#include <list>

namespace marius {
  using namespace ast;

  class ScopeTracker : public Visitor {
    typedef StringMap<Local*>::type LocalScope;

    marius::State& S;
    LocalScope* scope_;

    std::list<LocalScope*> stack_;
    ArgMap& globals_;
    LocalMap& locals_;

  public:
    ScopeTracker(marius::State& S, ArgMap& globals, LocalMap& locals)
      : S(S)
      , scope_(new LocalScope)
      , globals_(globals)
      , locals_(locals)
    {}

    void visit(Import* imp) {
      int depth = stack_.size();

      ArgMap::iterator i = globals_.find(String::internalize(S, "Importer"));

      assert(i != globals_.end());
      Local* l = new Local;
      l->make_global(i->second, depth);

      Local* lv = locals_.add(imp);
      lv->set_extra(l);

      scope_->insert(LocalScope::value_type(imp->name(), lv));
    }

    void before_visit(ast::Class* cls) {
      scope_->insert(LocalScope::value_type(cls->name(),
                                            locals_.add(cls->body())));
    }

    void before_visit(Scope* s) {
      stack_.push_back(scope_);
      scope_ = new LocalScope;

      // ArgMap& args = s->arguments();

      ArgumentList& args = s->arg_objs();

      for(ArgumentList::iterator i = args.begin();
          i != args.end();
          ++i)
      {
        Argument* a = *i;
        Local* l = new Local;
        l->make_arg(a->position());

        locals_.add(a, l);

        scope_->insert(LocalScope::value_type(a->name(), l));
      }

      Argument* a = s->self();
      if(a) {
        Local* l = new Local;
        l->make_arg(a->position());

        locals_.add(a, l);
        scope_->insert(LocalScope::value_type(a->name(), l));
      }
    }

    void visit(Scope* s) {
      int regs = 0;
      int closed = 0;

      for(LocalScope::iterator i = scope_->begin();
          i != scope_->end();
          ++i) {
        Local* l = i->second;
        if(l->reg_p()) {
          int r;

          if(l->needs_reg_p()) {
            r = regs++;
            i->second->set_reg(r);
          } else {
            r = i->second->reg();
          }

          s->add_local(i->first, r);
        } else {
          int c = closed++;
          i->second->set_reg(c);
          s->add_closed_local(i->first, c);
        }
      }

      delete scope_;

      scope_ = stack_.back();

      stack_.pop_back();
    }

    void visit(Assign* a) {
      LocalScope::iterator j = scope_->find(a->name());
      if(j != scope_->end()) {
        locals_.add(a, j->second);
        return;
      }

      int d = 0;
      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, d++)
      {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(a->name());
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(a);
          l->make_closure_access(j->second, d);
        }
      }

      scope_->insert(LocalScope::value_type(a->name(), locals_.add(a)));
    }

    void visit(AssignOp* a) {
      LocalScope::iterator j = scope_->find(a->name());
      if(j != scope_->end()) {
        locals_.add(a, j->second);
        return;
      }

      int d = 0;
      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, d++)
      {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(a->name());
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(a);
          l->make_closure_access(j->second, d);
        }
      }

      scope_->insert(LocalScope::value_type(a->name(), locals_.add(a)));
    }

    void find_scoped(Node* n, String* name) {
      LocalScope::iterator j = scope_->find(name);
      if(j != scope_->end()) {
        locals_.add(n, j->second);
        return;
      }

      int depth = 1;

      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, depth++) {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(name);
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(n);
          l->make_closure_access(j->second, depth);
          return;
        }
      }

      ArgMap::iterator i = globals_.find(name);
      if(i != globals_.end()) {
        Local* l = locals_.add(n);
        l->make_global(i->second, depth-1);
      }
    }

    void visit(Named* n) {
      find_scoped(n, n->name());
    }

    void visit(Self* s) {
      find_scoped(s, String::internalize(S, "self"));
    }
  };

  void calculate_locals(marius::State& S, ast::Node* top,
                        ArgMap& globals, LocalMap& locals) {
    ScopeTracker tracker(S, globals, locals);
    top->accept(&tracker);
  }
}
