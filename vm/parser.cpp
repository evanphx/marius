
#include <string.h>
#include <stdlib.h>

#include "parser.hpp"

#include "parser_tokens.h"

#include "parser.c.inc"

#include "buffer.hpp"
#include "utf8.hpp"

namespace r5 {

  void Parser::import_start() {
    import_name_ = true;
  }

  void Parser::import_end() {
    import_name_ = false;
  }

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
        if(left > 0) {
          // shift the unused data up to the front of the buffer.
          memmove((void*)buffer_, pos_, left);
          end_ = buffer_ + left;
          *end_ = 0;
        }
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
    value_.line = line_;
    value_.i = 0;

    if(import_name_) {
      return import_name_match();
    }

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
      case '-':
      case '$':
        if(match_operator()) {
          return TK_OP1_SET;
        } else {
          return TK_OP1;
        }
        break;

      case '*':
      case '/':
        if(match_operator()) {
          return TK_OP2_SET;
        } else {
          return TK_OP2;
        }
        break;

      case '%':
        advance(1);

        if(next_c() == '(') {
          advance(1);
          return TK_TUPLE_START;
        }

        if(next_c() == '{') {
          advance(1);
          return TK_DICT_START;
        }

        if(next_c() == '[') {
          advance(1);
          return TK_LIST;
        }

        return sym_match();

      case '.':
        advance(1);

        if(next_c() == '$') {
          advance(1);
          return TK_DOT_DOLLAR;
        }

        return id_match(TK_DOT);

      case ',':
        advance(1);
        return TK_COMMA;

      case '|':
        advance(1);
        value_.s = String::internalize(S, "|");
        return TK_PIPE;

      case '}':
        advance(1);
        return TK_RB;

      case '{':
        advance(1);
        return TK_LB;

      case '[':
        advance(1);
        if(next_c() == ']') {
          advance(1);
          value_.s = String::internalize(S, "[]");
          return TK_SQUARE;
        }

        return TK_LSB;

      case ']':
        advance(1);
        return TK_RSB;

      case '(':
        advance(1);
        return TK_LP;

      case ')':
        advance(1);
        return TK_RP;

      case '=':
        advance(1);

        if(next_c() == '=') {
          advance(1);

          if(next_c() == '=') {
            advance(1);
            value_.s = String::internalize(S, "===");
          } else {
            value_.s = String::internalize(S, "==");
          }

          return TK_OP0;
        }

        return TK_EQUAL;

      case '!':
        advance(1);

        if(next_c() == '=') {
          advance(1);
          return TK_NEQUAL;
        }

        return TK_NOT;
      case '<':
        {
          bool s = match_operator();

          if(value_.s->equal("<")) {
            return TK_LT;
          }

          return s ? TK_OP0_SET : TK_OP0;
        }
      case '>':
        return match_operator() ? TK_OP0_SET : TK_OP0;

      case '\n':
        column_ = 0;
        line_++;

        advance(1);
        return TK_NL;

      case ';':
        advance(1);
        return TK_SEMI;

      case '@':
        advance(1);
        return id_match(TK_IVAR);

      case ':':
        advance(1);

        if(next_c() == ':') {
          advance(1);
          value_.s = String::internalize(S, "::");
          return TK_DCOLON;
        }

        return TK_CAST;

      case '&':
        {
          bool s = match_operator();

          if(value_.s->equal("&&")) {
            return TK_AND;
          }

          return s ? TK_OP0_SET : TK_OP0;
        }

      case '"':
        advance(1);
        return str_match();

      case '#':
        while(next_c() != '\n') {
          if(!next_c()) break;
          advance(1);
        }

        column_ = 0;
        line_++;

        advance(1);

        goto again;

      default:
        {
          int t = keyword_match();
          if(t != -1) return t;

          if(isalpha(c)) return id_match(TK_ID);

          printf("Unknown token at line %d, column %d: '%c'\n",
                 line_, column_, c);
        }
    }


    return -1;
  }

  int Parser::import_name_match() {
    import_name_ = false;
    ScratchBuffer buf;

    while(next_c() == ' ' ||
          next_c() == '\t') advance(1);

    while(isalnum(next_c()) ||
          next_c() == '_' ||
          next_c() == '.') {
      buf.append(next_c());
      advance(1);
    }

    value_.s = String::internalize(S, buf.copy_out());
    return TK_DOT_NAME;
  }

  bool Parser::match_operator() {
    ScratchBuffer buf;

    buf.append(next_c());
    advance(1);

    for(;;) {
      char c = next_c();
      switch(c) {
      case '+':
      case '-':
      case '!':
      case '@':
      case '#':
      case '$':
      case '%':
      case '^':
      case '&':
      case '*':
      case '<':
      case '>':
      case '?':
      case '|':
      case '~':
      case ':':
      case '=':
      case '/':
        buf.append(c);
        advance(1);
        break;
      default:
        bool set = false;
        if(buf.last() == '=') {
          buf.remove_last();
          set = true;
        }

        value_.s = String::internalize(S, buf.copy_out());
        return set;
      }
    }
  }

  static inline int min(int a, int b) {
    return a < b ? a : b;
  }

  struct Keyword {
    const char* str;
    int token;

    Keyword()
      : str(0)
      , token(0)
    {}

    Keyword(const char* s, int t)
      : str(s)
      , token(t)
    {}
  };

  static Keyword* cKeywords[256] = {0};

  void Parser::init_keywords() {
    Keyword* k = new Keyword[2];
    k[0] = Keyword("as", TK_AS);

    cKeywords[(int)'a'] = k;

    k = new Keyword[2];
    k[0] = Keyword("class", TK_CLASS);

    cKeywords[(int)'c'] = k;

    k = new Keyword[2];
    k[0] = Keyword("def", TK_DEF);

    cKeywords[(int)'d'] = k;

    k = new Keyword[3];
    k[0] = Keyword("end", TK_END);
    k[1] = Keyword("else", TK_ELSE);

    cKeywords[(int)'e'] = k;

    k = new Keyword[2];
    k[0] = Keyword("false", TK_FALSE);

    cKeywords[(int)'f'] = k;

    k = new Keyword[3];
    k[0] = Keyword("if", TK_IF);
    k[1] = Keyword("import", TK_IMPORT);

    cKeywords[(int)'i'] = k;

    k = new Keyword[2];
    k[0] = Keyword("nil", TK_NIL);

    cKeywords[(int)'n'] = k;

    k = new Keyword[4];
    k[0] = Keyword("rescue", TK_RESCUE);
    k[1] = Keyword("raise", TK_RAISE);
    k[2] = Keyword("return", TK_RETURN);

    cKeywords[(int)'r'] = k;

    k = new Keyword[2];
    k[0] = Keyword("self", TK_SELF);

    cKeywords[(int)'s'] = k;

    k = new Keyword[4];
    k[0] = Keyword("true", TK_TRUE);
    k[1] = Keyword("try", TK_TRY);
    k[2] = Keyword("trait", TK_TRAIT);

    cKeywords[(int)'t'] = k;

    k = new Keyword[2];
    k[0] = Keyword("unless", TK_UNLESS);

    cKeywords[(int)'u'] = k;

    k = new Keyword[2];
    k[0] = Keyword("while", TK_WHILE);

    cKeywords[(int)'w'] = k;
  }

  int Parser::keyword_match() {
    Keyword* k = cKeywords[(int)next_c()];

    if(!k) return -1;

    while(k->str) {
      int len = strlen(k->str);
      const char* str = next_str(len);

      if(str && strncmp(str, k->str, len) == 0) {
        // Check that the data following it isn't an alpha
        // character, otherwise we're inside this string
        // as a subsequence.
        const char* str = next_str(len+1);
        if(!str) {
          advance(len);
          return k->token;
        }

        const char n = str[len];
        if(!n || (!isalpha(n) && n != '_')) {
          advance(len);
          return k->token;
        }
      }

      k++;
    }

    return -1;
  }

  int Parser::id_match(int tk) {
    ScratchBuffer buf;

    uint8_t c = next_c();

    while(c && (isalnum(c) || c == '_')) {
      buf.append(c);
      advance(1);
      c = next_c();
    }

    if(!buf.empty_p()) {
      c = next_c();
      switch(c) {
      case '?':
      case '!':
        buf.append(c);
        advance(1);
        break;
      }
    }

    value_.s = String::internalize(S, buf.copy_out());
    return tk;
  }

  int Parser::str_match() {
    ScratchBuffer buf;

    uint8_t c = next_c();

    while(c && c != '"') {
      buf.append(c);
      advance(1);
      c = next_c();
    }

    if(!c) return -1;

    advance(1);

    value_.s = String::internalize(S, buf.copy_out());
    return TK_LITSTR;
  }

  int Parser::sym_match() {
    ScratchBuffer buf;

    uint8_t c = next_c();

    while(c && isalpha(c)) {
      buf.append(c);
      advance(1);
      c = next_c();
    }

    if(!c || buf.empty_p()) return -1;

    if(c == '=' || c == '?' || c == '!') {
      buf.append(c);
      advance(1);
    }

    value_.s = String::internalize(S, buf.copy_out());
    return TK_LITSTR;
  }

  bool Parser::parse(bool debug) {
    static bool setup_keywords = false;
    if(!setup_keywords) {
      init_keywords();
      setup_keywords = true;
    }

    next_c(); // prime the buffer
    engine_ = r5ParserAlloc(malloc);

    ParserState PS(S, *this);

    FILE* stream = 0;

    if(debug) {
      stream = fopen("debug.out", "wb");
      r5ParserTrace(stream, (char*)">");
    }

    for(;;) {
      int token = next_token();
      if(token == -1) break;

      if(token == TK_IMPORT) import_start();

      r5Parser(engine_, token, value_, &PS);

      if(PS.syntax_error_p()) break;

      if(token == TK_EOF) {
        r5Parser(engine_, 0, value_, &PS);
        break;
      }
    }

    r5ParserFree(engine_, free);

    if(debug) fclose(stream);

    if(PS.syntax_error_p()) return false;

    top_ = PS.top();

    return true;
  }
}
