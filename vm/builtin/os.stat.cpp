#include "r5_ext.hpp"
#include <sys/stat.h>
;
;
#include "os.stat.hpp"
using namespace os_stat;
r5::Handle Stat_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  return r5::ext::allocate<Stat>(S, recv->as_class());
}
r5::Handle Stat_initialize(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Stat* self = r5::ext::unwrap<Stat>(recv);
  r5::String* path = args[0]->as_string();
  stat((path)->c_str(), r5::ext::ptr(S, self->info));
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Stat_directory_p(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Stat* self = r5::ext::unwrap<Stat>(recv);
  auto s = (r5::ext::ptr(S, self->info))->st_mode;
  return handle(S, r5::ext::to_bool(S, (s) & (S_IFDIR)));
;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Stat_file_p(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Stat* self = r5::ext::unwrap<Stat>(recv);
  auto s = (r5::ext::ptr(S, self->info))->st_mode;
  return handle(S, r5::ext::to_bool(S, (s) & (S_IFREG)));
;
  return handle(S, r5::OOP::nil());
}
void init_Stat(r5::State& S) {
  r5::Handle mod = S.new_module("os.stat");
  r5::Handle cls = S.new_class(mod, "Stat");
  S.add_method(cls, "allocate", Stat_allocate, 0);
  S.add_method(cls, "initialize", Stat_initialize, 1);
  S.add_method(cls, "directory?", Stat_directory_p, 0);
  S.add_method(cls, "file?", Stat_file_p, 0);
}
static r5::ExtInitializer setup(init_Stat);
