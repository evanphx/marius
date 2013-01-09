
extern "C" {
  #include <string.h>
}

#include "parser.hpp"

#include "parser_tokens.h"

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
        size_ = 1023;
        buffer_ = new char[size_ + 1];
        end_ = buffer_ + size_;
      } else {
        // shift the unused data up to the front of the buffer.
        memmove((void*)buffer_, pos_, left);
        end_ = buffer_ + left;
        *end_ = 0;
      }

      pos_ = buffer_;

      // Read more data from the file into the end of the buffer.
      int r = fread((void*)(pos_ + left), 1, size_ - left, file_);
      if(r == 0) return 0;

      // Pin the end to where the actual filled data ends
      end_ = pos_ + left + r;

      *end_ = 0;

      // We still couldn't read in enough data, dang.
      if(end_ - pos_ < count) return 0;

      return pos_;
    }

    return 0;
  }

  int Parser::next_token() {
    value_.i = 0;

again:

    char c = next_c();

    if(!c) return TK_EOF;

    switch(c) {
      case '0': case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9':
        {
          char* end;
          value_.i = strtol(pos_, &end, 0);
          if(end == pos_) return -1;

          advance(end - pos_);

          return TK_NUM;
        }
      case ' ':
        while(next_c() == ' ') advance(1);

        goto again;

      case '+':
        advance(1);
        return TK_PLUS;

      case '.':
        advance(1);
        if(next_c() == '{') {
          advance(1);
          return TK_CASCADE;
        }

        return TK_DOT;

      case ',':
        advance(1);
        return TK_COMMA;

      case '}':
        advance(1);
        return TK_RB;

      case '(':
        advance(1);
        return TK_LP;

      case ')':
        advance(1);
        return TK_RP;

      case '=':
        advance(1);
        return TK_EQUAL;

      case '\n':
        column_ = 0;
        line_++;

        // fallthrough
      case ';':
        advance(1);
        return TK_FIN;

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

  struct Keyword {
    const char* str;
    int token;
  };

  static Keyword cKeywords[256][10] = {
    ['c'] = {{"class", TK_CLASS}, {0,0}},
    ['d'] = {{"def", TK_DEF}, {0,0}},
    ['e'] = {{"end", TK_END}, {0,0}},
    ['f'] = {{"false", TK_FALSE}, {0,0}},
    ['i'] = {
              {"if", TK_IF}, {"import", TK_IMPORT},
              {0,0}
            },
    ['n'] = {{"nil", TK_NIL}, {0,0}},
    ['r'] = {{"rescue", TK_RESCUE}, {0,0}},
    ['t'] = {
              {"true", TK_TRUE},
              {"try", TK_TRY},
              {0,0}
            }
  };

  int Parser::keyword_match() {
    Keyword* k = cKeywords[(int)pos_[0]];

    while(k->str) {
      int len = strlen(k->str);
      const char* str = next_str(len);

      if(str && strncmp(str, k->str, len) == 0) {
        // Check that the data following it isn't an alpha
        // character, otherwise we're inside this string
        // as a subsequence.
        const char n = pos_[len];
        if(!n || !isalpha(n)) {
          advance(len);
          return k->token;
        }
      }

      k++;
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
    return TK_ID;
  }

  bool Parser::parse(bool debug) {
    next_c(); // prime the buffer
    engine_ = mariusParserAlloc(malloc);

    ParserState S(*this);

    FILE* stream = 0;

    if(debug) {
      stream = fopen("debug.out", "wb");
      mariusParserTrace(stream, (char*)">");
    }

    for(;;) {
      int token = next_token();
      if(token == -1) break;

      mariusParser(engine_, token, value_, &S);

      if(S.syntax_error_p()) break;

      if(token == TK_EOF) {
        mariusParser(engine_, 0, value_, &S);
        break;
      }
    }

    mariusParserFree(engine_, free);

    if(debug) fclose(stream);

    if(S.syntax_error_p()) return false;

    top_ = S.top();

    return true;
  }
}
