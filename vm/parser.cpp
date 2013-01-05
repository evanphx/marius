#include "parser.hpp"

#include "parser_tokens.h"

union Token {
  int i;
  marius::String* s;
};

#include "parser.c.inc"

namespace marius {

  int Parser::next_token() {
    if(pos_ >= end_) return 0;

    value_.i = 0;

again:

    char c = *pos_;

    switch(c) {
      case '0': case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9':
        {
          char* end;
          value_.i = strtol(pos_, &end, 0);
          if(end == pos_) return -1;

          pos_ = end;

          return NUM;
        }
      case ' ':
        while(*pos_ == ' ') pos_++;

        goto again;

      case '+':
        pos_++;
        return PLUS;

      case '.':
        pos_++;
        return DOT;

      case ';':
      case '\n':
        pos_++;
        return FIN;

      default:
        {
          int t = keyword_match();
          if(t != -1) return t;

          if(isalpha(c)) return id_match();
          printf("Unknown token: '%c'\n", c);
        }
    }


    return -1;
  }

  static inline int min(int a, int b) {
    return a < b ? a : b;
  }

  int Parser::keyword_match() {
    switch(pos_[0]) {
    case 'c':
      if(strncmp(pos_, "class", min(end_ - pos_, 5)) == 0) {
        pos_ += 5;
        return CLASS;
      }
      break;

    case 'd':
      if(strncmp(pos_, "def", min(end_ - pos_, 3)) == 0) {
        pos_ += 3;
        return DEF;
      }
      break;

    case 'e':
      if(strncmp(pos_, "end", min(end_ - pos_, 3)) == 0) {
        pos_ += 3;
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

    pos_ = p;

    value_.s = &String::internalize(strndup(start, p - start));
    return ID;
  }

  bool Parser::parse() {
    engine_ = mariusParserAlloc(malloc);

    ParserState S;

    FILE* debug = fopen("debug.out", "wb");
    mariusParserTrace(debug, (char*)">");

    for(;;) {
      int token = next_token();
      if(token == -1) break;

      mariusParser(engine_, token, value_, &S);

      if(token == 0) break;
    }

    mariusParserFree(engine_, free);

    code_ = new Code(S.sequence(), S.sequence_size(), *S.strings(), *S.codes());

    return true;
  }
}
