#include "list.hpp"
#include "oop.hpp"
#include "state.hpp"
#include "class.hpp"
#include "vm.hpp"
#include "arguments.hpp"

namespace r5 {

  namespace {

    Handle new_list(State& S, Handle recv, Arguments& args) {
      return handle(S, new(S) List(S));
    }

    Handle aref(State& S, Handle recv, Arguments& args) {
      List* l = recv->as_list();
      int idx = args[0]->int_value();

      return handle(S, l->get(idx));
    }

    Handle each(State& S, Handle recv, Arguments& args) {
      List* l = recv->as_list();
      Method* m = args[0]->as_method();

      OOP* fp = args.rest() + 1;
      fp[-1] = OOP(m);

      for(size_t i = 0; i < l->size(); i++) {
        fp[0] = l->get(i);
        Arguments out_args(S, 1, fp);
        OOP t = S.vm().run(S, m, out_args);
        if(t.unwind_p()) return handle(S, t);
      }

      return recv;
    }

    Handle size_m(State& S, Handle recv, Arguments& args) {
      return handle(S, OOP::integer(recv->as_list()->size()));
    }

    Handle append(State& S, Handle recv, Arguments& args) {
      recv->as_list()->push(S, *args[0]);
      return recv;
    }

    Handle equal(State& S, Handle recv, Arguments& args) {
      HList lst = recv;
      HList o = args[0];

      if(lst->size() != o->size()) {
        return handle(S, OOP::false_());
      }

      unsigned tot = lst->size();

      for(unsigned i = 0; i < tot; i++) {
        Arguments oa = args.setup(lst->get(i), o->get(i));
        Handle ret = oa.apply(String::internalize(S, "=="));
        if(!ret->true_condition_p()) return handle(S, OOP::false_());
      }

      return handle(S, OOP::true_());
    }
  }

  void List::init(State& S, Class* list) {
    list->add_class_method(S, "new", new_list, 0);
    list->add_method(S, "[]", aref, 1);
    list->add_method(S, "each", each, 1);
    list->add_method(S, "size", size_m, 0);
    list->add_method(S, "<<", append, 1);
    list->add_method(S, "==", equal, 1);
  }

  List* List::make(State& S, OOP* fp, int size) {
    List* l = new(S) List(S);

    for(unsigned i = 0; i < size; i++) {
      l->push(S, fp[i]);
    }

    return l;
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
