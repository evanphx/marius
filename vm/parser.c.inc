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
#define YYNOCODE 77
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
#define YYNSTATE 201
#define YYNRULE 106
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
#define YY_ACTTAB_COUNT (915)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    32,  196,  195,  196,  195,  194,  201,  192,   22,   47,
 /*    10 */    42,  190,  101,  113,  180,  179,  178,  177,  176,   97,
 /*    20 */   173,   33,    4,   74,   73,  117,  165,  138,   29,   28,
 /*    30 */    27,  104,   57,   31,   30,   32,   26,   76,  196,  195,
 /*    40 */   196,  195,  192,  191,   47,   49,  190,  101,  113,  180,
 /*    50 */   179,  178,  177,  176,   97,  173,   52,   75,   74,   73,
 /*    60 */   186,  165,  136,   29,   28,   27,  104,   57,  120,  188,
 /*    70 */    32,   26,  187,  196,  195,  184,  185,  192,  106,   47,
 /*    80 */    20,  190,   45,  189,  180,  179,  178,  177,  176,   97,
 /*    90 */   173,  122,    5,   74,   73,   72,  165,  138,   29,   28,
 /*   100 */    27,  104,   57,  196,  195,   32,   26,  170,  196,  195,
 /*   110 */   196,  195,  124,  181,   47,  105,  116,   20,   20,  180,
 /*   120 */   179,  178,  177,  176,   97,  173,  308,    3,   74,   73,
 /*   130 */    71,  165,  167,   29,   28,   27,  104,   57,  168,  111,
 /*   140 */    32,   26,  164,  196,  195,  114,  162,   20,  144,   47,
 /*   150 */   110,  109,   20,   20,  180,  179,  178,  177,  176,   97,
 /*   160 */   173,  158,  155,   74,   73,  153,  165,   21,   29,   28,
 /*   170 */    27,  104,   57,  151,  141,   32,   26,  150,  196,  195,
 /*   180 */   108,   83,   20,  143,   47,  133,  161,   65,   20,  180,
 /*   190 */   179,  178,  177,  176,   97,  173,   78,    6,   74,   73,
 /*   200 */   183,  165,  138,   29,   28,   27,  104,   57,   19,  112,
 /*   210 */    32,   26,   17,  196,  195,   11,   16,  138,  142,   47,
 /*   220 */   138,  138,  120,  135,  180,  179,  178,  177,  176,   97,
 /*   230 */   173,   80,   10,   74,   73,  103,  165,  138,   29,   28,
 /*   240 */    27,  104,   57,  119,   84,   32,   26,   15,  196,  195,
 /*   250 */     9,   14,  138,    8,   47,  138,  138,  115,  138,  180,
 /*   260 */   179,  178,  177,  176,   97,  173,  171,   13,   74,   73,
 /*   270 */    48,  165,  138,   29,   28,   27,  104,   57,   55,  309,
 /*   280 */    32,   26,    7,  196,  195,   12,    1,  138,  140,   47,
 /*   290 */   138,  138,  169,  309,  180,  179,  178,  177,  176,   97,
 /*   300 */   173,  163,    2,   74,   73,  159,  165,  138,   29,   28,
 /*   310 */    27,  104,   57,  309,  156,   32,   26,   18,  196,  195,
 /*   320 */   309,  309,  138,  128,   47,  157,  154,   20,   20,  180,
 /*   330 */   179,  178,  177,  176,   97,  173,  309,  309,   74,   73,
 /*   340 */   309,  165,  309,   29,   28,   27,  104,   57,  309,  309,
 /*   350 */    32,   26,  309,  196,  195,  309,  309,  309,  309,   47,
 /*   360 */   309,  309,  309,  309,  180,  179,  178,  177,  176,   97,
 /*   370 */   173,  309,  309,   74,   73,   32,  165,  309,   29,   28,
 /*   380 */    27,  104,   57,  309,   47,  309,   26,  309,  309,  180,
 /*   390 */   179,  178,  177,  176,   97,  173,  309,  309,   74,   73,
 /*   400 */   257,  165,  309,   29,   28,   27,  104,   57,  309,  257,
 /*   410 */   309,   26,   70,  309,  257,  257,  257,  257,  257,  257,
 /*   420 */   257,  309,   25,  309,   43,   42,  257,  101,  113,  309,
 /*   430 */   309,  309,  309,   66,   24,   23,  127,  199,  198,  197,
 /*   440 */   193,  309,  309,  121,  126,  145,   77,  309,  309,  309,
 /*   450 */   309,  160,   66,  309,  152,  127,  199,  198,  197,  193,
 /*   460 */    92,   82,  121,  125,  145,   77,  309,  309,  172,   85,
 /*   470 */   160,  166,  309,  152,  134,   81,  309,  309,   82,   92,
 /*   480 */    82,   46,  309,  309,  127,  199,  198,  197,  123,  137,
 /*   490 */   193,  121,   64,  145,   77,  145,  309,  129,   32,  160,
 /*   500 */   309,  160,  152,  309,  152,  309,  309,   50,   92,   82,
 /*   510 */    92,   82,  180,  179,  178,  177,  176,  174,  173,  148,
 /*   520 */   309,   74,   73,  309,  165,  160,  309,  309,  152,  200,
 /*   530 */   199,  198,  197,  193,   92,   82,  121,  309,  145,   77,
 /*   540 */   309,  309,  309,  257,  160,  309,  309,  152,  309,  309,
 /*   550 */   309,  309,  257,   92,   82,   70,  309,  257,  257,  257,
 /*   560 */   257,  257,  257,  257,  257,  309,  309,  172,   93,  257,
 /*   570 */   166,  309,  309,  257,  309,  309,   69,   82,  257,  257,
 /*   580 */   257,  257,  257,  257,  257,  257,  172,   86,  309,  166,
 /*   590 */   257,   67,  134,   79,  257,  309,   82,   68,  309,  257,
 /*   600 */   257,  257,  257,  257,  257,  257,   39,  309,  309,  172,
 /*   610 */    96,  257,  166,  309,  309,  175,  309,  309,  309,   82,
 /*   620 */   180,  179,  178,  177,  176,  174,  173,   39,  172,   98,
 /*   630 */   309,  166,  165,  309,  309,  309,  118,  309,   82,  309,
 /*   640 */   309,  180,  179,  178,  177,  176,  174,  173,  309,  309,
 /*   650 */   309,  309,  175,  165,  309,  309,  309,  180,  179,  178,
 /*   660 */   177,  176,  174,  173,  137,  193,  309,   62,  137,  193,
 /*   670 */   145,   60,  309,  309,  145,  309,  160,  309,  309,  152,
 /*   680 */   160,  309,  309,  152,  309,   92,   82,  309,  309,   92,
 /*   690 */    82,  309,  309,  309,  137,  193,  309,   58,  137,  193,
 /*   700 */   145,   56,  309,  309,  145,  309,  160,  309,  309,  152,
 /*   710 */   160,  137,  193,  152,   54,   92,   82,  145,  309,   92,
 /*   720 */    82,  309,  309,  160,  309,  309,  152,  309,  309,  309,
 /*   730 */   309,  309,   92,   82,   44,   41,   40,   43,   42,  309,
 /*   740 */   101,  113,   37,   38,   34,   36,   35,  137,   99,  107,
 /*   750 */    51,  182,  193,  145,  309,  309,  309,  145,  309,  160,
 /*   760 */   309,  309,  152,  160,  309,  149,  152,  309,   92,   82,
 /*   770 */   147,  160,   92,   82,  152,  309,  160,  309,  146,  152,
 /*   780 */    92,   82,   63,  309,  160,   92,   82,  152,  160,  309,
 /*   790 */   309,  152,  309,   92,   82,   61,  309,   92,   82,  309,
 /*   800 */    59,  160,  309,  309,  152,  309,  160,  309,  139,  152,
 /*   810 */    92,   82,  132,  309,  160,   92,   82,  152,  160,  309,
 /*   820 */   309,  152,  309,   92,   82,  131,  309,   92,   82,  130,
 /*   830 */   309,  160,  309,   53,  152,  160,  309,  309,  152,  160,
 /*   840 */    92,   82,  152,  309,   92,   82,  309,  309,   92,   82,
 /*   850 */   172,  102,  309,  166,  309,  309,  172,   95,  309,  166,
 /*   860 */    82,  309,  172,   94,  309,  166,   82,  309,  309,  309,
 /*   870 */   309,  309,   82,  172,  100,  309,  166,  172,   91,  309,
 /*   880 */   166,  172,   90,   82,  166,  309,  309,   82,  309,  172,
 /*   890 */    89,   82,  166,  172,   88,  309,  166,  309,  309,   82,
 /*   900 */   309,  309,  309,   82,  172,   87,  309,  166,  309,  309,
 /*   910 */   309,  309,  309,  309,   82,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    9,   10,    9,   10,   11,    0,   13,   16,   15,
 /*    10 */     5,   17,    7,    8,   20,   21,   22,   23,   24,   25,
 /*    20 */    26,   28,   48,   29,   30,   15,   32,   53,   34,   35,
 /*    30 */    36,   37,   38,   40,   41,    6,   42,   27,    9,   10,
 /*    40 */     9,   10,   13,   14,   15,   15,   17,    7,    8,   20,
 /*    50 */    21,   22,   23,   24,   25,   26,   15,   27,   29,   30,
 /*    60 */     9,   32,   31,   34,   35,   36,   37,   38,   12,    1,
 /*    70 */     6,   42,    4,    9,   10,   19,   15,   13,   66,   15,
 /*    80 */    68,   17,   28,   15,   20,   21,   22,   23,   24,   25,
 /*    90 */    26,   47,   48,   29,   30,   18,   32,   53,   34,   35,
 /*   100 */    36,   37,   38,    9,   10,    6,   42,   19,    9,   10,
 /*   110 */     9,   10,   11,   14,   15,   66,   66,   68,   68,   20,
 /*   120 */    21,   22,   23,   24,   25,   26,   44,   45,   29,   30,
 /*   130 */    18,   32,   15,   34,   35,   36,   37,   38,   19,   15,
 /*   140 */     6,   42,   33,    9,   10,   66,   19,   68,   14,   15,
 /*   150 */    66,   66,   68,   68,   20,   21,   22,   23,   24,   25,
 /*   160 */    26,   19,   19,   29,   30,   15,   32,   54,   34,   35,
 /*   170 */    36,   37,   38,   19,   15,    6,   42,   31,    9,   10,
 /*   180 */    66,   18,   68,   14,   15,   72,   66,   62,   68,   20,
 /*   190 */    21,   22,   23,   24,   25,   26,   61,   48,   29,   30,
 /*   200 */    15,   32,   53,   34,   35,   36,   37,   38,   75,   33,
 /*   210 */     6,   42,   48,    9,   10,   48,   48,   53,   14,   15,
 /*   220 */    53,   53,   12,   70,   20,   21,   22,   23,   24,   25,
 /*   230 */    26,   54,   48,   29,   30,   15,   32,   53,   34,   35,
 /*   240 */    36,   37,   38,   54,   63,    6,   42,   48,    9,   10,
 /*   250 */    48,   48,   53,   48,   15,   53,   53,   64,   53,   20,
 /*   260 */    21,   22,   23,   24,   25,   26,   19,   48,   29,   30,
 /*   270 */    64,   32,   53,   34,   35,   36,   37,   38,   39,   76,
 /*   280 */     6,   42,   48,    9,   10,   48,   48,   53,   14,   15,
 /*   290 */    53,   53,   19,   76,   20,   21,   22,   23,   24,   25,
 /*   300 */    26,   19,   48,   29,   30,   19,   32,   53,   34,   35,
 /*   310 */    36,   37,   38,   76,   19,    6,   42,   48,    9,   10,
 /*   320 */    76,   76,   53,   14,   15,   66,   66,   68,   68,   20,
 /*   330 */    21,   22,   23,   24,   25,   26,   76,   76,   29,   30,
 /*   340 */    76,   32,   76,   34,   35,   36,   37,   38,   76,   76,
 /*   350 */     6,   42,   76,    9,   10,   76,   76,   76,   76,   15,
 /*   360 */    76,   76,   76,   76,   20,   21,   22,   23,   24,   25,
 /*   370 */    26,   76,   76,   29,   30,    6,   32,   76,   34,   35,
 /*   380 */    36,   37,   38,   76,   15,   76,   42,   76,   76,   20,
 /*   390 */    21,   22,   23,   24,   25,   26,   76,   76,   29,   30,
 /*   400 */     6,   32,   76,   34,   35,   36,   37,   38,   76,   15,
 /*   410 */    76,   42,   18,   76,   20,   21,   22,   23,   24,   25,
 /*   420 */    26,   76,   28,   76,    4,    5,   32,    7,    8,   76,
 /*   430 */    76,   76,   76,   46,   40,   41,   49,   50,   51,   52,
 /*   440 */    53,   76,   76,   56,   57,   58,   59,   76,   76,   76,
 /*   450 */    76,   64,   46,   76,   67,   49,   50,   51,   52,   53,
 /*   460 */    73,   74,   56,   57,   58,   59,   76,   76,   64,   65,
 /*   470 */    64,   67,   76,   67,   70,   71,   76,   76,   74,   73,
 /*   480 */    74,   46,   76,   76,   49,   50,   51,   52,   53,   52,
 /*   490 */    53,   56,   55,   58,   59,   58,   76,   60,    6,   64,
 /*   500 */    76,   64,   67,   76,   67,   76,   76,   15,   73,   74,
 /*   510 */    73,   74,   20,   21,   22,   23,   24,   25,   26,   58,
 /*   520 */    76,   29,   30,   76,   32,   64,   76,   76,   67,   49,
 /*   530 */    50,   51,   52,   53,   73,   74,   56,   76,   58,   59,
 /*   540 */    76,   76,   76,    6,   64,   76,   76,   67,   76,   76,
 /*   550 */    76,   76,   15,   73,   74,   18,   76,   20,   21,   22,
 /*   560 */    23,   24,   25,   26,    6,   76,   76,   64,   65,   32,
 /*   570 */    67,   76,   76,   15,   76,   76,   18,   74,   20,   21,
 /*   580 */    22,   23,   24,   25,   26,    6,   64,   65,   76,   67,
 /*   590 */    32,   69,   70,   71,   15,   76,   74,   18,   76,   20,
 /*   600 */    21,   22,   23,   24,   25,   26,    6,   76,   76,   64,
 /*   610 */    65,   32,   67,   76,   76,   15,   76,   76,   76,   74,
 /*   620 */    20,   21,   22,   23,   24,   25,   26,    6,   64,   65,
 /*   630 */    76,   67,   32,   76,   76,   76,   15,   76,   74,   76,
 /*   640 */    76,   20,   21,   22,   23,   24,   25,   26,   76,   76,
 /*   650 */    76,   76,   15,   32,   76,   76,   76,   20,   21,   22,
 /*   660 */    23,   24,   25,   26,   52,   53,   76,   55,   52,   53,
 /*   670 */    58,   55,   76,   76,   58,   76,   64,   76,   76,   67,
 /*   680 */    64,   76,   76,   67,   76,   73,   74,   76,   76,   73,
 /*   690 */    74,   76,   76,   76,   52,   53,   76,   55,   52,   53,
 /*   700 */    58,   55,   76,   76,   58,   76,   64,   76,   76,   67,
 /*   710 */    64,   52,   53,   67,   55,   73,   74,   58,   76,   73,
 /*   720 */    74,   76,   76,   64,   76,   76,   67,   76,   76,   76,
 /*   730 */    76,   76,   73,   74,    1,    2,    3,    4,    5,   76,
 /*   740 */     7,    8,    1,    2,    3,    4,    5,   52,    7,    8,
 /*   750 */    55,   52,   53,   58,   76,   76,   76,   58,   76,   64,
 /*   760 */    76,   76,   67,   64,   76,   58,   67,   76,   73,   74,
 /*   770 */    58,   64,   73,   74,   67,   76,   64,   76,   58,   67,
 /*   780 */    73,   74,   58,   76,   64,   73,   74,   67,   64,   76,
 /*   790 */    76,   67,   76,   73,   74,   58,   76,   73,   74,   76,
 /*   800 */    58,   64,   76,   76,   67,   76,   64,   76,   58,   67,
 /*   810 */    73,   74,   58,   76,   64,   73,   74,   67,   64,   76,
 /*   820 */    76,   67,   76,   73,   74,   58,   76,   73,   74,   58,
 /*   830 */    76,   64,   76,   58,   67,   64,   76,   76,   67,   64,
 /*   840 */    73,   74,   67,   76,   73,   74,   76,   76,   73,   74,
 /*   850 */    64,   65,   76,   67,   76,   76,   64,   65,   76,   67,
 /*   860 */    74,   76,   64,   65,   76,   67,   74,   76,   76,   76,
 /*   870 */    76,   76,   74,   64,   65,   76,   67,   64,   65,   76,
 /*   880 */    67,   64,   65,   74,   67,   76,   76,   74,   76,   64,
 /*   890 */    65,   74,   67,   64,   65,   76,   67,   76,   76,   74,
 /*   900 */    76,   76,   76,   74,   64,   65,   76,   67,   76,   76,
 /*   910 */    76,   76,   76,   76,   74,
};
#define YY_SHIFT_USE_DFLT (-9)
#define YY_SHIFT_COUNT (122)
#define YY_SHIFT_MIN   (-8)
#define YY_SHIFT_MAX   (741)
static const short yy_shift_ofst[] = {
 /*     0 */    -9,   64,   64,   64,   29,   -6,  309,  344,  344,  344,
 /*    10 */   344,  344,  274,  239,  204,  169,  134,   99,  344,  369,
 /*    20 */   621,  621,  492,  492,  492,  492,  492,  492,  492,  492,
 /*    30 */   492,  492,  492,  492,  600,  600,  600,  600,  600,  600,
 /*    40 */   600,  600,  600,  600,  600,  600,  101,  394,  579,  558,
 /*    50 */   537,   31,   -8,   94,   94,   94,   94,   94,   94,   94,
 /*    60 */    94,   94,   94,   94,   94,   94,   94,  210,  295,  286,
 /*    70 */   282,  273,  247,   -9,   -9,  637,  637,   68,   56,  210,
 /*    80 */   220,  210,  176,  185,  163,  733,  733,  733,  733,  733,
 /*    90 */   733,  733,  741,  733,  420,  420,  420,   -7,    5,   30,
 /*   100 */    40,   10,   40,   54,  159,  146,  154,  150,  143,  142,
 /*   110 */   127,  109,  124,  117,  119,  112,   88,   77,   54,   61,
 /*   120 */    51,   41,    6,
};
#define YY_REDUCE_USE_DFLT (-27)
#define YY_REDUCE_COUNT (84)
#define YY_REDUCE_MIN   (-26)
#define YY_REDUCE_MAX   (840)
static const short yy_reduce_ofst[] = {
 /*     0 */    82,  406,  387,  435,  480,  480,  437,  659,  646,  642,
 /*    10 */   616,  612,  699,  699,  699,  699,  699,  699,  699,  695,
 /*    20 */   522,  404,  775,  771,  767,  754,  750,  742,  737,  724,
 /*    30 */   720,  712,  707,  461,  840,  829,  825,  817,  813,  809,
 /*    40 */   798,  792,  786,  564,  545,  503,   44,  120,  260,  259,
 /*    50 */   120,  269,  254,  238,  237,  234,  219,  205,  203,  202,
 /*    60 */   199,  184,  168,  167,  164,  149,  -26,  113,  114,   85,
 /*    70 */    84,   79,   50,   49,   12,  206,  193,  181,  189,  177,
 /*    80 */   153,  177,  133,  135,  125,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   209,  307,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    10 */   307,  307,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    20 */   307,  307,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    30 */   307,  307,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    40 */   307,  307,  307,  307,  307,  307,  307,  239,  274,  270,
 /*    50 */   239,  307,  307,  307,  307,  307,  307,  307,  307,  307,
 /*    60 */   307,  307,  307,  307,  307,  307,  307,  263,  257,  257,
 /*    70 */   257,  257,  257,  257,  257,  307,  307,  307,  307,  266,
 /*    80 */   307,  264,  293,  307,  227,  258,  259,  287,  286,  285,
 /*    90 */   284,  283,  288,  260,  247,  246,  243,  240,  244,  307,
 /*   100 */   255,  307,  245,  307,  307,  307,  307,  307,  307,  307,
 /*   110 */   307,  307,  307,  307,  307,  252,  307,  248,  239,  307,
 /*   120 */   216,  307,  307,  210,  211,  222,  221,  203,  233,  232,
 /*   130 */   302,  301,  300,  265,  262,  261,  294,  218,  214,  306,
 /*   140 */   299,  298,  297,  296,  295,  290,  305,  304,  303,  289,
 /*   150 */   279,  278,  277,  273,  281,  276,  275,  280,  272,  271,
 /*   160 */   267,  282,  269,  268,  292,  291,  256,  251,  254,  253,
 /*   170 */   250,  249,  242,  241,  240,  239,  238,  237,  236,  235,
 /*   180 */   234,  224,  217,  226,  228,  225,  215,  231,  230,  229,
 /*   190 */   223,  220,  219,  213,  212,  208,  207,  206,  205,  204,
 /*   200 */   202,
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
  "def_body",      "id_list",       "def_args",      "def_name",    
  "lit",           "np_arg",        "np_arg_list",   "lambda",      
  "np_arg_list_start",  "np_arg_list_elems",  "np_kw_arg",     "np_kw_arg_list_elems",
  "np_opt_kw_arg_list",  "np_recv",       "lambda_start",  "lambda_args", 
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
 /*  24 */ "id_list ::= id_list comma ID",
 /*  25 */ "id_list ::= ID",
 /*  26 */ "def_args ::=",
 /*  27 */ "def_args ::= LP id_list RP",
 /*  28 */ "def_name ::= ID",
 /*  29 */ "def_name ::= OP0",
 /*  30 */ "def_name ::= OP1",
 /*  31 */ "def ::= def_start def_name def_args fin def_body",
 /*  32 */ "def ::= def_start def_name def_args fin END",
 /*  33 */ "lit ::= NUM",
 /*  34 */ "lit ::= NIL",
 /*  35 */ "lit ::= TRUE",
 /*  36 */ "lit ::= FALSE",
 /*  37 */ "lit ::= SELF",
 /*  38 */ "lit ::= ID",
 /*  39 */ "lit ::= IVAR",
 /*  40 */ "lit ::= LITSTR",
 /*  41 */ "np_arg ::= lit",
 /*  42 */ "np_arg ::= np_arg OP0 np_arg",
 /*  43 */ "np_arg ::= np_arg OP1 np_arg",
 /*  44 */ "np_arg ::= np_arg OP2 np_arg",
 /*  45 */ "np_arg ::= np_arg CAST np_arg",
 /*  46 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  47 */ "np_arg ::= np_arg DOT ID",
 /*  48 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  49 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  50 */ "np_arg ::= np_arg DCOLON ID",
 /*  51 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  52 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  53 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  54 */ "np_arg ::= NOT np_arg",
 /*  55 */ "np_arg ::= lambda",
 /*  56 */ "np_arg_list_start ::=",
 /*  57 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  58 */ "np_arg_list_elems ::= np_arg",
 /*  59 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  60 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  61 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  62 */ "np_opt_kw_arg_list ::=",
 /*  63 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  64 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  65 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  66 */ "np_recv ::= lit",
 /*  67 */ "np_recv ::= ID LP RP",
 /*  68 */ "np_recv ::= ID LP np_arg_list RP",
 /*  69 */ "np_recv ::= np_recv DOT ID",
 /*  70 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  71 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  72 */ "np_recv ::= np_recv DCOLON ID",
 /*  73 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  74 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  75 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  76 */ "np_recv ::= lambda",
 /*  77 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  78 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  79 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  80 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  81 */ "s2 ::= ID np_arg_list",
 /*  82 */ "s2 ::= np_recv CAST np_arg",
 /*  83 */ "s2 ::= np_recv OP0 np_arg",
 /*  84 */ "s2 ::= np_recv OP1 np_arg",
 /*  85 */ "s2 ::= np_recv OP2 np_arg",
 /*  86 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  87 */ "s2 ::= np_recv",
 /*  88 */ "s2 ::= NOT s2",
 /*  89 */ "stmt ::= s2",
 /*  90 */ "lambda_start ::= LB",
 /*  91 */ "lambda_args ::= PIPE ID PIPE",
 /*  92 */ "lambda_args ::=",
 /*  93 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  94 */ "stmt ::= IF s2 fin seq fin END",
 /*  95 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  96 */ "stmt ::= WHILE s2 fin seq fin END",
 /*  97 */ "stmt ::= IMPORT ID",
 /*  98 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  99 */ "stmt ::= ID EQUAL s2",
 /* 100 */ "stmt ::= ID OP1_SET s2",
 /* 101 */ "stmt ::= ID OP0_SET s2",
 /* 102 */ "stmt ::= IVAR EQUAL s2",
 /* 103 */ "stmt ::= IVAR OP1_SET s2",
 /* 104 */ "stmt ::= IVAR OP0_SET s2",
 /* 105 */ "stmt ::= RAISE s2",
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
  { 61, 3 },
  { 61, 1 },
  { 62, 0 },
  { 62, 3 },
  { 63, 1 },
  { 63, 1 },
  { 63, 1 },
  { 51, 5 },
  { 51, 5 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 64, 1 },
  { 65, 1 },
  { 65, 3 },
  { 65, 3 },
  { 65, 3 },
  { 65, 3 },
  { 65, 3 },
  { 65, 3 },
  { 65, 5 },
  { 65, 6 },
  { 65, 3 },
  { 65, 4 },
  { 65, 6 },
  { 65, 7 },
  { 65, 2 },
  { 65, 1 },
  { 68, 0 },
  { 69, 3 },
  { 69, 1 },
  { 70, 3 },
  { 71, 3 },
  { 71, 1 },
  { 72, 0 },
  { 72, 2 },
  { 66, 3 },
  { 66, 2 },
  { 73, 1 },
  { 73, 3 },
  { 73, 4 },
  { 73, 3 },
  { 73, 5 },
  { 73, 6 },
  { 73, 3 },
  { 73, 4 },
  { 73, 6 },
  { 73, 7 },
  { 73, 1 },
  { 73, 3 },
  { 73, 3 },
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
  { 74, 1 },
  { 75, 3 },
  { 75, 0 },
  { 67, 4 },
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
#line 1096 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy32.a = S->seq(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1102 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 41: /* np_arg ::= lit */ yytestcase(yyruleno==41);
      case 55: /* np_arg ::= lambda */ yytestcase(yyruleno==55);
      case 66: /* np_recv ::= lit */ yytestcase(yyruleno==66);
      case 76: /* np_recv ::= lambda */ yytestcase(yyruleno==76);
      case 87: /* s2 ::= np_recv */ yytestcase(yyruleno==87);
      case 89: /* stmt ::= s2 */ yytestcase(yyruleno==89);
#line 33 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[0].minor.yy32.a; }
#line 1117 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1122 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[-2].minor.yy32.a; }
#line 1128 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy32.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy32.a);
             }
#line 1135 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy32.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a);
             }
#line 1142 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1147 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1153 "vm/parser.c.inc"
        break;
      case 28: /* def_name ::= ID */
      case 29: /* def_name ::= OP0 */ yytestcase(yyruleno==29);
      case 30: /* def_name ::= OP1 */ yytestcase(yyruleno==30);
#line 77 "vm/parser.lm"
{ yygotominor.yy32.s = yymsp[0].minor.yy0.s; }
#line 1160 "vm/parser.c.inc"
        break;
      case 31: /* def ::= def_start def_name def_args fin def_body */
#line 82 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(yymsp[-3].minor.yy32.s, yymsp[0].minor.yy32.a);
            }
#line 1167 "vm/parser.c.inc"
        break;
      case 32: /* def ::= def_start def_name def_args fin END */
#line 85 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(yymsp[-3].minor.yy32.s, S->ast_nil());
            }
#line 1174 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= NUM */
#line 89 "vm/parser.lm"
{ yygotominor.yy32.a = S->number(yymsp[0].minor.yy0.i); }
#line 1179 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= NIL */
#line 90 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_nil();  }
#line 1184 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= TRUE */
#line 91 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_true();  }
#line 1189 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= FALSE */
#line 92 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_false(); }
#line 1194 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= SELF */
#line 93 "vm/parser.lm"
{ yygotominor.yy32.a = S->self(); }
#line 1199 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= ID */
#line 94 "vm/parser.lm"
{ yygotominor.yy32.a = S->named(yymsp[0].minor.yy0.s); }
#line 1204 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= IVAR */
#line 95 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1209 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= LITSTR */
#line 96 "vm/parser.lm"
{ yygotominor.yy32.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1214 "vm/parser.c.inc"
        break;
      case 42: /* np_arg ::= np_arg OP0 np_arg */
      case 43: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==43);
      case 83: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==83);
      case 84: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==84);
#line 100 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1222 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg OP2 np_arg */
      case 85: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==85);
#line 104 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1228 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg CAST np_arg */
      case 82: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==82);
#line 106 "vm/parser.lm"
{ yygotominor.yy32.a = S->cast(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1234 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg NEQUAL np_arg */
      case 86: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==86);
#line 108 "vm/parser.lm"
{ yygotominor.yy32.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a)); }
#line 1240 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT ID */
      case 69: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==69);
#line 109 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy0.s); }
#line 1246 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg DOT ID LP RP */
      case 70: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==70);
#line 110 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy0.s); }
#line 1252 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 71: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==71);
#line 112 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-5].minor.yy32.a, yymsp[-3].minor.yy0.s); }
#line 1258 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DCOLON ID */
      case 72: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==72);
#line 113 "vm/parser.lm"
{ yygotominor.yy32.a = S->dcolon(yymsp[-2].minor.yy32.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1264 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 73: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==73);
#line 115 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect(yymsp[-3].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 1270 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 74: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==74);
#line 117 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect(yymsp[-5].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1276 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 75: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==75);
#line 119 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect_args(yymsp[-6].minor.yy32.a, yymsp[-3].minor.yy32.a); }
#line 1282 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= NOT np_arg */
      case 88: /* s2 ::= NOT s2 */ yytestcase(yyruleno==88);
#line 120 "vm/parser.lm"
{ yygotominor.yy32.a = S->not_(yymsp[0].minor.yy32.a); }
#line 1288 "vm/parser.c.inc"
        break;
      case 56: /* np_arg_list_start ::= */
#line 123 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1293 "vm/parser.c.inc"
        break;
      case 57: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 58: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==58);
#line 124 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy32.a); }
#line 1299 "vm/parser.c.inc"
        break;
      case 59: /* np_kw_arg ::= ID EQUAL np_arg */
#line 127 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1304 "vm/parser.c.inc"
        break;
      case 67: /* np_recv ::= ID LP RP */
#line 139 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1309 "vm/parser.c.inc"
        break;
      case 68: /* np_recv ::= ID LP np_arg_list RP */
#line 140 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1314 "vm/parser.c.inc"
        break;
      case 77: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 152 "vm/parser.lm"
{ yygotominor.yy32.a = S->tuple(); }
#line 1319 "vm/parser.c.inc"
        break;
      case 78: /* np_recv ::= DICT_START np_arg_list RB */
#line 153 "vm/parser.lm"
{ yygotominor.yy32.a = S->dict(); }
#line 1324 "vm/parser.c.inc"
        break;
      case 79: /* s2 ::= np_recv DOT ID np_arg_list */
#line 155 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-3].minor.yy32.a, yymsp[-1].minor.yy0.s); }
#line 1329 "vm/parser.c.inc"
        break;
      case 80: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 157 "vm/parser.lm"
{ yygotominor.yy32.a = S->send_indirect_args(yymsp[-4].minor.yy32.a, yymsp[-1].minor.yy32.a); }
#line 1334 "vm/parser.c.inc"
        break;
      case 81: /* s2 ::= ID np_arg_list */
#line 158 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1339 "vm/parser.c.inc"
        break;
      case 90: /* lambda_start ::= LB */
#line 172 "vm/parser.lm"
{ S->start_lambda(); }
#line 1344 "vm/parser.c.inc"
        break;
      case 91: /* lambda_args ::= PIPE ID PIPE */
#line 174 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1349 "vm/parser.c.inc"
        break;
      case 93: /* lambda ::= lambda_start lambda_args seq RB */
#line 177 "vm/parser.lm"
{ yygotominor.yy32.a = S->lambda(yymsp[-1].minor.yy32.a); }
#line 1354 "vm/parser.c.inc"
        break;
      case 94: /* stmt ::= IF s2 fin seq fin END */
#line 181 "vm/parser.lm"
{ yygotominor.yy32.a = S->if_cond(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1359 "vm/parser.c.inc"
        break;
      case 95: /* stmt ::= UNLESS s2 fin seq fin END */
#line 182 "vm/parser.lm"
{ yygotominor.yy32.a = S->unless(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1364 "vm/parser.c.inc"
        break;
      case 96: /* stmt ::= WHILE s2 fin seq fin END */
#line 183 "vm/parser.lm"
{ yygotominor.yy32.a = S->while_(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1369 "vm/parser.c.inc"
        break;
      case 97: /* stmt ::= IMPORT ID */
#line 187 "vm/parser.lm"
{ yygotominor.yy32.a = S->import(yymsp[0].minor.yy0.s); }
#line 1374 "vm/parser.c.inc"
        break;
      case 98: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 189 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_try(yymsp[-6].minor.yy32.a, yymsp[-2].minor.yy32.a);
            }
#line 1381 "vm/parser.c.inc"
        break;
      case 99: /* stmt ::= ID EQUAL s2 */
#line 193 "vm/parser.lm"
{ yygotominor.yy32.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1386 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= ID OP1_SET s2 */
      case 101: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==101);
#line 194 "vm/parser.lm"
{ yygotominor.yy32.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1392 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= IVAR EQUAL s2 */
#line 196 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1397 "vm/parser.c.inc"
        break;
      case 103: /* stmt ::= IVAR OP1_SET s2 */
      case 104: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==104);
#line 198 "vm/parser.lm"
{ yygotominor.yy32.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1403 "vm/parser.c.inc"
        break;
      case 105: /* stmt ::= RAISE s2 */
#line 201 "vm/parser.lm"
{ yygotominor.yy32.a = S->raise(yymsp[0].minor.yy32.a); }
#line 1408 "vm/parser.c.inc"
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
      /* (26) def_args ::= */ yytestcase(yyruleno==26);
      /* (27) def_args ::= LP id_list RP */ yytestcase(yyruleno==27);
      /* (60) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==60);
      /* (61) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==61);
      /* (62) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==62);
      /* (63) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==63);
      /* (64) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==64);
      /* (65) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==65);
      /* (92) lambda_args ::= */ yytestcase(yyruleno==92);
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
#line 1495 "vm/parser.c.inc"
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
