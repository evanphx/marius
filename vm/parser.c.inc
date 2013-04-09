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
#define YYNOCODE 85
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
#define YYNSTATE 261
#define YYNRULE 130
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
#define YY_ACTTAB_COUNT (1284)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    41,  249,  117,   11,  242,  237,  236,  186,  234,  185,
 /*    10 */   107,   64,  183,   42,  237,  236,  257,  256,  255,  254,
 /*    20 */   253,  124,  250,  133,   91,   90,   45,   89,  239,  175,
 /*    30 */    30,   29,   28,  140,   22,   76,  158,   41,   20,  157,
 /*    40 */    27,   20,  237,  236,  237,  236,  185,  184,   64,  183,
 /*    50 */    42,  261,   60,  257,  256,  255,  254,  253,  124,  250,
 /*    60 */    21,   91,   90,   12,  247,  239,  101,   30,   29,   28,
 /*    70 */   140,  234,   76,  246,   41,  249,  119,   27,  242,  237,
 /*    80 */   236,  188,   88,  185,  107,   64,  183,   42,  243,  244,
 /*    90 */   257,  256,  255,  254,  253,  124,  250,  241,   91,   90,
 /*   100 */   154,  156,  239,   20,   30,   29,   28,  140,   34,   76,
 /*   110 */   148,   41,   20,  147,   27,   20,  237,  236,   33,   32,
 /*   120 */    31,  203,   64,  146,   42,   20,  240,  257,  256,  255,
 /*   130 */   254,  253,  124,  250,  238,   91,   90,  197,  232,  239,
 /*   140 */    19,   30,   29,   28,  140,  234,   76,   18,   41,  166,
 /*   150 */     4,   27,  234,  237,  236,  234,  228,  226,  202,   64,
 /*   160 */   162,   42,   20,  224,  257,  256,  255,  254,  253,  124,
 /*   170 */   250,  220,   91,   90,  222,  159,  239,   20,   30,   29,
 /*   180 */    28,  140,  152,   76,   20,   41,  219,  151,   27,   20,
 /*   190 */   237,  236,  237,  236,  167,  201,   64,  149,   42,   20,
 /*   200 */   200,  257,  256,  255,  254,  253,  124,  250,  218,   91,
 /*   210 */    90,  216,  174,  239,  100,   30,   29,   28,  140,   10,
 /*   220 */    76,   17,   41,  195,  234,   27,  234,  237,  236,  231,
 /*   230 */   215,   20,    9,   64,  227,   42,   20,  234,  257,  256,
 /*   240 */   255,  254,  253,  124,  250,  214,   91,   90,  213,  196,
 /*   250 */   239,   16,   30,   29,   28,  140,  234,   76,   74,   41,
 /*   260 */   194,    8,   27,  191,  237,  236,  234,  193,  192,  199,
 /*   270 */    64,  223,   42,   20,   68,  257,  256,  255,  254,  253,
 /*   280 */   124,  250,   86,   91,   90,   85,   54,  239,   15,   30,
 /*   290 */    29,   28,  140,  234,   76,    7,   41,   87,   14,   27,
 /*   300 */   234,  237,  236,  234,   63,  155,  173,   64,  105,   42,
 /*   310 */   133,  190,  257,  256,  255,  254,  253,  124,  250,  132,
 /*   320 */    91,   90,   83,   71,  239,    3,   30,   29,   28,  140,
 /*   330 */   234,   76,    6,   41,  176,   13,   27,  234,  237,  236,
 /*   340 */   234,  130,  235,  171,   64,  102,   42,  103,  248,  257,
 /*   350 */   256,  255,  254,  253,  124,  250,  245,   91,   90,  160,
 /*   360 */    65,  239,    1,   30,   29,   28,  140,  234,   76,    2,
 /*   370 */    41,  128,  233,   27,  234,  237,  236,  229,  225,  393,
 /*   380 */   393,   64,  393,   42,  393,  393,  257,  256,  255,  254,
 /*   390 */   253,  124,  250,  393,   91,   90,  393,  393,  239,  393,
 /*   400 */    30,   29,   28,  140,   41,   76,  393,  393,  393,  393,
 /*   410 */    27,  393,  393,  185,  393,   64,  183,   42,  393,  393,
 /*   420 */   257,  256,  255,  254,  253,  124,  250,  393,   91,   90,
 /*   430 */    41,  393,  239,  393,   30,   29,   28,  140,  393,   76,
 /*   440 */   393,   64,  393,   42,   27,  393,  257,  256,  255,  254,
 /*   450 */   253,  124,  250,  393,   91,   90,  331,  393,  239,  393,
 /*   460 */    30,   29,   28,  140,  393,   76,  393,  331,  393,   87,
 /*   470 */    27,  393,  331,  331,  331,  331,  331,  331,  331,  393,
 /*   480 */   331,  331,  393,   44,  331,   72,  393,  393,  170,  259,
 /*   490 */   258,  165,  235,   37,   36,   35,  131,  169,  204,   99,
 /*   500 */   393,  393,  116,  393,  393,  393,  230,   72,  393,  221,
 /*   510 */   170,  259,  258,  165,  235,  107,  393,  393,  131,  168,
 /*   520 */   204,   99,  331,  393,  116,  392,    5,  393,  230,  101,
 /*   530 */   393,  221,  393,  331,  234,   87,  393,  107,  331,  331,
 /*   540 */   331,  331,  331,  331,  331,  393,  331,  331,  331,  393,
 /*   550 */   331,  249,  109,  393,  242,  393,   84,  189,  104,  331,
 /*   560 */   107,   86,  393,  393,  331,  331,  331,  331,  331,  331,
 /*   570 */   331,  393,  331,  331,  331,  393,  331,   51,   50,  393,
 /*   580 */   163,  161,   98,   95,  393,  331,  393,   85,  393,  393,
 /*   590 */   331,  331,  331,  331,  331,  331,  331,  393,  331,  331,
 /*   600 */    57,   50,  331,  163,  161,   98,   95,  393,  393,  393,
 /*   610 */   393,  252,  393,   23,  393,  393,  257,  256,  255,  254,
 /*   620 */   253,  251,  250,  187,   94,   93,   57,  116,  239,  393,
 /*   630 */   393,  230,  249,  118,  221,  242,  393,  252,  393,   24,
 /*   640 */   107,  107,  257,  256,  255,  254,  253,  251,  250,  212,
 /*   650 */    94,   93,   57,  116,  239,  249,  108,  230,  242,  393,
 /*   660 */   221,  189,  106,  252,  107,   25,  107,  393,  257,  256,
 /*   670 */   255,  254,  253,  251,  250,  393,   94,   93,   57,  393,
 /*   680 */   239,  163,  161,   98,   95,  393,  393,  393,  393,  252,
 /*   690 */   393,   26,  393,  393,  257,  256,  255,  254,  253,  251,
 /*   700 */   250,  393,   94,   93,   57,  393,  239,  129,  150,   96,
 /*   710 */    92,  393,  393,  393,  393,  252,  393,   43,  393,  393,
 /*   720 */   257,  256,  255,  254,  253,  251,  250,  144,   94,   93,
 /*   730 */    57,  116,  239,  393,  393,  230,  249,  125,  221,  242,
 /*   740 */   393,  252,  393,   40,  107,  107,  257,  256,  255,  254,
 /*   750 */   253,  251,  250,  123,   94,   93,   57,  230,  239,  393,
 /*   760 */   221,  393,  393,  393,  393,  393,  107,  252,  393,   39,
 /*   770 */   393,  393,  257,  256,  255,  254,  253,  251,  250,  393,
 /*   780 */    94,   93,   57,  393,  239,  393,  393,  393,  393,  393,
 /*   790 */   393,  393,  393,  252,  393,   38,  393,  393,  257,  256,
 /*   800 */   255,  254,  253,  251,  250,  393,   94,   93,   41,  393,
 /*   810 */   239,  249,  115,  393,  242,  393,  393,  393,  393,   67,
 /*   820 */   107,   42,  393,  393,  257,  256,  255,  254,  253,  251,
 /*   830 */   250,  393,   91,   90,   57,  393,  239,  393,  393,   53,
 /*   840 */    52,   59,   58,   51,   50,  252,  163,  161,   98,   95,
 /*   850 */   257,  256,  255,  254,  253,  251,  250,  393,   94,   93,
 /*   860 */   393,  393,  239,  393,  393,  127,  393,   42,  393,  393,
 /*   870 */   257,  256,  255,  254,  253,  251,  250,  393,   91,   90,
 /*   880 */    57,  393,  239,  393,  393,   49,   48,   56,   55,   47,
 /*   890 */    46,  164,   66,  150,   97,   92,  257,  256,  255,  254,
 /*   900 */   253,  251,  250,  393,   94,   93,   61,  393,  239,  170,
 /*   910 */   259,  258,  165,  249,  110,  393,  242,  131,  393,  204,
 /*   920 */    99,  393,  107,  116,  393,  393,  393,  230,  393,  393,
 /*   930 */   221,  260,  259,  258,  165,  235,  107,  393,  393,  131,
 /*   940 */   393,  204,   99,  393,  393,  116,  393,  393,  393,  230,
 /*   950 */   139,  235,  221,   70,  393,  393,  145,  204,  107,  172,
 /*   960 */   116,  116,  393,  393,  230,  230,  393,  221,  221,  393,
 /*   970 */   252,  393,  393,  107,  107,  257,  256,  255,  254,  253,
 /*   980 */   251,  250,  139,  393,  393,   62,  138,  249,  121,  204,
 /*   990 */   242,  393,  393,  116,  393,  393,  107,  230,  139,  235,
 /*  1000 */   221,   81,  393,  393,  393,  204,  107,  393,  393,  116,
 /*  1010 */   393,  393,  393,  230,  393,  393,  221,  139,  235,  393,
 /*  1020 */    79,  393,  107,  393,  204,  181,  180,  393,  116,  179,
 /*  1030 */   178,  393,  230,  139,  235,  221,   77,  393,  393,  217,
 /*  1040 */   204,  107,  182,  116,  116,  393,  177,  230,  230,  393,
 /*  1050 */   221,  221,  139,  235,  393,   75,  107,  107,  393,  204,
 /*  1060 */   393,  393,  393,  116,  393,  393,  393,  230,  139,  235,
 /*  1070 */   221,   73,  393,  393,  393,  204,  107,  393,  393,  116,
 /*  1080 */   393,  393,  393,  230,  393,  393,  221,  153,  235,  393,
 /*  1090 */   393,  393,  107,  393,  204,  143,  142,  393,  116,  116,
 /*  1100 */   116,  393,  230,  230,  230,  221,  221,  221,  393,  393,
 /*  1110 */   141,  107,  107,  107,  116,  393,  249,  120,  230,  242,
 /*  1120 */   393,  221,  211,  393,  393,  107,  116,  107,  393,  393,
 /*  1130 */   230,  393,  393,  221,  210,  393,  209,  393,  116,  107,
 /*  1140 */   116,  393,  230,  393,  230,  221,  393,  221,  393,  393,
 /*  1150 */   393,  107,  208,  107,  207,  393,  116,  393,  116,  393,
 /*  1160 */   230,  393,  230,  221,  206,  221,  205,  393,  116,  107,
 /*  1170 */   116,  107,  230,  393,  230,  221,   82,  221,   80,  393,
 /*  1180 */   116,  107,  116,  107,  230,  393,  230,  221,   78,  221,
 /*  1190 */   393,  393,  116,  107,  393,  107,  230,  393,  393,  221,
 /*  1200 */   198,  393,  137,  393,  116,  107,  116,  393,  230,  393,
 /*  1210 */   230,  221,  393,  221,  393,  393,  393,  107,  136,  107,
 /*  1220 */   135,  393,  116,  393,  116,  393,  230,  393,  230,  221,
 /*  1230 */   134,  221,   69,  393,  116,  107,  116,  107,  230,  393,
 /*  1240 */   230,  221,  393,  221,  393,  249,  122,  107,  242,  107,
 /*  1250 */   249,  126,  393,  242,  107,  249,  114,  393,  242,  107,
 /*  1260 */   249,  113,  393,  242,  107,  393,  393,  249,  112,  107,
 /*  1270 */   242,  393,  393,  393,  249,  111,  107,  242,  393,  393,
 /*  1280 */   393,  393,  393,  107,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     8,   73,   74,   54,   76,   13,   14,   15,   59,   17,
 /*    10 */    82,   19,   20,   21,   13,   14,   24,   25,   26,   27,
 /*    20 */    28,   29,   30,   16,   32,   33,    1,   21,   36,   22,
 /*    30 */    38,   39,   40,   41,    3,   43,   75,    8,   77,   75,
 /*    40 */    48,   77,   13,   14,   13,   14,   17,   18,   19,   20,
 /*    50 */    21,    0,   35,   24,   25,   26,   27,   28,   29,   30,
 /*    60 */    60,   32,   33,   51,   22,   36,   54,   38,   39,   40,
 /*    70 */    41,   59,   43,   19,    8,   73,   74,   48,   76,   13,
 /*    80 */    14,   81,   21,   17,   82,   19,   20,   21,   31,   22,
 /*    90 */    24,   25,   26,   27,   28,   29,   30,   22,   32,   33,
 /*   100 */    19,   75,   36,   77,   38,   39,   40,   41,   35,   43,
 /*   110 */    75,    8,   77,   75,   48,   77,   13,   14,   45,   46,
 /*   120 */    47,   18,   19,   75,   21,   77,   34,   24,   25,   26,
 /*   130 */    27,   28,   29,   30,   37,   32,   33,   51,   22,   36,
 /*   140 */    54,   38,   39,   40,   41,   59,   43,   54,    8,   53,
 /*   150 */    54,   48,   59,   13,   14,   59,   22,   19,   18,   19,
 /*   160 */    75,   21,   77,   22,   24,   25,   26,   27,   28,   29,
 /*   170 */    30,   22,   32,   33,   31,   75,   36,   77,   38,   39,
 /*   180 */    40,   41,   75,   43,   77,    8,   34,   75,   48,   77,
 /*   190 */    13,   14,   13,   14,   15,   18,   19,   75,   21,   77,
 /*   200 */    42,   24,   25,   26,   27,   28,   29,   30,   22,   32,
 /*   210 */    33,   22,   68,   36,   70,   38,   39,   40,   41,   54,
 /*   220 */    43,   54,    8,   22,   59,   48,   59,   13,   14,   75,
 /*   230 */    22,   77,   54,   19,   75,   21,   77,   59,   24,   25,
 /*   240 */    26,   27,   28,   29,   30,   22,   32,   33,   22,   34,
 /*   250 */    36,   54,   38,   39,   40,   41,   59,   43,   44,    8,
 /*   260 */    22,   54,   48,   13,   13,   14,   59,   22,   22,   18,
 /*   270 */    19,   75,   21,   77,   19,   24,   25,   26,   27,   28,
 /*   280 */    29,   30,   21,   32,   33,   21,    4,   36,   54,   38,
 /*   290 */    39,   40,   41,   59,   43,   54,    8,   21,   54,   48,
 /*   300 */    59,   13,   14,   59,   83,   37,   18,   19,   60,   21,
 /*   310 */    16,   79,   24,   25,   26,   27,   28,   29,   30,   19,
 /*   320 */    32,   33,   21,   71,   36,   54,   38,   39,   40,   41,
 /*   330 */    59,   43,   54,    8,   68,   54,   48,   59,   13,   14,
 /*   340 */    59,   19,   59,   18,   19,   60,   21,   72,   22,   24,
 /*   350 */    25,   26,   27,   28,   29,   30,   22,   32,   33,   73,
 /*   360 */    73,   36,   54,   38,   39,   40,   41,   59,   43,   54,
 /*   370 */     8,   73,   22,   48,   59,   13,   14,   22,   22,   84,
 /*   380 */    84,   19,   84,   21,   84,   84,   24,   25,   26,   27,
 /*   390 */    28,   29,   30,   84,   32,   33,   84,   84,   36,   84,
 /*   400 */    38,   39,   40,   41,    8,   43,   84,   84,   84,   84,
 /*   410 */    48,   84,   84,   17,   84,   19,   20,   21,   84,   84,
 /*   420 */    24,   25,   26,   27,   28,   29,   30,   84,   32,   33,
 /*   430 */     8,   84,   36,   84,   38,   39,   40,   41,   84,   43,
 /*   440 */    84,   19,   84,   21,   48,   84,   24,   25,   26,   27,
 /*   450 */    28,   29,   30,   84,   32,   33,    8,   84,   36,   84,
 /*   460 */    38,   39,   40,   41,   84,   43,   84,   19,   84,   21,
 /*   470 */    48,   84,   24,   25,   26,   27,   28,   29,   30,   84,
 /*   480 */    32,   33,   84,   35,   36,   52,   84,   84,   55,   56,
 /*   490 */    57,   58,   59,   45,   46,   47,   63,   64,   65,   66,
 /*   500 */    84,   84,   69,   84,   84,   84,   73,   52,   84,   76,
 /*   510 */    55,   56,   57,   58,   59,   82,   84,   84,   63,   64,
 /*   520 */    65,   66,    8,   84,   69,   50,   51,   84,   73,   54,
 /*   530 */    84,   76,   84,   19,   59,   21,   84,   82,   24,   25,
 /*   540 */    26,   27,   28,   29,   30,   84,   32,   33,    8,   84,
 /*   550 */    36,   73,   74,   84,   76,   84,   78,   79,   80,   19,
 /*   560 */    82,   21,   84,   84,   24,   25,   26,   27,   28,   29,
 /*   570 */    30,   84,   32,   33,    8,   84,   36,    6,    7,   84,
 /*   580 */     9,   10,   11,   12,   84,   19,   84,   21,   84,   84,
 /*   590 */    24,   25,   26,   27,   28,   29,   30,   84,   32,   33,
 /*   600 */     8,    7,   36,    9,   10,   11,   12,   84,   84,   84,
 /*   610 */    84,   19,   84,   21,   84,   84,   24,   25,   26,   27,
 /*   620 */    28,   29,   30,   65,   32,   33,    8,   69,   36,   84,
 /*   630 */    84,   73,   73,   74,   76,   76,   84,   19,   84,   21,
 /*   640 */    82,   82,   24,   25,   26,   27,   28,   29,   30,   65,
 /*   650 */    32,   33,    8,   69,   36,   73,   74,   73,   76,   84,
 /*   660 */    76,   79,   80,   19,   82,   21,   82,   84,   24,   25,
 /*   670 */    26,   27,   28,   29,   30,   84,   32,   33,    8,   84,
 /*   680 */    36,    9,   10,   11,   12,   84,   84,   84,   84,   19,
 /*   690 */    84,   21,   84,   84,   24,   25,   26,   27,   28,   29,
 /*   700 */    30,   84,   32,   33,    8,   84,   36,    9,   10,   11,
 /*   710 */    12,   84,   84,   84,   84,   19,   84,   21,   84,   84,
 /*   720 */    24,   25,   26,   27,   28,   29,   30,   65,   32,   33,
 /*   730 */     8,   69,   36,   84,   84,   73,   73,   74,   76,   76,
 /*   740 */    84,   19,   84,   21,   82,   82,   24,   25,   26,   27,
 /*   750 */    28,   29,   30,   69,   32,   33,    8,   73,   36,   84,
 /*   760 */    76,   84,   84,   84,   84,   84,   82,   19,   84,   21,
 /*   770 */    84,   84,   24,   25,   26,   27,   28,   29,   30,   84,
 /*   780 */    32,   33,    8,   84,   36,   84,   84,   84,   84,   84,
 /*   790 */    84,   84,   84,   19,   84,   21,   84,   84,   24,   25,
 /*   800 */    26,   27,   28,   29,   30,   84,   32,   33,    8,   84,
 /*   810 */    36,   73,   74,   84,   76,   84,   84,   84,   84,   19,
 /*   820 */    82,   21,   84,   84,   24,   25,   26,   27,   28,   29,
 /*   830 */    30,   84,   32,   33,    8,   84,   36,   84,   84,    2,
 /*   840 */     3,    4,    5,    6,    7,   19,    9,   10,   11,   12,
 /*   850 */    24,   25,   26,   27,   28,   29,   30,   84,   32,   33,
 /*   860 */    84,   84,   36,   84,   84,   19,   84,   21,   84,   84,
 /*   870 */    24,   25,   26,   27,   28,   29,   30,   84,   32,   33,
 /*   880 */     8,   84,   36,   84,   84,    2,    3,    4,    5,    6,
 /*   890 */     7,   19,    9,   10,   11,   12,   24,   25,   26,   27,
 /*   900 */    28,   29,   30,   84,   32,   33,   52,   84,   36,   55,
 /*   910 */    56,   57,   58,   73,   74,   84,   76,   63,   84,   65,
 /*   920 */    66,   84,   82,   69,   84,   84,   84,   73,   84,   84,
 /*   930 */    76,   55,   56,   57,   58,   59,   82,   84,   84,   63,
 /*   940 */    84,   65,   66,   84,   84,   69,   84,   84,   84,   73,
 /*   950 */    58,   59,   76,   61,   84,   84,   65,   65,   82,   67,
 /*   960 */    69,   69,   84,   84,   73,   73,   84,   76,   76,   84,
 /*   970 */    19,   84,   84,   82,   82,   24,   25,   26,   27,   28,
 /*   980 */    29,   30,   58,   84,   84,   61,   62,   73,   74,   65,
 /*   990 */    76,   84,   84,   69,   84,   84,   82,   73,   58,   59,
 /*  1000 */    76,   61,   84,   84,   84,   65,   82,   84,   84,   69,
 /*  1010 */    84,   84,   84,   73,   84,   84,   76,   58,   59,   84,
 /*  1020 */    61,   84,   82,   84,   65,    2,    3,   84,   69,    6,
 /*  1030 */     7,   84,   73,   58,   59,   76,   61,   84,   84,   65,
 /*  1040 */    65,   82,   19,   69,   69,   84,   23,   73,   73,   84,
 /*  1050 */    76,   76,   58,   59,   84,   61,   82,   82,   84,   65,
 /*  1060 */    84,   84,   84,   69,   84,   84,   84,   73,   58,   59,
 /*  1070 */    76,   61,   84,   84,   84,   65,   82,   84,   84,   69,
 /*  1080 */    84,   84,   84,   73,   84,   84,   76,   58,   59,   84,
 /*  1090 */    84,   84,   82,   84,   65,   65,   65,   84,   69,   69,
 /*  1100 */    69,   84,   73,   73,   73,   76,   76,   76,   84,   84,
 /*  1110 */    65,   82,   82,   82,   69,   84,   73,   74,   73,   76,
 /*  1120 */    84,   76,   65,   84,   84,   82,   69,   82,   84,   84,
 /*  1130 */    73,   84,   84,   76,   65,   84,   65,   84,   69,   82,
 /*  1140 */    69,   84,   73,   84,   73,   76,   84,   76,   84,   84,
 /*  1150 */    84,   82,   65,   82,   65,   84,   69,   84,   69,   84,
 /*  1160 */    73,   84,   73,   76,   65,   76,   65,   84,   69,   82,
 /*  1170 */    69,   82,   73,   84,   73,   76,   65,   76,   65,   84,
 /*  1180 */    69,   82,   69,   82,   73,   84,   73,   76,   65,   76,
 /*  1190 */    84,   84,   69,   82,   84,   82,   73,   84,   84,   76,
 /*  1200 */    65,   84,   65,   84,   69,   82,   69,   84,   73,   84,
 /*  1210 */    73,   76,   84,   76,   84,   84,   84,   82,   65,   82,
 /*  1220 */    65,   84,   69,   84,   69,   84,   73,   84,   73,   76,
 /*  1230 */    65,   76,   65,   84,   69,   82,   69,   82,   73,   84,
 /*  1240 */    73,   76,   84,   76,   84,   73,   74,   82,   76,   82,
 /*  1250 */    73,   74,   84,   76,   82,   73,   74,   84,   76,   82,
 /*  1260 */    73,   74,   84,   76,   82,   84,   84,   73,   74,   82,
 /*  1270 */    76,   84,   84,   84,   73,   74,   82,   76,   84,   84,
 /*  1280 */    84,   84,   84,   82,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (166)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (1023)
static const short yy_shift_ofst[] = {
 /*     0 */     1,   66,   66,   29,   -8,  396,  325,  362,  362,  362,
 /*    10 */   362,  362,  422,  288,  251,  214,  177,  140,  103,  362,
 /*    20 */   872,  872,  800,  800,  800,  800,  800,  800,  800,  800,
 /*    30 */   800,  800,  800,  800,  800,  800,  800,  800,  800,  800,
 /*    40 */   800,  800,  800,  800,  800,  800,  774,  748,  722,  696,
 /*    50 */   670,  644,  618,  592,  846,  826,  826,  826,  826,  826,
 /*    60 */   826,  179,    1,    1,  448,  566,  540,  514,   31,    1,
 /*    70 */     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*    80 */     1,    1,    1,  322,  294,  356,  355,  350,  334,  326,
 /*    90 */    -9,   -9,   -9,   -9,   -9,   -9,  951,  951,  951, 1023,
 /*   100 */     7,    1,  322,  301,  294,  300,  294,  268,  837,  837,
 /*   110 */   837,  837,  837,  837,  837,  837,  883,  837,  571,  571,
 /*   120 */   571,  571,  594,  698,   73,  672,  672,  276,  264,  261,
 /*   130 */   282,  255,   17,  250,  246,  245,  238,  201,  215,   25,
 /*   140 */   158,  226,  223,  208,  189,  186,  152,  149,  143,  141,
 /*   150 */   138,  134,  116,   25,   97,   81,   92,   75,   57,   67,
 /*   160 */    61,   54,   42,    6,   17,   25,   51,
};
#define YY_REDUCE_USE_DFLT (-73)
#define YY_REDUCE_COUNT (107)
#define YY_REDUCE_MIN   (-72)
#define YY_REDUCE_MAX   (1201)
static const short yy_reduce_ofst[] = {
 /*     0 */   475,  455,  433,  876,  876,  854,  892, 1010,  994,  975,
 /*    10 */   959,  940,  924, 1029, 1029, 1029, 1029, 1029, 1029, 1029,
 /*    20 */   478,  582, 1167, 1165, 1155, 1153, 1137, 1135, 1123, 1113,
 /*    30 */  1111, 1101, 1099, 1089, 1087, 1071, 1069, 1057, 1045, 1031,
 /*    40 */  1030,  974,  891,  662,  584,  558, 1201, 1194, 1187, 1182,
 /*    50 */  1177, 1172, 1043,  914,  684,  840,  738,  663,  559,    2,
 /*    60 */   -72,   96,   86,   12,  154,  196,  159,  154,  315,  308,
 /*    70 */   281,  278,  271,  244,  241,  234,  207,  197,  178,  167,
 /*    80 */   165,   93,  -51,  144,    0,  122,  112,  107,  100,   85,
 /*    90 */    48,   38,   35,   26,  -36,  -39,  298,  287,  286,  275,
 /*   100 */   285,  283,  266,  252,  248,  232,  248,  221,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   269,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    10 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  270,
 /*    20 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    30 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    40 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    50 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    60 */   391,  391,  269,  269,  305,  348,  344,  305,  391,  391,
 /*    70 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*    80 */   391,  391,  391,  391,  337,  331,  331,  331,  331,  331,
 /*    90 */   331,  331,  331,  331,  331,  331,  391,  391,  391,  391,
 /*   100 */   391,  270,  391,  290,  340,  391,  338,  375,  332,  333,
 /*   110 */   368,  366,  364,  362,  360,  359,  369,  334,  318,  317,
 /*   120 */   311,  309,  313,  287,  306,  326,  315,  305,  348,  344,
 /*   130 */   286,  391,  391,  276,  391,  391,  391,  391,  391,  278,
 /*   140 */   391,  391,  391,  391,  391,  391,  391,  391,  391,  391,
 /*   150 */   391,  391,  391,  277,  391,  391,  391,  391,  391,  391,
 /*   160 */   323,  391,  391,  319,  305,  266,  391,  271,  283,  282,
 /*   170 */   263,  299,  298,  285,  289,  291,  288,  297,  296,  295,
 /*   180 */   294,  293,  292,  284,  281,  280,  272,  372,  339,  336,
 /*   190 */   335,  275,  310,  312,  314,  316,  376,  279,  390,  381,
 /*   200 */   380,  379,  378,  377,  371,  389,  388,  387,  386,  385,
 /*   210 */   384,  383,  382,  367,  365,  363,  361,  370,  355,  353,
 /*   220 */   352,  351,  354,  357,  350,  349,  347,  356,  346,  345,
 /*   230 */   341,  358,  343,  342,  274,  273,  268,  267,  374,  373,
 /*   240 */   330,  329,  327,  328,  325,  324,  322,  321,  320,  308,
 /*   250 */   307,  306,  305,  304,  303,  302,  301,  300,  265,  264,
 /*   260 */   262,
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
  "$",             "AND",           "OP0",           "LT",          
  "CAST",          "NEQUAL",        "OP1",           "OP2",         
  "NOT",           "DOT",           "DCOLON",        "DOT_DOLLAR",  
  "LSB",           "NL",            "SEMI",          "EOF",         
  "COMMA",         "CLASS",         "END",           "ID",          
  "DEF",           "LP",            "RP",            "SQUARE",      
  "NUM",           "NIL",           "TRUE",          "FALSE",       
  "SELF",          "IVAR",          "LITSTR",        "RSB",         
  "TUPLE_START",   "DICT_START",    "RB",            "EQUAL",       
  "LB",            "PIPE",          "IF",            "UNLESS",      
  "WHILE",         "IMPORT",        "DOT_NAME",      "TRY",         
  "RESCUE",        "OP2_SET",       "OP1_SET",       "OP0_SET",     
  "RAISE",         "error",         "program",       "opt_fin",     
  "l1",            "last_fin",      "fin",           "l1e",         
  "class",         "def",           "stmt",          "fin_m",       
  "comma",         "seq",           "delim_seq",     "class_start", 
  "class_body",    "s2",            "def_start",     "def_body",    
  "arg",           "np_recv",       "id_list",       "def_args",    
  "def_name",      "lit",           "np_arg",        "np_arg_list", 
  "lambda",        "np_arg_list_start",  "np_arg_list_elems",  "np_kw_arg",   
  "np_kw_arg_list_elems",  "np_opt_kw_arg_list",  "lambda_start",  "lambda_args", 
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
 /*   9 */ "opt_fin ::= fin",
 /*  10 */ "last_fin ::= EOF",
 /*  11 */ "last_fin ::= fin EOF",
 /*  12 */ "fin ::= fin fin_m",
 /*  13 */ "fin ::= fin_m",
 /*  14 */ "comma ::= COMMA NL",
 /*  15 */ "comma ::= COMMA",
 /*  16 */ "seq ::= seq fin stmt",
 /*  17 */ "seq ::= stmt",
 /*  18 */ "delim_seq ::= seq opt_fin",
 /*  19 */ "class_start ::= CLASS",
 /*  20 */ "class_body ::= l1 fin END",
 /*  21 */ "class ::= class_start ID fin class_body",
 /*  22 */ "class ::= class_start ID LT s2 fin class_body",
 /*  23 */ "def_start ::= DEF",
 /*  24 */ "def_body ::= seq fin END",
 /*  25 */ "arg ::= ID",
 /*  26 */ "arg ::= ID CAST np_recv",
 /*  27 */ "id_list ::= id_list comma arg",
 /*  28 */ "id_list ::= arg",
 /*  29 */ "def_args ::=",
 /*  30 */ "def_args ::= LP id_list RP",
 /*  31 */ "def_name ::= ID",
 /*  32 */ "def_name ::= OP0",
 /*  33 */ "def_name ::= LT",
 /*  34 */ "def_name ::= OP1",
 /*  35 */ "def_name ::= OP2",
 /*  36 */ "def_name ::= SQUARE",
 /*  37 */ "def ::= def_start def_name def_args fin def_body",
 /*  38 */ "def ::= def_start def_name def_args fin END",
 /*  39 */ "lit ::= NUM",
 /*  40 */ "lit ::= NIL",
 /*  41 */ "lit ::= TRUE",
 /*  42 */ "lit ::= FALSE",
 /*  43 */ "lit ::= SELF",
 /*  44 */ "lit ::= ID",
 /*  45 */ "lit ::= IVAR",
 /*  46 */ "lit ::= LITSTR",
 /*  47 */ "np_arg ::= lit",
 /*  48 */ "np_arg ::= np_arg OP0 np_arg",
 /*  49 */ "np_arg ::= np_arg OP0 LP s2 RP",
 /*  50 */ "np_arg ::= np_arg LT np_arg",
 /*  51 */ "np_arg ::= np_arg LT LP s2 RP",
 /*  52 */ "np_arg ::= np_arg OP1 np_arg",
 /*  53 */ "np_arg ::= np_arg OP1 LP s2 RP",
 /*  54 */ "np_arg ::= np_arg OP2 np_arg",
 /*  55 */ "np_arg ::= np_arg OP2 LP s2 RP",
 /*  56 */ "np_arg ::= np_arg CAST np_arg",
 /*  57 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  58 */ "np_arg ::= np_arg DOT",
 /*  59 */ "np_arg ::= np_arg DOT LP RP",
 /*  60 */ "np_arg ::= np_arg DOT LP np_arg_list RP",
 /*  61 */ "np_arg ::= np_arg DCOLON ID",
 /*  62 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  63 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  64 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  65 */ "np_arg ::= NOT np_arg",
 /*  66 */ "np_arg ::= lambda",
 /*  67 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  68 */ "np_arg ::= TUPLE_START np_arg_list RP",
 /*  69 */ "np_arg ::= DICT_START np_arg_list RB",
 /*  70 */ "np_arg_list_start ::=",
 /*  71 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  72 */ "np_arg_list_elems ::= np_arg",
 /*  73 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  74 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  75 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  76 */ "np_opt_kw_arg_list ::=",
 /*  77 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  78 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  79 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  80 */ "np_recv ::= lit",
 /*  81 */ "np_recv ::= ID LP RP",
 /*  82 */ "np_recv ::= ID LP np_arg_list RP",
 /*  83 */ "np_recv ::= np_recv DOT",
 /*  84 */ "np_recv ::= np_recv DOT LP RP",
 /*  85 */ "np_recv ::= np_recv DOT LP np_arg_list RP",
 /*  86 */ "np_recv ::= np_recv DCOLON ID",
 /*  87 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  88 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  89 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  90 */ "np_recv ::= lambda",
 /*  91 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  92 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  93 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  94 */ "np_recv ::= LP s2 RP",
 /*  95 */ "s2 ::= np_recv DOT np_arg_list",
 /*  96 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /*  97 */ "s2 ::= ID np_arg_list",
 /*  98 */ "s2 ::= np_recv CAST np_arg",
 /*  99 */ "s2 ::= np_recv OP0 np_arg",
 /* 100 */ "s2 ::= np_recv OP0 LP s2 RP",
 /* 101 */ "s2 ::= np_recv LT np_arg",
 /* 102 */ "s2 ::= np_recv LT LP s2 RP",
 /* 103 */ "s2 ::= np_recv OP1 np_arg",
 /* 104 */ "s2 ::= np_recv OP1 LP s2 RP",
 /* 105 */ "s2 ::= np_recv OP2 np_arg",
 /* 106 */ "s2 ::= np_recv OP2 LP s2 RP",
 /* 107 */ "s2 ::= np_recv NEQUAL np_arg",
 /* 108 */ "s2 ::= np_recv",
 /* 109 */ "s2 ::= NOT s2",
 /* 110 */ "stmt ::= s2",
 /* 111 */ "stmt ::= stmt AND s2",
 /* 112 */ "lambda_start ::= LB",
 /* 113 */ "lambda_args ::= PIPE ID PIPE",
 /* 114 */ "lambda_args ::=",
 /* 115 */ "lambda ::= lambda_start lambda_args opt_fin delim_seq RB",
 /* 116 */ "stmt ::= IF s2 fin seq fin END",
 /* 117 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 118 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 119 */ "stmt ::= IMPORT DOT_NAME",
 /* 120 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 121 */ "stmt ::= ID EQUAL s2",
 /* 122 */ "stmt ::= ID OP2_SET s2",
 /* 123 */ "stmt ::= ID OP1_SET s2",
 /* 124 */ "stmt ::= ID OP0_SET s2",
 /* 125 */ "stmt ::= IVAR EQUAL s2",
 /* 126 */ "stmt ::= IVAR OP2_SET s2",
 /* 127 */ "stmt ::= IVAR OP1_SET s2",
 /* 128 */ "stmt ::= IVAR OP0_SET s2",
 /* 129 */ "stmt ::= RAISE s2",
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
  { 50, 3 },
  { 52, 3 },
  { 52, 1 },
  { 55, 1 },
  { 55, 1 },
  { 55, 1 },
  { 59, 1 },
  { 59, 1 },
  { 51, 0 },
  { 51, 1 },
  { 53, 1 },
  { 53, 2 },
  { 54, 2 },
  { 54, 1 },
  { 60, 2 },
  { 60, 1 },
  { 61, 3 },
  { 61, 1 },
  { 62, 2 },
  { 63, 1 },
  { 64, 3 },
  { 56, 4 },
  { 56, 6 },
  { 66, 1 },
  { 67, 3 },
  { 68, 1 },
  { 68, 3 },
  { 70, 3 },
  { 70, 1 },
  { 71, 0 },
  { 71, 3 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 57, 5 },
  { 57, 5 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 74, 1 },
  { 74, 3 },
  { 74, 5 },
  { 74, 3 },
  { 74, 5 },
  { 74, 3 },
  { 74, 5 },
  { 74, 3 },
  { 74, 5 },
  { 74, 3 },
  { 74, 3 },
  { 74, 2 },
  { 74, 4 },
  { 74, 5 },
  { 74, 3 },
  { 74, 3 },
  { 74, 5 },
  { 74, 6 },
  { 74, 2 },
  { 74, 1 },
  { 74, 4 },
  { 74, 3 },
  { 74, 3 },
  { 77, 0 },
  { 78, 3 },
  { 78, 1 },
  { 79, 3 },
  { 80, 3 },
  { 80, 1 },
  { 81, 0 },
  { 81, 2 },
  { 75, 3 },
  { 75, 2 },
  { 69, 1 },
  { 69, 3 },
  { 69, 4 },
  { 69, 2 },
  { 69, 4 },
  { 69, 5 },
  { 69, 3 },
  { 69, 3 },
  { 69, 5 },
  { 69, 6 },
  { 69, 1 },
  { 69, 3 },
  { 69, 3 },
  { 69, 4 },
  { 69, 3 },
  { 65, 3 },
  { 65, 4 },
  { 65, 2 },
  { 65, 3 },
  { 65, 3 },
  { 65, 5 },
  { 65, 3 },
  { 65, 5 },
  { 65, 3 },
  { 65, 5 },
  { 65, 3 },
  { 65, 5 },
  { 65, 3 },
  { 65, 1 },
  { 65, 2 },
  { 58, 1 },
  { 58, 3 },
  { 82, 1 },
  { 83, 3 },
  { 83, 0 },
  { 76, 5 },
  { 58, 6 },
  { 58, 6 },
  { 58, 6 },
  { 58, 2 },
  { 58, 9 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 2 },
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
#line 32 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy88.a)); }
#line 1232 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1238 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 47: /* np_arg ::= lit */ yytestcase(yyruleno==47);
      case 66: /* np_arg ::= lambda */ yytestcase(yyruleno==66);
      case 80: /* np_recv ::= lit */ yytestcase(yyruleno==80);
      case 90: /* np_recv ::= lambda */ yytestcase(yyruleno==90);
      case 108: /* s2 ::= np_recv */ yytestcase(yyruleno==108);
      case 110: /* stmt ::= s2 */ yytestcase(yyruleno==110);
#line 35 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1253 "vm/parser.c.inc"
        break;
      case 18: /* delim_seq ::= seq opt_fin */
      case 94: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==94);
#line 59 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-1].minor.yy88.a; }
#line 1259 "vm/parser.c.inc"
        break;
      case 19: /* class_start ::= CLASS */
#line 61 "vm/parser.lm"
{ S->start_class(); }
#line 1264 "vm/parser.c.inc"
        break;
      case 20: /* class_body ::= l1 fin END */
      case 24: /* def_body ::= seq fin END */ yytestcase(yyruleno==24);
#line 62 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1270 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1277 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID LT s2 fin class_body */
#line 68 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1284 "vm/parser.c.inc"
        break;
      case 23: /* def_start ::= DEF */
#line 72 "vm/parser.lm"
{ S->start_def(); }
#line 1289 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID */
#line 75 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1294 "vm/parser.c.inc"
        break;
      case 26: /* arg ::= ID CAST np_recv */
#line 76 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1299 "vm/parser.c.inc"
        break;
      case 31: /* def_name ::= ID */
      case 32: /* def_name ::= OP0 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= LT */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= OP1 */ yytestcase(yyruleno==34);
      case 35: /* def_name ::= OP2 */ yytestcase(yyruleno==35);
      case 36: /* def_name ::= SQUARE */ yytestcase(yyruleno==36);
#line 84 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1309 "vm/parser.c.inc"
        break;
      case 37: /* def ::= def_start def_name def_args fin def_body */
#line 92 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1316 "vm/parser.c.inc"
        break;
      case 38: /* def ::= def_start def_name def_args fin END */
#line 95 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1323 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= NUM */
#line 99 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1328 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= NIL */
#line 100 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1333 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= TRUE */
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1338 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= FALSE */
#line 102 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1343 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= SELF */
#line 103 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1348 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= ID */
#line 104 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1353 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= IVAR */
#line 105 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1358 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= LITSTR */
#line 106 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1363 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP0 np_arg */
      case 50: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==50);
      case 52: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==52);
      case 99: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==99);
      case 101: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==101);
      case 103: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==103);
#line 111 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1373 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 51: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==51);
      case 53: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==53);
      case 100: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==100);
      case 102: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==102);
      case 104: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==104);
#line 113 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1383 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg OP2 np_arg */
      case 105: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==105);
#line 126 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1389 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 106: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==106);
#line 128 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1395 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg CAST np_arg */
      case 98: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==98);
#line 131 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1401 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg NEQUAL np_arg */
      case 107: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==107);
#line 133 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1407 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg DOT */
      case 83: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==83);
#line 134 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-1].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1413 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg DOT LP RP */
      case 84: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==84);
#line 135 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-3].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1419 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 85: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==85);
#line 137 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1425 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg DCOLON ID */
      case 86: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==86);
#line 138 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1431 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 87: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==87);
#line 141 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1437 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 88: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1443 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1449 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= NOT np_arg */
      case 109: /* s2 ::= NOT s2 */ yytestcase(yyruleno==109);
#line 146 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1455 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 93: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==93);
#line 149 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1461 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 91: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==91);
#line 151 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1467 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= DICT_START np_arg_list RB */
      case 92: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==92);
#line 152 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1473 "vm/parser.c.inc"
        break;
      case 70: /* np_arg_list_start ::= */
#line 154 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1478 "vm/parser.c.inc"
        break;
      case 71: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 72: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==72);
#line 155 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1484 "vm/parser.c.inc"
        break;
      case 73: /* np_kw_arg ::= ID EQUAL np_arg */
#line 158 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1489 "vm/parser.c.inc"
        break;
      case 81: /* np_recv ::= ID LP RP */
#line 170 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1494 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= ID LP np_arg_list RP */
#line 171 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1499 "vm/parser.c.inc"
        break;
      case 95: /* s2 ::= np_recv DOT np_arg_list */
#line 189 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1504 "vm/parser.c.inc"
        break;
      case 96: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 191 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1509 "vm/parser.c.inc"
        break;
      case 97: /* s2 ::= ID np_arg_list */
#line 192 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1514 "vm/parser.c.inc"
        break;
      case 111: /* stmt ::= stmt AND s2 */
#line 208 "vm/parser.lm"
{ yygotominor.yy88.a = S->and_(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1519 "vm/parser.c.inc"
        break;
      case 112: /* lambda_start ::= LB */
#line 212 "vm/parser.lm"
{ S->start_lambda(); }
#line 1524 "vm/parser.c.inc"
        break;
      case 113: /* lambda_args ::= PIPE ID PIPE */
#line 214 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1529 "vm/parser.c.inc"
        break;
      case 115: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 217 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1534 "vm/parser.c.inc"
        break;
      case 116: /* stmt ::= IF s2 fin seq fin END */
#line 221 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1539 "vm/parser.c.inc"
        break;
      case 117: /* stmt ::= UNLESS s2 fin seq fin END */
#line 222 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1544 "vm/parser.c.inc"
        break;
      case 118: /* stmt ::= WHILE s2 fin seq fin END */
#line 223 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1549 "vm/parser.c.inc"
        break;
      case 119: /* stmt ::= IMPORT DOT_NAME */
#line 227 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1554 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 229 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1561 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= ID EQUAL s2 */
#line 233 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1566 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= ID OP2_SET s2 */
      case 123: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==123);
      case 124: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==124);
#line 234 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1573 "vm/parser.c.inc"
        break;
      case 125: /* stmt ::= IVAR EQUAL s2 */
#line 237 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1578 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= IVAR OP2_SET s2 */
      case 127: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==127);
      case 128: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==128);
#line 239 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1585 "vm/parser.c.inc"
        break;
      case 129: /* stmt ::= RAISE s2 */
#line 244 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1590 "vm/parser.c.inc"
        break;
      default:
      /* (6) fin_m ::= NL */ yytestcase(yyruleno==6);
      /* (7) fin_m ::= SEMI */ yytestcase(yyruleno==7);
      /* (8) opt_fin ::= */ yytestcase(yyruleno==8);
      /* (9) opt_fin ::= fin */ yytestcase(yyruleno==9);
      /* (10) last_fin ::= EOF */ yytestcase(yyruleno==10);
      /* (11) last_fin ::= fin EOF */ yytestcase(yyruleno==11);
      /* (12) fin ::= fin fin_m */ yytestcase(yyruleno==12);
      /* (13) fin ::= fin_m */ yytestcase(yyruleno==13);
      /* (14) comma ::= COMMA NL */ yytestcase(yyruleno==14);
      /* (15) comma ::= COMMA */ yytestcase(yyruleno==15);
      /* (27) id_list ::= id_list comma arg */ yytestcase(yyruleno==27);
      /* (28) id_list ::= arg */ yytestcase(yyruleno==28);
      /* (29) def_args ::= */ yytestcase(yyruleno==29);
      /* (30) def_args ::= LP id_list RP */ yytestcase(yyruleno==30);
      /* (74) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==74);
      /* (75) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==75);
      /* (76) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==76);
      /* (77) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==77);
      /* (78) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==78);
      /* (79) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==79);
      /* (114) lambda_args ::= */ yytestcase(yyruleno==114);
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
#line 25 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1679 "vm/parser.c.inc"
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
