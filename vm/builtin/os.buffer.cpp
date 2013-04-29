#include "r5_ext.hpp"
#include "stdlib.h"
;
;
;
;
;
#include "os.buffer.hpp"
using namespace os_buffer;
r5::Handle Buffer_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  return r5::ext::allocate<Buffer>(S, recv->as_class());
}
r5::Handle Buffer_initialize(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Buffer* self = r5::ext::unwrap<Buffer>(recv);
  int size = args[0]->int_value();
  self->ptr = ((uint8_t*)(malloc(size)));
  self->capacity = size;
  self->limit = size;
  self->position = 0;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Buffer_clear(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Buffer* self = r5::ext::unwrap<Buffer>(recv);
  self->limit = self->capacity;
  self->position = 0;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Buffer_flip(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Buffer* self = r5::ext::unwrap<Buffer>(recv);
  self->limit = self->position;
  self->position = 0;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Buffer_rewind(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Buffer* self = r5::ext::unwrap<Buffer>(recv);
  self->position = 0;
  return handle(S, r5::OOP::nil());
}
;
r5::Handle Buffer_string(r5::State& S, r5::Handle recv, r5::Arguments& args) {
  Buffer* self = r5::ext::unwrap<Buffer>(recv);
  int size = args[0]->int_value();
  auto p = (self->ptr) + (self->position);
  auto cs = r5::ext::clamp(S, size, (self->limit) - (self->position));
  self->position = (self->position) + (cs);
  return handle(S, r5::ext::string(S, p, cs));
;
  return handle(S, r5::OOP::nil());
}
void init_Buffer(r5::State& S) {
  r5::Handle mod = S.new_module("os.buffer");
  r5::Handle cls = S.new_class(mod, "Buffer");
  S.add_class_method(cls, "allocate", Buffer_allocate, 0);
  S.add_method(cls, "initialize", Buffer_initialize, 1);
  S.add_method(cls, "clear", Buffer_clear, 0);
  S.add_method(cls, "flip", Buffer_flip, 0);
  S.add_method(cls, "rewind", Buffer_rewind, 0);
  S.add_method(cls, "string", Buffer_string, 1);
}
static r5::ExtInitializer setup(init_Buffer);
