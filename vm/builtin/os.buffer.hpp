#ifndef R5EXT_Buffer_HPP
#define R5EXT_Buffer_HPP
#include "r5_ext.hpp"
namespace os_buffer {
struct Buffer {
  uint8_t* ptr;
  int limit;
  int capacity;
  int position;
};
}
namespace r5 { namespace ext {
  template <> inline os_buffer::Buffer* cast<os_buffer::Buffer>(r5::Handle hndl) {
    return unwrap<os_buffer::Buffer>(hndl);
  }
}}
#endif
