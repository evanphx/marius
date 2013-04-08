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
#define YYNSTATE 242
#define YYNRULE 121
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
#define YY_ACTTAB_COUNT (1071)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    39,  217,  107,  242,  210,  237,  236,  235,   21,  233,
 /*    10 */    97,   57,   62,  231,   40,  364,    3,  225,  224,  223,
 /*    20 */   222,  221,  112,  218,  150,    5,   85,   84,  164,  209,
 /*    30 */   173,   29,   28,   27,  124,   69,   39,  120,  237,  236,
 /*    40 */    26,  237,  236,    4,  160,  233,  232,   57,  173,  231,
 /*    50 */    40,  237,  236,  225,  224,  223,  222,  221,  112,  218,
 /*    60 */    43,  171,   85,   84,  138,  209,   20,   29,   28,   27,
 /*    70 */   124,   69,   39,  237,  236,  152,   26,  237,  236,   82,
 /*    80 */   131,  233,   20,   57,  146,  231,   40,  143,   55,  225,
 /*    90 */   224,  223,  222,  221,  112,  218,   81,  214,   85,   84,
 /*   100 */   130,  209,   20,   29,   28,   27,  124,   69,   39,  215,
 /*   110 */   237,  236,   26,  237,  236,   11,   80,   22,  179,   57,
 /*   120 */   173,  159,   40,   92,  212,  225,  224,  223,  222,  221,
 /*   130 */   112,  218,  205,  208,   85,   84,  129,  209,   20,   29,
 /*   140 */    28,   27,  124,   69,   39,  118,  211,   20,   26,  237,
 /*   150 */   236,  142,  136,   20,  178,   57,   59,  201,   40,  197,
 /*   160 */   194,  225,  224,  223,  222,  221,  112,  218,  199,  195,
 /*   170 */    85,   84,  139,  209,   20,   29,   28,   27,  124,   69,
 /*   180 */    39,  135,  193,   20,   26,  237,  236,  132,   17,   20,
 /*   190 */   177,   57,  191,  173,   40,  176,  190,  225,  224,  223,
 /*   200 */   222,  221,  112,  218,  189,  170,   85,   84,  169,  209,
 /*   210 */   167,   29,   28,   27,  124,   69,   39,  204,  168,   20,
 /*   220 */    26,  237,  236,  147,  133,   88,   86,   57,  162,   78,
 /*   230 */    40,   79,   65,  225,  224,  223,  222,  221,  112,  218,
 /*   240 */    83,   10,   85,   84,  137,  209,  173,   29,   28,   27,
 /*   250 */   124,   69,   67,   16,   39,  120,   26,   19,  173,  237,
 /*   260 */   236,   95,  166,  161,  175,   57,  119,  202,   40,   20,
 /*   270 */   148,  225,  224,  223,  222,  221,  112,  218,  163,    9,
 /*   280 */    85,   84,   93,  209,  173,   29,   28,   27,  124,   69,
 /*   290 */    39,   98,   15,  140,   26,  237,  236,  173,    8,   58,
 /*   300 */   158,   57,  117,  173,   40,  365,  216,  225,  224,  223,
 /*   310 */   222,  221,  112,  218,  213,  206,   85,   84,  200,  209,
 /*   320 */   365,   29,   28,   27,  124,   69,   39,  365,   14,    7,
 /*   330 */    26,  237,  236,  173,  173,  365,  156,   57,  365,  365,
 /*   340 */    40,  365,  365,  225,  224,  223,  222,  221,  112,  218,
 /*   350 */   365,   13,   85,   84,  365,  209,  173,   29,   28,   27,
 /*   360 */   124,   69,   39,  198,  365,   20,   26,  237,  236,  144,
 /*   370 */   141,   90,   87,   57,  365,  365,   40,  365,  365,  225,
 /*   380 */   224,  223,  222,  221,  112,  218,  365,   39,   85,   84,
 /*   390 */   365,  209,  365,   29,   28,   27,  124,   69,   57,  365,
 /*   400 */   365,   40,   26,  365,  225,  224,  223,  222,  221,  112,
 /*   410 */   218,  365,  306,   85,   84,  365,  209,  365,   29,   28,
 /*   420 */    27,  124,   69,  306,  365,  306,   79,   26,  365,  306,
 /*   430 */   306,  306,  306,  306,  306,  306,  306,   42,  365,   79,
 /*   440 */   365,  306,  306,  306,  306,  306,  306,  306,  306,   36,
 /*   450 */    35,   34,   76,  365,  306,  155,  240,  239,  238,  234,
 /*   460 */   365,    6,  149,  154,  180,   91,  173,  365,  106,   12,
 /*   470 */   365,  365,  203,   76,  173,  196,  155,  240,  239,  238,
 /*   480 */   234,   97,  365,  149,  153,  180,   91,   39,  365,  106,
 /*   490 */     1,  217,  109,  203,  210,  173,  196,  365,   60,  365,
 /*   500 */    97,   40,   97,  365,  225,  224,  223,  222,  221,  219,
 /*   510 */   218,  365,    2,   85,   84,   56,  209,  173,  155,  240,
 /*   520 */   239,  238,  151,  217,   99,  149,  210,  180,   91,  165,
 /*   530 */    96,  106,   97,  365,  365,  203,   18,  365,  196,  116,
 /*   540 */   365,  173,   40,  365,   97,  225,  224,  223,  222,  221,
 /*   550 */   219,  218,  365,  365,   85,   84,  365,  209,  241,  240,
 /*   560 */   239,  238,  234,  217,  108,  149,  210,  180,   91,  306,
 /*   570 */   365,  106,   97,  365,  365,  203,  217,  113,  196,  210,
 /*   580 */   306,  365,  306,   82,   97,   97,  306,  306,  306,  306,
 /*   590 */   306,  306,  306,  306,  365,   52,   78,  365,  306,  306,
 /*   600 */   306,  306,  306,  306,  306,  306,  220,  365,   52,   23,
 /*   610 */   365,  306,  225,  224,  223,  222,  221,  219,  218,  220,
 /*   620 */   365,   52,   24,  365,  209,  225,  224,  223,  222,  221,
 /*   630 */   219,  218,  220,  365,   52,   25,  365,  209,  225,  224,
 /*   640 */   223,  222,  221,  219,  218,  220,  365,   52,   41,  365,
 /*   650 */   209,  225,  224,  223,  222,  221,  219,  218,  220,  365,
 /*   660 */    52,   38,  365,  209,  225,  224,  223,  222,  221,  219,
 /*   670 */   218,  220,  365,   52,   37,  365,  209,  225,  224,  223,
 /*   680 */   222,  221,  219,  218,  220,  365,   52,   33,  365,  209,
 /*   690 */   225,  224,  223,  222,  221,  219,  218,  145,  365,   32,
 /*   700 */    31,   30,  209,  225,  224,  223,  222,  221,  219,  218,
 /*   710 */    49,   54,   53,   48,   47,  209,  144,  141,   90,   87,
 /*   720 */    46,   51,   50,   45,   44,  365,  134,  133,   89,   86,
 /*   730 */   172,  234,  365,   64,  217,  105,  180,  210,  157,  365,
 /*   740 */   106,  365,  365,   97,  203,  365,  365,  196,  220,  365,
 /*   750 */   365,  365,  365,   97,  225,  224,  223,  222,  221,  219,
 /*   760 */   218,  172,  234,  365,   74,  365,  365,  180,  365,  365,
 /*   770 */   365,  106,  365,  172,  234,  203,   72,  365,  196,  180,
 /*   780 */   365,  365,  365,  106,   97,  172,  234,  203,   70,  229,
 /*   790 */   196,  180,  228,  227,  365,  106,   97,  172,  234,  203,
 /*   800 */    68,  365,  196,  180,  365,  230,  365,  106,   97,  365,
 /*   810 */   226,  203,  172,  234,  196,   66,  365,  365,  180,  365,
 /*   820 */    97,  365,  106,  365,  365,  365,  203,  217,  100,  196,
 /*   830 */   210,  365,   77,  165,   94,   97,   97,  365,  365,  365,
 /*   840 */   172,  207,  234,   61,  365,  365,  180,  180,  188,  365,
 /*   850 */   106,  106,  106,  365,  203,  203,  203,  196,  196,  196,
 /*   860 */   365,  365,  365,   97,   97,   97,  365,  365,   48,   47,
 /*   870 */   365,  144,  141,   90,   87,   47,  365,  144,  141,   90,
 /*   880 */    87,  127,  365,  128,  365,  106,  365,  106,  365,  203,
 /*   890 */   365,  203,  196,  192,  196,  126,  365,  106,   97,  106,
 /*   900 */    97,  203,  365,  203,  196,  125,  196,  115,  365,  106,
 /*   910 */    97,  203,   97,  203,  196,  187,  196,  186,  365,  106,
 /*   920 */    97,  106,   97,  203,  365,  203,  196,  185,  196,  365,
 /*   930 */   365,  106,   97,  365,   97,  203,  365,  184,  196,  365,
 /*   940 */   365,  106,  183,  365,   97,  203,  106,  365,  196,  365,
 /*   950 */   203,  365,  182,  196,   97,  365,  106,  181,  365,   97,
 /*   960 */   203,  106,   75,  196,  365,  203,  106,   73,  196,   97,
 /*   970 */   203,  106,   71,  196,   97,  203,  106,  365,  196,   97,
 /*   980 */   203,  365,  174,  196,   97,  365,  106,  365,  365,   97,
 /*   990 */   203,  365,  365,  196,  123,  365,  365,  365,  106,   97,
 /*  1000 */   365,  365,  203,  365,  122,  196,  365,  365,  106,  121,
 /*  1010 */   365,   97,  203,  106,  365,  196,  365,  203,  365,   63,
 /*  1020 */   196,   97,  365,  106,  365,  365,   97,  203,  217,  101,
 /*  1030 */   196,  210,  217,  110,  365,  210,   97,   97,  365,  217,
 /*  1040 */   111,   97,  210,  217,  114,  365,  210,  365,   97,  365,
 /*  1050 */   217,  104,   97,  210,  217,  103,  365,  210,  365,   97,
 /*  1060 */   365,  217,  102,   97,  210,  365,  365,  365,  365,  365,
 /*  1070 */    97,
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
 /*   220 */    46,   11,   12,    7,    8,    9,   10,   17,   21,   20,
 /*   230 */    20,   20,   68,   23,   24,   25,   26,   27,   28,   29,
 /*   240 */    20,   52,   32,   33,   36,   35,   57,   37,   38,   39,
 /*   250 */    40,   41,   42,   52,    6,   14,   46,   80,   57,   11,
 /*   260 */    12,   58,   76,   65,   16,   17,   17,   72,   20,   74,
 /*   270 */    17,   23,   24,   25,   26,   27,   28,   29,   21,   52,
 /*   280 */    32,   33,   58,   35,   57,   37,   38,   39,   40,   41,
 /*   290 */     6,   69,   52,   70,   46,   11,   12,   57,   52,   70,
 /*   300 */    16,   17,   70,   57,   20,   81,   21,   23,   24,   25,
 /*   310 */    26,   27,   28,   29,   21,   21,   32,   33,   21,   35,
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
 /*   670 */    29,   17,   81,    6,   20,   81,   35,   23,   24,   25,
 /*   680 */    26,   27,   28,   29,   17,   81,    6,   31,   81,   35,
 /*   690 */    23,   24,   25,   26,   27,   28,   29,   17,   81,   43,
 /*   700 */    44,   45,   35,   23,   24,   25,   26,   27,   28,   29,
 /*   710 */     1,    2,    3,    4,    5,   35,    7,    8,    9,   10,
 /*   720 */     1,    2,    3,    4,    5,   81,    7,    8,    9,   10,
 /*   730 */    56,   57,   81,   59,   70,   71,   62,   73,   64,   81,
 /*   740 */    66,   81,   81,   79,   70,   81,   81,   73,   17,   81,
 /*   750 */    81,   81,   81,   79,   23,   24,   25,   26,   27,   28,
 /*   760 */    29,   56,   57,   81,   59,   81,   81,   62,   81,   81,
 /*   770 */    81,   66,   81,   56,   57,   70,   59,   81,   73,   62,
 /*   780 */    81,   81,   81,   66,   79,   56,   57,   70,   59,    1,
 /*   790 */    73,   62,    4,    5,   81,   66,   79,   56,   57,   70,
 /*   800 */    59,   81,   73,   62,   81,   17,   81,   66,   79,   81,
 /*   810 */    22,   70,   56,   57,   73,   59,   81,   81,   62,   81,
 /*   820 */    79,   81,   66,   81,   81,   81,   70,   70,   71,   73,
 /*   830 */    73,   81,   75,   76,   77,   79,   79,   81,   81,   81,
 /*   840 */    56,   56,   57,   59,   81,   81,   62,   62,   62,   81,
 /*   850 */    66,   66,   66,   81,   70,   70,   70,   73,   73,   73,
 /*   860 */    81,   81,   81,   79,   79,   79,   81,   81,    4,    5,
 /*   870 */    81,    7,    8,    9,   10,    5,   81,    7,    8,    9,
 /*   880 */    10,   62,   81,   62,   81,   66,   81,   66,   81,   70,
 /*   890 */    81,   70,   73,   62,   73,   62,   81,   66,   79,   66,
 /*   900 */    79,   70,   81,   70,   73,   62,   73,   66,   81,   66,
 /*   910 */    79,   70,   79,   70,   73,   62,   73,   62,   81,   66,
 /*   920 */    79,   66,   79,   70,   81,   70,   73,   62,   73,   81,
 /*   930 */    81,   66,   79,   81,   79,   70,   81,   62,   73,   81,
 /*   940 */    81,   66,   62,   81,   79,   70,   66,   81,   73,   81,
 /*   950 */    70,   81,   62,   73,   79,   81,   66,   62,   81,   79,
 /*   960 */    70,   66,   62,   73,   81,   70,   66,   62,   73,   79,
 /*   970 */    70,   66,   62,   73,   79,   70,   66,   81,   73,   79,
 /*   980 */    70,   81,   62,   73,   79,   81,   66,   81,   81,   79,
 /*   990 */    70,   81,   81,   73,   62,   81,   81,   81,   66,   79,
 /*  1000 */    81,   81,   70,   81,   62,   73,   81,   81,   66,   62,
 /*  1010 */    81,   79,   70,   66,   81,   73,   81,   70,   81,   62,
 /*  1020 */    73,   79,   81,   66,   81,   81,   79,   70,   70,   71,
 /*  1030 */    73,   73,   70,   71,   81,   73,   79,   79,   81,   70,
 /*  1040 */    71,   79,   73,   70,   71,   81,   73,   81,   79,   81,
 /*  1050 */    70,   71,   79,   73,   70,   71,   81,   73,   81,   79,
 /*  1060 */    81,   70,   71,   79,   73,   81,   81,   81,   81,   81,
 /*  1070 */    79,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (150)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (870)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   66,   66,   66,   30,   -6,  320,  356,  356,  356,
 /*    10 */   356,  356,  284,  248,  210,  174,  138,  102,  356,  381,
 /*    20 */   680,  680,  481,  481,  481,  481,  481,  481,  481,  481,
 /*    30 */   481,  481,  481,  481,  481,  481,  481,  481,  481,  481,
 /*    40 */   481,  481,  481,  522,  654,  641,  628,  615,  602,  589,
 /*    50 */   667,  667,  667,  667,  667,  667,   62,  406,  576,  563,
 /*    60 */   419,   27,   99,   40,   40,   40,   40,   40,   40,   40,
 /*    70 */    40,   40,   40,   40,   40,   40,   40,  241,  297,  294,
 /*    80 */   293,  285,  257,  253,   -7,   -7,   -7,   -7,  731,  731,
 /*    90 */   731,  788,   23,  253,  241,  249,  241,  208,  220,  709,
 /*   100 */   709,  709,  709,  709,  709,  709,  719,  709,  864,  864,
 /*   110 */   864,  870,  656,  362,  362,  216,  211,  209,  207,   57,
 /*   120 */   199,  197,  187,  184,  178,  183,  175,  171,  161,  126,
 /*   130 */   148,  129,  147,  140,  139,  111,   97,  135,  116,  103,
 /*   140 */    96,   80,   88,   76,   70,   57,   59,   67,   58,   -5,
 /*   150 */     3,
};
#define YY_REDUCE_USE_DFLT (-70)
#define YY_REDUCE_COUNT (98)
#define YY_REDUCE_MIN   (-69)
#define YY_REDUCE_MAX   (991)
static const short yy_reduce_ofst[] = {
 /*     0 */   -33,  423,  402,  465,  505,  505,  674,  756,  741,  729,
 /*    10 */   717,  705,  785,  785,  785,  785,  785,  785,  785,  784,
 /*    20 */   757,  453,  957,  947,  942,  932,  920,  910,  905,  900,
 /*    30 */   895,  890,  880,  875,  865,  855,  853,  843,  833,  831,
 /*    40 */   821,  819,  786,  841,  991,  984,  980,  973,  969,  962,
 /*    50 */   958,  664,  506,  493,  421,  -69,  -27,  145,  291,  195,
 /*    60 */   145,  484,  460,  438,  417,  409,  299,  277,  276,  246,
 /*    70 */   240,  227,  201,  189,  136,   63,   -9,  -50,  115,  109,
 /*    80 */   100,   79,   73,   56,   64,   28,    8,   -8,  232,  229,
 /*    90 */   223,  222,  224,  198,  203,  186,  203,  177,  164,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   250,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    10 */   363,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    20 */   363,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    30 */   363,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    40 */   363,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    50 */   363,  363,  363,  363,  363,  363,  363,  284,  323,  319,
 /*    60 */   284,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*    70 */   363,  363,  363,  363,  363,  363,  363,  312,  306,  306,
 /*    80 */   306,  306,  306,  363,  306,  306,  306,  306,  363,  363,
 /*    90 */   363,  363,  363,  363,  315,  363,  313,  347,  270,  307,
 /*   100 */   308,  341,  339,  337,  335,  334,  342,  309,  295,  294,
 /*   110 */   288,  290,  285,  303,  292,  267,  284,  323,  363,  363,
 /*   120 */   257,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*   130 */   363,  363,  363,  363,  363,  363,  363,  363,  363,  363,
 /*   140 */   300,  363,  363,  296,  363,  284,  319,  363,  266,  363,
 /*   150 */   363,  251,  252,  263,  262,  244,  278,  277,  265,  269,
 /*   160 */   271,  268,  321,  320,  314,  311,  310,  256,  289,  291,
 /*   170 */   293,  348,  259,  255,  362,  353,  352,  351,  350,  349,
 /*   180 */   344,  361,  360,  359,  358,  357,  356,  355,  354,  340,
 /*   190 */   338,  336,  343,  330,  328,  327,  326,  329,  332,  325,
 /*   200 */   324,  322,  331,  316,  333,  318,  317,  258,  346,  345,
 /*   210 */   304,  305,  302,  301,  299,  298,  297,  287,  286,  285,
 /*   220 */   284,  283,  282,  281,  280,  279,  276,  275,  274,  273,
 /*   230 */   272,  264,  261,  260,  254,  253,  249,  248,  247,  246,
 /*   240 */   245,  243,
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
 /*  47 */ "np_arg ::= np_arg OP0 LP s2 RP",
 /*  48 */ "np_arg ::= np_arg OP1 np_arg",
 /*  49 */ "np_arg ::= np_arg OP1 LP s2 RP",
 /*  50 */ "np_arg ::= np_arg OP2 np_arg",
 /*  51 */ "np_arg ::= np_arg OP2 LP s2 RP",
 /*  52 */ "np_arg ::= np_arg CAST np_arg",
 /*  53 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  54 */ "np_arg ::= np_arg DOT ID",
 /*  55 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  56 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  57 */ "np_arg ::= np_arg DCOLON ID",
 /*  58 */ "np_arg ::= np_arg DOT_DOLLAR lit",
 /*  59 */ "np_arg ::= np_arg DOT_DOLLAR lit LP RP",
 /*  60 */ "np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP",
 /*  61 */ "np_arg ::= NOT np_arg",
 /*  62 */ "np_arg ::= lambda",
 /*  63 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  64 */ "np_arg_list_start ::=",
 /*  65 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  66 */ "np_arg_list_elems ::= np_arg",
 /*  67 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  68 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  69 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  70 */ "np_opt_kw_arg_list ::=",
 /*  71 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  72 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  73 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  74 */ "np_recv ::= lit",
 /*  75 */ "np_recv ::= ID LP RP",
 /*  76 */ "np_recv ::= ID LP np_arg_list RP",
 /*  77 */ "np_recv ::= np_recv DOT ID",
 /*  78 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  79 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  80 */ "np_recv ::= np_recv DCOLON ID",
 /*  81 */ "np_recv ::= np_recv DOT_DOLLAR lit",
 /*  82 */ "np_recv ::= np_recv DOT_DOLLAR lit LP RP",
 /*  83 */ "np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP",
 /*  84 */ "np_recv ::= lambda",
 /*  85 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  86 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  87 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  88 */ "np_recv ::= LP s2 RP",
 /*  89 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  90 */ "s2 ::= np_recv DOT_DOLLAR lit np_arg_list",
 /*  91 */ "s2 ::= ID np_arg_list",
 /*  92 */ "s2 ::= np_recv CAST np_arg",
 /*  93 */ "s2 ::= np_recv OP0 np_arg",
 /*  94 */ "s2 ::= np_recv OP0 LP s2 RP",
 /*  95 */ "s2 ::= np_recv OP1 np_arg",
 /*  96 */ "s2 ::= np_recv OP1 LP s2 RP",
 /*  97 */ "s2 ::= np_recv OP2 np_arg",
 /*  98 */ "s2 ::= np_recv OP2 LP s2 RP",
 /*  99 */ "s2 ::= np_recv NEQUAL np_arg",
 /* 100 */ "s2 ::= np_recv",
 /* 101 */ "s2 ::= NOT s2",
 /* 102 */ "stmt ::= s2",
 /* 103 */ "lambda_start ::= LB",
 /* 104 */ "lambda_args ::= PIPE ID PIPE",
 /* 105 */ "lambda_args ::=",
 /* 106 */ "lambda ::= lambda_start lambda_args seq RB",
 /* 107 */ "stmt ::= IF s2 fin seq fin END",
 /* 108 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 109 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 110 */ "stmt ::= IMPORT ID",
 /* 111 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 112 */ "stmt ::= ID EQUAL s2",
 /* 113 */ "stmt ::= ID OP2_SET s2",
 /* 114 */ "stmt ::= ID OP1_SET s2",
 /* 115 */ "stmt ::= ID OP0_SET s2",
 /* 116 */ "stmt ::= IVAR EQUAL s2",
 /* 117 */ "stmt ::= IVAR OP2_SET s2",
 /* 118 */ "stmt ::= IVAR OP1_SET s2",
 /* 119 */ "stmt ::= IVAR OP0_SET s2",
 /* 120 */ "stmt ::= RAISE s2",
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
  { 71, 5 },
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
#line 1168 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 33 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1174 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 45: /* np_arg ::= lit */ yytestcase(yyruleno==45);
      case 62: /* np_arg ::= lambda */ yytestcase(yyruleno==62);
      case 74: /* np_recv ::= lit */ yytestcase(yyruleno==74);
      case 84: /* np_recv ::= lambda */ yytestcase(yyruleno==84);
      case 100: /* s2 ::= np_recv */ yytestcase(yyruleno==100);
      case 102: /* stmt ::= s2 */ yytestcase(yyruleno==102);
#line 34 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1189 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 58 "vm/parser.lm"
{ S->start_class(); }
#line 1194 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 59 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1200 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 61 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1207 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1214 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 69 "vm/parser.lm"
{ S->start_def(); }
#line 1219 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 72 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1224 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST np_recv */
#line 73 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1229 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= OP2 */ yytestcase(yyruleno==33);
      case 34: /* def_name ::= SQUARE */ yytestcase(yyruleno==34);
#line 81 "vm/parser.lm"
{ yygotominor.yy88.s = yymsp[0].minor.yy0.s; }
#line 1238 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin def_body */
#line 88 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, yymsp[0].minor.yy88.a);
            }
#line 1245 "vm/parser.c.inc"
        break;
      case 36: /* def ::= def_start def_name def_args fin END */
#line 91 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(yymsp[-3].minor.yy88.s, S->ast_nil());
            }
#line 1252 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NUM */
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1257 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= NIL */
#line 96 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1262 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= TRUE */
#line 97 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1267 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= FALSE */
#line 98 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1272 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= SELF */
#line 99 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1277 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= ID */
#line 100 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(yymsp[0].minor.yy0.s); }
#line 1282 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= IVAR */
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1287 "vm/parser.c.inc"
        break;
      case 44: /* lit ::= LITSTR */
#line 102 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1292 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg OP0 np_arg */
      case 48: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==48);
      case 93: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==93);
      case 95: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==95);
#line 107 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1300 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg OP0 LP s2 RP */
      case 49: /* np_arg ::= np_arg OP1 LP s2 RP */ yytestcase(yyruleno==49);
      case 94: /* s2 ::= np_recv OP0 LP s2 RP */ yytestcase(yyruleno==94);
      case 96: /* s2 ::= np_recv OP1 LP s2 RP */ yytestcase(yyruleno==96);
#line 109 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.s, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1308 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg OP2 np_arg */
      case 97: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==97);
#line 117 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1314 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg OP2 LP s2 RP */
      case 98: /* s2 ::= np_recv OP2 LP s2 RP */ yytestcase(yyruleno==98);
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-3].minor.yy0.cs, yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1320 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg CAST np_arg */
      case 92: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==92);
#line 122 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1326 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg NEQUAL np_arg */
      case 99: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==99);
#line 124 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1332 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DOT ID */
      case 77: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==77);
#line 125 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy0.s); }
#line 1338 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT ID LP RP */
      case 78: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==78);
#line 126 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy0.s); }
#line 1344 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 79: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==79);
#line 128 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy0.s); }
#line 1350 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= np_arg DCOLON ID */
      case 80: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==80);
#line 129 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1356 "vm/parser.c.inc"
        break;
      case 58: /* np_arg ::= np_arg DOT_DOLLAR lit */
      case 81: /* np_recv ::= np_recv DOT_DOLLAR lit */ yytestcase(yyruleno==81);
#line 131 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1362 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg DOT_DOLLAR lit LP RP */
      case 82: /* np_recv ::= np_recv DOT_DOLLAR lit LP RP */ yytestcase(yyruleno==82);
#line 133 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1368 "vm/parser.c.inc"
        break;
      case 60: /* np_arg ::= np_arg DOT_DOLLAR lit LP np_arg_list RP */
      case 83: /* np_recv ::= np_recv DOT_DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==83);
#line 135 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-5].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1374 "vm/parser.c.inc"
        break;
      case 61: /* np_arg ::= NOT np_arg */
      case 101: /* s2 ::= NOT s2 */ yytestcase(yyruleno==101);
#line 136 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1380 "vm/parser.c.inc"
        break;
      case 63: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 87: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==87);
#line 139 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, "[]"); }
#line 1386 "vm/parser.c.inc"
        break;
      case 64: /* np_arg_list_start ::= */
#line 141 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1391 "vm/parser.c.inc"
        break;
      case 65: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 66: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==66);
#line 142 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1397 "vm/parser.c.inc"
        break;
      case 67: /* np_kw_arg ::= ID EQUAL np_arg */
#line 145 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1402 "vm/parser.c.inc"
        break;
      case 75: /* np_recv ::= ID LP RP */
#line 157 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1407 "vm/parser.c.inc"
        break;
      case 76: /* np_recv ::= ID LP np_arg_list RP */
#line 158 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1412 "vm/parser.c.inc"
        break;
      case 85: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 170 "vm/parser.lm"
{ yygotominor.yy88.a = S->tuple(); }
#line 1417 "vm/parser.c.inc"
        break;
      case 86: /* np_recv ::= DICT_START np_arg_list RB */
#line 171 "vm/parser.lm"
{ yygotominor.yy88.a = S->dict(); }
#line 1422 "vm/parser.c.inc"
        break;
      case 88: /* np_recv ::= LP s2 RP */
#line 174 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-1].minor.yy88.a; }
#line 1427 "vm/parser.c.inc"
        break;
      case 89: /* s2 ::= np_recv DOT ID np_arg_list */
#line 176 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy0.s); }
#line 1432 "vm/parser.c.inc"
        break;
      case 90: /* s2 ::= np_recv DOT_DOLLAR lit np_arg_list */
#line 178 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-3].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1437 "vm/parser.c.inc"
        break;
      case 91: /* s2 ::= ID np_arg_list */
#line 179 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1442 "vm/parser.c.inc"
        break;
      case 103: /* lambda_start ::= LB */
#line 196 "vm/parser.lm"
{ S->start_lambda(); }
#line 1447 "vm/parser.c.inc"
        break;
      case 104: /* lambda_args ::= PIPE ID PIPE */
#line 198 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1452 "vm/parser.c.inc"
        break;
      case 106: /* lambda ::= lambda_start lambda_args seq RB */
#line 201 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1457 "vm/parser.c.inc"
        break;
      case 107: /* stmt ::= IF s2 fin seq fin END */
#line 205 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1462 "vm/parser.c.inc"
        break;
      case 108: /* stmt ::= UNLESS s2 fin seq fin END */
#line 206 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1467 "vm/parser.c.inc"
        break;
      case 109: /* stmt ::= WHILE s2 fin seq fin END */
#line 207 "vm/parser.lm"
{ yygotominor.yy88.a = S->while_(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1472 "vm/parser.c.inc"
        break;
      case 110: /* stmt ::= IMPORT ID */
#line 211 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(yymsp[0].minor.yy0.s); }
#line 1477 "vm/parser.c.inc"
        break;
      case 111: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 213 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1484 "vm/parser.c.inc"
        break;
      case 112: /* stmt ::= ID EQUAL s2 */
#line 217 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1489 "vm/parser.c.inc"
        break;
      case 113: /* stmt ::= ID OP2_SET s2 */
      case 114: /* stmt ::= ID OP1_SET s2 */ yytestcase(yyruleno==114);
      case 115: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==115);
#line 218 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1496 "vm/parser.c.inc"
        break;
      case 116: /* stmt ::= IVAR EQUAL s2 */
#line 221 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1501 "vm/parser.c.inc"
        break;
      case 117: /* stmt ::= IVAR OP2_SET s2 */
      case 118: /* stmt ::= IVAR OP1_SET s2 */ yytestcase(yyruleno==118);
      case 119: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==119);
#line 223 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1508 "vm/parser.c.inc"
        break;
      case 120: /* stmt ::= RAISE s2 */
#line 228 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1513 "vm/parser.c.inc"
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
      /* (68) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==68);
      /* (69) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==69);
      /* (70) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==70);
      /* (71) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==71);
      /* (72) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==72);
      /* (73) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==73);
      /* (105) lambda_args ::= */ yytestcase(yyruleno==105);
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
#line 1602 "vm/parser.c.inc"
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
