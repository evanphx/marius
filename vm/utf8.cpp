#include <stdint.h>
#include "utf8.hpp"

namespace marius {

  static const uint32_t utf8_limits[] = {
      0x0,        /* 1 */
      0x80,       /* 2 */
      0x800,      /* 3 */
      0x10000,    /* 4 */
      0x200000,   /* 5 */
      0x4000000,  /* 6 */
      0x80000000, /* 7 */
    };

  int decode_utf8(Buffer buf, uint32_t* uv) {
    uint8_t* p = buf.buf;

    uint32_t c = *p++ & 0xff;
    int n;

    *uv = c;

    if (!(*uv & 0x80)) return 1;
    if (!(*uv & 0x40)) return -1;

    if      (!(*uv & 0x20)) { n = 2; *uv &= 0x1f; }
    else if (!(*uv & 0x10)) { n = 3; *uv &= 0x0f; }
    else if (!(*uv & 0x08)) { n = 4; *uv &= 0x07; }
    else if (!(*uv & 0x04)) { n = 5; *uv &= 0x03; }
    else if (!(*uv & 0x02)) { n = 6; *uv &= 0x01; }
    else    { return -1; }

    if(n > buf.len) return -1;

    int len = n;

    while (n--) {
      c = *p++ & 0xff;
      if ((c & 0xc0) != 0x80) {
        return -1;
      } else {
        c &= 0x3f;
        *uv = *uv << 6 | c;
      }
    }

    if (*uv < utf8_limits[len-1]) return -1;

    return len;
  }
}

