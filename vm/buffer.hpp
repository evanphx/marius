#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <stdint.h>
#include <stddef.h>

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
}

#endif
