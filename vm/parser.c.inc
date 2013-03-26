/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#include <assert.h>
#line 2 "vm/parser.lm"

#include "parser_state.hpp"
#include "parser_tokens.h"
#include <iostream>
#line 14 "vm/parser.c.inc"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    mariusParserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is mariusParserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    mariusParserARG_SDECL     A static variable declaration for the %extra_argument
**    mariusParserARG_PDECL     A parameter declaration for the %extra_argument
**    mariusParserARG_STORE     Code to store %extra_argument into yypParser
**    mariusParserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 74
#define YYACTIONTYPE unsigned char
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy30;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 150
#define YYNRULE 78
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (718)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    25,  144,  145,  143,  150,   78,   83,  141,   69,   85,
 /*    10 */    84,  132,  131,  130,  129,  128,   77,   88,  124,   42,
 /*    20 */    30,   31,   28,   29,   27,   26,  111,  115,   22,   33,
 /*    30 */    76,   46,   56,   21,   25,  144,    7,  143,  142,   78,
 /*    40 */    74,  141,   73,   27,   26,  132,  131,  130,  129,  128,
 /*    50 */    77,   88,  124,   30,   31,   28,   29,   27,   26,  140,
 /*    60 */   111,  125,   22,   33,   76,   46,  144,   21,   25,   93,
 /*    70 */   116,  143,   67,   78,   89,  141,  139,  123,   64,  132,
 /*    80 */   131,  130,  129,  128,   77,   88,  124,   50,  112,   49,
 /*    90 */   115,  122,  115,   34,  111,   20,   22,   33,   76,   46,
 /*   100 */   121,   21,   25,  144,  120,  143,  119,   78,   83,  141,
 /*   110 */    69,   85,   84,  132,  131,  130,  129,  128,   77,   88,
 /*   120 */   124,   32,   83,   51,   69,   85,   84,   79,  111,   99,
 /*   130 */    22,   33,   76,   46,   24,   21,   25,  144,   36,  115,
 /*   140 */   136,   78,   92,    5,  115,  115,   94,  132,  131,  130,
 /*   150 */   129,  128,   77,   88,  124,   28,   29,   27,   26,  123,
 /*   160 */    65,  110,  111,  114,   22,   33,   76,   46,  104,   21,
 /*   170 */    25,  144,  123,   39,  109,   78,  229,    3,   23,  107,
 /*   180 */    54,  132,  131,  130,  129,  128,   77,   88,  124,  102,
 /*   190 */   101,    4,  115,   55,  138,   72,  111,    6,   22,   33,
 /*   200 */    76,   46,   18,   21,   25,  144,  103,   13,  108,   78,
 /*   210 */   118,   81,  113,   12,   41,  132,  131,  130,  129,  128,
 /*   220 */    77,   88,  124,   80,   17,   16,    9,   15,  100,    8,
 /*   230 */   111,   14,   22,   33,   76,   46,    2,   21,   25,  144,
 /*   240 */    68,   19,   66,   78,   10,   87,  230,  123,   64,  132,
 /*   250 */   131,  130,  129,  128,   77,   88,  124,   50,  112,   49,
 /*   260 */    11,    1,  230,  230,  111,  230,   22,   33,   76,   46,
 /*   270 */    44,   21,   25,  144,  230,  230,  106,   78,  230,  230,
 /*   280 */   230,  230,  230,  132,  131,  130,  129,  128,   77,   88,
 /*   290 */   124,  230,  230,  230,  230,  230,  230,  230,  111,  230,
 /*   300 */    22,   33,   76,   46,  230,   21,   25,  144,  230,  230,
 /*   310 */    71,   78,  230,  230,  230,  123,   64,  132,  131,  130,
 /*   320 */   129,  128,   77,   88,  124,   50,  112,   49,  230,  230,
 /*   330 */   230,  230,  111,  230,   22,   33,   76,   46,  230,   21,
 /*   340 */    25,  230,  230,  230,   70,   78,  230,  230,  230,  123,
 /*   350 */    64,  132,  131,  130,  129,  128,   77,   88,  124,   50,
 /*   360 */   112,   49,  230,  230,  230,  230,  111,  230,   22,   33,
 /*   370 */    76,   46,  230,   21,  230,  230,  230,  230,  230,   57,
 /*   380 */   230,  230,   97,  148,  147,  146,  230,   91,   96,   63,
 /*   390 */    90,  230,  135,  230,  123,   64,  230,  123,   64,  230,
 /*   400 */   230,  230,  230,  230,   50,  112,   49,   50,  112,   49,
 /*   410 */   230,   57,  230,  230,   97,  148,  147,  146,  230,   91,
 /*   420 */    95,   63,   90,  230,  230,  230,  123,   64,  230,  230,
 /*   430 */   230,  230,  230,  230,  230,  230,   50,  112,   49,   35,
 /*   440 */   230,  230,   97,  148,  147,  146,  230,   91,  230,   63,
 /*   450 */    90,  230,  230,  230,  123,   64,  230,  230,  230,  230,
 /*   460 */   230,  230,  230,  230,   50,  112,   49,  149,  148,  147,
 /*   470 */   146,  230,   91,  230,   63,   90,  230,  230,  230,  123,
 /*   480 */    64,  230,   25,  230,  230,  230,  230,  127,  230,   50,
 /*   490 */   112,   49,  230,  132,  131,  130,  129,  128,  126,   88,
 /*   500 */   124,   25,  230,  230,  230,  230,   86,  230,  111,  230,
 /*   510 */   230,  230,  132,  131,  130,  129,  128,  126,   88,  124,
 /*   520 */   105,   53,  230,  230,   63,  127,   98,  111,  230,  123,
 /*   530 */    64,  132,  131,  130,  129,  128,  126,   88,  124,   50,
 /*   540 */   112,   49,   62,  230,  230,  230,  230,  123,   64,  230,
 /*   550 */    52,  230,   75,  230,  117,   61,  230,   50,  112,   49,
 /*   560 */   123,   64,  230,  230,  230,   82,  230,  117,  230,  230,
 /*   570 */    50,  112,   49,  230,  230,  105,   40,  230,  230,   63,
 /*   580 */   230,  230,  105,   48,  123,   64,   63,  230,  230,  105,
 /*   590 */    47,  123,   64,   63,   50,  112,   49,  230,  123,   64,
 /*   600 */   230,   50,  112,   49,  230,  230,  230,  230,   50,  112,
 /*   610 */    49,  105,   45,  230,  230,   63,  230,  230,  105,   43,
 /*   620 */   123,   64,   63,  230,  230,  230,  230,  123,   64,  230,
 /*   630 */    50,  112,   49,  230,  230,  230,  137,   50,  112,   49,
 /*   640 */    63,  230,  230,  230,  134,  123,   64,  133,  230,  123,
 /*   650 */    64,  230,  123,   64,  230,   50,  112,   49,  230,   50,
 /*   660 */   112,   49,   50,  112,   49,   60,  230,  230,  230,  230,
 /*   670 */   123,   64,  230,   59,  230,  230,  230,  230,  123,   64,
 /*   680 */    50,  112,   49,  230,  230,  230,   38,  230,   50,  112,
 /*   690 */    49,  123,   64,   58,  230,  230,  230,  230,  123,   64,
 /*   700 */    37,   50,  112,   49,  230,  123,   64,  230,   50,  112,
 /*   710 */    49,  230,  230,  230,  230,   50,  112,   49,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     7,    8,    9,   10,    0,   12,   24,   14,   26,   27,
 /*    10 */    28,   18,   19,   20,   21,   22,   23,   24,   25,   12,
 /*    20 */     1,    2,    3,    4,    5,    6,   33,    8,   35,   36,
 /*    30 */    37,   38,   12,   40,    7,    8,   61,   10,   11,   12,
 /*    40 */    65,   14,   67,    5,    6,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,    1,    2,    3,    4,    5,    6,   12,
 /*    60 */    33,   12,   35,   36,   37,   38,    8,   40,    7,    8,
 /*    70 */    12,   10,   54,   12,   15,   14,   17,   59,   60,   18,
 /*    80 */    19,   20,   21,   22,   23,   24,   25,   69,   70,   71,
 /*    90 */     8,   17,    8,   30,   33,   13,   35,   36,   37,   38,
 /*   100 */    12,   40,    7,    8,   12,   10,   12,   12,   24,   14,
 /*   110 */    26,   27,   28,   18,   19,   20,   21,   22,   23,   24,
 /*   120 */    25,   12,   24,   15,   26,   27,   28,   12,   33,   31,
 /*   130 */    35,   36,   37,   38,   30,   40,    7,    8,   29,    8,
 /*   140 */    11,   12,   45,   46,    8,    8,    9,   18,   19,   20,
 /*   150 */    21,   22,   23,   24,   25,    3,    4,    5,    6,   59,
 /*   160 */    60,   34,   33,   32,   35,   36,   37,   38,   32,   40,
 /*   170 */     7,    8,   59,   60,   11,   12,   42,   43,   30,   12,
 /*   180 */    58,   18,   19,   20,   21,   22,   23,   24,   25,   17,
 /*   190 */    17,   46,    8,   16,   12,   57,   33,   46,   35,   36,
 /*   200 */    37,   38,   46,   40,    7,    8,   63,   15,   11,   12,
 /*   210 */    66,   12,   12,   72,   68,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   34,   46,   46,   46,   46,   59,   46,
 /*   230 */    33,   46,   35,   36,   37,   38,   46,   40,    7,    8,
 /*   240 */    46,   46,   54,   12,   46,   16,   73,   59,   60,   18,
 /*   250 */    19,   20,   21,   22,   23,   24,   25,   69,   70,   71,
 /*   260 */    46,   46,   73,   73,   33,   73,   35,   36,   37,   38,
 /*   270 */    39,   40,    7,    8,   73,   73,   11,   12,   73,   73,
 /*   280 */    73,   73,   73,   18,   19,   20,   21,   22,   23,   24,
 /*   290 */    25,   73,   73,   73,   73,   73,   73,   73,   33,   73,
 /*   300 */    35,   36,   37,   38,   73,   40,    7,    8,   73,   73,
 /*   310 */    54,   12,   73,   73,   73,   59,   60,   18,   19,   20,
 /*   320 */    21,   22,   23,   24,   25,   69,   70,   71,   73,   73,
 /*   330 */    73,   73,   33,   73,   35,   36,   37,   38,   73,   40,
 /*   340 */     7,   73,   73,   73,   54,   12,   73,   73,   73,   59,
 /*   350 */    60,   18,   19,   20,   21,   22,   23,   24,   25,   69,
 /*   360 */    70,   71,   73,   73,   73,   73,   33,   73,   35,   36,
 /*   370 */    37,   38,   73,   40,   73,   73,   73,   73,   73,   44,
 /*   380 */    73,   73,   47,   48,   49,   50,   73,   52,   53,   54,
 /*   390 */    55,   73,   54,   73,   59,   60,   73,   59,   60,   73,
 /*   400 */    73,   73,   73,   73,   69,   70,   71,   69,   70,   71,
 /*   410 */    73,   44,   73,   73,   47,   48,   49,   50,   73,   52,
 /*   420 */    53,   54,   55,   73,   73,   73,   59,   60,   73,   73,
 /*   430 */    73,   73,   73,   73,   73,   73,   69,   70,   71,   44,
 /*   440 */    73,   73,   47,   48,   49,   50,   73,   52,   73,   54,
 /*   450 */    55,   73,   73,   73,   59,   60,   73,   73,   73,   73,
 /*   460 */    73,   73,   73,   73,   69,   70,   71,   47,   48,   49,
 /*   470 */    50,   73,   52,   73,   54,   55,   73,   73,   73,   59,
 /*   480 */    60,   73,    7,   73,   73,   73,   73,   12,   73,   69,
 /*   490 */    70,   71,   73,   18,   19,   20,   21,   22,   23,   24,
 /*   500 */    25,    7,   73,   73,   73,   73,   12,   73,   33,   73,
 /*   510 */    73,   73,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   520 */    50,   51,   73,   73,   54,   12,   56,   33,   73,   59,
 /*   530 */    60,   18,   19,   20,   21,   22,   23,   24,   25,   69,
 /*   540 */    70,   71,   54,   73,   73,   73,   73,   59,   60,   73,
 /*   550 */    62,   73,   64,   73,   66,   54,   73,   69,   70,   71,
 /*   560 */    59,   60,   73,   73,   73,   64,   73,   66,   73,   73,
 /*   570 */    69,   70,   71,   73,   73,   50,   51,   73,   73,   54,
 /*   580 */    73,   73,   50,   51,   59,   60,   54,   73,   73,   50,
 /*   590 */    51,   59,   60,   54,   69,   70,   71,   73,   59,   60,
 /*   600 */    73,   69,   70,   71,   73,   73,   73,   73,   69,   70,
 /*   610 */    71,   50,   51,   73,   73,   54,   73,   73,   50,   51,
 /*   620 */    59,   60,   54,   73,   73,   73,   73,   59,   60,   73,
 /*   630 */    69,   70,   71,   73,   73,   73,   50,   69,   70,   71,
 /*   640 */    54,   73,   73,   73,   54,   59,   60,   54,   73,   59,
 /*   650 */    60,   73,   59,   60,   73,   69,   70,   71,   73,   69,
 /*   660 */    70,   71,   69,   70,   71,   54,   73,   73,   73,   73,
 /*   670 */    59,   60,   73,   54,   73,   73,   73,   73,   59,   60,
 /*   680 */    69,   70,   71,   73,   73,   73,   54,   73,   69,   70,
 /*   690 */    71,   59,   60,   54,   73,   73,   73,   73,   59,   60,
 /*   700 */    54,   69,   70,   71,   73,   59,   60,   73,   69,   70,
 /*   710 */    71,   73,   73,   73,   73,   69,   70,   71,
};
#define YY_SHIFT_USE_DFLT (-19)
#define YY_SHIFT_COUNT (92)
#define YY_SHIFT_MIN   (-18)
#define YY_SHIFT_MAX   (513)
static const short yy_shift_ofst[] = {
 /*     0 */   -19,   95,   95,   61,   27,   -7,  299,  494,  299,  299,
 /*    10 */   299,  299,  333,  494,  265,  231,  197,  163,  129,  299,
 /*    20 */   475,  475,  475,  475,  475,  475,  475,  475,  475,  475,
 /*    30 */   475,  475,  229,  513,  513,  137,  513,   19,   19,   84,
 /*    40 */   136,  131,   82,  184,  184,  184,  184,  184,  184,  189,
 /*    50 */   200,  199,  192,  184,  184,  182,  177,  184,   52,   52,
 /*    60 */    52,   52,   52,   52,   98,  -18,  152,  152,   58,  109,
 /*    70 */    38,   38,   59,  173,  172,  108,  167,  148,  104,  127,
 /*    80 */   115,   63,  108,   94,   92,   88,   63,   74,   49,   47,
 /*    90 */    20,    7,    4,
};
#define YY_REDUCE_USE_DFLT (-26)
#define YY_REDUCE_COUNT (57)
#define YY_REDUCE_MIN   (-25)
#define YY_REDUCE_MAX   (646)
static const short yy_reduce_ofst[] = {
 /*     0 */   134,  367,  335,  395,  420,  420,  470,  488,  568,  561,
 /*    10 */   539,  532,  525,  501,  586,  586,  586,  586,  586,  586,
 /*    20 */   646,  639,  632,  619,  611,  593,  590,  338,  290,  256,
 /*    30 */   188,   18,  -25,  113,  100,   97,  169,  215,  214,  198,
 /*    40 */   195,  194,  190,  185,  183,  181,  180,  179,  178,  141,
 /*    50 */   146,  144,  143,  156,  151,  138,  122,  145,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   156,  228,  228,  228,  228,  228,  228,  228,  228,  228,
 /*    10 */   228,  228,  228,  228,  228,  228,  228,  228,  228,  228,
 /*    20 */   228,  228,  228,  228,  228,  228,  228,  228,  228,  228,
 /*    30 */   228,  228,  192,  228,  228,  228,  228,  228,  228,  228,
 /*    40 */   228,  228,  228,  228,  228,  228,  228,  228,  228,  218,
 /*    50 */   228,  228,  199,  228,  228,  228,  172,  228,  227,  226,
 /*    60 */   225,  197,  198,  220,  214,  205,  176,  175,  228,  228,
 /*    70 */   178,  177,  228,  228,  228,  208,  228,  188,  187,  228,
 /*    80 */   228,  228,  200,  228,  228,  228,  187,  196,  228,  228,
 /*    90 */   228,  228,  228,  157,  158,  167,  166,  152,  174,  212,
 /*   100 */   202,  209,  204,  201,  219,  163,  224,  223,  222,  221,
 /*   110 */   217,  216,  215,  211,  213,  161,  210,  207,  206,  195,
 /*   120 */   194,  193,  203,  191,  190,  189,  188,  187,  186,  185,
 /*   130 */   184,  183,  182,  181,  180,  179,  169,  162,  171,  173,
 /*   140 */   170,  168,  165,  164,  160,  159,  155,  154,  153,  151,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  mariusParserARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void mariusParserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "PLUS",          "MINUS",         "DIVIDE",      
  "TIMES",         "DEQUAL",        "NEQUAL",        "NOT",         
  "FIN",           "EOF",           "CLASS",         "END",         
  "ID",            "LT",            "DEF",           "COMMA",       
  "LP",            "RP",            "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "COLON",         "LITSTR",        "DOT",           "ATTR",        
  "DCOLON",        "DOLLAR",        "EQUAL",         "CASCADE",     
  "RB",            "LB",            "PIPE",          "IF",          
  "UNLESS",        "IMPORT",        "TRY",           "RESCUE",      
  "RAISE",         "error",         "program",       "opt_fin",     
  "l1",            "last_fin",      "fin",           "l1e",         
  "class",         "def",           "stmt",          "seq",         
  "class_start",   "class_body",    "expr",          "def_start",   
  "def_body",      "id_list",       "def_args",      "sexpr",       
  "send",          "arg_list_start",  "arg_list_elems",  "opt_kw_arg_list",
  "kw_arg_list_elems",  "arg_list",      "kw_arg",        "kw_arg_list", 
  "message_seq",   "cascade_start",  "cascade",       "lambda_start",
  "lambda_args", 
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= opt_fin l1 last_fin",
 /*   1 */ "l1 ::= l1 fin l1e",
 /*   2 */ "l1 ::= l1e",
 /*   3 */ "l1e ::= class",
 /*   4 */ "l1e ::= def",
 /*   5 */ "l1e ::= stmt",
 /*   6 */ "opt_fin ::=",
 /*   7 */ "opt_fin ::= opt_fin FIN",
 /*   8 */ "last_fin ::= EOF",
 /*   9 */ "last_fin ::= fin EOF",
 /*  10 */ "fin ::= fin FIN",
 /*  11 */ "fin ::= FIN",
 /*  12 */ "seq ::= seq fin stmt",
 /*  13 */ "seq ::= stmt",
 /*  14 */ "class_start ::= CLASS",
 /*  15 */ "class_body ::= l1 fin END",
 /*  16 */ "class ::= class_start ID fin class_body",
 /*  17 */ "class ::= class_start ID LT expr fin class_body",
 /*  18 */ "def_start ::= DEF",
 /*  19 */ "def_body ::= seq fin END",
 /*  20 */ "id_list ::= id_list COMMA ID",
 /*  21 */ "id_list ::= ID",
 /*  22 */ "def_args ::=",
 /*  23 */ "def_args ::= LP id_list RP",
 /*  24 */ "def ::= def_start ID def_args fin def_body",
 /*  25 */ "expr ::= expr MINUS expr",
 /*  26 */ "expr ::= expr PLUS expr",
 /*  27 */ "expr ::= expr TIMES expr",
 /*  28 */ "expr ::= expr DIVIDE expr",
 /*  29 */ "expr ::= expr DEQUAL expr",
 /*  30 */ "expr ::= expr NEQUAL expr",
 /*  31 */ "expr ::= NOT expr",
 /*  32 */ "sexpr ::= NUM",
 /*  33 */ "sexpr ::= NIL",
 /*  34 */ "sexpr ::= TRUE",
 /*  35 */ "sexpr ::= FALSE",
 /*  36 */ "sexpr ::= SELF",
 /*  37 */ "sexpr ::= ID",
 /*  38 */ "sexpr ::= IVAR",
 /*  39 */ "sexpr ::= COLON ID",
 /*  40 */ "sexpr ::= LITSTR",
 /*  41 */ "send ::= sexpr",
 /*  42 */ "send ::= send DOT ID",
 /*  43 */ "send ::= send ATTR ID",
 /*  44 */ "send ::= send DCOLON ID",
 /*  45 */ "send ::= send COLON ID",
 /*  46 */ "arg_list_start ::= LP",
 /*  47 */ "arg_list_elems ::= arg_list_elems COMMA expr",
 /*  48 */ "arg_list_elems ::= expr",
 /*  49 */ "opt_kw_arg_list ::=",
 /*  50 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  51 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  52 */ "send ::= send DOT DOLLAR sexpr",
 /*  53 */ "send ::= send DOT ID LP RP",
 /*  54 */ "send ::= send DOT ID arg_list RP",
 /*  55 */ "kw_arg ::= ID EQUAL send",
 /*  56 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  57 */ "kw_arg_list_elems ::= kw_arg",
 /*  58 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  59 */ "send ::= send DOT ID kw_arg_list RP",
 /*  60 */ "message_seq ::= message_seq fin ID",
 /*  61 */ "message_seq ::= ID",
 /*  62 */ "cascade_start ::= send CASCADE",
 /*  63 */ "cascade ::= cascade_start message_seq RB",
 /*  64 */ "cascade ::= send",
 /*  65 */ "expr ::= cascade",
 /*  66 */ "lambda_start ::= LB",
 /*  67 */ "lambda_args ::= PIPE ID PIPE",
 /*  68 */ "lambda_args ::=",
 /*  69 */ "expr ::= lambda_start lambda_args seq RB",
 /*  70 */ "stmt ::= expr",
 /*  71 */ "stmt ::= IF expr fin seq fin END",
 /*  72 */ "stmt ::= UNLESS send fin seq fin END",
 /*  73 */ "stmt ::= IMPORT ID",
 /*  74 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  75 */ "stmt ::= ID EQUAL expr",
 /*  76 */ "stmt ::= IVAR EQUAL expr",
 /*  77 */ "stmt ::= RAISE expr",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to mariusParser and mariusParserFree.
*/
void *mariusParserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  mariusParserARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
  mariusParserARG_STORE; /* Quiet a warning about the arg not being used */
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from mariusParserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void mariusParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int mariusParserStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   mariusParserARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   mariusParserARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 42, 3 },
  { 44, 3 },
  { 44, 1 },
  { 47, 1 },
  { 47, 1 },
  { 47, 1 },
  { 43, 0 },
  { 43, 2 },
  { 45, 1 },
  { 45, 2 },
  { 46, 2 },
  { 46, 1 },
  { 51, 3 },
  { 51, 1 },
  { 52, 1 },
  { 53, 3 },
  { 48, 4 },
  { 48, 6 },
  { 55, 1 },
  { 56, 3 },
  { 57, 3 },
  { 57, 1 },
  { 58, 0 },
  { 58, 3 },
  { 49, 5 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 2 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 2 },
  { 59, 1 },
  { 60, 1 },
  { 60, 3 },
  { 60, 3 },
  { 60, 3 },
  { 60, 3 },
  { 61, 1 },
  { 62, 3 },
  { 62, 1 },
  { 63, 0 },
  { 63, 2 },
  { 65, 3 },
  { 60, 4 },
  { 60, 5 },
  { 60, 5 },
  { 66, 3 },
  { 64, 3 },
  { 64, 1 },
  { 67, 2 },
  { 60, 5 },
  { 68, 3 },
  { 68, 1 },
  { 69, 2 },
  { 70, 3 },
  { 70, 1 },
  { 54, 1 },
  { 71, 1 },
  { 72, 3 },
  { 72, 0 },
  { 54, 4 },
  { 50, 1 },
  { 50, 6 },
  { 50, 6 },
  { 50, 2 },
  { 50, 9 },
  { 50, 3 },
  { 50, 3 },
  { 50, 2 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  mariusParserARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* program ::= opt_fin l1 last_fin */
#line 28 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy30.a)); }
#line 988 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 30 "vm/parser.lm"
{ yygotominor.yy30.a = S->seq(yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 994 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 41: /* send ::= sexpr */ yytestcase(yyruleno==41);
      case 64: /* cascade ::= send */ yytestcase(yyruleno==64);
      case 65: /* expr ::= cascade */ yytestcase(yyruleno==65);
      case 70: /* stmt ::= expr */ yytestcase(yyruleno==70);
#line 31 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[0].minor.yy30.a; }
#line 1007 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 49 "vm/parser.lm"
{ S->start_class(); }
#line 1012 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 19: /* def_body ::= seq fin END */ yytestcase(yyruleno==19);
#line 50 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[-2].minor.yy30.a; }
#line 1018 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 52 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy30.a);
             }
#line 1025 "vm/parser.c.inc"
        break;
      case 17: /* class ::= class_start ID LT expr fin class_body */
#line 56 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a);
             }
#line 1032 "vm/parser.c.inc"
        break;
      case 18: /* def_start ::= DEF */
#line 60 "vm/parser.lm"
{ S->start_def(); }
#line 1037 "vm/parser.c.inc"
        break;
      case 20: /* id_list ::= id_list COMMA ID */
      case 21: /* id_list ::= ID */ yytestcase(yyruleno==21);
#line 63 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1043 "vm/parser.c.inc"
        break;
      case 24: /* def ::= def_start ID def_args fin def_body */
#line 69 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy30.a);
            }
#line 1050 "vm/parser.c.inc"
        break;
      case 25: /* expr ::= expr MINUS expr */
#line 73 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("-", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1055 "vm/parser.c.inc"
        break;
      case 26: /* expr ::= expr PLUS expr */
#line 74 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("+", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1060 "vm/parser.c.inc"
        break;
      case 27: /* expr ::= expr TIMES expr */
#line 75 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("*", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1065 "vm/parser.c.inc"
        break;
      case 28: /* expr ::= expr DIVIDE expr */
#line 76 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("/", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1070 "vm/parser.c.inc"
        break;
      case 29: /* expr ::= expr DEQUAL expr */
#line 77 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("==", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1075 "vm/parser.c.inc"
        break;
      case 30: /* expr ::= expr NEQUAL expr */
#line 78 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a)); }
#line 1080 "vm/parser.c.inc"
        break;
      case 31: /* expr ::= NOT expr */
#line 79 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(yymsp[0].minor.yy30.a); }
#line 1085 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= NUM */
#line 81 "vm/parser.lm"
{ yygotominor.yy30.a = S->number(yymsp[0].minor.yy0.i); }
#line 1090 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= NIL */
#line 82 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_nil();  }
#line 1095 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= TRUE */
#line 83 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_true();  }
#line 1100 "vm/parser.c.inc"
        break;
      case 35: /* sexpr ::= FALSE */
#line 84 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_false(); }
#line 1105 "vm/parser.c.inc"
        break;
      case 36: /* sexpr ::= SELF */
#line 85 "vm/parser.lm"
{ yygotominor.yy30.a = S->self(); }
#line 1110 "vm/parser.c.inc"
        break;
      case 37: /* sexpr ::= ID */
#line 86 "vm/parser.lm"
{ yygotominor.yy30.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1115 "vm/parser.c.inc"
        break;
      case 38: /* sexpr ::= IVAR */
#line 87 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1120 "vm/parser.c.inc"
        break;
      case 39: /* sexpr ::= COLON ID */
      case 40: /* sexpr ::= LITSTR */ yytestcase(yyruleno==40);
#line 88 "vm/parser.lm"
{ yygotominor.yy30.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1126 "vm/parser.c.inc"
        break;
      case 42: /* send ::= send DOT ID */
#line 92 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-2].minor.yy30.a, *yymsp[0].minor.yy0.s); }
#line 1131 "vm/parser.c.inc"
        break;
      case 43: /* send ::= send ATTR ID */
#line 93 "vm/parser.lm"
{ yygotominor.yy30.a = S->attr(yymsp[-2].minor.yy30.a, *yymsp[0].minor.yy0.s); }
#line 1136 "vm/parser.c.inc"
        break;
      case 44: /* send ::= send DCOLON ID */
#line 94 "vm/parser.lm"
{ yygotominor.yy30.a = S->dcolon(yymsp[-2].minor.yy30.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1141 "vm/parser.c.inc"
        break;
      case 45: /* send ::= send COLON ID */
#line 95 "vm/parser.lm"
{ yygotominor.yy30.a = S->cast(yymsp[-2].minor.yy30.a, S->named(*yymsp[0].minor.yy0.s)); }
#line 1146 "vm/parser.c.inc"
        break;
      case 46: /* arg_list_start ::= LP */
#line 99 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1151 "vm/parser.c.inc"
        break;
      case 47: /* arg_list_elems ::= arg_list_elems COMMA expr */
      case 48: /* arg_list_elems ::= expr */ yytestcase(yyruleno==48);
#line 100 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy30.a); }
#line 1157 "vm/parser.c.inc"
        break;
      case 52: /* send ::= send DOT DOLLAR sexpr */
#line 108 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect(yymsp[-3].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1162 "vm/parser.c.inc"
        break;
      case 53: /* send ::= send DOT ID LP RP */
#line 110 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s); }
#line 1167 "vm/parser.c.inc"
        break;
      case 54: /* send ::= send DOT ID arg_list RP */
#line 111 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s); }
#line 1172 "vm/parser.c.inc"
        break;
      case 55: /* kw_arg ::= ID EQUAL send */
#line 115 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1177 "vm/parser.c.inc"
        break;
      case 59: /* send ::= send DOT ID kw_arg_list RP */
#line 122 "vm/parser.lm"
{
              yygotominor.yy30.a = S->call_kw_args(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s);
            }
#line 1184 "vm/parser.c.inc"
        break;
      case 60: /* message_seq ::= message_seq fin ID */
      case 61: /* message_seq ::= ID */ yytestcase(yyruleno==61);
#line 128 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1190 "vm/parser.c.inc"
        break;
      case 62: /* cascade_start ::= send CASCADE */
#line 131 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy30.a); }
#line 1195 "vm/parser.c.inc"
        break;
      case 63: /* cascade ::= cascade_start message_seq RB */
#line 132 "vm/parser.lm"
{ yygotominor.yy30.a = S->end_cascade(); }
#line 1200 "vm/parser.c.inc"
        break;
      case 66: /* lambda_start ::= LB */
#line 140 "vm/parser.lm"
{ S->start_lambda(); }
#line 1205 "vm/parser.c.inc"
        break;
      case 67: /* lambda_args ::= PIPE ID PIPE */
#line 142 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1210 "vm/parser.c.inc"
        break;
      case 69: /* expr ::= lambda_start lambda_args seq RB */
#line 145 "vm/parser.lm"
{ yygotominor.yy30.a = S->lambda(yymsp[-1].minor.yy30.a); }
#line 1215 "vm/parser.c.inc"
        break;
      case 71: /* stmt ::= IF expr fin seq fin END */
#line 153 "vm/parser.lm"
{ yygotominor.yy30.a = S->if_cond(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1220 "vm/parser.c.inc"
        break;
      case 72: /* stmt ::= UNLESS send fin seq fin END */
#line 154 "vm/parser.lm"
{ yygotominor.yy30.a = S->unless(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1225 "vm/parser.c.inc"
        break;
      case 73: /* stmt ::= IMPORT ID */
#line 158 "vm/parser.lm"
{ yygotominor.yy30.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1230 "vm/parser.c.inc"
        break;
      case 74: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 160 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_try(yymsp[-6].minor.yy30.a, yymsp[-2].minor.yy30.a);
            }
#line 1237 "vm/parser.c.inc"
        break;
      case 75: /* stmt ::= ID EQUAL expr */
#line 164 "vm/parser.lm"
{ yygotominor.yy30.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1242 "vm/parser.c.inc"
        break;
      case 76: /* stmt ::= IVAR EQUAL expr */
#line 165 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1247 "vm/parser.c.inc"
        break;
      case 77: /* stmt ::= RAISE expr */
#line 166 "vm/parser.lm"
{ yygotominor.yy30.a = S->raise(yymsp[0].minor.yy30.a); }
#line 1252 "vm/parser.c.inc"
        break;
      default:
      /* (6) opt_fin ::= */ yytestcase(yyruleno==6);
      /* (7) opt_fin ::= opt_fin FIN */ yytestcase(yyruleno==7);
      /* (8) last_fin ::= EOF */ yytestcase(yyruleno==8);
      /* (9) last_fin ::= fin EOF */ yytestcase(yyruleno==9);
      /* (10) fin ::= fin FIN */ yytestcase(yyruleno==10);
      /* (11) fin ::= FIN */ yytestcase(yyruleno==11);
      /* (22) def_args ::= */ yytestcase(yyruleno==22);
      /* (23) def_args ::= LP id_list RP */ yytestcase(yyruleno==23);
      /* (49) opt_kw_arg_list ::= */ yytestcase(yyruleno==49);
      /* (50) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==50);
      /* (51) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==51);
      /* (56) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==56);
      /* (57) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==57);
      /* (58) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==58);
      /* (68) lambda_args ::= */ yytestcase(yyruleno==68);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  mariusParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  mariusParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  mariusParserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 21 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1335 "vm/parser.c.inc"
  mariusParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  mariusParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  mariusParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "mariusParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void mariusParser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  mariusParserTOKENTYPE yyminor       /* The value for the token */
  mariusParserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  mariusParserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
