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
#define YYNOCODE 74
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy30;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 187
#define YYNRULE 99
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
#define YY_ACTTAB_COUNT (864)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    28,  187,  182,  181,  180,   38,  178,   93,   43,   48,
 /*    10 */   176,  182,  181,  167,  166,  165,  164,  163,  102,  160,
 /*    20 */   182,  181,  117,   69,  153,  182,  181,   27,   26,   25,
 /*    30 */    96,   53,   22,   24,   28,  127,  182,  181,  113,  173,
 /*    40 */   178,  177,   43,  109,  176,  171,  174,  167,  166,  165,
 /*    50 */   164,  163,  102,  160,    4,   71,  175,   69,  153,  129,
 /*    60 */   172,   27,   26,   25,   96,   53,   41,   24,   28,   68,
 /*    70 */   182,  181,   39,   38,  178,   93,   43,   97,  176,   20,
 /*    80 */    93,  167,  166,  165,  164,  163,  102,  160,   45,  287,
 /*    90 */     3,   69,  153,  182,  181,   27,   26,   25,   96,   53,
 /*   100 */    70,   24,   28,   67,  182,  181,  157,  115,    5,  168,
 /*   110 */    43,  155,  108,  129,   20,  167,  166,  165,  164,  163,
 /*   120 */   102,  160,  106,   21,   20,   69,  153,  103,  152,   27,
 /*   130 */    26,   25,   96,   53,   29,   24,   28,  150,  182,  181,
 /*   140 */   101,  124,   20,  135,   43,  100,   99,   20,   20,  167,
 /*   150 */   166,  165,  164,  163,  102,  160,    6,  146,  143,   69,
 /*   160 */   153,  129,  141,   27,   26,   25,   96,   53,  132,   24,
 /*   170 */    28,   17,  182,  181,  139,   78,  129,  134,   43,  149,
 /*   180 */   145,   20,   20,  167,  166,  165,  164,  163,  102,  160,
 /*   190 */    11,   16,   61,   69,  153,  129,  129,   27,   26,   25,
 /*   200 */    96,   53,   72,   24,   28,   10,  182,  181,   19,  170,
 /*   210 */   129,  133,   43,  142,  104,   20,   75,  167,  166,  165,
 /*   220 */   164,  163,  102,  160,   15,  113,  126,   69,  153,  129,
 /*   230 */    95,   27,   26,   25,   96,   53,   79,   24,   28,    9,
 /*   240 */   182,  181,   14,  112,  129,    8,   43,  129,  107,   44,
 /*   250 */   129,  167,  166,  165,  164,  163,  102,  160,   13,  158,
 /*   260 */   156,   69,  153,  129,  151,   27,   26,   25,   96,   53,
 /*   270 */    51,   24,   28,    7,  182,  181,  147,  144,  129,  131,
 /*   280 */    43,  288,  288,  288,  288,  167,  166,  165,  164,  163,
 /*   290 */   102,  160,   12,    1,  288,   69,  153,  129,  129,   27,
 /*   300 */    26,   25,   96,   53,  288,   24,   28,    2,  182,  181,
 /*   310 */   288,  288,  129,  121,   43,  288,  288,  288,  288,  167,
 /*   320 */   166,  165,  164,  163,  102,  160,   18,  288,  288,   69,
 /*   330 */   153,  129,  288,   27,   26,   25,   96,   53,  288,   24,
 /*   340 */    28,  288,  182,  181,  288,  288,  288,  288,   43,  288,
 /*   350 */   288,  288,  288,  167,  166,  165,  164,  163,  102,  160,
 /*   360 */   288,  288,  288,   69,  153,  288,   28,   27,   26,   25,
 /*   370 */    96,   53,  288,   24,   43,  288,  288,  288,  288,  167,
 /*   380 */   166,  165,  164,  163,  102,  160,  288,  288,  288,   69,
 /*   390 */   153,  288,  288,   27,   26,   25,   96,   53,   62,   24,
 /*   400 */   288,  120,  185,  184,  183,  179,  288,  288,  114,  119,
 /*   410 */   136,   73,  288,  288,  288,  288,  148,   62,  288,  140,
 /*   420 */   120,  185,  184,  183,  179,   80,   77,  114,  118,  136,
 /*   430 */    73,  159,   88,  288,  154,  148,  288,  288,  140,  288,
 /*   440 */   288,   77,  288,   42,   80,   77,  120,  185,  184,  183,
 /*   450 */   116,  128,  179,  114,   60,  136,   73,  136,  288,  122,
 /*   460 */   288,  148,  288,  148,  140,  288,  140,  288,  241,  288,
 /*   470 */    80,   77,   80,   77,  288,  288,  241,  288,  288,   66,
 /*   480 */   288,  241,  241,  241,  241,  241,  241,  241,  288,   23,
 /*   490 */   288,  288,  241,  186,  185,  184,  183,  179,  128,  179,
 /*   500 */   114,   58,  136,   73,  136,  288,  159,   91,  148,  154,
 /*   510 */   148,  140,  288,  140,  288,  241,   77,   80,   77,   80,
 /*   520 */    77,  288,  288,  241,  288,  288,   66,  288,  241,  241,
 /*   530 */   241,  241,  241,  241,  241,  241,  288,  288,  288,  241,
 /*   540 */   288,  288,  288,  241,  288,  288,   65,  288,  241,  241,
 /*   550 */   241,  241,  241,  241,  241,  241,  288,  159,   94,  241,
 /*   560 */   154,  288,  288,  241,  288,  288,   64,   77,  241,  241,
 /*   570 */   241,  241,  241,  241,  241,   28,  288,  159,  110,  241,
 /*   580 */   154,  288,  288,   46,  288,  288,  288,   77,  167,  166,
 /*   590 */   165,  164,  163,  161,  160,   35,  288,  288,   69,  153,
 /*   600 */   288,  288,  288,  162,  288,  288,  288,  288,  167,  166,
 /*   610 */   165,  164,  163,  161,  160,   35,  288,  159,   90,  153,
 /*   620 */   154,  288,  288,  111,  288,  288,  288,   77,  167,  166,
 /*   630 */   165,  164,  163,  161,  160,  288,  288,  288,  162,  153,
 /*   640 */   288,  288,  288,  167,  166,  165,  164,  163,  161,  160,
 /*   650 */   288,  288,  288,  128,  179,  288,   56,  288,  288,  136,
 /*   660 */   288,  128,  179,  288,   54,  148,  288,  136,  140,  288,
 /*   670 */   288,  288,  288,  148,   80,   77,  140,  288,  128,  179,
 /*   680 */   288,   52,   80,   77,  136,   33,   34,   30,   32,   31,
 /*   690 */   148,   92,  288,  140,  288,  128,  179,  288,   50,   80,
 /*   700 */    77,  136,  288,  288,  288,  288,  288,  148,  159,   82,
 /*   710 */   140,  154,   98,   63,  125,   74,   80,   77,   77,  288,
 /*   720 */   288,  288,  288,  128,  137,  288,   47,  288,  288,  136,
 /*   730 */   148,  169,  179,  140,  288,  148,  288,  136,  140,   80,
 /*   740 */    77,  288,  288,  148,   80,   77,  140,  288,  288,  288,
 /*   750 */   288,  288,   80,   77,   40,   37,   36,   39,   38,  288,
 /*   760 */    93,  159,   81,  138,  154,  288,  288,  125,   76,  148,
 /*   770 */   288,   77,  140,  288,   59,  288,  288,  288,   80,   77,
 /*   780 */   148,  288,   57,  140,  288,  288,   55,  288,  148,   80,
 /*   790 */    77,  140,  148,  288,  130,  140,  288,   80,   77,  123,
 /*   800 */   148,   80,   77,  140,  288,  148,  288,  288,  140,   80,
 /*   810 */    77,   49,  288,  288,   80,   77,  288,  148,  159,   89,
 /*   820 */   140,  154,  159,  105,  288,  154,   80,   77,   77,  288,
 /*   830 */   159,   87,   77,  154,  159,   86,  288,  154,  288,  288,
 /*   840 */    77,  288,  159,   85,   77,  154,  288,  288,  159,   84,
 /*   850 */   288,  154,   77,  159,   83,  288,  154,  288,   77,  288,
 /*   860 */   288,  288,  288,   77,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    0,    8,    9,   10,    5,   12,    7,   14,   14,
 /*    10 */    16,    8,    9,   19,   20,   21,   22,   23,   24,   25,
 /*    20 */     8,    9,   10,   29,   30,    8,    9,   33,   34,   35,
 /*    30 */    36,   37,   15,   39,    6,   32,    8,    9,   11,    8,
 /*    40 */    12,   13,   14,   14,   16,   18,    4,   19,   20,   21,
 /*    50 */    22,   23,   24,   25,   45,   26,   14,   29,   30,   50,
 /*    60 */    14,   33,   34,   35,   36,   37,   27,   39,    6,   17,
 /*    70 */     8,    9,    4,    5,   12,    7,   14,   63,   16,   65,
 /*    80 */     7,   19,   20,   21,   22,   23,   24,   25,   14,   41,
 /*    90 */    42,   29,   30,    8,    9,   33,   34,   35,   36,   37,
 /*   100 */    26,   39,    6,   17,    8,    9,   18,   44,   45,   13,
 /*   110 */    14,   18,   63,   50,   65,   19,   20,   21,   22,   23,
 /*   120 */    24,   25,   63,   51,   65,   29,   30,   14,   31,   33,
 /*   130 */    34,   35,   36,   37,   27,   39,    6,   18,    8,    9,
 /*   140 */    63,   69,   65,   13,   14,   63,   63,   65,   65,   19,
 /*   150 */    20,   21,   22,   23,   24,   25,   45,   18,   18,   29,
 /*   160 */    30,   50,   14,   33,   34,   35,   36,   37,   14,   39,
 /*   170 */     6,   45,    8,    9,   18,   17,   50,   13,   14,   63,
 /*   180 */    63,   65,   65,   19,   20,   21,   22,   23,   24,   25,
 /*   190 */    45,   45,   59,   29,   30,   50,   50,   33,   34,   35,
 /*   200 */    36,   37,   58,   39,    6,   45,    8,    9,   72,   14,
 /*   210 */    50,   13,   14,   63,   31,   65,   51,   19,   20,   21,
 /*   220 */    22,   23,   24,   25,   45,   11,   67,   29,   30,   50,
 /*   230 */    14,   33,   34,   35,   36,   37,   60,   39,    6,   45,
 /*   240 */     8,    9,   45,   51,   50,   45,   14,   50,   61,   61,
 /*   250 */    50,   19,   20,   21,   22,   23,   24,   25,   45,   18,
 /*   260 */    18,   29,   30,   50,   18,   33,   34,   35,   36,   37,
 /*   270 */    38,   39,    6,   45,    8,    9,   18,   18,   50,   13,
 /*   280 */    14,   73,   73,   73,   73,   19,   20,   21,   22,   23,
 /*   290 */    24,   25,   45,   45,   73,   29,   30,   50,   50,   33,
 /*   300 */    34,   35,   36,   37,   73,   39,    6,   45,    8,    9,
 /*   310 */    73,   73,   50,   13,   14,   73,   73,   73,   73,   19,
 /*   320 */    20,   21,   22,   23,   24,   25,   45,   73,   73,   29,
 /*   330 */    30,   50,   73,   33,   34,   35,   36,   37,   73,   39,
 /*   340 */     6,   73,    8,    9,   73,   73,   73,   73,   14,   73,
 /*   350 */    73,   73,   73,   19,   20,   21,   22,   23,   24,   25,
 /*   360 */    73,   73,   73,   29,   30,   73,    6,   33,   34,   35,
 /*   370 */    36,   37,   73,   39,   14,   73,   73,   73,   73,   19,
 /*   380 */    20,   21,   22,   23,   24,   25,   73,   73,   73,   29,
 /*   390 */    30,   73,   73,   33,   34,   35,   36,   37,   43,   39,
 /*   400 */    73,   46,   47,   48,   49,   50,   73,   73,   53,   54,
 /*   410 */    55,   56,   73,   73,   73,   73,   61,   43,   73,   64,
 /*   420 */    46,   47,   48,   49,   50,   70,   71,   53,   54,   55,
 /*   430 */    56,   61,   62,   73,   64,   61,   73,   73,   64,   73,
 /*   440 */    73,   71,   73,   43,   70,   71,   46,   47,   48,   49,
 /*   450 */    50,   49,   50,   53,   52,   55,   56,   55,   73,   57,
 /*   460 */    73,   61,   73,   61,   64,   73,   64,   73,    6,   73,
 /*   470 */    70,   71,   70,   71,   73,   73,   14,   73,   73,   17,
 /*   480 */    73,   19,   20,   21,   22,   23,   24,   25,   73,   27,
 /*   490 */    73,   73,   30,   46,   47,   48,   49,   50,   49,   50,
 /*   500 */    53,   52,   55,   56,   55,   73,   61,   62,   61,   64,
 /*   510 */    61,   64,   73,   64,   73,    6,   71,   70,   71,   70,
 /*   520 */    71,   73,   73,   14,   73,   73,   17,   73,   19,   20,
 /*   530 */    21,   22,   23,   24,   25,    6,   73,   73,   73,   30,
 /*   540 */    73,   73,   73,   14,   73,   73,   17,   73,   19,   20,
 /*   550 */    21,   22,   23,   24,   25,    6,   73,   61,   62,   30,
 /*   560 */    64,   73,   73,   14,   73,   73,   17,   71,   19,   20,
 /*   570 */    21,   22,   23,   24,   25,    6,   73,   61,   62,   30,
 /*   580 */    64,   73,   73,   14,   73,   73,   73,   71,   19,   20,
 /*   590 */    21,   22,   23,   24,   25,    6,   73,   73,   29,   30,
 /*   600 */    73,   73,   73,   14,   73,   73,   73,   73,   19,   20,
 /*   610 */    21,   22,   23,   24,   25,    6,   73,   61,   62,   30,
 /*   620 */    64,   73,   73,   14,   73,   73,   73,   71,   19,   20,
 /*   630 */    21,   22,   23,   24,   25,   73,   73,   73,   14,   30,
 /*   640 */    73,   73,   73,   19,   20,   21,   22,   23,   24,   25,
 /*   650 */    73,   73,   73,   49,   50,   73,   52,   73,   73,   55,
 /*   660 */    73,   49,   50,   73,   52,   61,   73,   55,   64,   73,
 /*   670 */    73,   73,   73,   61,   70,   71,   64,   73,   49,   50,
 /*   680 */    73,   52,   70,   71,   55,    1,    2,    3,    4,    5,
 /*   690 */    61,    7,   73,   64,   73,   49,   50,   73,   52,   70,
 /*   700 */    71,   55,   73,   73,   73,   73,   73,   61,   61,   62,
 /*   710 */    64,   64,   28,   66,   67,   68,   70,   71,   71,   73,
 /*   720 */    73,   73,   73,   49,   55,   73,   52,   73,   73,   55,
 /*   730 */    61,   49,   50,   64,   73,   61,   73,   55,   64,   70,
 /*   740 */    71,   73,   73,   61,   70,   71,   64,   73,   73,   73,
 /*   750 */    73,   73,   70,   71,    1,    2,    3,    4,    5,   73,
 /*   760 */     7,   61,   62,   55,   64,   73,   73,   67,   68,   61,
 /*   770 */    73,   71,   64,   73,   55,   73,   73,   73,   70,   71,
 /*   780 */    61,   73,   55,   64,   73,   73,   55,   73,   61,   70,
 /*   790 */    71,   64,   61,   73,   55,   64,   73,   70,   71,   55,
 /*   800 */    61,   70,   71,   64,   73,   61,   73,   73,   64,   70,
 /*   810 */    71,   55,   73,   73,   70,   71,   73,   61,   61,   62,
 /*   820 */    64,   64,   61,   62,   73,   64,   70,   71,   71,   73,
 /*   830 */    61,   62,   71,   64,   61,   62,   73,   64,   73,   73,
 /*   840 */    71,   73,   61,   62,   71,   64,   73,   73,   61,   62,
 /*   850 */    73,   64,   71,   61,   62,   73,   64,   73,   71,   73,
 /*   860 */    73,   73,   73,   71,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (115)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (753)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   62,   62,   62,   28,   -6,  300,  334,  334,  334,
 /*    10 */   334,  334,  266,  232,  198,  164,  130,   96,  334,  360,
 /*    20 */   609,  609,  569,  569,  569,  569,  569,  569,  569,  569,
 /*    30 */   589,  589,  589,  589,  589,  589,  589,  589,  589,  589,
 /*    40 */   589,  589,   12,  462,  549,  529,  509,    3,   17,   85,
 /*    50 */    85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
 /*    60 */    85,   85,   85,  214,  259,  258,  246,  242,  241,   -7,
 /*    70 */   624,  624,   27,   42,  214,  216,  214,  183,  195,  158,
 /*    80 */   684,  753,  753,  753,  753,  753,  753,  753,  753,   68,
 /*    90 */    68,   68,   74,   29,    0,   39,  154,  156,  148,  140,
 /*   100 */   139,  119,  107,   97,  113,   73,   93,   86,   88,   52,
 /*   110 */    73,   39,   46,   31,   -5,    1,
};
#define YY_REDUCE_USE_DFLT (-1)
#define YY_REDUCE_COUNT (79)
#define YY_REDUCE_MIN   (0)
#define YY_REDUCE_MAX   (792)
static const short yy_reduce_ofst[] = {
 /*     0 */    48,  374,  355,  400,  447,  447,  402,  646,  629,  612,
 /*    10 */   604,  449,  682,  682,  682,  682,  682,  682,  682,  674,
 /*    20 */   647,  700,  756,  744,  739,  731,  727,  719,  708,  669,
 /*    30 */   792,  787,  781,  773,  769,  761,  757,  556,  516,  496,
 /*    40 */   445,  370,   63,  116,  150,  117,  116,  281,  262,  248,
 /*    50 */   247,  228,  213,  200,  197,  194,  179,  160,  146,  145,
 /*    60 */   126,  111,    9,   72,   83,   82,   77,   59,   49,   14,
 /*    70 */   188,  187,  192,  176,  165,  159,  165,  136,  144,  133,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   195,  286,  286,  286,  286,  286,  286,  286,  286,  286,
 /*    10 */   286,  286,  286,  286,  286,  286,  286,  286,  286,  286,
 /*    20 */   286,  286,  286,  286,  286,  286,  286,  286,  286,  286,
 /*    30 */   286,  286,  286,  286,  286,  286,  286,  286,  286,  286,
 /*    40 */   286,  286,  286,  224,  258,  254,  224,  286,  286,  286,
 /*    50 */   286,  286,  286,  286,  286,  286,  286,  286,  286,  286,
 /*    60 */   286,  286,  286,  247,  241,  241,  241,  241,  241,  241,
 /*    70 */   286,  286,  286,  286,  250,  286,  248,  276,  286,  213,
 /*    80 */   271,  242,  243,  270,  269,  268,  267,  266,  244,  232,
 /*    90 */   231,  228,  286,  286,  229,  286,  286,  286,  286,  286,
 /*   100 */   286,  286,  225,  286,  286,  239,  286,  236,  286,  233,
 /*   110 */   230,  224,  286,  202,  286,  286,  196,  197,  208,  207,
 /*   120 */   189,  218,  217,  283,  249,  246,  245,  277,  204,  200,
 /*   130 */   285,  282,  281,  280,  279,  278,  273,  284,  272,  262,
 /*   140 */   261,  257,  264,  260,  259,  263,  256,  255,  251,  265,
 /*   150 */   253,  252,  275,  274,  240,  238,  237,  235,  234,  227,
 /*   160 */   226,  225,  224,  223,  222,  221,  220,  219,  210,  203,
 /*   170 */   212,  214,  211,  201,  216,  215,  209,  206,  205,  199,
 /*   180 */   198,  194,  193,  192,  191,  190,  188,
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
  "NL",            "SEMI",          "EOF",           "COMMA",       
  "CLASS",         "END",           "ID",            "LT",          
  "DEF",           "LP",            "RP",            "NUM",         
  "NIL",           "TRUE",          "FALSE",         "SELF",        
  "IVAR",          "LITSTR",        "DOLLAR",        "EQUAL",       
  "DCOLON",        "TUPLE_START",   "LB",            "PIPE",        
  "RB",            "IF",            "UNLESS",        "WHILE",       
  "IMPORT",        "TRY",           "RESCUE",        "RAISE",       
  "error",         "program",       "opt_fin",       "l1",          
  "last_fin",      "fin",           "l1e",           "class",       
  "def",           "stmt",          "fin_m",         "comma",       
  "seq",           "class_start",   "class_body",    "s2",          
  "def_start",     "def_body",      "id_list",       "def_args",    
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
 /*  24 */ "id_list ::= id_list comma ID",
 /*  25 */ "id_list ::= ID",
 /*  26 */ "def_args ::=",
 /*  27 */ "def_args ::= LP id_list RP",
 /*  28 */ "def_name ::= ID",
 /*  29 */ "def_name ::= OP1",
 /*  30 */ "def ::= def_start def_name def_args fin def_body",
 /*  31 */ "def ::= def_start def_name def_args fin END",
 /*  32 */ "lit ::= NUM",
 /*  33 */ "lit ::= NIL",
 /*  34 */ "lit ::= TRUE",
 /*  35 */ "lit ::= FALSE",
 /*  36 */ "lit ::= SELF",
 /*  37 */ "lit ::= ID",
 /*  38 */ "lit ::= IVAR",
 /*  39 */ "lit ::= LITSTR",
 /*  40 */ "np_arg ::= lit",
 /*  41 */ "np_arg ::= np_arg OP0 np_arg",
 /*  42 */ "np_arg ::= np_arg OP1 np_arg",
 /*  43 */ "np_arg ::= np_arg OP2 np_arg",
 /*  44 */ "np_arg ::= np_arg CAST np_arg",
 /*  45 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  46 */ "np_arg ::= np_arg DOT ID",
 /*  47 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  48 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  49 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  50 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  51 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  52 */ "np_arg ::= NOT np_arg",
 /*  53 */ "np_arg ::= lambda",
 /*  54 */ "np_arg_list_start ::=",
 /*  55 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  56 */ "np_arg_list_elems ::= np_arg",
 /*  57 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  58 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  59 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  60 */ "np_opt_kw_arg_list ::=",
 /*  61 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  62 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  63 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  64 */ "np_recv ::= lit",
 /*  65 */ "np_recv ::= ID LP RP",
 /*  66 */ "np_recv ::= ID LP np_arg_list RP",
 /*  67 */ "np_recv ::= np_recv DOT ID",
 /*  68 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  69 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  70 */ "np_recv ::= np_recv DCOLON ID",
 /*  71 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  72 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  73 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  74 */ "np_recv ::= lambda",
 /*  75 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  76 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  77 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  78 */ "s2 ::= ID np_arg_list",
 /*  79 */ "s2 ::= np_recv CAST np_arg",
 /*  80 */ "s2 ::= np_recv OP0 np_arg",
 /*  81 */ "s2 ::= np_recv OP1 np_arg",
 /*  82 */ "s2 ::= np_recv OP2 np_arg",
 /*  83 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  84 */ "s2 ::= np_recv",
 /*  85 */ "s2 ::= NOT s2",
 /*  86 */ "stmt ::= s2",
 /*  87 */ "lambda_start ::= LB",
 /*  88 */ "lambda_args ::= PIPE ID PIPE",
 /*  89 */ "lambda_args ::=",
 /*  90 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  91 */ "stmt ::= IF s2 fin seq fin END",
 /*  92 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  93 */ "stmt ::= WHILE s2 fin seq fin END",
 /*  94 */ "stmt ::= IMPORT ID",
 /*  95 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  96 */ "stmt ::= ID EQUAL s2",
 /*  97 */ "stmt ::= IVAR EQUAL s2",
 /*  98 */ "stmt ::= RAISE s2",
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
  { 41, 3 },
  { 43, 3 },
  { 43, 1 },
  { 46, 1 },
  { 46, 1 },
  { 46, 1 },
  { 50, 1 },
  { 50, 1 },
  { 42, 0 },
  { 42, 2 },
  { 44, 1 },
  { 44, 2 },
  { 45, 2 },
  { 45, 1 },
  { 51, 2 },
  { 51, 1 },
  { 52, 3 },
  { 52, 1 },
  { 53, 1 },
  { 54, 3 },
  { 47, 4 },
  { 47, 6 },
  { 56, 1 },
  { 57, 3 },
  { 58, 3 },
  { 58, 1 },
  { 59, 0 },
  { 59, 3 },
  { 60, 1 },
  { 60, 1 },
  { 48, 5 },
  { 48, 5 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 62, 1 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 3 },
  { 62, 5 },
  { 62, 6 },
  { 62, 4 },
  { 62, 6 },
  { 62, 7 },
  { 62, 2 },
  { 62, 1 },
  { 65, 0 },
  { 66, 3 },
  { 66, 1 },
  { 67, 3 },
  { 68, 3 },
  { 68, 1 },
  { 69, 0 },
  { 69, 2 },
  { 63, 3 },
  { 63, 2 },
  { 70, 1 },
  { 70, 3 },
  { 70, 4 },
  { 70, 3 },
  { 70, 5 },
  { 70, 6 },
  { 70, 3 },
  { 70, 4 },
  { 70, 6 },
  { 70, 7 },
  { 70, 1 },
  { 70, 3 },
  { 55, 4 },
  { 55, 5 },
  { 55, 2 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 1 },
  { 55, 2 },
  { 49, 1 },
  { 71, 1 },
  { 72, 3 },
  { 72, 0 },
  { 64, 4 },
  { 49, 6 },
  { 49, 6 },
  { 49, 6 },
  { 49, 2 },
  { 49, 9 },
  { 49, 3 },
  { 49, 3 },
  { 49, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy30.a)); }
#line 1068 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy30.a = S->seq(yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1074 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 40: /* np_arg ::= lit */ yytestcase(yyruleno==40);
      case 53: /* np_arg ::= lambda */ yytestcase(yyruleno==53);
      case 64: /* np_recv ::= lit */ yytestcase(yyruleno==64);
      case 74: /* np_recv ::= lambda */ yytestcase(yyruleno==74);
      case 84: /* s2 ::= np_recv */ yytestcase(yyruleno==84);
      case 86: /* stmt ::= s2 */ yytestcase(yyruleno==86);
#line 33 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[0].minor.yy30.a; }
#line 1089 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1094 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy30.a = yymsp[-2].minor.yy30.a; }
#line 1100 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy30.a);
             }
#line 1107 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy30.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a);
             }
#line 1114 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1119 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1125 "vm/parser.c.inc"
        break;
      case 28: /* def_name ::= ID */
      case 29: /* def_name ::= OP1 */ yytestcase(yyruleno==29);
#line 77 "vm/parser.lm"
{ yygotominor.yy30.s = yymsp[0].minor.yy0.s; }
#line 1131 "vm/parser.c.inc"
        break;
      case 30: /* def ::= def_start def_name def_args fin def_body */
#line 81 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_def(yymsp[-3].minor.yy30.s, yymsp[0].minor.yy30.a);
            }
#line 1138 "vm/parser.c.inc"
        break;
      case 31: /* def ::= def_start def_name def_args fin END */
#line 84 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_def(yymsp[-3].minor.yy30.s, S->ast_nil());
            }
#line 1145 "vm/parser.c.inc"
        break;
      case 32: /* lit ::= NUM */
#line 88 "vm/parser.lm"
{ yygotominor.yy30.a = S->number(yymsp[0].minor.yy0.i); }
#line 1150 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= NIL */
#line 89 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_nil();  }
#line 1155 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= TRUE */
#line 90 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_true();  }
#line 1160 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= FALSE */
#line 91 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_false(); }
#line 1165 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= SELF */
#line 92 "vm/parser.lm"
{ yygotominor.yy30.a = S->self(); }
#line 1170 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= ID */
#line 93 "vm/parser.lm"
{ yygotominor.yy30.a = S->named(yymsp[0].minor.yy0.s); }
#line 1175 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= IVAR */
#line 94 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1180 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= LITSTR */
#line 95 "vm/parser.lm"
{ yygotominor.yy30.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1185 "vm/parser.c.inc"
        break;
      case 41: /* np_arg ::= np_arg OP0 np_arg */
      case 43: /* np_arg ::= np_arg OP2 np_arg */ yytestcase(yyruleno==43);
      case 80: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==80);
      case 82: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==82);
#line 99 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1193 "vm/parser.c.inc"
        break;
      case 42: /* np_arg ::= np_arg OP1 np_arg */
      case 81: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==81);
#line 101 "vm/parser.lm"
{ yygotominor.yy30.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1199 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg CAST np_arg */
      case 79: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==79);
#line 105 "vm/parser.lm"
{ yygotominor.yy30.a = S->cast(yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1205 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg NEQUAL np_arg */
      case 83: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==83);
#line 107 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy30.a, yymsp[0].minor.yy30.a)); }
#line 1211 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg DOT ID */
      case 67: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==67);
#line 108 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-2].minor.yy30.a, yymsp[0].minor.yy0.s); }
#line 1217 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT ID LP RP */
      case 68: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==68);
#line 109 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy0.s); }
#line 1223 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 69: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==69);
#line 111 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(yymsp[-5].minor.yy30.a, yymsp[-3].minor.yy0.s); }
#line 1229 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 71: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==71);
#line 113 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect(yymsp[-3].minor.yy30.a, yymsp[0].minor.yy30.a); }
#line 1235 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 72: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==72);
#line 115 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect(yymsp[-5].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1241 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 73: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==73);
#line 117 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect_args(yymsp[-6].minor.yy30.a, yymsp[-3].minor.yy30.a); }
#line 1247 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= NOT np_arg */
      case 85: /* s2 ::= NOT s2 */ yytestcase(yyruleno==85);
#line 118 "vm/parser.lm"
{ yygotominor.yy30.a = S->not_(yymsp[0].minor.yy30.a); }
#line 1253 "vm/parser.c.inc"
        break;
      case 54: /* np_arg_list_start ::= */
#line 121 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1258 "vm/parser.c.inc"
        break;
      case 55: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 56: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==56);
#line 122 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy30.a); }
#line 1264 "vm/parser.c.inc"
        break;
      case 57: /* np_kw_arg ::= ID EQUAL np_arg */
#line 125 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1269 "vm/parser.c.inc"
        break;
      case 65: /* np_recv ::= ID LP RP */
#line 137 "vm/parser.lm"
{ yygotominor.yy30.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1274 "vm/parser.c.inc"
        break;
      case 66: /* np_recv ::= ID LP np_arg_list RP */
#line 138 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1279 "vm/parser.c.inc"
        break;
      case 70: /* np_recv ::= np_recv DCOLON ID */
#line 142 "vm/parser.lm"
{ yygotominor.yy30.a = S->dcolon(yymsp[-2].minor.yy30.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1284 "vm/parser.c.inc"
        break;
      case 75: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 150 "vm/parser.lm"
{ yygotominor.yy30.a = S->tuple(); }
#line 1289 "vm/parser.c.inc"
        break;
      case 76: /* s2 ::= np_recv DOT ID np_arg_list */
#line 152 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(yymsp[-3].minor.yy30.a, yymsp[-1].minor.yy0.s); }
#line 1294 "vm/parser.c.inc"
        break;
      case 77: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 154 "vm/parser.lm"
{ yygotominor.yy30.a = S->send_indirect_args(yymsp[-4].minor.yy30.a, yymsp[-1].minor.yy30.a); }
#line 1299 "vm/parser.c.inc"
        break;
      case 78: /* s2 ::= ID np_arg_list */
#line 155 "vm/parser.lm"
{ yygotominor.yy30.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1304 "vm/parser.c.inc"
        break;
      case 87: /* lambda_start ::= LB */
#line 169 "vm/parser.lm"
{ S->start_lambda(); }
#line 1309 "vm/parser.c.inc"
        break;
      case 88: /* lambda_args ::= PIPE ID PIPE */
#line 171 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1314 "vm/parser.c.inc"
        break;
      case 90: /* lambda ::= lambda_start lambda_args seq RB */
#line 174 "vm/parser.lm"
{ yygotominor.yy30.a = S->lambda(yymsp[-1].minor.yy30.a); }
#line 1319 "vm/parser.c.inc"
        break;
      case 91: /* stmt ::= IF s2 fin seq fin END */
#line 178 "vm/parser.lm"
{ yygotominor.yy30.a = S->if_cond(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1324 "vm/parser.c.inc"
        break;
      case 92: /* stmt ::= UNLESS s2 fin seq fin END */
#line 179 "vm/parser.lm"
{ yygotominor.yy30.a = S->unless(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1329 "vm/parser.c.inc"
        break;
      case 93: /* stmt ::= WHILE s2 fin seq fin END */
#line 180 "vm/parser.lm"
{ yygotominor.yy30.a = S->while_(yymsp[-4].minor.yy30.a, yymsp[-2].minor.yy30.a); }
#line 1334 "vm/parser.c.inc"
        break;
      case 94: /* stmt ::= IMPORT ID */
#line 184 "vm/parser.lm"
{ yygotominor.yy30.a = S->import(yymsp[0].minor.yy0.s); }
#line 1339 "vm/parser.c.inc"
        break;
      case 95: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 186 "vm/parser.lm"
{
              yygotominor.yy30.a = S->ast_try(yymsp[-6].minor.yy30.a, yymsp[-2].minor.yy30.a);
            }
#line 1346 "vm/parser.c.inc"
        break;
      case 96: /* stmt ::= ID EQUAL s2 */
#line 190 "vm/parser.lm"
{ yygotominor.yy30.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1351 "vm/parser.c.inc"
        break;
      case 97: /* stmt ::= IVAR EQUAL s2 */
#line 191 "vm/parser.lm"
{ yygotominor.yy30.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy30.a); }
#line 1356 "vm/parser.c.inc"
        break;
      case 98: /* stmt ::= RAISE s2 */
#line 192 "vm/parser.lm"
{ yygotominor.yy30.a = S->raise(yymsp[0].minor.yy30.a); }
#line 1361 "vm/parser.c.inc"
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
      /* (58) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==58);
      /* (59) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==59);
      /* (60) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==60);
      /* (61) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==61);
      /* (62) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==62);
      /* (63) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==63);
      /* (89) lambda_args ::= */ yytestcase(yyruleno==89);
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
#line 1448 "vm/parser.c.inc"
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
