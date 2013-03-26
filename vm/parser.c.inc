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
#define YYNSTATE 156
#define YYNRULE 80
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
#define YY_ACTTAB_COUNT (739)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    25,  150,  151,  149,  156,   35,   85,  147,   73,   87,
 /*    10 */    86,  138,  137,  136,  135,  134,   81,   90,  130,   46,
 /*    20 */    30,   31,   28,   29,   27,   26,  115,  119,   22,   33,
 /*    30 */    80,   50,   60,   21,   25,  150,    7,  149,  148,   35,
 /*    40 */    78,  147,   77,   27,   26,  138,  137,  136,  135,  134,
 /*    50 */    81,   90,  130,   30,   31,   28,   29,   27,   26,   79,
 /*    60 */   115,  121,   22,   33,   80,   50,  150,   21,   25,   97,
 /*    70 */   120,  149,   71,   35,   93,  147,  145,  129,   68,  138,
 /*    80 */   137,  136,  135,  134,   81,   90,  130,   54,  116,   53,
 /*    90 */   119,  146,  119,  133,  115,   20,   22,   33,   80,   50,
 /*   100 */    38,   21,   25,  150,   34,  149,   88,   35,   85,  147,
 /*   110 */    73,   87,   86,  138,  137,  136,  135,  134,   81,   90,
 /*   120 */   130,   32,   85,  131,   73,   87,   86,  128,  115,  123,
 /*   130 */    22,   33,   80,   50,  127,   21,   25,  150,   40,  119,
 /*   140 */   142,   35,   96,    5,  119,  119,   98,  138,  137,  136,
 /*   150 */   135,  134,   81,   90,  130,   28,   29,   27,   26,   92,
 /*   160 */   129,   69,  115,  118,   22,   33,   80,   50,  108,   21,
 /*   170 */    25,  150,   55,   34,  113,   35,   92,  129,   43,  126,
 /*   180 */   125,  138,  137,  136,  135,  134,   81,   90,  130,  124,
 /*   190 */    24,  237,    3,   82,   23,  114,  115,  111,   22,   33,
 /*   200 */    80,   50,    4,   21,   25,  150,  106,  105,  112,   35,
 /*   210 */   119,   58,   59,  144,  107,  138,  137,  136,  135,  134,
 /*   220 */    81,   90,  130,   76,    6,   18,   13,   91,  122,  117,
 /*   230 */   115,   12,   22,   33,   80,   50,   92,   21,   25,  150,
 /*   240 */    45,   83,   70,   35,   17,   16,    9,  129,   68,  138,
 /*   250 */   137,  136,  135,  134,   81,   90,  130,   54,  116,   53,
 /*   260 */    15,   89,    8,  103,  115,   14,   22,   33,   80,   50,
 /*   270 */    48,   21,   25,  150,    2,   72,  110,   35,   19,   10,
 /*   280 */    11,    1,  238,  138,  137,  136,  135,  134,   81,   90,
 /*   290 */   130,  238,  238,  238,  238,  238,  238,  238,  115,  238,
 /*   300 */    22,   33,   80,   50,  238,   21,   25,  150,  238,  238,
 /*   310 */    75,   35,  238,  238,  238,  129,   68,  138,  137,  136,
 /*   320 */   135,  134,   81,   90,  130,   54,  116,   53,  238,  238,
 /*   330 */   238,  238,  115,  238,   22,   33,   80,   50,  238,   21,
 /*   340 */    25,  238,  238,  238,   74,   35,  238,  238,  238,  129,
 /*   350 */    68,  138,  137,  136,  135,  134,   81,   90,  130,   54,
 /*   360 */   116,   53,  238,  238,  238,  238,  115,  238,   22,   33,
 /*   370 */    80,   50,  238,   21,  238,  238,  238,  238,  238,   61,
 /*   380 */   238,  238,  101,  154,  153,  152,  238,   95,  100,   67,
 /*   390 */    94,  238,  141,  238,  129,   68,  238,  129,   68,  238,
 /*   400 */   238,  238,  238,  238,   54,  116,   53,   54,  116,   53,
 /*   410 */   238,   61,  238,  238,  101,  154,  153,  152,  238,   95,
 /*   420 */    99,   67,   94,  238,  238,  238,  129,   68,  238,  238,
 /*   430 */   238,  238,  238,  238,  238,  238,   54,  116,   53,   37,
 /*   440 */   238,  238,  101,  154,  153,  152,  238,   95,  238,   67,
 /*   450 */    94,  238,  238,  238,  129,   68,  238,  238,  238,  238,
 /*   460 */   238,  238,  238,  238,   54,  116,   53,  155,  154,  153,
 /*   470 */   152,  238,   95,  238,   67,   94,  238,  238,  238,  129,
 /*   480 */    68,  238,   25,  238,  238,  238,  238,   39,  238,   54,
 /*   490 */   116,   53,  238,  138,  137,  136,  135,  134,  132,   90,
 /*   500 */   130,   25,  238,  238,  238,  140,   36,  238,  115,  238,
 /*   510 */   129,   68,  138,  137,  136,  135,  134,  132,   90,  130,
 /*   520 */    54,  116,   53,  238,  238,  104,  238,  115,  238,  238,
 /*   530 */   238,  138,  137,  136,  135,  134,  132,   90,  130,  238,
 /*   540 */    39,  238,  238,  238,  238,  238,  138,  137,  136,  135,
 /*   550 */   134,  132,   90,  130,   66,  238,  238,  238,  238,  129,
 /*   560 */    68,  238,   56,  238,   79,  238,  121,  238,  238,   54,
 /*   570 */   116,   53,  238,  238,  238,  238,  109,   57,  238,  238,
 /*   580 */    67,  238,  102,  238,  238,  129,   68,  238,   65,  238,
 /*   590 */   238,  238,  238,  129,   68,   54,  116,   53,   84,  238,
 /*   600 */   121,  238,  238,   54,  116,   53,  238,  139,  238,  238,
 /*   610 */   109,   44,  129,   68,   67,  238,  238,  109,   52,  129,
 /*   620 */    68,   67,   54,  116,   53,  238,  129,   68,  238,   54,
 /*   630 */   116,   53,  238,  238,  238,  238,   54,  116,   53,  109,
 /*   640 */    51,  238,  238,   67,  238,  238,  109,   49,  129,   68,
 /*   650 */    67,  238,  238,  238,  238,  129,   68,  238,   54,  116,
 /*   660 */    53,  238,  238,  238,  238,   54,  116,   53,  109,   47,
 /*   670 */   238,  143,   67,  238,  238,   67,  238,  129,   68,   64,
 /*   680 */   129,   68,  238,  238,  129,   68,  238,   54,  116,   53,
 /*   690 */    54,  116,   53,   63,   54,  116,   53,  238,  129,   68,
 /*   700 */   238,   42,  238,  238,  238,  238,  129,   68,   54,  116,
 /*   710 */    53,  238,  238,  238,   62,  238,   54,  116,   53,  129,
 /*   720 */    68,   41,  238,  238,  238,  238,  129,   68,  238,   54,
 /*   730 */   116,   53,  238,  238,  238,  238,   54,  116,   53,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     7,    8,    9,   10,    0,   12,   24,   14,   26,   27,
 /*    10 */    28,   18,   19,   20,   21,   22,   23,   24,   25,   12,
 /*    20 */     1,    2,    3,    4,    5,    6,   33,    8,   35,   36,
 /*    30 */    37,   38,   12,   40,    7,    8,   61,   10,   11,   12,
 /*    40 */    65,   14,   67,    5,    6,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,    1,    2,    3,    4,    5,    6,   64,
 /*    60 */    33,   66,   35,   36,   37,   38,    8,   40,    7,    8,
 /*    70 */    12,   10,   54,   12,   15,   14,   17,   59,   60,   18,
 /*    80 */    19,   20,   21,   22,   23,   24,   25,   69,   70,   71,
 /*    90 */     8,   12,    8,   17,   33,   13,   35,   36,   37,   38,
 /*   100 */    61,   40,    7,    8,   30,   10,   67,   12,   24,   14,
 /*   110 */    26,   27,   28,   18,   19,   20,   21,   22,   23,   24,
 /*   120 */    25,   12,   24,   12,   26,   27,   28,   17,   33,   31,
 /*   130 */    35,   36,   37,   38,   17,   40,    7,    8,   29,    8,
 /*   140 */    11,   12,   45,   46,    8,    8,    9,   18,   19,   20,
 /*   150 */    21,   22,   23,   24,   25,    3,    4,    5,    6,   16,
 /*   160 */    59,   60,   33,   32,   35,   36,   37,   38,   32,   40,
 /*   170 */     7,    8,   15,   30,   11,   12,   16,   59,   60,   12,
 /*   180 */    12,   18,   19,   20,   21,   22,   23,   24,   25,   12,
 /*   190 */    30,   42,   43,   12,   30,   34,   33,   12,   35,   36,
 /*   200 */    37,   38,   46,   40,    7,    8,   17,   17,   11,   12,
 /*   210 */     8,   58,   16,   12,   63,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   57,   46,   46,   15,   12,   66,   12,
 /*   230 */    33,   72,   35,   36,   37,   38,   16,   40,    7,    8,
 /*   240 */    68,   34,   54,   12,   46,   46,   46,   59,   60,   18,
 /*   250 */    19,   20,   21,   22,   23,   24,   25,   69,   70,   71,
 /*   260 */    46,   16,   46,   59,   33,   46,   35,   36,   37,   38,
 /*   270 */    39,   40,    7,    8,   46,   46,   11,   12,   46,   46,
 /*   280 */    46,   46,   73,   18,   19,   20,   21,   22,   23,   24,
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
 /*   500 */    25,    7,   73,   73,   73,   54,   12,   73,   33,   73,
 /*   510 */    59,   60,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   520 */    69,   70,   71,   73,   73,   12,   73,   33,   73,   73,
 /*   530 */    73,   18,   19,   20,   21,   22,   23,   24,   25,   73,
 /*   540 */    12,   73,   73,   73,   73,   73,   18,   19,   20,   21,
 /*   550 */    22,   23,   24,   25,   54,   73,   73,   73,   73,   59,
 /*   560 */    60,   73,   62,   73,   64,   73,   66,   73,   73,   69,
 /*   570 */    70,   71,   73,   73,   73,   73,   50,   51,   73,   73,
 /*   580 */    54,   73,   56,   73,   73,   59,   60,   73,   54,   73,
 /*   590 */    73,   73,   73,   59,   60,   69,   70,   71,   64,   73,
 /*   600 */    66,   73,   73,   69,   70,   71,   73,   54,   73,   73,
 /*   610 */    50,   51,   59,   60,   54,   73,   73,   50,   51,   59,
 /*   620 */    60,   54,   69,   70,   71,   73,   59,   60,   73,   69,
 /*   630 */    70,   71,   73,   73,   73,   73,   69,   70,   71,   50,
 /*   640 */    51,   73,   73,   54,   73,   73,   50,   51,   59,   60,
 /*   650 */    54,   73,   73,   73,   73,   59,   60,   73,   69,   70,
 /*   660 */    71,   73,   73,   73,   73,   69,   70,   71,   50,   51,
 /*   670 */    73,   50,   54,   73,   73,   54,   73,   59,   60,   54,
 /*   680 */    59,   60,   73,   73,   59,   60,   73,   69,   70,   71,
 /*   690 */    69,   70,   71,   54,   69,   70,   71,   73,   59,   60,
 /*   700 */    73,   54,   73,   73,   73,   73,   59,   60,   69,   70,
 /*   710 */    71,   73,   73,   73,   54,   73,   69,   70,   71,   59,
 /*   720 */    60,   54,   73,   73,   73,   73,   59,   60,   73,   69,
 /*   730 */    70,   71,   73,   73,   73,   73,   69,   70,   71,
};
#define YY_SHIFT_USE_DFLT (-19)
#define YY_SHIFT_COUNT (96)
#define YY_SHIFT_MIN   (-18)
#define YY_SHIFT_MAX   (528)
static const short yy_shift_ofst[] = {
 /*     0 */   -19,   95,   95,   61,   27,   -7,  299,  494,  299,  299,
 /*    10 */   299,  299,  333,  494,  265,  231,  197,  163,  129,  299,
 /*    20 */   475,  475,  475,  475,  475,  475,  475,  475,  475,  475,
 /*    30 */   475,  475,  245,  528,  528,  160,  143,  137,  215,  220,
 /*    40 */   513,   19,   19,   84,  136,  131,   82,  202,  202,  202,
 /*    50 */   202,  202,  202,  207,  217,  215,  211,  202,  202,  201,
 /*    60 */   196,  202,   52,   52,   52,   52,   52,   52,   98,  -18,
 /*    70 */   152,  152,   58,  109,   38,   38,   59,  190,  189,  157,
 /*    80 */   185,  164,  161,  181,  157,  177,  168,  167,  117,  110,
 /*    90 */   111,   74,   76,   79,   20,    7,    4,
};
#define YY_REDUCE_USE_DFLT (-26)
#define YY_REDUCE_COUNT (61)
#define YY_REDUCE_MIN   (-25)
#define YY_REDUCE_MAX   (667)
static const short yy_reduce_ofst[] = {
 /*     0 */   149,  367,  335,  395,  420,  420,  526,  500,  618,  596,
 /*    10 */   589,  567,  560,  534,  621,  621,  621,  621,  621,  621,
 /*    20 */   667,  660,  647,  639,  625,  553,  451,  338,  290,  256,
 /*    30 */   188,   18,  -25,  118,  101,   39,   39,   97,   -5,   39,
 /*    40 */   204,  235,  234,  233,  232,  229,  228,  219,  216,  214,
 /*    50 */   200,  199,  198,  159,  172,  162,  151,  179,  178,  166,
 /*    60 */   153,  156,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   162,  236,  236,  236,  236,  236,  236,  236,  236,  236,
 /*    10 */   236,  236,  236,  236,  236,  236,  236,  236,  236,  236,
 /*    20 */   236,  236,  236,  236,  236,  236,  236,  236,  236,  236,
 /*    30 */   236,  236,  198,  236,  236,  193,  193,  236,  236,  193,
 /*    40 */   236,  236,  236,  236,  236,  236,  236,  236,  236,  236,
 /*    50 */   236,  236,  236,  226,  236,  236,  205,  236,  236,  236,
 /*    60 */   178,  236,  235,  234,  233,  203,  204,  228,  222,  212,
 /*    70 */   182,  181,  236,  236,  184,  183,  236,  236,  236,  215,
 /*    80 */   236,  194,  236,  236,  206,  236,  236,  236,  236,  202,
 /*    90 */   236,  236,  202,  236,  236,  236,  236,  163,  164,  173,
 /*   100 */   172,  158,  180,  208,  193,  216,  210,  207,  227,  169,
 /*   110 */   232,  231,  230,  229,  225,  224,  223,  219,  221,  167,
 /*   120 */   218,  214,  213,  220,  201,  200,  199,  217,  209,  197,
 /*   130 */   196,  195,  194,  211,  192,  191,  190,  189,  188,  187,
 /*   140 */   186,  185,  175,  168,  177,  179,  176,  174,  171,  170,
 /*   150 */   166,  165,  161,  160,  159,  157,
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
 /*  55 */ "send ::= ID LP RP",
 /*  56 */ "kw_arg ::= ID EQUAL send",
 /*  57 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  58 */ "kw_arg_list_elems ::= kw_arg",
 /*  59 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  60 */ "send ::= send DOT ID kw_arg_list RP",
 /*  61 */ "send ::= ID kw_arg_list RP",
 /*  62 */ "message_seq ::= message_seq fin ID",
 /*  63 */ "message_seq ::= ID",
 /*  64 */ "cascade_start ::= send CASCADE",
 /*  65 */ "cascade ::= cascade_start message_seq RB",
 /*  66 */ "cascade ::= send",
 /*  67 */ "expr ::= cascade",
 /*  68 */ "lambda_start ::= LB",
 /*  69 */ "lambda_args ::= PIPE ID PIPE",
 /*  70 */ "lambda_args ::=",
 /*  71 */ "expr ::= lambda_start lambda_args seq RB",
 /*  72 */ "stmt ::= expr",
 /*  73 */ "stmt ::= IF expr fin seq fin END",
 /*  74 */ "stmt ::= UNLESS send fin seq fin END",
 /*  75 */ "stmt ::= IMPORT ID",
 /*  76 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  77 */ "stmt ::= ID EQUAL expr",
 /*  78 */ "stmt ::= IVAR EQUAL expr",
 /*  79 */ "stmt ::= RAISE expr",
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
  { 60, 3 },
  { 66, 3 },
  { 64, 3 },
  { 64, 1 },
  { 67, 2 },
  { 60, 5 },
  { 60, 3 },
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
#line 998 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 30 "vm/parser.lm"
{ yygotominor.yy30.a = S->seq(yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1004 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 41: /* send ::= sexpr */ yytestcase(yyruleno==41);
      case 66: /* cascade ::= send */ yytestcase(yyruleno==66);
      case 67: /* expr ::= cascade */ yytestcase(yyruleno==67);
      case 72: /* stmt ::= expr */ yytestcase(yyruleno==72);
#line 31 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[0].minor.yy30.a; }
#line 1017 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 49 "vm/parser.lm"
{ S->start_class(); }
#line 1022 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 19: /* def_body ::= seq fin END */ yytestcase(yyruleno==19);
#line 50 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[-2].minor.yy30.a; }
#line 1028 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 52 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy30.a);
             }
#line 1035 "vm/parser.c.inc"
        break;
      case 17: /* class ::= class_start ID LT expr fin class_body */
#line 56 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a);
             }
#line 1042 "vm/parser.c.inc"
        break;
      case 18: /* def_start ::= DEF */
#line 60 "vm/parser.lm"
{ S->start_def(); }
#line 1047 "vm/parser.c.inc"
        break;
      case 20: /* id_list ::= id_list COMMA ID */
      case 21: /* id_list ::= ID */ yytestcase(yyruleno==21);
#line 63 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1053 "vm/parser.c.inc"
        break;
      case 24: /* def ::= def_start ID def_args fin def_body */
#line 69 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy30.a);
            }
#line 1060 "vm/parser.c.inc"
        break;
      case 25: /* expr ::= expr MINUS expr */
#line 73 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("-", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1065 "vm/parser.c.inc"
        break;
      case 26: /* expr ::= expr PLUS expr */
#line 74 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("+", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1070 "vm/parser.c.inc"
        break;
      case 27: /* expr ::= expr TIMES expr */
#line 75 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("*", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1075 "vm/parser.c.inc"
        break;
      case 28: /* expr ::= expr DIVIDE expr */
#line 76 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("/", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1080 "vm/parser.c.inc"
        break;
      case 29: /* expr ::= expr DEQUAL expr */
#line 77 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop("==", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1085 "vm/parser.c.inc"
        break;
      case 30: /* expr ::= expr NEQUAL expr */
#line 78 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a)); }
#line 1090 "vm/parser.c.inc"
        break;
      case 31: /* expr ::= NOT expr */
#line 79 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(yymsp[0].minor.yy30.a); }
#line 1095 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= NUM */
#line 81 "vm/parser.lm"
{ yygotominor.yy30.a = S->number(yymsp[0].minor.yy0.i); }
#line 1100 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= NIL */
#line 82 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_nil();  }
#line 1105 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= TRUE */
#line 83 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_true();  }
#line 1110 "vm/parser.c.inc"
        break;
      case 35: /* sexpr ::= FALSE */
#line 84 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_false(); }
#line 1115 "vm/parser.c.inc"
        break;
      case 36: /* sexpr ::= SELF */
#line 85 "vm/parser.lm"
{ yygotominor.yy30.a = S->self(); }
#line 1120 "vm/parser.c.inc"
        break;
      case 37: /* sexpr ::= ID */
#line 86 "vm/parser.lm"
{ yygotominor.yy30.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1125 "vm/parser.c.inc"
        break;
      case 38: /* sexpr ::= IVAR */
#line 87 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1130 "vm/parser.c.inc"
        break;
      case 39: /* sexpr ::= COLON ID */
      case 40: /* sexpr ::= LITSTR */ yytestcase(yyruleno==40);
#line 88 "vm/parser.lm"
{ yygotominor.yy30.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1136 "vm/parser.c.inc"
        break;
      case 42: /* send ::= send DOT ID */
#line 92 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-2].minor.yy30.a, *yymsp[0].minor.yy0.s); }
#line 1141 "vm/parser.c.inc"
        break;
      case 43: /* send ::= send ATTR ID */
#line 93 "vm/parser.lm"
{ yygotominor.yy30.a = S->attr(yymsp[-2].minor.yy30.a, *yymsp[0].minor.yy0.s); }
#line 1146 "vm/parser.c.inc"
        break;
      case 44: /* send ::= send DCOLON ID */
#line 94 "vm/parser.lm"
{ yygotominor.yy30.a = S->dcolon(yymsp[-2].minor.yy30.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1151 "vm/parser.c.inc"
        break;
      case 45: /* send ::= send COLON ID */
#line 95 "vm/parser.lm"
{ yygotominor.yy30.a = S->cast(yymsp[-2].minor.yy30.a, S->named(*yymsp[0].minor.yy0.s)); }
#line 1156 "vm/parser.c.inc"
        break;
      case 46: /* arg_list_start ::= LP */
#line 99 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1161 "vm/parser.c.inc"
        break;
      case 47: /* arg_list_elems ::= arg_list_elems COMMA expr */
      case 48: /* arg_list_elems ::= expr */ yytestcase(yyruleno==48);
#line 100 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy30.a); }
#line 1167 "vm/parser.c.inc"
        break;
      case 52: /* send ::= send DOT DOLLAR sexpr */
#line 108 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect(yymsp[-3].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1172 "vm/parser.c.inc"
        break;
      case 53: /* send ::= send DOT ID LP RP */
#line 110 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s); }
#line 1177 "vm/parser.c.inc"
        break;
      case 54: /* send ::= send DOT ID arg_list RP */
#line 111 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s); }
#line 1182 "vm/parser.c.inc"
        break;
      case 55: /* send ::= ID LP RP */
#line 113 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(S->self(), *yymsp[-2].minor.yy0.s); }
#line 1187 "vm/parser.c.inc"
        break;
      case 56: /* kw_arg ::= ID EQUAL send */
#line 117 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1192 "vm/parser.c.inc"
        break;
      case 60: /* send ::= send DOT ID kw_arg_list RP */
#line 124 "vm/parser.lm"
{
              yygotominor.yy30.a = S->call_kw_args(yymsp[-4].minor.yy30.a, *yymsp[-2].minor.yy0.s);
            }
#line 1199 "vm/parser.c.inc"
        break;
      case 61: /* send ::= ID kw_arg_list RP */
#line 128 "vm/parser.lm"
{
              yygotominor.yy30.a = S->call_kw_args(S->self(), *yymsp[-2].minor.yy0.s);
            }
#line 1206 "vm/parser.c.inc"
        break;
      case 62: /* message_seq ::= message_seq fin ID */
      case 63: /* message_seq ::= ID */ yytestcase(yyruleno==63);
#line 134 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1212 "vm/parser.c.inc"
        break;
      case 64: /* cascade_start ::= send CASCADE */
#line 137 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy30.a); }
#line 1217 "vm/parser.c.inc"
        break;
      case 65: /* cascade ::= cascade_start message_seq RB */
#line 138 "vm/parser.lm"
{ yygotominor.yy30.a = S->end_cascade(); }
#line 1222 "vm/parser.c.inc"
        break;
      case 68: /* lambda_start ::= LB */
#line 146 "vm/parser.lm"
{ S->start_lambda(); }
#line 1227 "vm/parser.c.inc"
        break;
      case 69: /* lambda_args ::= PIPE ID PIPE */
#line 148 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1232 "vm/parser.c.inc"
        break;
      case 71: /* expr ::= lambda_start lambda_args seq RB */
#line 151 "vm/parser.lm"
{ yygotominor.yy30.a = S->lambda(yymsp[-1].minor.yy30.a); }
#line 1237 "vm/parser.c.inc"
        break;
      case 73: /* stmt ::= IF expr fin seq fin END */
#line 159 "vm/parser.lm"
{ yygotominor.yy30.a = S->if_cond(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1242 "vm/parser.c.inc"
        break;
      case 74: /* stmt ::= UNLESS send fin seq fin END */
#line 160 "vm/parser.lm"
{ yygotominor.yy30.a = S->unless(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1247 "vm/parser.c.inc"
        break;
      case 75: /* stmt ::= IMPORT ID */
#line 164 "vm/parser.lm"
{ yygotominor.yy30.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1252 "vm/parser.c.inc"
        break;
      case 76: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 166 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_try(yymsp[-6].minor.yy30.a, yymsp[-2].minor.yy30.a);
            }
#line 1259 "vm/parser.c.inc"
        break;
      case 77: /* stmt ::= ID EQUAL expr */
#line 170 "vm/parser.lm"
{ yygotominor.yy30.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1264 "vm/parser.c.inc"
        break;
      case 78: /* stmt ::= IVAR EQUAL expr */
#line 171 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1269 "vm/parser.c.inc"
        break;
      case 79: /* stmt ::= RAISE expr */
#line 172 "vm/parser.lm"
{ yygotominor.yy30.a = S->raise(yymsp[0].minor.yy30.a); }
#line 1274 "vm/parser.c.inc"
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
      /* (57) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==57);
      /* (58) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==58);
      /* (59) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==59);
      /* (70) lambda_args ::= */ yytestcase(yyruleno==70);
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
#line 1357 "vm/parser.c.inc"
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
