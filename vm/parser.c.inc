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
#define YYNOCODE 71
#define YYACTIONTYPE unsigned char
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
#define YYNSTATE 142
#define YYNRULE 74
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
#define YY_ACTTAB_COUNT (637)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   136,  137,  135,   84,   72,  131,  133,   65,   78,   77,
 /*    10 */   126,  125,  124,  123,  122,   71,   81,  118,   26,   27,
 /*    20 */    24,   25,   23,  110,  142,  106,  110,   30,   29,   70,
 /*    30 */    43,   20,  136,   39,  135,  134,   72,   53,  133,   24,
 /*    40 */    25,   23,  126,  125,  124,  123,  122,   71,   81,  118,
 /*    50 */    26,   27,   24,   25,   23,   87,    5,  106,   23,   30,
 /*    60 */    29,   70,   43,  129,   88,    7,  135,   59,   72,   68,
 /*    70 */   133,   67,  117,   60,  126,  125,  124,  123,  122,   71,
 /*    80 */    81,  118,   47,  107,   46,   65,   78,   77,  132,  106,
 /*    90 */    94,   30,   29,   70,   43,  119,  136,  116,  135,   63,
 /*   100 */    72,   28,  133,  110,  117,   60,  126,  125,  124,  123,
 /*   110 */   122,   71,   81,  118,   47,  107,   46,  110,   33,  110,
 /*   120 */    89,  106,  110,   30,   29,   70,   43,  109,  136,   31,
 /*   130 */   136,  128,   72,  115,  111,   65,   78,   77,  126,  125,
 /*   140 */   124,  123,  122,   71,   81,  118,   99,  114,  117,   61,
 /*   150 */   117,   36,   48,  106,   73,   30,   29,   70,   43,  105,
 /*   160 */   136,  117,   35,  104,   72,  217,    3,  102,   22,   21,
 /*   170 */   126,  125,  124,  123,  122,   71,   81,  118,   97,   96,
 /*   180 */   110,    4,   52,   51,   66,  106,  130,   30,   29,   70,
 /*   190 */    43,    6,  136,   18,   98,  103,   72,   13,  113,   75,
 /*   200 */   108,   38,  126,  125,  124,  123,  122,   71,   81,  118,
 /*   210 */    74,   12,   17,   16,  136,    9,   15,  106,   72,   30,
 /*   220 */    29,   70,   43,    8,  126,  125,  124,  123,  122,   71,
 /*   230 */    81,  118,   80,   95,   14,    2,   64,   19,   11,  106,
 /*   240 */    10,   30,   29,   70,   43,   41,  136,    1,  218,  101,
 /*   250 */    72,  218,  218,  218,  218,  218,  126,  125,  124,  123,
 /*   260 */   122,   71,   81,  118,  218,  218,  218,  218,  136,  218,
 /*   270 */   218,  106,   72,   30,   29,   70,   43,  218,  126,  125,
 /*   280 */   124,  123,  122,   71,   81,  118,  218,  218,  218,  218,
 /*   290 */   218,  218,  218,  106,   72,   30,   29,   70,   43,  218,
 /*   300 */   126,  125,  124,  123,  122,   71,   81,  118,  218,  218,
 /*   310 */   218,  218,  218,  218,  218,  106,  218,   30,   29,   70,
 /*   320 */    43,   54,  218,  218,   92,  140,  139,  138,   57,   86,
 /*   330 */    91,   59,   85,  117,   60,  218,  117,   60,   76,  218,
 /*   340 */   112,  218,  218,   47,  107,   46,   47,  107,   46,   54,
 /*   350 */   218,  218,   92,  140,  139,  138,   62,   86,   90,   59,
 /*   360 */    85,  117,   60,  218,  117,   60,  218,  218,  218,  218,
 /*   370 */   218,   47,  107,   46,   47,  107,   46,  218,   32,  218,
 /*   380 */   218,   92,  140,  139,  138,   83,   86,  218,   59,   85,
 /*   390 */   117,   60,  218,  117,   60,  218,  218,  218,  218,  218,
 /*   400 */    47,  107,   46,   47,  107,   46,  218,  218,  218,  141,
 /*   410 */   140,  139,  138,  218,   86,  218,   59,   85,  218,  218,
 /*   420 */   218,  117,   60,  218,  218,  218,  218,  218,  121,  218,
 /*   430 */   218,   47,  107,   46,  126,  125,  124,  123,  122,  120,
 /*   440 */    81,  118,  218,  218,   79,  218,  218,  218,  218,  106,
 /*   450 */   126,  125,  124,  123,  122,  120,   81,  118,  218,  218,
 /*   460 */   121,  218,  218,  218,  218,  106,  126,  125,  124,  123,
 /*   470 */   122,  120,   81,  118,   58,  218,  218,  218,  218,  117,
 /*   480 */    60,  218,   49,  218,   69,  218,  112,  218,  218,   47,
 /*   490 */   107,   46,  100,   50,  218,  218,   59,  218,   93,  100,
 /*   500 */    37,  117,   60,   59,  218,  218,  218,  218,  117,   60,
 /*   510 */   218,   47,  107,   46,  218,  218,  218,  218,   47,  107,
 /*   520 */    46,  100,   45,  218,  218,   59,  218,  218,  100,   44,
 /*   530 */   117,   60,   59,  218,  218,  218,  218,  117,   60,  218,
 /*   540 */    47,  107,   46,  218,  218,  218,  218,   47,  107,   46,
 /*   550 */   100,   42,  218,  218,   59,  218,  218,  100,   40,  117,
 /*   560 */    60,   59,  218,  218,  218,  218,  117,   60,  218,   47,
 /*   570 */   107,   46,  218,  218,   82,  218,   47,  107,   46,  117,
 /*   580 */    60,  127,  218,  218,  218,  218,  117,   60,  218,   47,
 /*   590 */   107,   46,  218,  218,   56,  218,   47,  107,   46,  117,
 /*   600 */    60,   55,  218,  218,  218,  218,  117,   60,  218,   47,
 /*   610 */   107,   46,  218,  218,  218,  218,   47,  107,   46,   34,
 /*   620 */   218,  218,  218,  218,  117,   60,  218,  218,  218,  218,
 /*   630 */   218,  218,  218,  218,   47,  107,   46,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    7,    8,   13,   10,   15,   12,   24,   25,   26,
 /*    10 */    16,   17,   18,   19,   20,   21,   22,   23,    1,    2,
 /*    20 */     3,    4,    5,    6,    0,   31,    6,   33,   34,   35,
 /*    30 */    36,   11,    6,   10,    8,    9,   10,   10,   12,    3,
 /*    40 */     4,    5,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    50 */     1,    2,    3,    4,    5,   42,   43,   31,    5,   33,
 /*    60 */    34,   35,   36,   47,    6,   58,    8,   51,   10,   62,
 /*    70 */    12,   64,   56,   57,   16,   17,   18,   19,   20,   21,
 /*    80 */    22,   23,   66,   67,   68,   24,   25,   26,   10,   31,
 /*    90 */    29,   33,   34,   35,   36,   10,    6,   15,    8,   51,
 /*   100 */    10,   10,   12,    6,   56,   57,   16,   17,   18,   19,
 /*   110 */    20,   21,   22,   23,   66,   67,   68,    6,   27,    6,
 /*   120 */     7,   31,    6,   33,   34,   35,   36,   30,    6,   28,
 /*   130 */     6,    9,   10,   10,   10,   24,   25,   26,   16,   17,
 /*   140 */    18,   19,   20,   21,   22,   23,   30,   10,   56,   57,
 /*   150 */    56,   57,   13,   31,   10,   33,   34,   35,   36,   32,
 /*   160 */     6,   56,   57,    9,   10,   39,   40,   10,   28,   28,
 /*   170 */    16,   17,   18,   19,   20,   21,   22,   23,   15,   15,
 /*   180 */     6,   43,   14,   55,   54,   31,   10,   33,   34,   35,
 /*   190 */    36,   43,    6,   43,   60,    9,   10,   13,   63,   10,
 /*   200 */    10,   65,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   210 */    32,   69,   43,   43,    6,   43,   43,   31,   10,   33,
 /*   220 */    34,   35,   36,   43,   16,   17,   18,   19,   20,   21,
 /*   230 */    22,   23,   14,   56,   43,   43,   43,   43,   43,   31,
 /*   240 */    43,   33,   34,   35,   36,   37,    6,   43,   70,    9,
 /*   250 */    10,   70,   70,   70,   70,   70,   16,   17,   18,   19,
 /*   260 */    20,   21,   22,   23,   70,   70,   70,   70,    6,   70,
 /*   270 */    70,   31,   10,   33,   34,   35,   36,   70,   16,   17,
 /*   280 */    18,   19,   20,   21,   22,   23,   70,   70,   70,   70,
 /*   290 */    70,   70,   70,   31,   10,   33,   34,   35,   36,   70,
 /*   300 */    16,   17,   18,   19,   20,   21,   22,   23,   70,   70,
 /*   310 */    70,   70,   70,   70,   70,   31,   70,   33,   34,   35,
 /*   320 */    36,   41,   70,   70,   44,   45,   46,   47,   51,   49,
 /*   330 */    50,   51,   52,   56,   57,   70,   56,   57,   61,   70,
 /*   340 */    63,   70,   70,   66,   67,   68,   66,   67,   68,   41,
 /*   350 */    70,   70,   44,   45,   46,   47,   51,   49,   50,   51,
 /*   360 */    52,   56,   57,   70,   56,   57,   70,   70,   70,   70,
 /*   370 */    70,   66,   67,   68,   66,   67,   68,   70,   41,   70,
 /*   380 */    70,   44,   45,   46,   47,   51,   49,   70,   51,   52,
 /*   390 */    56,   57,   70,   56,   57,   70,   70,   70,   70,   70,
 /*   400 */    66,   67,   68,   66,   67,   68,   70,   70,   70,   44,
 /*   410 */    45,   46,   47,   70,   49,   70,   51,   52,   70,   70,
 /*   420 */    70,   56,   57,   70,   70,   70,   70,   70,   10,   70,
 /*   430 */    70,   66,   67,   68,   16,   17,   18,   19,   20,   21,
 /*   440 */    22,   23,   70,   70,   10,   70,   70,   70,   70,   31,
 /*   450 */    16,   17,   18,   19,   20,   21,   22,   23,   70,   70,
 /*   460 */    10,   70,   70,   70,   70,   31,   16,   17,   18,   19,
 /*   470 */    20,   21,   22,   23,   51,   70,   70,   70,   70,   56,
 /*   480 */    57,   70,   59,   70,   61,   70,   63,   70,   70,   66,
 /*   490 */    67,   68,   47,   48,   70,   70,   51,   70,   53,   47,
 /*   500 */    48,   56,   57,   51,   70,   70,   70,   70,   56,   57,
 /*   510 */    70,   66,   67,   68,   70,   70,   70,   70,   66,   67,
 /*   520 */    68,   47,   48,   70,   70,   51,   70,   70,   47,   48,
 /*   530 */    56,   57,   51,   70,   70,   70,   70,   56,   57,   70,
 /*   540 */    66,   67,   68,   70,   70,   70,   70,   66,   67,   68,
 /*   550 */    47,   48,   70,   70,   51,   70,   70,   47,   48,   56,
 /*   560 */    57,   51,   70,   70,   70,   70,   56,   57,   70,   66,
 /*   570 */    67,   68,   70,   70,   51,   70,   66,   67,   68,   56,
 /*   580 */    57,   51,   70,   70,   70,   70,   56,   57,   70,   66,
 /*   590 */    67,   68,   70,   70,   51,   70,   66,   67,   68,   56,
 /*   600 */    57,   51,   70,   70,   70,   70,   56,   57,   70,   66,
 /*   610 */    67,   68,   70,   70,   70,   70,   66,   67,   68,   51,
 /*   620 */    70,   70,   70,   70,   56,   57,   70,   70,   70,   70,
 /*   630 */    70,   70,   70,   70,   66,   67,   68,
};
#define YY_SHIFT_USE_DFLT (-18)
#define YY_SHIFT_COUNT (87)
#define YY_SHIFT_MIN   (-17)
#define YY_SHIFT_MAX   (450)
static const short yy_shift_ofst[] = {
 /*     0 */   -18,   90,   90,   58,   26,   -6,  262,  434,  262,  262,
 /*    10 */   262,  262,  284,  434,  240,  208,  186,  154,  122,  262,
 /*    20 */   418,  418,  418,  418,  418,  418,  418,  418,  218,  450,
 /*    30 */   450,  450,  113,  450,   17,  111,  111,  116,   97,   20,
 /*    40 */   174,  174,  174,  174,  174,  174,  178,  190,  189,  184,
 /*    50 */   174,  174,  176,  168,  174,   49,   49,   49,   49,   49,
 /*    60 */    61,  -17,   36,   36,  124,   91,  -10,  164,  163,  139,
 /*    70 */   157,  141,  140,  127,  144,  101,  139,  137,  123,  101,
 /*    80 */    82,   85,   53,   53,   78,   27,   23,   24,
};
#define YY_REDUCE_USE_DFLT (-1)
#define YY_REDUCE_COUNT (54)
#define YY_REDUCE_MIN   (0)
#define YY_REDUCE_MAX   (568)
static const short yy_reduce_ofst[] = {
 /*     0 */   126,  308,  280,  337,  365,  365,  445,  423,  510,  503,
 /*    10 */   481,  474,  452,  277,   16,   16,   16,   16,   16,   16,
 /*    20 */   568,  550,  543,  530,  523,  334,  305,   48,    7,  105,
 /*    30 */    94,   92,   13,  177,  204,  197,  195,  194,  193,  192,
 /*    40 */   191,  180,  173,  172,  170,  169,  142,  136,  135,  134,
 /*    50 */   150,  148,  130,  128,  138,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   148,  216,  216,  216,  216,  216,  216,  216,  216,  216,
 /*    10 */   216,  216,  216,  216,  216,  216,  216,  216,  216,  216,
 /*    20 */   216,  216,  216,  216,  216,  216,  216,  216,  182,  216,
 /*    30 */   216,  216,  216,  216,  216,  216,  216,  216,  216,  216,
 /*    40 */   216,  216,  216,  216,  216,  216,  207,  216,  216,  188,
 /*    50 */   216,  216,  216,  164,  216,  215,  214,  186,  187,  209,
 /*    60 */   203,  194,  168,  167,  216,  216,  216,  216,  216,  197,
 /*    70 */   216,  178,  177,  216,  216,  216,  189,  216,  216,  177,
 /*    80 */   185,  216,  170,  169,  216,  216,  216,  216,  149,  150,
 /*    90 */   159,  158,  144,  166,  201,  191,  198,  193,  190,  208,
 /*   100 */   155,  213,  212,  211,  210,  206,  205,  204,  200,  202,
 /*   110 */   153,  199,  196,  195,  184,  183,  192,  181,  180,  179,
 /*   120 */   178,  177,  176,  175,  174,  173,  172,  171,  161,  154,
 /*   130 */   163,  165,  162,  160,  157,  156,  152,  151,  147,  146,
 /*   140 */   145,  143,
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
  "$",             "PLUS",          "MINUS",         "DIVIDE",      
  "TIMES",         "DEQUAL",        "FIN",           "EOF",         
  "CLASS",         "END",           "ID",            "LT",          
  "DEF",           "COMMA",         "LP",            "RP",          
  "NUM",           "NIL",           "TRUE",          "FALSE",       
  "SELF",          "IVAR",          "COLON",         "LITSTR",      
  "DOT",           "ATTR",          "DCOLON",        "DOLLAR",      
  "EQUAL",         "CASCADE",       "RB",            "LB",          
  "PIPE",          "IF",            "UNLESS",        "IMPORT",      
  "TRY",           "RESCUE",        "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "seq",           "class_start",   "class_body",    "expr",        
  "def_start",     "def_body",      "id_list",       "def_args",    
  "sexpr",         "send",          "arg_list_start",  "arg_list_elems",
  "opt_kw_arg_list",  "kw_arg_list_elems",  "arg_list",      "kw_arg",      
  "kw_arg_list",   "message_seq",   "cascade_start",  "cascade",     
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
 /*   4 */ "l1e ::= def",
 /*   5 */ "l1e ::= stmt",
 /*   6 */ "opt_fin ::=",
 /*   7 */ "opt_fin ::= opt_fin FIN",
 /*   8 */ "last_fin ::= EOF",
 /*   9 */ "last_fin ::= fin EOF",
 /*  10 */ "fin ::= fin FIN",
 /*  11 */ "fin ::= FIN",
 /*  12 */ "seq ::= seq fin stmt",
 /*  13 */ "seq ::= stmt",
 /*  14 */ "class_start ::= CLASS",
 /*  15 */ "class_body ::= l1 fin END",
 /*  16 */ "class ::= class_start ID fin class_body",
 /*  17 */ "class ::= class_start ID LT expr fin class_body",
 /*  18 */ "def_start ::= DEF",
 /*  19 */ "def_body ::= seq fin END",
 /*  20 */ "id_list ::= id_list COMMA ID",
 /*  21 */ "id_list ::= ID",
 /*  22 */ "def_args ::=",
 /*  23 */ "def_args ::= LP id_list RP",
 /*  24 */ "def ::= def_start ID def_args fin def_body",
 /*  25 */ "expr ::= expr MINUS expr",
 /*  26 */ "expr ::= expr PLUS expr",
 /*  27 */ "expr ::= expr TIMES expr",
 /*  28 */ "expr ::= expr DIVIDE expr",
 /*  29 */ "expr ::= expr DEQUAL expr",
 /*  30 */ "sexpr ::= NUM",
 /*  31 */ "sexpr ::= NIL",
 /*  32 */ "sexpr ::= TRUE",
 /*  33 */ "sexpr ::= FALSE",
 /*  34 */ "sexpr ::= SELF",
 /*  35 */ "sexpr ::= ID",
 /*  36 */ "sexpr ::= IVAR",
 /*  37 */ "sexpr ::= COLON ID",
 /*  38 */ "sexpr ::= LITSTR",
 /*  39 */ "send ::= sexpr",
 /*  40 */ "send ::= send DOT ID",
 /*  41 */ "send ::= send ATTR ID",
 /*  42 */ "send ::= send DCOLON ID",
 /*  43 */ "arg_list_start ::= LP",
 /*  44 */ "arg_list_elems ::= arg_list_elems COMMA expr",
 /*  45 */ "arg_list_elems ::= expr",
 /*  46 */ "opt_kw_arg_list ::=",
 /*  47 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  48 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  49 */ "send ::= send DOT DOLLAR sexpr",
 /*  50 */ "send ::= send DOT ID LP RP",
 /*  51 */ "send ::= send DOT ID arg_list RP",
 /*  52 */ "kw_arg ::= ID EQUAL send",
 /*  53 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  54 */ "kw_arg_list_elems ::= kw_arg",
 /*  55 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  56 */ "send ::= send DOT ID kw_arg_list RP",
 /*  57 */ "message_seq ::= message_seq fin ID",
 /*  58 */ "message_seq ::= ID",
 /*  59 */ "cascade_start ::= send CASCADE",
 /*  60 */ "cascade ::= cascade_start message_seq RB",
 /*  61 */ "cascade ::= send",
 /*  62 */ "expr ::= cascade",
 /*  63 */ "lambda_start ::= LB",
 /*  64 */ "lambda_args ::= PIPE ID PIPE",
 /*  65 */ "lambda_args ::=",
 /*  66 */ "expr ::= lambda_start lambda_args seq RB",
 /*  67 */ "stmt ::= expr",
 /*  68 */ "stmt ::= IF send fin seq fin END",
 /*  69 */ "stmt ::= UNLESS send fin seq fin END",
 /*  70 */ "stmt ::= IMPORT ID",
 /*  71 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  72 */ "stmt ::= ID EQUAL expr",
 /*  73 */ "stmt ::= IVAR EQUAL expr",
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
  { 39, 3 },
  { 41, 3 },
  { 41, 1 },
  { 44, 1 },
  { 44, 1 },
  { 44, 1 },
  { 40, 0 },
  { 40, 2 },
  { 42, 1 },
  { 42, 2 },
  { 43, 2 },
  { 43, 1 },
  { 48, 3 },
  { 48, 1 },
  { 49, 1 },
  { 50, 3 },
  { 45, 4 },
  { 45, 6 },
  { 52, 1 },
  { 53, 3 },
  { 54, 3 },
  { 54, 1 },
  { 55, 0 },
  { 55, 3 },
  { 46, 5 },
  { 51, 3 },
  { 51, 3 },
  { 51, 3 },
  { 51, 3 },
  { 51, 3 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 2 },
  { 56, 1 },
  { 57, 1 },
  { 57, 3 },
  { 57, 3 },
  { 57, 3 },
  { 58, 1 },
  { 59, 3 },
  { 59, 1 },
  { 60, 0 },
  { 60, 2 },
  { 62, 3 },
  { 57, 4 },
  { 57, 5 },
  { 57, 5 },
  { 63, 3 },
  { 61, 3 },
  { 61, 1 },
  { 64, 2 },
  { 57, 5 },
  { 65, 3 },
  { 65, 1 },
  { 66, 2 },
  { 67, 3 },
  { 67, 1 },
  { 51, 1 },
  { 68, 1 },
  { 69, 3 },
  { 69, 0 },
  { 51, 4 },
  { 47, 1 },
  { 47, 6 },
  { 47, 6 },
  { 47, 2 },
  { 47, 9 },
  { 47, 3 },
  { 47, 3 },
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
#line 28 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy88.a)); }
#line 962 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 30 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 968 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 39: /* send ::= sexpr */ yytestcase(yyruleno==39);
      case 61: /* cascade ::= send */ yytestcase(yyruleno==61);
      case 62: /* expr ::= cascade */ yytestcase(yyruleno==62);
      case 67: /* stmt ::= expr */ yytestcase(yyruleno==67);
#line 31 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 981 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 49 "vm/parser.lm"
{ S->start_class(); }
#line 986 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 19: /* def_body ::= seq fin END */ yytestcase(yyruleno==19);
#line 50 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 992 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 52 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 999 "vm/parser.c.inc"
        break;
      case 17: /* class ::= class_start ID LT expr fin class_body */
#line 56 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1006 "vm/parser.c.inc"
        break;
      case 18: /* def_start ::= DEF */
#line 60 "vm/parser.lm"
{ S->start_def(); }
#line 1011 "vm/parser.c.inc"
        break;
      case 20: /* id_list ::= id_list COMMA ID */
      case 21: /* id_list ::= ID */ yytestcase(yyruleno==21);
#line 63 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1017 "vm/parser.c.inc"
        break;
      case 24: /* def ::= def_start ID def_args fin def_body */
#line 69 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy88.a);
            }
#line 1024 "vm/parser.c.inc"
        break;
      case 25: /* expr ::= expr MINUS expr */
#line 73 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("-", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1029 "vm/parser.c.inc"
        break;
      case 26: /* expr ::= expr PLUS expr */
#line 74 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("+", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1034 "vm/parser.c.inc"
        break;
      case 27: /* expr ::= expr TIMES expr */
#line 75 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("*", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1039 "vm/parser.c.inc"
        break;
      case 28: /* expr ::= expr DIVIDE expr */
#line 76 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("/", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1044 "vm/parser.c.inc"
        break;
      case 29: /* expr ::= expr DEQUAL expr */
#line 77 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1049 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= NUM */
#line 79 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1054 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= NIL */
#line 80 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1059 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= TRUE */
#line 81 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1064 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= FALSE */
#line 82 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1069 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= SELF */
#line 83 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1074 "vm/parser.c.inc"
        break;
      case 35: /* sexpr ::= ID */
#line 84 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1079 "vm/parser.c.inc"
        break;
      case 36: /* sexpr ::= IVAR */
#line 85 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1084 "vm/parser.c.inc"
        break;
      case 37: /* sexpr ::= COLON ID */
      case 38: /* sexpr ::= LITSTR */ yytestcase(yyruleno==38);
#line 86 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1090 "vm/parser.c.inc"
        break;
      case 40: /* send ::= send DOT ID */
#line 90 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 1095 "vm/parser.c.inc"
        break;
      case 41: /* send ::= send ATTR ID */
#line 91 "vm/parser.lm"
{ yygotominor.yy88.a = S->attr(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 1100 "vm/parser.c.inc"
        break;
      case 42: /* send ::= send DCOLON ID */
#line 92 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1105 "vm/parser.c.inc"
        break;
      case 43: /* arg_list_start ::= LP */
#line 96 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1110 "vm/parser.c.inc"
        break;
      case 44: /* arg_list_elems ::= arg_list_elems COMMA expr */
      case 45: /* arg_list_elems ::= expr */ yytestcase(yyruleno==45);
#line 97 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1116 "vm/parser.c.inc"
        break;
      case 49: /* send ::= send DOT DOLLAR sexpr */
#line 105 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-3].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1121 "vm/parser.c.inc"
        break;
      case 50: /* send ::= send DOT ID LP RP */
#line 107 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1126 "vm/parser.c.inc"
        break;
      case 51: /* send ::= send DOT ID arg_list RP */
#line 108 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1131 "vm/parser.c.inc"
        break;
      case 52: /* kw_arg ::= ID EQUAL send */
#line 112 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1136 "vm/parser.c.inc"
        break;
      case 56: /* send ::= send DOT ID kw_arg_list RP */
#line 119 "vm/parser.lm"
{
              yygotominor.yy88.a = S->call_kw_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s);
            }
#line 1143 "vm/parser.c.inc"
        break;
      case 57: /* message_seq ::= message_seq fin ID */
      case 58: /* message_seq ::= ID */ yytestcase(yyruleno==58);
#line 125 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1149 "vm/parser.c.inc"
        break;
      case 59: /* cascade_start ::= send CASCADE */
#line 128 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy88.a); }
#line 1154 "vm/parser.c.inc"
        break;
      case 60: /* cascade ::= cascade_start message_seq RB */
#line 129 "vm/parser.lm"
{ yygotominor.yy88.a = S->end_cascade(); }
#line 1159 "vm/parser.c.inc"
        break;
      case 63: /* lambda_start ::= LB */
#line 137 "vm/parser.lm"
{ S->start_lambda(); }
#line 1164 "vm/parser.c.inc"
        break;
      case 64: /* lambda_args ::= PIPE ID PIPE */
#line 139 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1169 "vm/parser.c.inc"
        break;
      case 66: /* expr ::= lambda_start lambda_args seq RB */
#line 142 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1174 "vm/parser.c.inc"
        break;
      case 68: /* stmt ::= IF send fin seq fin END */
#line 150 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1179 "vm/parser.c.inc"
        break;
      case 69: /* stmt ::= UNLESS send fin seq fin END */
#line 151 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1184 "vm/parser.c.inc"
        break;
      case 70: /* stmt ::= IMPORT ID */
#line 155 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1189 "vm/parser.c.inc"
        break;
      case 71: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 157 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1196 "vm/parser.c.inc"
        break;
      case 72: /* stmt ::= ID EQUAL expr */
#line 161 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1201 "vm/parser.c.inc"
        break;
      case 73: /* stmt ::= IVAR EQUAL expr */
#line 162 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1206 "vm/parser.c.inc"
        break;
      default:
      /* (6) opt_fin ::= */ yytestcase(yyruleno==6);
      /* (7) opt_fin ::= opt_fin FIN */ yytestcase(yyruleno==7);
      /* (8) last_fin ::= EOF */ yytestcase(yyruleno==8);
      /* (9) last_fin ::= fin EOF */ yytestcase(yyruleno==9);
      /* (10) fin ::= fin FIN */ yytestcase(yyruleno==10);
      /* (11) fin ::= FIN */ yytestcase(yyruleno==11);
      /* (22) def_args ::= */ yytestcase(yyruleno==22);
      /* (23) def_args ::= LP id_list RP */ yytestcase(yyruleno==23);
      /* (46) opt_kw_arg_list ::= */ yytestcase(yyruleno==46);
      /* (47) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==47);
      /* (48) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==48);
      /* (53) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==53);
      /* (54) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==54);
      /* (55) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==55);
      /* (65) lambda_args ::= */ yytestcase(yyruleno==65);
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
#line 21 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1289 "vm/parser.c.inc"
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
