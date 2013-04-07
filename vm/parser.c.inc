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
#define YYNOCODE 81
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
#define YYNSTATE 208
#define YYNRULE 110
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
#define YY_ACTTAB_COUNT (902)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    32,  120,  208,  203,  202,  201,   52,  199,   33,   47,
 /*    10 */    42,  197,  103,  116,   78,  185,  184,  183,  182,  181,
 /*    20 */    99,  178,   31,   30,   75,   74,  123,  177,   95,  170,
 /*    30 */   171,   29,   28,   27,  106,   57,  192,   84,   32,   26,
 /*    40 */   191,  203,  202,  203,  202,  199,  198,   47,   45,  197,
 /*    50 */    22,  203,  202,  185,  184,  183,  182,  181,   99,  178,
 /*    60 */   103,  116,   75,   74,   72,  177,   98,  170,  171,   29,
 /*    70 */    28,   27,  106,   57,  140,   84,   32,   26,  175,  203,
 /*    80 */   202,   71,  109,  199,   20,   47,   49,  197,  108,  172,
 /*    90 */    20,  185,  184,  183,  182,  181,   99,  178,  173,   77,
 /*   100 */    75,   74,  114,  177,  100,  170,  171,   29,   28,   27,
 /*   110 */   106,   57,  169,   84,   32,   26,  167,  203,  202,  126,
 /*   120 */     5,  122,  186,   47,  107,  142,   20,  158,  189,  185,
 /*   130 */   184,  183,  182,  181,   99,  178,  188,   80,   75,   74,
 /*   140 */   163,  177,  104,  170,  171,   29,   28,   27,  106,   57,
 /*   150 */   157,   84,   32,   26,  160,  203,  202,  203,  202,  128,
 /*   160 */   148,   47,  119,  117,   20,   20,  155,  185,  184,  183,
 /*   170 */   182,  181,   99,  178,  203,  202,   75,   74,  145,  177,
 /*   180 */    97,  170,  171,   29,   28,   27,  106,   57,  154,   84,
 /*   190 */    32,   26,   65,  203,  202,  113,   73,   20,  147,   47,
 /*   200 */   112,  111,   20,   20,  190,  185,  184,  183,  182,  181,
 /*   210 */    99,  178,  124,   19,   75,   74,   21,  177,   96,  170,
 /*   220 */   171,   29,   28,   27,  106,   57,  115,   84,   32,   26,
 /*   230 */    82,  203,  202,    4,    6,  137,  146,   47,  142,  142,
 /*   240 */   166,  122,   20,  185,  184,  183,  182,  181,   99,  178,
 /*   250 */   319,    3,   75,   74,  139,  177,  102,  170,  171,   29,
 /*   260 */    28,   27,  106,   57,  105,   84,   32,   26,   17,  203,
 /*   270 */   202,   11,   16,  142,   10,   47,  142,  142,  162,  142,
 /*   280 */    20,  185,  184,  183,  182,  181,   99,  178,   85,  176,
 /*   290 */    75,   74,  118,  177,   94,  170,  171,   29,   28,   27,
 /*   300 */   106,   57,   55,   84,   32,   26,   86,  203,  202,   15,
 /*   310 */     9,   48,  144,   47,  142,  142,  159,  320,   20,  185,
 /*   320 */   184,  183,  182,  181,   99,  178,  174,  168,   75,   74,
 /*   330 */   164,  177,   93,  170,  171,   29,   28,   27,  106,   57,
 /*   340 */   161,   84,   32,   26,  320,  203,  202,   14,    8,  320,
 /*   350 */   132,   47,  142,  142,  320,  320,  320,  185,  184,  183,
 /*   360 */   182,  181,   99,  178,  320,  320,   75,   74,  320,  177,
 /*   370 */    92,  170,  171,   29,   28,   27,  106,   57,  320,   84,
 /*   380 */    32,   26,  320,  203,  202,   13,    7,  320,   12,   47,
 /*   390 */   142,  142,  320,  142,  320,  185,  184,  183,  182,  181,
 /*   400 */    99,  178,  320,    1,   75,   74,  320,   32,  142,  170,
 /*   410 */   320,   29,   28,   27,  106,   57,   47,   43,   42,   26,
 /*   420 */   103,  116,  185,  184,  183,  182,  181,   99,  178,    2,
 /*   430 */   320,   75,   74,  320,  142,  267,  170,  320,   29,   28,
 /*   440 */    27,  106,   57,   18,  267,  320,   26,   70,  142,  320,
 /*   450 */   267,  267,  267,  267,  267,  267,  267,  320,   25,  152,
 /*   460 */   320,  320,  320,  320,  267,  320,  165,  320,  320,  156,
 /*   470 */   320,  320,   24,   23,   66,   87,   84,  131,  206,  205,
 /*   480 */   204,  200,  320,  320,  125,  130,  149,   79,  320,  320,
 /*   490 */   320,  320,  320,  165,   66,  320,  156,  131,  206,  205,
 /*   500 */   204,  200,   87,   84,  125,  129,  149,   79,  320,  320,
 /*   510 */   320,  320,  320,  165,   46,  320,  156,  131,  206,  205,
 /*   520 */   204,  127,   87,   84,  125,  320,  149,   79,  320,   32,
 /*   530 */   320,  320,  320,  165,  320,  320,  156,  320,   50,  320,
 /*   540 */   320,  320,   87,   84,  185,  184,  183,  182,  181,  179,
 /*   550 */   178,  320,  320,   75,   74,  320,  320,  320,  170,  207,
 /*   560 */   206,  205,  204,  200,  320,  320,  125,  320,  149,   79,
 /*   570 */   320,  320,  320,  141,  200,  165,   64,  320,  156,  149,
 /*   580 */   320,  133,  267,  320,   87,   84,  165,  320,  320,  156,
 /*   590 */   320,  267,  320,  320,   70,   87,   84,  267,  267,  267,
 /*   600 */   267,  267,  267,  267,  267,  320,  320,  177,   91,  320,
 /*   610 */   171,  267,  320,  267,  320,  195,   69,   84,  194,  267,
 /*   620 */   267,  267,  267,  267,  267,  267,  267,  177,   90,  196,
 /*   630 */   171,  320,  320,  267,  193,  267,  320,   84,   68,  320,
 /*   640 */   320,  267,  267,  267,  267,  267,  267,  267,   39,  320,
 /*   650 */   320,  320,  320,  320,  320,  267,  320,  180,  320,  320,
 /*   660 */   320,  320,  320,  185,  184,  183,  182,  181,  179,  178,
 /*   670 */    39,  320,  320,  320,  320,  320,  320,  170,  320,  121,
 /*   680 */   320,  320,  320,  320,  320,  185,  184,  183,  182,  181,
 /*   690 */   179,  178,  320,  320,  320,  320,  320,  320,  320,  170,
 /*   700 */   320,   37,   38,   34,   36,   35,  180,  101,  110,  320,
 /*   710 */   320,  320,  185,  184,  183,  182,  181,  179,  178,  320,
 /*   720 */   320,  141,  200,  320,   62,  141,  200,  149,   60,  153,
 /*   730 */   320,  149,  320,   76,  165,  320,  165,  156,  165,  156,
 /*   740 */   320,  156,  320,   87,   84,   87,   84,   87,   84,   44,
 /*   750 */    41,   40,   43,   42,  320,  103,  116,  141,  200,  320,
 /*   760 */    58,  141,  200,  149,   56,  320,  320,  149,  320,  320,
 /*   770 */   165,  320,  320,  156,  165,  177,   88,  156,  171,   87,
 /*   780 */    84,  138,   83,   87,   84,   84,  320,  141,  200,  320,
 /*   790 */    54,  177,   89,  149,  171,  320,   67,  138,   81,  141,
 /*   800 */   165,   84,   51,  156,  320,  149,  320,  187,  200,   87,
 /*   810 */    84,  320,  165,  149,  320,  156,  320,  151,  320,  320,
 /*   820 */   165,   87,   84,  156,  165,  150,  320,  156,  320,   87,
 /*   830 */    84,  320,  165,   87,   84,  156,   63,  320,   61,  320,
 /*   840 */    59,   87,   84,  165,  320,  165,  156,  165,  156,  320,
 /*   850 */   156,  320,   87,   84,   87,   84,   87,   84,  143,  320,
 /*   860 */   136,  320,  135,  320,  320,  165,  320,  165,  156,  165,
 /*   870 */   156,  320,  156,  320,   87,   84,   87,   84,   87,   84,
 /*   880 */   320,  320,  134,  320,   53,  320,  320,  320,  320,  165,
 /*   890 */   320,  165,  156,  320,  156,  320,  320,  320,   87,   84,
 /*   900 */    87,   84,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   15,    0,    9,   10,   11,   15,   13,   29,   15,
 /*    10 */     5,   17,    7,    8,   28,   21,   22,   23,   24,   25,
 /*    20 */    26,   27,   43,   44,   30,   31,    2,   68,   69,   35,
 /*    30 */    71,   37,   38,   39,   40,   41,   15,   78,    6,   45,
 /*    40 */     9,    9,   10,    9,   10,   13,   14,   15,   29,   17,
 /*    50 */    16,    9,   10,   21,   22,   23,   24,   25,   26,   27,
 /*    60 */     7,    8,   30,   31,   18,   68,   69,   35,   71,   37,
 /*    70 */    38,   39,   40,   41,   32,   78,    6,   45,   19,    9,
 /*    80 */    10,   18,   70,   13,   72,   15,   15,   17,   70,   15,
 /*    90 */    72,   21,   22,   23,   24,   25,   26,   27,   19,   28,
 /*   100 */    30,   31,   15,   68,   69,   35,   71,   37,   38,   39,
 /*   110 */    40,   41,   36,   78,    6,   45,   19,    9,   10,   50,
 /*   120 */    51,   12,   14,   15,   70,   56,   72,   15,   19,   21,
 /*   130 */    22,   23,   24,   25,   26,   27,   64,   65,   30,   31,
 /*   140 */    19,   68,   69,   35,   71,   37,   38,   39,   40,   41,
 /*   150 */    34,   78,    6,   45,   19,    9,   10,    9,   10,   11,
 /*   160 */    14,   15,   70,   70,   72,   72,   19,   21,   22,   23,
 /*   170 */    24,   25,   26,   27,    9,   10,   30,   31,   15,   68,
 /*   180 */    69,   35,   71,   37,   38,   39,   40,   41,   32,   78,
 /*   190 */     6,   45,   66,    9,   10,   70,   18,   72,   14,   15,
 /*   200 */    70,   70,   72,   72,   64,   21,   22,   23,   24,   25,
 /*   210 */    26,   27,   15,   79,   30,   31,   57,   68,   69,   35,
 /*   220 */    71,   37,   38,   39,   40,   41,   36,   78,    6,   45,
 /*   230 */    57,    9,   10,   51,   51,   76,   14,   15,   56,   56,
 /*   240 */    70,   12,   72,   21,   22,   23,   24,   25,   26,   27,
 /*   250 */    47,   48,   30,   31,   74,   68,   69,   35,   71,   37,
 /*   260 */    38,   39,   40,   41,   15,   78,    6,   45,   51,    9,
 /*   270 */    10,   51,   51,   56,   51,   15,   56,   56,   70,   56,
 /*   280 */    72,   21,   22,   23,   24,   25,   26,   27,   57,   19,
 /*   290 */    30,   31,   68,   68,   69,   35,   71,   37,   38,   39,
 /*   300 */    40,   41,   42,   78,    6,   45,   67,    9,   10,   51,
 /*   310 */    51,   68,   14,   15,   56,   56,   70,   80,   72,   21,
 /*   320 */    22,   23,   24,   25,   26,   27,   19,   19,   30,   31,
 /*   330 */    19,   68,   69,   35,   71,   37,   38,   39,   40,   41,
 /*   340 */    19,   78,    6,   45,   80,    9,   10,   51,   51,   80,
 /*   350 */    14,   15,   56,   56,   80,   80,   80,   21,   22,   23,
 /*   360 */    24,   25,   26,   27,   80,   80,   30,   31,   80,   68,
 /*   370 */    69,   35,   71,   37,   38,   39,   40,   41,   80,   78,
 /*   380 */     6,   45,   80,    9,   10,   51,   51,   80,   51,   15,
 /*   390 */    56,   56,   80,   56,   80,   21,   22,   23,   24,   25,
 /*   400 */    26,   27,   80,   51,   30,   31,   80,    6,   56,   35,
 /*   410 */    80,   37,   38,   39,   40,   41,   15,    4,    5,   45,
 /*   420 */     7,    8,   21,   22,   23,   24,   25,   26,   27,   51,
 /*   430 */    80,   30,   31,   80,   56,    6,   35,   80,   37,   38,
 /*   440 */    39,   40,   41,   51,   15,   80,   45,   18,   56,   80,
 /*   450 */    21,   22,   23,   24,   25,   26,   27,   80,   29,   61,
 /*   460 */    80,   80,   80,   80,   35,   80,   68,   80,   80,   71,
 /*   470 */    80,   80,   43,   44,   49,   77,   78,   52,   53,   54,
 /*   480 */    55,   56,   80,   80,   59,   60,   61,   62,   80,   80,
 /*   490 */    80,   80,   80,   68,   49,   80,   71,   52,   53,   54,
 /*   500 */    55,   56,   77,   78,   59,   60,   61,   62,   80,   80,
 /*   510 */    80,   80,   80,   68,   49,   80,   71,   52,   53,   54,
 /*   520 */    55,   56,   77,   78,   59,   80,   61,   62,   80,    6,
 /*   530 */    80,   80,   80,   68,   80,   80,   71,   80,   15,   80,
 /*   540 */    80,   80,   77,   78,   21,   22,   23,   24,   25,   26,
 /*   550 */    27,   80,   80,   30,   31,   80,   80,   80,   35,   52,
 /*   560 */    53,   54,   55,   56,   80,   80,   59,   80,   61,   62,
 /*   570 */    80,   80,   80,   55,   56,   68,   58,   80,   71,   61,
 /*   580 */    80,   63,    6,   80,   77,   78,   68,   80,   80,   71,
 /*   590 */    80,   15,   80,   80,   18,   77,   78,   21,   22,   23,
 /*   600 */    24,   25,   26,   27,    6,   80,   80,   68,   69,   80,
 /*   610 */    71,   35,   80,   15,   80,    1,   18,   78,    4,   21,
 /*   620 */    22,   23,   24,   25,   26,   27,    6,   68,   69,   15,
 /*   630 */    71,   80,   80,   35,   20,   15,   80,   78,   18,   80,
 /*   640 */    80,   21,   22,   23,   24,   25,   26,   27,    6,   80,
 /*   650 */    80,   80,   80,   80,   80,   35,   80,   15,   80,   80,
 /*   660 */    80,   80,   80,   21,   22,   23,   24,   25,   26,   27,
 /*   670 */     6,   80,   80,   80,   80,   80,   80,   35,   80,   15,
 /*   680 */    80,   80,   80,   80,   80,   21,   22,   23,   24,   25,
 /*   690 */    26,   27,   80,   80,   80,   80,   80,   80,   80,   35,
 /*   700 */    80,    1,    2,    3,    4,    5,   15,    7,    8,   80,
 /*   710 */    80,   80,   21,   22,   23,   24,   25,   26,   27,   80,
 /*   720 */    80,   55,   56,   80,   58,   55,   56,   61,   58,   61,
 /*   730 */    80,   61,   80,   33,   68,   80,   68,   71,   68,   71,
 /*   740 */    80,   71,   80,   77,   78,   77,   78,   77,   78,    1,
 /*   750 */     2,    3,    4,    5,   80,    7,    8,   55,   56,   80,
 /*   760 */    58,   55,   56,   61,   58,   80,   80,   61,   80,   80,
 /*   770 */    68,   80,   80,   71,   68,   68,   69,   71,   71,   77,
 /*   780 */    78,   74,   75,   77,   78,   78,   80,   55,   56,   80,
 /*   790 */    58,   68,   69,   61,   71,   80,   73,   74,   75,   55,
 /*   800 */    68,   78,   58,   71,   80,   61,   80,   55,   56,   77,
 /*   810 */    78,   80,   68,   61,   80,   71,   80,   61,   80,   80,
 /*   820 */    68,   77,   78,   71,   68,   61,   80,   71,   80,   77,
 /*   830 */    78,   80,   68,   77,   78,   71,   61,   80,   61,   80,
 /*   840 */    61,   77,   78,   68,   80,   68,   71,   68,   71,   80,
 /*   850 */    71,   80,   77,   78,   77,   78,   77,   78,   61,   80,
 /*   860 */    61,   80,   61,   80,   80,   68,   80,   68,   71,   68,
 /*   870 */    71,   80,   71,   80,   77,   78,   77,   78,   77,   78,
 /*   880 */    80,   80,   61,   80,   61,   80,   80,   80,   80,   68,
 /*   890 */    80,   68,   71,   80,   71,   80,   80,   80,   77,   78,
 /*   900 */    77,   78,
};
#define YY_SHIFT_USE_DFLT (-22)
#define YY_SHIFT_COUNT (126)
#define YY_SHIFT_MIN   (-21)
#define YY_SHIFT_MAX   (748)
static const short yy_shift_ofst[] = {
 /*     0 */   -22,   70,   70,   70,   32,   -6,  336,  374,  374,  374,
 /*    10 */   374,  374,  298,  260,  222,  184,  146,  108,  374,  401,
 /*    20 */   664,  664,  523,  523,  523,  523,  523,  523,  523,  523,
 /*    30 */   523,  523,  523,  523,  642,  642,  642,  642,  642,  642,
 /*    40 */   642,  642,  642,  642,  642,  642,  148,  429,  620,  598,
 /*    50 */   576,   42,   34,  165,  165,  165,  165,  165,  165,  165,
 /*    60 */   165,  165,  165,  165,  165,  165,  165,  229,  321,  311,
 /*    70 */   308,  307,  270,  197,  -22,  -22,  -22,  691,  691,  614,
 /*    80 */   109,  229,  249,  229,  190,  197,  178,  700,  748,  748,
 /*    90 */   748,  748,  748,  748,  748,  748,  413,  413,  413,  -21,
 /*   100 */     5,   71,   53,  -14,   53,   19,  163,  156,  147,  116,
 /*   110 */   112,  135,  121,   97,   76,   87,   74,   79,   63,   59,
 /*   120 */    46,   19,   31,   21,   24,   -9,    2,
};
#define YY_REDUCE_USE_DFLT (-42)
#define YY_REDUCE_COUNT (86)
#define YY_REDUCE_MIN   (-41)
#define YY_REDUCE_MAX   (823)
static const short yy_reduce_ofst[] = {
 /*     0 */   203,  445,  425,  465,  507,  507,  518,  732,  706,  702,
 /*    10 */   670,  666,  752,  752,  752,  752,  752,  752,  752,  744,
 /*    20 */   723,  707,  823,  821,  801,  799,  797,  779,  777,  775,
 /*    30 */   764,  756,  668,  398,  559,  539,  301,  263,  225,  187,
 /*    40 */   149,  111,   73,   35,   -3,  -41,   69,  170,  246,  208,
 /*    50 */   170,  392,  378,  352,  337,  335,  334,  297,  296,  259,
 /*    60 */   258,  223,  221,  220,  217,  183,  182,  159,  131,  130,
 /*    70 */   125,   93,   92,   72,   54,   18,   12,  243,  224,  239,
 /*    80 */   231,  173,  180,  173,  134,  140,  126,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   216,  318,  318,  318,  318,  318,  318,  318,  318,  318,
 /*    10 */   318,  318,  318,  318,  318,  318,  318,  318,  318,  318,
 /*    20 */   318,  318,  318,  318,  318,  318,  318,  318,  318,  318,
 /*    30 */   318,  318,  318,  318,  318,  318,  318,  318,  318,  318,
 /*    40 */   318,  318,  318,  318,  318,  318,  318,  249,  284,  280,
 /*    50 */   249,  318,  318,  318,  318,  318,  318,  318,  318,  318,
 /*    60 */   318,  318,  318,  318,  318,  318,  318,  273,  267,  267,
 /*    70 */   267,  267,  267,  318,  267,  267,  267,  318,  318,  318,
 /*    80 */   318,  276,  318,  274,  304,  318,  236,  299,  268,  269,
 /*    90 */   298,  297,  296,  295,  294,  270,  257,  256,  253,  250,
 /*   100 */   254,  318,  265,  318,  255,  318,  318,  318,  318,  318,
 /*   110 */   318,  318,  318,  318,  318,  318,  318,  318,  262,  318,
 /*   120 */   258,  249,  223,  318,  232,  318,  318,  217,  218,  229,
 /*   130 */   228,  210,  243,  242,  313,  312,  311,  275,  272,  271,
 /*   140 */   305,  225,  221,  317,  310,  309,  308,  307,  306,  301,
 /*   150 */   316,  315,  314,  300,  289,  288,  287,  290,  283,  292,
 /*   160 */   286,  285,  291,  282,  281,  277,  293,  279,  278,  303,
 /*   170 */   302,  266,  261,  264,  263,  260,  259,  252,  251,  250,
 /*   180 */   249,  248,  247,  246,  245,  244,  231,  224,  235,  237,
 /*   190 */   234,  222,  233,  241,  240,  239,  238,  230,  227,  226,
 /*   200 */   220,  219,  215,  214,  213,  212,  211,  209,
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
  "SQUARE",        "NUM",           "NIL",           "TRUE",        
  "FALSE",         "SELF",          "IVAR",          "LITSTR",      
  "DOLLAR",        "EQUAL",         "TUPLE_START",   "DICT_START",  
  "RB",            "LSB",           "RSB",           "LB",          
  "PIPE",          "IF",            "UNLESS",        "WHILE",       
  "IMPORT",        "TRY",           "RESCUE",        "OP1_SET",     
  "OP0_SET",       "RAISE",         "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "fin_m",         "comma",         "seq",           "class_start", 
  "class_body",    "s2",            "def_start",     "def_body",    
  "arg",           "id_list",       "def_args",      "def_name",    
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
 /*  24 */ "arg ::= ID",
 /*  25 */ "arg ::= ID CAST ID",
 /*  26 */ "id_list ::= id_list comma arg",
 /*  27 */ "id_list ::= arg",
 /*  28 */ "def_args ::=",
 /*  29 */ "def_args ::= LP id_list RP",
 /*  30 */ "def_name ::= ID",
 /*  31 */ "def_name ::= OP0",
 /*  32 */ "def_name ::= OP1",
 /*  33 */ "def_name ::= SQUARE",
 /*  34 */ "def ::= def_start def_name def_args fin def_body",
 /*  35 */ "def ::= def_start def_name def_args fin END",
 /*  36 */ "lit ::= NUM",
 /*  37 */ "lit ::= NIL",
 /*  38 */ "lit ::= TRUE",
 /*  39 */ "lit ::= FALSE",
 /*  40 */ "lit ::= SELF",
 /*  41 */ "lit ::= ID",
 /*  42 */ "lit ::= IVAR",
 /*  43 */ "lit ::= LITSTR",
 /*  44 */ "np_arg ::= lit",
 /*  45 */ "np_arg ::= np_arg OP0 np_arg",
 /*  46 */ "np_arg ::= np_arg OP1 np_arg",
 /*  47 */ "np_arg ::= np_arg OP2 np_arg",
 /*  48 */ "np_arg ::= np_arg CAST np_arg",
 /*  49 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  50 */ "np_arg ::= np_arg DOT ID",
 /*  51 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  52 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  53 */ "np_arg ::= np_arg DCOLON ID",
 /*  54 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  55 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  56 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  57 */ "np_arg ::= NOT np_arg",
 /*  58 */ "np_arg ::= lambda",
 /*  59 */ "np_arg_list_start ::=",
 /*  60 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  61 */ "np_arg_list_elems ::= np_arg",
 /*  62 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  63 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  64 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  65 */ "np_opt_kw_arg_list ::=",
 /*  66 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  67 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  68 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  69 */ "np_recv ::= lit",
 /*  70 */ "np_recv ::= ID LP RP",
 /*  71 */ "np_recv ::= ID LP np_arg_list RP",
 /*  72 */ "np_recv ::= np_recv DOT ID",
 /*  73 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  74 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  75 */ "np_recv ::= np_recv DCOLON ID",
 /*  76 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  77 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  78 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  79 */ "np_recv ::= lambda",
 /*  80 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  81 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  82 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  83 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  84 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  85 */ "s2 ::= ID np_arg_list",
 /*  86 */ "s2 ::= np_recv CAST np_arg",
 /*  87 */ "s2 ::= np_recv OP0 np_arg",
 /*  88 */ "s2 ::= np_recv OP1 np_arg",
 /*  89 */ "s2 ::= np_recv OP2 np_arg",
 /*  90 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  91 */ "s2 ::= np_recv",
 /*  92 */ "s2 ::= NOT s2",
 /*  93 */ "stmt ::= s2",
 /*  94 */ "lambda_start ::= LB",
 /*  95 */ "lambda_args ::= PIPE ID PIPE",
 /*  96 */ "lambda_args ::=",
 /*  97 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  98 */ "stmt ::= IF s2 fin seq fin END",
 /*  99 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 100 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 101 */ "stmt ::= IMPORT ID",
 /* 102 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 103 */ "stmt ::= ID EQUAL s2",
 /* 104 */ "stmt ::= ID OP1_SET s2",
 /* 105 */ "stmt ::= ID OP0_SET s2",
 /* 106 */ "stmt ::= IVAR EQUAL s2",
 /* 107 */ "stmt ::= IVAR OP1_SET s2",
 /* 108 */ "stmt ::= IVAR OP0_SET s2",
 /* 109 */ "stmt ::= RAISE s2",
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
  { 47, 3 },
  { 49, 3 },
  { 49, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 56, 1 },
  { 56, 1 },
  { 48, 0 },
  { 48, 2 },
  { 50, 1 },
  { 50, 2 },
  { 51, 2 },
  { 51, 1 },
  { 57, 2 },
  { 57, 1 },
  { 58, 3 },
  { 58, 1 },
  { 59, 1 },
  { 60, 3 },
  { 53, 4 },
  { 53, 6 },
  { 62, 1 },
  { 63, 3 },
  { 64, 1 },
  { 64, 3 },
  { 65, 3 },
  { 65, 1 },
  { 66, 0 },
  { 66, 3 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 67, 1 },
  { 54, 5 },
  { 54, 5 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 69, 1 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 5 },
  { 69, 6 },
  { 69, 3 },
  { 69, 4 },
  { 69, 6 },
  { 69, 7 },
  { 69, 2 },
  { 69, 1 },
  { 72, 0 },
  { 73, 3 },
  { 73, 1 },
  { 74, 3 },
  { 75, 3 },
  { 75, 1 },
  { 76, 0 },
  { 76, 2 },
  { 70, 3 },
  { 70, 2 },
  { 77, 1 },
  { 77, 3 },
  { 77, 4 },
  { 77, 3 },
  { 77, 5 },
  { 77, 6 },
  { 77, 3 },
  { 77, 4 },
  { 77, 6 },
  { 77, 7 },
  { 77, 1 },
  { 77, 3 },
  { 77, 3 },
  { 77, 4 },
  { 61, 4 },
  { 61, 5 },
  { 61, 2 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 1 },
  { 61, 2 },
  { 55, 1 },
  { 78, 1 },
  { 79, 3 },
  { 79, 0 },
  { 71, 4 },
  { 55, 6 },
  { 55, 6 },
  { 55, 6 },
  { 55, 2 },
  { 55, 9 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 3 },
  { 55, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy128.a)); }
#line 1103 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy128.a = S->seq(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1109 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 44: /* np_arg ::= lit */ yytestcase(yyruleno==44);
      case 58: /* np_arg ::= lambda */ yytestcase(yyruleno==58);
      case 69: /* np_recv ::= lit */ yytestcase(yyruleno==69);
      case 79: /* np_recv ::= lambda */ yytestcase(yyruleno==79);
      case 91: /* s2 ::= np_recv */ yytestcase(yyruleno==91);
      case 93: /* stmt ::= s2 */ yytestcase(yyruleno==93);
#line 33 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[0].minor.yy128.a; }
#line 1124 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1129 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[-2].minor.yy128.a; }
#line 1135 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy128.a);
             }
#line 1142 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a);
             }
#line 1149 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1154 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 71 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1159 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST ID */
#line 72 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, S->named(yymsp[0].minor.yy0.s)); }
#line 1164 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= SQUARE */ yytestcase(yyruleno==33);
#line 80 "vm/parser.lm"
{ yygotominor.yy128.s = yymsp[0].minor.yy0.s; }
#line 1172 "vm/parser.c.inc"
        break;
      case 34: /* def ::= def_start def_name def_args fin def_body */
#line 86 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, yymsp[0].minor.yy128.a);
            }
#line 1179 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin END */
#line 89 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, S->ast_nil());
            }
#line 1186 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= NUM */
#line 93 "vm/parser.lm"
{ yygotominor.yy128.a = S->number(yymsp[0].minor.yy0.i); }
#line 1191 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NIL */
#line 94 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_nil();  }
#line 1196 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= TRUE */
#line 95 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_true();  }
#line 1201 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= FALSE */
#line 96 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_false(); }
#line 1206 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= SELF */
#line 97 "vm/parser.lm"
{ yygotominor.yy128.a = S->self(); }
#line 1211 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= ID */
#line 98 "vm/parser.lm"
{ yygotominor.yy128.a = S->named(yymsp[0].minor.yy0.s); }
#line 1216 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= IVAR */
#line 99 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1221 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= LITSTR */
#line 100 "vm/parser.lm"
{ yygotominor.yy128.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1226 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg OP0 np_arg */
      case 46: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==46);
      case 87: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==87);
      case 88: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==88);
#line 104 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1234 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg OP2 np_arg */
      case 89: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==89);
#line 108 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1240 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg CAST np_arg */
      case 86: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==86);
#line 110 "vm/parser.lm"
{ yygotominor.yy128.a = S->cast(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1246 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg NEQUAL np_arg */
      case 90: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==90);
#line 112 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a)); }
#line 1252 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DOT ID */
      case 72: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==72);
#line 113 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy0.s); }
#line 1258 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT ID LP RP */
      case 73: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==73);
#line 114 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy0.s); }
#line 1264 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 74: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==74);
#line 116 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-5].minor.yy128.a, yymsp[-3].minor.yy0.s); }
#line 1270 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DCOLON ID */
      case 75: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==75);
#line 117 "vm/parser.lm"
{ yygotominor.yy128.a = S->dcolon(yymsp[-2].minor.yy128.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1276 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 76: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==76);
#line 119 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-3].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1282 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 77: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==77);
#line 121 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-5].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1288 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 78: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==78);
#line 123 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-6].minor.yy128.a, yymsp[-3].minor.yy128.a); }
#line 1294 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= NOT np_arg */
      case 92: /* s2 ::= NOT s2 */ yytestcase(yyruleno==92);
#line 124 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(yymsp[0].minor.yy128.a); }
#line 1300 "vm/parser.c.inc"
        break;
      case 59: /* np_arg_list_start ::= */
#line 127 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1305 "vm/parser.c.inc"
        break;
      case 60: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 61: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==61);
#line 128 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy128.a); }
#line 1311 "vm/parser.c.inc"
        break;
      case 62: /* np_kw_arg ::= ID EQUAL np_arg */
#line 131 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1316 "vm/parser.c.inc"
        break;
      case 70: /* np_recv ::= ID LP RP */
#line 143 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1321 "vm/parser.c.inc"
        break;
      case 71: /* np_recv ::= ID LP np_arg_list RP */
#line 144 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1326 "vm/parser.c.inc"
        break;
      case 80: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 156 "vm/parser.lm"
{ yygotominor.yy128.a = S->tuple(); }
#line 1331 "vm/parser.c.inc"
        break;
      case 81: /* np_recv ::= DICT_START np_arg_list RB */
#line 157 "vm/parser.lm"
{ yygotominor.yy128.a = S->dict(); }
#line 1336 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= np_recv LSB np_arg_list RSB */
#line 159 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-3].minor.yy128.a, "[]"); }
#line 1341 "vm/parser.c.inc"
        break;
      case 83: /* s2 ::= np_recv DOT ID np_arg_list */
#line 161 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-3].minor.yy128.a, yymsp[-1].minor.yy0.s); }
#line 1346 "vm/parser.c.inc"
        break;
      case 84: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 163 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-4].minor.yy128.a, yymsp[-1].minor.yy128.a); }
#line 1351 "vm/parser.c.inc"
        break;
      case 85: /* s2 ::= ID np_arg_list */
#line 164 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1356 "vm/parser.c.inc"
        break;
      case 94: /* lambda_start ::= LB */
#line 178 "vm/parser.lm"
{ S->start_lambda(); }
#line 1361 "vm/parser.c.inc"
        break;
      case 95: /* lambda_args ::= PIPE ID PIPE */
#line 180 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1366 "vm/parser.c.inc"
        break;
      case 97: /* lambda ::= lambda_start lambda_args seq RB */
#line 183 "vm/parser.lm"
{ yygotominor.yy128.a = S->lambda(yymsp[-1].minor.yy128.a); }
#line 1371 "vm/parser.c.inc"
        break;
      case 98: /* stmt ::= IF s2 fin seq fin END */
#line 187 "vm/parser.lm"
{ yygotominor.yy128.a = S->if_cond(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1376 "vm/parser.c.inc"
        break;
      case 99: /* stmt ::= UNLESS s2 fin seq fin END */
#line 188 "vm/parser.lm"
{ yygotominor.yy128.a = S->unless(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1381 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= WHILE s2 fin seq fin END */
#line 189 "vm/parser.lm"
{ yygotominor.yy128.a = S->while_(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1386 "vm/parser.c.inc"
        break;
      case 101: /* stmt ::= IMPORT ID */
#line 193 "vm/parser.lm"
{ yygotominor.yy128.a = S->import(yymsp[0].minor.yy0.s); }
#line 1391 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 195 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_try(yymsp[-6].minor.yy128.a, yymsp[-2].minor.yy128.a);
            }
#line 1398 "vm/parser.c.inc"
        break;
      case 103: /* stmt ::= ID EQUAL s2 */
#line 199 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1403 "vm/parser.c.inc"
        break;
      case 104: /* stmt ::= ID OP1_SET s2 */
      case 105: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==105);
#line 200 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1409 "vm/parser.c.inc"
        break;
      case 106: /* stmt ::= IVAR EQUAL s2 */
#line 202 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1414 "vm/parser.c.inc"
        break;
      case 107: /* stmt ::= IVAR OP1_SET s2 */
      case 108: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==108);
#line 204 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1420 "vm/parser.c.inc"
        break;
      case 109: /* stmt ::= RAISE s2 */
#line 207 "vm/parser.lm"
{ yygotominor.yy128.a = S->raise(yymsp[0].minor.yy128.a); }
#line 1425 "vm/parser.c.inc"
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
      /* (63) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==63);
      /* (64) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==64);
      /* (65) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==65);
      /* (66) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==66);
      /* (67) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==67);
      /* (68) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==68);
      /* (96) lambda_args ::= */ yytestcase(yyruleno==96);
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
#line 1514 "vm/parser.c.inc"
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
