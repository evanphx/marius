#include "environment.hpp"
#include "memory_object.hpp"
#include "state.hpp"

#include "class.hpp"
#include "compiler.hpp"
#include "vm.hpp"

#include "module.hpp"
#include "settings.hpp"
#include "state.hpp"

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

    OOP import(State& S, OOP recv, Arguments& args) {
      assert(args.count() == 1);

      String& name = args[0].as_string();

      const char* path = find_path(S, name);

      if(!path) {
        printf("UNABLE TO FIND: %s\n", name.c_str());
        return OOP::nil();
      }

      FILE* file = fopen(path, "r");
      if(!file) {
        printf("UNABLE TO OPEN: %s\n", path);
        return OOP::nil();
      }

      Compiler compiler;

      if(!compiler.compile(file)) {
        printf("UNABLE TO COMPILE: %s\n", path);
        return OOP::nil();
      }

      Module* m = new Module;

      ModuleBuilder* b = new ModuleBuilder(m);

      OOP* fp = args.frame() + 1;
      fp[0] = b;

      S.env().bind(name, m);

      S.vm().run(S, *compiler.code(), fp + 1);

      return m;
    }

    OOP builder_add(State& S, OOP recv, Arguments& args) {
      assert(args.count() == 2);

      String& name = args[0].as_string();
      Code& code = args[1].as_code();

      Module* mod = recv.as_module_builder()->module();

      mod->add_native_method(name.c_str(), code);

      return recv;
    }
  }

  void init_import(Environment& env, Class** tbl) {
    Class* x = env.new_class("ImporterClass");
    x->add_method("import", import);

    Class* b = env.new_class("ModuleBuilder");
    b->add_method("add_method", builder_add);

    tbl[OOP::eModuleBuilder] = b;

    MemoryObject* obj = new MemoryObject(x);

    env.bind(String::internalize("Importer"), obj);
  }
}
