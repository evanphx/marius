
extern "C" {
  #include <string.h>
}

#include "parser.hpp"

#include "parser_tokens.h"

union Token {
  int i;
  marius::String* s;
};

#include "parser.c.inc"

namespace marius {

  char Parser::next_c() {
    const char* s = next_str(1);
    if(!s) return 0;
    return *s;
  }

  const char* Parser::next_str(int count) {
    int left = end_ - pos_;

    // If the buffer contains enough data to fulfill the request,
    // go ahead and give it out directly.

    if(left > count) {
      return pos_;
    }

    if(file_) {
      // Ok, we need more data and there is a file source registered.

      if(!buffer_) {
        size_ = 1024;
        buffer_ = new char[size_];
        end_ = buffer_ + size_;
      } else {
        // shift the unused data up to the front of the buffer.
        memmove((void*)buffer_, pos_, left);
      }

      pos_ = buffer_;

      // Read more data from the file into the end of the buffer.
      int r = fread((void*)(pos_ + left), 1, size_ - left, file_);
      if(r == 0) return 0;

      // Pin the end to where the actual filled data ends
      end_ = pos_ + left + r;

      // We still couldn't read in enough data, dang.
      if(end_ - pos_ < count) return 0;

      return pos_;
    }

    return 0;
  }

  int Parser::next_token() {
    if(pos_ >= end_) return 0;

    value_.i = 0;

again:

    char c = next_c();

    if(!c) return 0;

    switch(c) {
      case '0': case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9':
        {
          char* end;
          value_.i = strtol(pos_, &end, 0);
          if(end == pos_) return -1;

          advance(end - pos_);

          return NUM;
        }
      case ' ':
        while(next_c() == ' ') advance(1);

        goto again;

      case '+':
        advance(1);
        return PLUS;

      case '.':
        advance(1);
        return DOT;

      case '\n':
        column_ = 0;
        line_++;

        // fallthrough
      case ';':
        advance(1);
        return FIN;

      case '#':
        while(next_c() != '\n') advance(1);

        column_ = 0;
        line_++;

        advance(1);

        goto again;

      default:
        {
          int t = keyword_match();
          if(t != -1) return t;

          if(isalpha(c)) return id_match();
          printf("Unknown token at line %d, column %d: '%c'\n",
                 line_, column_, c);
        }
    }


    return -1;
  }

  static inline int min(int a, int b) {
    return a < b ? a : b;
  }

  int Parser::keyword_match() {
    const char* str;

    switch(pos_[0]) {
    case 'c':
      str = next_str(5);

      if(str && strncmp(str, "class", 5) == 0) {
        advance(5);
        return CLASS;
      }
      break;

    case 'd':
      str = next_str(3);

      if(str && strncmp(str, "def", 3) == 0) {
        advance(3);
        return DEF;
      }
      break;

    case 'e':
      str = next_str(3);

      if(str && strncmp(str, "end", 3) == 0) {
        advance(3);
        return END;
      }
      break;
    }

    return -1;
  }

  int Parser::id_match() {
    const char* start = pos_;
    const char* p = pos_;

    if(!isalpha(*p)) return -1;

    p++;

    while(p < end_) {
      if(!isalnum(*p)) break;
      p++;
    }

    advance(p - pos_);

    value_.s = &String::internalize(strndup(start, p - start));
    return ID;
  }

  bool Parser::parse(bool debug) {
    next_c(); // prime the buffer
    engine_ = mariusParserAlloc(malloc);

    ParserState S;

    FILE* stream = 0;

    if(debug) {
      stream = fopen("debug.out", "wb");
      mariusParserTrace(stream, (char*)">");
    }

    for(;;) {
      int token = next_token();
      if(token == -1) break;

      mariusParser(engine_, token, value_, &S);

      if(token == 0) break;
    }

    mariusParserFree(engine_, free);

    if(debug) fclose(stream);

    code_ = S.to_code();

    return true;
  }
}
