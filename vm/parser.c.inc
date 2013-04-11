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
#define YYNSTATE 277
#define YYNRULE 136
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
#define YY_ACTTAB_COUNT (1450)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    45,  264,  125,  277,  257,  252,  251,  200,   49,  199,
 /*    10 */   115,   68,  197,  195,   46,  252,  251,  272,  271,  270,
 /*    20 */   269,  268,  132,  265,  261,   99,   98,  264,  127,  254,
 /*    30 */   257,   34,  142,   33,   32,  151,  115,   26,   82,  187,
 /*    40 */    45,   25,  169,   31,   24,  252,  251,  252,  251,  199,
 /*    50 */   198,   68,  197,  195,   46,   64,  262,  272,  271,  270,
 /*    60 */   269,  268,  132,  265,  202,   99,   98,  264,  126,  254,
 /*    70 */   257,   34,   97,   33,   32,  151,  115,  168,   82,   24,
 /*    80 */    45,   14,  167,   31,   24,  252,  251,  249,   96,  199,
 /*    90 */   196,   68,  197,  195,   46,  258,  259,  272,  271,  270,
 /*   100 */   269,  268,  132,  265,  256,   99,   98,  264,  133,  254,
 /*   110 */   257,   34,  255,   33,   32,  151,  115,  159,   82,   24,
 /*   120 */    45,   15,   16,   31,  109,  252,  251,  253,  249,  199,
 /*   130 */   249,   68,  197,  195,   46,  237,  165,  272,  271,  270,
 /*   140 */   269,  268,  132,  265,  241,   99,   98,  264,  123,  254,
 /*   150 */   257,   34,  247,   33,   32,  151,  115,  158,   82,   24,
 /*   160 */    45,  243,  239,   31,  211,  252,  251,   23,  235,  234,
 /*   170 */   218,   68,  233,  249,   46,  150,  231,  272,  271,  270,
 /*   180 */   269,  268,  132,  265,  214,   99,   98,  264,  118,  254,
 /*   190 */   257,   34,   88,   33,   32,  151,  115,  157,   82,   24,
 /*   200 */    45,  230,  173,   31,   24,  252,  251,  252,  251,  178,
 /*   210 */   217,   68,  229,  170,   46,   24,  228,  272,  271,  270,
 /*   220 */   269,  268,  132,  265,  205,   99,   98,  264,  129,  254,
 /*   230 */   257,   34,  149,   33,   32,  151,  115,  163,   82,   24,
 /*   240 */    45,  210,  162,   31,   24,  252,  251,  160,   58,   24,
 /*   250 */   216,   68,  209,  186,   46,  108,  208,  272,  271,  270,
 /*   260 */   269,  268,  132,  265,  207,   99,   98,  264,  128,  254,
 /*   270 */   257,   34,   72,   33,   32,  151,  115,  246,   82,   24,
 /*   280 */    45,   13,  242,   31,   24,  252,  251,  249,  206,   77,
 /*   290 */   215,   68,   67,  238,   46,   24,   94,  272,  271,  270,
 /*   300 */   269,  268,  132,  265,   93,   99,   98,  264,  130,  254,
 /*   310 */   257,   34,   95,   33,   32,  151,  115,  166,   82,  113,
 /*   320 */    45,   22,  142,   31,   12,  252,  251,  249,  204,  141,
 /*   330 */   249,   68,  188,   75,   46,   91,  138,  272,  271,  270,
 /*   340 */   269,  268,  132,  265,  250,   99,   98,  264,  134,  254,
 /*   350 */   257,   34,  110,   33,   32,  151,  115,  171,   82,   80,
 /*   360 */    45,   21,  111,   31,   69,  252,  251,  249,  136,  263,
 /*   370 */   213,   68,  260,  248,   46,  415,  244,  272,  271,  270,
 /*   380 */   269,  268,  132,  265,  240,   99,   98,  264,  122,  254,
 /*   390 */   257,   34,  415,   33,   32,  151,  115,  415,   82,  415,
 /*   400 */    45,   11,  415,   31,  415,  252,  251,  249,  415,  415,
 /*   410 */   185,   68,  415,  415,   46,  415,  415,  272,  271,  270,
 /*   420 */   269,  268,  132,  265,  415,   99,   98,  264,  121,  254,
 /*   430 */   257,   34,  415,   33,   32,  151,  115,  415,   82,  415,
 /*   440 */    45,   20,  415,   31,  415,  252,  251,  249,  415,  415,
 /*   450 */   183,   68,  415,  415,   46,  415,  415,  272,  271,  270,
 /*   460 */   269,  268,  132,  265,   10,   99,   98,  415,   45,  254,
 /*   470 */   249,   34,  415,   33,   32,  151,  415,  199,   82,   68,
 /*   480 */   197,  195,   46,   31,  415,  272,  271,  270,  269,  268,
 /*   490 */   132,  265,   19,   99,   98,  415,  415,  254,  249,   34,
 /*   500 */   415,   33,   32,  151,  415,  415,   82,  415,   45,  264,
 /*   510 */   116,   31,  257,  252,  251,  203,  114,  415,  115,   68,
 /*   520 */   415,  415,   46,  415,  415,  272,  271,  270,  269,  268,
 /*   530 */   132,  265,    9,   99,   98,  415,   45,  254,  249,   34,
 /*   540 */   415,   33,   32,  151,  415,  415,   82,   68,  415,  415,
 /*   550 */    46,   31,  415,  272,  271,  270,  269,  268,  132,  265,
 /*   560 */    18,   99,   98,  415,  351,  254,  249,   34,  415,   33,
 /*   570 */    32,  151,  415,  415,   82,  351,  415,  415,   95,   31,
 /*   580 */   415,  351,  351,  351,  351,  351,  351,  351,    5,  351,
 /*   590 */   351,    2,   48,  351,  249,   78,  415,  249,  182,  275,
 /*   600 */   274,  273,  176,  250,   41,   40,   39,  140,  180,  219,
 /*   610 */   139,   38,  107,  177,    6,  124,  415,  415,  415,  245,
 /*   620 */   249,  415,  236,   37,   36,   35,   76,  415,  115,  182,
 /*   630 */   275,  274,  273,  176,  250,  415,  415,  415,  140,  201,
 /*   640 */   219,  139,  181,  107,  415,  124,  124,  415,    4,  245,
 /*   650 */   245,  415,  236,  236,  249,  415,  415,   78,  115,  115,
 /*   660 */   182,  275,  274,  273,  176,  250,  415,    8,  415,  140,
 /*   670 */   179,  219,  139,  249,  107,  415,  415,  124,  415,  415,
 /*   680 */   415,  245,   65,  415,  236,  182,  275,  274,  273,  176,
 /*   690 */   115,  131,  415,  415,  140,  245,  219,  139,  236,  107,
 /*   700 */   415,  415,  124,  415,  115,  415,  245,   17,    1,  236,
 /*   710 */   415,  415,  415,  249,  249,  115,  276,  275,  274,  273,
 /*   720 */   176,  250,  415,  264,  120,  140,  257,  219,  139,    3,
 /*   730 */   107,  415,  115,  124,  351,  249,  415,  245,  264,  119,
 /*   740 */   236,  257,  415,  415,  415,  351,  115,  115,   95,  415,
 /*   750 */   415,  351,  351,  351,  351,  351,  351,  351,  415,  351,
 /*   760 */   351,  351,  415,  351,  264,  117,  415,  257,  415,   92,
 /*   770 */   203,  112,  351,  115,  415,   94,  415,  415,  351,  351,
 /*   780 */   351,  351,  351,  351,  351,  415,  351,  351,  351,  415,
 /*   790 */   351,   55,   54,  415,  174,  172,  106,  103,  415,  351,
 /*   800 */   415,  415,   93,  415,  415,  351,  351,  351,  351,  351,
 /*   810 */   351,  351,  415,  351,  351,   61,   54,  351,  174,  172,
 /*   820 */   106,  103,  415,  415,  415,  415,  267,  415,  415,   27,
 /*   830 */   415,  415,  272,  271,  270,  269,  268,  266,  265,  227,
 /*   840 */   102,  101,   61,  415,  254,  124,  415,  415,  415,  245,
 /*   850 */   415,  415,  236,  267,  415,  415,   28,  415,  115,  272,
 /*   860 */   271,  270,  269,  268,  266,  265,  155,  102,  101,   61,
 /*   870 */   415,  254,  124,  415,  414,    7,  245,  415,  109,  236,
 /*   880 */   267,  415,  415,   29,  249,  115,  272,  271,  270,  269,
 /*   890 */   268,  266,  265,  415,  102,  101,   61,  415,  254,  174,
 /*   900 */   172,  106,  103,  415,  415,  415,  415,  267,  415,  415,
 /*   910 */    30,  415,  415,  272,  271,  270,  269,  268,  266,  265,
 /*   920 */   415,  102,  101,   61,  415,  254,  137,  161,  104,  100,
 /*   930 */   415,  415,  415,  415,  267,  415,  415,   47,  415,  415,
 /*   940 */   272,  271,  270,  269,  268,  266,  265,  415,  102,  101,
 /*   950 */    61,  415,  254,  415,  415,  415,  415,  415,  415,  415,
 /*   960 */   415,  267,  415,  415,   44,  415,  415,  272,  271,  270,
 /*   970 */   269,  268,  266,  265,  415,  102,  101,   61,  415,  254,
 /*   980 */   415,  415,  415,  415,  415,  415,  415,  415,  267,  415,
 /*   990 */   415,   43,  415,  415,  272,  271,  270,  269,  268,  266,
 /*  1000 */   265,  415,  102,  101,   61,  415,  254,  415,  415,  415,
 /*  1010 */   415,  415,  415,  415,  415,  267,  415,  415,   42,  415,
 /*  1020 */   415,  272,  271,  270,  269,  268,  266,  265,  415,  102,
 /*  1030 */   101,   45,  415,  254,  415,  415,  415,  415,  415,  415,
 /*  1040 */   415,  415,   71,  415,  415,   46,  415,  415,  272,  271,
 /*  1050 */   270,  269,  268,  266,  265,  415,   99,   98,   61,  415,
 /*  1060 */   254,  415,  415,   57,   56,   63,   62,   55,   54,  267,
 /*  1070 */   174,  172,  106,  103,  415,  272,  271,  270,  269,  268,
 /*  1080 */   266,  265,  415,  102,  101,  415,  415,  254,  415,  135,
 /*  1090 */   415,  415,   46,  415,  415,  272,  271,  270,  269,  268,
 /*  1100 */   266,  265,  415,   99,   98,   61,  415,  254,  415,  415,
 /*  1110 */    53,   52,   60,   59,   51,   50,  175,   70,  161,  105,
 /*  1120 */   100,  415,  272,  271,  270,  269,  268,  266,  265,  415,
 /*  1130 */   102,  101,  415,  415,  254,  148,  250,  415,   74,  415,
 /*  1140 */   415,  156,  219,  415,  415,  415,  184,  124,  124,  415,
 /*  1150 */   415,  245,  245,  415,  236,  236,  267,  415,  415,  415,
 /*  1160 */   115,  115,  272,  271,  270,  269,  268,  266,  265,  415,
 /*  1170 */   193,  192,  415,  148,  191,  190,   66,  147,  148,  250,
 /*  1180 */   219,   89,  415,  415,  415,  219,  124,  194,  415,  415,
 /*  1190 */   245,  124,  189,  236,  415,  245,  415,  232,  236,  115,
 /*  1200 */   415,  415,  415,  124,  115,  148,  250,  245,   87,  415,
 /*  1210 */   236,  154,  219,  415,  415,  415,  115,  124,  124,  415,
 /*  1220 */   415,  245,  245,  415,  236,  236,  148,  250,  415,   85,
 /*  1230 */   115,  115,  415,  219,  415,  415,  415,  415,  415,  124,
 /*  1240 */   415,  148,  250,  245,   83,  415,  236,  415,  219,  415,
 /*  1250 */   415,  415,  115,  415,  124,  415,  148,  250,  245,   81,
 /*  1260 */   415,  236,  415,  219,  415,  415,  415,  115,  415,  124,
 /*  1270 */   415,  148,  250,  245,   79,  415,  236,  153,  219,  415,
 /*  1280 */   415,  415,  115,  124,  124,  164,  250,  245,  245,  415,
 /*  1290 */   236,  236,  219,  415,  152,  415,  115,  115,  124,  415,
 /*  1300 */   124,  415,  245,  415,  245,  236,  415,  236,  415,  226,
 /*  1310 */   415,  115,  415,  115,  225,  124,  415,  415,  415,  245,
 /*  1320 */   124,  415,  236,  415,  245,  415,  224,  236,  115,  415,
 /*  1330 */   415,  223,  124,  115,  415,  415,  245,  124,  415,  236,
 /*  1340 */   415,  245,  222,  221,  236,  115,  415,  415,  124,  124,
 /*  1350 */   115,  415,  245,  245,  220,  236,  236,  415,  415,  415,
 /*  1360 */   124,  115,  115,  415,  245,  415,   90,  236,   86,  415,
 /*  1370 */   415,  415,  124,  115,  124,  415,  245,  415,  245,  236,
 /*  1380 */   415,  236,  415,   84,  212,  115,  415,  115,  415,  124,
 /*  1390 */   124,  415,  415,  245,  245,  415,  236,  236,  146,  415,
 /*  1400 */   415,  415,  115,  115,  124,  415,  145,  415,  245,  415,
 /*  1410 */   415,  236,  124,  415,  144,  415,  245,  115,  415,  236,
 /*  1420 */   124,  415,  143,  415,  245,  115,  415,  236,  124,  415,
 /*  1430 */    73,  415,  245,  115,  415,  236,  124,  415,  415,  415,
 /*  1440 */   245,  115,  415,  236,  415,  415,  415,  415,  415,  115,
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
 /*   100 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   110 */    82,   39,   35,   41,   42,   43,   88,   81,   46,   83,
 /*   120 */     8,   54,   57,   51,   57,   13,   14,   38,   63,   17,
 /*   130 */    63,   19,   20,   21,   22,   32,   19,   25,   26,   27,
 /*   140 */    28,   29,   30,   31,   19,   33,   34,   79,   80,   37,
 /*   150 */    82,   39,   23,   41,   42,   43,   88,   81,   46,   83,
 /*   160 */     8,   23,   23,   51,   54,   13,   14,   57,   23,   35,
 /*   170 */    18,   19,   23,   63,   22,   44,   23,   25,   26,   27,
 /*   180 */    28,   29,   30,   31,   19,   33,   34,   79,   80,   37,
 /*   190 */    82,   39,   40,   41,   42,   43,   88,   81,   46,   83,
 /*   200 */     8,   23,   81,   51,   83,   13,   14,   13,   14,   15,
 /*   210 */    18,   19,   23,   81,   22,   83,   23,   25,   26,   27,
 /*   220 */    28,   29,   30,   31,   13,   33,   34,   79,   80,   37,
 /*   230 */    82,   39,   45,   41,   42,   43,   88,   81,   46,   83,
 /*   240 */     8,   35,   81,   51,   83,   13,   14,   81,    4,   83,
 /*   250 */    18,   19,   23,   74,   22,   76,   23,   25,   26,   27,
 /*   260 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   270 */    82,   39,   19,   41,   42,   43,   88,   81,   46,   83,
 /*   280 */     8,   57,   81,   51,   83,   13,   14,   63,   23,   19,
 /*   290 */    18,   19,   89,   81,   22,   83,   22,   25,   26,   27,
 /*   300 */    28,   29,   30,   31,   22,   33,   34,   79,   80,   37,
 /*   310 */    82,   39,   22,   41,   42,   43,   88,   38,   46,   64,
 /*   320 */     8,   57,   16,   51,   57,   13,   14,   63,   85,   19,
 /*   330 */    63,   19,   74,   77,   22,   22,   19,   25,   26,   27,
 /*   340 */    28,   29,   30,   31,   63,   33,   34,   79,   80,   37,
 /*   350 */    82,   39,   64,   41,   42,   43,   88,   79,   46,   47,
 /*   360 */     8,   57,   78,   51,   79,   13,   14,   63,   79,   23,
 /*   370 */    18,   19,   23,   23,   22,   90,   23,   25,   26,   27,
 /*   380 */    28,   29,   30,   31,   23,   33,   34,   79,   80,   37,
 /*   390 */    82,   39,   90,   41,   42,   43,   88,   90,   46,   90,
 /*   400 */     8,   57,   90,   51,   90,   13,   14,   63,   90,   90,
 /*   410 */    18,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   420 */    28,   29,   30,   31,   90,   33,   34,   79,   80,   37,
 /*   430 */    82,   39,   90,   41,   42,   43,   88,   90,   46,   90,
 /*   440 */     8,   57,   90,   51,   90,   13,   14,   63,   90,   90,
 /*   450 */    18,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   460 */    28,   29,   30,   31,   57,   33,   34,   90,    8,   37,
 /*   470 */    63,   39,   90,   41,   42,   43,   90,   17,   46,   19,
 /*   480 */    20,   21,   22,   51,   90,   25,   26,   27,   28,   29,
 /*   490 */    30,   31,   57,   33,   34,   90,   90,   37,   63,   39,
 /*   500 */    90,   41,   42,   43,   90,   90,   46,   90,    8,   79,
 /*   510 */    80,   51,   82,   13,   14,   85,   86,   90,   88,   19,
 /*   520 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*   530 */    30,   31,   57,   33,   34,   90,    8,   37,   63,   39,
 /*   540 */    90,   41,   42,   43,   90,   90,   46,   19,   90,   90,
 /*   550 */    22,   51,   90,   25,   26,   27,   28,   29,   30,   31,
 /*   560 */    57,   33,   34,   90,    8,   37,   63,   39,   90,   41,
 /*   570 */    42,   43,   90,   90,   46,   19,   90,   90,   22,   51,
 /*   580 */    90,   25,   26,   27,   28,   29,   30,   31,   57,   33,
 /*   590 */    34,   57,   36,   37,   63,   55,   90,   63,   58,   59,
 /*   600 */    60,   61,   62,   63,   48,   49,   50,   67,   68,   69,
 /*   610 */    70,   36,   72,   56,   57,   75,   90,   90,   90,   79,
 /*   620 */    63,   90,   82,   48,   49,   50,   55,   90,   88,   58,
 /*   630 */    59,   60,   61,   62,   63,   90,   90,   90,   67,   69,
 /*   640 */    69,   70,   71,   72,   90,   75,   75,   90,   57,   79,
 /*   650 */    79,   90,   82,   82,   63,   90,   90,   55,   88,   88,
 /*   660 */    58,   59,   60,   61,   62,   63,   90,   57,   90,   67,
 /*   670 */    68,   69,   70,   63,   72,   90,   90,   75,   90,   90,
 /*   680 */    90,   79,   55,   90,   82,   58,   59,   60,   61,   62,
 /*   690 */    88,   75,   90,   90,   67,   79,   69,   70,   82,   72,
 /*   700 */    90,   90,   75,   90,   88,   90,   79,   57,   57,   82,
 /*   710 */    90,   90,   90,   63,   63,   88,   58,   59,   60,   61,
 /*   720 */    62,   63,   90,   79,   80,   67,   82,   69,   70,   57,
 /*   730 */    72,   90,   88,   75,    8,   63,   90,   79,   79,   80,
 /*   740 */    82,   82,   90,   90,   90,   19,   88,   88,   22,   90,
 /*   750 */    90,   25,   26,   27,   28,   29,   30,   31,   90,   33,
 /*   760 */    34,    8,   90,   37,   79,   80,   90,   82,   90,   84,
 /*   770 */    85,   86,   19,   88,   90,   22,   90,   90,   25,   26,
 /*   780 */    27,   28,   29,   30,   31,   90,   33,   34,    8,   90,
 /*   790 */    37,    6,    7,   90,    9,   10,   11,   12,   90,   19,
 /*   800 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*   810 */    30,   31,   90,   33,   34,    8,    7,   37,    9,   10,
 /*   820 */    11,   12,   90,   90,   90,   90,   19,   90,   90,   22,
 /*   830 */    90,   90,   25,   26,   27,   28,   29,   30,   31,   69,
 /*   840 */    33,   34,    8,   90,   37,   75,   90,   90,   90,   79,
 /*   850 */    90,   90,   82,   19,   90,   90,   22,   90,   88,   25,
 /*   860 */    26,   27,   28,   29,   30,   31,   69,   33,   34,    8,
 /*   870 */    90,   37,   75,   90,   53,   54,   79,   90,   57,   82,
 /*   880 */    19,   90,   90,   22,   63,   88,   25,   26,   27,   28,
 /*   890 */    29,   30,   31,   90,   33,   34,    8,   90,   37,    9,
 /*   900 */    10,   11,   12,   90,   90,   90,   90,   19,   90,   90,
 /*   910 */    22,   90,   90,   25,   26,   27,   28,   29,   30,   31,
 /*   920 */    90,   33,   34,    8,   90,   37,    9,   10,   11,   12,
 /*   930 */    90,   90,   90,   90,   19,   90,   90,   22,   90,   90,
 /*   940 */    25,   26,   27,   28,   29,   30,   31,   90,   33,   34,
 /*   950 */     8,   90,   37,   90,   90,   90,   90,   90,   90,   90,
 /*   960 */    90,   19,   90,   90,   22,   90,   90,   25,   26,   27,
 /*   970 */    28,   29,   30,   31,   90,   33,   34,    8,   90,   37,
 /*   980 */    90,   90,   90,   90,   90,   90,   90,   90,   19,   90,
 /*   990 */    90,   22,   90,   90,   25,   26,   27,   28,   29,   30,
 /*  1000 */    31,   90,   33,   34,    8,   90,   37,   90,   90,   90,
 /*  1010 */    90,   90,   90,   90,   90,   19,   90,   90,   22,   90,
 /*  1020 */    90,   25,   26,   27,   28,   29,   30,   31,   90,   33,
 /*  1030 */    34,    8,   90,   37,   90,   90,   90,   90,   90,   90,
 /*  1040 */    90,   90,   19,   90,   90,   22,   90,   90,   25,   26,
 /*  1050 */    27,   28,   29,   30,   31,   90,   33,   34,    8,   90,
 /*  1060 */    37,   90,   90,    2,    3,    4,    5,    6,    7,   19,
 /*  1070 */     9,   10,   11,   12,   90,   25,   26,   27,   28,   29,
 /*  1080 */    30,   31,   90,   33,   34,   90,   90,   37,   90,   19,
 /*  1090 */    90,   90,   22,   90,   90,   25,   26,   27,   28,   29,
 /*  1100 */    30,   31,   90,   33,   34,    8,   90,   37,   90,   90,
 /*  1110 */     2,    3,    4,    5,    6,    7,   19,    9,   10,   11,
 /*  1120 */    12,   90,   25,   26,   27,   28,   29,   30,   31,   90,
 /*  1130 */    33,   34,   90,   90,   37,   62,   63,   90,   65,   90,
 /*  1140 */    90,   69,   69,   90,   90,   90,   73,   75,   75,   90,
 /*  1150 */    90,   79,   79,   90,   82,   82,   19,   90,   90,   90,
 /*  1160 */    88,   88,   25,   26,   27,   28,   29,   30,   31,   90,
 /*  1170 */     2,    3,   90,   62,    6,    7,   65,   66,   62,   63,
 /*  1180 */    69,   65,   90,   90,   90,   69,   75,   19,   90,   90,
 /*  1190 */    79,   75,   24,   82,   90,   79,   90,   69,   82,   88,
 /*  1200 */    90,   90,   90,   75,   88,   62,   63,   79,   65,   90,
 /*  1210 */    82,   69,   69,   90,   90,   90,   88,   75,   75,   90,
 /*  1220 */    90,   79,   79,   90,   82,   82,   62,   63,   90,   65,
 /*  1230 */    88,   88,   90,   69,   90,   90,   90,   90,   90,   75,
 /*  1240 */    90,   62,   63,   79,   65,   90,   82,   90,   69,   90,
 /*  1250 */    90,   90,   88,   90,   75,   90,   62,   63,   79,   65,
 /*  1260 */    90,   82,   90,   69,   90,   90,   90,   88,   90,   75,
 /*  1270 */    90,   62,   63,   79,   65,   90,   82,   69,   69,   90,
 /*  1280 */    90,   90,   88,   75,   75,   62,   63,   79,   79,   90,
 /*  1290 */    82,   82,   69,   90,   69,   90,   88,   88,   75,   90,
 /*  1300 */    75,   90,   79,   90,   79,   82,   90,   82,   90,   69,
 /*  1310 */    90,   88,   90,   88,   69,   75,   90,   90,   90,   79,
 /*  1320 */    75,   90,   82,   90,   79,   90,   69,   82,   88,   90,
 /*  1330 */    90,   69,   75,   88,   90,   90,   79,   75,   90,   82,
 /*  1340 */    90,   79,   69,   69,   82,   88,   90,   90,   75,   75,
 /*  1350 */    88,   90,   79,   79,   69,   82,   82,   90,   90,   90,
 /*  1360 */    75,   88,   88,   90,   79,   90,   69,   82,   69,   90,
 /*  1370 */    90,   90,   75,   88,   75,   90,   79,   90,   79,   82,
 /*  1380 */    90,   82,   90,   69,   69,   88,   90,   88,   90,   75,
 /*  1390 */    75,   90,   90,   79,   79,   90,   82,   82,   69,   90,
 /*  1400 */    90,   90,   88,   88,   75,   90,   69,   90,   79,   90,
 /*  1410 */    90,   82,   75,   90,   69,   90,   79,   88,   90,   82,
 /*  1420 */    75,   90,   69,   90,   79,   88,   90,   82,   75,   90,
 /*  1430 */    69,   90,   79,   88,   90,   82,   75,   90,   90,   90,
 /*  1440 */    79,   88,   90,   82,   90,   90,   90,   90,   90,   88,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (177)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (1168)
static const short yy_shift_ofst[] = {
 /*     0 */     2,  112,  112,  112,   72,   32,   -8,  460,  432,  500,
 /*    10 */   500,  500,  500,  500,  500,  528,  152,  392,  352,  312,
 /*    20 */   272,  232,  192,  500, 1097, 1097, 1023, 1023, 1023, 1023,
 /*    30 */  1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
 /*    40 */  1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
 /*    50 */   996,  969,  942,  915,  888,  861,  834,  807, 1070, 1050,
 /*    60 */  1050, 1050, 1050, 1050, 1050,  194,    2,    2,  556,  780,
 /*    70 */   753,  726,   34,    2,    2,    2,    2,    2,    2,    2,
 /*    80 */     2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
 /*    90 */     2,  317,  306,  361,  353,  350,  349,  346,   -9,   -9,
 /*   100 */    -9,   -9,   -9,   -9, 1137, 1137, 1137, 1168,   16,    2,
 /*   110 */   317,  313,  306,  310,  306,  279, 1061, 1061, 1061, 1061,
 /*   120 */  1061, 1061, 1061, 1061, 1108, 1061,  785,  785,  785,  785,
 /*   130 */   809,  917,  575,  890,  890,  290,  282,  274,  244,  270,
 /*   140 */   253,   19,  211,  265,  241,  233,  229,  206,    7,  165,
 /*   150 */   187,  131,  193,  189,  178,  153,  149,  134,  145,  103,
 /*   160 */   139,  125,  138,  129,    7,   89,  117,   77,   81,   63,
 /*   170 */    73,   66,    5,   33,   50,   19,    7,    3,
};
#define YY_REDUCE_USE_DFLT (-79)
#define YY_REDUCE_COUNT (115)
#define YY_REDUCE_MIN   (-78)
#define YY_REDUCE_MAX   (1361)
static const short yy_reduce_ofst[] = {
 /*     0 */   821,  602,  571,  540,  658,  658,  658,  627, 1073, 1209,
 /*    10 */  1194, 1179, 1164, 1143, 1116, 1111, 1223, 1223, 1223, 1223,
 /*    20 */  1223, 1223, 1223, 1223,  685,  430, 1361, 1353, 1345, 1337,
 /*    30 */  1329, 1315, 1314, 1299, 1297, 1285, 1274, 1273, 1262, 1257,
 /*    40 */  1245, 1240, 1225, 1208, 1142, 1128, 1072,  797,  770,  570,
 /*    50 */   659,  644,  348,  308,  268,  228,  188,  148,  616,  108,
 /*    60 */    68,   28,  -12,  -52,  -78,  557,  110,   67,  196,  212,
 /*    70 */   201,  196,  672,  651,  650,  610,  591,  534,  531,  503,
 /*    80 */   475,  435,  407,  384,  344,  304,  267,  264,  224,   65,
 /*    90 */    24,  179,  -23,  166,  161,  156,  132,  121,  116,   76,
 /*   100 */    36,    1,   -4,  -39,  289,  285,  278,  284,  288,  281,
 /*   110 */   258,  256,  255,  243,  255,  203,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   286,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    10 */   413,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    20 */   413,  413,  413,  287,  413,  413,  413,  413,  413,  413,
 /*    30 */   413,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    40 */   413,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    50 */   413,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    60 */   413,  413,  413,  413,  413,  413,  286,  286,  325,  368,
 /*    70 */   364,  325,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    80 */   413,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*    90 */   413,  413,  357,  351,  351,  351,  351,  351,  351,  351,
 /*   100 */   351,  351,  351,  351,  413,  413,  413,  413,  413,  287,
 /*   110 */   413,  310,  360,  413,  358,  395,  352,  353,  388,  386,
 /*   120 */   384,  382,  380,  379,  389,  354,  338,  337,  331,  329,
 /*   130 */   333,  307,  326,  346,  335,  325,  368,  364,  306,  413,
 /*   140 */   413,  413,  293,  413,  413,  413,  413,  413,  295,  413,
 /*   150 */   401,  413,  413,  413,  413,  413,  413,  413,  413,  413,
 /*   160 */   413,  413,  413,  413,  294,  413,  413,  413,  413,  413,
 /*   170 */   413,  343,  413,  413,  339,  325,  283,  413,  288,  300,
 /*   180 */   299,  303,  279,  319,  318,  305,  309,  311,  308,  317,
 /*   190 */   316,  315,  314,  313,  312,  304,  302,  301,  298,  297,
 /*   200 */   289,  392,  359,  356,  355,  292,  330,  332,  334,  336,
 /*   210 */   396,  296,  412,  403,  402,  400,  399,  398,  397,  391,
 /*   220 */   411,  410,  409,  408,  407,  406,  405,  404,  387,  385,
 /*   230 */   383,  381,  390,  375,  373,  372,  371,  374,  377,  370,
 /*   240 */   369,  367,  376,  366,  365,  361,  378,  363,  362,  291,
 /*   250 */   290,  285,  284,  394,  393,  350,  349,  347,  348,  345,
 /*   260 */   344,  342,  341,  340,  328,  327,  326,  325,  324,  323,
 /*   270 */   322,  321,  320,  282,  281,  280,  278,
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
 /* 127 */ "stmt ::= ID EQUAL s2",
 /* 128 */ "stmt ::= ID OP2_SET s2",
 /* 129 */ "stmt ::= ID OP1_SET s2",
 /* 130 */ "stmt ::= ID OP0_SET s2",
 /* 131 */ "stmt ::= IVAR EQUAL s2",
 /* 132 */ "stmt ::= IVAR OP2_SET s2",
 /* 133 */ "stmt ::= IVAR OP1_SET s2",
 /* 134 */ "stmt ::= IVAR OP0_SET s2",
 /* 135 */ "stmt ::= RAISE s2",
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
#line 1281 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 17: /* seq ::= seq fin stmt */ yytestcase(yyruleno==17);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1287 "vm/parser.c.inc"
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
#line 1303 "vm/parser.c.inc"
        break;
      case 19: /* delim_seq ::= seq opt_fin */
      case 98: /* np_recv ::= LP s2 RP */ yytestcase(yyruleno==98);
#line 60 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-1].minor.yy88.a; }
#line 1309 "vm/parser.c.inc"
        break;
      case 20: /* class_start ::= CLASS */
#line 62 "vm/parser.lm"
{ S->start_class(); }
#line 1314 "vm/parser.c.inc"
        break;
      case 21: /* class_body ::= l1 fin END */
      case 25: /* trait_body ::= l1 fin END */ yytestcase(yyruleno==25);
      case 28: /* def_body ::= seq fin END */ yytestcase(yyruleno==28);
#line 63 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1321 "vm/parser.c.inc"
        break;
      case 22: /* class ::= class_start ID fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1328 "vm/parser.c.inc"
        break;
      case 23: /* class ::= class_start ID LT s2 fin class_body */
#line 69 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1335 "vm/parser.c.inc"
        break;
      case 24: /* trait_start ::= TRAIT */
#line 73 "vm/parser.lm"
{ S->start_trait(); }
#line 1340 "vm/parser.c.inc"
        break;
      case 26: /* trait ::= trait_start ID fin trait_body */
#line 76 "vm/parser.lm"
{
               yygotominor.yy88.a = S->trait(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a);
             }
#line 1347 "vm/parser.c.inc"
        break;
      case 27: /* def_start ::= DEF */
#line 80 "vm/parser.lm"
{ S->start_def(); }
#line 1352 "vm/parser.c.inc"
        break;
      case 29: /* arg ::= ID */
#line 83 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1357 "vm/parser.c.inc"
        break;
      case 30: /* arg ::= ID CAST np_recv */
#line 84 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1362 "vm/parser.c.inc"
        break;
      case 35: /* def_name ::= ID */
      case 36: /* def_name ::= OP0 */ yytestcase(yyruleno==36);
      case 37: /* def_name ::= LT */ yytestcase(yyruleno==37);
      case 38: /* def_name ::= OP1 */ yytestcase(yyruleno==38);
      case 39: /* def_name ::= OP2 */ yytestcase(yyruleno==39);
      case 40: /* def_name ::= SQUARE */ yytestcase(yyruleno==40);
#line 92 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1372 "vm/parser.c.inc"
        break;
      case 41: /* def ::= def_start def_name def_args fin def_body */
#line 100 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1379 "vm/parser.c.inc"
        break;
      case 42: /* def ::= def_start def_name def_args fin END */
#line 103 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1386 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= NUM */
#line 107 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1391 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= NIL */
#line 108 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1396 "vm/parser.c.inc"
        break;
      case 45: /* lit ::= TRUE */
#line 109 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1401 "vm/parser.c.inc"
        break;
      case 46: /* lit ::= FALSE */
#line 110 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1406 "vm/parser.c.inc"
        break;
      case 47: /* lit ::= SELF */
#line 111 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1411 "vm/parser.c.inc"
        break;
      case 48: /* lit ::= ID */
#line 112 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1416 "vm/parser.c.inc"
        break;
      case 49: /* lit ::= IVAR */
#line 113 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1421 "vm/parser.c.inc"
        break;
      case 50: /* lit ::= LITSTR */
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1426 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg OP0 np_arg */
      case 54: /* np_arg ::= np_arg LT np_arg */ yytestcase(yyruleno==54);
      case 56: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==56);
      case 103: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==103);
      case 105: /* s2 ::= np_recv LT np_arg */ yytestcase(yyruleno==105);
      case 107: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==107);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1436 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 55: /* np_arg ::= np_arg LT LP s2 RP */ yytestcase(yyruleno==55);
      case 57: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==57);
      case 104: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==104);
      case 106: /* s2 ::= np_recv LT LP s2 RP */ yytestcase(yyruleno==106);
      case 108: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==108);
#line 121 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1446 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg OP2 np_arg */
      case 109: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==109);
#line 134 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1452 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 110: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==110);
#line 136 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1458 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg CAST np_arg */
      case 102: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==102);
#line 139 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1464 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= np_arg NEQUAL np_arg */
      case 111: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==111);
#line 141 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1470 "vm/parser.c.inc"
        break;
      case 62: /* np_arg ::= np_arg DOT */
      case 87: /* np_recv ::= np_recv DOT */ yytestcase(yyruleno==87);
#line 142 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-1].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1476 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg DOT LP RP */
      case 88: /* np_recv ::= np_recv DOT LP RP */ yytestcase(yyruleno==88);
#line 143 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-3].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1482 "vm/parser.c.inc"
        break;
      case 64: /* np_arg ::= np_arg DOT LP np_arg_list RP */
      case 89: /* np_recv ::= np_recv DOT LP np_arg_list RP */ yytestcase(yyruleno==89);
#line 145 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1488 "vm/parser.c.inc"
        break;
      case 65: /* np_arg ::= np_arg DCOLON ID */
      case 90: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==90);
#line 146 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1494 "vm/parser.c.inc"
        break;
      case 66: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 91: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==91);
#line 149 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1500 "vm/parser.c.inc"
        break;
      case 67: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 92: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==92);
#line 151 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1506 "vm/parser.c.inc"
        break;
      case 68: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 93: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==93);
#line 153 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1512 "vm/parser.c.inc"
        break;
      case 69: /* np_arg ::= NOT np_arg */
      case 113: /* s2 ::= NOT s2 */ yytestcase(yyruleno==113);
#line 154 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1518 "vm/parser.c.inc"
        break;
      case 71: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 97: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==97);
#line 157 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1524 "vm/parser.c.inc"
        break;
      case 72: /* np_arg ::= TUPLE_START np_arg_list RP */
      case 95: /* np_recv ::= TUPLE_START np_arg_list RP */ yytestcase(yyruleno==95);
#line 159 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1530 "vm/parser.c.inc"
        break;
      case 73: /* np_arg ::= DICT_START np_arg_list RB */
      case 96: /* np_recv ::= DICT_START np_arg_list RB */ yytestcase(yyruleno==96);
#line 160 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1536 "vm/parser.c.inc"
        break;
      case 74: /* np_arg_list_start ::= */
#line 162 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1541 "vm/parser.c.inc"
        break;
      case 75: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 76: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==76);
#line 163 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1547 "vm/parser.c.inc"
        break;
      case 77: /* np_kw_arg ::= ID EQUAL np_arg */
#line 166 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1552 "vm/parser.c.inc"
        break;
      case 85: /* np_recv ::= ID LP RP */
#line 178 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1557 "vm/parser.c.inc"
        break;
      case 86: /* np_recv ::= ID LP np_arg_list RP */
#line 179 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1562 "vm/parser.c.inc"
        break;
      case 99: /* s2 ::= np_recv DOT np_arg_list */
#line 197 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1567 "vm/parser.c.inc"
        break;
      case 100: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 199 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1572 "vm/parser.c.inc"
        break;
      case 101: /* s2 ::= ID np_arg_list */
#line 200 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1577 "vm/parser.c.inc"
        break;
      case 115: /* stmt ::= stmt AND s2 */
#line 216 "vm/parser.lm"
{ yygotominor.yy88.a = S->and_(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1582 "vm/parser.c.inc"
        break;
      case 116: /* lambda_start ::= LB */
#line 220 "vm/parser.lm"
{ S->start_lambda(); }
#line 1587 "vm/parser.c.inc"
        break;
      case 117: /* lambda_args ::= PIPE ID PIPE */
#line 222 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1592 "vm/parser.c.inc"
        break;
      case 119: /* lambda ::= lambda_start lambda_args opt_fin delim_seq RB */
#line 225 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1597 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= IF s2 fin seq fin END */
#line 229 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1602 "vm/parser.c.inc"
        break;
      case 121: /* stmt ::= IF s2 fin seq fin ELSE fin seq fin END */
#line 231 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_else(yymsp[-8].minor.yy88.a, yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1607 "vm/parser.c.inc"
        break;
      case 122: /* stmt ::= UNLESS s2 fin seq fin END */
#line 232 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1612 "vm/parser.c.inc"
        break;
      case 123: /* stmt ::= WHILE s2 fin seq fin END */
#line 233 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1617 "vm/parser.c.inc"
        break;
      case 124: /* stmt ::= IMPORT DOT_NAME */
#line 237 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1622 "vm/parser.c.inc"
        break;
      case 125: /* stmt ::= IMPORT DOT_NAME AS ID */
#line 238 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1627 "vm/parser.c.inc"
        break;
      case 126: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 240 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1634 "vm/parser.c.inc"
        break;
      case 127: /* stmt ::= ID EQUAL s2 */
#line 244 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1639 "vm/parser.c.inc"
        break;
      case 128: /* stmt ::= ID OP2_SET s2 */
      case 129: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==129);
      case 130: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==130);
#line 245 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1646 "vm/parser.c.inc"
        break;
      case 131: /* stmt ::= IVAR EQUAL s2 */
#line 248 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1651 "vm/parser.c.inc"
        break;
      case 132: /* stmt ::= IVAR OP2_SET s2 */
      case 133: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==133);
      case 134: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==134);
#line 250 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1658 "vm/parser.c.inc"
        break;
      case 135: /* stmt ::= RAISE s2 */
#line 255 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1663 "vm/parser.c.inc"
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
#line 1752 "vm/parser.c.inc"
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
