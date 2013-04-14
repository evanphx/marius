#include "dictionary.hpp"
#include "handle.hpp"
#include "arguments.hpp"
#include "class.hpp"
#include "tuple.hpp"

namespace r5 {

  namespace {
    Handle get_m(State& S, Handle recv, Arguments& args) {
      String* key = String::convert(S, *args[0]);

      Dictionary* dict = recv->as_dictionary();
      option<OOP> val = dict->get(key);

      if(val.set_p()) {
        return handle(S, *val);
      }

      return handle(S, OOP::nil());
    }

    Handle literal(State& S, Handle recv, Arguments& args) {
      Dictionary* dict = new(S) Dictionary(S);

      option<ArgMap>& keywords = args.keywords();
      if(keywords.set_p()) {
        ArgMap keys = *keywords;

        for(ArgMap::iterator i = keys.begin();
            i != keys.end();
            ++i) {
          dict->set(S, i->first, *args[i->second]);
        }
      }

      return handle(S, OOP(dict));
    }

    Handle keys_m(State& S, Handle recv, Arguments& args) {
      Dictionary* dict = recv->as_dictionary();
      return handle(S, dict->keys(S));
    }
  }

  void Dictionary::init(State& S, Class* dict) {
    dict->add_method(S, "::", get_m, 1);
    dict->add_method(S, "[]", get_m, 1);
    dict->add_method(S, "keys", keys_m, 0);
    dict->add_class_method(S, "literal", literal, -1);
  }

  option<OOP> Dictionary::get(String* name) {
    return table_.find(name);
  }

  void Dictionary::set(State& S, String* name, OOP val) {
    table_.set(S, name, val);
  }

  OOP Dictionary::keys(State& S) {
    return table_.keys(S);
  }
}
