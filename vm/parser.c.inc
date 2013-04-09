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
#define YYNOCODE 84
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy74;
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
#define YY_ACTTAB_COUNT (1290)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    41,  249,  117,   11,  242,  237,  236,  186,  234,  185,
 /*    10 */   107,   64,  183,   42,  237,  236,  257,  256,  255,  254,
 /*    20 */   253,  124,  250,  261,   91,   90,  249,  119,  239,  242,
 /*    30 */    30,   29,   28,  140,   76,  107,   45,   41,  133,   27,
 /*    40 */    18,   22,  237,  236,  175,  234,  185,  184,   64,  183,
 /*    50 */    42,  237,  236,  257,  256,  255,  254,  253,  124,  250,
 /*    60 */    60,   91,   90,  249,  118,  239,  242,   30,   29,   28,
 /*    70 */   140,   76,  107,  158,   41,   20,   27,   89,  246,  237,
 /*    80 */   236,   12,  247,  185,  101,   64,  183,   42,   88,  234,
 /*    90 */   257,  256,  255,  254,  253,  124,  250,  240,   91,   90,
 /*   100 */   249,  125,  239,  242,   30,   29,   28,  140,   76,  107,
 /*   110 */   244,   41,  197,   27,  243,   19,  237,  236,  241,  154,
 /*   120 */   234,  203,   64,  157,   42,   20,  238,  257,  256,  255,
 /*   130 */   254,  253,  124,  250,   21,   91,   90,  249,  115,  239,
 /*   140 */   242,   30,   29,   28,  140,   76,  107,  156,   41,   20,
 /*   150 */    27,  166,    4,  237,  236,  188,  232,  234,  202,   64,
 /*   160 */   148,   42,   20,  228,  257,  256,  255,  254,  253,  124,
 /*   170 */   250,  226,   91,   90,  249,  110,  239,  242,   30,   29,
 /*   180 */    28,  140,   76,  107,  147,   41,   20,   27,  224,  222,
 /*   190 */   237,  236,  237,  236,  167,  201,   64,  146,   42,   20,
 /*   200 */   220,  257,  256,  255,  254,  253,  124,  250,  219,   91,
 /*   210 */    90,  249,  121,  239,  242,   30,   29,   28,  140,   76,
 /*   220 */   107,  162,   41,   20,   27,  218,  200,  237,  236,  163,
 /*   230 */   161,   98,   95,   64,  159,   42,   20,  216,  257,  256,
 /*   240 */   255,  254,  253,  124,  250,  196,   91,   90,  215,  152,
 /*   250 */   239,   20,   30,   29,   28,  140,   76,   74,  151,   41,
 /*   260 */    20,   27,  214,  213,  237,  236,  149,  195,   20,  199,
 /*   270 */    64,  174,   42,  100,  191,  257,  256,  255,  254,  253,
 /*   280 */   124,  250,  194,   91,   90,  249,  120,  239,  242,   30,
 /*   290 */    29,   28,  140,   76,  107,   10,   41,  231,   27,   20,
 /*   300 */   234,  237,  236,   17,  193,    9,  173,   64,  234,   42,
 /*   310 */   234,   68,  257,  256,  255,  254,  253,  124,  250,   54,
 /*   320 */    91,   90,  192,   86,  239,   85,   30,   29,   28,  140,
 /*   330 */    76,   16,    8,   41,   87,   27,  234,  234,  237,  236,
 /*   340 */    63,  190,   15,  171,   64,  105,   42,  234,  155,  257,
 /*   350 */   256,  255,  254,  253,  124,  250,  133,   91,   90,  249,
 /*   360 */   122,  239,  242,   30,   29,   28,  140,   76,  107,   34,
 /*   370 */    41,  227,   27,   20,  132,  237,  236,   71,   33,   32,
 /*   380 */    31,   64,  223,   42,   20,   83,  257,  256,  255,  254,
 /*   390 */   253,  124,  250,  176,   91,   90,  130,  235,  239,   41,
 /*   400 */    30,   29,   28,  140,   76,  102,  103,  248,  185,   27,
 /*   410 */    64,  183,   42,  160,   65,  257,  256,  255,  254,  253,
 /*   420 */   124,  250,  128,   91,   90,  245,   41,  239,  233,   30,
 /*   430 */    29,   28,  140,   76,  229,    7,  225,   64,   27,   42,
 /*   440 */   234,  393,  257,  256,  255,  254,  253,  124,  250,  393,
 /*   450 */    91,   90,  393,  331,  239,  393,   30,   29,   28,  140,
 /*   460 */    76,  393,   14,    3,  331,   27,   87,  234,  234,  331,
 /*   470 */   331,  331,  331,  331,  331,  331,  393,  331,  331,  393,
 /*   480 */    44,  331,   51,   50,  393,  163,  161,   98,   95,   37,
 /*   490 */    36,   35,  393,  393,   72,  393,  393,  170,  259,  258,
 /*   500 */   165,  235,  393,  393,    6,  131,  169,  204,   99,  234,
 /*   510 */   393,  116,   13,  393,  393,  230,   72,  234,  221,  170,
 /*   520 */   259,  258,  165,  235,  107,  393,  393,  131,  168,  204,
 /*   530 */    99,  331,  393,  116,    1,  393,    2,  230,  393,  234,
 /*   540 */   221,  234,  331,  393,   87,  393,  107,  331,  331,  331,
 /*   550 */   331,  331,  331,  331,  187,  331,  331,  331,  116,  331,
 /*   560 */   249,  108,  230,  242,  393,  221,  189,  106,  331,  107,
 /*   570 */    86,  107,  393,  331,  331,  331,  331,  331,  331,  331,
 /*   580 */   393,  331,  331,  331,   50,  331,  163,  161,   98,   95,
 /*   590 */   393,  393,  393,  393,  331,  393,   85,  393,  393,  331,
 /*   600 */   331,  331,  331,  331,  331,  331,  393,  331,  331,   57,
 /*   610 */   393,  331,  129,  150,   96,   92,  393,  393,  393,  393,
 /*   620 */   252,  393,   23,  393,  393,  257,  256,  255,  254,  253,
 /*   630 */   251,  250,  212,   94,   93,   57,  116,  239,  249,  126,
 /*   640 */   230,  242,  393,  221,  393,  393,  252,  107,   24,  107,
 /*   650 */   393,  257,  256,  255,  254,  253,  251,  250,  123,   94,
 /*   660 */    93,   57,  230,  239,  393,  221,  393,  249,  114,  393,
 /*   670 */   242,  107,  252,  393,   25,  393,  107,  257,  256,  255,
 /*   680 */   254,  253,  251,  250,  393,   94,   93,   57,  393,  239,
 /*   690 */   393,  393,  393,  249,  113,  393,  242,  393,  252,  393,
 /*   700 */    26,  393,  107,  257,  256,  255,  254,  253,  251,  250,
 /*   710 */   393,   94,   93,   57,  393,  239,  249,  112,  393,  242,
 /*   720 */   393,  393,  393,  393,  252,  107,   43,  393,  393,  257,
 /*   730 */   256,  255,  254,  253,  251,  250,  393,   94,   93,   57,
 /*   740 */   393,  239,  393,  393,  249,  111,  393,  242,  393,  393,
 /*   750 */   252,  393,   40,  107,  393,  257,  256,  255,  254,  253,
 /*   760 */   251,  250,  393,   94,   93,   57,  393,  239,  393,  393,
 /*   770 */   393,  393,  393,  393,  393,  393,  252,  393,   39,  393,
 /*   780 */   393,  257,  256,  255,  254,  253,  251,  250,  393,   94,
 /*   790 */    93,   57,  393,  239,  392,    5,  393,  393,  101,  393,
 /*   800 */   393,  393,  252,  234,   38,  393,  393,  257,  256,  255,
 /*   810 */   254,  253,  251,  250,  393,   94,   93,   41,  393,  239,
 /*   820 */   393,  393,  393,  393,  393,  393,  393,  393,   67,  393,
 /*   830 */    42,  393,  393,  257,  256,  255,  254,  253,  251,  250,
 /*   840 */   393,   91,   90,   57,  393,  239,  393,  393,   53,   52,
 /*   850 */    59,   58,   51,   50,  252,  163,  161,   98,   95,  257,
 /*   860 */   256,  255,  254,  253,  251,  250,  393,   94,   93,  393,
 /*   870 */   393,  239,  393,  393,  127,  393,   42,  393,  393,  257,
 /*   880 */   256,  255,  254,  253,  251,  250,  393,   91,   90,   57,
 /*   890 */   393,  239,  393,  393,   49,   48,   56,   55,   47,   46,
 /*   900 */   164,   66,  150,   97,   92,  257,  256,  255,  254,  253,
 /*   910 */   251,  250,  393,   94,   93,   61,  393,  239,  170,  259,
 /*   920 */   258,  165,  393,  393,  393,  393,  131,  393,  204,   99,
 /*   930 */   393,  393,  116,  393,  393,  393,  230,  393,  393,  221,
 /*   940 */   260,  259,  258,  165,  235,  107,  393,  393,  131,  393,
 /*   950 */   204,   99,  393,  393,  116,  393,  393,  393,  230,  139,
 /*   960 */   235,  221,   70,  393,  393,  144,  204,  107,  172,  116,
 /*   970 */   116,  393,  393,  230,  230,  393,  221,  221,  393,  252,
 /*   980 */   393,  393,  107,  107,  257,  256,  255,  254,  253,  251,
 /*   990 */   250,  393,  393,  393,  139,  393,  393,   62,  138,  139,
 /*  1000 */   235,  204,   81,  393,  393,  116,  204,  393,  393,  230,
 /*  1010 */   116,  393,  221,  393,  230,  393,  393,  221,  107,  139,
 /*  1020 */   235,  393,   79,  107,  139,  235,  204,   77,  393,  393,
 /*  1030 */   116,  204,  393,  393,  230,  116,  393,  221,  393,  230,
 /*  1040 */   393,  393,  221,  107,  139,  235,  393,   75,  107,  393,
 /*  1050 */   393,  204,  393,  393,  393,  116,  393,  393,  393,  230,
 /*  1060 */   139,  235,  221,   73,  393,  393,  393,  204,  107,  393,
 /*  1070 */   393,  116,  393,  393,  393,  230,  393,  393,  221,  393,
 /*  1080 */   393,  393,  249,  109,  107,  242,  393,   84,  189,  104,
 /*  1090 */   393,  107,  153,  235,  393,  393,  181,  180,  393,  204,
 /*  1100 */   179,  178,  393,  116,  145,  393,  393,  230,  116,  393,
 /*  1110 */   221,  393,  230,  182,  393,  221,  107,  177,  393,  393,
 /*  1120 */   217,  107,  393,  393,  116,  143,  393,  393,  230,  116,
 /*  1130 */   393,  221,  393,  230,  393,  393,  221,  107,  393,  393,
 /*  1140 */   142,  393,  107,  393,  116,  393,  393,  393,  230,  393,
 /*  1150 */   141,  221,  211,  393,  116,  393,  116,  107,  230,  393,
 /*  1160 */   230,  221,  210,  221,  209,  393,  116,  107,  116,  107,
 /*  1170 */   230,  393,  230,  221,  393,  221,  393,  393,  208,  107,
 /*  1180 */   207,  107,  116,  393,  116,  393,  230,  393,  230,  221,
 /*  1190 */   206,  221,  393,  393,  116,  107,  393,  107,  230,  393,
 /*  1200 */   393,  221,  205,  393,  393,  393,  116,  107,  393,  393,
 /*  1210 */   230,  393,  393,  221,  393,  393,   82,   80,  393,  107,
 /*  1220 */   116,  116,  393,  393,  230,  230,  393,  221,  221,  393,
 /*  1230 */   393,   78,  198,  107,  107,  116,  116,  393,  393,  230,
 /*  1240 */   230,  393,  221,  221,  393,  393,  137,  136,  107,  107,
 /*  1250 */   116,  116,  393,  393,  230,  230,  393,  221,  221,  393,
 /*  1260 */   393,  393,  135,  107,  107,  393,  116,  134,  393,  393,
 /*  1270 */   230,  116,   69,  221,  393,  230,  116,  393,  221,  107,
 /*  1280 */   230,  393,  393,  221,  107,  393,  393,  393,  393,  107,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     8,   72,   73,   53,   75,   13,   14,   15,   58,   17,
 /*    10 */    81,   19,   20,   21,   13,   14,   24,   25,   26,   27,
 /*    20 */    28,   29,   30,    0,   32,   33,   72,   73,   36,   75,
 /*    30 */    38,   39,   40,   41,   42,   81,    1,    8,   16,   47,
 /*    40 */    53,    3,   13,   14,   22,   58,   17,   18,   19,   20,
 /*    50 */    21,   13,   14,   24,   25,   26,   27,   28,   29,   30,
 /*    60 */    35,   32,   33,   72,   73,   36,   75,   38,   39,   40,
 /*    70 */    41,   42,   81,   74,    8,   76,   47,   21,   19,   13,
 /*    80 */    14,   50,   22,   17,   53,   19,   20,   21,   21,   58,
 /*    90 */    24,   25,   26,   27,   28,   29,   30,   34,   32,   33,
 /*   100 */    72,   73,   36,   75,   38,   39,   40,   41,   42,   81,
 /*   110 */    22,    8,   50,   47,   31,   53,   13,   14,   22,   19,
 /*   120 */    58,   18,   19,   74,   21,   76,   37,   24,   25,   26,
 /*   130 */    27,   28,   29,   30,   59,   32,   33,   72,   73,   36,
 /*   140 */    75,   38,   39,   40,   41,   42,   81,   74,    8,   76,
 /*   150 */    47,   52,   53,   13,   14,   80,   22,   58,   18,   19,
 /*   160 */    74,   21,   76,   22,   24,   25,   26,   27,   28,   29,
 /*   170 */    30,   19,   32,   33,   72,   73,   36,   75,   38,   39,
 /*   180 */    40,   41,   42,   81,   74,    8,   76,   47,   22,   31,
 /*   190 */    13,   14,   13,   14,   15,   18,   19,   74,   21,   76,
 /*   200 */    22,   24,   25,   26,   27,   28,   29,   30,   34,   32,
 /*   210 */    33,   72,   73,   36,   75,   38,   39,   40,   41,   42,
 /*   220 */    81,   74,    8,   76,   47,   22,   19,   13,   14,    9,
 /*   230 */    10,   11,   12,   19,   74,   21,   76,   22,   24,   25,
 /*   240 */    26,   27,   28,   29,   30,   34,   32,   33,   22,   74,
 /*   250 */    36,   76,   38,   39,   40,   41,   42,   43,   74,    8,
 /*   260 */    76,   47,   22,   22,   13,   14,   74,   22,   76,   18,
 /*   270 */    19,   67,   21,   69,   13,   24,   25,   26,   27,   28,
 /*   280 */    29,   30,   22,   32,   33,   72,   73,   36,   75,   38,
 /*   290 */    39,   40,   41,   42,   81,   53,    8,   74,   47,   76,
 /*   300 */    58,   13,   14,   53,   22,   53,   18,   19,   58,   21,
 /*   310 */    58,   19,   24,   25,   26,   27,   28,   29,   30,    4,
 /*   320 */    32,   33,   22,   21,   36,   21,   38,   39,   40,   41,
 /*   330 */    42,   53,   53,    8,   21,   47,   58,   58,   13,   14,
 /*   340 */    82,   78,   53,   18,   19,   59,   21,   58,   37,   24,
 /*   350 */    25,   26,   27,   28,   29,   30,   16,   32,   33,   72,
 /*   360 */    73,   36,   75,   38,   39,   40,   41,   42,   81,   35,
 /*   370 */     8,   74,   47,   76,   19,   13,   14,   70,   44,   45,
 /*   380 */    46,   19,   74,   21,   76,   21,   24,   25,   26,   27,
 /*   390 */    28,   29,   30,   67,   32,   33,   19,   58,   36,    8,
 /*   400 */    38,   39,   40,   41,   42,   59,   71,   22,   17,   47,
 /*   410 */    19,   20,   21,   72,   72,   24,   25,   26,   27,   28,
 /*   420 */    29,   30,   72,   32,   33,   22,    8,   36,   22,   38,
 /*   430 */    39,   40,   41,   42,   22,   53,   22,   19,   47,   21,
 /*   440 */    58,   83,   24,   25,   26,   27,   28,   29,   30,   83,
 /*   450 */    32,   33,   83,    8,   36,   83,   38,   39,   40,   41,
 /*   460 */    42,   83,   53,   53,   19,   47,   21,   58,   58,   24,
 /*   470 */    25,   26,   27,   28,   29,   30,   83,   32,   33,   83,
 /*   480 */    35,   36,    6,    7,   83,    9,   10,   11,   12,   44,
 /*   490 */    45,   46,   83,   83,   51,   83,   83,   54,   55,   56,
 /*   500 */    57,   58,   83,   83,   53,   62,   63,   64,   65,   58,
 /*   510 */    83,   68,   53,   83,   83,   72,   51,   58,   75,   54,
 /*   520 */    55,   56,   57,   58,   81,   83,   83,   62,   63,   64,
 /*   530 */    65,    8,   83,   68,   53,   83,   53,   72,   83,   58,
 /*   540 */    75,   58,   19,   83,   21,   83,   81,   24,   25,   26,
 /*   550 */    27,   28,   29,   30,   64,   32,   33,    8,   68,   36,
 /*   560 */    72,   73,   72,   75,   83,   75,   78,   79,   19,   81,
 /*   570 */    21,   81,   83,   24,   25,   26,   27,   28,   29,   30,
 /*   580 */    83,   32,   33,    8,    7,   36,    9,   10,   11,   12,
 /*   590 */    83,   83,   83,   83,   19,   83,   21,   83,   83,   24,
 /*   600 */    25,   26,   27,   28,   29,   30,   83,   32,   33,    8,
 /*   610 */    83,   36,    9,   10,   11,   12,   83,   83,   83,   83,
 /*   620 */    19,   83,   21,   83,   83,   24,   25,   26,   27,   28,
 /*   630 */    29,   30,   64,   32,   33,    8,   68,   36,   72,   73,
 /*   640 */    72,   75,   83,   75,   83,   83,   19,   81,   21,   81,
 /*   650 */    83,   24,   25,   26,   27,   28,   29,   30,   68,   32,
 /*   660 */    33,    8,   72,   36,   83,   75,   83,   72,   73,   83,
 /*   670 */    75,   81,   19,   83,   21,   83,   81,   24,   25,   26,
 /*   680 */    27,   28,   29,   30,   83,   32,   33,    8,   83,   36,
 /*   690 */    83,   83,   83,   72,   73,   83,   75,   83,   19,   83,
 /*   700 */    21,   83,   81,   24,   25,   26,   27,   28,   29,   30,
 /*   710 */    83,   32,   33,    8,   83,   36,   72,   73,   83,   75,
 /*   720 */    83,   83,   83,   83,   19,   81,   21,   83,   83,   24,
 /*   730 */    25,   26,   27,   28,   29,   30,   83,   32,   33,    8,
 /*   740 */    83,   36,   83,   83,   72,   73,   83,   75,   83,   83,
 /*   750 */    19,   83,   21,   81,   83,   24,   25,   26,   27,   28,
 /*   760 */    29,   30,   83,   32,   33,    8,   83,   36,   83,   83,
 /*   770 */    83,   83,   83,   83,   83,   83,   19,   83,   21,   83,
 /*   780 */    83,   24,   25,   26,   27,   28,   29,   30,   83,   32,
 /*   790 */    33,    8,   83,   36,   49,   50,   83,   83,   53,   83,
 /*   800 */    83,   83,   19,   58,   21,   83,   83,   24,   25,   26,
 /*   810 */    27,   28,   29,   30,   83,   32,   33,    8,   83,   36,
 /*   820 */    83,   83,   83,   83,   83,   83,   83,   83,   19,   83,
 /*   830 */    21,   83,   83,   24,   25,   26,   27,   28,   29,   30,
 /*   840 */    83,   32,   33,    8,   83,   36,   83,   83,    2,    3,
 /*   850 */     4,    5,    6,    7,   19,    9,   10,   11,   12,   24,
 /*   860 */    25,   26,   27,   28,   29,   30,   83,   32,   33,   83,
 /*   870 */    83,   36,   83,   83,   19,   83,   21,   83,   83,   24,
 /*   880 */    25,   26,   27,   28,   29,   30,   83,   32,   33,    8,
 /*   890 */    83,   36,   83,   83,    2,    3,    4,    5,    6,    7,
 /*   900 */    19,    9,   10,   11,   12,   24,   25,   26,   27,   28,
 /*   910 */    29,   30,   83,   32,   33,   51,   83,   36,   54,   55,
 /*   920 */    56,   57,   83,   83,   83,   83,   62,   83,   64,   65,
 /*   930 */    83,   83,   68,   83,   83,   83,   72,   83,   83,   75,
 /*   940 */    54,   55,   56,   57,   58,   81,   83,   83,   62,   83,
 /*   950 */    64,   65,   83,   83,   68,   83,   83,   83,   72,   57,
 /*   960 */    58,   75,   60,   83,   83,   64,   64,   81,   66,   68,
 /*   970 */    68,   83,   83,   72,   72,   83,   75,   75,   83,   19,
 /*   980 */    83,   83,   81,   81,   24,   25,   26,   27,   28,   29,
 /*   990 */    30,   83,   83,   83,   57,   83,   83,   60,   61,   57,
 /*  1000 */    58,   64,   60,   83,   83,   68,   64,   83,   83,   72,
 /*  1010 */    68,   83,   75,   83,   72,   83,   83,   75,   81,   57,
 /*  1020 */    58,   83,   60,   81,   57,   58,   64,   60,   83,   83,
 /*  1030 */    68,   64,   83,   83,   72,   68,   83,   75,   83,   72,
 /*  1040 */    83,   83,   75,   81,   57,   58,   83,   60,   81,   83,
 /*  1050 */    83,   64,   83,   83,   83,   68,   83,   83,   83,   72,
 /*  1060 */    57,   58,   75,   60,   83,   83,   83,   64,   81,   83,
 /*  1070 */    83,   68,   83,   83,   83,   72,   83,   83,   75,   83,
 /*  1080 */    83,   83,   72,   73,   81,   75,   83,   77,   78,   79,
 /*  1090 */    83,   81,   57,   58,   83,   83,    2,    3,   83,   64,
 /*  1100 */     6,    7,   83,   68,   64,   83,   83,   72,   68,   83,
 /*  1110 */    75,   83,   72,   19,   83,   75,   81,   23,   83,   83,
 /*  1120 */    64,   81,   83,   83,   68,   64,   83,   83,   72,   68,
 /*  1130 */    83,   75,   83,   72,   83,   83,   75,   81,   83,   83,
 /*  1140 */    64,   83,   81,   83,   68,   83,   83,   83,   72,   83,
 /*  1150 */    64,   75,   64,   83,   68,   83,   68,   81,   72,   83,
 /*  1160 */    72,   75,   64,   75,   64,   83,   68,   81,   68,   81,
 /*  1170 */    72,   83,   72,   75,   83,   75,   83,   83,   64,   81,
 /*  1180 */    64,   81,   68,   83,   68,   83,   72,   83,   72,   75,
 /*  1190 */    64,   75,   83,   83,   68,   81,   83,   81,   72,   83,
 /*  1200 */    83,   75,   64,   83,   83,   83,   68,   81,   83,   83,
 /*  1210 */    72,   83,   83,   75,   83,   83,   64,   64,   83,   81,
 /*  1220 */    68,   68,   83,   83,   72,   72,   83,   75,   75,   83,
 /*  1230 */    83,   64,   64,   81,   81,   68,   68,   83,   83,   72,
 /*  1240 */    72,   83,   75,   75,   83,   83,   64,   64,   81,   81,
 /*  1250 */    68,   68,   83,   83,   72,   72,   83,   75,   75,   83,
 /*  1260 */    83,   83,   64,   81,   81,   83,   68,   64,   83,   83,
 /*  1270 */    72,   68,   64,   75,   83,   72,   68,   83,   75,   81,
 /*  1280 */    72,   83,   83,   75,   81,   83,   83,   83,   83,   81,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (166)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (1094)
static const short yy_shift_ofst[] = {
 /*     0 */     1,   66,   66,   29,   -8,  391,  325,  362,  362,  362,
 /*    10 */   362,  362,  418,  288,  251,  214,  177,  140,  103,  362,
 /*    20 */   881,  881,  809,  809,  809,  809,  809,  809,  809,  809,
 /*    30 */   809,  809,  809,  809,  809,  809,  809,  809,  809,  809,
 /*    40 */   809,  809,  809,  809,  809,  809,  783,  757,  731,  705,
 /*    50 */   679,  653,  627,  601,  855,  835,  835,  835,  835,  835,
 /*    60 */   835,  179,    1,    1,  445,  575,  549,  523,   38,    1,
 /*    70 */     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*    80 */     1,    1,    1,  377,  340,  414,  412,  406,  403,  385,
 /*    90 */    -9,   -9,   -9,   -9,   -9,   -9,  960,  960,  960, 1094,
 /*   100 */    22,    1,  377,  364,  340,  355,  340,  311,  846,  846,
 /*   110 */   846,  846,  846,  846,  846,  846,  892,  846,  476,  476,
 /*   120 */   476,  476,  577,  603,  334,  220,  220,  313,  304,  302,
 /*   130 */   315,  292,   25,  261,  300,  282,  260,  245,  211,   35,
 /*   140 */   207,  241,  240,  226,  215,  203,  174,  178,  158,  166,
 /*   150 */   152,  141,  134,   35,   89,  100,   63,   96,   83,   88,
 /*   160 */    67,   59,   60,   56,   25,   35,   23,
};
#define YY_REDUCE_USE_DFLT (-72)
#define YY_REDUCE_COUNT (107)
#define YY_REDUCE_MIN   (-71)
#define YY_REDUCE_MAX   (1208)
static const short yy_reduce_ofst[] = {
 /*     0 */   745,  465,  443,  886,  886,  864,  902, 1003,  987,  967,
 /*    10 */   962,  942,  937, 1035, 1035, 1035, 1035, 1035, 1035, 1035,
 /*    20 */  1010,  488, 1208, 1203, 1198, 1183, 1182, 1168, 1167, 1153,
 /*    30 */  1152, 1138, 1126, 1116, 1114, 1100, 1098, 1088, 1086, 1076,
 /*    40 */  1061, 1056, 1040,  901,  568,  490,  672,  644,  621,  595,
 /*    50 */   566,  287,  213,  139,  590,  102,   65,   28,   -9,  -46,
 /*    60 */   -71,   99,   62,   31,  223,  308,  297,  223,  483,  481,
 /*    70 */   459,  451,  410,  409,  382,  289,  279,  278,  252,  250,
 /*    80 */   242,  -13,  -50,  204,   75,  192,  184,  175,  160,  147,
 /*    90 */   123,  110,   86,   73,   49,   -1,  350,  342,  341,  335,
 /*   100 */   346,  339,  326,  307,  286,  263,  286,  258,
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
  "WHILE",         "IMPORT",        "TRY",           "RESCUE",      
  "OP2_SET",       "OP1_SET",       "OP0_SET",       "RAISE",       
  "error",         "program",       "opt_fin",       "l1",          
  "last_fin",      "fin",           "l1e",           "class",       
  "def",           "stmt",          "fin_m",         "comma",       
  "seq",           "delim_seq",     "class_start",   "class_body",  
  "s2",            "def_start",     "def_body",      "arg",         
  "np_recv",       "id_list",       "def_args",      "def_name",    
  "lit",           "np_arg",        "np_arg_list",   "lambda",      
  "np_arg_list_start",  "np_arg_list_elems",  "np_kw_arg",     "np_kw_arg_list_elems",
  "np_opt_kw_arg_list",  "lambda_start",  "lambda_args", 
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
 /* 119 */ "stmt ::= IMPORT ID",
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
  { 49, 3 },
  { 51, 3 },
  { 51, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 58, 1 },
  { 58, 1 },
  { 50, 0 },
  { 50, 1 },
  { 52, 1 },
  { 52, 2 },
  { 53, 2 },
  { 53, 1 },
  { 59, 2 },
  { 59, 1 },
  { 60, 3 },
  { 60, 1 },
  { 61, 2 },
  { 62, 1 },
  { 63, 3 },
  { 55, 4 },
  { 55, 6 },
  { 65, 1 },
  { 66, 3 },
  { 67, 1 },
  { 67, 3 },
  { 69, 3 },
  { 69, 1 },
  { 70, 0 },
  { 70, 3 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 56, 5 },
  { 56, 5 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 73, 1 },
  { 73, 3 },
  { 73, 5 },
  { 73, 3 },
  { 73, 5 },
  { 73, 3 },
  { 73, 5 },
  { 73, 3 },
  { 73, 5 },
  { 73, 3 },
  { 73, 3 },
  { 73, 2 },
  { 73, 4 },
  { 73, 5 },
  { 73, 3 },
  { 73, 3 },
  { 73, 5 },
  { 73, 6 },
  { 73, 2 },
  { 73, 1 },
  { 73, 4 },
  { 73, 3 },
  { 73, 3 },
  { 76, 0 },
  { 77, 3 },
  { 77, 1 },
  { 78, 3 },
  { 79, 3 },
  { 79, 1 },
  { 80, 0 },
  { 80, 2 },
  { 74, 3 },
  { 74, 2 },
  { 68, 1 },
  { 68, 3 },
  { 68, 4 },
  { 68, 2 },
  { 68, 4 },
  { 68, 5 },
  { 68, 3 },
  { 68, 3 },
  { 68, 5 },
  { 68, 6 },
  { 68, 1 },
  { 68, 3 },
  { 68, 3 },
  { 68, 4 },
  { 68, 3 },
  { 64, 3 },
  { 64, 4 },
  { 64, 2 },
  { 64, 3 },
  { 64, 3 },
  { 64, 5 },
  { 64, 3 },
  { 64, 5 },
  { 64, 3 },
  { 64, 5 },
  { 64, 3 },
  { 64, 5 },
  { 64, 3 },
  { 64, 1 },
  { 64, 2 },
  { 57, 1 },
  { 57, 3 },
  { 81, 1 },
  { 82, 3 },
  { 82, 0 },
  { 75, 5 },
  { 57, 6 },
  { 57, 6 },
  { 57, 6 },
  { 57, 2 },
  { 57, 9 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 57, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy74.a)); }
#line 1232 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 34 "vm/parser.lm"
{ yygotominor.yy74.a = S->seq(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
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
{ yygotominor.yy74.a = yymsp[0].minor.yy74.a; }
#line 1253 "vm/parser.c.inc"
        break;
      case 18: /* delim_seq ::= seq opt_fin */
      case 94: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==94);
#line 59 "vm/parser.lm"
{ yygotominor.yy74.a = yymsp[-1].minor.yy74.a; }
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
{ yygotominor.yy74.a = yymsp[-2].minor.yy74.a; }
#line 1270 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy74.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy74.a);
             }
#line 1277 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID LT s2 fin class_body */
#line 68 "vm/parser.lm"
{
               yygotominor.yy74.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a);
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
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1299 "vm/parser.c.inc"
        break;
      case 31: /* def_name ::= ID */
      case 32: /* def_name ::= OP0 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= LT */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= OP1 */ yytestcase(yyruleno==34);
      case 35: /* def_name ::= OP2 */ yytestcase(yyruleno==35);
      case 36: /* def_name ::= SQUARE */ yytestcase(yyruleno==36);
#line 84 "vm/parser.lm"
{ yygotominor.yy74.s = yymsp[0].minor.yy0.s; }
#line 1309 "vm/parser.c.inc"
        break;
      case 37: /* def ::= def_start def_name def_args fin def_body */
#line 92 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_def(yymsp[-3].minor.yy74.s, yymsp[0].minor.yy74.a);
            }
#line 1316 "vm/parser.c.inc"
        break;
      case 38: /* def ::= def_start def_name def_args fin END */
#line 95 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_def(yymsp[-3].minor.yy74.s, S->ast_nil());
            }
#line 1323 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= NUM */
#line 99 "vm/parser.lm"
{ yygotominor.yy74.a = S->number(yymsp[0].minor.yy0.i); }
#line 1328 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= NIL */
#line 100 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_nil();  }
#line 1333 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= TRUE */
#line 101 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_true();  }
#line 1338 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= FALSE */
#line 102 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_false(); }
#line 1343 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= SELF */
#line 103 "vm/parser.lm"
{ yygotominor.yy74.a = S->self(); }
#line 1348 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= ID */
#line 104 "vm/parser.lm"
{ yygotominor.yy74.a = S->named(yymsp[0].minor.yy0.s); }
#line 1353 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= IVAR */
#line 105 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1358 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= LITSTR */
#line 106 "vm/parser.lm"
{ yygotominor.yy74.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1363 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP0 np_arg */
      case 50: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==50);
      case 52: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==52);
      case 99: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==99);
      case 101: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==101);
      case 103: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==103);
#line 111 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1373 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 51: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==51);
      case 53: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==53);
      case 100: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==100);
      case 102: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==102);
      case 104: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==104);
#line 113 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1383 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg OP2 np_arg */
      case 105: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==105);
#line 126 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1389 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 106: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==106);
#line 128 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1395 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg CAST np_arg */
      case 98: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==98);
#line 131 "vm/parser.lm"
{ yygotominor.yy74.a = S->cast(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1401 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg NEQUAL np_arg */
      case 107: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==107);
#line 133 "vm/parser.lm"
{ yygotominor.yy74.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a)); }
#line 1407 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg DOT */
      case 83: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==83);
#line 134 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(yymsp[-1].minor.yy74.a, yymsp[0].minor.yy0.s); }
#line 1413 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg DOT LP RP */
      case 84: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==84);
#line 135 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(yymsp[-3].minor.yy74.a, yymsp[-2].minor.yy0.s); }
#line 1419 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 85: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==85);
#line 137 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-4].minor.yy74.a, yymsp[-3].minor.yy0.s); }
#line 1425 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg DCOLON ID */
      case 86: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==86);
#line 138 "vm/parser.lm"
{ yygotominor.yy74.a = S->dcolon(yymsp[-2].minor.yy74.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1431 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 87: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==87);
#line 141 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1437 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 88: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1443 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect_args(yymsp[-5].minor.yy74.a, yymsp[-3].minor.yy74.a); }
#line 1449 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= NOT np_arg */
      case 109: /* s2 ::= NOT s2 */ yytestcase(yyruleno==109);
#line 146 "vm/parser.lm"
{ yygotominor.yy74.a = S->not_(yymsp[0].minor.yy74.a); }
#line 1455 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 93: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==93);
#line 149 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-3].minor.yy74.a, "[]"); }
#line 1461 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 91: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==91);
#line 151 "vm/parser.lm"
{ yygotominor.yy74.a = S->tuple(); }
#line 1467 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= DICT_START np_arg_list RB */
      case 92: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==92);
#line 152 "vm/parser.lm"
{ yygotominor.yy74.a = S->dict(); }
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
{ S->add_arg(yymsp[0].minor.yy74.a); }
#line 1484 "vm/parser.c.inc"
        break;
      case 73: /* np_kw_arg ::= ID EQUAL np_arg */
#line 158 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1489 "vm/parser.c.inc"
        break;
      case 81: /* np_recv ::= ID LP RP */
#line 170 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1494 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= ID LP np_arg_list RP */
#line 171 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1499 "vm/parser.c.inc"
        break;
      case 95: /* s2 ::= np_recv DOT np_arg_list */
#line 189 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-2].minor.yy74.a, yymsp[-1].minor.yy0.s); }
#line 1504 "vm/parser.c.inc"
        break;
      case 96: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 191 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect_args(yymsp[-3].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1509 "vm/parser.c.inc"
        break;
      case 97: /* s2 ::= ID np_arg_list */
#line 192 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1514 "vm/parser.c.inc"
        break;
      case 111: /* stmt ::= stmt AND s2 */
#line 208 "vm/parser.lm"
{ yygotominor.yy74.a = S->and_(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
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
{ yygotominor.yy74.a = S->lambda(yymsp[-1].minor.yy74.a); }
#line 1534 "vm/parser.c.inc"
        break;
      case 116: /* stmt ::= IF s2 fin seq fin END */
#line 221 "vm/parser.lm"
{ yygotominor.yy74.a = S->if_cond(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1539 "vm/parser.c.inc"
        break;
      case 117: /* stmt ::= UNLESS s2 fin seq fin END */
#line 222 "vm/parser.lm"
{ yygotominor.yy74.a = S->unless(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1544 "vm/parser.c.inc"
        break;
      case 118: /* stmt ::= WHILE s2 fin seq fin END */
#line 223 "vm/parser.lm"
{ yygotominor.yy74.a = S->while_(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1549 "vm/parser.c.inc"
        break;
      case 119: /* stmt ::= IMPORT ID */
#line 227 "vm/parser.lm"
{ yygotominor.yy74.a = S->import(yymsp[0].minor.yy0.s); }
#line 1554 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 229 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_try(yymsp[-6].minor.yy74.a, yymsp[-2].minor.yy74.a);
            }
#line 1561 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= ID EQUAL s2 */
#line 233 "vm/parser.lm"
{ yygotominor.yy74.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1566 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= ID OP2_SET s2 */
      case 123: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==123);
      case 124: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==124);
#line 234 "vm/parser.lm"
{ yygotominor.yy74.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1573 "vm/parser.c.inc"
        break;
      case 125: /* stmt ::= IVAR EQUAL s2 */
#line 237 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1578 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= IVAR OP2_SET s2 */
      case 127: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==127);
      case 128: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==128);
#line 239 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1585 "vm/parser.c.inc"
        break;
      case 129: /* stmt ::= RAISE s2 */
#line 244 "vm/parser.lm"
{ yygotominor.yy74.a = S->raise(yymsp[0].minor.yy74.a); }
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
