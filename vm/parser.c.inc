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
#define YYNOCODE 78
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy32;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 204
#define YYNRULE 108
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
#define YY_ACTTAB_COUNT (884)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    32,  199,  198,  199,  198,  197,  204,  195,   22,   47,
 /*    10 */    42,  193,  102,  114,  182,  181,  180,  179,  178,   98,
 /*    20 */   175,   33,    4,   75,   74,  118,  167,  140,   29,   28,
 /*    30 */    27,  105,   57,   31,   30,   32,   26,   77,  199,  198,
 /*    40 */   199,  198,  195,  194,   47,   49,  193,  102,  114,  182,
 /*    50 */   181,  180,  179,  178,   98,  175,   52,   76,   75,   74,
 /*    60 */   121,  167,  138,   29,   28,   27,  105,   57,  120,  191,
 /*    70 */    32,   26,  190,  199,  198,  186,  107,  195,   20,   47,
 /*    80 */   106,  193,   20,  192,  182,  181,  180,  179,  178,   98,
 /*    90 */   175,  124,    5,   75,   74,  189,  167,  140,   29,   28,
 /*   100 */    27,  105,   57,  185,   79,   32,   26,   21,  199,  198,
 /*   110 */   199,  198,  126,  183,   47,  117,  115,   20,   20,  182,
 /*   120 */   181,  180,  179,  178,   98,  175,  135,  188,   75,   74,
 /*   130 */   111,  167,   20,   29,   28,   27,  105,   57,  199,  198,
 /*   140 */    32,   26,   72,  199,  198,  110,    6,   20,  146,   47,
 /*   150 */   109,  140,   20,   45,  182,  181,  180,  179,  178,   98,
 /*   160 */   175,  172,   17,   75,   74,   71,  167,  140,   29,   28,
 /*   170 */    27,  105,   57,  170,  169,   32,   26,  112,  199,  198,
 /*   180 */    11,   16,  164,  145,   47,  140,  140,  155,  166,  182,
 /*   190 */   181,  180,  179,  178,   98,  175,  160,   10,   75,   74,
 /*   200 */   157,  167,  140,   29,   28,   27,  105,   57,  153,  152,
 /*   210 */    32,   26,   15,  199,  198,    9,   14,  140,  144,   47,
 /*   220 */   140,  140,  143,   65,  182,  181,  180,  179,  178,   98,
 /*   230 */   175,   73,    8,   75,   74,  187,  167,  140,   29,   28,
 /*   240 */    27,  105,   57,  122,  113,   32,   26,   13,  199,  198,
 /*   250 */     7,   12,  140,    1,   47,  140,  140,  120,  140,  182,
 /*   260 */   181,  180,  179,  178,   98,  175,   19,    2,   75,   74,
 /*   270 */    81,  167,  140,   29,   28,   27,  105,   57,   55,  137,
 /*   280 */    32,   26,   18,  199,  198,  313,    3,  140,  142,   47,
 /*   290 */   104,   84,  116,   85,  182,  181,  180,  179,  178,   98,
 /*   300 */   175,   48,  173,   75,   74,  163,  167,   20,   29,   28,
 /*   310 */    27,  105,   57,  171,  165,   32,   26,  161,  199,  198,
 /*   320 */   159,  158,   20,  130,   47,  314,  156,  314,   20,  182,
 /*   330 */   181,  180,  179,  178,   98,  175,  314,  314,   75,   74,
 /*   340 */   314,  167,  314,   29,   28,   27,  105,   57,  314,  314,
 /*   350 */    32,   26,  314,  199,  198,  314,  314,  314,  314,   47,
 /*   360 */   314,  314,  314,  314,  182,  181,  180,  179,  178,   98,
 /*   370 */   175,  314,  314,   75,   74,   32,  167,  314,   29,   28,
 /*   380 */    27,  105,   57,  314,   47,  314,   26,  314,  314,  182,
 /*   390 */   181,  180,  179,  178,   98,  175,  314,  314,   75,   74,
 /*   400 */   262,  167,  314,   29,   28,   27,  105,   57,  314,  262,
 /*   410 */   314,   26,   70,  314,  262,  262,  262,  262,  262,  262,
 /*   420 */   262,  314,   25,  314,   43,   42,  262,  102,  114,  314,
 /*   430 */   314,  314,  314,   66,   24,   23,  129,  202,  201,  200,
 /*   440 */   196,  314,  314,  123,  128,  147,   78,  314,  314,  314,
 /*   450 */   314,  314,  162,   66,  314,  154,  129,  202,  201,  200,
 /*   460 */   196,   93,   83,  123,  127,  147,   78,  314,  314,  314,
 /*   470 */   314,  314,  162,   46,  314,  154,  129,  202,  201,  200,
 /*   480 */   125,   93,   83,  123,  314,  147,   78,  314,  314,   32,
 /*   490 */   174,   94,  162,  168,  314,  154,  314,  314,   50,  314,
 /*   500 */    83,   93,   83,  182,  181,  180,  179,  178,  176,  175,
 /*   510 */   314,  314,   75,   74,  314,  167,  203,  202,  201,  200,
 /*   520 */   196,  314,  314,  123,  314,  147,   78,   44,   41,   40,
 /*   530 */    43,   42,  162,  102,  114,  154,  314,  314,  314,  262,
 /*   540 */   314,   93,   83,   37,   38,   34,   36,   35,  262,  100,
 /*   550 */   108,   70,  314,  262,  262,  262,  262,  262,  262,  262,
 /*   560 */   262,  174,   87,  314,  168,  262,   67,  136,   80,  262,
 /*   570 */   314,   83,   69,  314,  262,  262,  262,  262,  262,  262,
 /*   580 */   262,  262,  174,   86,  314,  168,  262,  314,  136,   82,
 /*   590 */   262,  314,   83,   68,  314,  262,  262,  262,  262,  262,
 /*   600 */   262,  262,   39,  314,  314,  174,   97,  262,  168,  314,
 /*   610 */   314,  177,  314,  314,  314,   83,  182,  181,  180,  179,
 /*   620 */   178,  176,  175,   39,  174,   99,  314,  168,  167,  314,
 /*   630 */   314,  314,  119,  314,   83,  314,  314,  182,  181,  180,
 /*   640 */   179,  178,  176,  175,  314,  150,  314,  314,  314,  167,
 /*   650 */   139,  196,  162,   64,  314,  154,  147,  314,  131,  314,
 /*   660 */   314,   93,   83,  162,  314,  314,  154,  314,  314,  177,
 /*   670 */   314,  314,   93,   83,  182,  181,  180,  179,  178,  176,
 /*   680 */   175,  139,  196,  314,   62,  139,  196,  147,   60,  174,
 /*   690 */   103,  147,  168,  314,  162,  314,  314,  154,  162,   83,
 /*   700 */   314,  154,  314,   93,   83,  314,  314,   93,   83,  139,
 /*   710 */   196,  314,   58,  314,  314,  147,  174,   96,  314,  168,
 /*   720 */   314,  314,  162,  314,  314,  154,   83,  139,  196,  314,
 /*   730 */    56,   93,   83,  147,  314,  139,  196,  151,   54,  139,
 /*   740 */   162,  147,   51,  154,  162,  147,  314,  154,  162,   93,
 /*   750 */    83,  154,  162,   93,   83,  154,  314,   93,   83,  314,
 /*   760 */   314,   93,   83,  184,  196,  174,   95,  149,  168,  147,
 /*   770 */   314,  148,  314,  314,  162,   83,  162,  154,  162,  154,
 /*   780 */   314,  154,  314,   93,   83,   93,   83,   93,   83,   63,
 /*   790 */   314,   61,  314,  314,  314,  314,  162,  314,  162,  154,
 /*   800 */   314,  154,   59,  314,  141,   93,   83,   93,   83,  162,
 /*   810 */   314,  162,  154,  314,  154,  314,  134,  314,   93,   83,
 /*   820 */    93,   83,  314,  162,  174,  101,  154,  168,  133,  314,
 /*   830 */   132,  314,   93,   83,   83,  162,  314,  162,  154,  314,
 /*   840 */   154,  314,   53,  314,   93,   83,   93,   83,  314,  162,
 /*   850 */   174,   92,  154,  168,  174,   91,  314,  168,   93,   83,
 /*   860 */    83,  314,  174,   90,   83,  168,  314,  174,   89,  314,
 /*   870 */   168,  314,   83,  174,   88,  314,  168,   83,  314,  314,
 /*   880 */   314,  314,  314,   83,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    9,   10,    9,   10,   11,    0,   13,   16,   15,
 /*    10 */     5,   17,    7,    8,   20,   21,   22,   23,   24,   25,
 /*    20 */    26,   28,   48,   29,   30,   15,   32,   53,   34,   35,
 /*    30 */    36,   37,   38,   40,   41,    6,   42,   27,    9,   10,
 /*    40 */     9,   10,   13,   14,   15,   15,   17,    7,    8,   20,
 /*    50 */    21,   22,   23,   24,   25,   26,   15,   27,   29,   30,
 /*    60 */     2,   32,   31,   34,   35,   36,   37,   38,   12,    1,
 /*    70 */     6,   42,    4,    9,   10,   19,   67,   13,   69,   15,
 /*    80 */    67,   17,   69,   15,   20,   21,   22,   23,   24,   25,
 /*    90 */    26,   47,   48,   29,   30,   15,   32,   53,   34,   35,
 /*   100 */    36,   37,   38,   61,   62,    6,   42,   54,    9,   10,
 /*   110 */     9,   10,   11,   14,   15,   67,   67,   69,   69,   20,
 /*   120 */    21,   22,   23,   24,   25,   26,   73,    9,   29,   30,
 /*   130 */    67,   32,   69,   34,   35,   36,   37,   38,    9,   10,
 /*   140 */     6,   42,   18,    9,   10,   67,   48,   69,   14,   15,
 /*   150 */    67,   53,   69,   28,   20,   21,   22,   23,   24,   25,
 /*   160 */    26,   19,   48,   29,   30,   18,   32,   53,   34,   35,
 /*   170 */    36,   37,   38,   19,   15,    6,   42,   15,    9,   10,
 /*   180 */    48,   48,   19,   14,   15,   53,   53,   15,   33,   20,
 /*   190 */    21,   22,   23,   24,   25,   26,   19,   48,   29,   30,
 /*   200 */    19,   32,   53,   34,   35,   36,   37,   38,   19,   31,
 /*   210 */     6,   42,   48,    9,   10,   48,   48,   53,   14,   15,
 /*   220 */    53,   53,   15,   63,   20,   21,   22,   23,   24,   25,
 /*   230 */    26,   18,   48,   29,   30,   61,   32,   53,   34,   35,
 /*   240 */    36,   37,   38,   15,   33,    6,   42,   48,    9,   10,
 /*   250 */    48,   48,   53,   48,   15,   53,   53,   12,   53,   20,
 /*   260 */    21,   22,   23,   24,   25,   26,   76,   48,   29,   30,
 /*   270 */    54,   32,   53,   34,   35,   36,   37,   38,   39,   71,
 /*   280 */     6,   42,   48,    9,   10,   44,   45,   53,   14,   15,
 /*   290 */    15,   54,   65,   64,   20,   21,   22,   23,   24,   25,
 /*   300 */    26,   65,   19,   29,   30,   67,   32,   69,   34,   35,
 /*   310 */    36,   37,   38,   19,   19,    6,   42,   19,    9,   10,
 /*   320 */    67,   19,   69,   14,   15,   77,   67,   77,   69,   20,
 /*   330 */    21,   22,   23,   24,   25,   26,   77,   77,   29,   30,
 /*   340 */    77,   32,   77,   34,   35,   36,   37,   38,   77,   77,
 /*   350 */     6,   42,   77,    9,   10,   77,   77,   77,   77,   15,
 /*   360 */    77,   77,   77,   77,   20,   21,   22,   23,   24,   25,
 /*   370 */    26,   77,   77,   29,   30,    6,   32,   77,   34,   35,
 /*   380 */    36,   37,   38,   77,   15,   77,   42,   77,   77,   20,
 /*   390 */    21,   22,   23,   24,   25,   26,   77,   77,   29,   30,
 /*   400 */     6,   32,   77,   34,   35,   36,   37,   38,   77,   15,
 /*   410 */    77,   42,   18,   77,   20,   21,   22,   23,   24,   25,
 /*   420 */    26,   77,   28,   77,    4,    5,   32,    7,    8,   77,
 /*   430 */    77,   77,   77,   46,   40,   41,   49,   50,   51,   52,
 /*   440 */    53,   77,   77,   56,   57,   58,   59,   77,   77,   77,
 /*   450 */    77,   77,   65,   46,   77,   68,   49,   50,   51,   52,
 /*   460 */    53,   74,   75,   56,   57,   58,   59,   77,   77,   77,
 /*   470 */    77,   77,   65,   46,   77,   68,   49,   50,   51,   52,
 /*   480 */    53,   74,   75,   56,   77,   58,   59,   77,   77,    6,
 /*   490 */    65,   66,   65,   68,   77,   68,   77,   77,   15,   77,
 /*   500 */    75,   74,   75,   20,   21,   22,   23,   24,   25,   26,
 /*   510 */    77,   77,   29,   30,   77,   32,   49,   50,   51,   52,
 /*   520 */    53,   77,   77,   56,   77,   58,   59,    1,    2,    3,
 /*   530 */     4,    5,   65,    7,    8,   68,   77,   77,   77,    6,
 /*   540 */    77,   74,   75,    1,    2,    3,    4,    5,   15,    7,
 /*   550 */     8,   18,   77,   20,   21,   22,   23,   24,   25,   26,
 /*   560 */     6,   65,   66,   77,   68,   32,   70,   71,   72,   15,
 /*   570 */    77,   75,   18,   77,   20,   21,   22,   23,   24,   25,
 /*   580 */    26,    6,   65,   66,   77,   68,   32,   77,   71,   72,
 /*   590 */    15,   77,   75,   18,   77,   20,   21,   22,   23,   24,
 /*   600 */    25,   26,    6,   77,   77,   65,   66,   32,   68,   77,
 /*   610 */    77,   15,   77,   77,   77,   75,   20,   21,   22,   23,
 /*   620 */    24,   25,   26,    6,   65,   66,   77,   68,   32,   77,
 /*   630 */    77,   77,   15,   77,   75,   77,   77,   20,   21,   22,
 /*   640 */    23,   24,   25,   26,   77,   58,   77,   77,   77,   32,
 /*   650 */    52,   53,   65,   55,   77,   68,   58,   77,   60,   77,
 /*   660 */    77,   74,   75,   65,   77,   77,   68,   77,   77,   15,
 /*   670 */    77,   77,   74,   75,   20,   21,   22,   23,   24,   25,
 /*   680 */    26,   52,   53,   77,   55,   52,   53,   58,   55,   65,
 /*   690 */    66,   58,   68,   77,   65,   77,   77,   68,   65,   75,
 /*   700 */    77,   68,   77,   74,   75,   77,   77,   74,   75,   52,
 /*   710 */    53,   77,   55,   77,   77,   58,   65,   66,   77,   68,
 /*   720 */    77,   77,   65,   77,   77,   68,   75,   52,   53,   77,
 /*   730 */    55,   74,   75,   58,   77,   52,   53,   58,   55,   52,
 /*   740 */    65,   58,   55,   68,   65,   58,   77,   68,   65,   74,
 /*   750 */    75,   68,   65,   74,   75,   68,   77,   74,   75,   77,
 /*   760 */    77,   74,   75,   52,   53,   65,   66,   58,   68,   58,
 /*   770 */    77,   58,   77,   77,   65,   75,   65,   68,   65,   68,
 /*   780 */    77,   68,   77,   74,   75,   74,   75,   74,   75,   58,
 /*   790 */    77,   58,   77,   77,   77,   77,   65,   77,   65,   68,
 /*   800 */    77,   68,   58,   77,   58,   74,   75,   74,   75,   65,
 /*   810 */    77,   65,   68,   77,   68,   77,   58,   77,   74,   75,
 /*   820 */    74,   75,   77,   65,   65,   66,   68,   68,   58,   77,
 /*   830 */    58,   77,   74,   75,   75,   65,   77,   65,   68,   77,
 /*   840 */    68,   77,   58,   77,   74,   75,   74,   75,   77,   65,
 /*   850 */    65,   66,   68,   68,   65,   66,   77,   68,   74,   75,
 /*   860 */    75,   77,   65,   66,   75,   68,   77,   65,   66,   77,
 /*   870 */    68,   77,   75,   65,   66,   77,   68,   75,   77,   77,
 /*   880 */    77,   77,   77,   75,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (124)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (654)
static const short yy_shift_ofst[] = {
 /*     0 */    -9,   64,   64,   64,   29,   -6,  309,  344,  344,  344,
 /*    10 */   344,  344,  274,  239,  204,  169,  134,   99,  344,  369,
 /*    20 */   617,  617,  483,  483,  483,  483,  483,  483,  483,  483,
 /*    30 */   483,  483,  483,  483,  596,  596,  596,  596,  596,  596,
 /*    40 */   596,  596,  596,  596,  596,  596,  101,  394,  575,  554,
 /*    50 */   533,   31,   -8,  129,  129,  129,  129,  129,  129,  129,
 /*    60 */   129,  129,  129,  129,  129,  129,  129,  245,  302,  298,
 /*    70 */   295,  294,  283,  228,   -9,   -9,  654,  654,   68,   56,
 /*    80 */   245,  275,  245,  211,  228,  213,  526,  526,  526,  526,
 /*    90 */   526,  526,  526,  542,  526,  420,  420,  420,   -7,    5,
 /*   100 */    30,   40,   10,   40,  125,  207,  178,  189,  172,  181,
 /*   110 */   177,  163,  155,  162,  159,  154,  147,  142,  124,  125,
 /*   120 */   118,   80,   58,   41,    6,
};
#define YY_REDUCE_USE_DFLT (-27)
#define YY_REDUCE_COUNT (85)
#define YY_REDUCE_MIN   (-26)
#define YY_REDUCE_MAX   (808)
static const short yy_reduce_ofst[] = {
 /*     0 */   241,  407,  387,  427,  467,  467,  598,  683,  675,  657,
 /*    10 */   633,  629,  711,  711,  711,  711,  711,  711,  711,  687,
 /*    20 */   496,  517,  784,  772,  770,  758,  746,  744,  733,  731,
 /*    30 */   713,  709,  679,  587,  808,  802,  797,  789,  785,  759,
 /*    40 */   700,  651,  624,  559,  540,  425,   44,  238,  259,  253,
 /*    50 */   238,  234,  219,  205,  203,  202,  199,  184,  168,  167,
 /*    60 */   164,  149,  133,  132,  114,   98,  -26,   53,   83,   78,
 /*    70 */    63,   49,   48,   42,   13,    9,  236,  227,  229,  237,
 /*    80 */   216,  208,  216,  190,  174,  160,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   212,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*    10 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*    20 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*    30 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*    40 */   312,  312,  312,  312,  312,  312,  312,  244,  279,  275,
 /*    50 */   244,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*    60 */   312,  312,  312,  312,  312,  312,  312,  268,  262,  262,
 /*    70 */   262,  262,  262,  312,  262,  262,  312,  312,  312,  312,
 /*    80 */   271,  312,  269,  298,  312,  232,  263,  264,  292,  291,
 /*    90 */   290,  289,  288,  293,  265,  252,  251,  248,  245,  249,
 /*   100 */   312,  260,  312,  250,  312,  312,  312,  312,  312,  312,
 /*   110 */   312,  312,  312,  312,  312,  312,  257,  312,  253,  244,
 /*   120 */   219,  312,  228,  312,  312,  213,  214,  225,  224,  206,
 /*   130 */   238,  237,  307,  306,  305,  270,  267,  266,  299,  221,
 /*   140 */   217,  311,  304,  303,  302,  301,  300,  295,  310,  309,
 /*   150 */   308,  294,  284,  283,  282,  278,  286,  281,  280,  285,
 /*   160 */   277,  276,  272,  287,  274,  273,  297,  296,  261,  256,
 /*   170 */   259,  258,  255,  254,  247,  246,  245,  244,  243,  242,
 /*   180 */   241,  240,  239,  227,  220,  231,  233,  230,  218,  229,
 /*   190 */   236,  235,  234,  226,  223,  222,  216,  215,  211,  210,
 /*   200 */   209,  208,  207,  205,
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
  "DCOLON",        "NL",            "SEMI",          "EOF",         
  "COMMA",         "CLASS",         "END",           "ID",          
  "LT",            "DEF",           "LP",            "RP",          
  "NUM",           "NIL",           "TRUE",          "FALSE",       
  "SELF",          "IVAR",          "LITSTR",        "DOLLAR",      
  "EQUAL",         "TUPLE_START",   "DICT_START",    "RB",          
  "LB",            "PIPE",          "IF",            "UNLESS",      
  "WHILE",         "IMPORT",        "TRY",           "RESCUE",      
  "OP1_SET",       "OP0_SET",       "RAISE",         "error",       
  "program",       "opt_fin",       "l1",            "last_fin",    
  "fin",           "l1e",           "class",         "def",         
  "stmt",          "fin_m",         "comma",         "seq",         
  "class_start",   "class_body",    "s2",            "def_start",   
  "def_body",      "arg",           "id_list",       "def_args",    
  "def_name",      "lit",           "np_arg",        "np_arg_list", 
  "lambda",        "np_arg_list_start",  "np_arg_list_elems",  "np_kw_arg",   
  "np_kw_arg_list_elems",  "np_opt_kw_arg_list",  "np_recv",       "lambda_start",
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
 /*  25 */ "arg ::= ID CAST ID",
 /*  26 */ "id_list ::= id_list comma arg",
 /*  27 */ "id_list ::= arg",
 /*  28 */ "def_args ::=",
 /*  29 */ "def_args ::= LP id_list RP",
 /*  30 */ "def_name ::= ID",
 /*  31 */ "def_name ::= OP0",
 /*  32 */ "def_name ::= OP1",
 /*  33 */ "def ::= def_start def_name def_args fin def_body",
 /*  34 */ "def ::= def_start def_name def_args fin END",
 /*  35 */ "lit ::= NUM",
 /*  36 */ "lit ::= NIL",
 /*  37 */ "lit ::= TRUE",
 /*  38 */ "lit ::= FALSE",
 /*  39 */ "lit ::= SELF",
 /*  40 */ "lit ::= ID",
 /*  41 */ "lit ::= IVAR",
 /*  42 */ "lit ::= LITSTR",
 /*  43 */ "np_arg ::= lit",
 /*  44 */ "np_arg ::= np_arg OP0 np_arg",
 /*  45 */ "np_arg ::= np_arg OP1 np_arg",
 /*  46 */ "np_arg ::= np_arg OP2 np_arg",
 /*  47 */ "np_arg ::= np_arg CAST np_arg",
 /*  48 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  49 */ "np_arg ::= np_arg DOT ID",
 /*  50 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  51 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  52 */ "np_arg ::= np_arg DCOLON ID",
 /*  53 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  54 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  55 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  56 */ "np_arg ::= NOT np_arg",
 /*  57 */ "np_arg ::= lambda",
 /*  58 */ "np_arg_list_start ::=",
 /*  59 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  60 */ "np_arg_list_elems ::= np_arg",
 /*  61 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  62 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  63 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  64 */ "np_opt_kw_arg_list ::=",
 /*  65 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  66 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  67 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  68 */ "np_recv ::= lit",
 /*  69 */ "np_recv ::= ID LP RP",
 /*  70 */ "np_recv ::= ID LP np_arg_list RP",
 /*  71 */ "np_recv ::= np_recv DOT ID",
 /*  72 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  73 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  74 */ "np_recv ::= np_recv DCOLON ID",
 /*  75 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  76 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  77 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  78 */ "np_recv ::= lambda",
 /*  79 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  80 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  81 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  82 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  83 */ "s2 ::= ID np_arg_list",
 /*  84 */ "s2 ::= np_recv CAST np_arg",
 /*  85 */ "s2 ::= np_recv OP0 np_arg",
 /*  86 */ "s2 ::= np_recv OP1 np_arg",
 /*  87 */ "s2 ::= np_recv OP2 np_arg",
 /*  88 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  89 */ "s2 ::= np_recv",
 /*  90 */ "s2 ::= NOT s2",
 /*  91 */ "stmt ::= s2",
 /*  92 */ "lambda_start ::= LB",
 /*  93 */ "lambda_args ::= PIPE ID PIPE",
 /*  94 */ "lambda_args ::=",
 /*  95 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  96 */ "stmt ::= IF s2 fin seq fin END",
 /*  97 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  98 */ "stmt ::= WHILE s2 fin seq fin END",
 /*  99 */ "stmt ::= IMPORT ID",
 /* 100 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 101 */ "stmt ::= ID EQUAL s2",
 /* 102 */ "stmt ::= ID OP1_SET s2",
 /* 103 */ "stmt ::= ID OP0_SET s2",
 /* 104 */ "stmt ::= IVAR EQUAL s2",
 /* 105 */ "stmt ::= IVAR OP1_SET s2",
 /* 106 */ "stmt ::= IVAR OP0_SET s2",
 /* 107 */ "stmt ::= RAISE s2",
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
  { 44, 3 },
  { 46, 3 },
  { 46, 1 },
  { 49, 1 },
  { 49, 1 },
  { 49, 1 },
  { 53, 1 },
  { 53, 1 },
  { 45, 0 },
  { 45, 2 },
  { 47, 1 },
  { 47, 2 },
  { 48, 2 },
  { 48, 1 },
  { 54, 2 },
  { 54, 1 },
  { 55, 3 },
  { 55, 1 },
  { 56, 1 },
  { 57, 3 },
  { 50, 4 },
  { 50, 6 },
  { 59, 1 },
  { 60, 3 },
  { 61, 1 },
  { 61, 3 },
  { 62, 3 },
  { 62, 1 },
  { 63, 0 },
  { 63, 3 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 51, 5 },
  { 51, 5 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 65, 1 },
  { 66, 1 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 3 },
  { 66, 5 },
  { 66, 6 },
  { 66, 3 },
  { 66, 4 },
  { 66, 6 },
  { 66, 7 },
  { 66, 2 },
  { 66, 1 },
  { 69, 0 },
  { 70, 3 },
  { 70, 1 },
  { 71, 3 },
  { 72, 3 },
  { 72, 1 },
  { 73, 0 },
  { 73, 2 },
  { 67, 3 },
  { 67, 2 },
  { 74, 1 },
  { 74, 3 },
  { 74, 4 },
  { 74, 3 },
  { 74, 5 },
  { 74, 6 },
  { 74, 3 },
  { 74, 4 },
  { 74, 6 },
  { 74, 7 },
  { 74, 1 },
  { 74, 3 },
  { 74, 3 },
  { 58, 4 },
  { 58, 5 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 1 },
  { 58, 2 },
  { 52, 1 },
  { 75, 1 },
  { 76, 3 },
  { 76, 0 },
  { 68, 4 },
  { 52, 6 },
  { 52, 6 },
  { 52, 6 },
  { 52, 2 },
  { 52, 9 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 2 },
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
#line 30 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy32.a)); }
#line 1095 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy32.a = S->seq(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1101 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 43: /* np_arg ::= lit */ yytestcase(yyruleno==43);
      case 57: /* np_arg ::= lambda */ yytestcase(yyruleno==57);
      case 68: /* np_recv ::= lit */ yytestcase(yyruleno==68);
      case 78: /* np_recv ::= lambda */ yytestcase(yyruleno==78);
      case 89: /* s2 ::= np_recv */ yytestcase(yyruleno==89);
      case 91: /* stmt ::= s2 */ yytestcase(yyruleno==91);
#line 33 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[0].minor.yy32.a; }
#line 1116 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1121 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[-2].minor.yy32.a; }
#line 1127 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy32.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy32.a);
             }
#line 1134 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy32.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a);
             }
#line 1141 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1146 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 71 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1151 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST ID */
#line 72 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, S->named(yymsp[0].minor.yy0.s)); }
#line 1156 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
#line 80 "vm/parser.lm"
{ yygotominor.yy32.s = yymsp[0].minor.yy0.s; }
#line 1163 "vm/parser.c.inc"
        break;
      case 33: /* def ::= def_start def_name def_args fin def_body */
#line 85 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(yymsp[-3].minor.yy32.s, yymsp[0].minor.yy32.a);
            }
#line 1170 "vm/parser.c.inc"
        break;
      case 34: /* def ::= def_start def_name def_args fin END */
#line 88 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(yymsp[-3].minor.yy32.s, S->ast_nil());
            }
#line 1177 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= NUM */
#line 92 "vm/parser.lm"
{ yygotominor.yy32.a = S->number(yymsp[0].minor.yy0.i); }
#line 1182 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= NIL */
#line 93 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_nil();  }
#line 1187 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= TRUE */
#line 94 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_true();  }
#line 1192 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= FALSE */
#line 95 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_false(); }
#line 1197 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= SELF */
#line 96 "vm/parser.lm"
{ yygotominor.yy32.a = S->self(); }
#line 1202 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= ID */
#line 97 "vm/parser.lm"
{ yygotominor.yy32.a = S->named(yymsp[0].minor.yy0.s); }
#line 1207 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= IVAR */
#line 98 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1212 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= LITSTR */
#line 99 "vm/parser.lm"
{ yygotominor.yy32.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1217 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg OP0 np_arg */
      case 45: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==45);
      case 85: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==85);
      case 86: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==86);
#line 103 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1225 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg OP2 np_arg */
      case 87: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==87);
#line 107 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1231 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg CAST np_arg */
      case 84: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==84);
#line 109 "vm/parser.lm"
{ yygotominor.yy32.a = S->cast(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1237 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg NEQUAL np_arg */
      case 88: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==88);
#line 111 "vm/parser.lm"
{ yygotominor.yy32.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a)); }
#line 1243 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT ID */
      case 71: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==71);
#line 112 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy0.s); }
#line 1249 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DOT ID LP RP */
      case 72: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==72);
#line 113 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy0.s); }
#line 1255 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 73: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==73);
#line 115 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-5].minor.yy32.a, yymsp[-3].minor.yy0.s); }
#line 1261 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DCOLON ID */
      case 74: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==74);
#line 116 "vm/parser.lm"
{ yygotominor.yy32.a = S->dcolon(yymsp[-2].minor.yy32.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1267 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 75: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==75);
#line 118 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect(yymsp[-3].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1273 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 76: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==76);
#line 120 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect(yymsp[-5].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1279 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 77: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==77);
#line 122 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect_args(yymsp[-6].minor.yy32.a, yymsp[-3].minor.yy32.a); }
#line 1285 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= NOT np_arg */
      case 90: /* s2 ::= NOT s2 */ yytestcase(yyruleno==90);
#line 123 "vm/parser.lm"
{ yygotominor.yy32.a = S->not_(yymsp[0].minor.yy32.a); }
#line 1291 "vm/parser.c.inc"
        break;
      case 58: /* np_arg_list_start ::= */
#line 126 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1296 "vm/parser.c.inc"
        break;
      case 59: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 60: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==60);
#line 127 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy32.a); }
#line 1302 "vm/parser.c.inc"
        break;
      case 61: /* np_kw_arg ::= ID EQUAL np_arg */
#line 130 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1307 "vm/parser.c.inc"
        break;
      case 69: /* np_recv ::= ID LP RP */
#line 142 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1312 "vm/parser.c.inc"
        break;
      case 70: /* np_recv ::= ID LP np_arg_list RP */
#line 143 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1317 "vm/parser.c.inc"
        break;
      case 79: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 155 "vm/parser.lm"
{ yygotominor.yy32.a = S->tuple(); }
#line 1322 "vm/parser.c.inc"
        break;
      case 80: /* np_recv ::= DICT_START np_arg_list RB */
#line 156 "vm/parser.lm"
{ yygotominor.yy32.a = S->dict(); }
#line 1327 "vm/parser.c.inc"
        break;
      case 81: /* s2 ::= np_recv DOT ID np_arg_list */
#line 158 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-3].minor.yy32.a, yymsp[-1].minor.yy0.s); }
#line 1332 "vm/parser.c.inc"
        break;
      case 82: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 160 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect_args(yymsp[-4].minor.yy32.a, yymsp[-1].minor.yy32.a); }
#line 1337 "vm/parser.c.inc"
        break;
      case 83: /* s2 ::= ID np_arg_list */
#line 161 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1342 "vm/parser.c.inc"
        break;
      case 92: /* lambda_start ::= LB */
#line 175 "vm/parser.lm"
{ S->start_lambda(); }
#line 1347 "vm/parser.c.inc"
        break;
      case 93: /* lambda_args ::= PIPE ID PIPE */
#line 177 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1352 "vm/parser.c.inc"
        break;
      case 95: /* lambda ::= lambda_start lambda_args seq RB */
#line 180 "vm/parser.lm"
{ yygotominor.yy32.a = S->lambda(yymsp[-1].minor.yy32.a); }
#line 1357 "vm/parser.c.inc"
        break;
      case 96: /* stmt ::= IF s2 fin seq fin END */
#line 184 "vm/parser.lm"
{ yygotominor.yy32.a = S->if_cond(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1362 "vm/parser.c.inc"
        break;
      case 97: /* stmt ::= UNLESS s2 fin seq fin END */
#line 185 "vm/parser.lm"
{ yygotominor.yy32.a = S->unless(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1367 "vm/parser.c.inc"
        break;
      case 98: /* stmt ::= WHILE s2 fin seq fin END */
#line 186 "vm/parser.lm"
{ yygotominor.yy32.a = S->while_(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1372 "vm/parser.c.inc"
        break;
      case 99: /* stmt ::= IMPORT ID */
#line 190 "vm/parser.lm"
{ yygotominor.yy32.a = S->import(yymsp[0].minor.yy0.s); }
#line 1377 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 192 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_try(yymsp[-6].minor.yy32.a, yymsp[-2].minor.yy32.a);
            }
#line 1384 "vm/parser.c.inc"
        break;
      case 101: /* stmt ::= ID EQUAL s2 */
#line 196 "vm/parser.lm"
{ yygotominor.yy32.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1389 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= ID OP1_SET s2 */
      case 103: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==103);
#line 197 "vm/parser.lm"
{ yygotominor.yy32.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1395 "vm/parser.c.inc"
        break;
      case 104: /* stmt ::= IVAR EQUAL s2 */
#line 199 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1400 "vm/parser.c.inc"
        break;
      case 105: /* stmt ::= IVAR OP1_SET s2 */
      case 106: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==106);
#line 201 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1406 "vm/parser.c.inc"
        break;
      case 107: /* stmt ::= RAISE s2 */
#line 204 "vm/parser.lm"
{ yygotominor.yy32.a = S->raise(yymsp[0].minor.yy32.a); }
#line 1411 "vm/parser.c.inc"
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
      /* (62) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==62);
      /* (63) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==63);
      /* (64) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==64);
      /* (65) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==65);
      /* (66) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==66);
      /* (67) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==67);
      /* (94) lambda_args ::= */ yytestcase(yyruleno==94);
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
#line 23 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1500 "vm/parser.c.inc"
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
