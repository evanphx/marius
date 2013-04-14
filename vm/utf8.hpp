#ifndef UTF8_hPP
#define UTF8_hPP

#include "buffer.hpp"

namespace r5 {
  int decode_utf8(Buffer buf, uint32_t* uv);
  size_t utf8_charlen(const char* data, size_t bytelen=0);
}

#endif
