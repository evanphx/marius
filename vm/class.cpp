#include "class.hpp"
#include "method_table.hpp"
#include "method.hpp"
#include "string.hpp"

namespace marius {
  Class::Class(State& S, enum Boot, Class* cls, Class* sup, String& name)
    : MemoryObject(cls)
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
  {}

  Class::Class(State& S, Class* sup, String& name)
    : MemoryObject(new(S) Class(S, Class::Boot,
                          sup->klass()->klass(),  sup->klass(),
                          Class::metaclass_name(S, name)))
    , Attributes(S)
    , name_(name)
    , superclass_(sup)
  {}

  String& Class::metaclass_name(State& S, String& name) {
    return String::internalize(S, std::string("<MetaClass:") + name.c_str() + ">");
  }

  Method* Class::lookup(String& name) {
    Method* meth;

    Class* cls = this;

    while(true) {
      meth = cls->method_table_.lookup(name);
      if(meth) return meth;
      cls = cls->superclass_;
      if(!cls) break;
    }

    return 0;
  }

  void Class::add_method(State& S, const char* name,
                         SimpleFunc func, int arity)
  {
    String& s = String::internalize(S, name);

    Method* meth = new(S) Method(name_, func, arity);

    method_table_.add(s, meth);
  }

  void Class::add_native_method(State& S, const char* name, Method* meth) {
    String& s = String::internalize(S, name);

    method_table_.add(s, meth);
  }

  void Class::add_class_method(State& S, const char* name,
                               SimpleFunc func, int arity)
  {
    klass()->add_method(S, name, func, arity);
  }

  static Class** base_classes_;

  void Class::init_base(Class** base) {
    base_classes_ = base;
  }

  Class* Class::base_class(int idx) {
    return base_classes_[idx];
  }

  OOP Class::methods(State& S) {
    return method_table_.methods(S);
  }
}
