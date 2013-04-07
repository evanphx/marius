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
#define YY_ACTTAB_COUNT (1001)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    34,  221,  216,  215,  216,  215,  214,   55,  212,   22,
 /*    10 */    50,   45,  210,  110,  127,   80,  204,  203,  202,  201,
 /*    20 */   200,  104,  197,  111,  121,   79,   78,   77,  126,  188,
 /*    30 */    20,   26,   25,   24,  117,   62,  196,  100,   34,  189,
 /*    40 */    23,   36,  216,  215,   75,   90,  212,  211,   50,   30,
 /*    50 */   210,  110,  127,   80,  204,  203,  202,  201,  200,  104,
 /*    60 */   197,   29,   28,   27,   78,   77,  133,  188,  116,   26,
 /*    70 */    25,   24,  117,   62,  131,  146,   34,   52,   23,   81,
 /*    80 */   216,  215,  196,  103,  212,  189,   50,   83,  210,  194,
 /*    90 */    82,   90,  204,  203,  202,  201,  200,  104,  197,   48,
 /*   100 */   136,    5,   78,   77,   74,  188,  156,   26,   25,   24,
 /*   110 */   117,   62,   73,  108,   34,  192,   23,  182,  216,  215,
 /*   120 */   175,  216,  215,  162,   50,  191,   90,  216,  215,  190,
 /*   130 */   204,  203,  202,  201,  200,  104,  197,  216,  215,  138,
 /*   140 */    78,   77,  145,  188,   85,   26,   25,   24,  117,   62,
 /*   150 */   124,  154,   34,  120,   23,   20,  216,  215,  119,  187,
 /*   160 */    20,  161,   50,  118,  114,   20,   20,  184,  204,  203,
 /*   170 */   202,  201,  200,  104,  197,  130,  173,   20,   78,   77,
 /*   180 */   179,  188,  177,   26,   25,   24,  117,   62,  336,    3,
 /*   190 */    34,  128,   23,   20,  216,  215,  123,    4,   20,  160,
 /*   200 */    50,  122,  156,   20,  159,  176,  204,  203,  202,  201,
 /*   210 */   200,  104,  197,   11,   21,   17,   78,   77,  156,  188,
 /*   220 */   156,   26,   25,   24,  117,   62,   10,  183,   34,   20,
 /*   230 */    23,  156,  216,  215,  150,  153,  174,   16,   50,  181,
 /*   240 */   148,   20,  156,   71,  204,  203,  202,  201,  200,  104,
 /*   250 */   197,    9,   72,   15,   78,   77,  156,  188,  156,   26,
 /*   260 */    25,   24,  117,   62,   60,   58,   34,    8,   23,   14,
 /*   270 */   216,  215,  156,    7,  156,  158,   50,  125,  156,  178,
 /*   280 */    76,   20,  204,  203,  202,  201,  200,  104,  197,   19,
 /*   290 */    88,   13,   78,   77,  116,  188,  156,   26,   25,   24,
 /*   300 */   117,   62,    6,  152,   34,  115,   23,  156,  216,  215,
 /*   310 */    12,    1,  147,  144,   50,  156,  156,  134,   91,  149,
 /*   320 */   204,  203,  202,  201,  200,  104,  197,    2,   86,   18,
 /*   330 */    78,   77,  156,  188,  156,   26,   25,   24,  117,   62,
 /*   340 */   195,  129,   34,   51,   23,  193,  216,  215,  113,  185,
 /*   350 */   180,  142,   50,  337,  337,  337,  337,  337,  204,  203,
 /*   360 */   202,  201,  200,  104,  197,  337,  337,  337,   78,   77,
 /*   370 */   337,  188,  337,   26,   25,   24,  117,   62,  337,  337,
 /*   380 */    34,  337,   23,  337,  216,  215,  337,  337,  337,  337,
 /*   390 */    50,  337,  337,  337,  337,  337,  204,  203,  202,  201,
 /*   400 */   200,  104,  197,  337,  337,  337,   78,   77,   34,  188,
 /*   410 */   337,   26,   25,   24,  117,   62,  337,  337,   50,  337,
 /*   420 */    23,  337,  337,  337,  204,  203,  202,  201,  200,  104,
 /*   430 */   197,  337,  337,  337,   78,   77,  282,  188,  337,   26,
 /*   440 */    25,   24,  117,   62,  337,  337,  282,  337,   23,   72,
 /*   450 */   337,  337,  282,  282,  282,  282,  282,  282,  282,  337,
 /*   460 */   199,   35,  337,  337,  337,  282,  204,  203,  202,  201,
 /*   470 */   200,  198,  197,   33,   32,   31,   69,  337,  337,  141,
 /*   480 */   219,  218,  217,  213,  337,  337,  135,  140,  163,   84,
 /*   490 */   337,  208,   99,  337,  207,  206,  182,   69,  337,  175,
 /*   500 */   141,  219,  218,  217,  213,   90,  209,  135,  139,  163,
 /*   510 */    84,  205,  337,   99,  337,  337,  337,  182,   46,   45,
 /*   520 */   175,  110,  127,   80,   49,  337,   90,  141,  219,  218,
 /*   530 */   217,  137,  337,  337,  135,  171,  163,   84,   34,   99,
 /*   540 */    99,  337,  337,  182,  182,  337,  175,  175,   53,  337,
 /*   550 */   337,  337,   90,   90,  204,  203,  202,  201,  200,  198,
 /*   560 */   197,  337,  337,  337,   78,   77,  337,  188,  337,  337,
 /*   570 */   337,  220,  219,  218,  217,  213,  196,  105,  135,  189,
 /*   580 */   163,   84,  282,  337,   99,   90,  337,  337,  182,  337,
 /*   590 */   337,  175,  282,  337,  337,   72,  337,   90,  282,  282,
 /*   600 */   282,  282,  282,  282,  282,  282,   47,   44,   43,   46,
 /*   610 */    45,  282,  110,  127,   80,  282,  337,  337,   75,  337,
 /*   620 */   337,  282,  282,  282,  282,  282,  282,  282,  282,   40,
 /*   630 */    41,   37,   39,   38,  282,  109,  121,   79,  282,  337,
 /*   640 */   337,   71,  337,  337,  282,  282,  282,  282,  282,  282,
 /*   650 */   282,  196,  107,  337,  189,  112,  337,  282,  337,  337,
 /*   660 */    90,  204,  203,  202,  201,  200,  198,  197,   42,  337,
 /*   670 */   337,   78,   77,  337,  188,  337,  337,  337,  199,  337,
 /*   680 */   337,  337,  337,  337,  204,  203,  202,  201,  200,  198,
 /*   690 */   197,   42,  337,  196,   93,  337,  189,  188,   70,  151,
 /*   700 */    87,  132,   90,  337,  337,  337,  337,  204,  203,  202,
 /*   710 */   201,  200,  198,  197,  337,  337,  196,  102,  337,  189,
 /*   720 */   188,  155,  213,  337,   57,   90,  337,  163,  337,  143,
 /*   730 */   337,   99,  337,  337,  337,  182,  337,  337,  175,  337,
 /*   740 */   337,  337,  155,  213,   90,   67,  337,  337,  163,  337,
 /*   750 */   337,  337,   99,  337,  155,  213,  182,   65,  337,  175,
 /*   760 */   163,  337,  337,  337,   99,   90,  155,  213,  182,   63,
 /*   770 */   337,  175,  163,  337,  337,  337,   99,   90,  155,  213,
 /*   780 */   182,   61,  337,  175,  163,  337,  337,  337,   99,   90,
 /*   790 */   337,  337,  182,  337,  337,  175,  337,  337,  337,  155,
 /*   800 */   213,   90,   59,  337,  337,  163,  337,  337,  337,   99,
 /*   810 */   337,  155,  337,  182,   54,  337,  175,  163,  337,  337,
 /*   820 */   337,   99,   90,  186,  213,  182,  337,  337,  175,  163,
 /*   830 */   337,  337,  337,   99,   90,  196,   92,  182,  189,  172,
 /*   840 */   175,  151,   89,   99,   90,  337,   90,  182,  337,  337,
 /*   850 */   175,  170,  337,  337,  337,   99,   90,  337,  337,  182,
 /*   860 */   337,  337,  175,  169,  337,  168,  337,   99,   90,   99,
 /*   870 */   337,  182,  337,  182,  175,  337,  175,  167,  337,  166,
 /*   880 */    90,   99,   90,   99,  337,  182,  337,  182,  175,  337,
 /*   890 */   175,  165,  337,  337,   90,   99,   90,  337,  337,  182,
 /*   900 */   337,  164,  175,   68,  337,   99,  337,   99,   90,  182,
 /*   910 */   337,  182,  175,   66,  175,  337,  337,   99,   90,  337,
 /*   920 */    90,  182,  337,  337,  175,   64,  337,  337,  337,   99,
 /*   930 */    90,  337,  337,  182,  337,  337,  175,  157,  337,   56,
 /*   940 */   337,   99,   90,   99,  337,  182,  337,  182,  175,  337,
 /*   950 */   175,  337,  196,  101,   90,  189,   90,  337,  337,  196,
 /*   960 */   106,   90,  189,  337,  337,  337,  196,   98,   90,  189,
 /*   970 */   196,   97,  337,  189,  337,   90,  337,  337,  337,   90,
 /*   980 */   196,   96,  337,  189,  196,   95,  337,  189,  337,   90,
 /*   990 */   337,  196,   94,   90,  189,  337,  337,  337,  337,  337,
 /*  1000 */    90,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    0,   10,   11,   10,   11,   12,   16,   14,   17,
 /*    10 */    16,    5,   18,    7,    8,    9,   22,   23,   24,   25,
 /*    20 */    26,   27,   28,    7,    8,    9,   32,   33,   72,   35,
 /*    30 */    74,   37,   38,   39,   40,   41,   70,   71,    6,   73,
 /*    40 */    46,    2,   10,   11,   19,   79,   14,   15,   16,   31,
 /*    50 */    18,    7,    8,    9,   22,   23,   24,   25,   26,   27,
 /*    60 */    28,   43,   44,   45,   32,   33,   16,   35,   13,   37,
 /*    70 */    38,   39,   40,   41,   16,   20,    6,   16,   46,   29,
 /*    80 */    10,   11,   70,   71,   14,   73,   16,   29,   18,   20,
 /*    90 */    29,   79,   22,   23,   24,   25,   26,   27,   28,   31,
 /*   100 */    51,   52,   32,   33,   19,   35,   57,   37,   38,   39,
 /*   110 */    40,   41,   19,   66,    6,   20,   46,   70,   10,   11,
 /*   120 */    73,   10,   11,   15,   16,   16,   79,   10,   11,   30,
 /*   130 */    22,   23,   24,   25,   26,   27,   28,   10,   11,   12,
 /*   140 */    32,   33,   65,   35,   67,   37,   38,   39,   40,   41,
 /*   150 */    16,   34,    6,   72,   46,   74,   10,   11,   72,   36,
 /*   160 */    74,   15,   16,   72,   72,   74,   74,   20,   22,   23,
 /*   170 */    24,   25,   26,   27,   28,   72,   34,   74,   32,   33,
 /*   180 */    20,   35,   16,   37,   38,   39,   40,   41,   48,   49,
 /*   190 */     6,   72,   46,   74,   10,   11,   72,   52,   74,   15,
 /*   200 */    16,   72,   57,   74,   16,   30,   22,   23,   24,   25,
 /*   210 */    26,   27,   28,   52,   58,   52,   32,   33,   57,   35,
 /*   220 */    57,   37,   38,   39,   40,   41,   52,   72,    6,   74,
 /*   230 */    46,   57,   10,   11,   78,   10,   20,   52,   16,   72,
 /*   240 */    20,   74,   57,   19,   22,   23,   24,   25,   26,   27,
 /*   250 */    28,   52,   19,   52,   32,   33,   57,   35,   57,   37,
 /*   260 */    38,   39,   40,   41,   42,   68,    6,   52,   46,   52,
 /*   270 */    10,   11,   57,   52,   57,   15,   16,   36,   57,   72,
 /*   280 */    19,   74,   22,   23,   24,   25,   26,   27,   28,   80,
 /*   290 */    58,   52,   32,   33,   13,   35,   57,   37,   38,   39,
 /*   300 */    40,   41,   52,   76,    6,   16,   46,   57,   10,   11,
 /*   310 */    52,   52,   65,   15,   16,   57,   57,   16,   69,   20,
 /*   320 */    22,   23,   24,   25,   26,   27,   28,   52,   58,   52,
 /*   330 */    32,   33,   57,   35,   57,   37,   38,   39,   40,   41,
 /*   340 */    20,   70,    6,   70,   46,   20,   10,   11,   70,   20,
 /*   350 */    20,   15,   16,   81,   81,   81,   81,   81,   22,   23,
 /*   360 */    24,   25,   26,   27,   28,   81,   81,   81,   32,   33,
 /*   370 */    81,   35,   81,   37,   38,   39,   40,   41,   81,   81,
 /*   380 */     6,   81,   46,   81,   10,   11,   81,   81,   81,   81,
 /*   390 */    16,   81,   81,   81,   81,   81,   22,   23,   24,   25,
 /*   400 */    26,   27,   28,   81,   81,   81,   32,   33,    6,   35,
 /*   410 */    81,   37,   38,   39,   40,   41,   81,   81,   16,   81,
 /*   420 */    46,   81,   81,   81,   22,   23,   24,   25,   26,   27,
 /*   430 */    28,   81,   81,   81,   32,   33,    6,   35,   81,   37,
 /*   440 */    38,   39,   40,   41,   81,   81,   16,   81,   46,   19,
 /*   450 */    81,   81,   22,   23,   24,   25,   26,   27,   28,   81,
 /*   460 */    16,   31,   81,   81,   81,   35,   22,   23,   24,   25,
 /*   470 */    26,   27,   28,   43,   44,   45,   50,   81,   81,   53,
 /*   480 */    54,   55,   56,   57,   81,   81,   60,   61,   62,   63,
 /*   490 */    81,    1,   66,   81,    4,    5,   70,   50,   81,   73,
 /*   500 */    53,   54,   55,   56,   57,   79,   16,   60,   61,   62,
 /*   510 */    63,   21,   81,   66,   81,   81,   81,   70,    4,    5,
 /*   520 */    73,    7,    8,    9,   50,   81,   79,   53,   54,   55,
 /*   530 */    56,   57,   81,   81,   60,   62,   62,   63,    6,   66,
 /*   540 */    66,   81,   81,   70,   70,   81,   73,   73,   16,   81,
 /*   550 */    81,   81,   79,   79,   22,   23,   24,   25,   26,   27,
 /*   560 */    28,   81,   81,   81,   32,   33,   81,   35,   81,   81,
 /*   570 */    81,   53,   54,   55,   56,   57,   70,   71,   60,   73,
 /*   580 */    62,   63,    6,   81,   66,   79,   81,   81,   70,   81,
 /*   590 */    81,   73,   16,   81,   81,   19,   81,   79,   22,   23,
 /*   600 */    24,   25,   26,   27,   28,    6,    1,    2,    3,    4,
 /*   610 */     5,   35,    7,    8,    9,   16,   81,   81,   19,   81,
 /*   620 */    81,   22,   23,   24,   25,   26,   27,   28,    6,    1,
 /*   630 */     2,    3,    4,    5,   35,    7,    8,    9,   16,   81,
 /*   640 */    81,   19,   81,   81,   22,   23,   24,   25,   26,   27,
 /*   650 */    28,   70,   71,   81,   73,   16,   81,   35,   81,   81,
 /*   660 */    79,   22,   23,   24,   25,   26,   27,   28,    6,   81,
 /*   670 */    81,   32,   33,   81,   35,   81,   81,   81,   16,   81,
 /*   680 */    81,   81,   81,   81,   22,   23,   24,   25,   26,   27,
 /*   690 */    28,    6,   81,   70,   71,   81,   73,   35,   75,   76,
 /*   700 */    77,   16,   79,   81,   81,   81,   81,   22,   23,   24,
 /*   710 */    25,   26,   27,   28,   81,   81,   70,   71,   81,   73,
 /*   720 */    35,   56,   57,   81,   59,   79,   81,   62,   81,   64,
 /*   730 */    81,   66,   81,   81,   81,   70,   81,   81,   73,   81,
 /*   740 */    81,   81,   56,   57,   79,   59,   81,   81,   62,   81,
 /*   750 */    81,   81,   66,   81,   56,   57,   70,   59,   81,   73,
 /*   760 */    62,   81,   81,   81,   66,   79,   56,   57,   70,   59,
 /*   770 */    81,   73,   62,   81,   81,   81,   66,   79,   56,   57,
 /*   780 */    70,   59,   81,   73,   62,   81,   81,   81,   66,   79,
 /*   790 */    81,   81,   70,   81,   81,   73,   81,   81,   81,   56,
 /*   800 */    57,   79,   59,   81,   81,   62,   81,   81,   81,   66,
 /*   810 */    81,   56,   81,   70,   59,   81,   73,   62,   81,   81,
 /*   820 */    81,   66,   79,   56,   57,   70,   81,   81,   73,   62,
 /*   830 */    81,   81,   81,   66,   79,   70,   71,   70,   73,   62,
 /*   840 */    73,   76,   77,   66,   79,   81,   79,   70,   81,   81,
 /*   850 */    73,   62,   81,   81,   81,   66,   79,   81,   81,   70,
 /*   860 */    81,   81,   73,   62,   81,   62,   81,   66,   79,   66,
 /*   870 */    81,   70,   81,   70,   73,   81,   73,   62,   81,   62,
 /*   880 */    79,   66,   79,   66,   81,   70,   81,   70,   73,   81,
 /*   890 */    73,   62,   81,   81,   79,   66,   79,   81,   81,   70,
 /*   900 */    81,   62,   73,   62,   81,   66,   81,   66,   79,   70,
 /*   910 */    81,   70,   73,   62,   73,   81,   81,   66,   79,   81,
 /*   920 */    79,   70,   81,   81,   73,   62,   81,   81,   81,   66,
 /*   930 */    79,   81,   81,   70,   81,   81,   73,   62,   81,   62,
 /*   940 */    81,   66,   79,   66,   81,   70,   81,   70,   73,   81,
 /*   950 */    73,   81,   70,   71,   79,   73,   79,   81,   81,   70,
 /*   960 */    71,   79,   73,   81,   81,   81,   70,   71,   79,   73,
 /*   970 */    70,   71,   81,   73,   81,   79,   81,   81,   81,   79,
 /*   980 */    70,   71,   81,   73,   70,   71,   81,   73,   81,   79,
 /*   990 */    81,   70,   71,   79,   73,   81,   81,   81,   81,   81,
 /*  1000 */    79,
};
#define YY_SHIFT_USE_DFLT (-10)
#define YY_SHIFT_COUNT (136)
#define YY_SHIFT_MIN   (-9)
#define YY_SHIFT_MAX   (685)
static const short yy_shift_ofst[] = {
 /*     0 */   -10,   70,   70,   70,   32,   -6,  336,  374,  374,  374,
 /*    10 */   374,  374,  298,  260,  222,  184,  146,  108,  374,  402,
 /*    20 */   685,  685,  532,  532,  532,  532,  532,  532,  532,  532,
 /*    30 */   532,  532,  532,  532,  532,  532,  639,  662,  662,  662,
 /*    40 */   662,  662,  662,  662,  662,  662,  662,  662,  662,  127,
 /*    50 */   430,  622,  599,  576,  117,   -8,  111,  111,  111,  111,
 /*    60 */   111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
 /*    70 */   281,  330,  329,  325,  320,  299,  301,  -10,  -10,  -10,
 /*    80 */   -10,  444,  444,  444,  490,   55,  301,  281,  289,  281,
 /*    90 */   241,  261,  605,  605,  605,  605,  605,  605,  605,  628,
 /*   100 */   605,  514,  514,  514,   18,    6,   44,   44,   16,   61,
 /*   110 */    58,   50,  233,  224,  220,   68,  225,  188,  142,  216,
 /*   120 */   175,  166,  160,  147,  123,  134,   99,  109,   95,   93,
 /*   130 */    69,   85,   68,   25,   39,   -9,    1,
};
#define YY_REDUCE_USE_DFLT (-45)
#define YY_REDUCE_COUNT (91)
#define YY_REDUCE_MIN   (-44)
#define YY_REDUCE_MAX   (921)
static const short yy_reduce_ofst[] = {
 /*     0 */   140,  447,  426,  474,  518,  518,  665,  743,  722,  710,
 /*    10 */   698,  686,  767,  767,  767,  767,  767,  767,  767,  755,
 /*    20 */   623,  765,  877,  875,  863,  851,  841,  839,  829,  817,
 /*    30 */   815,  803,  801,  789,  777,  473,   47,  921,  914,  910,
 /*    40 */   900,  896,  889,  882,  646,  581,  506,   12,  -34,   49,
 /*    50 */   155,  207,  167,  155,  277,  275,  259,  258,  250,  239,
 /*    60 */   221,  217,  215,  201,  199,  185,  174,  163,  161,  145,
 /*    70 */   156,  129,  124,  119,  103,   92,   77,   91,   86,   81,
 /*    80 */   -44,  278,  273,  271,  249,  270,  247,  232,  227,  232,
 /*    90 */   209,  197,
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
 /*   100 */   285,  271,  270,  267,  264,  268,  279,  269,  246,  335,
 /*   110 */   335,  335,  263,  299,  335,  335,  236,  335,  335,  335,
 /*   120 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  276,
 /*   130 */   335,  272,  263,  295,  245,  335,  335,  230,  231,  242,
 /*   140 */   241,  223,  257,  256,  244,  248,  250,  247,  297,  296,
 /*   150 */   290,  287,  286,  235,  320,  238,  234,  334,  325,  324,
 /*   160 */   323,  322,  321,  316,  333,  332,  331,  330,  329,  328,
 /*   170 */   327,  326,  315,  304,  303,  302,  305,  298,  307,  301,
 /*   180 */   300,  306,  292,  308,  294,  293,  237,  318,  317,  280,
 /*   190 */   281,  275,  278,  277,  274,  273,  266,  265,  264,  263,
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
  "DCOLON",        "LSB",           "NL",            "SEMI",        
  "EOF",           "COMMA",         "CLASS",         "END",         
  "ID",            "LT",            "DEF",           "LP",          
  "RP",            "SQUARE",        "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "LITSTR",        "DOLLAR",        "RSB",           "EQUAL",       
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
 /*  55 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  56 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  57 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
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
 /*  78 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  79 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  80 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  81 */ "np_recv ::= lambda",
 /*  82 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  83 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  84 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  85 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  86 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
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
  { 71, 4 },
  { 71, 6 },
  { 71, 7 },
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
  { 66, 4 },
  { 66, 6 },
  { 66, 7 },
  { 66, 1 },
  { 66, 3 },
  { 66, 3 },
  { 66, 4 },
  { 62, 4 },
  { 62, 5 },
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
#line 1136 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 33 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1142 "vm/parser.c.inc"
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
#line 1157 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 58 "vm/parser.lm"
{ S->start_class(); }
#line 1162 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 59 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1168 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 61 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1175 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1182 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 69 "vm/parser.lm"
{ S->start_def(); }
#line 1187 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 72 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1192 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST np_recv */
#line 73 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1197 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= OP2 */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= SQUARE */ yytestcase(yyruleno==34);
#line 81 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1206 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin def_body */
#line 88 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1213 "vm/parser.c.inc"
        break;
      case 36: /* def ::= def_start def_name def_args fin END */
#line 91 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1220 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NUM */
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1225 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= NIL */
#line 96 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1230 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= TRUE */
#line 97 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1235 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= FALSE */
#line 98 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1240 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= SELF */
#line 99 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1245 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= ID */
#line 100 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1250 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= IVAR */
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1255 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= LITSTR */
#line 102 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1260 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg OP0 np_arg */
      case 47: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==47);
      case 89: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==89);
      case 90: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==90);
#line 106 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1268 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP2 np_arg */
      case 91: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==91);
#line 110 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1274 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg CAST np_arg */
      case 88: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==88);
#line 112 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1280 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg NEQUAL np_arg */
      case 92: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==92);
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1286 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT ID */
      case 74: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==74);
#line 115 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1292 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DOT ID LP RP */
      case 75: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==75);
#line 116 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1298 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 76: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==76);
#line 118 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1304 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DCOLON ID */
      case 77: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==77);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1310 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 78: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==78);
#line 121 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-3].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1316 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 79: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==79);
#line 123 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-5].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1322 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 80: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==80);
#line 125 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-6].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1328 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= NOT np_arg */
      case 94: /* s2 ::= NOT s2 */ yytestcase(yyruleno==94);
#line 126 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1334 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 84: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==84);
#line 129 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1340 "vm/parser.c.inc"
        break;
      case 61: /* np_arg_list_start ::= */
#line 131 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1345 "vm/parser.c.inc"
        break;
      case 62: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 63: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==63);
#line 132 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1351 "vm/parser.c.inc"
        break;
      case 64: /* np_kw_arg ::= ID EQUAL np_arg */
#line 135 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1356 "vm/parser.c.inc"
        break;
      case 72: /* np_recv ::= ID LP RP */
#line 147 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1361 "vm/parser.c.inc"
        break;
      case 73: /* np_recv ::= ID LP np_arg_list RP */
#line 148 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1366 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 160 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1371 "vm/parser.c.inc"
        break;
      case 83: /* np_recv ::= DICT_START np_arg_list RB */
#line 161 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1376 "vm/parser.c.inc"
        break;
      case 85: /* s2 ::= np_recv DOT ID np_arg_list */
#line 165 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1381 "vm/parser.c.inc"
        break;
      case 86: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 167 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1386 "vm/parser.c.inc"
        break;
      case 87: /* s2 ::= ID np_arg_list */
#line 168 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1391 "vm/parser.c.inc"
        break;
      case 96: /* lambda_start ::= LB */
#line 182 "vm/parser.lm"
{ S->start_lambda(); }
#line 1396 "vm/parser.c.inc"
        break;
      case 97: /* lambda_args ::= PIPE ID PIPE */
#line 184 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1401 "vm/parser.c.inc"
        break;
      case 99: /* lambda ::= lambda_start lambda_args seq RB */
#line 187 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1406 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= IF s2 fin seq fin END */
#line 191 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1411 "vm/parser.c.inc"
        break;
      case 101: /* stmt ::= UNLESS s2 fin seq fin END */
#line 192 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1416 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= WHILE s2 fin seq fin END */
#line 193 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1421 "vm/parser.c.inc"
        break;
      case 103: /* stmt ::= IMPORT ID */
#line 197 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1426 "vm/parser.c.inc"
        break;
      case 104: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 199 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1433 "vm/parser.c.inc"
        break;
      case 105: /* stmt ::= ID EQUAL s2 */
#line 203 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1438 "vm/parser.c.inc"
        break;
      case 106: /* stmt ::= ID OP2_SET s2 */
      case 107: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==107);
      case 108: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==108);
#line 204 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1445 "vm/parser.c.inc"
        break;
      case 109: /* stmt ::= IVAR EQUAL s2 */
#line 207 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1450 "vm/parser.c.inc"
        break;
      case 110: /* stmt ::= IVAR OP2_SET s2 */
      case 111: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==111);
      case 112: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==112);
#line 209 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1457 "vm/parser.c.inc"
        break;
      case 113: /* stmt ::= RAISE s2 */
#line 214 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1462 "vm/parser.c.inc"
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
#line 1551 "vm/parser.c.inc"
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
