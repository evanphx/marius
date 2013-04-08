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
#define YYNSTATE 239
#define YYNRULE 120
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
#define YY_ACTTAB_COUNT (1057)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    38,  214,  106,  239,  207,  234,  233,  232,   21,  230,
 /*    10 */    96,   56,   61,  228,   39,  360,    3,  222,  221,  220,
 /*    20 */   219,  218,  111,  215,  148,    5,   84,   83,  162,  206,
 /*    30 */   170,   28,   27,   26,  122,   68,   38,  119,  234,  233,
 /*    40 */    25,  234,  233,    4,  158,  230,  229,   56,  170,  228,
 /*    50 */    39,  234,  233,  222,  221,  220,  219,  218,  111,  215,
 /*    60 */    42,  168,   84,   83,  136,  206,   20,   28,   27,   26,
 /*    70 */   122,   68,   38,  234,  233,  150,   25,  234,  233,   81,
 /*    80 */   129,  230,   20,   56,  144,  228,   39,  141,   54,  222,
 /*    90 */   221,  220,  219,  218,  111,  215,   80,  211,   84,   83,
 /*   100 */   128,  206,   20,   28,   27,   26,  122,   68,   38,  212,
 /*   110 */   234,  233,   25,  234,  233,   11,   79,   22,  176,   56,
 /*   120 */   170,  157,   39,   91,  209,  222,  221,  220,  219,  218,
 /*   130 */   111,  215,  202,  205,   84,   83,  127,  206,   20,   28,
 /*   140 */    27,   26,  122,   68,   38,  117,  208,   20,   25,  234,
 /*   150 */   233,  140,  134,   20,  175,   56,   58,  198,   39,  194,
 /*   160 */   191,  222,  221,  220,  219,  218,  111,  215,  196,  192,
 /*   170 */    84,   83,  137,  206,   20,   28,   27,   26,  122,   68,
 /*   180 */    38,  133,  190,   20,   25,  234,  233,  130,   17,   20,
 /*   190 */   174,   56,  188,  170,   39,  173,  187,  222,  221,  220,
 /*   200 */   219,  218,  111,  215,  186,  167,   84,   83,  166,  206,
 /*   210 */   165,   28,   27,   26,  122,   68,   38,  201,  160,   20,
 /*   220 */    25,  234,  233,  145,  131,   87,   85,   56,   77,   78,
 /*   230 */    39,   64,   82,  222,  221,  220,  219,  218,  111,  215,
 /*   240 */    19,   10,   84,   83,   94,  206,  170,   28,   27,   26,
 /*   250 */   122,   68,   66,   16,   38,  135,   25,  119,  170,  234,
 /*   260 */   233,  164,  118,  159,  172,   56,  146,  199,   39,   20,
 /*   270 */   138,  222,  221,  220,  219,  218,  111,  215,   92,    9,
 /*   280 */    84,   83,   97,  206,  170,   28,   27,   26,  122,   68,
 /*   290 */    38,   57,   15,  116,   25,  234,  233,  170,    8,  161,
 /*   300 */   156,   56,  213,  170,   39,  361,  210,  222,  221,  220,
 /*   310 */   219,  218,  111,  215,  203,  197,   84,   83,  361,  206,
 /*   320 */   361,   28,   27,   26,  122,   68,   38,  361,   14,    7,
 /*   330 */    25,  234,  233,  170,  170,  361,  154,   56,  361,  361,
 /*   340 */    39,  361,  361,  222,  221,  220,  219,  218,  111,  215,
 /*   350 */   361,   13,   84,   83,  361,  206,  170,   28,   27,   26,
 /*   360 */   122,   68,   38,  195,  361,   20,   25,  234,  233,  142,
 /*   370 */   139,   89,   86,   56,  361,  361,   39,  361,  361,  222,
 /*   380 */   221,  220,  219,  218,  111,  215,  361,   38,   84,   83,
 /*   390 */   361,  206,  361,   28,   27,   26,  122,   68,   56,  361,
 /*   400 */   361,   39,   25,  361,  222,  221,  220,  219,  218,  111,
 /*   410 */   215,  361,  302,   84,   83,  361,  206,  361,   28,   27,
 /*   420 */    26,  122,   68,  302,  361,  302,   78,   25,  361,  302,
 /*   430 */   302,  302,  302,  302,  302,  302,  302,   41,  361,   78,
 /*   440 */   361,  302,  302,  302,  302,  302,  302,  302,  302,   35,
 /*   450 */    34,   33,   75,  361,  302,  153,  237,  236,  235,  231,
 /*   460 */   361,    6,  147,  152,  177,   90,  170,  361,  105,   12,
 /*   470 */   361,  361,  200,   75,  170,  193,  153,  237,  236,  235,
 /*   480 */   231,   96,  361,  147,  151,  177,   90,   38,  361,  105,
 /*   490 */     1,  214,  109,  200,  207,  170,  193,  361,   59,  361,
 /*   500 */    96,   39,   96,  361,  222,  221,  220,  219,  218,  216,
 /*   510 */   215,  361,    2,   84,   83,   55,  206,  170,  153,  237,
 /*   520 */   236,  235,  149,  214,   98,  147,  207,  177,   90,  163,
 /*   530 */    95,  105,   96,  361,  361,  200,   18,  361,  193,  115,
 /*   540 */   361,  170,   39,  361,   96,  222,  221,  220,  219,  218,
 /*   550 */   216,  215,  361,  361,   84,   83,  361,  206,  238,  237,
 /*   560 */   236,  235,  231,  214,  108,  147,  207,  177,   90,  302,
 /*   570 */   361,  105,   96,  361,  361,  200,  214,  107,  193,  207,
 /*   580 */   302,  361,  302,   81,   96,   96,  302,  302,  302,  302,
 /*   590 */   302,  302,  302,  302,  361,   50,   77,  361,  302,  302,
 /*   600 */   302,  302,  302,  302,  302,  302,  217,  361,   50,   23,
 /*   610 */   361,  302,  222,  221,  220,  219,  218,  216,  215,  217,
 /*   620 */   361,   50,   24,  361,  206,  222,  221,  220,  219,  218,
 /*   630 */   216,  215,  217,  361,   50,   40,  361,  206,  222,  221,
 /*   640 */   220,  219,  218,  216,  215,  217,  361,   50,   37,  361,
 /*   650 */   206,  222,  221,  220,  219,  218,  216,  215,  217,  361,
 /*   660 */    50,   36,  361,  206,  222,  221,  220,  219,  218,  216,
 /*   670 */   215,  217,  361,   50,   32,  361,  206,  222,  221,  220,
 /*   680 */   219,  218,  216,  215,  143,  361,   31,   30,   29,  206,
 /*   690 */   222,  221,  220,  219,  218,  216,  215,   53,   52,   51,
 /*   700 */    47,   46,  206,  142,  139,   89,   86,   45,   49,   48,
 /*   710 */    44,   43,  361,  132,  131,   88,   85,  169,  231,  361,
 /*   720 */    63,  214,  112,  177,  207,  155,  361,  105,  361,  361,
 /*   730 */    96,  200,  361,  361,  193,  217,  361,  361,  361,  361,
 /*   740 */    96,  222,  221,  220,  219,  218,  216,  215,  169,  231,
 /*   750 */   361,   73,  361,  361,  177,  361,  361,  361,  105,  361,
 /*   760 */   169,  231,  200,   71,  361,  193,  177,  361,  361,  361,
 /*   770 */   105,   96,  169,  231,  200,   69,  226,  193,  177,  225,
 /*   780 */   224,  361,  105,   96,  169,  231,  200,   67,  361,  193,
 /*   790 */   177,  361,  227,  361,  105,   96,  361,  223,  200,  169,
 /*   800 */   231,  193,   65,  361,  361,  177,  361,   96,  361,  105,
 /*   810 */   361,  361,  361,  200,  214,   99,  193,  207,  361,   76,
 /*   820 */   163,   93,   96,   96,  361,  361,  361,  169,  204,  231,
 /*   830 */    60,  361,  361,  177,  177,  185,  361,  105,  105,  105,
 /*   840 */   361,  200,  200,  200,  193,  193,  193,  361,  361,  361,
 /*   850 */    96,   96,   96,  361,  361,   47,   46,  361,  142,  139,
 /*   860 */    89,   86,   46,  361,  142,  139,   89,   86,  125,  361,
 /*   870 */   126,  361,  105,  361,  105,  361,  200,  361,  200,  193,
 /*   880 */   189,  193,  124,  361,  105,   96,  105,   96,  200,  361,
 /*   890 */   200,  193,  123,  193,  114,  361,  105,   96,  200,   96,
 /*   900 */   200,  193,  184,  193,  183,  361,  105,   96,  105,   96,
 /*   910 */   200,  361,  200,  193,  182,  193,  361,  361,  105,   96,
 /*   920 */   361,   96,  200,  361,  181,  193,  361,  361,  105,  180,
 /*   930 */   361,   96,  200,  105,  361,  193,  361,  200,  361,  179,
 /*   940 */   193,   96,  361,  105,  178,  361,   96,  200,  105,   74,
 /*   950 */   193,  361,  200,  105,   72,  193,   96,  200,  105,   70,
 /*   960 */   193,   96,  200,  105,  361,  193,   96,  200,  361,  171,
 /*   970 */   193,   96,  361,  105,  361,  361,   96,  200,  361,  361,
 /*   980 */   193,  121,  361,  361,  361,  105,   96,  361,  361,  200,
 /*   990 */   361,  120,  193,  361,  361,  105,   62,  361,   96,  200,
 /*  1000 */   105,  361,  193,  361,  200,  361,  361,  193,   96,  361,
 /*  1010 */   361,  214,  104,   96,  207,  214,  100,  361,  207,  361,
 /*  1020 */    96,  361,  361,  361,   96,  214,  110,  361,  207,  214,
 /*  1030 */   113,  361,  207,  361,   96,  361,  214,  103,   96,  207,
 /*  1040 */   214,  102,  361,  207,  361,   96,  361,  214,  101,   96,
 /*  1050 */   207,  361,  361,  361,  361,  361,   96,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   70,   71,    0,   73,   11,   12,   13,   58,   15,
 /*    10 */    79,   17,   17,   19,   20,   48,   49,   23,   24,   25,
 /*    20 */    26,   27,   28,   29,   51,   52,   32,   33,   78,   35,
 /*    30 */    57,   37,   38,   39,   40,   41,    6,   14,   11,   12,
 /*    40 */    46,   11,   12,   52,   21,   15,   16,   17,   57,   19,
 /*    50 */    20,   11,   12,   23,   24,   25,   26,   27,   28,   29,
 /*    60 */     2,   34,   32,   33,   72,   35,   74,   37,   38,   39,
 /*    70 */    40,   41,    6,   11,   12,   13,   46,   11,   12,   20,
 /*    80 */    72,   15,   74,   17,   17,   19,   20,   17,   31,   23,
 /*    90 */    24,   25,   26,   27,   28,   29,   20,   17,   32,   33,
 /*   100 */    72,   35,   74,   37,   38,   39,   40,   41,    6,   21,
 /*   110 */    11,   12,   46,   11,   12,   52,   20,   18,   16,   17,
 /*   120 */    57,   65,   20,   67,   21,   23,   24,   25,   26,   27,
 /*   130 */    28,   29,   21,   36,   32,   33,   72,   35,   74,   37,
 /*   140 */    38,   39,   40,   41,    6,   72,   30,   74,   46,   11,
 /*   150 */    12,   72,   17,   74,   16,   17,   17,   17,   20,   30,
 /*   160 */    34,   23,   24,   25,   26,   27,   28,   29,   21,   21,
 /*   170 */    32,   33,   72,   35,   74,   37,   38,   39,   40,   41,
 /*   180 */     6,   72,   21,   74,   46,   11,   12,   72,   52,   74,
 /*   190 */    16,   17,   21,   57,   20,   17,   21,   23,   24,   25,
 /*   200 */    26,   27,   28,   29,   21,   21,   32,   33,   21,   35,
 /*   210 */    11,   37,   38,   39,   40,   41,    6,   72,   21,   74,
 /*   220 */    46,   11,   12,    7,    8,    9,   10,   17,   20,   20,
 /*   230 */    20,   68,   20,   23,   24,   25,   26,   27,   28,   29,
 /*   240 */    80,   52,   32,   33,   58,   35,   57,   37,   38,   39,
 /*   250 */    40,   41,   42,   52,    6,   36,   46,   14,   57,   11,
 /*   260 */    12,   76,   17,   65,   16,   17,   17,   72,   20,   74,
 /*   270 */    70,   23,   24,   25,   26,   27,   28,   29,   58,   52,
 /*   280 */    32,   33,   69,   35,   57,   37,   38,   39,   40,   41,
 /*   290 */     6,   70,   52,   70,   46,   11,   12,   57,   52,   21,
 /*   300 */    16,   17,   21,   57,   20,   81,   21,   23,   24,   25,
 /*   310 */    26,   27,   28,   29,   21,   21,   32,   33,   81,   35,
 /*   320 */    81,   37,   38,   39,   40,   41,    6,   81,   52,   52,
 /*   330 */    46,   11,   12,   57,   57,   81,   16,   17,   81,   81,
 /*   340 */    20,   81,   81,   23,   24,   25,   26,   27,   28,   29,
 /*   350 */    81,   52,   32,   33,   81,   35,   57,   37,   38,   39,
 /*   360 */    40,   41,    6,   72,   81,   74,   46,   11,   12,    7,
 /*   370 */     8,    9,   10,   17,   81,   81,   20,   81,   81,   23,
 /*   380 */    24,   25,   26,   27,   28,   29,   81,    6,   32,   33,
 /*   390 */    81,   35,   81,   37,   38,   39,   40,   41,   17,   81,
 /*   400 */    81,   20,   46,   81,   23,   24,   25,   26,   27,   28,
 /*   410 */    29,   81,    6,   32,   33,   81,   35,   81,   37,   38,
 /*   420 */    39,   40,   41,   17,   81,    6,   20,   46,   81,   23,
 /*   430 */    24,   25,   26,   27,   28,   29,   17,   31,   81,   20,
 /*   440 */    81,   35,   23,   24,   25,   26,   27,   28,   29,   43,
 /*   450 */    44,   45,   50,   81,   35,   53,   54,   55,   56,   57,
 /*   460 */    81,   52,   60,   61,   62,   63,   57,   81,   66,   52,
 /*   470 */    81,   81,   70,   50,   57,   73,   53,   54,   55,   56,
 /*   480 */    57,   79,   81,   60,   61,   62,   63,    6,   81,   66,
 /*   490 */    52,   70,   71,   70,   73,   57,   73,   81,   17,   81,
 /*   500 */    79,   20,   79,   81,   23,   24,   25,   26,   27,   28,
 /*   510 */    29,   81,   52,   32,   33,   50,   35,   57,   53,   54,
 /*   520 */    55,   56,   57,   70,   71,   60,   73,   62,   63,   76,
 /*   530 */    77,   66,   79,   81,   81,   70,   52,   81,   73,   17,
 /*   540 */    81,   57,   20,   81,   79,   23,   24,   25,   26,   27,
 /*   550 */    28,   29,   81,   81,   32,   33,   81,   35,   53,   54,
 /*   560 */    55,   56,   57,   70,   71,   60,   73,   62,   63,    6,
 /*   570 */    81,   66,   79,   81,   81,   70,   70,   71,   73,   73,
 /*   580 */    17,   81,    6,   20,   79,   79,   23,   24,   25,   26,
 /*   590 */    27,   28,   29,   17,   81,    6,   20,   81,   35,   23,
 /*   600 */    24,   25,   26,   27,   28,   29,   17,   81,    6,   20,
 /*   610 */    81,   35,   23,   24,   25,   26,   27,   28,   29,   17,
 /*   620 */    81,    6,   20,   81,   35,   23,   24,   25,   26,   27,
 /*   630 */    28,   29,   17,   81,    6,   20,   81,   35,   23,   24,
 /*   640 */    25,   26,   27,   28,   29,   17,   81,    6,   20,   81,
 /*   650 */    35,   23,   24,   25,   26,   27,   28,   29,   17,   81,
 /*   660 */     6,   20,   81,   35,   23,   24,   25,   26,   27,   28,
 /*   670 */    29,   17,   81,    6,   31,   81,   35,   23,   24,   25,
 /*   680 */    26,   27,   28,   29,   17,   81,   43,   44,   45,   35,
 /*   690 */    23,   24,   25,   26,   27,   28,   29,    1,    2,    3,
 /*   700 */     4,    5,   35,    7,    8,    9,   10,    1,    2,    3,
 /*   710 */     4,    5,   81,    7,    8,    9,   10,   56,   57,   81,
 /*   720 */    59,   70,   71,   62,   73,   64,   81,   66,   81,   81,
 /*   730 */    79,   70,   81,   81,   73,   17,   81,   81,   81,   81,
 /*   740 */    79,   23,   24,   25,   26,   27,   28,   29,   56,   57,
 /*   750 */    81,   59,   81,   81,   62,   81,   81,   81,   66,   81,
 /*   760 */    56,   57,   70,   59,   81,   73,   62,   81,   81,   81,
 /*   770 */    66,   79,   56,   57,   70,   59,    1,   73,   62,    4,
 /*   780 */     5,   81,   66,   79,   56,   57,   70,   59,   81,   73,
 /*   790 */    62,   81,   17,   81,   66,   79,   81,   22,   70,   56,
 /*   800 */    57,   73,   59,   81,   81,   62,   81,   79,   81,   66,
 /*   810 */    81,   81,   81,   70,   70,   71,   73,   73,   81,   75,
 /*   820 */    76,   77,   79,   79,   81,   81,   81,   56,   56,   57,
 /*   830 */    59,   81,   81,   62,   62,   62,   81,   66,   66,   66,
 /*   840 */    81,   70,   70,   70,   73,   73,   73,   81,   81,   81,
 /*   850 */    79,   79,   79,   81,   81,    4,    5,   81,    7,    8,
 /*   860 */     9,   10,    5,   81,    7,    8,    9,   10,   62,   81,
 /*   870 */    62,   81,   66,   81,   66,   81,   70,   81,   70,   73,
 /*   880 */    62,   73,   62,   81,   66,   79,   66,   79,   70,   81,
 /*   890 */    70,   73,   62,   73,   66,   81,   66,   79,   70,   79,
 /*   900 */    70,   73,   62,   73,   62,   81,   66,   79,   66,   79,
 /*   910 */    70,   81,   70,   73,   62,   73,   81,   81,   66,   79,
 /*   920 */    81,   79,   70,   81,   62,   73,   81,   81,   66,   62,
 /*   930 */    81,   79,   70,   66,   81,   73,   81,   70,   81,   62,
 /*   940 */    73,   79,   81,   66,   62,   81,   79,   70,   66,   62,
 /*   950 */    73,   81,   70,   66,   62,   73,   79,   70,   66,   62,
 /*   960 */    73,   79,   70,   66,   81,   73,   79,   70,   81,   62,
 /*   970 */    73,   79,   81,   66,   81,   81,   79,   70,   81,   81,
 /*   980 */    73,   62,   81,   81,   81,   66,   79,   81,   81,   70,
 /*   990 */    81,   62,   73,   81,   81,   66,   62,   81,   79,   70,
 /*  1000 */    66,   81,   73,   81,   70,   81,   81,   73,   79,   81,
 /*  1010 */    81,   70,   71,   79,   73,   70,   71,   81,   73,   81,
 /*  1020 */    79,   81,   81,   81,   79,   70,   71,   81,   73,   70,
 /*  1030 */    71,   81,   73,   81,   79,   81,   70,   71,   79,   73,
 /*  1040 */    70,   71,   81,   73,   81,   79,   81,   70,   71,   79,
 /*  1050 */    73,   81,   81,   81,   81,   81,   79,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (148)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (857)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   66,   66,   66,   30,   -6,  320,  356,  356,  356,
 /*    10 */   356,  356,  284,  248,  210,  174,  138,  102,  356,  381,
 /*    20 */   667,  667,  481,  481,  481,  481,  481,  481,  481,  481,
 /*    30 */   481,  481,  481,  481,  481,  481,  481,  481,  481,  481,
 /*    40 */   481,  481,  522,  641,  628,  615,  602,  589,  654,  654,
 /*    50 */   654,  654,  654,  654,  654,   62,  406,  576,  563,  419,
 /*    60 */    27,   99,   40,   40,   40,   40,   40,   40,   40,   40,
 /*    70 */    40,   40,   40,   40,   40,   40,  243,  294,  293,  285,
 /*    80 */   281,  278,  249,   -7,   -7,   -7,   -7,  718,  718,  718,
 /*    90 */   775,   23,  249,  243,  245,  243,  219,  212,  696,  696,
 /*   100 */   696,  696,  696,  696,  696,  706,  696,  851,  851,  851,
 /*   110 */   857,  643,  362,  362,  216,  209,  208,  197,   57,  199,
 /*   120 */   187,  184,  178,  183,  175,  171,  161,  126,  148,  129,
 /*   130 */   147,  140,  139,  111,   97,  135,  116,  103,   96,   80,
 /*   140 */    88,   76,   70,   57,   59,   67,   58,   -5,    3,
};
#define YY_REDUCE_USE_DFLT (-70)
#define YY_REDUCE_COUNT (97)
#define YY_REDUCE_MIN   (-69)
#define YY_REDUCE_MAX   (977)
static const short yy_reduce_ofst[] = {
 /*     0 */   -33,  423,  402,  465,  505,  505,  661,  743,  728,  716,
 /*    10 */   704,  692,  772,  772,  772,  772,  772,  772,  772,  771,
 /*    20 */   744,  453,  934,  929,  919,  907,  897,  892,  887,  882,
 /*    30 */   877,  867,  862,  852,  842,  840,  830,  820,  818,  808,
 /*    40 */   806,  773,  828,  977,  970,  966,  959,  955,  945,  941,
 /*    50 */   651,  506,  493,  421,  -69,  -27,  145,  291,  195,  145,
 /*    60 */   484,  460,  438,  417,  409,  299,  277,  276,  246,  240,
 /*    70 */   227,  201,  189,  136,   63,   -9,  -50,  115,  109,  100,
 /*    80 */    79,   73,   56,   64,   28,    8,   -8,  223,  221,  200,
 /*    90 */   213,  220,  198,  186,  185,  186,  160,  163,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   247,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    10 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    20 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    30 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    40 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    50 */   359,  359,  359,  359,  359,  359,  281,  319,  315,  281,
 /*    60 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*    70 */   359,  359,  359,  359,  359,  359,  308,  302,  302,  302,
 /*    80 */   302,  302,  359,  302,  302,  302,  302,  359,  359,  359,
 /*    90 */   359,  359,  359,  311,  359,  309,  343,  267,  303,  304,
 /*   100 */   337,  335,  333,  331,  330,  338,  305,  291,  290,  285,
 /*   110 */   286,  282,  299,  288,  264,  281,  319,  359,  359,  254,
 /*   120 */   359,  359,  359,  359,  359,  359,  359,  359,  359,  359,
 /*   130 */   359,  359,  359,  359,  359,  359,  359,  359,  296,  359,
 /*   140 */   359,  292,  359,  281,  315,  359,  263,  359,  359,  248,
 /*   150 */   249,  260,  259,  241,  275,  274,  262,  266,  268,  265,
 /*   160 */   317,  316,  310,  307,  306,  253,  287,  289,  344,  256,
 /*   170 */   252,  358,  349,  348,  347,  346,  345,  340,  357,  356,
 /*   180 */   355,  354,  353,  352,  351,  350,  336,  334,  332,  339,
 /*   190 */   326,  324,  323,  322,  325,  328,  321,  320,  318,  327,
 /*   200 */   312,  329,  314,  313,  255,  342,  341,  300,  301,  298,
 /*   210 */   297,  295,  294,  293,  284,  283,  282,  281,  280,  279,
 /*   220 */   278,  277,  276,  273,  272,  271,  270,  269,  261,  258,
 /*   230 */   257,  251,  250,  246,  245,  244,  243,  242,  240,
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
 /*  48 */ "np_arg ::= np_arg OP1 LP s2 RP",
 /*  49 */ "np_arg ::= np_arg OP2 np_arg",
 /*  50 */ "np_arg ::= np_arg OP2 LP s2 RP",
 /*  51 */ "np_arg ::= np_arg CAST np_arg",
 /*  52 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  53 */ "np_arg ::= np_arg DOT ID",
 /*  54 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  55 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  56 */ "np_arg ::= np_arg DCOLON ID",
 /*  57 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  58 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  59 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  60 */ "np_arg ::= NOT np_arg",
 /*  61 */ "np_arg ::= lambda",
 /*  62 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  63 */ "np_arg_list_start ::=",
 /*  64 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  65 */ "np_arg_list_elems ::= np_arg",
 /*  66 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  67 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  68 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  69 */ "np_opt_kw_arg_list ::=",
 /*  70 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  71 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  72 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  73 */ "np_recv ::= lit",
 /*  74 */ "np_recv ::= ID LP RP",
 /*  75 */ "np_recv ::= ID LP np_arg_list RP",
 /*  76 */ "np_recv ::= np_recv DOT ID",
 /*  77 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  78 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  79 */ "np_recv ::= np_recv DCOLON ID",
 /*  80 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  81 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  82 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  83 */ "np_recv ::= lambda",
 /*  84 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  85 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  86 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  87 */ "np_recv ::= LP s2 RP",
 /*  88 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  89 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /*  90 */ "s2 ::= ID np_arg_list",
 /*  91 */ "s2 ::= np_recv CAST np_arg",
 /*  92 */ "s2 ::= np_recv OP0 np_arg",
 /*  93 */ "s2 ::= np_recv OP0 LP s2 RP",
 /*  94 */ "s2 ::= np_recv OP1 np_arg",
 /*  95 */ "s2 ::= np_recv OP1 LP s2 RP",
 /*  96 */ "s2 ::= np_recv OP2 np_arg",
 /*  97 */ "s2 ::= np_recv OP2 LP s2 RP",
 /*  98 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  99 */ "s2 ::= np_recv",
 /* 100 */ "s2 ::= NOT s2",
 /* 101 */ "stmt ::= s2",
 /* 102 */ "lambda_start ::= LB",
 /* 103 */ "lambda_args ::= PIPE ID PIPE",
 /* 104 */ "lambda_args ::=",
 /* 105 */ "lambda ::= lambda_start lambda_args seq RB",
 /* 106 */ "stmt ::= IF s2 fin seq fin END",
 /* 107 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 108 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 109 */ "stmt ::= IMPORT ID",
 /* 110 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 111 */ "stmt ::= ID EQUAL s2",
 /* 112 */ "stmt ::= ID OP2_SET s2",
 /* 113 */ "stmt ::= ID OP1_SET s2",
 /* 114 */ "stmt ::= ID OP0_SET s2",
 /* 115 */ "stmt ::= IVAR EQUAL s2",
 /* 116 */ "stmt ::= IVAR OP2_SET s2",
 /* 117 */ "stmt ::= IVAR OP1_SET s2",
 /* 118 */ "stmt ::= IVAR OP0_SET s2",
 /* 119 */ "stmt ::= RAISE s2",
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
  { 71, 5 },
  { 71, 3 },
  { 71, 5 },
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
  { 66, 3 },
  { 62, 4 },
  { 62, 4 },
  { 62, 2 },
  { 62, 3 },
  { 62, 3 },
  { 62, 5 },
  { 62, 3 },
  { 62, 5 },
  { 62, 3 },
  { 62, 5 },
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
#line 1160 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 33 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1166 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 45: /* np_arg ::= lit */ yytestcase(yyruleno==45);
      case 61: /* np_arg ::= lambda */ yytestcase(yyruleno==61);
      case 73: /* np_recv ::= lit */ yytestcase(yyruleno==73);
      case 83: /* np_recv ::= lambda */ yytestcase(yyruleno==83);
      case 99: /* s2 ::= np_recv */ yytestcase(yyruleno==99);
      case 101: /* stmt ::= s2 */ yytestcase(yyruleno==101);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1181 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 58 "vm/parser.lm"
{ S->start_class(); }
#line 1186 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 59 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1192 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 61 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1199 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1206 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 69 "vm/parser.lm"
{ S->start_def(); }
#line 1211 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 72 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1216 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST np_recv */
#line 73 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1221 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= OP2 */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= SQUARE */ yytestcase(yyruleno==34);
#line 81 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1230 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin def_body */
#line 88 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1237 "vm/parser.c.inc"
        break;
      case 36: /* def ::= def_start def_name def_args fin END */
#line 91 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1244 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NUM */
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1249 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= NIL */
#line 96 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1254 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= TRUE */
#line 97 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1259 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= FALSE */
#line 98 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1264 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= SELF */
#line 99 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1269 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= ID */
#line 100 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1274 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= IVAR */
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1279 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= LITSTR */
#line 102 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1284 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg OP0 np_arg */
      case 47: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==47);
      case 92: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==92);
      case 94: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==94);
#line 106 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1292 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP1 LP s2 RP */
      case 93: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==93);
      case 95: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==95);
#line 110 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1299 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg OP2 np_arg */
      case 96: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==96);
#line 112 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1305 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 97: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==97);
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1311 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg CAST np_arg */
      case 91: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==91);
#line 116 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1317 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg NEQUAL np_arg */
      case 98: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==98);
#line 118 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1323 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DOT ID */
      case 76: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==76);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1329 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DOT ID LP RP */
      case 77: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==77);
#line 120 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1335 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 78: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==78);
#line 122 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1341 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DCOLON ID */
      case 79: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==79);
#line 123 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1347 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 80: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==80);
#line 125 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1353 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 81: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==81);
#line 127 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1359 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 82: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==82);
#line 129 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1365 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= NOT np_arg */
      case 100: /* s2 ::= NOT s2 */ yytestcase(yyruleno==100);
#line 130 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1371 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 86: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==86);
#line 133 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1377 "vm/parser.c.inc"
        break;
      case 63: /* np_arg_list_start ::= */
#line 135 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1382 "vm/parser.c.inc"
        break;
      case 64: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 65: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==65);
#line 136 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1388 "vm/parser.c.inc"
        break;
      case 66: /* np_kw_arg ::= ID EQUAL np_arg */
#line 139 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1393 "vm/parser.c.inc"
        break;
      case 74: /* np_recv ::= ID LP RP */
#line 151 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1398 "vm/parser.c.inc"
        break;
      case 75: /* np_recv ::= ID LP np_arg_list RP */
#line 152 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1403 "vm/parser.c.inc"
        break;
      case 84: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 164 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1408 "vm/parser.c.inc"
        break;
      case 85: /* np_recv ::= DICT_START np_arg_list RB */
#line 165 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1413 "vm/parser.c.inc"
        break;
      case 87: /* np_recv ::= LP s2 RP */
#line 168 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-1].minor.yy88.a; }
#line 1418 "vm/parser.c.inc"
        break;
      case 88: /* s2 ::= np_recv DOT ID np_arg_list */
#line 170 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1423 "vm/parser.c.inc"
        break;
      case 89: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 172 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1428 "vm/parser.c.inc"
        break;
      case 90: /* s2 ::= ID np_arg_list */
#line 173 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1433 "vm/parser.c.inc"
        break;
      case 102: /* lambda_start ::= LB */
#line 190 "vm/parser.lm"
{ S->start_lambda(); }
#line 1438 "vm/parser.c.inc"
        break;
      case 103: /* lambda_args ::= PIPE ID PIPE */
#line 192 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1443 "vm/parser.c.inc"
        break;
      case 105: /* lambda ::= lambda_start lambda_args seq RB */
#line 195 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1448 "vm/parser.c.inc"
        break;
      case 106: /* stmt ::= IF s2 fin seq fin END */
#line 199 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1453 "vm/parser.c.inc"
        break;
      case 107: /* stmt ::= UNLESS s2 fin seq fin END */
#line 200 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1458 "vm/parser.c.inc"
        break;
      case 108: /* stmt ::= WHILE s2 fin seq fin END */
#line 201 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1463 "vm/parser.c.inc"
        break;
      case 109: /* stmt ::= IMPORT ID */
#line 205 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1468 "vm/parser.c.inc"
        break;
      case 110: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 207 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1475 "vm/parser.c.inc"
        break;
      case 111: /* stmt ::= ID EQUAL s2 */
#line 211 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1480 "vm/parser.c.inc"
        break;
      case 112: /* stmt ::= ID OP2_SET s2 */
      case 113: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==113);
      case 114: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==114);
#line 212 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1487 "vm/parser.c.inc"
        break;
      case 115: /* stmt ::= IVAR EQUAL s2 */
#line 215 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1492 "vm/parser.c.inc"
        break;
      case 116: /* stmt ::= IVAR OP2_SET s2 */
      case 117: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==117);
      case 118: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==118);
#line 217 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1499 "vm/parser.c.inc"
        break;
      case 119: /* stmt ::= RAISE s2 */
#line 222 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1504 "vm/parser.c.inc"
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
      /* (67) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==67);
      /* (68) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==68);
      /* (69) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==69);
      /* (70) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==70);
      /* (71) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==71);
      /* (72) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==72);
      /* (104) lambda_args ::= */ yytestcase(yyruleno==104);
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
#line 1593 "vm/parser.c.inc"
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
