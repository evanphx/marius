#include "parser.hpp"

#include "parser_tokens.h"
#include "parser.c.inc"

namespace marius {

  int Parser::next_token() {
    if(pos_ >= end_) return 0;

    value_ = 0;

again:

    char c = *pos_;

    switch(c) {
      case '0': case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9':
        {
          char* end;
          value_ = strtol(pos_, &end, 0);
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

      default:
        return -1;
    }

    return -1;
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
