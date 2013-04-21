#include "environment.hpp"
#include "memory_object.hpp"
#include "state.hpp"

#include "class.hpp"
#include "compiler.hpp"
#include "vm.hpp"

#include "module.hpp"
#include "settings.hpp"
#include "state.hpp"
#include "method.hpp"
#include "closure.hpp"
#include "dictionary.hpp"

#include "exception.hpp"
#include "arguments.hpp"

#include <string.h>
#include <unistd.h>

namespace r5 {
  namespace {

    const char* find_path(State& S, String* req) {
      std::vector<const char*>& lp = S.settings().load_path();

      char* path = new char[1024];
      for(std::vector<const char*>::iterator i = lp.begin();
          i != lp.end();
          ++i) {
        path[0] = 0;

        strcat(path, *i);
        strcat(path, "/");
        strcat(path, req->c_str());
        strcat(path, ".mr");

        if(access(path, R_OK) == 0) return path;
      }

      delete path;
      return 0;
    }

    Handle import(State& S, Handle recv, Arguments& args) {
      String* name = args[0]->as_string();

      option<OOP> val = S.env().modules()->get(name);
      if(val.set_p()) {
        return handle(S, *val);
      }

      const char* c_name = name->c_str();

      const char* path;

      if(strrchr(c_name, '.')) {
        char buf[128];
        buf[0] = 0;

        strncpy(buf, c_name, 128);

        char* last_dot = strrchr(buf, '.');

        *last_dot = '/';

        path = find_path(S, String::internalize(S, buf));
      } else {
        path = find_path(S, name);
      }

      if(!path) {
        return handle(S, OOP::make_unwind(
            Exception::create(S, "ImportError",
                              "Unable to find '%s'", name->c_str())));
      }

      FILE* file = fopen(path, "r");
      delete path;

      if(!file) {
        return handle(S, OOP::make_unwind(
            Exception::create(S, "ImportError",
                              "Unable to open '%s'", name->c_str())));
      }

      Compiler compiler;

      if(!compiler.compile(S, file)) {
        return handle(S, OOP::make_unwind(
            Exception::create(S, "ImportError",
                              "Unable to compile '%s'", name->c_str())));
      }

      Module* m = new(S) Module(S,
          S.env().lookup(S, "Module").as_class(), name);

      S.env().modules()->set(S, name, m);

      OOP* fp = args.rest() + 1;
      fp[0] = m;

      Code* code = compiler.code();

      Method* top = new(S) Method(name, code, S.env().globals());

      Arguments out_args(S, 1, fp + 1);

      OOP t = S.vm().run(S, top, out_args);
      if(t.unwind_p()) return handle(S, t);

      return handle(S, m);
    }

    Handle current(State& S, Handle recv, Arguments& args) {
      return handle(S, S.importer());
    }
  }

  Class* init_import(State& S) {
    Class* x = S.env().new_class(S, "Importer");
    x->add_method(S, "import", import, 1);
    x->add_class_method(S, "current", current, 0);

    S.env().new_class(S, "ImportError");
    return x;
  }
}
