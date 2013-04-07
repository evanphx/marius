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
#define YYNOCODE 82
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy88;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 221
#define YYNRULE 114
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
#define YY_ACTTAB_COUNT (971)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    34,  113,   30,  216,  215,  216,  215,  214,  146,  212,
 /*    10 */    22,   50,   55,  210,   29,   28,   27,  204,  203,  202,
 /*    20 */   201,  200,  105,  197,  136,    5,   78,   77,   21,  188,
 /*    30 */   156,   26,   25,   24,  114,   62,   34,   36,  216,  215,
 /*    40 */    23,  216,  215,  216,  215,  212,  211,   50,  150,  210,
 /*    50 */   216,  215,  138,  204,  203,  202,  201,  200,  105,  197,
 /*    60 */   221,  154,   78,   77,  145,  188,   85,   26,   25,   24,
 /*    70 */   114,   62,   34,  124,    4,   20,   23,  216,  215,  156,
 /*    80 */   117,  212,   20,   50,  116,  210,   20,  132,   75,  204,
 /*    90 */   203,  202,  201,  200,  105,  197,  336,    3,   78,   77,
 /*   100 */   115,  188,   20,   26,   25,   24,  114,   62,   34,  111,
 /*   110 */   129,   20,   23,  216,  215,  128,   48,   20,  162,   50,
 /*   120 */   133,  119,   81,   79,   74,  204,  203,  202,  201,  200,
 /*   130 */   105,  197,  194,  193,   78,   77,  125,  188,   20,   26,
 /*   140 */    25,   24,  114,   62,   34,  121,   73,   20,   23,  216,
 /*   150 */   215,  118,  190,   20,  161,   50,  130,  127,   83,   80,
 /*   160 */   191,  204,  203,  202,  201,  200,  105,  197,  122,  187,
 /*   170 */    78,   77,  183,  188,   20,   26,   25,   24,  114,   62,
 /*   180 */    34,  184,   11,   17,   23,  216,  215,  156,  156,   10,
 /*   190 */   160,   50,   52,  181,  156,   20,  180,  204,  203,  202,
 /*   200 */   201,  200,  105,  197,  178,  174,   78,   77,  177,  188,
 /*   210 */    20,   26,   25,   24,  114,   62,   34,  176,   16,    9,
 /*   220 */    23,  216,  215,  156,  156,   46,   45,   50,  130,  127,
 /*   230 */    83,   80,  173,  204,  203,  202,  201,  200,  105,  197,
 /*   240 */   159,   15,   78,   77,  153,  188,  156,   26,   25,   24,
 /*   250 */   114,   62,   60,    8,   34,  148,   23,   71,  156,  216,
 /*   260 */   215,   72,   58,   76,  158,   50,   19,  123,  113,   88,
 /*   270 */   112,  204,  203,  202,  201,  200,  105,  197,  152,   14,
 /*   280 */    78,   77,  147,  188,  156,   26,   25,   24,  114,   62,
 /*   290 */    34,  134,    7,   86,   23,  216,  215,  156,   13,    6,
 /*   300 */   144,   50,  126,  156,  156,   91,  149,  204,  203,  202,
 /*   310 */   201,  200,  105,  197,   51,  110,   78,   77,  195,  188,
 /*   320 */   337,   26,   25,   24,  114,   62,   34,  192,   12,    1,
 /*   330 */    23,  216,  215,  156,  156,  185,  142,   50,  179,  337,
 /*   340 */   337,  337,  337,  204,  203,  202,  201,  200,  105,  197,
 /*   350 */   337,    2,   78,   77,  337,  188,  156,   26,   25,   24,
 /*   360 */   114,   62,   34,  337,   18,  337,   23,  216,  215,  156,
 /*   370 */   337,  337,   45,   50,  130,  127,   83,   80,  337,  204,
 /*   380 */   203,  202,  201,  200,  105,  197,  337,   34,   78,   77,
 /*   390 */   337,  188,  337,   26,   25,   24,  114,   62,   50,  337,
 /*   400 */   337,  337,   23,  337,  204,  203,  202,  201,  200,  105,
 /*   410 */   197,  337,  282,   78,   77,  337,  188,  337,   26,   25,
 /*   420 */    24,  114,   62,  282,  337,  282,   72,   23,  337,  282,
 /*   430 */   282,  282,  282,  282,  282,  282,  282,   35,  337,   72,
 /*   440 */   337,  282,  282,  282,  282,  282,  282,  282,  282,   33,
 /*   450 */    32,   31,  337,   69,  282,  337,  141,  219,  218,  217,
 /*   460 */   213,  337,  337,  135,  140,  163,   84,  208,  337,   99,
 /*   470 */   207,  206,  337,  182,   69,  337,  175,  141,  219,  218,
 /*   480 */   217,  213,   90,  209,  135,  139,  163,   84,  205,  108,
 /*   490 */    99,  337,  337,  182,  182,  337,  175,  175,  337,  337,
 /*   500 */   337,   49,   90,   90,  141,  219,  218,  217,  137,  337,
 /*   510 */   337,  135,  337,  163,   84,   34,  337,   99,  337,  337,
 /*   520 */   337,  182,  196,   93,  175,  189,   53,   70,  151,   87,
 /*   530 */    90,   90,  204,  203,  202,  201,  200,  198,  197,  337,
 /*   540 */   337,   78,   77,  337,  188,  337,  337,  337,  220,  219,
 /*   550 */   218,  217,  213,  196,  100,  135,  189,  163,   84,  282,
 /*   560 */   337,   99,   90,  337,  337,  182,  337,  337,  175,  337,
 /*   570 */   282,  337,  282,   75,   90,  337,  282,  282,  282,  282,
 /*   580 */   282,  282,  282,  282,  337,  337,   71,  337,  282,  282,
 /*   590 */   282,  282,  282,  282,  282,  282,  109,  337,   42,  337,
 /*   600 */   337,  282,  204,  203,  202,  201,  200,  198,  197,  199,
 /*   610 */   337,   78,   77,   42,  188,  204,  203,  202,  201,  200,
 /*   620 */   198,  197,  337,  337,  131,  337,  337,  188,  337,  337,
 /*   630 */   204,  203,  202,  201,  200,  198,  197,   47,   44,   43,
 /*   640 */    46,   45,  188,  130,  127,   83,   80,   40,   41,   37,
 /*   650 */    39,   38,  337,  120,  119,   82,   79,  337,  155,  213,
 /*   660 */   337,   57,  337,  337,  163,  337,  143,  337,   99,  337,
 /*   670 */   337,  337,  182,  337,  337,  175,  199,  337,  337,  337,
 /*   680 */   337,   90,  204,  203,  202,  201,  200,  198,  197,  155,
 /*   690 */   213,  337,   67,  337,  337,  163,  337,  337,  337,   99,
 /*   700 */   337,  155,  213,  182,   65,  337,  175,  163,  337,  337,
 /*   710 */   337,   99,   90,  155,  213,  182,   63,  337,  175,  163,
 /*   720 */   337,  337,  337,   99,   90,  155,  213,  182,   61,  337,
 /*   730 */   175,  163,  337,  337,  337,   99,   90,  337,  337,  182,
 /*   740 */   155,  213,  175,   59,  337,  337,  163,  337,   90,  337,
 /*   750 */    99,  337,  155,  337,  182,   54,  337,  175,  163,  337,
 /*   760 */   337,  337,   99,   90,  186,  213,  182,  337,  337,  175,
 /*   770 */   163,  337,  337,  337,   99,   90,  337,  337,  182,  337,
 /*   780 */   337,  175,  196,   92,  337,  189,  171,   90,  151,   89,
 /*   790 */    99,   90,  337,  337,  182,  337,  337,  175,  172,  337,
 /*   800 */   337,  337,   99,   90,  337,  337,  182,  196,  103,  175,
 /*   810 */   189,  196,  104,  170,  189,   90,   90,   99,  169,  337,
 /*   820 */    90,  182,   99,  337,  175,  337,  182,  337,  168,  175,
 /*   830 */    90,  337,   99,  167,  337,   90,  182,   99,  166,  175,
 /*   840 */   337,  182,   99,  337,  175,   90,  182,  337,  165,  175,
 /*   850 */    90,  337,   99,  164,  337,   90,  182,   99,  337,  175,
 /*   860 */   337,  182,  337,  337,  175,   90,  337,  337,  337,   68,
 /*   870 */    90,  337,  337,   99,  337,  337,  337,  182,  337,  337,
 /*   880 */   175,   66,  337,  337,  337,   99,   90,  196,  107,  182,
 /*   890 */   189,   64,  175,  157,  337,   99,   90,   99,   90,  182,
 /*   900 */   337,  182,  175,  337,  175,   56,  337,  337,   90,   99,
 /*   910 */    90,  337,  337,  182,  337,  337,  175,  196,  102,  337,
 /*   920 */   189,  337,   90,  337,  196,  101,   90,  189,  196,  106,
 /*   930 */   337,  189,  337,   90,  337,  196,   98,   90,  189,  337,
 /*   940 */   196,   97,  337,  189,   90,  337,  337,  337,  337,   90,
 /*   950 */   337,  196,   96,  337,  189,  337,  196,   95,  337,  189,
 /*   960 */    90,  196,   94,  337,  189,   90,  337,  337,  337,  337,
 /*   970 */    90,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   14,   31,   11,   12,   11,   12,   13,   21,   15,
 /*    10 */    18,   17,   17,   19,   43,   44,   45,   23,   24,   25,
 /*    20 */    26,   27,   28,   29,   51,   52,   32,   33,   58,   35,
 /*    30 */    57,   37,   38,   39,   40,   41,    6,    2,   11,   12,
 /*    40 */    46,   11,   12,   11,   12,   15,   16,   17,   78,   19,
 /*    50 */    11,   12,   13,   23,   24,   25,   26,   27,   28,   29,
 /*    60 */     0,   34,   32,   33,   65,   35,   67,   37,   38,   39,
 /*    70 */    40,   41,    6,   72,   52,   74,   46,   11,   12,   57,
 /*    80 */    72,   15,   74,   17,   72,   19,   74,   17,   20,   23,
 /*    90 */    24,   25,   26,   27,   28,   29,   48,   49,   32,   33,
 /*   100 */    72,   35,   74,   37,   38,   39,   40,   41,    6,   72,
 /*   110 */    17,   74,   46,   11,   12,   72,   31,   74,   16,   17,
 /*   120 */     7,    8,    9,   10,   20,   23,   24,   25,   26,   27,
 /*   130 */    28,   29,   21,   17,   32,   33,   72,   35,   74,   37,
 /*   140 */    38,   39,   40,   41,    6,   72,   20,   74,   46,   11,
 /*   150 */    12,   72,   30,   74,   16,   17,    7,    8,    9,   10,
 /*   160 */    21,   23,   24,   25,   26,   27,   28,   29,   17,   36,
 /*   170 */    32,   33,   72,   35,   74,   37,   38,   39,   40,   41,
 /*   180 */     6,   21,   52,   52,   46,   11,   12,   57,   57,   52,
 /*   190 */    16,   17,   17,   72,   57,   74,   17,   23,   24,   25,
 /*   200 */    26,   27,   28,   29,   21,   21,   32,   33,   72,   35,
 /*   210 */    74,   37,   38,   39,   40,   41,    6,   30,   52,   52,
 /*   220 */    46,   11,   12,   57,   57,    4,    5,   17,    7,    8,
 /*   230 */     9,   10,   34,   23,   24,   25,   26,   27,   28,   29,
 /*   240 */    17,   52,   32,   33,   11,   35,   57,   37,   38,   39,
 /*   250 */    40,   41,   42,   52,    6,   21,   46,   20,   57,   11,
 /*   260 */    12,   20,   68,   20,   16,   17,   80,   36,   14,   58,
 /*   270 */    17,   23,   24,   25,   26,   27,   28,   29,   76,   52,
 /*   280 */    32,   33,   65,   35,   57,   37,   38,   39,   40,   41,
 /*   290 */     6,   17,   52,   58,   46,   11,   12,   57,   52,   52,
 /*   300 */    16,   17,   70,   57,   57,   69,   21,   23,   24,   25,
 /*   310 */    26,   27,   28,   29,   70,   70,   32,   33,   21,   35,
 /*   320 */    81,   37,   38,   39,   40,   41,    6,   21,   52,   52,
 /*   330 */    46,   11,   12,   57,   57,   21,   16,   17,   21,   81,
 /*   340 */    81,   81,   81,   23,   24,   25,   26,   27,   28,   29,
 /*   350 */    81,   52,   32,   33,   81,   35,   57,   37,   38,   39,
 /*   360 */    40,   41,    6,   81,   52,   81,   46,   11,   12,   57,
 /*   370 */    81,   81,    5,   17,    7,    8,    9,   10,   81,   23,
 /*   380 */    24,   25,   26,   27,   28,   29,   81,    6,   32,   33,
 /*   390 */    81,   35,   81,   37,   38,   39,   40,   41,   17,   81,
 /*   400 */    81,   81,   46,   81,   23,   24,   25,   26,   27,   28,
 /*   410 */    29,   81,    6,   32,   33,   81,   35,   81,   37,   38,
 /*   420 */    39,   40,   41,   17,   81,    6,   20,   46,   81,   23,
 /*   430 */    24,   25,   26,   27,   28,   29,   17,   31,   81,   20,
 /*   440 */    81,   35,   23,   24,   25,   26,   27,   28,   29,   43,
 /*   450 */    44,   45,   81,   50,   35,   81,   53,   54,   55,   56,
 /*   460 */    57,   81,   81,   60,   61,   62,   63,    1,   81,   66,
 /*   470 */     4,    5,   81,   70,   50,   81,   73,   53,   54,   55,
 /*   480 */    56,   57,   79,   17,   60,   61,   62,   63,   22,   66,
 /*   490 */    66,   81,   81,   70,   70,   81,   73,   73,   81,   81,
 /*   500 */    81,   50,   79,   79,   53,   54,   55,   56,   57,   81,
 /*   510 */    81,   60,   81,   62,   63,    6,   81,   66,   81,   81,
 /*   520 */    81,   70,   70,   71,   73,   73,   17,   75,   76,   77,
 /*   530 */    79,   79,   23,   24,   25,   26,   27,   28,   29,   81,
 /*   540 */    81,   32,   33,   81,   35,   81,   81,   81,   53,   54,
 /*   550 */    55,   56,   57,   70,   71,   60,   73,   62,   63,    6,
 /*   560 */    81,   66,   79,   81,   81,   70,   81,   81,   73,   81,
 /*   570 */    17,   81,    6,   20,   79,   81,   23,   24,   25,   26,
 /*   580 */    27,   28,   29,   17,   81,   81,   20,   81,   35,   23,
 /*   590 */    24,   25,   26,   27,   28,   29,   17,   81,    6,   81,
 /*   600 */    81,   35,   23,   24,   25,   26,   27,   28,   29,   17,
 /*   610 */    81,   32,   33,    6,   35,   23,   24,   25,   26,   27,
 /*   620 */    28,   29,   81,   81,   17,   81,   81,   35,   81,   81,
 /*   630 */    23,   24,   25,   26,   27,   28,   29,    1,    2,    3,
 /*   640 */     4,    5,   35,    7,    8,    9,   10,    1,    2,    3,
 /*   650 */     4,    5,   81,    7,    8,    9,   10,   81,   56,   57,
 /*   660 */    81,   59,   81,   81,   62,   81,   64,   81,   66,   81,
 /*   670 */    81,   81,   70,   81,   81,   73,   17,   81,   81,   81,
 /*   680 */    81,   79,   23,   24,   25,   26,   27,   28,   29,   56,
 /*   690 */    57,   81,   59,   81,   81,   62,   81,   81,   81,   66,
 /*   700 */    81,   56,   57,   70,   59,   81,   73,   62,   81,   81,
 /*   710 */    81,   66,   79,   56,   57,   70,   59,   81,   73,   62,
 /*   720 */    81,   81,   81,   66,   79,   56,   57,   70,   59,   81,
 /*   730 */    73,   62,   81,   81,   81,   66,   79,   81,   81,   70,
 /*   740 */    56,   57,   73,   59,   81,   81,   62,   81,   79,   81,
 /*   750 */    66,   81,   56,   81,   70,   59,   81,   73,   62,   81,
 /*   760 */    81,   81,   66,   79,   56,   57,   70,   81,   81,   73,
 /*   770 */    62,   81,   81,   81,   66,   79,   81,   81,   70,   81,
 /*   780 */    81,   73,   70,   71,   81,   73,   62,   79,   76,   77,
 /*   790 */    66,   79,   81,   81,   70,   81,   81,   73,   62,   81,
 /*   800 */    81,   81,   66,   79,   81,   81,   70,   70,   71,   73,
 /*   810 */    73,   70,   71,   62,   73,   79,   79,   66,   62,   81,
 /*   820 */    79,   70,   66,   81,   73,   81,   70,   81,   62,   73,
 /*   830 */    79,   81,   66,   62,   81,   79,   70,   66,   62,   73,
 /*   840 */    81,   70,   66,   81,   73,   79,   70,   81,   62,   73,
 /*   850 */    79,   81,   66,   62,   81,   79,   70,   66,   81,   73,
 /*   860 */    81,   70,   81,   81,   73,   79,   81,   81,   81,   62,
 /*   870 */    79,   81,   81,   66,   81,   81,   81,   70,   81,   81,
 /*   880 */    73,   62,   81,   81,   81,   66,   79,   70,   71,   70,
 /*   890 */    73,   62,   73,   62,   81,   66,   79,   66,   79,   70,
 /*   900 */    81,   70,   73,   81,   73,   62,   81,   81,   79,   66,
 /*   910 */    79,   81,   81,   70,   81,   81,   73,   70,   71,   81,
 /*   920 */    73,   81,   79,   81,   70,   71,   79,   73,   70,   71,
 /*   930 */    81,   73,   81,   79,   81,   70,   71,   79,   73,   81,
 /*   940 */    70,   71,   81,   73,   79,   81,   81,   81,   81,   79,
 /*   950 */    81,   70,   71,   81,   73,   81,   70,   71,   81,   73,
 /*   960 */    79,   70,   71,   81,   73,   79,   81,   81,   81,   81,
 /*   970 */    79,
};
#define YY_SHIFT_USE_DFLT (-30)
#define YY_SHIFT_COUNT (136)
#define YY_SHIFT_MIN   (-29)
#define YY_SHIFT_MAX   (659)
static const short yy_shift_ofst[] = {
 /*     0 */   -30,   66,   66,   66,   30,   -6,  320,  356,  356,  356,
 /*    10 */   356,  356,  284,  248,  210,  174,  138,  102,  356,  381,
 /*    20 */   607,  607,  509,  509,  509,  509,  509,  509,  509,  509,
 /*    30 */   509,  509,  509,  509,  509,  509,  579,  592,  592,  592,
 /*    40 */   592,  592,  592,  592,  592,  592,  592,  592,  592,   39,
 /*    50 */   406,  566,  553,  419,   27,   -8,   32,   32,   32,   32,
 /*    60 */    32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
 /*    70 */   254,  317,  314,  306,  297,  285,  274,  -30,  -30,  -30,
 /*    80 */   -30,  659,  659,  659,  466,  -13,  274,  254,  253,  254,
 /*    90 */   231,  243,  636,  636,  636,  636,  636,  636,  636,  646,
 /*   100 */   636,  221,  221,  221,  367,  -29,  149,  149,  113,  241,
 /*   110 */   237,  234,   85,  233,  223,  198,  184,  187,  183,  179,
 /*   120 */   175,  160,  133,  151,  122,  139,  126,  116,  111,  104,
 /*   130 */    93,   85,   68,   70,   35,   -5,   60,
};
#define YY_REDUCE_USE_DFLT (-31)
#define YY_REDUCE_COUNT (91)
#define YY_REDUCE_MIN   (-30)
#define YY_REDUCE_MAX   (891)
static const short yy_reduce_ofst[] = {
 /*     0 */    48,  424,  403,  451,  495,  495,  602,  684,  669,  657,
 /*    10 */   645,  633,  708,  708,  708,  708,  708,  708,  708,  696,
 /*    20 */   452,  712,  843,  831,  829,  819,  807,  791,  786,  776,
 /*    30 */   771,  766,  756,  751,  736,  724,  423,  891,  886,  881,
 /*    40 */   870,  865,  858,  854,  847,  817,  741,  737,  483,  -27,
 /*    50 */   100,  136,  121,  100,  312,  299,  277,  276,  247,  246,
 /*    60 */   240,  227,  201,  189,  167,  166,  137,  131,  130,   22,
 /*    70 */   -30,   79,   73,   64,   43,   37,   -1,   28,   12,    8,
 /*    80 */     1,  245,  244,  232,  236,  235,  217,  211,  202,  211,
 /*    90 */   186,  194,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   229,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    10 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    20 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    30 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    40 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    50 */   263,  299,  295,  263,  335,  335,  335,  335,  335,  335,
 /*    60 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    70 */   288,  282,  282,  282,  282,  282,  335,  282,  282,  282,
 /*    80 */   282,  335,  335,  335,  335,  335,  335,  291,  335,  289,
 /*    90 */   319,  249,  283,  284,  313,  312,  311,  310,  309,  314,
 /*   100 */   285,  271,  270,  267,  268,  264,  279,  269,  246,  263,
 /*   110 */   299,  335,  335,  236,  335,  335,  335,  335,  335,  335,
 /*   120 */   335,  335,  335,  335,  335,  335,  276,  335,  335,  272,
 /*   130 */   335,  263,  295,  335,  245,  335,  335,  230,  231,  242,
 /*   140 */   241,  223,  257,  256,  244,  248,  250,  247,  297,  296,
 /*   150 */   290,  287,  286,  235,  320,  238,  234,  334,  325,  324,
 /*   160 */   323,  322,  321,  316,  333,  332,  331,  330,  329,  328,
 /*   170 */   327,  326,  315,  304,  303,  302,  305,  307,  301,  300,
 /*   180 */   298,  306,  292,  308,  294,  293,  237,  318,  317,  280,
 /*   190 */   281,  278,  277,  275,  274,  273,  266,  265,  264,  263,
 /*   200 */   262,  261,  260,  259,  258,  255,  254,  253,  252,  251,
 /*   210 */   243,  240,  239,  233,  232,  228,  227,  226,  225,  224,
 /*   220 */   222,
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
  "$",             "OP0",           "CAST",          "NEQUAL",      
  "OP1",           "OP2",           "NOT",           "DOT",         
  "DCOLON",        "DOT_DOLLAR",    "LSB",           "NL",          
  "SEMI",          "EOF",           "COMMA",         "CLASS",       
  "END",           "ID",            "LT",            "DEF",         
  "LP",            "RP",            "SQUARE",        "NUM",         
  "NIL",           "TRUE",          "FALSE",         "SELF",        
  "IVAR",          "LITSTR",        "RSB",           "EQUAL",       
  "TUPLE_START",   "DICT_START",    "RB",            "LB",          
  "PIPE",          "IF",            "UNLESS",        "WHILE",       
  "IMPORT",        "TRY",           "RESCUE",        "OP2_SET",     
  "OP1_SET",       "OP0_SET",       "RAISE",         "error",       
  "program",       "opt_fin",       "l1",            "last_fin",    
  "fin",           "l1e",           "class",         "def",         
  "stmt",          "fin_m",         "comma",         "seq",         
  "class_start",   "class_body",    "s2",            "def_start",   
  "def_body",      "arg",           "np_recv",       "id_list",     
  "def_args",      "def_name",      "lit",           "np_arg",      
  "np_arg_list",   "lambda",        "np_arg_list_start",  "np_arg_list_elems",
  "np_kw_arg",     "np_kw_arg_list_elems",  "np_opt_kw_arg_list",  "lambda_start",
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
 /*   6 */ "fin_m ::= NL",
 /*   7 */ "fin_m ::= SEMI",
 /*   8 */ "opt_fin ::=",
 /*   9 */ "opt_fin ::= opt_fin fin_m",
 /*  10 */ "last_fin ::= EOF",
 /*  11 */ "last_fin ::= fin EOF",
 /*  12 */ "fin ::= fin fin_m",
 /*  13 */ "fin ::= fin_m",
 /*  14 */ "comma ::= COMMA NL",
 /*  15 */ "comma ::= COMMA",
 /*  16 */ "seq ::= seq fin stmt",
 /*  17 */ "seq ::= stmt",
 /*  18 */ "class_start ::= CLASS",
 /*  19 */ "class_body ::= l1 fin END",
 /*  20 */ "class ::= class_start ID fin class_body",
 /*  21 */ "class ::= class_start ID LT s2 fin class_body",
 /*  22 */ "def_start ::= DEF",
 /*  23 */ "def_body ::= seq fin END",
 /*  24 */ "arg ::= ID",
 /*  25 */ "arg ::= ID CAST np_recv",
 /*  26 */ "id_list ::= id_list comma arg",
 /*  27 */ "id_list ::= arg",
 /*  28 */ "def_args ::=",
 /*  29 */ "def_args ::= LP id_list RP",
 /*  30 */ "def_name ::= ID",
 /*  31 */ "def_name ::= OP0",
 /*  32 */ "def_name ::= OP1",
 /*  33 */ "def_name ::= OP2",
 /*  34 */ "def_name ::= SQUARE",
 /*  35 */ "def ::= def_start def_name def_args fin def_body",
 /*  36 */ "def ::= def_start def_name def_args fin END",
 /*  37 */ "lit ::= NUM",
 /*  38 */ "lit ::= NIL",
 /*  39 */ "lit ::= TRUE",
 /*  40 */ "lit ::= FALSE",
 /*  41 */ "lit ::= SELF",
 /*  42 */ "lit ::= ID",
 /*  43 */ "lit ::= IVAR",
 /*  44 */ "lit ::= LITSTR",
 /*  45 */ "np_arg ::= lit",
 /*  46 */ "np_arg ::= np_arg OP0 np_arg",
 /*  47 */ "np_arg ::= np_arg OP1 np_arg",
 /*  48 */ "np_arg ::= np_arg OP2 np_arg",
 /*  49 */ "np_arg ::= np_arg CAST np_arg",
 /*  50 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  51 */ "np_arg ::= np_arg DOT ID",
 /*  52 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  53 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  54 */ "np_arg ::= np_arg DCOLON ID",
 /*  55 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  56 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  57 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  58 */ "np_arg ::= NOT np_arg",
 /*  59 */ "np_arg ::= lambda",
 /*  60 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  61 */ "np_arg_list_start ::=",
 /*  62 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  63 */ "np_arg_list_elems ::= np_arg",
 /*  64 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  65 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  66 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  67 */ "np_opt_kw_arg_list ::=",
 /*  68 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  69 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  70 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  71 */ "np_recv ::= lit",
 /*  72 */ "np_recv ::= ID LP RP",
 /*  73 */ "np_recv ::= ID LP np_arg_list RP",
 /*  74 */ "np_recv ::= np_recv DOT ID",
 /*  75 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  76 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  77 */ "np_recv ::= np_recv DCOLON ID",
 /*  78 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  79 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  80 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  81 */ "np_recv ::= lambda",
 /*  82 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  83 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  84 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  85 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  86 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /*  87 */ "s2 ::= ID np_arg_list",
 /*  88 */ "s2 ::= np_recv CAST np_arg",
 /*  89 */ "s2 ::= np_recv OP0 np_arg",
 /*  90 */ "s2 ::= np_recv OP1 np_arg",
 /*  91 */ "s2 ::= np_recv OP2 np_arg",
 /*  92 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  93 */ "s2 ::= np_recv",
 /*  94 */ "s2 ::= NOT s2",
 /*  95 */ "stmt ::= s2",
 /*  96 */ "lambda_start ::= LB",
 /*  97 */ "lambda_args ::= PIPE ID PIPE",
 /*  98 */ "lambda_args ::=",
 /*  99 */ "lambda ::= lambda_start lambda_args seq RB",
 /* 100 */ "stmt ::= IF s2 fin seq fin END",
 /* 101 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 102 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 103 */ "stmt ::= IMPORT ID",
 /* 104 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 105 */ "stmt ::= ID EQUAL s2",
 /* 106 */ "stmt ::= ID OP2_SET s2",
 /* 107 */ "stmt ::= ID OP1_SET s2",
 /* 108 */ "stmt ::= ID OP0_SET s2",
 /* 109 */ "stmt ::= IVAR EQUAL s2",
 /* 110 */ "stmt ::= IVAR OP2_SET s2",
 /* 111 */ "stmt ::= IVAR OP1_SET s2",
 /* 112 */ "stmt ::= IVAR OP0_SET s2",
 /* 113 */ "stmt ::= RAISE s2",
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
  { 48, 3 },
  { 50, 3 },
  { 50, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 57, 1 },
  { 57, 1 },
  { 49, 0 },
  { 49, 2 },
  { 51, 1 },
  { 51, 2 },
  { 52, 2 },
  { 52, 1 },
  { 58, 2 },
  { 58, 1 },
  { 59, 3 },
  { 59, 1 },
  { 60, 1 },
  { 61, 3 },
  { 54, 4 },
  { 54, 6 },
  { 63, 1 },
  { 64, 3 },
  { 65, 1 },
  { 65, 3 },
  { 67, 3 },
  { 67, 1 },
  { 68, 0 },
  { 68, 3 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 55, 5 },
  { 55, 5 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 70, 1 },
  { 71, 1 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 5 },
  { 71, 6 },
  { 71, 3 },
  { 71, 3 },
  { 71, 5 },
  { 71, 6 },
  { 71, 2 },
  { 71, 1 },
  { 71, 4 },
  { 74, 0 },
  { 75, 3 },
  { 75, 1 },
  { 76, 3 },
  { 77, 3 },
  { 77, 1 },
  { 78, 0 },
  { 78, 2 },
  { 72, 3 },
  { 72, 2 },
  { 66, 1 },
  { 66, 3 },
  { 66, 4 },
  { 66, 3 },
  { 66, 5 },
  { 66, 6 },
  { 66, 3 },
  { 66, 3 },
  { 66, 5 },
  { 66, 6 },
  { 66, 1 },
  { 66, 3 },
  { 66, 3 },
  { 66, 4 },
  { 62, 4 },
  { 62, 4 },
  { 62, 2 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 1 },
  { 62, 2 },
  { 56, 1 },
  { 79, 1 },
  { 80, 3 },
  { 80, 0 },
  { 73, 4 },
  { 56, 6 },
  { 56, 6 },
  { 56, 6 },
  { 56, 2 },
  { 56, 9 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 2 },
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
#line 31 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy88.a)); }
#line 1130 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 33 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1136 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 45: /* np_arg ::= lit */ yytestcase(yyruleno==45);
      case 59: /* np_arg ::= lambda */ yytestcase(yyruleno==59);
      case 71: /* np_recv ::= lit */ yytestcase(yyruleno==71);
      case 81: /* np_recv ::= lambda */ yytestcase(yyruleno==81);
      case 93: /* s2 ::= np_recv */ yytestcase(yyruleno==93);
      case 95: /* stmt ::= s2 */ yytestcase(yyruleno==95);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1151 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 58 "vm/parser.lm"
{ S->start_class(); }
#line 1156 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 59 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1162 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 61 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1169 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1176 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 69 "vm/parser.lm"
{ S->start_def(); }
#line 1181 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 72 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1186 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST np_recv */
#line 73 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1191 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= OP2 */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= SQUARE */ yytestcase(yyruleno==34);
#line 81 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1200 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin def_body */
#line 88 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1207 "vm/parser.c.inc"
        break;
      case 36: /* def ::= def_start def_name def_args fin END */
#line 91 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1214 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NUM */
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1219 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= NIL */
#line 96 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1224 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= TRUE */
#line 97 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1229 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= FALSE */
#line 98 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1234 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= SELF */
#line 99 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1239 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= ID */
#line 100 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1244 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= IVAR */
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1249 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= LITSTR */
#line 102 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1254 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg OP0 np_arg */
      case 47: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==47);
      case 89: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==89);
      case 90: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==90);
#line 106 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1262 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP2 np_arg */
      case 91: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==91);
#line 110 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1268 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg CAST np_arg */
      case 88: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==88);
#line 112 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1274 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg NEQUAL np_arg */
      case 92: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==92);
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1280 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT ID */
      case 74: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==74);
#line 115 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1286 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DOT ID LP RP */
      case 75: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==75);
#line 116 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1292 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 76: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==76);
#line 118 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1298 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DCOLON ID */
      case 77: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==77);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1304 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 78: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==78);
#line 121 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1310 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 79: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==79);
#line 123 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1316 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 80: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==80);
#line 125 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1322 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= NOT np_arg */
      case 94: /* s2 ::= NOT s2 */ yytestcase(yyruleno==94);
#line 126 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1328 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 84: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==84);
#line 129 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1334 "vm/parser.c.inc"
        break;
      case 61: /* np_arg_list_start ::= */
#line 131 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1339 "vm/parser.c.inc"
        break;
      case 62: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 63: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==63);
#line 132 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1345 "vm/parser.c.inc"
        break;
      case 64: /* np_kw_arg ::= ID EQUAL np_arg */
#line 135 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1350 "vm/parser.c.inc"
        break;
      case 72: /* np_recv ::= ID LP RP */
#line 147 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1355 "vm/parser.c.inc"
        break;
      case 73: /* np_recv ::= ID LP np_arg_list RP */
#line 148 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1360 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 160 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1365 "vm/parser.c.inc"
        break;
      case 83: /* np_recv ::= DICT_START np_arg_list RB */
#line 161 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1370 "vm/parser.c.inc"
        break;
      case 85: /* s2 ::= np_recv DOT ID np_arg_list */
#line 165 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1375 "vm/parser.c.inc"
        break;
      case 86: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 167 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1380 "vm/parser.c.inc"
        break;
      case 87: /* s2 ::= ID np_arg_list */
#line 168 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1385 "vm/parser.c.inc"
        break;
      case 96: /* lambda_start ::= LB */
#line 182 "vm/parser.lm"
{ S->start_lambda(); }
#line 1390 "vm/parser.c.inc"
        break;
      case 97: /* lambda_args ::= PIPE ID PIPE */
#line 184 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1395 "vm/parser.c.inc"
        break;
      case 99: /* lambda ::= lambda_start lambda_args seq RB */
#line 187 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1400 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= IF s2 fin seq fin END */
#line 191 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1405 "vm/parser.c.inc"
        break;
      case 101: /* stmt ::= UNLESS s2 fin seq fin END */
#line 192 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1410 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= WHILE s2 fin seq fin END */
#line 193 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1415 "vm/parser.c.inc"
        break;
      case 103: /* stmt ::= IMPORT ID */
#line 197 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1420 "vm/parser.c.inc"
        break;
      case 104: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 199 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1427 "vm/parser.c.inc"
        break;
      case 105: /* stmt ::= ID EQUAL s2 */
#line 203 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1432 "vm/parser.c.inc"
        break;
      case 106: /* stmt ::= ID OP2_SET s2 */
      case 107: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==107);
      case 108: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==108);
#line 204 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1439 "vm/parser.c.inc"
        break;
      case 109: /* stmt ::= IVAR EQUAL s2 */
#line 207 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1444 "vm/parser.c.inc"
        break;
      case 110: /* stmt ::= IVAR OP2_SET s2 */
      case 111: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==111);
      case 112: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==112);
#line 209 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1451 "vm/parser.c.inc"
        break;
      case 113: /* stmt ::= RAISE s2 */
#line 214 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1456 "vm/parser.c.inc"
        break;
      default:
      /* (6) fin_m ::= NL */ yytestcase(yyruleno==6);
      /* (7) fin_m ::= SEMI */ yytestcase(yyruleno==7);
      /* (8) opt_fin ::= */ yytestcase(yyruleno==8);
      /* (9) opt_fin ::= opt_fin fin_m */ yytestcase(yyruleno==9);
      /* (10) last_fin ::= EOF */ yytestcase(yyruleno==10);
      /* (11) last_fin ::= fin EOF */ yytestcase(yyruleno==11);
      /* (12) fin ::= fin fin_m */ yytestcase(yyruleno==12);
      /* (13) fin ::= fin_m */ yytestcase(yyruleno==13);
      /* (14) comma ::= COMMA NL */ yytestcase(yyruleno==14);
      /* (15) comma ::= COMMA */ yytestcase(yyruleno==15);
      /* (26) id_list ::= id_list comma arg */ yytestcase(yyruleno==26);
      /* (27) id_list ::= arg */ yytestcase(yyruleno==27);
      /* (28) def_args ::= */ yytestcase(yyruleno==28);
      /* (29) def_args ::= LP id_list RP */ yytestcase(yyruleno==29);
      /* (65) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==65);
      /* (66) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==66);
      /* (67) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==67);
      /* (68) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==68);
      /* (69) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==69);
      /* (70) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==70);
      /* (98) lambda_args ::= */ yytestcase(yyruleno==98);
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
#line 24 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1545 "vm/parser.c.inc"
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
