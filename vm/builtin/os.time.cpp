#include "r5_ext.hpp"
#include "sys/time.h"
;
;
#include "os.time.hpp"
using namespace os_time;
r5::Handle Moment_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  return r5::ext::allocate<Moment>(S, recv->as_class());
}
r5::Handle Moment_initialize(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Moment* self = r5::ext::unwrap<Moment>(recv);
  gettimeofday(r5::ext::ptr(S, self->tv), NULL);
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Moment_format(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Moment* self = r5::ext::unwrap<Moment>(recv);
  r5::String* fmt = args[0]->as_string();
  char buf[256];
;
  struct tm now;
;
  auto ptr = r5::ext::ptr(S, now);
  localtime_r(r5::ext::ptr(S, (r5::ext::ptr(S, self->tv))->tv_sec), ptr);
  auto sz = strftime(buf, 256, (fmt)->c_str(), ptr);
  return handle(S, r5::ext::string(S, buf, sz));
;
  return handle(S, r5::OOP::nil());
}
void init_Moment(r5::State& S) {
  r5::Handle mod = S.new_module("os.time");
  r5::Handle cls = S.new_class(mod, "Moment");
  S.add_class_method(cls, "allocate", Moment_allocate, 0);
  S.add_method(cls, "initialize", Moment_initialize, 0);
  S.add_method(cls, "format", Moment_format, 1);
}
static r5::ExtInitializer setup(init_Moment);
