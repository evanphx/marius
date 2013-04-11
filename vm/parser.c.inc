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
#define YYNOCODE 90
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy14;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 272
#define YYNRULE 135
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
#define YY_ACTTAB_COUNT (1324)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    43,  259,  121,  272,  252,  247,  246,  196,   47,  195,
 /*    10 */   111,   66,  193,  191,   44,  247,  246,  267,  266,  265,
 /*    20 */   264,  263,  128,  260,   62,   95,   94,  259,  123,  249,
 /*    30 */   252,   32,   31,   30,  147,   43,  111,   80,   93,   92,
 /*    40 */   247,  246,   29,  257,  195,  194,   66,  193,  191,   44,
 /*    50 */    23,  256,  267,  266,  265,  264,  263,  128,  260,  254,
 /*    60 */    95,   94,  259,  122,  249,  252,   32,   31,   30,  147,
 /*    70 */    43,  111,   80,  198,  253,  247,  246,   29,  251,  195,
 /*    80 */   192,   66,  193,  191,   44,  250,  161,  267,  266,  265,
 /*    90 */   264,  263,  128,  260,  248,   95,   94,  259,  129,  249,
 /*   100 */   252,   32,   31,   30,  147,   43,  111,   80,  173,    6,
 /*   110 */   247,  246,   29,  242,  195,  244,   66,  193,  191,   44,
 /*   120 */   236,  232,  267,  266,  265,  264,  263,  128,  260,  238,
 /*   130 */    95,   94,  234,  230,  249,   43,   32,   31,   30,  147,
 /*   140 */   247,  246,   80,  229,  138,  213,   66,   29,  165,   44,
 /*   150 */    22,  183,  267,  266,  265,  264,  263,  128,  260,  228,
 /*   160 */    95,   94,  226,  225,  249,   43,   32,   31,   30,  147,
 /*   170 */   247,  246,   80,  224,  223,  212,   66,   29,  164,   44,
 /*   180 */    22,  146,  267,  266,  265,  264,  263,  128,  260,  145,
 /*   190 */    95,   94,  210,  205,  249,   43,   32,   31,   30,  147,
 /*   200 */   247,  246,   80,  206,  204,  211,   66,   29,  182,   44,
 /*   210 */   104,  201,  267,  266,  265,  264,  263,  128,  260,  203,
 /*   220 */    95,   94,   36,  202,  249,   43,   32,   31,   30,  147,
 /*   230 */   247,  246,   80,   35,   34,   33,   66,   29,  163,   44,
 /*   240 */    22,   70,  267,  266,  265,  264,  263,  128,  260,   75,
 /*   250 */    95,   94,   65,   56,  249,   43,   32,   31,   30,  147,
 /*   260 */   247,  246,   80,   78,   90,  209,   66,   29,  155,   44,
 /*   270 */    22,  162,  267,  266,  265,  264,  263,  128,  260,   89,
 /*   280 */    95,   94,   91,  109,  249,   43,   32,   31,   30,  147,
 /*   290 */   247,  246,   80,  200,  138,  181,   66,   29,  154,   44,
 /*   300 */    22,  137,  267,  266,  265,  264,  263,  128,  260,   87,
 /*   310 */    95,   94,   73,  184,  249,   43,   32,   31,   30,  147,
 /*   320 */   247,  246,   80,  134,  245,  179,   66,   29,  153,   44,
 /*   330 */    22,  106,  267,  266,  265,  264,  263,  128,  260,  167,
 /*   340 */    95,   94,   43,  169,  249,   22,   32,   31,   30,  147,
 /*   350 */   107,  195,   80,   66,  193,  191,   44,   29,   67,  267,
 /*   360 */   266,  265,  264,  263,  128,  260,  132,   95,   94,  258,
 /*   370 */   409,  249,   43,   32,   31,   30,  147,  247,  246,   80,
 /*   380 */   166,  255,   22,   66,   29,  159,   44,   22,  243,  267,
 /*   390 */   266,  265,  264,  263,  128,  260,  239,   95,   94,   43,
 /*   400 */   158,  249,   22,   32,   31,   30,  147,  235,  409,   80,
 /*   410 */    66,  409,  409,   44,   29,  409,  267,  266,  265,  264,
 /*   420 */   263,  128,  260,  409,   95,   94,  346,  156,  249,   22,
 /*   430 */    32,   31,   30,  147,  409,  409,   80,  346,  409,  409,
 /*   440 */    91,   29,  409,  346,  346,  346,  346,  346,  346,  346,
 /*   450 */   409,  346,  346,  409,   46,  346,   76,  409,  409,  178,
 /*   460 */   270,  269,  268,  172,  245,   39,   38,   37,  136,  176,
 /*   470 */   214,  135,  409,  103,  408,    7,  120,  409,  105,   14,
 /*   480 */   240,  409,  105,  231,  244,  409,  409,   74,  244,  111,
 /*   490 */   178,  270,  269,  268,  172,  245,  247,  246,  174,  136,
 /*   500 */   197,  214,  135,  177,  103,   24,  120,  120,  409,  409,
 /*   510 */   240,  240,  409,  231,  231,  247,  246,  409,   76,  111,
 /*   520 */   111,  178,  270,  269,  268,  172,  245,  241,   13,   22,
 /*   530 */   136,  175,  214,  135,  244,  103,  409,  127,  120,  409,
 /*   540 */    20,  240,  240,  409,  231,  231,  244,  409,  409,   63,
 /*   550 */   111,  111,  178,  270,  269,  268,  172,  409,  409,  259,
 /*   560 */   119,  136,  252,  214,  135,  237,  103,   22,  111,  120,
 /*   570 */   409,  259,  112,  240,  252,   12,  231,  199,  110,  409,
 /*   580 */   111,  244,  111,  271,  270,  269,  268,  172,  245,  409,
 /*   590 */   259,  114,  136,  252,  214,  135,  233,  103,   22,  111,
 /*   600 */   120,  346,  259,  125,  240,  252,  409,  231,   19,  409,
 /*   610 */    11,  111,  346,  111,  244,   91,  244,  409,  346,  346,
 /*   620 */   346,  346,  346,  346,  346,  409,  346,  346,  346,   18,
 /*   630 */   346,  259,  113,  409,  252,  244,   88,  199,  108,  346,
 /*   640 */   111,  409,   90,  409,  409,  346,  346,  346,  346,  346,
 /*   650 */   346,  346,  409,  346,  346,  346,  409,  346,   53,   52,
 /*   660 */   409,  170,  168,  102,   99,   10,  346,  409,  409,   89,
 /*   670 */   409,  244,  346,  346,  346,  346,  346,  346,  346,  409,
 /*   680 */   346,  346,   59,   52,  346,  170,  168,  102,   99,   17,
 /*   690 */   409,    9,   16,  262,  409,  244,   25,  244,  244,  267,
 /*   700 */   266,  265,  264,  263,  261,  260,  222,   98,   97,   59,
 /*   710 */   409,  249,  120,  409,  409,  207,  240,  409,   21,  231,
 /*   720 */   262,  409,  409,   26,  244,  111,  267,  266,  265,  264,
 /*   730 */   263,  261,  260,  151,   98,   97,   59,  409,  249,  120,
 /*   740 */   409,  409,    5,  240,  409,    2,  231,  262,  244,  409,
 /*   750 */    27,  244,  111,  267,  266,  265,  264,  263,  261,  260,
 /*   760 */   409,   98,   97,   59,    4,  249,  170,  168,  102,   99,
 /*   770 */   244,  409,    8,   15,  262,  409,  409,   28,  244,  244,
 /*   780 */   267,  266,  265,  264,  263,  261,  260,  409,   98,   97,
 /*   790 */    59,    1,  249,  133,  157,  100,   96,  244,  409,    3,
 /*   800 */   409,  262,  409,  409,   45,  244,  409,  267,  266,  265,
 /*   810 */   264,  263,  261,  260,  409,   98,   97,   59,  409,  249,
 /*   820 */   409,  409,  409,  409,  409,  409,  409,  409,  262,  409,
 /*   830 */   409,   42,  409,  409,  267,  266,  265,  264,  263,  261,
 /*   840 */   260,  409,   98,   97,   59,  409,  249,  259,  124,  409,
 /*   850 */   252,  409,  409,  409,  409,  262,  111,  409,   41,  409,
 /*   860 */   409,  267,  266,  265,  264,  263,  261,  260,  409,   98,
 /*   870 */    97,   59,  409,  249,  259,  126,  409,  252,  409,  409,
 /*   880 */   409,  409,  262,  111,  409,   40,  409,  409,  267,  266,
 /*   890 */   265,  264,  263,  261,  260,  409,   98,   97,   43,  409,
 /*   900 */   249,  409,  409,  409,  409,  409,  409,  409,  409,   69,
 /*   910 */   409,  409,   44,  409,  409,  267,  266,  265,  264,  263,
 /*   920 */   261,  260,  409,   95,   94,   59,  409,  249,  409,  409,
 /*   930 */    55,   54,   61,   60,   53,   52,  262,  170,  168,  102,
 /*   940 */    99,  409,  267,  266,  265,  264,  263,  261,  260,  409,
 /*   950 */    98,   97,  259,  130,  249,  252,  131,  409,  409,   44,
 /*   960 */   409,  111,  267,  266,  265,  264,  263,  261,  260,  409,
 /*   970 */    95,   94,   59,  409,  249,  409,  409,   51,   50,   58,
 /*   980 */    57,   49,   48,  171,   68,  157,  101,   96,  409,  267,
 /*   990 */   266,  265,  264,  263,  261,  260,  409,   98,   97,  144,
 /*  1000 */   245,  249,   72,  409,  259,  118,  214,  252,  409,  409,
 /*  1010 */   180,  409,  120,  111,  259,  117,  240,  252,  409,  231,
 /*  1020 */   262,  409,  409,  111,  409,  111,  267,  266,  265,  264,
 /*  1030 */   263,  261,  260,  144,  189,  188,   64,  143,  187,  186,
 /*  1040 */   214,  144,  245,  409,   85,  409,  120,  409,  214,  409,
 /*  1050 */   240,  190,  409,  231,  120,  409,  185,  409,  240,  111,
 /*  1060 */   409,  231,  409,  144,  245,  409,   83,  111,  144,  245,
 /*  1070 */   214,   81,  409,  409,  409,  214,  120,  409,  409,  409,
 /*  1080 */   240,  120,  409,  231,  409,  240,  409,  409,  231,  111,
 /*  1090 */   144,  245,  409,   79,  111,  144,  245,  214,   77,  409,
 /*  1100 */   409,  409,  214,  120,  409,  409,  409,  240,  120,  409,
 /*  1110 */   231,  409,  240,  409,  409,  231,  111,  259,  116,  152,
 /*  1120 */   252,  111,  409,  160,  245,  120,  111,  409,  409,  240,
 /*  1130 */   214,  409,  231,  409,  409,  227,  120,  409,  111,  409,
 /*  1140 */   240,  120,  409,  231,  409,  240,  409,  409,  231,  111,
 /*  1150 */   150,  409,  149,  409,  111,  409,  120,  409,  120,  409,
 /*  1160 */   240,  409,  240,  231,  148,  231,  221,  409,  409,  111,
 /*  1170 */   120,  111,  120,  409,  240,  409,  240,  231,  409,  231,
 /*  1180 */   409,  220,  409,  111,  409,  111,  409,  120,  409,  409,
 /*  1190 */   409,  240,  219,  218,  231,  409,  409,  409,  120,  120,
 /*  1200 */   111,  409,  240,  240,  217,  231,  231,  409,  409,  216,
 /*  1210 */   120,  111,  111,  409,  240,  120,  409,  231,  409,  240,
 /*  1220 */   409,  215,  231,  111,  409,  409,  409,  120,  111,   86,
 /*  1230 */   409,  240,  409,  409,  231,  120,  409,  409,  409,  240,
 /*  1240 */   111,   84,  231,   82,  409,  409,  409,  120,  111,  120,
 /*  1250 */   409,  240,  409,  240,  231,  409,  231,  409,  409,  409,
 /*  1260 */   111,  208,  111,  142,  409,  409,  409,  120,  409,  120,
 /*  1270 */   409,  240,  409,  240,  231,  141,  231,  409,  409,  409,
 /*  1280 */   111,  120,  111,  140,  409,  240,  409,  409,  231,  120,
 /*  1290 */   409,  139,  409,  240,  111,  409,  231,  120,  409,  409,
 /*  1300 */   409,  240,  111,   71,  231,  409,  409,  409,  409,  120,
 /*  1310 */   111,  409,  409,  240,  259,  115,  231,  252,  409,  409,
 /*  1320 */   409,  409,  111,  111,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     8,   78,   79,    0,   81,   13,   14,   15,    1,   17,
 /*    10 */    87,   19,   20,   21,   22,   13,   14,   25,   26,   27,
 /*    20 */    28,   29,   30,   31,   36,   33,   34,   78,   79,   37,
 /*    30 */    81,   39,   40,   41,   42,    8,   87,   45,   22,   22,
 /*    40 */    13,   14,   50,   23,   17,   18,   19,   20,   21,   22,
 /*    50 */    63,   19,   25,   26,   27,   28,   29,   30,   31,   23,
 /*    60 */    33,   34,   78,   79,   37,   81,   39,   40,   41,   42,
 /*    70 */     8,   87,   45,   86,   32,   13,   14,   50,   23,   17,
 /*    80 */    18,   19,   20,   21,   22,   35,   19,   25,   26,   27,
 /*    90 */    28,   29,   30,   31,   38,   33,   34,   78,   79,   37,
 /*   100 */    81,   39,   40,   41,   42,    8,   87,   45,   55,   56,
 /*   110 */    13,   14,   50,   23,   17,   62,   19,   20,   21,   22,
 /*   120 */    19,   32,   25,   26,   27,   28,   29,   30,   31,   23,
 /*   130 */    33,   34,   23,   23,   37,    8,   39,   40,   41,   42,
 /*   140 */    13,   14,   45,   35,   16,   18,   19,   50,   80,   22,
 /*   150 */    82,   23,   25,   26,   27,   28,   29,   30,   31,   23,
 /*   160 */    33,   34,   23,   23,   37,    8,   39,   40,   41,   42,
 /*   170 */    13,   14,   45,   23,   23,   18,   19,   50,   80,   22,
 /*   180 */    82,   43,   25,   26,   27,   28,   29,   30,   31,   44,
 /*   190 */    33,   34,   19,   23,   37,    8,   39,   40,   41,   42,
 /*   200 */    13,   14,   45,   35,   23,   18,   19,   50,   73,   22,
 /*   210 */    75,   13,   25,   26,   27,   28,   29,   30,   31,   23,
 /*   220 */    33,   34,   36,   23,   37,    8,   39,   40,   41,   42,
 /*   230 */    13,   14,   45,   47,   48,   49,   19,   50,   80,   22,
 /*   240 */    82,   19,   25,   26,   27,   28,   29,   30,   31,   19,
 /*   250 */    33,   34,   88,    4,   37,    8,   39,   40,   41,   42,
 /*   260 */    13,   14,   45,   46,   22,   18,   19,   50,   80,   22,
 /*   270 */    82,   38,   25,   26,   27,   28,   29,   30,   31,   22,
 /*   280 */    33,   34,   22,   63,   37,    8,   39,   40,   41,   42,
 /*   290 */    13,   14,   45,   84,   16,   18,   19,   50,   80,   22,
 /*   300 */    82,   19,   25,   26,   27,   28,   29,   30,   31,   22,
 /*   310 */    33,   34,   76,   73,   37,    8,   39,   40,   41,   42,
 /*   320 */    13,   14,   45,   19,   62,   18,   19,   50,   80,   22,
 /*   330 */    82,   63,   25,   26,   27,   28,   29,   30,   31,   78,
 /*   340 */    33,   34,    8,   80,   37,   82,   39,   40,   41,   42,
 /*   350 */    77,   17,   45,   19,   20,   21,   22,   50,   78,   25,
 /*   360 */    26,   27,   28,   29,   30,   31,   78,   33,   34,   23,
 /*   370 */    89,   37,    8,   39,   40,   41,   42,   13,   14,   45,
 /*   380 */    80,   23,   82,   19,   50,   80,   22,   82,   23,   25,
 /*   390 */    26,   27,   28,   29,   30,   31,   23,   33,   34,    8,
 /*   400 */    80,   37,   82,   39,   40,   41,   42,   23,   89,   45,
 /*   410 */    19,   89,   89,   22,   50,   89,   25,   26,   27,   28,
 /*   420 */    29,   30,   31,   89,   33,   34,    8,   80,   37,   82,
 /*   430 */    39,   40,   41,   42,   89,   89,   45,   19,   89,   89,
 /*   440 */    22,   50,   89,   25,   26,   27,   28,   29,   30,   31,
 /*   450 */    89,   33,   34,   89,   36,   37,   54,   89,   89,   57,
 /*   460 */    58,   59,   60,   61,   62,   47,   48,   49,   66,   67,
 /*   470 */    68,   69,   89,   71,   52,   53,   74,   89,   56,   53,
 /*   480 */    78,   89,   56,   81,   62,   89,   89,   54,   62,   87,
 /*   490 */    57,   58,   59,   60,   61,   62,   13,   14,   15,   66,
 /*   500 */    68,   68,   69,   70,   71,    3,   74,   74,   89,   89,
 /*   510 */    78,   78,   89,   81,   81,   13,   14,   89,   54,   87,
 /*   520 */    87,   57,   58,   59,   60,   61,   62,   80,   56,   82,
 /*   530 */    66,   67,   68,   69,   62,   71,   89,   74,   74,   89,
 /*   540 */    56,   78,   78,   89,   81,   81,   62,   89,   89,   54,
 /*   550 */    87,   87,   57,   58,   59,   60,   61,   89,   89,   78,
 /*   560 */    79,   66,   81,   68,   69,   80,   71,   82,   87,   74,
 /*   570 */    89,   78,   79,   78,   81,   56,   81,   84,   85,   89,
 /*   580 */    87,   62,   87,   57,   58,   59,   60,   61,   62,   89,
 /*   590 */    78,   79,   66,   81,   68,   69,   80,   71,   82,   87,
 /*   600 */    74,    8,   78,   79,   78,   81,   89,   81,   56,   89,
 /*   610 */    56,   87,   19,   87,   62,   22,   62,   89,   25,   26,
 /*   620 */    27,   28,   29,   30,   31,   89,   33,   34,    8,   56,
 /*   630 */    37,   78,   79,   89,   81,   62,   83,   84,   85,   19,
 /*   640 */    87,   89,   22,   89,   89,   25,   26,   27,   28,   29,
 /*   650 */    30,   31,   89,   33,   34,    8,   89,   37,    6,    7,
 /*   660 */    89,    9,   10,   11,   12,   56,   19,   89,   89,   22,
 /*   670 */    89,   62,   25,   26,   27,   28,   29,   30,   31,   89,
 /*   680 */    33,   34,    8,    7,   37,    9,   10,   11,   12,   56,
 /*   690 */    89,   56,   56,   19,   89,   62,   22,   62,   62,   25,
 /*   700 */    26,   27,   28,   29,   30,   31,   68,   33,   34,    8,
 /*   710 */    89,   37,   74,   89,   89,   53,   78,   89,   56,   81,
 /*   720 */    19,   89,   89,   22,   62,   87,   25,   26,   27,   28,
 /*   730 */    29,   30,   31,   68,   33,   34,    8,   89,   37,   74,
 /*   740 */    89,   89,   56,   78,   89,   56,   81,   19,   62,   89,
 /*   750 */    22,   62,   87,   25,   26,   27,   28,   29,   30,   31,
 /*   760 */    89,   33,   34,    8,   56,   37,    9,   10,   11,   12,
 /*   770 */    62,   89,   56,   56,   19,   89,   89,   22,   62,   62,
 /*   780 */    25,   26,   27,   28,   29,   30,   31,   89,   33,   34,
 /*   790 */     8,   56,   37,    9,   10,   11,   12,   62,   89,   56,
 /*   800 */    89,   19,   89,   89,   22,   62,   89,   25,   26,   27,
 /*   810 */    28,   29,   30,   31,   89,   33,   34,    8,   89,   37,
 /*   820 */    89,   89,   89,   89,   89,   89,   89,   89,   19,   89,
 /*   830 */    89,   22,   89,   89,   25,   26,   27,   28,   29,   30,
 /*   840 */    31,   89,   33,   34,    8,   89,   37,   78,   79,   89,
 /*   850 */    81,   89,   89,   89,   89,   19,   87,   89,   22,   89,
 /*   860 */    89,   25,   26,   27,   28,   29,   30,   31,   89,   33,
 /*   870 */    34,    8,   89,   37,   78,   79,   89,   81,   89,   89,
 /*   880 */    89,   89,   19,   87,   89,   22,   89,   89,   25,   26,
 /*   890 */    27,   28,   29,   30,   31,   89,   33,   34,    8,   89,
 /*   900 */    37,   89,   89,   89,   89,   89,   89,   89,   89,   19,
 /*   910 */    89,   89,   22,   89,   89,   25,   26,   27,   28,   29,
 /*   920 */    30,   31,   89,   33,   34,    8,   89,   37,   89,   89,
 /*   930 */     2,    3,    4,    5,    6,    7,   19,    9,   10,   11,
 /*   940 */    12,   89,   25,   26,   27,   28,   29,   30,   31,   89,
 /*   950 */    33,   34,   78,   79,   37,   81,   19,   89,   89,   22,
 /*   960 */    89,   87,   25,   26,   27,   28,   29,   30,   31,   89,
 /*   970 */    33,   34,    8,   89,   37,   89,   89,    2,    3,    4,
 /*   980 */     5,    6,    7,   19,    9,   10,   11,   12,   89,   25,
 /*   990 */    26,   27,   28,   29,   30,   31,   89,   33,   34,   61,
 /*  1000 */    62,   37,   64,   89,   78,   79,   68,   81,   89,   89,
 /*  1010 */    72,   89,   74,   87,   78,   79,   78,   81,   89,   81,
 /*  1020 */    19,   89,   89,   87,   89,   87,   25,   26,   27,   28,
 /*  1030 */    29,   30,   31,   61,    2,    3,   64,   65,    6,    7,
 /*  1040 */    68,   61,   62,   89,   64,   89,   74,   89,   68,   89,
 /*  1050 */    78,   19,   89,   81,   74,   89,   24,   89,   78,   87,
 /*  1060 */    89,   81,   89,   61,   62,   89,   64,   87,   61,   62,
 /*  1070 */    68,   64,   89,   89,   89,   68,   74,   89,   89,   89,
 /*  1080 */    78,   74,   89,   81,   89,   78,   89,   89,   81,   87,
 /*  1090 */    61,   62,   89,   64,   87,   61,   62,   68,   64,   89,
 /*  1100 */    89,   89,   68,   74,   89,   89,   89,   78,   74,   89,
 /*  1110 */    81,   89,   78,   89,   89,   81,   87,   78,   79,   68,
 /*  1120 */    81,   87,   89,   61,   62,   74,   87,   89,   89,   78,
 /*  1130 */    68,   89,   81,   89,   89,   68,   74,   89,   87,   89,
 /*  1140 */    78,   74,   89,   81,   89,   78,   89,   89,   81,   87,
 /*  1150 */    68,   89,   68,   89,   87,   89,   74,   89,   74,   89,
 /*  1160 */    78,   89,   78,   81,   68,   81,   68,   89,   89,   87,
 /*  1170 */    74,   87,   74,   89,   78,   89,   78,   81,   89,   81,
 /*  1180 */    89,   68,   89,   87,   89,   87,   89,   74,   89,   89,
 /*  1190 */    89,   78,   68,   68,   81,   89,   89,   89,   74,   74,
 /*  1200 */    87,   89,   78,   78,   68,   81,   81,   89,   89,   68,
 /*  1210 */    74,   87,   87,   89,   78,   74,   89,   81,   89,   78,
 /*  1220 */    89,   68,   81,   87,   89,   89,   89,   74,   87,   68,
 /*  1230 */    89,   78,   89,   89,   81,   74,   89,   89,   89,   78,
 /*  1240 */    87,   68,   81,   68,   89,   89,   89,   74,   87,   74,
 /*  1250 */    89,   78,   89,   78,   81,   89,   81,   89,   89,   89,
 /*  1260 */    87,   68,   87,   68,   89,   89,   89,   74,   89,   74,
 /*  1270 */    89,   78,   89,   78,   81,   68,   81,   89,   89,   89,
 /*  1280 */    87,   74,   87,   68,   89,   78,   89,   89,   81,   74,
 /*  1290 */    89,   68,   89,   78,   87,   89,   81,   74,   89,   89,
 /*  1300 */    89,   78,   87,   68,   81,   89,   89,   89,   89,   74,
 /*  1310 */    87,   89,   89,   78,   78,   79,   81,   81,   89,   89,
 /*  1320 */    89,   89,   87,   87,
};
#define YY_SHIFT_USE_DFLT (-13)
#define YY_SHIFT_COUNT (173)
#define YY_SHIFT_MIN   (-12)
#define YY_SHIFT_MAX   (1032)
static const short yy_shift_ofst[] = {
 /*     0 */     2,   97,   97,   97,   62,   27,   -8,  334,  307,  364,
 /*    10 */   364,  364,  364,  364,  391,  277,  247,  217,  187,  157,
 /*    20 */   127,  364,  964,  964,  890,  890,  890,  890,  890,  890,
 /*    30 */   890,  890,  890,  890,  890,  890,  890,  890,  890,  890,
 /*    40 */   890,  890,  890,  890,  890,  890,  890,  890,  863,  836,
 /*    50 */   809,  782,  755,  728,  701,  674,  937,  917,  917,  917,
 /*    60 */   917,  917,  917,  483,    2,    2,  418,  647,  620,  593,
 /*    70 */   502,    2,    2,    2,    2,    2,    2,    2,    2,    2,
 /*    80 */     2,    2,    2,    2,    2,    2,    2,  304,  278,  384,
 /*    90 */   373,  365,  358,  346,  -13,  -13,  -13,  -13,  -13,  -13,
 /*   100 */  1001, 1001, 1001, 1032,  128,    2,  304,  287,  278,  282,
 /*   110 */   278,  233,  928,  928,  928,  928,  928,  928,  928,  928,
 /*   120 */   975,  928,  652,  652,  652,  652,  676,  784,  186,  757,
 /*   130 */   757,  260,  257,  242,  249,  230,  222,  -12,  198,  200,
 /*   140 */   196,  181,  170,  168,    7,  173,  145,  138,  151,  150,
 /*   150 */   140,  139,  136,  108,  110,   89,  109,  101,  106,   90,
 /*   160 */     7,   56,   67,   50,   55,   42,   36,   17,   32,   20,
 /*   170 */    16,  -12,    7,    3,
};
#define YY_REDUCE_USE_DFLT (-78)
#define YY_REDUCE_COUNT (111)
#define YY_REDUCE_MIN   (-77)
#define YY_REDUCE_MAX   (1236)
static const short yy_reduce_ofst[] = {
 /*     0 */   422,  464,  433,  402,  526,  526,  526,  495,  938, 1034,
 /*    10 */  1029, 1007, 1002,  980,  972, 1062, 1062, 1062, 1062, 1062,
 /*    20 */  1062, 1062,  553,  493, 1235, 1223, 1215, 1207, 1195, 1193,
 /*    30 */  1175, 1173, 1161, 1153, 1141, 1136, 1125, 1124, 1113, 1098,
 /*    40 */  1096, 1084, 1082, 1067, 1051,  665,  638,  432, 1236, 1039,
 /*    50 */   936,  926,  874,  796,  769,  524,  463,  512,  481,   19,
 /*    60 */   -16,  -51,  -77,   53,  662,  426,  447,  516,  485,  447,
 /*    70 */   743,  735,  717,  716,  708,  689,  686,  636,  635,  633,
 /*    80 */   609,  573,  554,  552,  519,  484,  472,  135,  -13,  347,
 /*    90 */   320,  305,  300,  263,  248,  218,  188,  158,   98,   68,
 /*   100 */   288,  280,  261,  273,  268,  262,  240,  236,  220,  209,
 /*   110 */   220,  164,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   281,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    10 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    20 */   407,  282,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    30 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    40 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    50 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    60 */   407,  407,  407,  407,  281,  281,  320,  363,  359,  320,
 /*    70 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*    80 */   407,  407,  407,  407,  407,  407,  407,  407,  352,  346,
 /*    90 */   346,  346,  346,  346,  346,  346,  346,  346,  346,  346,
 /*   100 */   407,  407,  407,  407,  407,  282,  407,  305,  355,  407,
 /*   110 */   353,  390,  347,  348,  383,  381,  379,  377,  375,  374,
 /*   120 */   384,  349,  333,  332,  326,  324,  328,  302,  321,  341,
 /*   130 */   330,  320,  363,  359,  301,  407,  407,  407,  288,  407,
 /*   140 */   407,  407,  407,  407,  290,  407,  395,  407,  407,  407,
 /*   150 */   407,  407,  407,  407,  407,  407,  407,  407,  407,  407,
 /*   160 */   289,  407,  407,  407,  407,  407,  407,  338,  407,  407,
 /*   170 */   334,  320,  278,  407,  283,  295,  294,  298,  274,  314,
 /*   180 */   313,  300,  304,  306,  303,  312,  311,  310,  309,  308,
 /*   190 */   307,  299,  297,  296,  293,  292,  284,  387,  354,  351,
 /*   200 */   350,  287,  325,  327,  329,  331,  391,  291,  406,  397,
 /*   210 */   396,  394,  393,  392,  386,  405,  404,  403,  402,  401,
 /*   220 */   400,  399,  398,  382,  380,  378,  376,  385,  370,  368,
 /*   230 */   367,  366,  369,  372,  365,  364,  362,  371,  361,  360,
 /*   240 */   356,  373,  358,  357,  286,  285,  280,  279,  389,  388,
 /*   250 */   345,  344,  342,  343,  340,  339,  337,  336,  335,  323,
 /*   260 */   322,  321,  320,  319,  318,  317,  316,  315,  277,  276,
 /*   270 */   275,  273,
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
  "TRAIT",         "DEF",           "LP",            "RP",          
  "SQUARE",        "NUM",           "NIL",           "TRUE",        
  "FALSE",         "SELF",          "IVAR",          "LITSTR",      
  "RSB",           "TUPLE_START",   "DICT_START",    "RB",          
  "EQUAL",         "LB",            "PIPE",          "IF",          
  "UNLESS",        "WHILE",         "IMPORT",        "DOT_NAME",    
  "AS",            "TRY",           "RESCUE",        "OP2_SET",     
  "OP1_SET",       "OP0_SET",       "RAISE",         "error",       
  "program",       "opt_fin",       "l1",            "last_fin",    
  "fin",           "l1e",           "class",         "trait",       
  "def",           "stmt",          "fin_m",         "comma",       
  "seq",           "delim_seq",     "class_start",   "class_body",  
  "s2",            "trait_start",   "trait_body",    "def_start",   
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
 /*   4 */ "l1e ::= trait",
 /*   5 */ "l1e ::= def",
 /*   6 */ "l1e ::= stmt",
 /*   7 */ "fin_m ::= NL",
 /*   8 */ "fin_m ::= SEMI",
 /*   9 */ "opt_fin ::=",
 /*  10 */ "opt_fin ::= fin",
 /*  11 */ "last_fin ::= EOF",
 /*  12 */ "last_fin ::= fin EOF",
 /*  13 */ "fin ::= fin fin_m",
 /*  14 */ "fin ::= fin_m",
 /*  15 */ "comma ::= COMMA NL",
 /*  16 */ "comma ::= COMMA",
 /*  17 */ "seq ::= seq fin stmt",
 /*  18 */ "seq ::= stmt",
 /*  19 */ "delim_seq ::= seq opt_fin",
 /*  20 */ "class_start ::= CLASS",
 /*  21 */ "class_body ::= l1 fin END",
 /*  22 */ "class ::= class_start ID fin class_body",
 /*  23 */ "class ::= class_start ID LT s2 fin class_body",
 /*  24 */ "trait_start ::= TRAIT",
 /*  25 */ "trait_body ::= l1 fin END",
 /*  26 */ "trait ::= trait_start ID fin trait_body",
 /*  27 */ "def_start ::= DEF",
 /*  28 */ "def_body ::= seq fin END",
 /*  29 */ "arg ::= ID",
 /*  30 */ "arg ::= ID CAST np_recv",
 /*  31 */ "id_list ::= id_list comma arg",
 /*  32 */ "id_list ::= arg",
 /*  33 */ "def_args ::=",
 /*  34 */ "def_args ::= LP id_list RP",
 /*  35 */ "def_name ::= ID",
 /*  36 */ "def_name ::= OP0",
 /*  37 */ "def_name ::= LT",
 /*  38 */ "def_name ::= OP1",
 /*  39 */ "def_name ::= OP2",
 /*  40 */ "def_name ::= SQUARE",
 /*  41 */ "def ::= def_start def_name def_args fin def_body",
 /*  42 */ "def ::= def_start def_name def_args fin END",
 /*  43 */ "lit ::= NUM",
 /*  44 */ "lit ::= NIL",
 /*  45 */ "lit ::= TRUE",
 /*  46 */ "lit ::= FALSE",
 /*  47 */ "lit ::= SELF",
 /*  48 */ "lit ::= ID",
 /*  49 */ "lit ::= IVAR",
 /*  50 */ "lit ::= LITSTR",
 /*  51 */ "np_arg ::= lit",
 /*  52 */ "np_arg ::= np_arg OP0 np_arg",
 /*  53 */ "np_arg ::= np_arg OP0 LP s2 RP",
 /*  54 */ "np_arg ::= np_arg LT np_arg",
 /*  55 */ "np_arg ::= np_arg LT LP s2 RP",
 /*  56 */ "np_arg ::= np_arg OP1 np_arg",
 /*  57 */ "np_arg ::= np_arg OP1 LP s2 RP",
 /*  58 */ "np_arg ::= np_arg OP2 np_arg",
 /*  59 */ "np_arg ::= np_arg OP2 LP s2 RP",
 /*  60 */ "np_arg ::= np_arg CAST np_arg",
 /*  61 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  62 */ "np_arg ::= np_arg DOT",
 /*  63 */ "np_arg ::= np_arg DOT LP RP",
 /*  64 */ "np_arg ::= np_arg DOT LP np_arg_list RP",
 /*  65 */ "np_arg ::= np_arg DCOLON ID",
 /*  66 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  67 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  68 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  69 */ "np_arg ::= NOT np_arg",
 /*  70 */ "np_arg ::= lambda",
 /*  71 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  72 */ "np_arg ::= TUPLE_START np_arg_list RP",
 /*  73 */ "np_arg ::= DICT_START np_arg_list RB",
 /*  74 */ "np_arg_list_start ::=",
 /*  75 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  76 */ "np_arg_list_elems ::= np_arg",
 /*  77 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  78 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  79 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  80 */ "np_opt_kw_arg_list ::=",
 /*  81 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  82 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  83 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  84 */ "np_recv ::= lit",
 /*  85 */ "np_recv ::= ID LP RP",
 /*  86 */ "np_recv ::= ID LP np_arg_list RP",
 /*  87 */ "np_recv ::= np_recv DOT",
 /*  88 */ "np_recv ::= np_recv DOT LP RP",
 /*  89 */ "np_recv ::= np_recv DOT LP np_arg_list RP",
 /*  90 */ "np_recv ::= np_recv DCOLON ID",
 /*  91 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  92 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  93 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  94 */ "np_recv ::= lambda",
 /*  95 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  96 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  97 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  98 */ "np_recv ::= LP s2 RP",
 /*  99 */ "s2 ::= np_recv DOT np_arg_list",
 /* 100 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /* 101 */ "s2 ::= ID np_arg_list",
 /* 102 */ "s2 ::= np_recv CAST np_arg",
 /* 103 */ "s2 ::= np_recv OP0 np_arg",
 /* 104 */ "s2 ::= np_recv OP0 LP s2 RP",
 /* 105 */ "s2 ::= np_recv LT np_arg",
 /* 106 */ "s2 ::= np_recv LT LP s2 RP",
 /* 107 */ "s2 ::= np_recv OP1 np_arg",
 /* 108 */ "s2 ::= np_recv OP1 LP s2 RP",
 /* 109 */ "s2 ::= np_recv OP2 np_arg",
 /* 110 */ "s2 ::= np_recv OP2 LP s2 RP",
 /* 111 */ "s2 ::= np_recv NEQUAL np_arg",
 /* 112 */ "s2 ::= np_recv",
 /* 113 */ "s2 ::= NOT s2",
 /* 114 */ "stmt ::= s2",
 /* 115 */ "stmt ::= stmt AND s2",
 /* 116 */ "lambda_start ::= LB",
 /* 117 */ "lambda_args ::= PIPE ID PIPE",
 /* 118 */ "lambda_args ::=",
 /* 119 */ "lambda ::= lambda_start lambda_args opt_fin delim_seq RB",
 /* 120 */ "stmt ::= IF s2 fin seq fin END",
 /* 121 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 122 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 123 */ "stmt ::= IMPORT DOT_NAME",
 /* 124 */ "stmt ::= IMPORT DOT_NAME AS ID",
 /* 125 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 126 */ "stmt ::= ID EQUAL s2",
 /* 127 */ "stmt ::= ID OP2_SET s2",
 /* 128 */ "stmt ::= ID OP1_SET s2",
 /* 129 */ "stmt ::= ID OP0_SET s2",
 /* 130 */ "stmt ::= IVAR EQUAL s2",
 /* 131 */ "stmt ::= IVAR OP2_SET s2",
 /* 132 */ "stmt ::= IVAR OP1_SET s2",
 /* 133 */ "stmt ::= IVAR OP0_SET s2",
 /* 134 */ "stmt ::= RAISE s2",
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
  { 52, 3 },
  { 54, 3 },
  { 54, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 62, 1 },
  { 62, 1 },
  { 53, 0 },
  { 53, 1 },
  { 55, 1 },
  { 55, 2 },
  { 56, 2 },
  { 56, 1 },
  { 63, 2 },
  { 63, 1 },
  { 64, 3 },
  { 64, 1 },
  { 65, 2 },
  { 66, 1 },
  { 67, 3 },
  { 58, 4 },
  { 58, 6 },
  { 69, 1 },
  { 70, 3 },
  { 59, 4 },
  { 71, 1 },
  { 72, 3 },
  { 73, 1 },
  { 73, 3 },
  { 75, 3 },
  { 75, 1 },
  { 76, 0 },
  { 76, 3 },
  { 77, 1 },
  { 77, 1 },
  { 77, 1 },
  { 77, 1 },
  { 77, 1 },
  { 77, 1 },
  { 60, 5 },
  { 60, 5 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 79, 1 },
  { 79, 3 },
  { 79, 5 },
  { 79, 3 },
  { 79, 5 },
  { 79, 3 },
  { 79, 5 },
  { 79, 3 },
  { 79, 5 },
  { 79, 3 },
  { 79, 3 },
  { 79, 2 },
  { 79, 4 },
  { 79, 5 },
  { 79, 3 },
  { 79, 3 },
  { 79, 5 },
  { 79, 6 },
  { 79, 2 },
  { 79, 1 },
  { 79, 4 },
  { 79, 3 },
  { 79, 3 },
  { 82, 0 },
  { 83, 3 },
  { 83, 1 },
  { 84, 3 },
  { 85, 3 },
  { 85, 1 },
  { 86, 0 },
  { 86, 2 },
  { 80, 3 },
  { 80, 2 },
  { 74, 1 },
  { 74, 3 },
  { 74, 4 },
  { 74, 2 },
  { 74, 4 },
  { 74, 5 },
  { 74, 3 },
  { 74, 3 },
  { 74, 5 },
  { 74, 6 },
  { 74, 1 },
  { 74, 3 },
  { 74, 3 },
  { 74, 4 },
  { 74, 3 },
  { 68, 3 },
  { 68, 4 },
  { 68, 2 },
  { 68, 3 },
  { 68, 3 },
  { 68, 5 },
  { 68, 3 },
  { 68, 5 },
  { 68, 3 },
  { 68, 5 },
  { 68, 3 },
  { 68, 5 },
  { 68, 3 },
  { 68, 1 },
  { 68, 2 },
  { 61, 1 },
  { 61, 3 },
  { 87, 1 },
  { 88, 3 },
  { 88, 0 },
  { 81, 5 },
  { 61, 6 },
  { 61, 6 },
  { 61, 6 },
  { 61, 2 },
  { 61, 4 },
  { 61, 9 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy14.a)); }
#line 1255 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 17: /* seq ::= seq fin stmt */ yytestcase(yyruleno==17);
#line 34 "vm/parser.lm"
{ yygotominor.yy14.a = S->seq(yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1261 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= trait */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= def */ yytestcase(yyruleno==5);
      case 6: /* l1e ::= stmt */ yytestcase(yyruleno==6);
      case 18: /* seq ::= stmt */ yytestcase(yyruleno==18);
      case 51: /* np_arg ::= lit */ yytestcase(yyruleno==51);
      case 70: /* np_arg ::= lambda */ yytestcase(yyruleno==70);
      case 84: /* np_recv ::= lit */ yytestcase(yyruleno==84);
      case 94: /* np_recv ::= lambda */ yytestcase(yyruleno==94);
      case 112: /* s2 ::= np_recv */ yytestcase(yyruleno==112);
      case 114: /* stmt ::= s2 */ yytestcase(yyruleno==114);
#line 35 "vm/parser.lm"
{ yygotominor.yy14.a = yymsp[0].minor.yy14.a; }
#line 1277 "vm/parser.c.inc"
        break;
      case 19: /* delim_seq ::= seq opt_fin */
      case 98: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==98);
#line 60 "vm/parser.lm"
{ yygotominor.yy14.a = yymsp[-1].minor.yy14.a; }
#line 1283 "vm/parser.c.inc"
        break;
      case 20: /* class_start ::= CLASS */
#line 62 "vm/parser.lm"
{ S->start_class(); }
#line 1288 "vm/parser.c.inc"
        break;
      case 21: /* class_body ::= l1 fin END */
      case 25: /* trait_body ::= l1 fin END */ yytestcase(yyruleno==25);
      case 28: /* def_body ::= seq fin END */ yytestcase(yyruleno==28);
#line 63 "vm/parser.lm"
{ yygotominor.yy14.a = yymsp[-2].minor.yy14.a; }
#line 1295 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy14.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy14.a);
             }
#line 1302 "vm/parser.c.inc"
        break;
      case 23: /* class ::= class_start ID LT s2 fin class_body */
#line 69 "vm/parser.lm"
{
               yygotominor.yy14.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a);
             }
#line 1309 "vm/parser.c.inc"
        break;
      case 24: /* trait_start ::= TRAIT */
#line 73 "vm/parser.lm"
{ S->start_trait(); }
#line 1314 "vm/parser.c.inc"
        break;
      case 26: /* trait ::= trait_start ID fin trait_body */
#line 76 "vm/parser.lm"
{
               yygotominor.yy14.a = S->trait(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy14.a);
             }
#line 1321 "vm/parser.c.inc"
        break;
      case 27: /* def_start ::= DEF */
#line 80 "vm/parser.lm"
{ S->start_def(); }
#line 1326 "vm/parser.c.inc"
        break;
      case 29: /* arg ::= ID */
#line 83 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1331 "vm/parser.c.inc"
        break;
      case 30: /* arg ::= ID CAST np_recv */
#line 84 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1336 "vm/parser.c.inc"
        break;
      case 35: /* def_name ::= ID */
      case 36: /* def_name ::= OP0 */ yytestcase(yyruleno==36);
      case 37: /* def_name ::= LT */ yytestcase(yyruleno==37);
      case 38: /* def_name ::= OP1 */ yytestcase(yyruleno==38);
      case 39: /* def_name ::= OP2 */ yytestcase(yyruleno==39);
      case 40: /* def_name ::= SQUARE */ yytestcase(yyruleno==40);
#line 92 "vm/parser.lm"
{ yygotominor.yy14.s = yymsp[0].minor.yy0.s; }
#line 1346 "vm/parser.c.inc"
        break;
      case 41: /* def ::= def_start def_name def_args fin def_body */
#line 100 "vm/parser.lm"
{
              yygotominor.yy14.a = S->ast_def(yymsp[-3].minor.yy14.s, yymsp[0].minor.yy14.a);
            }
#line 1353 "vm/parser.c.inc"
        break;
      case 42: /* def ::= def_start def_name def_args fin END */
#line 103 "vm/parser.lm"
{
              yygotominor.yy14.a = S->ast_def(yymsp[-3].minor.yy14.s, S->ast_nil());
            }
#line 1360 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= NUM */
#line 107 "vm/parser.lm"
{ yygotominor.yy14.a = S->number(yymsp[0].minor.yy0.i); }
#line 1365 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= NIL */
#line 108 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_nil();  }
#line 1370 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= TRUE */
#line 109 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_true();  }
#line 1375 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= FALSE */
#line 110 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_false(); }
#line 1380 "vm/parser.c.inc"
        break;
      case 47: /* lit ::= SELF */
#line 111 "vm/parser.lm"
{ yygotominor.yy14.a = S->self(); }
#line 1385 "vm/parser.c.inc"
        break;
      case 48: /* lit ::= ID */
#line 112 "vm/parser.lm"
{ yygotominor.yy14.a = S->named(yymsp[0].minor.yy0.s); }
#line 1390 "vm/parser.c.inc"
        break;
      case 49: /* lit ::= IVAR */
#line 113 "vm/parser.lm"
{ yygotominor.yy14.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1395 "vm/parser.c.inc"
        break;
      case 50: /* lit ::= LITSTR */
#line 114 "vm/parser.lm"
{ yygotominor.yy14.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1400 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg OP0 np_arg */
      case 54: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==54);
      case 56: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==56);
      case 103: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==103);
      case 105: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==105);
      case 107: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==107);
#line 119 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1410 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 55: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==55);
      case 57: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==57);
      case 104: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==104);
      case 106: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==106);
      case 108: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==108);
#line 121 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy14.a, yymsp[-1].minor.yy14.a); }
#line 1420 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg OP2 np_arg */
      case 109: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==109);
#line 134 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1426 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 110: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==110);
#line 136 "vm/parser.lm"
{ yygotominor.yy14.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy14.a, yymsp[-1].minor.yy14.a); }
#line 1432 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg CAST np_arg */
      case 102: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==102);
#line 139 "vm/parser.lm"
{ yygotominor.yy14.a = S->cast(yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1438 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg NEQUAL np_arg */
      case 111: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==111);
#line 141 "vm/parser.lm"
{ yygotominor.yy14.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a)); }
#line 1444 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT */
      case 87: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==87);
#line 142 "vm/parser.lm"
{ yygotominor.yy14.a = S->call(yymsp[-1].minor.yy14.a, yymsp[0].minor.yy0.s); }
#line 1450 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT LP RP */
      case 88: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy14.a = S->call(yymsp[-3].minor.yy14.a, yymsp[-2].minor.yy0.s); }
#line 1456 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy14.a = S->call_args(yymsp[-4].minor.yy14.a, yymsp[-3].minor.yy0.s); }
#line 1462 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= np_arg DCOLON ID */
      case 90: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==90);
#line 146 "vm/parser.lm"
{ yygotominor.yy14.a = S->dcolon(yymsp[-2].minor.yy14.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1468 "vm/parser.c.inc"
        break;
      case 66: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 91: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==91);
#line 149 "vm/parser.lm"
{ yygotominor.yy14.a = S->send_indirect(yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1474 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 92: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==92);
#line 151 "vm/parser.lm"
{ yygotominor.yy14.a = S->send_indirect(yymsp[-4].minor.yy14.a, yymsp[-2].minor.yy14.a); }
#line 1480 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 93: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==93);
#line 153 "vm/parser.lm"
{ yygotominor.yy14.a = S->send_indirect_args(yymsp[-5].minor.yy14.a, yymsp[-3].minor.yy14.a); }
#line 1486 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= NOT np_arg */
      case 113: /* s2 ::= NOT s2 */ yytestcase(yyruleno==113);
#line 154 "vm/parser.lm"
{ yygotominor.yy14.a = S->not_(yymsp[0].minor.yy14.a); }
#line 1492 "vm/parser.c.inc"
        break;
      case 71: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 97: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==97);
#line 157 "vm/parser.lm"
{ yygotominor.yy14.a = S->call_args(yymsp[-3].minor.yy14.a, "[]"); }
#line 1498 "vm/parser.c.inc"
        break;
      case 72: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 95: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==95);
#line 159 "vm/parser.lm"
{ yygotominor.yy14.a = S->tuple(); }
#line 1504 "vm/parser.c.inc"
        break;
      case 73: /* np_arg ::= DICT_START np_arg_list RB */
      case 96: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==96);
#line 160 "vm/parser.lm"
{ yygotominor.yy14.a = S->dict(); }
#line 1510 "vm/parser.c.inc"
        break;
      case 74: /* np_arg_list_start ::= */
#line 162 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1515 "vm/parser.c.inc"
        break;
      case 75: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 76: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==76);
#line 163 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy14.a); }
#line 1521 "vm/parser.c.inc"
        break;
      case 77: /* np_kw_arg ::= ID EQUAL np_arg */
#line 166 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1526 "vm/parser.c.inc"
        break;
      case 85: /* np_recv ::= ID LP RP */
#line 178 "vm/parser.lm"
{ yygotominor.yy14.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1531 "vm/parser.c.inc"
        break;
      case 86: /* np_recv ::= ID LP np_arg_list RP */
#line 179 "vm/parser.lm"
{ yygotominor.yy14.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1536 "vm/parser.c.inc"
        break;
      case 99: /* s2 ::= np_recv DOT np_arg_list */
#line 197 "vm/parser.lm"
{ yygotominor.yy14.a = S->call_args(yymsp[-2].minor.yy14.a, yymsp[-1].minor.yy0.s); }
#line 1541 "vm/parser.c.inc"
        break;
      case 100: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 199 "vm/parser.lm"
{ yygotominor.yy14.a = S->send_indirect_args(yymsp[-3].minor.yy14.a, yymsp[-1].minor.yy14.a); }
#line 1546 "vm/parser.c.inc"
        break;
      case 101: /* s2 ::= ID np_arg_list */
#line 200 "vm/parser.lm"
{ yygotominor.yy14.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1551 "vm/parser.c.inc"
        break;
      case 115: /* stmt ::= stmt AND s2 */
#line 216 "vm/parser.lm"
{ yygotominor.yy14.a = S->and_(yymsp[-2].minor.yy14.a, yymsp[0].minor.yy14.a); }
#line 1556 "vm/parser.c.inc"
        break;
      case 116: /* lambda_start ::= LB */
#line 220 "vm/parser.lm"
{ S->start_lambda(); }
#line 1561 "vm/parser.c.inc"
        break;
      case 117: /* lambda_args ::= PIPE ID PIPE */
#line 222 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1566 "vm/parser.c.inc"
        break;
      case 119: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 225 "vm/parser.lm"
{ yygotominor.yy14.a = S->lambda(yymsp[-1].minor.yy14.a); }
#line 1571 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= IF s2 fin seq fin END */
#line 229 "vm/parser.lm"
{ yygotominor.yy14.a = S->if_cond(yymsp[-4].minor.yy14.a, yymsp[-2].minor.yy14.a); }
#line 1576 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= UNLESS s2 fin seq fin END */
#line 230 "vm/parser.lm"
{ yygotominor.yy14.a = S->unless(yymsp[-4].minor.yy14.a, yymsp[-2].minor.yy14.a); }
#line 1581 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= WHILE s2 fin seq fin END */
#line 231 "vm/parser.lm"
{ yygotominor.yy14.a = S->while_(yymsp[-4].minor.yy14.a, yymsp[-2].minor.yy14.a); }
#line 1586 "vm/parser.c.inc"
        break;
      case 123: /* stmt ::= IMPORT DOT_NAME */
#line 235 "vm/parser.lm"
{ yygotominor.yy14.a = S->import(yymsp[0].minor.yy0.s); }
#line 1591 "vm/parser.c.inc"
        break;
      case 124: /* stmt ::= IMPORT DOT_NAME AS ID */
#line 236 "vm/parser.lm"
{ yygotominor.yy14.a = S->import(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1596 "vm/parser.c.inc"
        break;
      case 125: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 238 "vm/parser.lm"
{
              yygotominor.yy14.a = S->ast_try(yymsp[-6].minor.yy14.a, yymsp[-2].minor.yy14.a);
            }
#line 1603 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= ID EQUAL s2 */
#line 242 "vm/parser.lm"
{ yygotominor.yy14.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1608 "vm/parser.c.inc"
        break;
      case 127: /* stmt ::= ID OP2_SET s2 */
      case 128: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==128);
      case 129: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==129);
#line 243 "vm/parser.lm"
{ yygotominor.yy14.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1615 "vm/parser.c.inc"
        break;
      case 130: /* stmt ::= IVAR EQUAL s2 */
#line 246 "vm/parser.lm"
{ yygotominor.yy14.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1620 "vm/parser.c.inc"
        break;
      case 131: /* stmt ::= IVAR OP2_SET s2 */
      case 132: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==132);
      case 133: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==133);
#line 248 "vm/parser.lm"
{ yygotominor.yy14.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy14.a); }
#line 1627 "vm/parser.c.inc"
        break;
      case 134: /* stmt ::= RAISE s2 */
#line 253 "vm/parser.lm"
{ yygotominor.yy14.a = S->raise(yymsp[0].minor.yy14.a); }
#line 1632 "vm/parser.c.inc"
        break;
      default:
      /* (7) fin_m ::= NL */ yytestcase(yyruleno==7);
      /* (8) fin_m ::= SEMI */ yytestcase(yyruleno==8);
      /* (9) opt_fin ::= */ yytestcase(yyruleno==9);
      /* (10) opt_fin ::= fin */ yytestcase(yyruleno==10);
      /* (11) last_fin ::= EOF */ yytestcase(yyruleno==11);
      /* (12) last_fin ::= fin EOF */ yytestcase(yyruleno==12);
      /* (13) fin ::= fin fin_m */ yytestcase(yyruleno==13);
      /* (14) fin ::= fin_m */ yytestcase(yyruleno==14);
      /* (15) comma ::= COMMA NL */ yytestcase(yyruleno==15);
      /* (16) comma ::= COMMA */ yytestcase(yyruleno==16);
      /* (31) id_list ::= id_list comma arg */ yytestcase(yyruleno==31);
      /* (32) id_list ::= arg */ yytestcase(yyruleno==32);
      /* (33) def_args ::= */ yytestcase(yyruleno==33);
      /* (34) def_args ::= LP id_list RP */ yytestcase(yyruleno==34);
      /* (78) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==78);
      /* (79) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==79);
      /* (80) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==80);
      /* (81) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==81);
      /* (82) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==82);
      /* (83) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==83);
      /* (118) lambda_args ::= */ yytestcase(yyruleno==118);
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
#line 1721 "vm/parser.c.inc"
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
