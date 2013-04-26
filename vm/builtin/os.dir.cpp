#include "r5_ext.hpp"
#include <dirent.h>
;
;
#include "os.dir.hpp"
using namespace os_dir;
r5::Handle Dir_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  return r5::ext::allocate<Dir>(S, recv->as_class());
}
r5::Handle Dir_initialize(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  r5::String* name = args[0]->as_string();
  self->os = opendir((name)->c_str());
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Dir_read(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  auto a = readdir(self->os);
  if((a) == (NULL)) {
return handle(S, handle(S, r5::OOP::nil()));
}
;
  return handle(S, r5::ext::string(S, (a)->d_name));
;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Dir_close(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  closedir(self->os);
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Dir_rewind(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  rewinddir(self->os);
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Dir_tell(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  return handle(S, r5::ext::wrap(S, telldir(self->os)));
;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Dir_seek(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Dir* self = r5::ext::unwrap<Dir>(recv);
  int pos = args[0]->int_value();
  seekdir(self->os, pos);
  return handle(S, r5::OOP::nil());
}
void init_Dir(r5::State& S) {
  r5::Handle mod = S.new_module("os.dir");
  r5::Handle cls = S.new_class(mod, "Dir");
  S.add_method(cls, "allocate", Dir_allocate, 0);
  S.add_method(cls, "initialize", Dir_initialize, 1);
  S.add_method(cls, "read", Dir_read, 0);
  S.add_method(cls, "close", Dir_close, 0);
  S.add_method(cls, "rewind", Dir_rewind, 0);
  S.add_method(cls, "tell", Dir_tell, 0);
  S.add_method(cls, "seek", Dir_seek, 1);
}
static r5::ExtInitializer setup(init_Dir);
