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
#define YYNOCODE 70
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy34;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 171
#define YYNRULE 92
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
#define YY_ACTTAB_COUNT (723)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    25,   43,  166,  165,  164,   33,  162,   82,   38,   96,
 /*    10 */   160,   18,  171,  153,  152,  151,  150,  149,   90,  146,
 /*    20 */     4,   34,   33,  139,   82,  117,   24,   23,   85,   48,
 /*    30 */    70,   22,   25,  159,  166,  165,  166,  165,  162,  161,
 /*    40 */    38,  158,  160,   20,   82,  153,  152,  151,  150,  149,
 /*    50 */    90,  146,   61,  166,  165,  139,  104,    5,   24,   23,
 /*    60 */    85,   48,  117,   22,   25,   36,  166,  165,  101,   94,
 /*    70 */   162,   18,   38,  143,  160,  157,  115,  153,  152,  151,
 /*    80 */   150,  149,   90,  146,  166,  165,  106,  139,   97,  141,
 /*    90 */    24,   23,   85,   48,   40,   22,   25,   91,  166,  165,
 /*   100 */    63,  166,  165,  154,   38,   60,   62,  264,    3,  153,
 /*   110 */   152,  151,  150,  149,   90,  146,   89,  138,   18,  139,
 /*   120 */   127,    6,   24,   23,   85,   48,  117,   22,   25,   26,
 /*   130 */   166,  165,   88,   19,   18,  122,   38,   87,  120,   18,
 /*   140 */    69,  153,  152,  151,  150,  149,   90,  146,  135,  132,
 /*   150 */   112,  139,  129,   15,   24,   23,   85,   48,  117,   22,
 /*   160 */    25,   10,  166,  165,   14,   54,  117,  121,   38,  117,
 /*   170 */    64,  156,   17,  153,  152,  151,  150,  149,   90,  146,
 /*   180 */    92,  101,   25,  139,  166,  165,   24,   23,   85,   48,
 /*   190 */    38,   22,  137,  114,   18,  153,  152,  151,  150,  149,
 /*   200 */    90,  146,    9,   84,  131,  139,   18,  117,   24,   23,
 /*   210 */    85,   48,   46,   22,   25,   66,  166,  165,   13,   95,
 /*   220 */     8,  119,   38,  117,  128,  117,   18,  153,  152,  151,
 /*   230 */   150,  149,   90,  146,  100,  144,   25,  139,  166,  165,
 /*   240 */    24,   23,   85,   48,   38,   22,   39,  142,  265,  153,
 /*   250 */   152,  151,  150,  149,   90,  146,   12,  136,   25,  139,
 /*   260 */   133,  117,   24,   23,   85,   48,   38,   22,  130,  265,
 /*   270 */   265,  153,  152,  151,  150,  149,   90,  146,  265,  265,
 /*   280 */   265,  139,  265,    7,   24,   23,   85,   48,  117,   22,
 /*   290 */    55,  265,  265,  109,  169,  168,  167,  163,  265,   11,
 /*   300 */   103,  108,  124,  102,  117,  265,  265,  134,   55,  265,
 /*   310 */   126,  109,  169,  168,  167,  163,   71,   68,  103,  107,
 /*   320 */   124,  102,  265,  265,  265,  134,   37,  265,  126,  109,
 /*   330 */   169,  168,  167,  105,   71,   68,  103,    1,  124,  102,
 /*   340 */   265,  265,  117,  134,  145,   72,  126,  140,  265,  221,
 /*   350 */   113,   67,   71,   68,   68,  265,    2,  221,  265,  265,
 /*   360 */    59,  117,  221,  221,  221,  221,  221,  221,  221,  265,
 /*   370 */    21,  265,  221,  170,  169,  168,  167,  163,  116,  163,
 /*   380 */   103,   53,  124,  102,  124,  265,  110,  134,  265,  134,
 /*   390 */   126,  265,  126,  221,  265,   16,   71,   68,   71,   68,
 /*   400 */   117,  221,  265,  265,   59,  265,  221,  221,  221,  221,
 /*   410 */   221,  221,  221,  221,  265,  265,  221,  265,  265,  265,
 /*   420 */   265,  221,  265,  265,   58,  265,  221,  221,  221,  221,
 /*   430 */   221,  221,  221,  221,  265,  265,  221,  265,  265,  265,
 /*   440 */   265,  221,  265,  265,   57,  265,  221,  221,  221,  221,
 /*   450 */   221,  221,  221,   31,  145,   78,  221,  140,  265,  265,
 /*   460 */   265,  148,  265,  265,   68,  265,  153,  152,  151,  150,
 /*   470 */   149,  147,  146,   31,  145,   80,  139,  140,  265,  265,
 /*   480 */   265,   99,  265,  265,   68,  265,  153,  152,  151,  150,
 /*   490 */   149,  147,  146,  265,  265,   41,  139,  265,  265,  265,
 /*   500 */   153,  152,  151,  150,  149,  147,  146,  265,  265,  148,
 /*   510 */   139,  265,  265,  265,  153,  152,  151,  150,  149,  147,
 /*   520 */   146,  265,  265,  116,  163,  265,   51,  265,  265,  124,
 /*   530 */   265,  265,  265,  265,  134,  116,  163,  126,   49,  116,
 /*   540 */   163,  124,   47,   71,   68,  124,  134,  265,  265,  126,
 /*   550 */   134,  116,  163,  126,   45,   71,   68,  124,  265,   71,
 /*   560 */    68,  265,  134,  145,   73,  126,  140,  265,   56,  113,
 /*   570 */    65,   71,   68,   68,  145,   83,  116,  140,  265,   42,
 /*   580 */   265,  265,  124,  265,   68,  265,  265,  134,  155,  163,
 /*   590 */   126,  265,  265,  265,  124,  265,   71,   68,  265,  134,
 /*   600 */   265,  265,  126,  265,  145,   98,  265,  140,   71,   68,
 /*   610 */    29,   30,   28,   27,   68,   81,  125,   35,   32,   34,
 /*   620 */    33,  134,   82,  265,  126,  265,  265,  265,  265,  123,
 /*   630 */    71,   68,  265,  265,  134,  265,   86,  126,  265,  265,
 /*   640 */    52,  265,   50,   71,   68,  134,  265,  134,  126,  265,
 /*   650 */   126,  265,  265,  265,   71,   68,   71,   68,  265,  265,
 /*   660 */   265,  265,  118,  265,  111,  265,   44,  134,  265,  134,
 /*   670 */   126,  134,  126,  265,  126,  265,   71,   68,   71,   68,
 /*   680 */    71,   68,  145,   79,  265,  140,  265,  145,   93,  265,
 /*   690 */   140,  265,   68,  265,  265,  145,   77,   68,  140,  265,
 /*   700 */   145,   76,  265,  140,  265,   68,  145,   75,  265,  140,
 /*   710 */    68,  265,  145,   74,  265,  140,   68,  265,  265,  265,
 /*   720 */   265,  265,   68,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,   13,    7,    8,    9,    4,   11,    6,   13,   59,
 /*    10 */    15,   61,    0,   18,   19,   20,   21,   22,   23,   24,
 /*    20 */    42,    3,    4,   28,    6,   47,   31,   32,   33,   34,
 /*    30 */    13,   36,    5,    7,    7,    8,    7,    8,   11,   12,
 /*    40 */    13,   13,   15,   14,    6,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   16,    7,    8,   28,   41,   42,   31,   32,
 /*    60 */    33,   34,   47,   36,    5,   26,    7,    8,   10,   59,
 /*    70 */    11,   61,   13,   17,   15,   17,   30,   18,   19,   20,
 /*    80 */    21,   22,   23,   24,    7,    8,    9,   28,   13,   17,
 /*    90 */    31,   32,   33,   34,   13,   36,    5,   13,    7,    8,
 /*   100 */    25,    7,    8,   12,   13,   16,   25,   38,   39,   18,
 /*   110 */    19,   20,   21,   22,   23,   24,   59,   29,   61,   28,
 /*   120 */    13,   42,   31,   32,   33,   34,   47,   36,    5,   26,
 /*   130 */     7,    8,   59,   48,   61,   12,   13,   59,   13,   61,
 /*   140 */    16,   18,   19,   20,   21,   22,   23,   24,   17,   17,
 /*   150 */    65,   28,   17,   42,   31,   32,   33,   34,   47,   36,
 /*   160 */     5,   42,    7,    8,   42,   56,   47,   12,   13,   47,
 /*   170 */    55,   13,   68,   18,   19,   20,   21,   22,   23,   24,
 /*   180 */    29,   10,    5,   28,    7,    8,   31,   32,   33,   34,
 /*   190 */    13,   36,   59,   63,   61,   18,   19,   20,   21,   22,
 /*   200 */    23,   24,   42,   13,   59,   28,   61,   47,   31,   32,
 /*   210 */    33,   34,   35,   36,    5,   48,    7,    8,   42,   57,
 /*   220 */    42,   12,   13,   47,   59,   47,   61,   18,   19,   20,
 /*   230 */    21,   22,   23,   24,   48,   17,    5,   28,    7,    8,
 /*   240 */    31,   32,   33,   34,   13,   36,   57,   17,   69,   18,
 /*   250 */    19,   20,   21,   22,   23,   24,   42,   17,    5,   28,
 /*   260 */    17,   47,   31,   32,   33,   34,   13,   36,   17,   69,
 /*   270 */    69,   18,   19,   20,   21,   22,   23,   24,   69,   69,
 /*   280 */    69,   28,   69,   42,   31,   32,   33,   34,   47,   36,
 /*   290 */    40,   69,   69,   43,   44,   45,   46,   47,   69,   42,
 /*   300 */    50,   51,   52,   53,   47,   69,   69,   57,   40,   69,
 /*   310 */    60,   43,   44,   45,   46,   47,   66,   67,   50,   51,
 /*   320 */    52,   53,   69,   69,   69,   57,   40,   69,   60,   43,
 /*   330 */    44,   45,   46,   47,   66,   67,   50,   42,   52,   53,
 /*   340 */    69,   69,   47,   57,   57,   58,   60,   60,   69,    5,
 /*   350 */    63,   64,   66,   67,   67,   69,   42,   13,   69,   69,
 /*   360 */    16,   47,   18,   19,   20,   21,   22,   23,   24,   69,
 /*   370 */    26,   69,   28,   43,   44,   45,   46,   47,   46,   47,
 /*   380 */    50,   49,   52,   53,   52,   69,   54,   57,   69,   57,
 /*   390 */    60,   69,   60,    5,   69,   42,   66,   67,   66,   67,
 /*   400 */    47,   13,   69,   69,   16,   69,   18,   19,   20,   21,
 /*   410 */    22,   23,   24,    5,   69,   69,   28,   69,   69,   69,
 /*   420 */    69,   13,   69,   69,   16,   69,   18,   19,   20,   21,
 /*   430 */    22,   23,   24,    5,   69,   69,   28,   69,   69,   69,
 /*   440 */    69,   13,   69,   69,   16,   69,   18,   19,   20,   21,
 /*   450 */    22,   23,   24,    5,   57,   58,   28,   60,   69,   69,
 /*   460 */    69,   13,   69,   69,   67,   69,   18,   19,   20,   21,
 /*   470 */    22,   23,   24,    5,   57,   58,   28,   60,   69,   69,
 /*   480 */    69,   13,   69,   69,   67,   69,   18,   19,   20,   21,
 /*   490 */    22,   23,   24,   69,   69,   13,   28,   69,   69,   69,
 /*   500 */    18,   19,   20,   21,   22,   23,   24,   69,   69,   13,
 /*   510 */    28,   69,   69,   69,   18,   19,   20,   21,   22,   23,
 /*   520 */    24,   69,   69,   46,   47,   69,   49,   69,   69,   52,
 /*   530 */    69,   69,   69,   69,   57,   46,   47,   60,   49,   46,
 /*   540 */    47,   52,   49,   66,   67,   52,   57,   69,   69,   60,
 /*   550 */    57,   46,   47,   60,   49,   66,   67,   52,   69,   66,
 /*   560 */    67,   69,   57,   57,   58,   60,   60,   69,   62,   63,
 /*   570 */    64,   66,   67,   67,   57,   58,   46,   60,   69,   49,
 /*   580 */    69,   69,   52,   69,   67,   69,   69,   57,   46,   47,
 /*   590 */    60,   69,   69,   69,   52,   69,   66,   67,   69,   57,
 /*   600 */    69,   69,   60,   69,   57,   58,   69,   60,   66,   67,
 /*   610 */     1,    2,    3,    4,   67,    6,   52,    1,    2,    3,
 /*   620 */     4,   57,    6,   69,   60,   69,   69,   69,   69,   52,
 /*   630 */    66,   67,   69,   69,   57,   69,   27,   60,   69,   69,
 /*   640 */    52,   69,   52,   66,   67,   57,   69,   57,   60,   69,
 /*   650 */    60,   69,   69,   69,   66,   67,   66,   67,   69,   69,
 /*   660 */    69,   69,   52,   69,   52,   69,   52,   57,   69,   57,
 /*   670 */    60,   57,   60,   69,   60,   69,   66,   67,   66,   67,
 /*   680 */    66,   67,   57,   58,   69,   60,   69,   57,   58,   69,
 /*   690 */    60,   69,   67,   69,   69,   57,   58,   67,   60,   69,
 /*   700 */    57,   58,   69,   60,   69,   67,   57,   58,   69,   60,
 /*   710 */    67,   69,   57,   58,   69,   60,   67,   69,   69,   69,
 /*   720 */    69,   69,   67,
};
#define YY_SHIFT_USE_DFLT (-13)
#define YY_SHIFT_COUNT (104)
#define YY_SHIFT_MIN   (-12)
#define YY_SHIFT_MAX   (616)
static const short yy_shift_ofst[] = {
 /*     0 */   -13,   59,   59,   59,   27,   -5,  231,  231,  231,  231,
 /*    10 */   231,  209,  177,  155,  123,   91,  231,  253,  468,  468,
 /*    20 */   482,  482,  482,  482,  482,  482,  482,  448,  448,  448,
 /*    30 */   448,  448,  448,  448,  448,  448,  448,   77,  344,  428,
 /*    40 */   408,  388,   46,   29,   94,   94,   94,   94,   94,   94,
 /*    50 */    94,   94,   94,   94,   94,   94,  171,  251,  243,  240,
 /*    60 */   230,  218,  496,  496,   58,  171,  190,  171,  151,  158,
 /*    70 */   124,  609,  616,  616,  616,  616,  616,  616,  616,   18,
 /*    80 */    18,   81,   75,    1,   39,  125,  107,  135,  132,  131,
 /*    90 */   103,   88,   84,   38,   72,   89,   56,   36,   38,   39,
 /*   100 */    28,   26,   17,  -12,   12,
};
#define YY_REDUCE_USE_DFLT (-51)
#define YY_REDUCE_COUNT (70)
#define YY_REDUCE_MIN   (-50)
#define YY_REDUCE_MAX   (655)
static const short yy_reduce_ofst[] = {
 /*     0 */    69,  268,  250,  286,  330,  330,  332,  505,  493,  489,
 /*    10 */   477,  542,  542,  542,  542,  542,  542,  530,  506,  287,
 /*    20 */   614,  612,  610,  590,  588,  577,  564,  655,  649,  643,
 /*    30 */   638,  630,  625,  547,  517,  417,  397,   15,  133,  165,
 /*    40 */   145,  133,  353,  314,  295,  257,  241,  214,  178,  176,
 /*    50 */   160,  122,  119,  111,   79,  -22,   85,   78,   73,   57,
 /*    60 */    10,  -50,  189,  162,  186,  167,  130,  167,  104,  115,
 /*    70 */   109,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   179,  263,  263,  263,  263,  263,  263,  263,  263,  263,
 /*    10 */   263,  263,  263,  263,  263,  263,  263,  263,  263,  263,
 /*    20 */   263,  263,  263,  263,  263,  263,  263,  263,  263,  263,
 /*    30 */   263,  263,  263,  263,  263,  263,  263,  263,  205,  236,
 /*    40 */   232,  205,  263,  263,  263,  263,  263,  263,  263,  263,
 /*    50 */   263,  263,  263,  263,  263,  263,  227,  221,  221,  221,
 /*    60 */   221,  221,  263,  263,  263,  230,  263,  228,  254,  263,
 /*    70 */   197,  249,  222,  223,  248,  247,  246,  245,  224,  212,
 /*    80 */   209,  263,  263,  210,  263,  263,  263,  263,  263,  263,
 /*    90 */   206,  263,  263,  219,  263,  216,  263,  213,  211,  205,
 /*   100 */   263,  186,  263,  263,  263,  180,  181,  192,  191,  173,
 /*   110 */   199,  260,  229,  226,  225,  255,  188,  184,  262,  259,
 /*   120 */   258,  257,  256,  251,  250,  261,  239,  235,  241,  238,
 /*   130 */   237,  240,  234,  233,  231,  244,  243,  242,  253,  252,
 /*   140 */   220,  218,  217,  215,  214,  208,  207,  206,  205,  204,
 /*   150 */   203,  202,  201,  200,  194,  187,  196,  198,  195,  185,
 /*   160 */   193,  190,  189,  183,  182,  178,  177,  176,  175,  174,
 /*   170 */   172,
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
  "$",             "OP0",           "CAST",          "OP1",         
  "OP2",           "NOT",           "DOT",           "NL",          
  "SEMI",          "EOF",           "COMMA",         "CLASS",       
  "END",           "ID",            "LT",            "DEF",         
  "LP",            "RP",            "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "LITSTR",        "DOLLAR",        "EQUAL",         "DCOLON",      
  "LB",            "PIPE",          "RB",            "IF",          
  "UNLESS",        "IMPORT",        "TRY",           "RESCUE",      
  "RAISE",         "error",         "program",       "opt_fin",     
  "l1",            "last_fin",      "fin",           "l1e",         
  "class",         "def",           "stmt",          "fin_m",       
  "comma",         "seq",           "class_start",   "class_body",  
  "s2",            "def_start",     "def_body",      "id_list",     
  "def_args",      "lit",           "np_arg",        "np_arg_list", 
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
 /*  28 */ "def ::= def_start ID def_args fin def_body",
 /*  29 */ "lit ::= NUM",
 /*  30 */ "lit ::= NIL",
 /*  31 */ "lit ::= TRUE",
 /*  32 */ "lit ::= FALSE",
 /*  33 */ "lit ::= SELF",
 /*  34 */ "lit ::= ID",
 /*  35 */ "lit ::= IVAR",
 /*  36 */ "lit ::= LITSTR",
 /*  37 */ "np_arg ::= lit",
 /*  38 */ "np_arg ::= np_arg OP0 np_arg",
 /*  39 */ "np_arg ::= np_arg OP1 np_arg",
 /*  40 */ "np_arg ::= np_arg OP2 np_arg",
 /*  41 */ "np_arg ::= np_arg CAST np_arg",
 /*  42 */ "np_arg ::= np_arg DOT ID",
 /*  43 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  44 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  45 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  46 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  47 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  48 */ "np_arg ::= NOT np_arg",
 /*  49 */ "np_arg ::= lambda",
 /*  50 */ "np_arg_list_start ::=",
 /*  51 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  52 */ "np_arg_list_elems ::= np_arg",
 /*  53 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  54 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  55 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  56 */ "np_opt_kw_arg_list ::=",
 /*  57 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  58 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  59 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  60 */ "np_recv ::= lit",
 /*  61 */ "np_recv ::= np_recv DOT ID",
 /*  62 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  63 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  64 */ "np_recv ::= np_recv DCOLON ID",
 /*  65 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  66 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  67 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  68 */ "np_recv ::= lambda",
 /*  69 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  70 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  71 */ "s2 ::= ID np_arg_list",
 /*  72 */ "s2 ::= ID LP RP",
 /*  73 */ "s2 ::= ID LP np_arg_list RP",
 /*  74 */ "s2 ::= np_recv CAST np_arg",
 /*  75 */ "s2 ::= np_recv OP0 np_arg",
 /*  76 */ "s2 ::= np_recv OP1 np_arg",
 /*  77 */ "s2 ::= np_recv OP2 np_arg",
 /*  78 */ "s2 ::= np_recv",
 /*  79 */ "stmt ::= s2",
 /*  80 */ "stmt ::= NOT s2",
 /*  81 */ "lambda_start ::= LB",
 /*  82 */ "lambda_args ::= PIPE ID PIPE",
 /*  83 */ "lambda_args ::=",
 /*  84 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  85 */ "stmt ::= IF s2 fin seq fin END",
 /*  86 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  87 */ "stmt ::= IMPORT ID",
 /*  88 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  89 */ "stmt ::= ID EQUAL s2",
 /*  90 */ "stmt ::= IVAR EQUAL s2",
 /*  91 */ "stmt ::= RAISE s2",
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
  { 38, 3 },
  { 40, 3 },
  { 40, 1 },
  { 43, 1 },
  { 43, 1 },
  { 43, 1 },
  { 47, 1 },
  { 47, 1 },
  { 39, 0 },
  { 39, 2 },
  { 41, 1 },
  { 41, 2 },
  { 42, 2 },
  { 42, 1 },
  { 48, 2 },
  { 48, 1 },
  { 49, 3 },
  { 49, 1 },
  { 50, 1 },
  { 51, 3 },
  { 44, 4 },
  { 44, 6 },
  { 53, 1 },
  { 54, 3 },
  { 55, 3 },
  { 55, 1 },
  { 56, 0 },
  { 56, 3 },
  { 45, 5 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 58, 1 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 3 },
  { 58, 5 },
  { 58, 6 },
  { 58, 4 },
  { 58, 6 },
  { 58, 7 },
  { 58, 2 },
  { 58, 1 },
  { 61, 0 },
  { 62, 3 },
  { 62, 1 },
  { 63, 3 },
  { 64, 3 },
  { 64, 1 },
  { 65, 0 },
  { 65, 2 },
  { 59, 3 },
  { 59, 2 },
  { 66, 1 },
  { 66, 3 },
  { 66, 5 },
  { 66, 6 },
  { 66, 3 },
  { 66, 4 },
  { 66, 6 },
  { 66, 7 },
  { 66, 1 },
  { 52, 4 },
  { 52, 5 },
  { 52, 2 },
  { 52, 3 },
  { 52, 4 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 3 },
  { 52, 1 },
  { 46, 1 },
  { 46, 2 },
  { 67, 1 },
  { 68, 3 },
  { 68, 0 },
  { 60, 4 },
  { 46, 6 },
  { 46, 6 },
  { 46, 2 },
  { 46, 9 },
  { 46, 3 },
  { 46, 3 },
  { 46, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy34.a)); }
#line 1023 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy34.a = S->seq(yymsp[-2].minor.yy34.a, yymsp[0].minor.yy34.a); }
#line 1029 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 37: /* np_arg ::= lit */ yytestcase(yyruleno==37);
      case 49: /* np_arg ::= lambda */ yytestcase(yyruleno==49);
      case 60: /* np_recv ::= lit */ yytestcase(yyruleno==60);
      case 68: /* np_recv ::= lambda */ yytestcase(yyruleno==68);
      case 78: /* s2 ::= np_recv */ yytestcase(yyruleno==78);
      case 79: /* stmt ::= s2 */ yytestcase(yyruleno==79);
#line 33 "vm/parser.lm"
{ yygotominor.yy34.a = yymsp[0].minor.yy34.a; }
#line 1044 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1049 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy34.a = yymsp[-2].minor.yy34.a; }
#line 1055 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy34.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy34.a);
             }
#line 1062 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy34.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy34.a, yymsp[0].minor.yy34.a);
             }
#line 1069 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1074 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1080 "vm/parser.c.inc"
        break;
      case 28: /* def ::= def_start ID def_args fin def_body */
#line 77 "vm/parser.lm"
{
              yygotominor.yy34.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy34.a);
            }
#line 1087 "vm/parser.c.inc"
        break;
      case 29: /* lit ::= NUM */
#line 81 "vm/parser.lm"
{ yygotominor.yy34.a = S->number(yymsp[0].minor.yy0.i); }
#line 1092 "vm/parser.c.inc"
        break;
      case 30: /* lit ::= NIL */
#line 82 "vm/parser.lm"
{ yygotominor.yy34.a = S->ast_nil();  }
#line 1097 "vm/parser.c.inc"
        break;
      case 31: /* lit ::= TRUE */
#line 83 "vm/parser.lm"
{ yygotominor.yy34.a = S->ast_true();  }
#line 1102 "vm/parser.c.inc"
        break;
      case 32: /* lit ::= FALSE */
#line 84 "vm/parser.lm"
{ yygotominor.yy34.a = S->ast_false(); }
#line 1107 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= SELF */
#line 85 "vm/parser.lm"
{ yygotominor.yy34.a = S->self(); }
#line 1112 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= ID */
#line 86 "vm/parser.lm"
{ yygotominor.yy34.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1117 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= IVAR */
#line 87 "vm/parser.lm"
{ yygotominor.yy34.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1122 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= LITSTR */
#line 88 "vm/parser.lm"
{ yygotominor.yy34.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1127 "vm/parser.c.inc"
        break;
      case 38: /* np_arg ::= np_arg OP0 np_arg */
      case 39: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==39);
      case 40: /* np_arg ::= np_arg OP2 np_arg */ yytestcase(yyruleno==40);
      case 75: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==75);
      case 76: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==76);
      case 77: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==77);
#line 92 "vm/parser.lm"
{ yygotominor.yy34.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy34.a, yymsp[0].minor.yy34.a); }
#line 1137 "vm/parser.c.inc"
        break;
      case 41: /* np_arg ::= np_arg CAST np_arg */
      case 74: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==74);
#line 98 "vm/parser.lm"
{ yygotominor.yy34.a = S->cast(yymsp[-2].minor.yy34.a, yymsp[0].minor.yy34.a); }
#line 1143 "vm/parser.c.inc"
        break;
      case 42: /* np_arg ::= np_arg DOT ID */
      case 61: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==61);
#line 99 "vm/parser.lm"
{ yygotominor.yy34.a = S->call(yymsp[-2].minor.yy34.a, *yymsp[0].minor.yy0.s); }
#line 1149 "vm/parser.c.inc"
        break;
      case 43: /* np_arg ::= np_arg DOT ID LP RP */
      case 62: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==62);
#line 100 "vm/parser.lm"
{ yygotominor.yy34.a = S->call(yymsp[-4].minor.yy34.a, *yymsp[-2].minor.yy0.s); }
#line 1155 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 63: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==63);
#line 102 "vm/parser.lm"
{ yygotominor.yy34.a = S->call_args(yymsp[-5].minor.yy34.a, *yymsp[-3].minor.yy0.s); }
#line 1161 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 65: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==65);
#line 104 "vm/parser.lm"
{ yygotominor.yy34.a = S->send_indirect(yymsp[-3].minor.yy34.a, yymsp[0].minor.yy34.a); }
#line 1167 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 66: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==66);
#line 106 "vm/parser.lm"
{ yygotominor.yy34.a = S->send_indirect(yymsp[-5].minor.yy34.a, yymsp[-2].minor.yy34.a); }
#line 1173 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 67: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==67);
#line 108 "vm/parser.lm"
{ yygotominor.yy34.a = S->send_indirect_args(yymsp[-6].minor.yy34.a, yymsp[-3].minor.yy34.a); }
#line 1179 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= NOT np_arg */
      case 80: /* stmt ::= NOT s2 */ yytestcase(yyruleno==80);
#line 109 "vm/parser.lm"
{ yygotominor.yy34.a = S->not_(yymsp[0].minor.yy34.a); }
#line 1185 "vm/parser.c.inc"
        break;
      case 50: /* np_arg_list_start ::= */
#line 112 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1190 "vm/parser.c.inc"
        break;
      case 51: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 52: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==52);
#line 113 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy34.a); }
#line 1196 "vm/parser.c.inc"
        break;
      case 53: /* np_kw_arg ::= ID EQUAL np_arg */
#line 116 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy34.a); }
#line 1201 "vm/parser.c.inc"
        break;
      case 64: /* np_recv ::= np_recv DCOLON ID */
#line 131 "vm/parser.lm"
{ yygotominor.yy34.a = S->dcolon(yymsp[-2].minor.yy34.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1206 "vm/parser.c.inc"
        break;
      case 69: /* s2 ::= np_recv DOT ID np_arg_list */
#line 140 "vm/parser.lm"
{ yygotominor.yy34.a = S->call_args(yymsp[-3].minor.yy34.a, *yymsp[-1].minor.yy0.s); }
#line 1211 "vm/parser.c.inc"
        break;
      case 70: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 142 "vm/parser.lm"
{ yygotominor.yy34.a = S->send_indirect_args(yymsp[-4].minor.yy34.a, yymsp[-1].minor.yy34.a); }
#line 1216 "vm/parser.c.inc"
        break;
      case 71: /* s2 ::= ID np_arg_list */
#line 143 "vm/parser.lm"
{ yygotominor.yy34.a = S->call_args(S->self(), *yymsp[-1].minor.yy0.s); }
#line 1221 "vm/parser.c.inc"
        break;
      case 72: /* s2 ::= ID LP RP */
#line 144 "vm/parser.lm"
{ yygotominor.yy34.a = S->call(S->self(), *yymsp[-2].minor.yy0.s); }
#line 1226 "vm/parser.c.inc"
        break;
      case 73: /* s2 ::= ID LP np_arg_list RP */
#line 145 "vm/parser.lm"
{ yygotominor.yy34.a = S->call_args(S->self(), *yymsp[-3].minor.yy0.s); }
#line 1231 "vm/parser.c.inc"
        break;
      case 81: /* lambda_start ::= LB */
#line 157 "vm/parser.lm"
{ S->start_lambda(); }
#line 1236 "vm/parser.c.inc"
        break;
      case 82: /* lambda_args ::= PIPE ID PIPE */
#line 159 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1241 "vm/parser.c.inc"
        break;
      case 84: /* lambda ::= lambda_start lambda_args seq RB */
#line 162 "vm/parser.lm"
{ yygotominor.yy34.a = S->lambda(yymsp[-1].minor.yy34.a); }
#line 1246 "vm/parser.c.inc"
        break;
      case 85: /* stmt ::= IF s2 fin seq fin END */
#line 166 "vm/parser.lm"
{ yygotominor.yy34.a = S->if_cond(yymsp[-4].minor.yy34.a, yymsp[-2].minor.yy34.a); }
#line 1251 "vm/parser.c.inc"
        break;
      case 86: /* stmt ::= UNLESS s2 fin seq fin END */
#line 167 "vm/parser.lm"
{ yygotominor.yy34.a = S->unless(yymsp[-4].minor.yy34.a, yymsp[-2].minor.yy34.a); }
#line 1256 "vm/parser.c.inc"
        break;
      case 87: /* stmt ::= IMPORT ID */
#line 171 "vm/parser.lm"
{ yygotominor.yy34.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1261 "vm/parser.c.inc"
        break;
      case 88: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 173 "vm/parser.lm"
{
              yygotominor.yy34.a = S->ast_try(yymsp[-6].minor.yy34.a, yymsp[-2].minor.yy34.a);
            }
#line 1268 "vm/parser.c.inc"
        break;
      case 89: /* stmt ::= ID EQUAL s2 */
#line 177 "vm/parser.lm"
{ yygotominor.yy34.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy34.a); }
#line 1273 "vm/parser.c.inc"
        break;
      case 90: /* stmt ::= IVAR EQUAL s2 */
#line 178 "vm/parser.lm"
{ yygotominor.yy34.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy34.a); }
#line 1278 "vm/parser.c.inc"
        break;
      case 91: /* stmt ::= RAISE s2 */
#line 179 "vm/parser.lm"
{ yygotominor.yy34.a = S->raise(yymsp[0].minor.yy34.a); }
#line 1283 "vm/parser.c.inc"
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
      /* (54) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==54);
      /* (55) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==55);
      /* (56) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==56);
      /* (57) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==57);
      /* (58) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==58);
      /* (59) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==59);
      /* (83) lambda_args ::= */ yytestcase(yyruleno==83);
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
#line 1370 "vm/parser.c.inc"
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
