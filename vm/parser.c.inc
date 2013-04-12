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
#define YYNOCODE 91
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
#define YYNSTATE 284
#define YYNRULE 137
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
#define YY_ACTTAB_COUNT (1513)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    48,  271,  130,  284,  264,  259,  258,  206,   52,  205,
 /*    10 */   120,   71,  203,  201,   49,  259,  258,  279,  278,  277,
 /*    20 */   276,  275,  137,  272,  268,  104,  103,  271,  132,  261,
 /*    30 */   264,   37,  147,   36,   35,  157,  120,   28,   87,  193,
 /*    40 */    48,   27,  175,   34,   26,  259,  258,  259,  258,  205,
 /*    50 */   204,   71,  203,  201,   49,   67,  269,  279,  278,  277,
 /*    60 */   276,  275,  137,  272,  208,  104,  103,  271,  131,  261,
 /*    70 */   264,   37,  102,   36,   35,  157,  120,  174,   87,   26,
 /*    80 */    48,   15,  173,   34,   26,  259,  258,  256,  101,  205,
 /*    90 */   202,   71,  203,  201,   49,  265,  266,  279,  278,  277,
 /*   100 */   276,  275,  137,  272,  262,  104,  103,  271,  138,  261,
 /*   110 */   264,   37,  263,   36,   35,  157,  120,  165,   87,   26,
 /*   120 */    48,   16,   17,   34,  114,  259,  258,  254,  256,  205,
 /*   130 */   256,   71,  203,  201,   49,  260,  171,  279,  278,  277,
 /*   140 */   276,  275,  137,  272,  250,  104,  103,  271,  128,  261,
 /*   150 */   264,   37,  248,   36,   35,  157,  120,  164,   87,   26,
 /*   160 */    48,  246,  163,   34,   26,  259,  258,  259,  258,  244,
 /*   170 */   225,   71,  242,  153,   49,  241,  240,  279,  278,  277,
 /*   180 */   276,  275,  137,  272,  155,  104,  103,  271,  123,  261,
 /*   190 */   264,   37,   93,   36,   35,  157,  120,  179,   87,   26,
 /*   200 */    48,  238,  237,   34,  217,  259,  258,   25,  156,  236,
 /*   210 */   224,   71,  235,  256,   49,   33,  221,  279,  278,  277,
 /*   220 */   276,  275,  137,  272,  215,  104,  103,  271,  134,  261,
 /*   230 */   264,   37,  214,   36,   35,  157,  120,  176,   87,   26,
 /*   240 */    48,  216,  169,   34,   26,  259,  258,  259,  258,  184,
 /*   250 */   223,   71,  213,  168,   49,   26,  212,  279,  278,  277,
 /*   260 */   276,  275,  137,  272,  211,  104,  103,  271,  133,  261,
 /*   270 */   264,   37,   75,   36,   35,  157,  120,  166,   87,   26,
 /*   280 */    48,   14,  192,   34,  113,  259,  258,  256,   81,   61,
 /*   290 */   222,   71,   99,  253,   49,   26,   98,  279,  278,  277,
 /*   300 */   276,  275,  137,  272,  100,  104,  103,  271,  135,  261,
 /*   310 */   264,   37,   70,   36,   35,  157,  120,  249,   87,   26,
 /*   320 */    48,   24,  172,   34,   13,  259,  258,  256,  210,  118,
 /*   330 */   256,   71,  147,  245,   49,   26,  146,  279,  278,  277,
 /*   340 */   276,  275,  137,  272,   96,  104,  103,  271,  139,  261,
 /*   350 */   264,   37,   79,   36,   35,  157,  120,  194,   87,   76,
 /*   360 */    48,   23,  143,   34,  257,  259,  258,  256,  116,  115,
 /*   370 */   220,   71,  177,   72,   49,  141,  270,  279,  278,  277,
 /*   380 */   276,  275,  137,  272,  267,  104,  103,  271,  127,  261,
 /*   390 */   264,   37,  255,   36,   35,  157,  120,  251,   87,  247,
 /*   400 */    48,   12,  423,   34,  423,  259,  258,  256,  423,  423,
 /*   410 */   218,   71,  423,  423,   49,  423,  423,  279,  278,  277,
 /*   420 */   276,  275,  137,  272,  423,  104,  103,  271,  126,  261,
 /*   430 */   264,   37,  423,   36,   35,  157,  120,  423,   87,  423,
 /*   440 */    48,   22,  423,   34,  423,  259,  258,  256,  423,  423,
 /*   450 */   191,   71,  423,  423,   49,  423,  423,  279,  278,  277,
 /*   460 */   276,  275,  137,  272,  423,  104,  103,  271,  125,  261,
 /*   470 */   264,   37,  423,   36,   35,  157,  120,  423,   87,  423,
 /*   480 */    48,   11,  423,   34,  423,  259,  258,  256,  423,  423,
 /*   490 */   189,   71,  423,  423,   49,  423,  423,  279,  278,  277,
 /*   500 */   276,  275,  137,  272,   21,  104,  103,  423,   48,  261,
 /*   510 */   256,   37,  423,   36,   35,  157,  423,  205,   87,   71,
 /*   520 */   203,  201,   49,   34,  423,  279,  278,  277,  276,  275,
 /*   530 */   137,  272,   20,  104,  103,  423,  423,  261,  256,   37,
 /*   540 */   423,   36,   35,  157,  423,  423,   87,  423,   48,  271,
 /*   550 */   121,   34,  264,  259,  258,  209,  119,  423,  120,   71,
 /*   560 */   423,  423,   49,  423,  423,  279,  278,  277,  276,  275,
 /*   570 */   137,  272,    9,  104,  103,  423,   48,  261,  256,   37,
 /*   580 */   423,   36,   35,  157,  423,  423,   87,   71,  423,  423,
 /*   590 */    49,   34,  423,  279,  278,  277,  276,  275,  137,  272,
 /*   600 */    19,  104,  103,  423,  358,  261,  256,   37,  423,   36,
 /*   610 */    35,  157,  423,  423,   87,  358,  423,  423,  100,   34,
 /*   620 */   423,  358,  358,  358,  358,  358,  358,  358,    5,  358,
 /*   630 */   358,    2,   51,  358,  256,   82,  423,  256,  188,  282,
 /*   640 */   281,  280,  182,  257,   44,   43,   42,  145,  186,  226,
 /*   650 */   144,   41,  112,  183,    6,  129,  423,  423,  423,  252,
 /*   660 */   256,  423,  243,   40,   39,   38,   80,  423,  120,  188,
 /*   670 */   282,  281,  280,  182,  257,  423,  423,  423,  145,  207,
 /*   680 */   226,  144,  187,  112,  423,  129,  129,  423,    4,  252,
 /*   690 */   252,  423,  243,  243,  256,  423,  423,   82,  120,  120,
 /*   700 */   188,  282,  281,  280,  182,  257,  423,    8,  423,  145,
 /*   710 */   185,  226,  144,  256,  112,  423,  423,  129,  423,  423,
 /*   720 */   423,  252,   68,  423,  243,  188,  282,  281,  280,  182,
 /*   730 */   120,  136,  423,  423,  145,  252,  226,  144,  243,  112,
 /*   740 */   423,  423,  129,  423,  120,  423,  252,   18,    1,  243,
 /*   750 */   423,  423,  423,  256,  256,  120,  283,  282,  281,  280,
 /*   760 */   182,  257,  423,  271,  124,  145,  264,  226,  144,   10,
 /*   770 */   112,  423,  120,  129,  358,  256,  423,  252,  423,  423,
 /*   780 */   243,  423,  423,    3,  423,  358,  120,  423,  100,  256,
 /*   790 */   423,  358,  358,  358,  358,  358,  358,  358,  423,  358,
 /*   800 */   358,  358,  423,  358,  271,  122,  423,  264,  423,   97,
 /*   810 */   209,  117,  358,  120,  423,   99,  423,  423,  358,  358,
 /*   820 */   358,  358,  358,  358,  358,  423,  358,  358,  358,  423,
 /*   830 */   358,   58,   57,  423,  180,  178,  111,  108,  423,  358,
 /*   840 */   423,  423,   98,  423,  423,  358,  358,  358,  358,  358,
 /*   850 */   358,  358,  423,  358,  358,   64,   57,  358,  180,  178,
 /*   860 */   111,  108,  423,  423,  423,  423,  274,  423,  423,   29,
 /*   870 */   423,  423,  279,  278,  277,  276,  275,  273,  272,  234,
 /*   880 */   107,  106,   64,  423,  261,  129,  423,  423,  423,  252,
 /*   890 */   423,  423,  243,  274,  423,  423,   30,  423,  120,  279,
 /*   900 */   278,  277,  276,  275,  273,  272,  161,  107,  106,   64,
 /*   910 */   423,  261,  129,  423,  422,    7,  252,  423,  114,  243,
 /*   920 */   274,  423,  423,   31,  256,  120,  279,  278,  277,  276,
 /*   930 */   275,  273,  272,  423,  107,  106,   64,  423,  261,  180,
 /*   940 */   178,  111,  108,  423,  423,  423,  423,  274,  423,  423,
 /*   950 */    32,  423,  423,  279,  278,  277,  276,  275,  273,  272,
 /*   960 */   423,  107,  106,   64,  423,  261,  142,  167,  109,  105,
 /*   970 */   423,  423,  423,  423,  274,  423,  423,   50,  423,  423,
 /*   980 */   279,  278,  277,  276,  275,  273,  272,  423,  107,  106,
 /*   990 */    64,  423,  261,  423,  423,  423,  423,  423,  423,  423,
 /*  1000 */   423,  274,  423,  423,   47,  423,  423,  279,  278,  277,
 /*  1010 */   276,  275,  273,  272,  423,  107,  106,   64,  423,  261,
 /*  1020 */   423,  423,  423,  423,  423,  423,  423,  423,  274,  423,
 /*  1030 */   423,   46,  423,  423,  279,  278,  277,  276,  275,  273,
 /*  1040 */   272,  423,  107,  106,   64,  423,  261,  423,  423,  423,
 /*  1050 */   423,  423,  423,  423,  423,  274,  423,  423,   45,  423,
 /*  1060 */   423,  279,  278,  277,  276,  275,  273,  272,  423,  107,
 /*  1070 */   106,   48,  423,  261,  423,  423,  423,  423,  423,  423,
 /*  1080 */   423,  423,   74,  423,  423,   49,  423,  423,  279,  278,
 /*  1090 */   277,  276,  275,  273,  272,  423,  104,  103,   64,  423,
 /*  1100 */   261,  423,  423,   60,   59,   66,   65,   58,   57,  274,
 /*  1110 */   180,  178,  111,  108,  423,  279,  278,  277,  276,  275,
 /*  1120 */   273,  272,  423,  107,  106,  423,  423,  261,  423,  140,
 /*  1130 */   423,  423,   49,  423,  423,  279,  278,  277,  276,  275,
 /*  1140 */   273,  272,  423,  104,  103,   64,  423,  261,  423,  423,
 /*  1150 */    56,   55,   63,   62,   54,   53,  181,   73,  167,  110,
 /*  1160 */   105,  423,  279,  278,  277,  276,  275,  273,  272,  423,
 /*  1170 */   107,  106,  423,  423,  261,  154,  257,  423,   78,  423,
 /*  1180 */   423,  162,  226,  423,  423,  423,  190,  129,  129,  423,
 /*  1190 */   423,  252,  252,  423,  243,  243,  274,  423,  423,  423,
 /*  1200 */   120,  120,  279,  278,  277,  276,  275,  273,  272,  423,
 /*  1210 */   199,  198,  423,  154,  197,  196,   69,  152,  154,  257,
 /*  1220 */   226,   94,  423,  423,  423,  226,  129,  200,  423,  423,
 /*  1230 */   252,  129,  195,  243,  423,  252,  423,  239,  243,  120,
 /*  1240 */   423,  423,  423,  129,  120,  154,  257,  252,   92,  423,
 /*  1250 */   243,  160,  226,  423,  423,  423,  120,  129,  129,  423,
 /*  1260 */   423,  252,  252,  423,  243,  243,  154,  257,  423,   90,
 /*  1270 */   120,  120,  423,  226,  423,  423,  423,  423,  423,  129,
 /*  1280 */   423,  154,  257,  252,   88,  423,  243,  423,  226,  423,
 /*  1290 */   423,  423,  120,  423,  129,  423,  154,  257,  252,   86,
 /*  1300 */   423,  243,  423,  226,  423,  423,  423,  120,  423,  129,
 /*  1310 */   423,  154,  257,  252,   85,  423,  243,  423,  226,  423,
 /*  1320 */   423,  423,  120,  423,  129,  423,  423,  423,  252,  154,
 /*  1330 */   257,  243,   83,  423,  170,  257,  226,  120,  423,  423,
 /*  1340 */   423,  226,  129,  423,  423,  423,  252,  129,  423,  243,
 /*  1350 */   423,  252,  159,  158,  243,  120,  423,  423,  129,  129,
 /*  1360 */   120,  423,  252,  252,  233,  243,  243,  423,  423,  232,
 /*  1370 */   129,  120,  120,  423,  252,  129,  423,  243,  423,  252,
 /*  1380 */   423,  231,  243,  120,  423,  423,  230,  129,  120,  423,
 /*  1390 */   423,  252,  129,  423,  243,  423,  252,  423,  229,  243,
 /*  1400 */   120,  423,  423,  423,  129,  120,  228,  423,  252,  423,
 /*  1410 */   423,  243,  129,  423,  423,  423,  252,  120,  423,  243,
 /*  1420 */   423,  227,   95,   91,  423,  120,  423,  129,  129,  129,
 /*  1430 */   423,  252,  252,  252,  243,  243,  243,  423,  423,   89,
 /*  1440 */   120,  120,  120,  423,  219,  129,  423,  423,  423,  252,
 /*  1450 */   129,  423,  243,  423,  252,  423,   84,  243,  120,  423,
 /*  1460 */   423,  151,  129,  120,  423,  423,  252,  129,  423,  243,
 /*  1470 */   423,  252,  423,  423,  243,  120,  150,  423,  149,  423,
 /*  1480 */   120,  423,  129,  423,  129,  423,  252,  423,  252,  243,
 /*  1490 */   423,  243,  148,   77,  423,  120,  423,  120,  129,  129,
 /*  1500 */   423,  423,  252,  252,  423,  243,  243,  423,  423,  423,
 /*  1510 */   423,  120,  120,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     8,   79,   80,    0,   82,   13,   14,   15,    1,   17,
 /*    10 */    88,   19,   20,   21,   22,   13,   14,   25,   26,   27,
 /*    20 */    28,   29,   30,   31,   19,   33,   34,   79,   80,   37,
 /*    30 */    82,   39,   16,   41,   42,   43,   88,    3,   46,   23,
 /*    40 */     8,   64,   81,   51,   83,   13,   14,   13,   14,   17,
 /*    50 */    18,   19,   20,   21,   22,   36,   23,   25,   26,   27,
 /*    60 */    28,   29,   30,   31,   87,   33,   34,   79,   80,   37,
 /*    70 */    82,   39,   22,   41,   42,   43,   88,   81,   46,   83,
 /*    80 */     8,   57,   81,   51,   83,   13,   14,   63,   22,   17,
 /*    90 */    18,   19,   20,   21,   22,   32,   23,   25,   26,   27,
 /*   100 */    28,   29,   30,   31,   35,   33,   34,   79,   80,   37,
 /*   110 */    82,   39,   23,   41,   42,   43,   88,   81,   46,   83,
 /*   120 */     8,   54,   57,   51,   57,   13,   14,   23,   63,   17,
 /*   130 */    63,   19,   20,   21,   22,   38,   19,   25,   26,   27,
 /*   140 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   150 */    82,   39,   19,   41,   42,   43,   88,   81,   46,   83,
 /*   160 */     8,   23,   81,   51,   83,   13,   14,   13,   14,   32,
 /*   170 */    18,   19,   23,   19,   22,   35,   23,   25,   26,   27,
 /*   180 */    28,   29,   30,   31,   45,   33,   34,   79,   80,   37,
 /*   190 */    82,   39,   40,   41,   42,   43,   88,   81,   46,   83,
 /*   200 */     8,   23,   23,   51,   54,   13,   14,   57,   44,   23,
 /*   210 */    18,   19,   23,   63,   22,    4,   19,   25,   26,   27,
 /*   220 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   230 */    82,   39,   23,   41,   42,   43,   88,   81,   46,   83,
 /*   240 */     8,   35,   81,   51,   83,   13,   14,   13,   14,   15,
 /*   250 */    18,   19,   23,   81,   22,   83,   23,   25,   26,   27,
 /*   260 */    28,   29,   30,   31,   13,   33,   34,   79,   80,   37,
 /*   270 */    82,   39,   19,   41,   42,   43,   88,   81,   46,   83,
 /*   280 */     8,   57,   74,   51,   76,   13,   14,   63,   19,    4,
 /*   290 */    18,   19,   22,   81,   22,   83,   22,   25,   26,   27,
 /*   300 */    28,   29,   30,   31,   22,   33,   34,   79,   80,   37,
 /*   310 */    82,   39,   89,   41,   42,   43,   88,   81,   46,   83,
 /*   320 */     8,   57,   38,   51,   57,   13,   14,   63,   85,   64,
 /*   330 */    63,   19,   16,   81,   22,   83,   19,   25,   26,   27,
 /*   340 */    28,   29,   30,   31,   22,   33,   34,   79,   80,   37,
 /*   350 */    82,   39,   77,   41,   42,   43,   88,   74,   46,   47,
 /*   360 */     8,   57,   19,   51,   63,   13,   14,   63,   78,   64,
 /*   370 */    18,   19,   79,   79,   22,   79,   23,   25,   26,   27,
 /*   380 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   390 */    82,   39,   23,   41,   42,   43,   88,   23,   46,   23,
 /*   400 */     8,   57,   90,   51,   90,   13,   14,   63,   90,   90,
 /*   410 */    18,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   420 */    28,   29,   30,   31,   90,   33,   34,   79,   80,   37,
 /*   430 */    82,   39,   90,   41,   42,   43,   88,   90,   46,   90,
 /*   440 */     8,   57,   90,   51,   90,   13,   14,   63,   90,   90,
 /*   450 */    18,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   460 */    28,   29,   30,   31,   90,   33,   34,   79,   80,   37,
 /*   470 */    82,   39,   90,   41,   42,   43,   88,   90,   46,   90,
 /*   480 */     8,   57,   90,   51,   90,   13,   14,   63,   90,   90,
 /*   490 */    18,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   500 */    28,   29,   30,   31,   57,   33,   34,   90,    8,   37,
 /*   510 */    63,   39,   90,   41,   42,   43,   90,   17,   46,   19,
 /*   520 */    20,   21,   22,   51,   90,   25,   26,   27,   28,   29,
 /*   530 */    30,   31,   57,   33,   34,   90,   90,   37,   63,   39,
 /*   540 */    90,   41,   42,   43,   90,   90,   46,   90,    8,   79,
 /*   550 */    80,   51,   82,   13,   14,   85,   86,   90,   88,   19,
 /*   560 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*   570 */    30,   31,   57,   33,   34,   90,    8,   37,   63,   39,
 /*   580 */    90,   41,   42,   43,   90,   90,   46,   19,   90,   90,
 /*   590 */    22,   51,   90,   25,   26,   27,   28,   29,   30,   31,
 /*   600 */    57,   33,   34,   90,    8,   37,   63,   39,   90,   41,
 /*   610 */    42,   43,   90,   90,   46,   19,   90,   90,   22,   51,
 /*   620 */    90,   25,   26,   27,   28,   29,   30,   31,   57,   33,
 /*   630 */    34,   57,   36,   37,   63,   55,   90,   63,   58,   59,
 /*   640 */    60,   61,   62,   63,   48,   49,   50,   67,   68,   69,
 /*   650 */    70,   36,   72,   56,   57,   75,   90,   90,   90,   79,
 /*   660 */    63,   90,   82,   48,   49,   50,   55,   90,   88,   58,
 /*   670 */    59,   60,   61,   62,   63,   90,   90,   90,   67,   69,
 /*   680 */    69,   70,   71,   72,   90,   75,   75,   90,   57,   79,
 /*   690 */    79,   90,   82,   82,   63,   90,   90,   55,   88,   88,
 /*   700 */    58,   59,   60,   61,   62,   63,   90,   57,   90,   67,
 /*   710 */    68,   69,   70,   63,   72,   90,   90,   75,   90,   90,
 /*   720 */    90,   79,   55,   90,   82,   58,   59,   60,   61,   62,
 /*   730 */    88,   75,   90,   90,   67,   79,   69,   70,   82,   72,
 /*   740 */    90,   90,   75,   90,   88,   90,   79,   57,   57,   82,
 /*   750 */    90,   90,   90,   63,   63,   88,   58,   59,   60,   61,
 /*   760 */    62,   63,   90,   79,   80,   67,   82,   69,   70,   57,
 /*   770 */    72,   90,   88,   75,    8,   63,   90,   79,   90,   90,
 /*   780 */    82,   90,   90,   57,   90,   19,   88,   90,   22,   63,
 /*   790 */    90,   25,   26,   27,   28,   29,   30,   31,   90,   33,
 /*   800 */    34,    8,   90,   37,   79,   80,   90,   82,   90,   84,
 /*   810 */    85,   86,   19,   88,   90,   22,   90,   90,   25,   26,
 /*   820 */    27,   28,   29,   30,   31,   90,   33,   34,    8,   90,
 /*   830 */    37,    6,    7,   90,    9,   10,   11,   12,   90,   19,
 /*   840 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*   850 */    30,   31,   90,   33,   34,    8,    7,   37,    9,   10,
 /*   860 */    11,   12,   90,   90,   90,   90,   19,   90,   90,   22,
 /*   870 */    90,   90,   25,   26,   27,   28,   29,   30,   31,   69,
 /*   880 */    33,   34,    8,   90,   37,   75,   90,   90,   90,   79,
 /*   890 */    90,   90,   82,   19,   90,   90,   22,   90,   88,   25,
 /*   900 */    26,   27,   28,   29,   30,   31,   69,   33,   34,    8,
 /*   910 */    90,   37,   75,   90,   53,   54,   79,   90,   57,   82,
 /*   920 */    19,   90,   90,   22,   63,   88,   25,   26,   27,   28,
 /*   930 */    29,   30,   31,   90,   33,   34,    8,   90,   37,    9,
 /*   940 */    10,   11,   12,   90,   90,   90,   90,   19,   90,   90,
 /*   950 */    22,   90,   90,   25,   26,   27,   28,   29,   30,   31,
 /*   960 */    90,   33,   34,    8,   90,   37,    9,   10,   11,   12,
 /*   970 */    90,   90,   90,   90,   19,   90,   90,   22,   90,   90,
 /*   980 */    25,   26,   27,   28,   29,   30,   31,   90,   33,   34,
 /*   990 */     8,   90,   37,   90,   90,   90,   90,   90,   90,   90,
 /*  1000 */    90,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*  1010 */    28,   29,   30,   31,   90,   33,   34,    8,   90,   37,
 /*  1020 */    90,   90,   90,   90,   90,   90,   90,   90,   19,   90,
 /*  1030 */    90,   22,   90,   90,   25,   26,   27,   28,   29,   30,
 /*  1040 */    31,   90,   33,   34,    8,   90,   37,   90,   90,   90,
 /*  1050 */    90,   90,   90,   90,   90,   19,   90,   90,   22,   90,
 /*  1060 */    90,   25,   26,   27,   28,   29,   30,   31,   90,   33,
 /*  1070 */    34,    8,   90,   37,   90,   90,   90,   90,   90,   90,
 /*  1080 */    90,   90,   19,   90,   90,   22,   90,   90,   25,   26,
 /*  1090 */    27,   28,   29,   30,   31,   90,   33,   34,    8,   90,
 /*  1100 */    37,   90,   90,    2,    3,    4,    5,    6,    7,   19,
 /*  1110 */     9,   10,   11,   12,   90,   25,   26,   27,   28,   29,
 /*  1120 */    30,   31,   90,   33,   34,   90,   90,   37,   90,   19,
 /*  1130 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*  1140 */    30,   31,   90,   33,   34,    8,   90,   37,   90,   90,
 /*  1150 */     2,    3,    4,    5,    6,    7,   19,    9,   10,   11,
 /*  1160 */    12,   90,   25,   26,   27,   28,   29,   30,   31,   90,
 /*  1170 */    33,   34,   90,   90,   37,   62,   63,   90,   65,   90,
 /*  1180 */    90,   69,   69,   90,   90,   90,   73,   75,   75,   90,
 /*  1190 */    90,   79,   79,   90,   82,   82,   19,   90,   90,   90,
 /*  1200 */    88,   88,   25,   26,   27,   28,   29,   30,   31,   90,
 /*  1210 */     2,    3,   90,   62,    6,    7,   65,   66,   62,   63,
 /*  1220 */    69,   65,   90,   90,   90,   69,   75,   19,   90,   90,
 /*  1230 */    79,   75,   24,   82,   90,   79,   90,   69,   82,   88,
 /*  1240 */    90,   90,   90,   75,   88,   62,   63,   79,   65,   90,
 /*  1250 */    82,   69,   69,   90,   90,   90,   88,   75,   75,   90,
 /*  1260 */    90,   79,   79,   90,   82,   82,   62,   63,   90,   65,
 /*  1270 */    88,   88,   90,   69,   90,   90,   90,   90,   90,   75,
 /*  1280 */    90,   62,   63,   79,   65,   90,   82,   90,   69,   90,
 /*  1290 */    90,   90,   88,   90,   75,   90,   62,   63,   79,   65,
 /*  1300 */    90,   82,   90,   69,   90,   90,   90,   88,   90,   75,
 /*  1310 */    90,   62,   63,   79,   65,   90,   82,   90,   69,   90,
 /*  1320 */    90,   90,   88,   90,   75,   90,   90,   90,   79,   62,
 /*  1330 */    63,   82,   65,   90,   62,   63,   69,   88,   90,   90,
 /*  1340 */    90,   69,   75,   90,   90,   90,   79,   75,   90,   82,
 /*  1350 */    90,   79,   69,   69,   82,   88,   90,   90,   75,   75,
 /*  1360 */    88,   90,   79,   79,   69,   82,   82,   90,   90,   69,
 /*  1370 */    75,   88,   88,   90,   79,   75,   90,   82,   90,   79,
 /*  1380 */    90,   69,   82,   88,   90,   90,   69,   75,   88,   90,
 /*  1390 */    90,   79,   75,   90,   82,   90,   79,   90,   69,   82,
 /*  1400 */    88,   90,   90,   90,   75,   88,   69,   90,   79,   90,
 /*  1410 */    90,   82,   75,   90,   90,   90,   79,   88,   90,   82,
 /*  1420 */    90,   69,   69,   69,   90,   88,   90,   75,   75,   75,
 /*  1430 */    90,   79,   79,   79,   82,   82,   82,   90,   90,   69,
 /*  1440 */    88,   88,   88,   90,   69,   75,   90,   90,   90,   79,
 /*  1450 */    75,   90,   82,   90,   79,   90,   69,   82,   88,   90,
 /*  1460 */    90,   69,   75,   88,   90,   90,   79,   75,   90,   82,
 /*  1470 */    90,   79,   90,   90,   82,   88,   69,   90,   69,   90,
 /*  1480 */    88,   90,   75,   90,   75,   90,   79,   90,   79,   82,
 /*  1490 */    90,   82,   69,   69,   90,   88,   90,   88,   75,   75,
 /*  1500 */    90,   90,   79,   79,   90,   82,   82,   90,   90,   90,
 /*  1510 */    90,   88,   88,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (183)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (1208)
static const short yy_shift_ofst[] = {
 /*     0 */     2,  112,  112,  112,   72,   32,   -8,  500,  472,  540,
 /*    10 */   540,  540,  540,  540,  540,  540,  568,  152,  432,  392,
 /*    20 */   352,  312,  272,  232,  192,  540, 1137, 1137, 1063, 1063,
 /*    30 */  1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063,
 /*    40 */  1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063, 1063,
 /*    50 */  1063, 1063, 1063, 1036, 1009,  982,  955,  928,  901,  874,
 /*    60 */   847, 1110, 1090, 1090, 1090, 1090, 1090, 1090,  234,    2,
 /*    70 */     2,  596,  820,  793,  766,   34,  154,    2,    2,    2,
 /*    80 */     2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
 /*    90 */     2,    2,    2,    2,    2,    2,  343,  316,  376,  374,
 /*   100 */   369,  361,  353,   -9,   -9,   -9,   -9,   -9,   -9, 1177,
 /*   110 */  1177, 1177, 1208,   16,    2,  343,  322,  316,  317,  316,
 /*   120 */   284, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1148,
 /*   130 */  1101,  825,  825,  825,  825,  849,  957,  615,  930,  930,
 /*   140 */   282,  274,  270,  285,  269,  253,   19,  251,  233,  229,
 /*   150 */   209,  201,  206,  211,    7,  197,  139,  164,  189,  186,
 /*   160 */   179,  178,  153,  140,  149,  137,  138,  133,  121,  104,
 /*   170 */     7,   97,  117,   69,   89,   63,   73,   66,    5,   33,
 /*   180 */    50,   19,    7,    3,
};
#define YY_REDUCE_USE_DFLT (-79)
#define YY_REDUCE_COUNT (120)
#define YY_REDUCE_MIN   (-78)
#define YY_REDUCE_MAX   (1424)
static const short yy_reduce_ofst[] = {
 /*     0 */   861,  642,  611,  580,  698,  698,  698,  667, 1113, 1267,
 /*    10 */  1249, 1234, 1219, 1204, 1183, 1156, 1151, 1272, 1272, 1272,
 /*    20 */  1272, 1272, 1272, 1272, 1272, 1272,  725,  470, 1424, 1423,
 /*    30 */  1409, 1407, 1392, 1387, 1375, 1370, 1354, 1353, 1352, 1337,
 /*    40 */  1329, 1317, 1312, 1300, 1295, 1284, 1283, 1182, 1168, 1112,
 /*    50 */   837,  810,  610,  684,  388,  348,  308,  268,  228,  188,
 /*    60 */   148,  656,  108,   68,   28,  -12,  -52,  -78,  597,  150,
 /*    70 */    67,  212,  252,  236,  212,  726,  712,  691,  690,  650,
 /*    80 */   631,  574,  571,  543,  515,  475,  447,  424,  384,  344,
 /*    90 */   304,  267,  264,  224,   65,   24,  208,  -23,  196,  172,
 /*   100 */   161,  156,  116,   81,   76,   36,    1,   -4,  -39,  296,
 /*   110 */   294,  293,  290,  305,  301,  283,  275,  265,  243,  265,
 /*   120 */   223,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   293,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    10 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    20 */   421,  421,  421,  421,  421,  294,  421,  421,  421,  421,
 /*    30 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    40 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    50 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    60 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  293,
 /*    70 */   293,  332,  375,  371,  332,  421,  421,  421,  421,  421,
 /*    80 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*    90 */   421,  421,  421,  421,  421,  421,  421,  364,  358,  358,
 /*   100 */   358,  358,  358,  358,  358,  358,  358,  358,  358,  421,
 /*   110 */   421,  421,  421,  421,  294,  421,  317,  367,  421,  365,
 /*   120 */   402,  359,  360,  395,  393,  391,  389,  387,  386,  396,
 /*   130 */   361,  345,  344,  338,  336,  340,  314,  333,  353,  342,
 /*   140 */   332,  375,  371,  313,  421,  421,  421,  300,  421,  421,
 /*   150 */   421,  421,  421,  421,  302,  421,  408,  421,  421,  421,
 /*   160 */   421,  421,  421,  421,  421,  421,  421,  421,  421,  421,
 /*   170 */   301,  421,  421,  421,  421,  421,  421,  350,  421,  421,
 /*   180 */   346,  332,  290,  421,  295,  307,  306,  310,  286,  326,
 /*   190 */   325,  312,  316,  318,  315,  324,  323,  322,  321,  320,
 /*   200 */   319,  311,  309,  308,  305,  304,  296,  399,  366,  363,
 /*   210 */   362,  299,  337,  339,  341,  343,  403,  303,  411,  420,
 /*   220 */   410,  409,  407,  406,  405,  404,  398,  419,  418,  417,
 /*   230 */   416,  415,  414,  413,  412,  394,  392,  390,  388,  397,
 /*   240 */   382,  380,  379,  378,  381,  384,  377,  376,  374,  383,
 /*   250 */   373,  372,  368,  385,  370,  369,  298,  297,  292,  291,
 /*   260 */   401,  400,  357,  356,  354,  355,  352,  351,  349,  348,
 /*   270 */   347,  335,  334,  333,  332,  331,  330,  329,  328,  327,
 /*   280 */   289,  288,  287,  285,
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
  "ELSE",          "UNLESS",        "WHILE",         "IMPORT",      
  "DOT_NAME",      "AS",            "TRY",           "RESCUE",      
  "OP2_SET",       "OP1_SET",       "OP0_SET",       "RAISE",       
  "error",         "program",       "opt_fin",       "l1",          
  "last_fin",      "fin",           "l1e",           "class",       
  "trait",         "def",           "stmt",          "fin_m",       
  "comma",         "seq",           "delim_seq",     "class_start", 
  "class_body",    "s2",            "trait_start",   "trait_body",  
  "def_start",     "def_body",      "arg",           "np_recv",     
  "id_list",       "def_args",      "def_name",      "lit",         
  "np_arg",        "np_arg_list",   "lambda",        "np_arg_list_start",
  "np_arg_list_elems",  "np_kw_arg",     "np_kw_arg_list_elems",  "np_opt_kw_arg_list",
  "lambda_start",  "lambda_args", 
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
 /* 121 */ "stmt ::= IF s2 fin seq fin ELSE fin seq fin END",
 /* 122 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 123 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 124 */ "stmt ::= IMPORT DOT_NAME",
 /* 125 */ "stmt ::= IMPORT DOT_NAME AS ID",
 /* 126 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 127 */ "stmt ::= TRY fin seq fin RESCUE ID CAST s2 fin seq fin END",
 /* 128 */ "stmt ::= ID EQUAL s2",
 /* 129 */ "stmt ::= ID OP2_SET s2",
 /* 130 */ "stmt ::= ID OP1_SET s2",
 /* 131 */ "stmt ::= ID OP0_SET s2",
 /* 132 */ "stmt ::= IVAR EQUAL s2",
 /* 133 */ "stmt ::= IVAR OP2_SET s2",
 /* 134 */ "stmt ::= IVAR OP1_SET s2",
 /* 135 */ "stmt ::= IVAR OP0_SET s2",
 /* 136 */ "stmt ::= RAISE s2",
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
  { 53, 3 },
  { 55, 3 },
  { 55, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 63, 1 },
  { 63, 1 },
  { 54, 0 },
  { 54, 1 },
  { 56, 1 },
  { 56, 2 },
  { 57, 2 },
  { 57, 1 },
  { 64, 2 },
  { 64, 1 },
  { 65, 3 },
  { 65, 1 },
  { 66, 2 },
  { 67, 1 },
  { 68, 3 },
  { 59, 4 },
  { 59, 6 },
  { 70, 1 },
  { 71, 3 },
  { 60, 4 },
  { 72, 1 },
  { 73, 3 },
  { 74, 1 },
  { 74, 3 },
  { 76, 3 },
  { 76, 1 },
  { 77, 0 },
  { 77, 3 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 61, 5 },
  { 61, 5 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 80, 1 },
  { 80, 3 },
  { 80, 5 },
  { 80, 3 },
  { 80, 5 },
  { 80, 3 },
  { 80, 5 },
  { 80, 3 },
  { 80, 5 },
  { 80, 3 },
  { 80, 3 },
  { 80, 2 },
  { 80, 4 },
  { 80, 5 },
  { 80, 3 },
  { 80, 3 },
  { 80, 5 },
  { 80, 6 },
  { 80, 2 },
  { 80, 1 },
  { 80, 4 },
  { 80, 3 },
  { 80, 3 },
  { 83, 0 },
  { 84, 3 },
  { 84, 1 },
  { 85, 3 },
  { 86, 3 },
  { 86, 1 },
  { 87, 0 },
  { 87, 2 },
  { 81, 3 },
  { 81, 2 },
  { 75, 1 },
  { 75, 3 },
  { 75, 4 },
  { 75, 2 },
  { 75, 4 },
  { 75, 5 },
  { 75, 3 },
  { 75, 3 },
  { 75, 5 },
  { 75, 6 },
  { 75, 1 },
  { 75, 3 },
  { 75, 3 },
  { 75, 4 },
  { 75, 3 },
  { 69, 3 },
  { 69, 4 },
  { 69, 2 },
  { 69, 3 },
  { 69, 3 },
  { 69, 5 },
  { 69, 3 },
  { 69, 5 },
  { 69, 3 },
  { 69, 5 },
  { 69, 3 },
  { 69, 5 },
  { 69, 3 },
  { 69, 1 },
  { 69, 2 },
  { 62, 1 },
  { 62, 3 },
  { 88, 1 },
  { 89, 3 },
  { 89, 0 },
  { 82, 5 },
  { 62, 6 },
  { 62, 10 },
  { 62, 6 },
  { 62, 6 },
  { 62, 2 },
  { 62, 4 },
  { 62, 9 },
  { 62, 12 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 2 },
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
#line 1300 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 17: /* seq ::= seq fin stmt */ yytestcase(yyruleno==17);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1306 "vm/parser.c.inc"
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
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1322 "vm/parser.c.inc"
        break;
      case 19: /* delim_seq ::= seq opt_fin */
      case 98: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==98);
#line 60 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-1].minor.yy88.a; }
#line 1328 "vm/parser.c.inc"
        break;
      case 20: /* class_start ::= CLASS */
#line 62 "vm/parser.lm"
{ S->start_class(); }
#line 1333 "vm/parser.c.inc"
        break;
      case 21: /* class_body ::= l1 fin END */
      case 25: /* trait_body ::= l1 fin END */ yytestcase(yyruleno==25);
      case 28: /* def_body ::= seq fin END */ yytestcase(yyruleno==28);
#line 63 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1340 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1347 "vm/parser.c.inc"
        break;
      case 23: /* class ::= class_start ID LT s2 fin class_body */
#line 69 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1354 "vm/parser.c.inc"
        break;
      case 24: /* trait_start ::= TRAIT */
#line 73 "vm/parser.lm"
{ S->start_trait(); }
#line 1359 "vm/parser.c.inc"
        break;
      case 26: /* trait ::= trait_start ID fin trait_body */
#line 76 "vm/parser.lm"
{
               yygotominor.yy88.a = S->trait(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a);
             }
#line 1366 "vm/parser.c.inc"
        break;
      case 27: /* def_start ::= DEF */
#line 80 "vm/parser.lm"
{ S->start_def(); }
#line 1371 "vm/parser.c.inc"
        break;
      case 29: /* arg ::= ID */
#line 83 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1376 "vm/parser.c.inc"
        break;
      case 30: /* arg ::= ID CAST np_recv */
#line 84 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1381 "vm/parser.c.inc"
        break;
      case 35: /* def_name ::= ID */
      case 36: /* def_name ::= OP0 */ yytestcase(yyruleno==36);
      case 37: /* def_name ::= LT */ yytestcase(yyruleno==37);
      case 38: /* def_name ::= OP1 */ yytestcase(yyruleno==38);
      case 39: /* def_name ::= OP2 */ yytestcase(yyruleno==39);
      case 40: /* def_name ::= SQUARE */ yytestcase(yyruleno==40);
#line 92 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1391 "vm/parser.c.inc"
        break;
      case 41: /* def ::= def_start def_name def_args fin def_body */
#line 100 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1398 "vm/parser.c.inc"
        break;
      case 42: /* def ::= def_start def_name def_args fin END */
#line 103 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1405 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= NUM */
#line 107 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1410 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= NIL */
#line 108 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1415 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= TRUE */
#line 109 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1420 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= FALSE */
#line 110 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1425 "vm/parser.c.inc"
        break;
      case 47: /* lit ::= SELF */
#line 111 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1430 "vm/parser.c.inc"
        break;
      case 48: /* lit ::= ID */
#line 112 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1435 "vm/parser.c.inc"
        break;
      case 49: /* lit ::= IVAR */
#line 113 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1440 "vm/parser.c.inc"
        break;
      case 50: /* lit ::= LITSTR */
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1445 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg OP0 np_arg */
      case 54: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==54);
      case 56: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==56);
      case 103: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==103);
      case 105: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==105);
      case 107: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==107);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1455 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 55: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==55);
      case 57: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==57);
      case 104: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==104);
      case 106: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==106);
      case 108: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==108);
#line 121 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1465 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg OP2 np_arg */
      case 109: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==109);
#line 134 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1471 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 110: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==110);
#line 136 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1477 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg CAST np_arg */
      case 102: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==102);
#line 139 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1483 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg NEQUAL np_arg */
      case 111: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==111);
#line 141 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1489 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT */
      case 87: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==87);
#line 142 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-1].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1495 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT LP RP */
      case 88: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-3].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1501 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1507 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= np_arg DCOLON ID */
      case 90: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==90);
#line 146 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1513 "vm/parser.c.inc"
        break;
      case 66: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 91: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==91);
#line 149 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1519 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 92: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==92);
#line 151 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1525 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 93: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==93);
#line 153 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1531 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= NOT np_arg */
      case 113: /* s2 ::= NOT s2 */ yytestcase(yyruleno==113);
#line 154 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1537 "vm/parser.c.inc"
        break;
      case 71: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 97: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==97);
#line 157 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1543 "vm/parser.c.inc"
        break;
      case 72: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 95: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==95);
#line 159 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1549 "vm/parser.c.inc"
        break;
      case 73: /* np_arg ::= DICT_START np_arg_list RB */
      case 96: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==96);
#line 160 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1555 "vm/parser.c.inc"
        break;
      case 74: /* np_arg_list_start ::= */
#line 162 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1560 "vm/parser.c.inc"
        break;
      case 75: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 76: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==76);
#line 163 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1566 "vm/parser.c.inc"
        break;
      case 77: /* np_kw_arg ::= ID EQUAL np_arg */
#line 166 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1571 "vm/parser.c.inc"
        break;
      case 85: /* np_recv ::= ID LP RP */
#line 178 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1576 "vm/parser.c.inc"
        break;
      case 86: /* np_recv ::= ID LP np_arg_list RP */
#line 179 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1581 "vm/parser.c.inc"
        break;
      case 99: /* s2 ::= np_recv DOT np_arg_list */
#line 197 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1586 "vm/parser.c.inc"
        break;
      case 100: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 199 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1591 "vm/parser.c.inc"
        break;
      case 101: /* s2 ::= ID np_arg_list */
#line 200 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1596 "vm/parser.c.inc"
        break;
      case 115: /* stmt ::= stmt AND s2 */
#line 216 "vm/parser.lm"
{ yygotominor.yy88.a = S->and_(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1601 "vm/parser.c.inc"
        break;
      case 116: /* lambda_start ::= LB */
#line 220 "vm/parser.lm"
{ S->start_lambda(); }
#line 1606 "vm/parser.c.inc"
        break;
      case 117: /* lambda_args ::= PIPE ID PIPE */
#line 222 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1611 "vm/parser.c.inc"
        break;
      case 119: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 225 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1616 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= IF s2 fin seq fin END */
#line 229 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1621 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= IF s2 fin seq fin ELSE fin seq fin END */
#line 231 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_else(yymsp[-8].minor.yy88.a, yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1626 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= UNLESS s2 fin seq fin END */
#line 232 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1631 "vm/parser.c.inc"
        break;
      case 123: /* stmt ::= WHILE s2 fin seq fin END */
#line 233 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1636 "vm/parser.c.inc"
        break;
      case 124: /* stmt ::= IMPORT DOT_NAME */
#line 237 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1641 "vm/parser.c.inc"
        break;
      case 125: /* stmt ::= IMPORT DOT_NAME AS ID */
#line 238 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1646 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 240 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1653 "vm/parser.c.inc"
        break;
      case 127: /* stmt ::= TRY fin seq fin RESCUE ID CAST s2 fin seq fin END */
#line 244 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-9].minor.yy88.a, yymsp[-6].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1660 "vm/parser.c.inc"
        break;
      case 128: /* stmt ::= ID EQUAL s2 */
#line 248 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1665 "vm/parser.c.inc"
        break;
      case 129: /* stmt ::= ID OP2_SET s2 */
      case 130: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==130);
      case 131: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==131);
#line 249 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1672 "vm/parser.c.inc"
        break;
      case 132: /* stmt ::= IVAR EQUAL s2 */
#line 252 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1677 "vm/parser.c.inc"
        break;
      case 133: /* stmt ::= IVAR OP2_SET s2 */
      case 134: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==134);
      case 135: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==135);
#line 254 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1684 "vm/parser.c.inc"
        break;
      case 136: /* stmt ::= RAISE s2 */
#line 259 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1689 "vm/parser.c.inc"
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
#line 1778 "vm/parser.c.inc"
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
