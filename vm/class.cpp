#include "class.hpp"
#include "method_table.hpp"
#include "method.hpp"
#include "string.hpp"
#include "trait.hpp"
#include "list.hpp"
#include "tuple.hpp"
#include "exception.hpp"

namespace marius {
  Class::Class(State& S, enum Boot, Class* cls, Class* sup, String* name)
    : MemoryObject(cls)
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
    , method_table_(new(S) MethodTable(S))
    , traits_(new(S) List(S))
  {}

  Class::Class(State& S, Class* sup, String* name)
    : MemoryObject(new(S) Class(S, Class::Boot,
                          sup->klass()->klass(),  sup->klass(),
                          Class::metaclass_name(S, name)))
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
    , method_table_(new(S) MethodTable(S))
    , traits_(new(S) List(S))
  {}

  String* Class::metaclass_name(State& S, String* name) {
    return String::internalize(S, std::string("<MetaClass:") + name->c_str() + ">");
  }

  Method* Class::lookup(String* name) {
    option<Method*> meth;

    Class* cls = this;

    while(true) {
      meth = cls->method_table_->lookup(name);
      if(meth.set_p()) return *meth;
      cls = cls->superclass_;
      if(!cls) break;
    }

    return 0;
  }

  void Class::add_method(State& S, const char* name,
                         SimpleFunc func, int arity)
  {
    String* s = String::internalize(S, name);

    Method* meth = new(S) Method(name_, func, arity);

    method_table_->add(S, s, meth);
  }

  void Class::add_native_method(State& S, const char* name, Method* meth) {
    String* s = String::internalize(S, name);

    method_table_->add(S, s, meth);
  }

  void Class::add_class_method(State& S, const char* name,
                               SimpleFunc func, int arity)
  {
    klass()->add_method(S, name, func, arity);
  }

  bool Class::instance_method_p(String* name) {
    return lookup(name) != 0;
  }

  OOP Class::uses_trait(State& S, Trait* trait) {
    MethodTable::Iterator i = trait->iterator();

    while(i.next()) {
      method_table_->add(S, i.key(), i.method());
    }

    traits_->push(S, trait);

    return OOP::nil();
  }

  OOP Class::check_traits(State& S) {
    for(unsigned i = 0; i < traits_->size(); i++) {
      Trait* t = traits_->get(i).as_trait();
      Tuple* s = t->sends();

      for(size_t j = 0; j < s->size(); j++) {
        String* name = s->get(j).as_string();
        if(!instance_method_p(name)) {
          return OOP::make_unwind(
                  Exception::create(S, "TraitError",
                    "Missing required method '%s'", name->c_str()));
        }
      }
    }

    return OOP::nil();
  }

  static Class** base_classes_;

  void Class::init_base(Class** base) {
    base_classes_ = base;
  }

  Class* Class::base_class(int idx) {
    return base_classes_[idx];
  }

  OOP Class::methods(State& S) {
    return method_table_->methods(S);
  }
}
