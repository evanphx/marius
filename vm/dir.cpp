#include "r5_ext.hpp"
using namespace r5;
#include <dirent.h>
;
;
struct DirType {
  DIR* os;
};
Handle Dir_allocate(State& S, Handle recv, Arguments& args) {
  return ext::allocate<DirType>(S, recv->as_class());
}
Handle Dir_initialize(State& S, Handle recv, Arguments& args) {
  DirType* self = ext::unwrap<DirType>(recv);
  auto name = ext::cast<String>(args[0]);
  self->os = opendir((name)->c_str());
  return handle(S, OOP::nil());
}
;
Handle Dir_read(State& S, Handle recv, Arguments& args) {
  DirType* self = ext::unwrap<DirType>(recv);
  auto a = readdir(self->os);
  if((a) == (NULL)) {
return handle(S, handle(S, OOP::nil()));
}
;
  return handle(S, ext::string(S, (a)->d_name, (a)->d_namlen));
;
  return handle(S, OOP::nil());
}
;
Handle Dir_close(State& S, Handle recv, Arguments& args) {
  DirType* self = ext::unwrap<DirType>(recv);
  closedir(self->os);
  return handle(S, OOP::nil());
}
void init_Dir(State& S) {
  Handle mod = S.new_module("os.dir");
  Handle cls = S.new_class(mod, "Dir");
  S.add_method(cls, "allocate", Dir_allocate, 0);
  S.add_method(cls, "initialize", Dir_initialize, 1);
  S.add_method(cls, "read", Dir_read, 0);
  S.add_method(cls, "close", Dir_close, 0);
}
ExtInitializer setup(init_Dir);
