#include "tuple.hpp"
#include "state.hpp"

#include "environment.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "vm.hpp"
#include "class.hpp"

namespace r5 {
  Tuple::Tuple(State& S, size_t size)
    : data_(new(S) OOP[size])
    , size_(size)
  {}

  Tuple* Tuple::make(State& S, OOP* e, unsigned size) {
    Tuple* t = new(S) Tuple(S, size);
    for(unsigned i = 0; i < size; i++) {
      t->set(i, e[i]);
    }

    return t;
  }

  void Tuple::set(size_t idx, OOP val) {
    if(idx < size_) {
      data_[idx] = val;
    }
  }

  OOP Tuple::get(size_t idx) {
    if(idx < size_) {
      return data_[idx];
    }

    return OOP::nil();
  }

  namespace {
    Handle tuple_find_all(State& S, Handle recv, Arguments& args) {
      HTuple tup = recv;
      Method* m = args[0]->as_method();

      OOP* fp = args.rest() + 1;
      fp[-1] = OOP(m);

      std::vector<OOP> found;

      for(size_t i = 0; i < tup->size(); i++) {
        fp[0] = tup->get(i);

        Arguments out_args(S, 1, fp);
        OOP t = S.vm().run(S, m, out_args);

        if(t.unwind_p()) {
          return handle(S, t);
        }

        if(t.true_condition_p()) {
          found.push_back(fp[0]);
        }
      }

      HTuple out = handle(S, new(S) Tuple(S, found.size()));
      for(size_t i = 0; i < found.size(); i++) {
        out->set(i, found[i]);
      }

      return out;
    }

    Handle tuple_each(State& S, Handle recv, Arguments& args) {
      HTuple tup = recv;
      Method* m = args[0]->as_method();

      OOP* fp = args.rest() + 1;
      fp[-1] = OOP(m);

      for(size_t i = 0; i < tup->size(); i++) {
        fp[0] = tup->get(i);
        Arguments out_args(S, 1, fp);

        OOP t = S.vm().run(S, m, out_args);
        if(t.unwind_p()) return handle(S, t);
      }

      return recv;
    }

    Handle tuple_equal(State& S, Handle recv, Arguments& args) {
      HTuple tup = recv;
      HTuple o = args[0];

      if(tup->size() != o->size()) {
        return handle(S, OOP::false_());
      }

      size_t tot = tup->size();

      for(size_t i = 0; i < tot; i++) {
        Arguments oa = args.setup(tup->get(i), o->get(i));
        Handle ret = oa.apply(String::internalize(S, "=="));
        if(!ret->true_condition_p()) return handle(S, OOP::false_());
      }

      return handle(S, OOP::true_());
    }
  }

  Class* Tuple::init(State& S, Environment* env) {
    Class* tuple = env->new_class(S, "Tuple");
    tuple->add_method(S, "find_all", tuple_find_all, 1);
    tuple->add_method(S, "each", tuple_each, 1);
    tuple->add_method(S, "==", tuple_equal, 1);

    return tuple;
  }
};
