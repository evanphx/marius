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
#define YYNOCODE 92
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
#define YYNSTATE 300
#define YYNRULE 143
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
#define YY_ACTTAB_COUNT (1534)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    50,  271,  138,  300,  264,  294,  293,  292,   80,  290,
 /*    10 */   125,   75,  288,  286,   51,  294,  293,  279,  278,  277,
 /*    20 */   276,  275,  145,  272,   98,  109,  108,  107,   71,  105,
 /*    30 */   260,   38,  153,   37,   36,  163,   50,   27,   88,  203,
 /*    40 */    28,  294,  293,   35,  104,  290,  289,   75,  288,  286,
 /*    50 */    51,  294,  293,  279,  278,  277,  276,  275,  145,  272,
 /*    60 */   207,  109,  108,  107,   70,  269,  260,   38,  268,   37,
 /*    70 */    36,  163,   50,  202,   88,  119,  103,  294,  293,   35,
 /*    80 */   266,  290,  287,   75,  288,  286,   51,  261,  265,  279,
 /*    90 */   278,  277,  276,  275,  145,  272,  263,  109,  108,  107,
 /*   100 */   262,  177,  260,   38,  259,   37,   36,  163,   50,   16,
 /*   110 */    88,  255,  120,  294,  293,   35,  251,  290,  258,   75,
 /*   120 */   288,  286,   51,  247,  249,  279,  278,  277,  276,  275,
 /*   130 */   145,  272,  245,  109,  108,  107,  244,  242,  260,   38,
 /*   140 */   240,   37,   36,  163,   50,  239,   88,  243,  238,  294,
 /*   150 */   293,   35,  193,    6,  226,   75,  237,  236,   51,  258,
 /*   160 */   162,  279,  278,  277,  276,  275,  145,  272,  161,  109,
 /*   170 */   108,  107,  222,   34,  260,   38,   94,   37,   36,  163,
 /*   180 */    50,  216,   88,  215,  214,  294,  293,   35,  213,  212,
 /*   190 */   225,   75,  211,  182,   51,   26,  210,  279,  278,  277,
 /*   200 */   276,  275,  145,  272,  205,  109,  108,  107,  101,  102,
 /*   210 */   260,   38,   83,   37,   36,  163,   50,  106,   88,   74,
 /*   220 */   178,  294,  293,   35,  209,  153,  224,   75,  123,  181,
 /*   230 */    51,   26,  152,  279,  278,  277,  276,  275,  145,  272,
 /*   240 */   190,  109,  108,  107,  121,  204,  260,   38,  291,   37,
 /*   250 */    36,  163,   50,  126,   88,  184,   76,  294,  293,   35,
 /*   260 */   206,  150,  223,   75,  270,  180,   51,   26,  267,  279,
 /*   270 */   278,  277,  276,  275,  145,  272,  256,  109,  108,  107,
 /*   280 */   250,  445,  260,   38,  445,   37,   36,  163,   50,  445,
 /*   290 */    88,  445,  445,  294,  293,   35,  445,  294,  293,   75,
 /*   300 */   445,  445,   51,  160,  445,  279,  278,  277,  276,  275,
 /*   310 */   145,  272,  445,  109,  108,  107,  445,  445,  260,   38,
 /*   320 */   445,   37,   36,  163,   50,  445,   88,   79,  445,  294,
 /*   330 */   293,   35,  445,  445,  221,   75,  445,  179,   51,   26,
 /*   340 */   445,  279,  278,  277,  276,  275,  145,  272,  445,  109,
 /*   350 */   108,  107,  445,  445,  260,   38,  445,   37,   36,  163,
 /*   360 */    50,  445,   88,  445,  445,  294,  293,   35,  445,  445,
 /*   370 */   218,   75,  445,  173,   51,   26,  445,  279,  278,  277,
 /*   380 */   276,  275,  145,  272,  445,  109,  108,  107,  445,  445,
 /*   390 */   260,   38,  445,   37,   36,  163,   50,  445,   88,  445,
 /*   400 */   445,  294,  293,   35,  445,  445,  201,   75,  445,  172,
 /*   410 */    51,   26,  445,  279,  278,  277,  276,  275,  145,  272,
 /*   420 */   445,  109,  108,  107,  445,  445,  260,   38,  445,   37,
 /*   430 */    36,  163,   50,  445,   88,  445,  445,  294,  293,   35,
 /*   440 */   445,  445,  199,   75,  445,  171,   51,   26,  445,  279,
 /*   450 */   278,  277,  276,  275,  145,  272,  445,  109,  108,  107,
 /*   460 */    50,  445,  260,   38,  445,   37,   36,  163,  445,  290,
 /*   470 */    88,   75,  288,  286,   51,   35,  445,  279,  278,  277,
 /*   480 */   276,  275,  145,  272,  445,  109,  108,  107,  445,  445,
 /*   490 */   260,   38,  445,   37,   36,  163,   50,  170,   88,   26,
 /*   500 */   445,  294,  293,   35,  151,  445,   26,   75,  445,  186,
 /*   510 */    51,   26,  445,  279,  278,  277,  276,  275,  145,  272,
 /*   520 */   445,  109,  108,  107,   50,  445,  260,   38,  445,   37,
 /*   530 */    36,  163,  445,  445,   88,   75,  445,  445,   51,   35,
 /*   540 */   445,  279,  278,  277,  276,  275,  145,  272,  445,  109,
 /*   550 */   108,  107,  377,  445,  260,   38,  445,   37,   36,  163,
 /*   560 */   445,  445,   88,  377,  445,  445,  102,   35,  445,  377,
 /*   570 */   377,  377,  377,  377,  377,  377,  445,  377,  377,  377,
 /*   580 */   445,   53,  377,   99,  445,  445,  198,  298,  297,  296,
 /*   590 */   295,  291,   45,   44,   43,  192,  196,  227,  191,  445,
 /*   600 */   118,  444,    7,  127,  445,  120,  217,  253,  445,   25,
 /*   610 */   246,  258,   42,  445,   97,  258,  125,  198,  298,  297,
 /*   620 */   296,  295,  291,   41,   40,   39,  192,  445,  227,  191,
 /*   630 */   197,  118,  445,    5,  127,  294,  293,  194,  253,  258,
 /*   640 */     2,  246,  183,  445,   26,   99,  258,  125,  198,  298,
 /*   650 */   297,  296,  295,  291,  176,    4,   26,  192,  195,  227,
 /*   660 */   191,  258,  118,  377,  445,  127,  148,  445,  445,  253,
 /*   670 */   253,  445,  246,  246,  377,  445,  445,  102,  125,  125,
 /*   680 */   377,  377,  377,  377,  377,  377,  377,  377,  377,  377,
 /*   690 */   377,  445,   59,  377,  187,  185,  117,  114,  377,  445,
 /*   700 */   174,  105,   26,  445,  377,  377,  377,  377,  377,  377,
 /*   710 */   377,  377,  377,  377,  377,  445,  445,  377,  189,  175,
 /*   720 */   115,  110,  377,  445,  254,  101,   26,  445,  377,  377,
 /*   730 */   377,  377,  377,  377,  377,   67,  377,  377,  377,  445,
 /*   740 */   445,  377,  187,  185,  117,  114,  274,  445,  252,   29,
 /*   750 */    26,  445,  279,  278,  277,  276,  275,  273,  272,   67,
 /*   760 */   113,  112,  111,  271,  140,  260,  264,  445,   15,   17,
 /*   770 */   274,  445,  125,   30,  258,  258,  279,  278,  277,  276,
 /*   780 */   275,  273,  272,   67,  113,  112,  111,  271,  139,  260,
 /*   790 */   264,  445,   14,   24,  274,  445,  125,   31,  258,  258,
 /*   800 */   279,  278,  277,  276,  275,  273,  272,   67,  113,  112,
 /*   810 */   111,  271,  146,  260,  264,  445,   13,   23,  274,  445,
 /*   820 */   125,   32,  258,  258,  279,  278,  277,  276,  275,  273,
 /*   830 */   272,   67,  113,  112,  111,  271,  137,  260,  264,  445,
 /*   840 */    12,   22,  274,  445,  125,   33,  258,  258,  279,  278,
 /*   850 */   277,  276,  275,  273,  272,   67,  113,  112,  111,  271,
 /*   860 */   131,  260,  264,  445,   11,   21,  274,  445,  125,   52,
 /*   870 */   258,  258,  279,  278,  277,  276,  275,  273,  272,   67,
 /*   880 */   113,  112,  111,  271,  130,  260,  264,  445,   20,    9,
 /*   890 */   274,  445,  125,   49,  258,  258,  279,  278,  277,  276,
 /*   900 */   275,  273,  272,   67,  113,  112,  111,  271,  142,  260,
 /*   910 */   264,  445,   19,    8,  274,  445,  125,   48,  258,  258,
 /*   920 */   279,  278,  277,  276,  275,  273,  272,   67,  113,  112,
 /*   930 */   111,  271,  141,  260,  264,  445,   18,    1,  274,  445,
 /*   940 */   125,   47,  258,  258,  279,  278,  277,  276,  275,  273,
 /*   950 */   272,   67,  113,  112,  111,  271,  144,  260,  264,  445,
 /*   960 */     3,   10,  274,  445,  125,   46,  258,  258,  279,  278,
 /*   970 */   277,  276,  275,  273,  272,   50,  113,  112,  111,  271,
 /*   980 */   143,  260,  264,  248,  445,   26,   78,  445,  125,   51,
 /*   990 */   445,  445,  279,  278,  277,  276,  275,  273,  272,  445,
 /*  1000 */   109,  108,  107,   72,  445,  260,  198,  298,  297,  296,
 /*  1010 */   295,  445,  445,  271,  147,  192,  264,  227,  191,  445,
 /*  1020 */   118,  445,  125,  127,  445,  271,  128,  253,  264,  445,
 /*  1030 */   246,  208,  124,  445,  125,  445,  125,  299,  298,  297,
 /*  1040 */   296,  295,  291,  445,  445,  445,  192,  235,  227,  191,
 /*  1050 */   445,  118,  445,  127,  127,  445,  445,  253,  253,  445,
 /*  1060 */   246,  246,  149,  445,  445,   51,  125,  125,  279,  278,
 /*  1070 */   277,  276,  275,  273,  272,   67,  109,  108,  107,  445,
 /*  1080 */   445,  260,  445,   61,   60,   59,  274,  187,  185,  117,
 /*  1090 */   114,  445,  279,  278,  277,  276,  275,  273,  272,  445,
 /*  1100 */   113,  112,  111,   67,  445,  260,  271,  136,  445,  264,
 /*  1110 */   445,  445,  445,  445,  188,  125,  445,  445,  445,  445,
 /*  1120 */   279,  278,  277,  276,  275,  273,  272,  445,  113,  112,
 /*  1130 */   111,  445,  445,  260,  445,   64,   58,   57,   66,   65,
 /*  1140 */    56,   55,   54,  445,   77,  175,  116,  110,   63,   62,
 /*  1150 */    69,   68,   61,   60,   59,  445,  187,  185,  117,  114,
 /*  1160 */   219,  291,  445,   82,  445,  445,  445,  227,  445,  271,
 /*  1170 */   129,  200,  264,  127,  100,  208,  122,  253,  125,  445,
 /*  1180 */   246,  274,  445,  445,  445,  445,  125,  279,  278,  277,
 /*  1190 */   276,  275,  273,  272,  219,  445,  445,   73,  159,  219,
 /*  1200 */   291,  227,   95,  445,  445,  445,  227,  127,  445,  284,
 /*  1210 */   283,  253,  127,  282,  246,  281,  253,  445,  445,  246,
 /*  1220 */   125,  219,  291,  168,   93,  125,  445,  285,  227,  127,
 /*  1230 */   445,  445,  280,  253,  127,  445,  246,  445,  253,  445,
 /*  1240 */   445,  246,  125,  445,  445,  219,  291,  125,   91,  445,
 /*  1250 */   219,  291,  227,   89,  445,  445,  445,  227,  127,  445,
 /*  1260 */   445,  445,  253,  127,  445,  246,  445,  253,  445,  445,
 /*  1270 */   246,  125,  445,  445,  445,  445,  125,  445,  219,  291,
 /*  1280 */   445,   87,  445,  219,  291,  227,   86,  445,  445,  445,
 /*  1290 */   227,  127,  445,  445,  445,  253,  127,  445,  246,  445,
 /*  1300 */   253,  445,  445,  246,  125,  219,  291,  445,   84,  125,
 /*  1310 */   257,  291,  227,  445,  445,  445,  445,  227,  127,  445,
 /*  1320 */   445,  445,  253,  127,  445,  246,  445,  253,  169,  241,
 /*  1330 */   246,  125,  445,  445,  127,  127,  125,  445,  253,  253,
 /*  1340 */   445,  246,  246,  271,  135,  445,  264,  125,  125,  167,
 /*  1350 */   166,  445,  125,  445,  445,  127,  127,  445,  445,  253,
 /*  1360 */   253,  165,  246,  246,  445,  445,  164,  127,  125,  125,
 /*  1370 */   445,  253,  127,  445,  246,  445,  253,  234,  445,  246,
 /*  1380 */   125,  445,  233,  127,  445,  125,  445,  253,  127,  445,
 /*  1390 */   246,  445,  253,  232,  231,  246,  125,  445,  445,  127,
 /*  1400 */   127,  125,  445,  253,  253,  230,  246,  246,  445,  445,
 /*  1410 */   229,  127,  125,  125,  445,  253,  127,  445,  246,  445,
 /*  1420 */   253,  228,  445,  246,  125,  445,   96,  127,  445,  125,
 /*  1430 */   445,  253,  127,  445,  246,  445,  253,   92,   90,  246,
 /*  1440 */   125,  445,  445,  127,  127,  125,  445,  253,  253,  445,
 /*  1450 */   246,  246,  445,  220,   85,  445,  125,  125,  445,  127,
 /*  1460 */   127,  445,  445,  253,  253,  158,  246,  246,  445,  445,
 /*  1470 */   157,  127,  125,  125,  445,  253,  127,  445,  246,  445,
 /*  1480 */   253,  156,  155,  246,  125,  445,  445,  127,  127,  125,
 /*  1490 */   445,  253,  253,  445,  246,  246,  445,  154,   81,  445,
 /*  1500 */   125,  125,  445,  127,  127,  445,  445,  253,  253,  445,
 /*  1510 */   246,  246,  271,  134,  445,  264,  125,  125,  445,  271,
 /*  1520 */   133,  125,  264,  445,  271,  132,  445,  264,  125,  445,
 /*  1530 */   445,  445,  445,  125,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     9,   80,   81,    0,   83,   14,   15,   16,   20,   18,
 /*    10 */    89,   20,   21,   22,   23,   14,   15,   26,   27,   28,
 /*    20 */    29,   30,   31,   32,   20,   34,   35,   36,    4,   23,
 /*    30 */    39,   40,   17,   42,   43,   44,    9,   65,   47,   24,
 /*    40 */     3,   14,   15,   52,   23,   18,   19,   20,   21,   22,
 /*    50 */    23,   14,   15,   26,   27,   28,   29,   30,   31,   32,
 /*    60 */    88,   34,   35,   36,   38,   24,   39,   40,   20,   42,
 /*    70 */    43,   44,    9,   75,   47,   77,   23,   14,   15,   52,
 /*    80 */    24,   18,   19,   20,   21,   22,   23,   37,   33,   26,
 /*    90 */    27,   28,   29,   30,   31,   32,   24,   34,   35,   36,
 /*   100 */    33,   20,   39,   40,    7,   42,   43,   44,    9,   55,
 /*   110 */    47,   24,   58,   14,   15,   52,   20,   18,   64,   20,
 /*   120 */    21,   22,   23,   33,   24,   26,   27,   28,   29,   30,
 /*   130 */    31,   32,   24,   34,   35,   36,   33,   24,   39,   40,
 /*   140 */    24,   42,   43,   44,    9,   24,   47,   37,   24,   14,
 /*   150 */    15,   52,   57,   58,   19,   20,   24,   24,   23,   64,
 /*   160 */    45,   26,   27,   28,   29,   30,   31,   32,   46,   34,
 /*   170 */    35,   36,   20,    4,   39,   40,   41,   42,   43,   44,
 /*   180 */     9,   37,   47,   24,   24,   14,   15,   52,   24,   24,
 /*   190 */    19,   20,   24,   82,   23,   84,   14,   26,   27,   28,
 /*   200 */    29,   30,   31,   32,   24,   34,   35,   36,   23,   23,
 /*   210 */    39,   40,   78,   42,   43,   44,    9,   23,   47,   90,
 /*   220 */     7,   14,   15,   52,   86,   17,   19,   20,   65,   82,
 /*   230 */    23,   84,   20,   26,   27,   28,   29,   30,   31,   32,
 /*   240 */    20,   34,   35,   36,   65,   75,   39,   40,   64,   42,
 /*   250 */    43,   44,    9,   79,   47,   80,   80,   14,   15,   52,
 /*   260 */    24,   80,   19,   20,   24,   82,   23,   84,   24,   26,
 /*   270 */    27,   28,   29,   30,   31,   32,   24,   34,   35,   36,
 /*   280 */    24,   91,   39,   40,   91,   42,   43,   44,    9,   91,
 /*   290 */    47,   91,   91,   14,   15,   52,   91,   14,   15,   20,
 /*   300 */    91,   91,   23,   20,   91,   26,   27,   28,   29,   30,
 /*   310 */    31,   32,   91,   34,   35,   36,   91,   91,   39,   40,
 /*   320 */    91,   42,   43,   44,    9,   91,   47,   48,   91,   14,
 /*   330 */    15,   52,   91,   91,   19,   20,   91,   82,   23,   84,
 /*   340 */    91,   26,   27,   28,   29,   30,   31,   32,   91,   34,
 /*   350 */    35,   36,   91,   91,   39,   40,   91,   42,   43,   44,
 /*   360 */     9,   91,   47,   91,   91,   14,   15,   52,   91,   91,
 /*   370 */    19,   20,   91,   82,   23,   84,   91,   26,   27,   28,
 /*   380 */    29,   30,   31,   32,   91,   34,   35,   36,   91,   91,
 /*   390 */    39,   40,   91,   42,   43,   44,    9,   91,   47,   91,
 /*   400 */    91,   14,   15,   52,   91,   91,   19,   20,   91,   82,
 /*   410 */    23,   84,   91,   26,   27,   28,   29,   30,   31,   32,
 /*   420 */    91,   34,   35,   36,   91,   91,   39,   40,   91,   42,
 /*   430 */    43,   44,    9,   91,   47,   91,   91,   14,   15,   52,
 /*   440 */    91,   91,   19,   20,   91,   82,   23,   84,   91,   26,
 /*   450 */    27,   28,   29,   30,   31,   32,   91,   34,   35,   36,
 /*   460 */     9,   91,   39,   40,   91,   42,   43,   44,   91,   18,
 /*   470 */    47,   20,   21,   22,   23,   52,   91,   26,   27,   28,
 /*   480 */    29,   30,   31,   32,   91,   34,   35,   36,   91,   91,
 /*   490 */    39,   40,   91,   42,   43,   44,    9,   82,   47,   84,
 /*   500 */    91,   14,   15,   52,   82,   91,   84,   20,   91,   82,
 /*   510 */    23,   84,   91,   26,   27,   28,   29,   30,   31,   32,
 /*   520 */    91,   34,   35,   36,    9,   91,   39,   40,   91,   42,
 /*   530 */    43,   44,   91,   91,   47,   20,   91,   91,   23,   52,
 /*   540 */    91,   26,   27,   28,   29,   30,   31,   32,   91,   34,
 /*   550 */    35,   36,    9,   91,   39,   40,   91,   42,   43,   44,
 /*   560 */    91,   91,   47,   20,   91,   91,   23,   52,   91,   26,
 /*   570 */    27,   28,   29,   30,   31,   32,   91,   34,   35,   36,
 /*   580 */    91,   38,   39,   56,   91,   91,   59,   60,   61,   62,
 /*   590 */    63,   64,   49,   50,   51,   68,   69,   70,   71,   91,
 /*   600 */    73,   54,   55,   76,   91,   58,   55,   80,   91,   58,
 /*   610 */    83,   64,   38,   91,   56,   64,   89,   59,   60,   61,
 /*   620 */    62,   63,   64,   49,   50,   51,   68,   91,   70,   71,
 /*   630 */    72,   73,   91,   58,   76,   14,   15,   16,   80,   64,
 /*   640 */    58,   83,   82,   91,   84,   56,   64,   89,   59,   60,
 /*   650 */    61,   62,   63,   64,   82,   58,   84,   68,   69,   70,
 /*   660 */    71,   64,   73,    9,   91,   76,   76,   91,   91,   80,
 /*   670 */    80,   91,   83,   83,   20,   91,   91,   23,   89,   89,
 /*   680 */    26,   27,   28,   29,   30,   31,   32,    9,   34,   35,
 /*   690 */    36,   91,    8,   39,   10,   11,   12,   13,   20,   91,
 /*   700 */    82,   23,   84,   91,   26,   27,   28,   29,   30,   31,
 /*   710 */    32,    9,   34,   35,   36,   91,   91,   39,   10,   11,
 /*   720 */    12,   13,   20,   91,   82,   23,   84,   91,   26,   27,
 /*   730 */    28,   29,   30,   31,   32,    9,   34,   35,   36,   91,
 /*   740 */    91,   39,   10,   11,   12,   13,   20,   91,   82,   23,
 /*   750 */    84,   91,   26,   27,   28,   29,   30,   31,   32,    9,
 /*   760 */    34,   35,   36,   80,   81,   39,   83,   91,   58,   58,
 /*   770 */    20,   91,   89,   23,   64,   64,   26,   27,   28,   29,
 /*   780 */    30,   31,   32,    9,   34,   35,   36,   80,   81,   39,
 /*   790 */    83,   91,   58,   58,   20,   91,   89,   23,   64,   64,
 /*   800 */    26,   27,   28,   29,   30,   31,   32,    9,   34,   35,
 /*   810 */    36,   80,   81,   39,   83,   91,   58,   58,   20,   91,
 /*   820 */    89,   23,   64,   64,   26,   27,   28,   29,   30,   31,
 /*   830 */    32,    9,   34,   35,   36,   80,   81,   39,   83,   91,
 /*   840 */    58,   58,   20,   91,   89,   23,   64,   64,   26,   27,
 /*   850 */    28,   29,   30,   31,   32,    9,   34,   35,   36,   80,
 /*   860 */    81,   39,   83,   91,   58,   58,   20,   91,   89,   23,
 /*   870 */    64,   64,   26,   27,   28,   29,   30,   31,   32,    9,
 /*   880 */    34,   35,   36,   80,   81,   39,   83,   91,   58,   58,
 /*   890 */    20,   91,   89,   23,   64,   64,   26,   27,   28,   29,
 /*   900 */    30,   31,   32,    9,   34,   35,   36,   80,   81,   39,
 /*   910 */    83,   91,   58,   58,   20,   91,   89,   23,   64,   64,
 /*   920 */    26,   27,   28,   29,   30,   31,   32,    9,   34,   35,
 /*   930 */    36,   80,   81,   39,   83,   91,   58,   58,   20,   91,
 /*   940 */    89,   23,   64,   64,   26,   27,   28,   29,   30,   31,
 /*   950 */    32,    9,   34,   35,   36,   80,   81,   39,   83,   91,
 /*   960 */    58,   58,   20,   91,   89,   23,   64,   64,   26,   27,
 /*   970 */    28,   29,   30,   31,   32,    9,   34,   35,   36,   80,
 /*   980 */    81,   39,   83,   82,   91,   84,   20,   91,   89,   23,
 /*   990 */    91,   91,   26,   27,   28,   29,   30,   31,   32,   91,
 /*  1000 */    34,   35,   36,   56,   91,   39,   59,   60,   61,   62,
 /*  1010 */    63,   91,   91,   80,   81,   68,   83,   70,   71,   91,
 /*  1020 */    73,   91,   89,   76,   91,   80,   81,   80,   83,   91,
 /*  1030 */    83,   86,   87,   91,   89,   91,   89,   59,   60,   61,
 /*  1040 */    62,   63,   64,   91,   91,   91,   68,   70,   70,   71,
 /*  1050 */    91,   73,   91,   76,   76,   91,   91,   80,   80,   91,
 /*  1060 */    83,   83,   20,   91,   91,   23,   89,   89,   26,   27,
 /*  1070 */    28,   29,   30,   31,   32,    9,   34,   35,   36,   91,
 /*  1080 */    91,   39,   91,    6,    7,    8,   20,   10,   11,   12,
 /*  1090 */    13,   91,   26,   27,   28,   29,   30,   31,   32,   91,
 /*  1100 */    34,   35,   36,    9,   91,   39,   80,   81,   91,   83,
 /*  1110 */    91,   91,   91,   91,   20,   89,   91,   91,   91,   91,
 /*  1120 */    26,   27,   28,   29,   30,   31,   32,   91,   34,   35,
 /*  1130 */    36,   91,   91,   39,   91,    1,    2,    3,    4,    5,
 /*  1140 */     6,    7,    8,   91,   10,   11,   12,   13,    2,    3,
 /*  1150 */     4,    5,    6,    7,    8,   91,   10,   11,   12,   13,
 /*  1160 */    63,   64,   91,   66,   91,   91,   91,   70,   91,   80,
 /*  1170 */    81,   74,   83,   76,   85,   86,   87,   80,   89,   91,
 /*  1180 */    83,   20,   91,   91,   91,   91,   89,   26,   27,   28,
 /*  1190 */    29,   30,   31,   32,   63,   91,   91,   66,   67,   63,
 /*  1200 */    64,   70,   66,   91,   91,   91,   70,   76,   91,    2,
 /*  1210 */     3,   80,   76,    6,   83,    8,   80,   91,   91,   83,
 /*  1220 */    89,   63,   64,   70,   66,   89,   91,   20,   70,   76,
 /*  1230 */    91,   91,   25,   80,   76,   91,   83,   91,   80,   91,
 /*  1240 */    91,   83,   89,   91,   91,   63,   64,   89,   66,   91,
 /*  1250 */    63,   64,   70,   66,   91,   91,   91,   70,   76,   91,
 /*  1260 */    91,   91,   80,   76,   91,   83,   91,   80,   91,   91,
 /*  1270 */    83,   89,   91,   91,   91,   91,   89,   91,   63,   64,
 /*  1280 */    91,   66,   91,   63,   64,   70,   66,   91,   91,   91,
 /*  1290 */    70,   76,   91,   91,   91,   80,   76,   91,   83,   91,
 /*  1300 */    80,   91,   91,   83,   89,   63,   64,   91,   66,   89,
 /*  1310 */    63,   64,   70,   91,   91,   91,   91,   70,   76,   91,
 /*  1320 */    91,   91,   80,   76,   91,   83,   91,   80,   70,   70,
 /*  1330 */    83,   89,   91,   91,   76,   76,   89,   91,   80,   80,
 /*  1340 */    91,   83,   83,   80,   81,   91,   83,   89,   89,   70,
 /*  1350 */    70,   91,   89,   91,   91,   76,   76,   91,   91,   80,
 /*  1360 */    80,   70,   83,   83,   91,   91,   70,   76,   89,   89,
 /*  1370 */    91,   80,   76,   91,   83,   91,   80,   70,   91,   83,
 /*  1380 */    89,   91,   70,   76,   91,   89,   91,   80,   76,   91,
 /*  1390 */    83,   91,   80,   70,   70,   83,   89,   91,   91,   76,
 /*  1400 */    76,   89,   91,   80,   80,   70,   83,   83,   91,   91,
 /*  1410 */    70,   76,   89,   89,   91,   80,   76,   91,   83,   91,
 /*  1420 */    80,   70,   91,   83,   89,   91,   70,   76,   91,   89,
 /*  1430 */    91,   80,   76,   91,   83,   91,   80,   70,   70,   83,
 /*  1440 */    89,   91,   91,   76,   76,   89,   91,   80,   80,   91,
 /*  1450 */    83,   83,   91,   70,   70,   91,   89,   89,   91,   76,
 /*  1460 */    76,   91,   91,   80,   80,   70,   83,   83,   91,   91,
 /*  1470 */    70,   76,   89,   89,   91,   80,   76,   91,   83,   91,
 /*  1480 */    80,   70,   70,   83,   89,   91,   91,   76,   76,   89,
 /*  1490 */    91,   80,   80,   91,   83,   83,   91,   70,   70,   91,
 /*  1500 */    89,   89,   91,   76,   76,   91,   91,   80,   80,   91,
 /*  1510 */    83,   83,   80,   81,   91,   83,   89,   89,   91,   80,
 /*  1520 */    81,   89,   83,   91,   80,   81,   91,   83,   89,   91,
 /*  1530 */    91,   91,   91,   89,
};
#define YY_SHIFT_USE_DFLT (-13)
#define YY_SHIFT_COUNT (193)
#define YY_SHIFT_MIN   (-12)
#define YY_SHIFT_MAX   (1207)
static const short yy_shift_ofst[] = {
 /*     0 */     1,   99,   99,   99,   63,   27,   -9,  451,  423,  487,
 /*    10 */   487,  487,  487,  487,  487,  487,  515,  135,  387,  351,
 /*    20 */   315,  279,  243,  207,  171,  487, 1094, 1094,  966,  966,
 /*    30 */   966,  966,  966,  966,  966,  966,  966,  966,  966,  966,
 /*    40 */   966,  966,  966,  966,  966,  966,  966,  966,  966,  966,
 /*    50 */   966,  966,  966,  966,  942,  918,  894,  870,  846,  822,
 /*    60 */   798,  774,  750,  726, 1066, 1066, 1066, 1066, 1066, 1066,
 /*    70 */  1066, 1042,  621,    1,    1,  543,  702,  678,  654,  283,
 /*    80 */    37,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*    90 */     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*   100 */   208,  256,  252,  244,  240,  236,  220,  -13,  -13,  -13,
 /*   110 */   -13,  -13,  -13,  -13,  -13, 1161, 1161, 1161, 1207,   15,
 /*   120 */     1,  220,  208,  212,  208,  213,  194, 1134, 1146, 1146,
 /*   130 */  1146, 1146, 1146, 1146, 1146, 1146, 1146, 1146, 1146, 1077,
 /*   140 */  1077, 1077, 1077,  684,  684,  574,  732,  732,  708,  186,
 /*   150 */   185,  180,   26,  182,  168,  165,  164,  160,  159,  144,
 /*   160 */   169,  152,  122,  115,  133,  132,  124,  121,  116,  113,
 /*   170 */   110,  103,  108,   90,  100,   96,   87,   97,   81,   50,
 /*   180 */    67,   72,   55,   56,   53,   48,   41,   21,   26,    6,
 /*   190 */    24,    4,  -12,    3,
};
#define YY_REDUCE_USE_DFLT (-80)
#define YY_REDUCE_COUNT (126)
#define YY_REDUCE_MIN   (-79)
#define YY_REDUCE_MAX   (1444)
static const short yy_reduce_ofst[] = {
 /*     0 */   547,  589,  558,  527,  978,  978,  978,  947, 1097, 1242,
 /*    10 */  1220, 1215, 1187, 1182, 1158, 1136, 1131, 1247, 1247, 1247,
 /*    20 */  1247, 1247, 1247, 1247, 1247, 1247, 1089,  945, 1428, 1427,
 /*    30 */  1412, 1411, 1400, 1395, 1384, 1383, 1368, 1367, 1356, 1351,
 /*    40 */  1340, 1335, 1324, 1323, 1312, 1307, 1296, 1291, 1280, 1279,
 /*    50 */  1259, 1258, 1153,  977, 1444, 1439, 1432, 1263, 1026,  933,
 /*    60 */   899,  875,  851,  827,  803,  779,  755,  731,  707,  683,
 /*    70 */   -79,  590,   95,  551,   54,  642,  901,  666,  642,  903,
 /*    80 */   902,  879,  878,  855,  854,  831,  830,  807,  806,  783,
 /*    90 */   782,  759,  758,  735,  734,  711,  710,  597,  582,  575,
 /*   100 */   -28,  618,  572,  560,  427,  422,   -2,  415,  363,  327,
 /*   110 */   291,  255,  183,  147,  111,  181,  176,  175,  174,  179,
 /*   120 */   184,  170,  163,  138,  163,  129,  134,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   309,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    10 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    20 */   443,  443,  443,  443,  443,  310,  443,  443,  443,  443,
 /*    30 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    40 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    50 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    60 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    70 */   443,  443,  443,  309,  309,  348,  394,  390,  348,  443,
 /*    80 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*    90 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*   100 */   383,  377,  377,  377,  377,  377,  443,  377,  377,  377,
 /*   110 */   377,  377,  377,  377,  377,  443,  443,  443,  443,  443,
 /*   120 */   310,  443,  386,  443,  384,  424,  333,  418,  378,  379,
 /*   130 */   420,  417,  415,  413,  411,  409,  407,  406,  380,  363,
 /*   140 */   362,  354,  352,  358,  356,  349,  371,  360,  330,  348,
 /*   150 */   394,  443,  443,  316,  443,  443,  443,  443,  443,  443,
 /*   160 */   443,  443,  430,  443,  443,  443,  443,  443,  443,  443,
 /*   170 */   443,  443,  443,  443,  443,  443,  443,  443,  443,  443,
 /*   180 */   443,  443,  443,  443,  368,  443,  443,  364,  348,  390,
 /*   190 */   329,  443,  443,  443,  311,  323,  322,  326,  302,  342,
 /*   200 */   341,  328,  332,  334,  331,  392,  391,  385,  382,  381,
 /*   210 */   315,  353,  355,  357,  359,  361,  425,  319,  433,  318,
 /*   220 */   442,  432,  431,  429,  428,  427,  426,  421,  441,  440,
 /*   230 */   439,  438,  437,  436,  435,  434,  416,  414,  412,  410,
 /*   240 */   408,  419,  402,  400,  399,  398,  397,  401,  404,  396,
 /*   250 */   395,  393,  403,  387,  405,  389,  388,  317,  314,  423,
 /*   260 */   422,  376,  375,  374,  372,  373,  370,  369,  367,  366,
 /*   270 */   365,  351,  350,  349,  348,  347,  346,  345,  344,  343,
 /*   280 */   340,  339,  338,  337,  336,  335,  327,  325,  324,  321,
 /*   290 */   320,  313,  312,  308,  307,  306,  305,  304,  303,  301,
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
  "CAST",          "NEQUAL",        "OP1",           "PIPE",        
  "OP2",           "NOT",           "DOT",           "DCOLON",      
  "DOT_DOLLAR",    "LSB",           "NL",            "SEMI",        
  "EOF",           "COMMA",         "CLASS",         "END",         
  "ID",            "TRAIT",         "DEF",           "LP",          
  "RP",            "SQUARE",        "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "LITSTR",        "RSB",           "TUPLE_START",   "LIST",        
  "DICT_START",    "RB",            "EQUAL",         "LB",          
  "IF",            "ELSE",          "UNLESS",        "WHILE",       
  "IMPORT",        "DOT_NAME",      "AS",            "TRY",         
  "RESCUE",        "OP2_SET",       "OP1_SET",       "OP0_SET",     
  "RAISE",         "error",         "program",       "opt_fin",     
  "l1",            "last_fin",      "fin",           "l1e",         
  "class",         "trait",         "def",           "stmt",        
  "fin_m",         "comma",         "seq",           "delim_seq",   
  "class_start",   "class_body",    "s2",            "trait_start", 
  "trait_body",    "def_start",     "def_body",      "arg",         
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
 /*  58 */ "np_arg ::= np_arg PIPE np_arg",
 /*  59 */ "np_arg ::= np_arg PIPE LP s2 RP",
 /*  60 */ "np_arg ::= np_arg OP2 np_arg",
 /*  61 */ "np_arg ::= np_arg OP2 LP s2 RP",
 /*  62 */ "np_arg ::= np_arg CAST np_arg",
 /*  63 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  64 */ "np_arg ::= np_arg DOT",
 /*  65 */ "np_arg ::= np_arg DOT LP RP",
 /*  66 */ "np_arg ::= np_arg DOT LP np_arg_list RP",
 /*  67 */ "np_arg ::= np_arg DCOLON ID",
 /*  68 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  69 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  70 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  71 */ "np_arg ::= NOT np_arg",
 /*  72 */ "np_arg ::= lambda",
 /*  73 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  74 */ "np_arg ::= TUPLE_START np_arg_list RP",
 /*  75 */ "np_arg ::= LIST np_arg_list RSB",
 /*  76 */ "np_arg ::= DICT_START np_arg_list RB",
 /*  77 */ "np_arg_list_start ::=",
 /*  78 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  79 */ "np_arg_list_elems ::= np_arg",
 /*  80 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  81 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  82 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  83 */ "np_opt_kw_arg_list ::=",
 /*  84 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  85 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  86 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  87 */ "np_recv ::= lit",
 /*  88 */ "np_recv ::= ID LP RP",
 /*  89 */ "np_recv ::= ID LP np_arg_list RP",
 /*  90 */ "np_recv ::= np_recv DOT",
 /*  91 */ "np_recv ::= np_recv DOT LP RP",
 /*  92 */ "np_recv ::= np_recv DOT LP np_arg_list RP",
 /*  93 */ "np_recv ::= np_recv DCOLON ID",
 /*  94 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  95 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  96 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  97 */ "np_recv ::= lambda",
 /*  98 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  99 */ "np_recv ::= LIST np_arg_list RSB",
 /* 100 */ "np_recv ::= DICT_START np_arg_list RB",
 /* 101 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /* 102 */ "np_recv ::= LP s2 RP",
 /* 103 */ "s2 ::= np_recv DOT np_arg_list",
 /* 104 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /* 105 */ "s2 ::= ID np_arg_list",
 /* 106 */ "s2 ::= np_recv CAST np_arg",
 /* 107 */ "s2 ::= np_recv OP0 np_arg",
 /* 108 */ "s2 ::= np_recv OP0 LP s2 RP",
 /* 109 */ "s2 ::= np_recv LT np_arg",
 /* 110 */ "s2 ::= np_recv LT LP s2 RP",
 /* 111 */ "s2 ::= np_recv OP1 np_arg",
 /* 112 */ "s2 ::= np_recv OP1 LP s2 RP",
 /* 113 */ "s2 ::= np_recv PIPE np_arg",
 /* 114 */ "s2 ::= np_recv PIPE LP s2 RP",
 /* 115 */ "s2 ::= np_recv OP2 np_arg",
 /* 116 */ "s2 ::= np_recv OP2 LP s2 RP",
 /* 117 */ "s2 ::= np_recv NEQUAL np_arg",
 /* 118 */ "s2 ::= np_recv",
 /* 119 */ "s2 ::= NOT s2",
 /* 120 */ "s2 ::= np_recv AND np_arg",
 /* 121 */ "stmt ::= s2",
 /* 122 */ "lambda_start ::= LB",
 /* 123 */ "lambda_args ::= PIPE ID PIPE",
 /* 124 */ "lambda_args ::=",
 /* 125 */ "lambda ::= lambda_start lambda_args opt_fin delim_seq RB",
 /* 126 */ "stmt ::= IF s2 fin seq fin END",
 /* 127 */ "stmt ::= IF s2 fin seq fin ELSE fin seq fin END",
 /* 128 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 129 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 130 */ "stmt ::= IMPORT DOT_NAME",
 /* 131 */ "stmt ::= IMPORT DOT_NAME AS ID",
 /* 132 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 133 */ "stmt ::= TRY fin seq fin RESCUE ID CAST s2 fin seq fin END",
 /* 134 */ "stmt ::= ID EQUAL s2",
 /* 135 */ "stmt ::= ID OP2_SET s2",
 /* 136 */ "stmt ::= ID OP1_SET s2",
 /* 137 */ "stmt ::= ID OP0_SET s2",
 /* 138 */ "stmt ::= IVAR EQUAL s2",
 /* 139 */ "stmt ::= IVAR OP2_SET s2",
 /* 140 */ "stmt ::= IVAR OP1_SET s2",
 /* 141 */ "stmt ::= IVAR OP0_SET s2",
 /* 142 */ "stmt ::= RAISE s2",
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
  { 54, 3 },
  { 56, 3 },
  { 56, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 64, 1 },
  { 64, 1 },
  { 55, 0 },
  { 55, 1 },
  { 57, 1 },
  { 57, 2 },
  { 58, 2 },
  { 58, 1 },
  { 65, 2 },
  { 65, 1 },
  { 66, 3 },
  { 66, 1 },
  { 67, 2 },
  { 68, 1 },
  { 69, 3 },
  { 60, 4 },
  { 60, 6 },
  { 71, 1 },
  { 72, 3 },
  { 61, 4 },
  { 73, 1 },
  { 74, 3 },
  { 75, 1 },
  { 75, 3 },
  { 77, 3 },
  { 77, 1 },
  { 78, 0 },
  { 78, 3 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 62, 5 },
  { 62, 5 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 81, 1 },
  { 81, 3 },
  { 81, 5 },
  { 81, 3 },
  { 81, 5 },
  { 81, 3 },
  { 81, 5 },
  { 81, 3 },
  { 81, 5 },
  { 81, 3 },
  { 81, 5 },
  { 81, 3 },
  { 81, 3 },
  { 81, 2 },
  { 81, 4 },
  { 81, 5 },
  { 81, 3 },
  { 81, 3 },
  { 81, 5 },
  { 81, 6 },
  { 81, 2 },
  { 81, 1 },
  { 81, 4 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 84, 0 },
  { 85, 3 },
  { 85, 1 },
  { 86, 3 },
  { 87, 3 },
  { 87, 1 },
  { 88, 0 },
  { 88, 2 },
  { 82, 3 },
  { 82, 2 },
  { 76, 1 },
  { 76, 3 },
  { 76, 4 },
  { 76, 2 },
  { 76, 4 },
  { 76, 5 },
  { 76, 3 },
  { 76, 3 },
  { 76, 5 },
  { 76, 6 },
  { 76, 1 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 4 },
  { 76, 3 },
  { 70, 3 },
  { 70, 4 },
  { 70, 2 },
  { 70, 3 },
  { 70, 3 },
  { 70, 5 },
  { 70, 3 },
  { 70, 5 },
  { 70, 3 },
  { 70, 5 },
  { 70, 3 },
  { 70, 5 },
  { 70, 3 },
  { 70, 5 },
  { 70, 3 },
  { 70, 1 },
  { 70, 2 },
  { 70, 3 },
  { 63, 1 },
  { 89, 1 },
  { 90, 3 },
  { 90, 0 },
  { 83, 5 },
  { 63, 6 },
  { 63, 10 },
  { 63, 6 },
  { 63, 6 },
  { 63, 2 },
  { 63, 4 },
  { 63, 9 },
  { 63, 12 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 2 },
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
#line 1318 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 17: /* seq ::= seq fin stmt */ yytestcase(yyruleno==17);
#line 34 "vm/parser.lm"
{ yygotominor.yy74.a = S->seq(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1324 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= trait */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= def */ yytestcase(yyruleno==5);
      case 6: /* l1e ::= stmt */ yytestcase(yyruleno==6);
      case 18: /* seq ::= stmt */ yytestcase(yyruleno==18);
      case 51: /* np_arg ::= lit */ yytestcase(yyruleno==51);
      case 72: /* np_arg ::= lambda */ yytestcase(yyruleno==72);
      case 87: /* np_recv ::= lit */ yytestcase(yyruleno==87);
      case 97: /* np_recv ::= lambda */ yytestcase(yyruleno==97);
      case 118: /* s2 ::= np_recv */ yytestcase(yyruleno==118);
      case 121: /* stmt ::= s2 */ yytestcase(yyruleno==121);
#line 35 "vm/parser.lm"
{ yygotominor.yy74.a = yymsp[0].minor.yy74.a; }
#line 1340 "vm/parser.c.inc"
        break;
      case 19: /* delim_seq ::= seq opt_fin */
      case 102: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==102);
#line 60 "vm/parser.lm"
{ yygotominor.yy74.a = yymsp[-1].minor.yy74.a; }
#line 1346 "vm/parser.c.inc"
        break;
      case 20: /* class_start ::= CLASS */
#line 62 "vm/parser.lm"
{ S->start_class(); }
#line 1351 "vm/parser.c.inc"
        break;
      case 21: /* class_body ::= l1 fin END */
      case 25: /* trait_body ::= l1 fin END */ yytestcase(yyruleno==25);
      case 28: /* def_body ::= seq fin END */ yytestcase(yyruleno==28);
#line 63 "vm/parser.lm"
{ yygotominor.yy74.a = yymsp[-2].minor.yy74.a; }
#line 1358 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy74.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy74.a);
             }
#line 1365 "vm/parser.c.inc"
        break;
      case 23: /* class ::= class_start ID LT s2 fin class_body */
#line 69 "vm/parser.lm"
{
               yygotominor.yy74.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a);
             }
#line 1372 "vm/parser.c.inc"
        break;
      case 24: /* trait_start ::= TRAIT */
#line 73 "vm/parser.lm"
{ S->start_trait(); }
#line 1377 "vm/parser.c.inc"
        break;
      case 26: /* trait ::= trait_start ID fin trait_body */
#line 76 "vm/parser.lm"
{
               yygotominor.yy74.a = S->trait(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a);
             }
#line 1384 "vm/parser.c.inc"
        break;
      case 27: /* def_start ::= DEF */
#line 80 "vm/parser.lm"
{ S->start_def(); }
#line 1389 "vm/parser.c.inc"
        break;
      case 29: /* arg ::= ID */
#line 83 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1394 "vm/parser.c.inc"
        break;
      case 30: /* arg ::= ID CAST np_recv */
#line 84 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1399 "vm/parser.c.inc"
        break;
      case 35: /* def_name ::= ID */
      case 36: /* def_name ::= OP0 */ yytestcase(yyruleno==36);
      case 37: /* def_name ::= LT */ yytestcase(yyruleno==37);
      case 38: /* def_name ::= OP1 */ yytestcase(yyruleno==38);
      case 39: /* def_name ::= OP2 */ yytestcase(yyruleno==39);
      case 40: /* def_name ::= SQUARE */ yytestcase(yyruleno==40);
#line 92 "vm/parser.lm"
{ yygotominor.yy74.s = yymsp[0].minor.yy0.s; }
#line 1409 "vm/parser.c.inc"
        break;
      case 41: /* def ::= def_start def_name def_args fin def_body */
#line 100 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_def(yymsp[-3].minor.yy74.s, yymsp[0].minor.yy74.a);
            }
#line 1416 "vm/parser.c.inc"
        break;
      case 42: /* def ::= def_start def_name def_args fin END */
#line 103 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_def(yymsp[-3].minor.yy74.s, S->ast_nil());
            }
#line 1423 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= NUM */
#line 107 "vm/parser.lm"
{ yygotominor.yy74.a = S->number(yymsp[0].minor.yy0.i); }
#line 1428 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= NIL */
#line 108 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_nil();  }
#line 1433 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= TRUE */
#line 109 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_true();  }
#line 1438 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= FALSE */
#line 110 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_false(); }
#line 1443 "vm/parser.c.inc"
        break;
      case 47: /* lit ::= SELF */
#line 111 "vm/parser.lm"
{ yygotominor.yy74.a = S->self(); }
#line 1448 "vm/parser.c.inc"
        break;
      case 48: /* lit ::= ID */
#line 112 "vm/parser.lm"
{ yygotominor.yy74.a = S->named(yymsp[0].minor.yy0.s); }
#line 1453 "vm/parser.c.inc"
        break;
      case 49: /* lit ::= IVAR */
#line 113 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1458 "vm/parser.c.inc"
        break;
      case 50: /* lit ::= LITSTR */
#line 114 "vm/parser.lm"
{ yygotominor.yy74.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1463 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg OP0 np_arg */
      case 54: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==54);
      case 56: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==56);
      case 58: /* np_arg ::= np_arg PIPE np_arg */ yytestcase(yyruleno==58);
      case 107: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==107);
      case 109: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==109);
      case 111: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==111);
      case 113: /* s2 ::= np_recv PIPE np_arg */ yytestcase(yyruleno==113);
      case 115: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==115);
#line 119 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1476 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 55: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==55);
      case 57: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==57);
      case 59: /* np_arg ::= np_arg PIPE LP s2 RP */ yytestcase(yyruleno==59);
      case 108: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==108);
      case 110: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==110);
      case 112: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==112);
      case 114: /* s2 ::= np_recv PIPE LP s2 RP */ yytestcase(yyruleno==114);
      case 116: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==116);
#line 121 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1489 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg OP2 np_arg */
#line 139 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1494 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg OP2 LP s2 RP */
#line 141 "vm/parser.lm"
{ yygotominor.yy74.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1499 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg CAST np_arg */
      case 106: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==106);
#line 144 "vm/parser.lm"
{ yygotominor.yy74.a = S->cast(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1505 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg NEQUAL np_arg */
      case 117: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==117);
#line 146 "vm/parser.lm"
{ yygotominor.yy74.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a)); }
#line 1511 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT */
      case 90: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==90);
#line 147 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(yymsp[-1].minor.yy74.a, yymsp[0].minor.yy0.s); }
#line 1517 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= np_arg DOT LP RP */
      case 91: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==91);
#line 148 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(yymsp[-3].minor.yy74.a, yymsp[-2].minor.yy0.s); }
#line 1523 "vm/parser.c.inc"
        break;
      case 66: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 92: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==92);
#line 150 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-4].minor.yy74.a, yymsp[-3].minor.yy0.s); }
#line 1529 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg DCOLON ID */
      case 93: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==93);
#line 151 "vm/parser.lm"
{ yygotominor.yy74.a = S->dcolon(yymsp[-2].minor.yy74.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1535 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 94: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==94);
#line 154 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1541 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 95: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==95);
#line 156 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1547 "vm/parser.c.inc"
        break;
      case 70: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 96: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==96);
#line 158 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect_args(yymsp[-5].minor.yy74.a, yymsp[-3].minor.yy74.a); }
#line 1553 "vm/parser.c.inc"
        break;
      case 71: /* np_arg ::= NOT np_arg */
      case 119: /* s2 ::= NOT s2 */ yytestcase(yyruleno==119);
#line 159 "vm/parser.lm"
{ yygotominor.yy74.a = S->not_(yymsp[0].minor.yy74.a); }
#line 1559 "vm/parser.c.inc"
        break;
      case 73: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 101: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==101);
#line 162 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-3].minor.yy74.a, "[]"); }
#line 1565 "vm/parser.c.inc"
        break;
      case 74: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 98: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==98);
#line 164 "vm/parser.lm"
{ yygotominor.yy74.a = S->tuple(); }
#line 1571 "vm/parser.c.inc"
        break;
      case 75: /* np_arg ::= LIST np_arg_list RSB */
      case 99: /* np_recv ::= LIST np_arg_list RSB */ yytestcase(yyruleno==99);
#line 165 "vm/parser.lm"
{ yygotominor.yy74.a = S->list(); }
#line 1577 "vm/parser.c.inc"
        break;
      case 76: /* np_arg ::= DICT_START np_arg_list RB */
      case 100: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==100);
#line 166 "vm/parser.lm"
{ yygotominor.yy74.a = S->dict(); }
#line 1583 "vm/parser.c.inc"
        break;
      case 77: /* np_arg_list_start ::= */
#line 168 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1588 "vm/parser.c.inc"
        break;
      case 78: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 79: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==79);
#line 169 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy74.a); }
#line 1594 "vm/parser.c.inc"
        break;
      case 80: /* np_kw_arg ::= ID EQUAL np_arg */
#line 172 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1599 "vm/parser.c.inc"
        break;
      case 88: /* np_recv ::= ID LP RP */
#line 184 "vm/parser.lm"
{ yygotominor.yy74.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1604 "vm/parser.c.inc"
        break;
      case 89: /* np_recv ::= ID LP np_arg_list RP */
#line 185 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1609 "vm/parser.c.inc"
        break;
      case 103: /* s2 ::= np_recv DOT np_arg_list */
#line 204 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(yymsp[-2].minor.yy74.a, yymsp[-1].minor.yy0.s); }
#line 1614 "vm/parser.c.inc"
        break;
      case 104: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 206 "vm/parser.lm"
{ yygotominor.yy74.a = S->send_indirect_args(yymsp[-3].minor.yy74.a, yymsp[-1].minor.yy74.a); }
#line 1619 "vm/parser.c.inc"
        break;
      case 105: /* s2 ::= ID np_arg_list */
#line 207 "vm/parser.lm"
{ yygotominor.yy74.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1624 "vm/parser.c.inc"
        break;
      case 120: /* s2 ::= np_recv AND np_arg */
#line 223 "vm/parser.lm"
{ yygotominor.yy74.a = S->and_(yymsp[-2].minor.yy74.a, yymsp[0].minor.yy74.a); }
#line 1629 "vm/parser.c.inc"
        break;
      case 122: /* lambda_start ::= LB */
#line 229 "vm/parser.lm"
{ S->start_lambda(); }
#line 1634 "vm/parser.c.inc"
        break;
      case 123: /* lambda_args ::= PIPE ID PIPE */
#line 231 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1639 "vm/parser.c.inc"
        break;
      case 125: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 234 "vm/parser.lm"
{ yygotominor.yy74.a = S->lambda(yymsp[-1].minor.yy74.a); }
#line 1644 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= IF s2 fin seq fin END */
#line 238 "vm/parser.lm"
{ yygotominor.yy74.a = S->if_cond(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1649 "vm/parser.c.inc"
        break;
      case 127: /* stmt ::= IF s2 fin seq fin ELSE fin seq fin END */
#line 240 "vm/parser.lm"
{ yygotominor.yy74.a = S->if_else(yymsp[-8].minor.yy74.a, yymsp[-6].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1654 "vm/parser.c.inc"
        break;
      case 128: /* stmt ::= UNLESS s2 fin seq fin END */
#line 241 "vm/parser.lm"
{ yygotominor.yy74.a = S->unless(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1659 "vm/parser.c.inc"
        break;
      case 129: /* stmt ::= WHILE s2 fin seq fin END */
#line 242 "vm/parser.lm"
{ yygotominor.yy74.a = S->while_(yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a); }
#line 1664 "vm/parser.c.inc"
        break;
      case 130: /* stmt ::= IMPORT DOT_NAME */
#line 246 "vm/parser.lm"
{ yygotominor.yy74.a = S->import(yymsp[0].minor.yy0.s); }
#line 1669 "vm/parser.c.inc"
        break;
      case 131: /* stmt ::= IMPORT DOT_NAME AS ID */
#line 247 "vm/parser.lm"
{ yygotominor.yy74.a = S->import(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1674 "vm/parser.c.inc"
        break;
      case 132: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 249 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_try(yymsp[-6].minor.yy74.a, yymsp[-2].minor.yy74.a);
            }
#line 1681 "vm/parser.c.inc"
        break;
      case 133: /* stmt ::= TRY fin seq fin RESCUE ID CAST s2 fin seq fin END */
#line 253 "vm/parser.lm"
{
              yygotominor.yy74.a = S->ast_try(yymsp[-9].minor.yy74.a, yymsp[-6].minor.yy0.s, yymsp[-4].minor.yy74.a, yymsp[-2].minor.yy74.a);
            }
#line 1688 "vm/parser.c.inc"
        break;
      case 134: /* stmt ::= ID EQUAL s2 */
#line 257 "vm/parser.lm"
{ yygotominor.yy74.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1693 "vm/parser.c.inc"
        break;
      case 135: /* stmt ::= ID OP2_SET s2 */
      case 136: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==136);
      case 137: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==137);
#line 258 "vm/parser.lm"
{ yygotominor.yy74.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1700 "vm/parser.c.inc"
        break;
      case 138: /* stmt ::= IVAR EQUAL s2 */
#line 261 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1705 "vm/parser.c.inc"
        break;
      case 139: /* stmt ::= IVAR OP2_SET s2 */
      case 140: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==140);
      case 141: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==141);
#line 263 "vm/parser.lm"
{ yygotominor.yy74.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy74.a); }
#line 1712 "vm/parser.c.inc"
        break;
      case 142: /* stmt ::= RAISE s2 */
#line 268 "vm/parser.lm"
{ yygotominor.yy74.a = S->raise(yymsp[0].minor.yy74.a); }
#line 1717 "vm/parser.c.inc"
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
      /* (81) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==81);
      /* (82) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==82);
      /* (83) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==83);
      /* (84) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==84);
      /* (85) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==85);
      /* (86) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==86);
      /* (124) lambda_args ::= */ yytestcase(yyruleno==124);
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
#line 1806 "vm/parser.c.inc"
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
