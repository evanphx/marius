#include "trait.hpp"
#include "arguments.hpp"
#include "handle.hpp"
#include "method.hpp"
#include "environment.hpp"
#include "vm.hpp"
#include "tuple.hpp"
#include "class.hpp"

namespace r5 {
  void Trait::add_native_method(State& S, String* name, Method* m) {
    method_table_->add(S, name, m);
  }

  namespace {
    Handle run_trait_body(State& S, Handle recv, Arguments& args) {
      Trait* trt = recv->as_trait();
      Method* m =  args[0]->as_method();

      std::string n = m->scope()->c_str();

      m = new(S) Method(
          String::internalize(S, n + "." + trt->name()->c_str()),
          m->code(), m->closure());

      Arguments out_args = args.setup(recv);

      return handle(S, S.vm().run(S, m, out_args));
    }

    Handle trait_add_method(State& S, Handle recv, Arguments& args) {
      String* name = args[0]->as_string();

      Method* m = args[1]->as_method();

      recv->as_trait()->add_native_method(S, name, m);

      return handle(S, OOP::nil());
    }

    Handle trait_new(State& S, Handle recv, Arguments& args) {
      String* name = args[0]->as_string();
      HTuple tup = args[1];

      return handle(S, OOP(new(S) Trait(S, name, *tup)));
    }
  }

  Class* Trait::init(State& S, Environment* env) {
    Class* trait = env->new_class(S, "Trait");
    env->new_class(S, "TraitError");

    trait->add_method(S, "run_body", run_trait_body, 1);
    trait->add_method(S, "add_method", trait_add_method, 2);
    trait->add_class_method(S, "new", trait_new, 2);

    return trait;
  }
}
