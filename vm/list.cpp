#include "list.hpp"
#include "oop.hpp"
#include "state.hpp"
#include "class.hpp"
#include "vm.hpp"

namespace marius {

  namespace {
    Handle aref(State& S, Handle recv, Arguments& args) {
      List* l = recv->as_list();
      int idx = args[0]->int_value();

      return handle(S, l->get(idx));
    }

    Handle each(State& S, Handle recv, Arguments& args) {
      List* l = recv->as_list();
      Method* m = args[0]->as_method();

      OOP* fp = args.frame() + 1;
      fp[-1] = OOP(m);

      for(size_t i = 0; i < l->size(); i++) {
        fp[0] = l->get(i);
        S.vm().run(S, m, fp);
      }

      return recv;
    }

    Handle size_m(State& S, Handle recv, Arguments& args) {
      return handle(S, OOP::integer(recv->as_list()->size()));
    }
  }

  void List::init(State& S, Class* list) {
    list->add_method(S, "[]", aref, 1);
    list->add_method(S, "each", each, 1);
    list->add_method(S, "size", size_m, 0);
  }

  void List::push(State& S, OOP val) {
    size_++;

    if(!head_) {
      head_ = new(S) Node(val);
    } else {
      Node* n = head_;

      while(n->next) {
        n = n->next;
      }

      n->next = new(S) Node(val);
    }
  }

  OOP List::get(int idx) {
    List::Node* n = head_;
    if(!n || idx > size_) OOP::nil();

    int i = 0;
    while(n) {
      if(i++ == idx) return n->val;
      n = n->next;
    }

    return OOP::nil();
  }
}
