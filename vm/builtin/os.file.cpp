#include "r5_ext.hpp"
#include <fcntl.h>
;
#include "os.buffer.hpp"
using namespace os_buffer;

;
;
#include "os.file.hpp"
using namespace os_file;
r5::Handle File_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  return r5::ext::allocate<File>(S, recv->as_class());
}
r5::Handle File_initialize(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  File* self = r5::ext::unwrap<File>(recv);
  r5::String* name = args[0]->as_string();
  self->fd = open((name)->c_str(), O_RDONLY);
  return handle(S, r5::OOP::nil());
}
;
r5::Handle File_read(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  File* self = r5::ext::unwrap<File>(recv);
  char buf[128];
;
  auto r = read(self->fd, buf, 128);
  if((r) == (0)) {
return handle(S, handle(S, r5::OOP::nil()));
}
;
  return handle(S, r5::ext::string(S, buf, r));
;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle File_fill(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  File* self = r5::ext::unwrap<File>(recv);
  auto buf = r5::ext::cast<Buffer>(args[0]);
  auto l = ((buf)->limit) - ((buf)->position);
  auto r = read(self->fd, (buf)->ptr, l);
  (buf)->position = (((buf)->position) + (r));
  return handle(S, r5::ext::wrap(S, r));
;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle File_close(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  File* self = r5::ext::unwrap<File>(recv);
  close(self->fd);
  return handle(S, r5::OOP::nil());
}
void init_File(r5::State& S) {
  r5::Handle mod = S.new_module("os.file");
  r5::Handle cls = S.new_class(mod, "File");
  S.add_method(cls, "allocate", File_allocate, 0);
  S.add_method(cls, "initialize", File_initialize, 1);
  S.add_method(cls, "read", File_read, 0);
  S.add_method(cls, "fill", File_fill, 1);
  S.add_method(cls, "close", File_close, 0);
}
static r5::ExtInitializer setup(init_File);
