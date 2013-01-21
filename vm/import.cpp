#include "environment.hpp"
#include "memory_object.hpp"
#include "state.hpp"

#include "class.hpp"
#include "compiler.hpp"
#include "vm.hpp"

#include "module.hpp"
#include "settings.hpp"
#include "state.hpp"

#include "unwind.hpp"

#include <string.h>

namespace marius {
  namespace {

    const char* find_path(State& S, String& req) {
      std::vector<const char*>& lp = S.settings().load_path();

      char* path = new char[1024];

      for(std::vector<const char*>::iterator i = lp.begin();
          i != lp.end();
          ++i) {
        strcat(path, *i);
        strcat(path, "/");
        strcat(path, req.c_str());
        strcat(path, ".mr");

        if(access(path, R_OK) == 0) return path;
      }

      delete path;
      return 0;
    }

    Handle import(State& S, Handle recv, Arguments& args) {
      assert(args.count() == 1);

      String& name = args[0]->as_string();

      const char* path = find_path(S, name);

      if(!path) {
        return handle(S, Unwind::import_error(name));
      }

      FILE* file = fopen(path, "r");
      delete path;

      if(!file) {
        return handle(S, Unwind::import_error(name));
      }

      Compiler compiler;

      if(!compiler.compile(file)) {
        return handle(S, Unwind::import_error(name));
      }

      Module* m = new Module(
          S.env().lookup("Class").as_class(),
          S.env().lookup("Module").as_class(), name);

      OOP* fp = args.frame() + 1;
      fp[0] = m;

      S.vm().run(S, *compiler.code(), fp + 1);

      return handle(S, m);
    }

    Handle current(State& S, Handle recv, Arguments& args) {
      return handle(S, S.importer());
    }
  }

  void init_import(State& S) {
    Class* x = S.env().new_class("Importer");
    x->add_method("import", import);
    x->add_class_method("current", current);
  }
}
