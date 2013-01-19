#ifndef UTF8_hPP
#define UTF8_hPP

#include "buffer.hpp"

namespace marius {
  int decode_utf8(Buffer buf, uint32_t* uv);
}

#endif
