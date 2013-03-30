#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <stdint.h>
#include <stddef.h>
#include <string.h>

namespace marius {
  struct Buffer {
    uint8_t* buf;
    size_t   len;

    Buffer(uint8_t* b, size_t s)
      : buf(b)
      , len(s)
    {}

    Buffer(const char* c, size_t s)
      : buf((uint8_t*)c)
      , len(s)
    {}

    char* c_buf() {
      return (char*)buf;
    }

    uint8_t take1() {
      uint8_t c = *buf;
      buf++;
      len--;
      return c;
    }

    uint8_t peek1() {
      return *buf;
    }

    bool empty_p() {
      return len == 0;
    }

    int trim(int count) {
      if(count > len) count = len;

      buf += count;
      len -= count;

      return count;
    }
  };

  struct ScratchBuffer {
    uint8_t* buf;
    size_t   len;
    size_t   capa;

    static const int cDefaultBufferSize = 32;

    ScratchBuffer()
      : buf(new uint8_t[cDefaultBufferSize])
      , len(0)
      , capa(cDefaultBufferSize)
    {}

    bool empty_p() {
      return len == 0;
    }

    void append(uint8_t c) {
      if(len == capa) {
        capa += cDefaultBufferSize;
        uint8_t* n = new uint8_t[capa];
        memcpy(n, buf, len-1);
        buf = n;
      }

      buf[len] = c;
      len++;
    }

    char* copy_out() {
      return strndup((const char*)buf, len);
    }
  };
}

#endif
