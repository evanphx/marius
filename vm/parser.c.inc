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
#define YYNOCODE 86
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy128;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 263
#define YYNRULE 131
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
#define YY_ACTTAB_COUNT (1239)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    41,  251,  117,   11,  244,  239,  238,  188,  236,  187,
 /*    10 */   107,   64,  185,   42,  239,  238,  259,  258,  257,  256,
 /*    20 */   255,  124,  252,  263,   91,   90,  251,  119,  241,  244,
 /*    30 */    30,   29,   28,  142,   41,  107,   76,   18,   22,  239,
 /*    40 */   238,   27,  236,  187,  186,   64,  185,   42,  239,  238,
 /*    50 */   259,  258,  257,  256,  255,  124,  252,   60,   91,   90,
 /*    60 */   251,  118,  241,  244,   30,   29,   28,  142,   41,  107,
 /*    70 */    76,   10,  133,  239,  238,   27,  236,  187,  177,   64,
 /*    80 */   185,   42,   45,   89,  259,  258,  257,  256,  255,  124,
 /*    90 */   252,   21,   91,   90,  249,  248,  241,   41,   30,   29,
 /*   100 */    28,  142,  239,  238,   76,  168,    4,  205,   64,   27,
 /*   110 */    42,  236,  190,  259,  258,  257,  256,  255,  124,  252,
 /*   120 */    88,   91,   90,  246,  245,  241,   41,   30,   29,   28,
 /*   130 */   142,  239,  238,   76,  243,   17,  204,   64,   27,   42,
 /*   140 */   236,  242,  259,  258,  257,  256,  255,  124,  252,  156,
 /*   150 */    91,   90,  240,  234,  241,   41,   30,   29,   28,  142,
 /*   160 */   239,  238,   76,  230,    9,  203,   64,   27,   42,  236,
 /*   170 */   228,  259,  258,  257,  256,  255,  124,  252,  226,   91,
 /*   180 */    90,   34,  222,  241,   41,   30,   29,   28,  142,  239,
 /*   190 */   238,   76,   33,   32,   31,   64,   27,   42,  221,  224,
 /*   200 */   259,  258,  257,  256,  255,  124,  252,  220,   91,   90,
 /*   210 */   218,  217,  241,   41,   30,   29,   28,  142,  239,  238,
 /*   220 */    76,   74,   16,  201,   64,   27,   42,  236,  216,  259,
 /*   230 */   258,  257,  256,  255,  124,  252,  215,   91,   90,  141,
 /*   240 */   202,  241,   41,   30,   29,   28,  142,  239,  238,   76,
 /*   250 */   140,    8,  175,   64,   27,   42,  236,  198,  259,  258,
 /*   260 */   257,  256,  255,  124,  252,  197,   91,   90,  196,  195,
 /*   270 */   241,   41,   30,   29,   28,  142,  239,  238,   76,  194,
 /*   280 */    15,  173,   64,   27,   42,  236,  193,  259,  258,  257,
 /*   290 */   256,  255,  124,  252,   68,   91,   90,   54,  157,  241,
 /*   300 */    41,   30,   29,   28,  142,  239,  238,   76,  160,    7,
 /*   310 */    20,   64,   27,   42,  236,   86,  259,  258,  257,  256,
 /*   320 */   255,  124,  252,   85,   91,   90,   41,   87,  241,   14,
 /*   330 */    30,   29,   28,  142,  236,  187,   76,   64,  185,   42,
 /*   340 */    63,   27,  259,  258,  257,  256,  255,  124,  252,  133,
 /*   350 */    91,   90,   41,  159,  241,   20,   30,   29,   28,  142,
 /*   360 */   105,  192,   76,   64,  158,   42,   20,   27,  259,  258,
 /*   370 */   257,  256,  255,  124,  252,  132,   91,   90,  333,  150,
 /*   380 */   241,   20,   30,   29,   28,  142,   83,   71,   76,  333,
 /*   390 */   149,   87,   20,   27,  333,  333,  333,  333,  333,  333,
 /*   400 */   333,   12,  333,  333,  101,   44,  333,  178,   72,  236,
 /*   410 */   130,  172,  261,  260,  167,  237,   37,   36,   35,  131,
 /*   420 */   171,  206,   99,  199,  237,  116,   19,  102,  162,  232,
 /*   430 */    72,  236,  223,  172,  261,  260,  167,  237,  107,  250,
 /*   440 */   103,  131,  170,  206,   99,  333,   65,  116,  395,    5,
 /*   450 */   128,  232,  101,  176,  223,  100,  333,  236,   87,  396,
 /*   460 */   107,  333,  333,  333,  333,  333,  333,  333,  247,  333,
 /*   470 */   333,  333,  235,  333,  251,  109,  231,  244,  227,   84,
 /*   480 */   191,  104,  333,  107,   86,  396,  396,  333,  333,  333,
 /*   490 */   333,  333,  333,  333,  396,  333,  333,  333,  396,  333,
 /*   500 */    51,   50,  396,  165,  163,   98,   95,  148,  333,   20,
 /*   510 */    85,  396,  396,  333,  333,  333,  333,  333,  333,  333,
 /*   520 */   396,  333,  333,   57,  396,  333,  251,  108,  396,  244,
 /*   530 */   396,  396,  191,  106,  254,  107,   23,  396,  396,  259,
 /*   540 */   258,  257,  256,  255,  253,  252,  396,   94,   93,   57,
 /*   550 */    50,  241,  165,  163,   98,   95,  396,  239,  238,  169,
 /*   560 */   254,  164,   24,   20,  396,  259,  258,  257,  256,  255,
 /*   570 */   253,  252,  189,   94,   93,   57,  116,  241,  251,  125,
 /*   580 */   232,  244,  396,  223,  396,    3,  254,  107,   25,  107,
 /*   590 */   236,  259,  258,  257,  256,  255,  253,  252,  396,   94,
 /*   600 */    93,   57,  396,  241,  165,  163,   98,   95,  396,  161,
 /*   610 */   396,   20,  254,  154,   26,   20,  396,  259,  258,  257,
 /*   620 */   256,  255,  253,  252,  396,   94,   93,   57,  396,  241,
 /*   630 */   129,  152,   96,   92,  153,  151,   20,   20,  254,  233,
 /*   640 */    43,   20,  396,  259,  258,  257,  256,  255,  253,  252,
 /*   650 */   214,   94,   93,   57,  116,  241,  251,  115,  232,  244,
 /*   660 */   396,  223,  396,  396,  254,  107,   40,  107,  396,  259,
 /*   670 */   258,  257,  256,  255,  253,  252,  396,   94,   93,   57,
 /*   680 */   396,  241,  251,  110,  396,  244,  396,  396,    6,   13,
 /*   690 */   254,  107,   39,  236,  236,  259,  258,  257,  256,  255,
 /*   700 */   253,  252,  123,   94,   93,   57,  232,  241,    1,  223,
 /*   710 */   396,  396,    2,  236,  396,  107,  254,  236,   38,  396,
 /*   720 */   396,  259,  258,  257,  256,  255,  253,  252,  146,   94,
 /*   730 */    93,   41,  116,  241,  251,  121,  232,  244,  396,  223,
 /*   740 */   396,  396,   67,  107,   42,  107,  396,  259,  258,  257,
 /*   750 */   256,  255,  253,  252,  396,   91,   90,   57,  229,  241,
 /*   760 */    20,  396,   53,   52,   59,   58,   51,   50,  254,  165,
 /*   770 */   163,   98,   95,  259,  258,  257,  256,  255,  253,  252,
 /*   780 */   396,   94,   93,  396,  225,  241,   20,  396,  127,  396,
 /*   790 */    42,  396,  396,  259,  258,  257,  256,  255,  253,  252,
 /*   800 */   396,   91,   90,   57,  396,  241,  396,  396,   49,   48,
 /*   810 */    56,   55,   47,   46,  166,   66,  152,   97,   92,  259,
 /*   820 */   258,  257,  256,  255,  253,  252,  396,   94,   93,   61,
 /*   830 */   396,  241,  172,  261,  260,  167,  396,  396,  251,  120,
 /*   840 */   131,  244,  206,   99,  396,  396,  116,  107,  396,  396,
 /*   850 */   232,  396,  396,  223,  262,  261,  260,  167,  237,  107,
 /*   860 */   251,  122,  131,  244,  206,   99,  396,  396,  116,  107,
 /*   870 */   396,  396,  232,  139,  237,  223,   70,  396,  396,  147,
 /*   880 */   206,  107,  174,  116,  116,  396,  396,  232,  232,  396,
 /*   890 */   223,  223,  396,  254,  396,  396,  107,  107,  259,  258,
 /*   900 */   257,  256,  255,  253,  252,  396,  139,  396,  396,   62,
 /*   910 */   138,  396,  396,  206,  396,  396,  396,  116,  396,  396,
 /*   920 */   396,  232,  139,  237,  223,   81,  396,  396,  396,  206,
 /*   930 */   107,  396,  396,  116,  396,  396,  396,  232,  396,  396,
 /*   940 */   223,  139,  237,  396,   79,  396,  107,  396,  206,  183,
 /*   950 */   182,  396,  116,  181,  180,  396,  232,  139,  237,  223,
 /*   960 */    77,  396,  396,  396,  206,  107,  184,  396,  116,  396,
 /*   970 */   179,  396,  232,  139,  237,  223,   75,  396,  396,  396,
 /*   980 */   206,  107,  396,  396,  116,  396,  396,  396,  232,  139,
 /*   990 */   237,  223,   73,  396,  396,  396,  206,  107,  396,  396,
 /*  1000 */   116,  155,  237,  396,  232,  396,  396,  223,  206,  396,
 /*  1010 */   396,  396,  116,  107,  396,  396,  232,  396,  396,  223,
 /*  1020 */   219,  396,  396,  396,  116,  107,  396,  396,  232,  396,
 /*  1030 */   396,  223,  145,  396,  396,  396,  116,  107,  396,  396,
 /*  1040 */   232,  396,  144,  223,  396,  396,  116,  143,  396,  107,
 /*  1050 */   232,  116,  396,  223,  396,  232,  396,  213,  223,  107,
 /*  1060 */   396,  116,  396,  396,  107,  232,  396,  212,  223,  211,
 /*  1070 */   396,  116,  396,  116,  107,  232,  396,  232,  223,  210,
 /*  1080 */   223,  396,  396,  116,  107,  396,  107,  232,  396,  396,
 /*  1090 */   223,  209,  396,  396,  396,  116,  107,  396,  396,  232,
 /*  1100 */   396,  396,  223,  208,  396,  396,  396,  116,  107,  396,
 /*  1110 */   396,  232,  396,  207,  223,  396,  396,  116,   82,  396,
 /*  1120 */   107,  232,  116,  396,  223,  396,  232,  396,   80,  223,
 /*  1130 */   107,  396,  116,  396,  396,  107,  232,  396,   78,  223,
 /*  1140 */   200,  396,  116,  396,  116,  107,  232,  396,  232,  223,
 /*  1150 */   137,  223,  396,  396,  116,  107,  396,  107,  232,  396,
 /*  1160 */   396,  223,  136,  396,  396,  396,  116,  107,  396,  396,
 /*  1170 */   232,  396,  396,  223,  135,  396,  396,  396,  116,  107,
 /*  1180 */   396,  396,  232,  396,  134,  223,  396,  396,  116,   69,
 /*  1190 */   396,  107,  232,  116,  396,  223,  396,  232,  396,  396,
 /*  1200 */   223,  107,  396,  396,  251,  126,  107,  244,  396,  396,
 /*  1210 */   396,  251,  114,  107,  244,  251,  113,  396,  244,  396,
 /*  1220 */   107,  396,  396,  396,  107,  251,  112,  396,  244,  251,
 /*  1230 */   111,  396,  244,  396,  107,  396,  396,  396,  107,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     8,   74,   75,   55,   77,   13,   14,   15,   60,   17,
 /*    10 */    83,   19,   20,   21,   13,   14,   24,   25,   26,   27,
 /*    20 */    28,   29,   30,    0,   32,   33,   74,   75,   36,   77,
 /*    30 */    38,   39,   40,   41,    8,   83,   44,   55,    3,   13,
 /*    40 */    14,   49,   60,   17,   18,   19,   20,   21,   13,   14,
 /*    50 */    24,   25,   26,   27,   28,   29,   30,   35,   32,   33,
 /*    60 */    74,   75,   36,   77,   38,   39,   40,   41,    8,   83,
 /*    70 */    44,   55,   16,   13,   14,   49,   60,   17,   22,   19,
 /*    80 */    20,   21,    1,   21,   24,   25,   26,   27,   28,   29,
 /*    90 */    30,   61,   32,   33,   22,   19,   36,    8,   38,   39,
 /*   100 */    40,   41,   13,   14,   44,   54,   55,   18,   19,   49,
 /*   110 */    21,   60,   82,   24,   25,   26,   27,   28,   29,   30,
 /*   120 */    21,   32,   33,   22,   31,   36,    8,   38,   39,   40,
 /*   130 */    41,   13,   14,   44,   22,   55,   18,   19,   49,   21,
 /*   140 */    60,   34,   24,   25,   26,   27,   28,   29,   30,   19,
 /*   150 */    32,   33,   37,   22,   36,    8,   38,   39,   40,   41,
 /*   160 */    13,   14,   44,   22,   55,   18,   19,   49,   21,   60,
 /*   170 */    19,   24,   25,   26,   27,   28,   29,   30,   22,   32,
 /*   180 */    33,   35,   22,   36,    8,   38,   39,   40,   41,   13,
 /*   190 */    14,   44,   46,   47,   48,   19,   49,   21,   34,   31,
 /*   200 */    24,   25,   26,   27,   28,   29,   30,   22,   32,   33,
 /*   210 */    22,   22,   36,    8,   38,   39,   40,   41,   13,   14,
 /*   220 */    44,   45,   55,   18,   19,   49,   21,   60,   22,   24,
 /*   230 */    25,   26,   27,   28,   29,   30,   22,   32,   33,   42,
 /*   240 */    19,   36,    8,   38,   39,   40,   41,   13,   14,   44,
 /*   250 */    43,   55,   18,   19,   49,   21,   60,   34,   24,   25,
 /*   260 */    26,   27,   28,   29,   30,   22,   32,   33,   22,   22,
 /*   270 */    36,    8,   38,   39,   40,   41,   13,   14,   44,   22,
 /*   280 */    55,   18,   19,   49,   21,   60,   13,   24,   25,   26,
 /*   290 */    27,   28,   29,   30,   19,   32,   33,    4,   37,   36,
 /*   300 */     8,   38,   39,   40,   41,   13,   14,   44,   76,   55,
 /*   310 */    78,   19,   49,   21,   60,   21,   24,   25,   26,   27,
 /*   320 */    28,   29,   30,   21,   32,   33,    8,   21,   36,   55,
 /*   330 */    38,   39,   40,   41,   60,   17,   44,   19,   20,   21,
 /*   340 */    84,   49,   24,   25,   26,   27,   28,   29,   30,   16,
 /*   350 */    32,   33,    8,   76,   36,   78,   38,   39,   40,   41,
 /*   360 */    61,   80,   44,   19,   76,   21,   78,   49,   24,   25,
 /*   370 */    26,   27,   28,   29,   30,   19,   32,   33,    8,   76,
 /*   380 */    36,   78,   38,   39,   40,   41,   21,   72,   44,   19,
 /*   390 */    76,   21,   78,   49,   24,   25,   26,   27,   28,   29,
 /*   400 */    30,   52,   32,   33,   55,   35,   36,   69,   53,   60,
 /*   410 */    19,   56,   57,   58,   59,   60,   46,   47,   48,   64,
 /*   420 */    65,   66,   67,   52,   60,   70,   55,   61,   74,   74,
 /*   430 */    53,   60,   77,   56,   57,   58,   59,   60,   83,   22,
 /*   440 */    73,   64,   65,   66,   67,    8,   74,   70,   51,   52,
 /*   450 */    74,   74,   55,   69,   77,   71,   19,   60,   21,   85,
 /*   460 */    83,   24,   25,   26,   27,   28,   29,   30,   22,   32,
 /*   470 */    33,    8,   22,   36,   74,   75,   22,   77,   22,   79,
 /*   480 */    80,   81,   19,   83,   21,   85,   85,   24,   25,   26,
 /*   490 */    27,   28,   29,   30,   85,   32,   33,    8,   85,   36,
 /*   500 */     6,    7,   85,    9,   10,   11,   12,   76,   19,   78,
 /*   510 */    21,   85,   85,   24,   25,   26,   27,   28,   29,   30,
 /*   520 */    85,   32,   33,    8,   85,   36,   74,   75,   85,   77,
 /*   530 */    85,   85,   80,   81,   19,   83,   21,   85,   85,   24,
 /*   540 */    25,   26,   27,   28,   29,   30,   85,   32,   33,    8,
 /*   550 */     7,   36,    9,   10,   11,   12,   85,   13,   14,   15,
 /*   560 */    19,   76,   21,   78,   85,   24,   25,   26,   27,   28,
 /*   570 */    29,   30,   66,   32,   33,    8,   70,   36,   74,   75,
 /*   580 */    74,   77,   85,   77,   85,   55,   19,   83,   21,   83,
 /*   590 */    60,   24,   25,   26,   27,   28,   29,   30,   85,   32,
 /*   600 */    33,    8,   85,   36,    9,   10,   11,   12,   85,   76,
 /*   610 */    85,   78,   19,   76,   21,   78,   85,   24,   25,   26,
 /*   620 */    27,   28,   29,   30,   85,   32,   33,    8,   85,   36,
 /*   630 */     9,   10,   11,   12,   76,   76,   78,   78,   19,   76,
 /*   640 */    21,   78,   85,   24,   25,   26,   27,   28,   29,   30,
 /*   650 */    66,   32,   33,    8,   70,   36,   74,   75,   74,   77,
 /*   660 */    85,   77,   85,   85,   19,   83,   21,   83,   85,   24,
 /*   670 */    25,   26,   27,   28,   29,   30,   85,   32,   33,    8,
 /*   680 */    85,   36,   74,   75,   85,   77,   85,   85,   55,   55,
 /*   690 */    19,   83,   21,   60,   60,   24,   25,   26,   27,   28,
 /*   700 */    29,   30,   70,   32,   33,    8,   74,   36,   55,   77,
 /*   710 */    85,   85,   55,   60,   85,   83,   19,   60,   21,   85,
 /*   720 */    85,   24,   25,   26,   27,   28,   29,   30,   66,   32,
 /*   730 */    33,    8,   70,   36,   74,   75,   74,   77,   85,   77,
 /*   740 */    85,   85,   19,   83,   21,   83,   85,   24,   25,   26,
 /*   750 */    27,   28,   29,   30,   85,   32,   33,    8,   76,   36,
 /*   760 */    78,   85,    2,    3,    4,    5,    6,    7,   19,    9,
 /*   770 */    10,   11,   12,   24,   25,   26,   27,   28,   29,   30,
 /*   780 */    85,   32,   33,   85,   76,   36,   78,   85,   19,   85,
 /*   790 */    21,   85,   85,   24,   25,   26,   27,   28,   29,   30,
 /*   800 */    85,   32,   33,    8,   85,   36,   85,   85,    2,    3,
 /*   810 */     4,    5,    6,    7,   19,    9,   10,   11,   12,   24,
 /*   820 */    25,   26,   27,   28,   29,   30,   85,   32,   33,   53,
 /*   830 */    85,   36,   56,   57,   58,   59,   85,   85,   74,   75,
 /*   840 */    64,   77,   66,   67,   85,   85,   70,   83,   85,   85,
 /*   850 */    74,   85,   85,   77,   56,   57,   58,   59,   60,   83,
 /*   860 */    74,   75,   64,   77,   66,   67,   85,   85,   70,   83,
 /*   870 */    85,   85,   74,   59,   60,   77,   62,   85,   85,   66,
 /*   880 */    66,   83,   68,   70,   70,   85,   85,   74,   74,   85,
 /*   890 */    77,   77,   85,   19,   85,   85,   83,   83,   24,   25,
 /*   900 */    26,   27,   28,   29,   30,   85,   59,   85,   85,   62,
 /*   910 */    63,   85,   85,   66,   85,   85,   85,   70,   85,   85,
 /*   920 */    85,   74,   59,   60,   77,   62,   85,   85,   85,   66,
 /*   930 */    83,   85,   85,   70,   85,   85,   85,   74,   85,   85,
 /*   940 */    77,   59,   60,   85,   62,   85,   83,   85,   66,    2,
 /*   950 */     3,   85,   70,    6,    7,   85,   74,   59,   60,   77,
 /*   960 */    62,   85,   85,   85,   66,   83,   19,   85,   70,   85,
 /*   970 */    23,   85,   74,   59,   60,   77,   62,   85,   85,   85,
 /*   980 */    66,   83,   85,   85,   70,   85,   85,   85,   74,   59,
 /*   990 */    60,   77,   62,   85,   85,   85,   66,   83,   85,   85,
 /*  1000 */    70,   59,   60,   85,   74,   85,   85,   77,   66,   85,
 /*  1010 */    85,   85,   70,   83,   85,   85,   74,   85,   85,   77,
 /*  1020 */    66,   85,   85,   85,   70,   83,   85,   85,   74,   85,
 /*  1030 */    85,   77,   66,   85,   85,   85,   70,   83,   85,   85,
 /*  1040 */    74,   85,   66,   77,   85,   85,   70,   66,   85,   83,
 /*  1050 */    74,   70,   85,   77,   85,   74,   85,   66,   77,   83,
 /*  1060 */    85,   70,   85,   85,   83,   74,   85,   66,   77,   66,
 /*  1070 */    85,   70,   85,   70,   83,   74,   85,   74,   77,   66,
 /*  1080 */    77,   85,   85,   70,   83,   85,   83,   74,   85,   85,
 /*  1090 */    77,   66,   85,   85,   85,   70,   83,   85,   85,   74,
 /*  1100 */    85,   85,   77,   66,   85,   85,   85,   70,   83,   85,
 /*  1110 */    85,   74,   85,   66,   77,   85,   85,   70,   66,   85,
 /*  1120 */    83,   74,   70,   85,   77,   85,   74,   85,   66,   77,
 /*  1130 */    83,   85,   70,   85,   85,   83,   74,   85,   66,   77,
 /*  1140 */    66,   85,   70,   85,   70,   83,   74,   85,   74,   77,
 /*  1150 */    66,   77,   85,   85,   70,   83,   85,   83,   74,   85,
 /*  1160 */    85,   77,   66,   85,   85,   85,   70,   83,   85,   85,
 /*  1170 */    74,   85,   85,   77,   66,   85,   85,   85,   70,   83,
 /*  1180 */    85,   85,   74,   85,   66,   77,   85,   85,   70,   66,
 /*  1190 */    85,   83,   74,   70,   85,   77,   85,   74,   85,   85,
 /*  1200 */    77,   83,   85,   85,   74,   75,   83,   77,   85,   85,
 /*  1210 */    85,   74,   75,   83,   77,   74,   75,   85,   77,   85,
 /*  1220 */    83,   85,   85,   85,   83,   74,   75,   85,   77,   74,
 /*  1230 */    75,   85,   77,   85,   83,   85,   85,   85,   83,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (168)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (947)
static const short yy_shift_ofst[] = {
 /*     0 */     1,   60,   60,   26,   -8,  318,  263,  292,  292,  292,
 /*    10 */   292,  292,  344,  234,  205,  176,  147,  118,   89,  292,
 /*    20 */   795,  795,  723,  723,  723,  723,  723,  723,  723,  723,
 /*    30 */   723,  723,  723,  723,  723,  723,  723,  723,  723,  723,
 /*    40 */   723,  723,  723,  723,  723,  723,  697,  671,  645,  619,
 /*    50 */   593,  567,  541,  515,  769,  749,  749,  749,  749,  749,
 /*    60 */   749,  544,    1,    1,  370,  489,  463,  437,   35,    1,
 /*    70 */     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*    80 */     1,    1,    1,  391,  333,  456,  454,  450,  446,  417,
 /*    90 */    -9,   -9,   -9,   -9,   -9,   -9,  874,  874,  874,  947,
 /*   100 */    56,    1,  391,  365,  333,  356,  333,  261,  760,  760,
 /*   110 */   760,  760,  760,  760,  760,  760,  806,  760,  494,  494,
 /*   120 */   494,  494,  543,  621,  146,  595,  595,  306,  302,  294,
 /*   130 */   293,  275,   22,  273,  257,  247,  246,  243,  223,   81,
 /*   140 */   221,  207,  197,  214,  206,  189,  188,  185,  164,  160,
 /*   150 */   168,  156,  151,  141,  131,   81,  115,  130,  107,  112,
 /*   160 */    93,  101,   99,   76,   72,   62,   22,   81,   23,
};
#define YY_REDUCE_USE_DFLT (-74)
#define YY_REDUCE_COUNT (107)
#define YY_REDUCE_MIN   (-73)
#define YY_REDUCE_MAX   (1155)
static const short yy_reduce_ofst[] = {
 /*     0 */   397,  377,  355,  798,  798,  776,  814,  930,  914,  898,
 /*    10 */   882,  863,  847,  942,  942,  942,  942,  942,  942,  942,
 /*    20 */   400,  452, 1123, 1118, 1108, 1096, 1084, 1074, 1072, 1062,
 /*    30 */  1052, 1047, 1037, 1025, 1013, 1003, 1001,  991,  981,  976,
 /*    40 */   966,  954,  813,  662,  584,  506, 1155, 1151, 1141, 1137,
 /*    50 */  1130,  786,  764,  660,  632,  608,  582,  504,  -14,  -48,
 /*    60 */   -73,   51,  371,  349,  563,  708,  682,  563,  657,  653,
 /*    70 */   634,  633,  530,  274,  254,  225,  196,  167,  109,   80,
 /*    80 */    16,  -18,  -52,  384,   30,  559,  558,  537,  533,  485,
 /*    90 */   431,  314,  303,  288,  277,  232,  376,  372,  354,  367,
 /*   100 */   366,  364,  338,  315,  299,  281,  299,  256,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   271,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    10 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  272,
 /*    20 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    30 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    40 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    50 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    60 */   394,  394,  271,  271,  307,  350,  346,  307,  394,  394,
 /*    70 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 /*    80 */   394,  394,  394,  394,  339,  333,  333,  333,  333,  333,
 /*    90 */   333,  333,  333,  333,  333,  333,  394,  394,  394,  394,
 /*   100 */   394,  272,  394,  292,  342,  394,  340,  377,  334,  335,
 /*   110 */   370,  368,  366,  364,  362,  361,  371,  336,  320,  319,
 /*   120 */   313,  311,  315,  289,  308,  328,  317,  307,  350,  346,
 /*   130 */   288,  394,  394,  278,  394,  394,  394,  394,  394,  280,
 /*   140 */   394,  382,  394,  394,  394,  394,  394,  394,  394,  394,
 /*   150 */   394,  394,  394,  394,  394,  279,  394,  394,  394,  394,
 /*   160 */   394,  394,  325,  394,  394,  321,  307,  268,  394,  273,
 /*   170 */   285,  284,  265,  301,  300,  287,  291,  293,  290,  299,
 /*   180 */   298,  297,  296,  295,  294,  286,  283,  282,  274,  374,
 /*   190 */   341,  338,  337,  277,  312,  314,  316,  318,  378,  281,
 /*   200 */   393,  384,  383,  381,  380,  379,  373,  392,  391,  390,
 /*   210 */   389,  388,  387,  386,  385,  369,  367,  365,  363,  372,
 /*   220 */   357,  355,  354,  353,  356,  359,  352,  351,  349,  358,
 /*   230 */   348,  347,  343,  360,  345,  344,  276,  275,  270,  269,
 /*   240 */   376,  375,  332,  331,  329,  330,  327,  326,  324,  323,
 /*   250 */   322,  310,  309,  308,  307,  306,  305,  304,  303,  302,
 /*   260 */   267,  266,  264,
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
  "WHILE",         "IMPORT",        "DOT_NAME",      "AS",          
  "TRY",           "RESCUE",        "OP2_SET",       "OP1_SET",     
  "OP0_SET",       "RAISE",         "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "fin_m",         "comma",         "seq",           "delim_seq",   
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
 /* 120 */ "stmt ::= IMPORT DOT_NAME AS ID",
 /* 121 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 122 */ "stmt ::= ID EQUAL s2",
 /* 123 */ "stmt ::= ID OP2_SET s2",
 /* 124 */ "stmt ::= ID OP1_SET s2",
 /* 125 */ "stmt ::= ID OP0_SET s2",
 /* 126 */ "stmt ::= IVAR EQUAL s2",
 /* 127 */ "stmt ::= IVAR OP2_SET s2",
 /* 128 */ "stmt ::= IVAR OP1_SET s2",
 /* 129 */ "stmt ::= IVAR OP0_SET s2",
 /* 130 */ "stmt ::= RAISE s2",
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
  { 51, 3 },
  { 53, 3 },
  { 53, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 60, 1 },
  { 60, 1 },
  { 52, 0 },
  { 52, 1 },
  { 54, 1 },
  { 54, 2 },
  { 55, 2 },
  { 55, 1 },
  { 61, 2 },
  { 61, 1 },
  { 62, 3 },
  { 62, 1 },
  { 63, 2 },
  { 64, 1 },
  { 65, 3 },
  { 57, 4 },
  { 57, 6 },
  { 67, 1 },
  { 68, 3 },
  { 69, 1 },
  { 69, 3 },
  { 71, 3 },
  { 71, 1 },
  { 72, 0 },
  { 72, 3 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 73, 1 },
  { 58, 5 },
  { 58, 5 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 75, 1 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 3 },
  { 75, 2 },
  { 75, 4 },
  { 75, 5 },
  { 75, 3 },
  { 75, 3 },
  { 75, 5 },
  { 75, 6 },
  { 75, 2 },
  { 75, 1 },
  { 75, 4 },
  { 75, 3 },
  { 75, 3 },
  { 78, 0 },
  { 79, 3 },
  { 79, 1 },
  { 80, 3 },
  { 81, 3 },
  { 81, 1 },
  { 82, 0 },
  { 82, 2 },
  { 76, 3 },
  { 76, 2 },
  { 70, 1 },
  { 70, 3 },
  { 70, 4 },
  { 70, 2 },
  { 70, 4 },
  { 70, 5 },
  { 70, 3 },
  { 70, 3 },
  { 70, 5 },
  { 70, 6 },
  { 70, 1 },
  { 70, 3 },
  { 70, 3 },
  { 70, 4 },
  { 70, 3 },
  { 66, 3 },
  { 66, 4 },
  { 66, 2 },
  { 66, 3 },
  { 66, 3 },
  { 66, 5 },
  { 66, 3 },
  { 66, 5 },
  { 66, 3 },
  { 66, 5 },
  { 66, 3 },
  { 66, 5 },
  { 66, 3 },
  { 66, 1 },
  { 66, 2 },
  { 59, 1 },
  { 59, 3 },
  { 83, 1 },
  { 84, 3 },
  { 84, 0 },
  { 77, 5 },
  { 59, 6 },
  { 59, 6 },
  { 59, 6 },
  { 59, 2 },
  { 59, 4 },
  { 59, 9 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy128.a)); }
#line 1225 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 34 "vm/parser.lm"
{ yygotominor.yy128.a = S->seq(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1231 "vm/parser.c.inc"
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
{ yygotominor.yy128.a = yymsp[0].minor.yy128.a; }
#line 1246 "vm/parser.c.inc"
        break;
      case 18: /* delim_seq ::= seq opt_fin */
      case 94: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==94);
#line 59 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[-1].minor.yy128.a; }
#line 1252 "vm/parser.c.inc"
        break;
      case 19: /* class_start ::= CLASS */
#line 61 "vm/parser.lm"
{ S->start_class(); }
#line 1257 "vm/parser.c.inc"
        break;
      case 20: /* class_body ::= l1 fin END */
      case 24: /* def_body ::= seq fin END */ yytestcase(yyruleno==24);
#line 62 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[-2].minor.yy128.a; }
#line 1263 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy128.a);
             }
#line 1270 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID LT s2 fin class_body */
#line 68 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a);
             }
#line 1277 "vm/parser.c.inc"
        break;
      case 23: /* def_start ::= DEF */
#line 72 "vm/parser.lm"
{ S->start_def(); }
#line 1282 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID */
#line 75 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1287 "vm/parser.c.inc"
        break;
      case 26: /* arg ::= ID CAST np_recv */
#line 76 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1292 "vm/parser.c.inc"
        break;
      case 31: /* def_name ::= ID */
      case 32: /* def_name ::= OP0 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= LT */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= OP1 */ yytestcase(yyruleno==34);
      case 35: /* def_name ::= OP2 */ yytestcase(yyruleno==35);
      case 36: /* def_name ::= SQUARE */ yytestcase(yyruleno==36);
#line 84 "vm/parser.lm"
{ yygotominor.yy128.s = yymsp[0].minor.yy0.s; }
#line 1302 "vm/parser.c.inc"
        break;
      case 37: /* def ::= def_start def_name def_args fin def_body */
#line 92 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, yymsp[0].minor.yy128.a);
            }
#line 1309 "vm/parser.c.inc"
        break;
      case 38: /* def ::= def_start def_name def_args fin END */
#line 95 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, S->ast_nil());
            }
#line 1316 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= NUM */
#line 99 "vm/parser.lm"
{ yygotominor.yy128.a = S->number(yymsp[0].minor.yy0.i); }
#line 1321 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= NIL */
#line 100 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_nil();  }
#line 1326 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= TRUE */
#line 101 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_true();  }
#line 1331 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= FALSE */
#line 102 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_false(); }
#line 1336 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= SELF */
#line 103 "vm/parser.lm"
{ yygotominor.yy128.a = S->self(); }
#line 1341 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= ID */
#line 104 "vm/parser.lm"
{ yygotominor.yy128.a = S->named(yymsp[0].minor.yy0.s); }
#line 1346 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= IVAR */
#line 105 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1351 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= LITSTR */
#line 106 "vm/parser.lm"
{ yygotominor.yy128.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1356 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg OP0 np_arg */
      case 50: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==50);
      case 52: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==52);
      case 99: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==99);
      case 101: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==101);
      case 103: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==103);
#line 111 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1366 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 51: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==51);
      case 53: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==53);
      case 100: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==100);
      case 102: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==102);
      case 104: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==104);
#line 113 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy128.a, yymsp[-1].minor.yy128.a); }
#line 1376 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg OP2 np_arg */
      case 105: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==105);
#line 126 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1382 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 106: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==106);
#line 128 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy128.a, yymsp[-1].minor.yy128.a); }
#line 1388 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg CAST np_arg */
      case 98: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==98);
#line 131 "vm/parser.lm"
{ yygotominor.yy128.a = S->cast(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1394 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg NEQUAL np_arg */
      case 107: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==107);
#line 133 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a)); }
#line 1400 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg DOT */
      case 83: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==83);
#line 134 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-1].minor.yy128.a, yymsp[0].minor.yy0.s); }
#line 1406 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg DOT LP RP */
      case 84: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==84);
#line 135 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-3].minor.yy128.a, yymsp[-2].minor.yy0.s); }
#line 1412 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 85: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==85);
#line 137 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-4].minor.yy128.a, yymsp[-3].minor.yy0.s); }
#line 1418 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg DCOLON ID */
      case 86: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==86);
#line 138 "vm/parser.lm"
{ yygotominor.yy128.a = S->dcolon(yymsp[-2].minor.yy128.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1424 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 87: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==87);
#line 141 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1430 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 88: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1436 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-5].minor.yy128.a, yymsp[-3].minor.yy128.a); }
#line 1442 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= NOT np_arg */
      case 109: /* s2 ::= NOT s2 */ yytestcase(yyruleno==109);
#line 146 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(yymsp[0].minor.yy128.a); }
#line 1448 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 93: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==93);
#line 149 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-3].minor.yy128.a, "[]"); }
#line 1454 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 91: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==91);
#line 151 "vm/parser.lm"
{ yygotominor.yy128.a = S->tuple(); }
#line 1460 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= DICT_START np_arg_list RB */
      case 92: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==92);
#line 152 "vm/parser.lm"
{ yygotominor.yy128.a = S->dict(); }
#line 1466 "vm/parser.c.inc"
        break;
      case 70: /* np_arg_list_start ::= */
#line 154 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1471 "vm/parser.c.inc"
        break;
      case 71: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 72: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==72);
#line 155 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy128.a); }
#line 1477 "vm/parser.c.inc"
        break;
      case 73: /* np_kw_arg ::= ID EQUAL np_arg */
#line 158 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1482 "vm/parser.c.inc"
        break;
      case 81: /* np_recv ::= ID LP RP */
#line 170 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1487 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= ID LP np_arg_list RP */
#line 171 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1492 "vm/parser.c.inc"
        break;
      case 95: /* s2 ::= np_recv DOT np_arg_list */
#line 189 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-2].minor.yy128.a, yymsp[-1].minor.yy0.s); }
#line 1497 "vm/parser.c.inc"
        break;
      case 96: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 191 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-3].minor.yy128.a, yymsp[-1].minor.yy128.a); }
#line 1502 "vm/parser.c.inc"
        break;
      case 97: /* s2 ::= ID np_arg_list */
#line 192 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1507 "vm/parser.c.inc"
        break;
      case 111: /* stmt ::= stmt AND s2 */
#line 208 "vm/parser.lm"
{ yygotominor.yy128.a = S->and_(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1512 "vm/parser.c.inc"
        break;
      case 112: /* lambda_start ::= LB */
#line 212 "vm/parser.lm"
{ S->start_lambda(); }
#line 1517 "vm/parser.c.inc"
        break;
      case 113: /* lambda_args ::= PIPE ID PIPE */
#line 214 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1522 "vm/parser.c.inc"
        break;
      case 115: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 217 "vm/parser.lm"
{ yygotominor.yy128.a = S->lambda(yymsp[-1].minor.yy128.a); }
#line 1527 "vm/parser.c.inc"
        break;
      case 116: /* stmt ::= IF s2 fin seq fin END */
#line 221 "vm/parser.lm"
{ yygotominor.yy128.a = S->if_cond(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1532 "vm/parser.c.inc"
        break;
      case 117: /* stmt ::= UNLESS s2 fin seq fin END */
#line 222 "vm/parser.lm"
{ yygotominor.yy128.a = S->unless(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1537 "vm/parser.c.inc"
        break;
      case 118: /* stmt ::= WHILE s2 fin seq fin END */
#line 223 "vm/parser.lm"
{ yygotominor.yy128.a = S->while_(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1542 "vm/parser.c.inc"
        break;
      case 119: /* stmt ::= IMPORT DOT_NAME */
#line 227 "vm/parser.lm"
{ yygotominor.yy128.a = S->import(yymsp[0].minor.yy0.s); }
#line 1547 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= IMPORT DOT_NAME AS ID */
#line 228 "vm/parser.lm"
{ yygotominor.yy128.a = S->import(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1552 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 230 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_try(yymsp[-6].minor.yy128.a, yymsp[-2].minor.yy128.a);
            }
#line 1559 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= ID EQUAL s2 */
#line 234 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1564 "vm/parser.c.inc"
        break;
      case 123: /* stmt ::= ID OP2_SET s2 */
      case 124: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==124);
      case 125: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==125);
#line 235 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1571 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= IVAR EQUAL s2 */
#line 238 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1576 "vm/parser.c.inc"
        break;
      case 127: /* stmt ::= IVAR OP2_SET s2 */
      case 128: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==128);
      case 129: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==129);
#line 240 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1583 "vm/parser.c.inc"
        break;
      case 130: /* stmt ::= RAISE s2 */
#line 245 "vm/parser.lm"
{ yygotominor.yy128.a = S->raise(yymsp[0].minor.yy128.a); }
#line 1588 "vm/parser.c.inc"
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
#line 1677 "vm/parser.c.inc"
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
