#include "environment.hpp"
#include "string.hpp"
#include "class.hpp"
#include "code.hpp"

namespace marius {
  OOP Environment::lookup(String& name) {
    Environment* env = this;

    while(true) {
      std::map<String*, OOP>::iterator i = binding_.find(&name);

      if(i != binding_.end()) return (*i).second;
      env = env->parent_;
    }

    return OOP::nil();
  }

  Class* Environment::new_class(const char* name) {
    String& s = String::internalize(name);

    Class* obj = binding_[&String::internalize("Class")].as_class();

    Class* cls = new Class(obj, s);

    binding_[&s] = OOP(cls);

    return cls;
  }

  static OOP int_plus(Environment& env, OOP recv, int argc, OOP* fp) {
    if(argc == 0) return OOP::nil();

    int val = recv.int_value() + fp[0].int_value();
    return OOP::integer(val);
  }

  static OOP class_new(Environment& env, OOP recv, int argc, OOP* fp) {
    assert(argc == 1);

    String& name = fp[0].as_string();

    return OOP(env.new_class(name.c_str()));
  }

  static OOP add_method(Environment& env, OOP recv, int argc, OOP* fp) {
    assert(argc == 2);

    String& name = fp[0].as_string();
    Code& code = fp[1].as_code();

    recv.as_class()->add_native_method(name.c_str(), code);

    return OOP::nil();
  }

  static OOP new_instance(Environment& env, OOP recv, int argc, OOP* fp) {
    Class* cls = recv.as_class();

    return OOP(new MemoryObject(cls));
  }

  void Environment::init_ontology() {
    String& mn = String::internalize("MetaClass");
    String& cn = String::internalize("Class");

    Class* m = new Class(0, mn);
    binding_[&mn] = m;

    Class* c = new Class(m, cn);
    m->klass_ = c;
    binding_[&cn] = c;

    m->add_method("new", class_new);

    c->add_method("add_method", add_method);
    c->add_method("new", new_instance);

    Class* i = new_class("Integer");
    i->add_method("+", int_plus);

    Class* n = new_class("NilClass");

    Class* s = new_class("String");

    Class::init_base(i, m, n, s);
  }
}
