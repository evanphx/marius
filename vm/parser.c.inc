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
#define YYNSTATE 176
#define YYNRULE 95
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
#define YY_ACTTAB_COUNT (788)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    25,  176,  171,  170,  169,   35,  167,   86,   40,   45,
 /*    10 */   165,  171,  170,  158,  157,  156,  155,  154,   94,  151,
 /*    20 */     4,   36,   35,  144,   86,  122,   24,   23,   89,   50,
 /*    30 */    25,   22,  171,  170,  120,   72,  167,  166,   40,  101,
 /*    40 */   165,  164,   42,  158,  157,  156,  155,  154,   94,  151,
 /*    50 */   100,   65,   18,  144,   64,   19,   24,   23,   89,   50,
 /*    60 */    25,   22,  171,  170,   38,   98,  167,   18,   40,   93,
 /*    70 */   165,   18,  117,  158,  157,  156,  155,  154,   94,  151,
 /*    80 */    92,  163,   18,  144,  171,  170,   24,   23,   89,   50,
 /*    90 */    25,   22,  171,  170,   63,  171,  170,  159,   40,  171,
 /*   100 */   170,  110,   20,  158,  157,  156,  155,  154,   94,  151,
 /*   110 */    91,   86,   18,  144,  272,    3,   24,   23,   89,   50,
 /*   120 */    25,   22,  171,  170,    6,  148,   15,  127,   40,  122,
 /*   130 */   140,  122,   18,  158,  157,  156,  155,  154,   94,  151,
 /*   140 */    10,   62,   95,  144,  146,  122,   24,   23,   89,   50,
 /*   150 */    25,   22,  171,  170,   14,  143,    9,  126,   40,  122,
 /*   160 */   136,  122,   18,  158,  157,  156,  155,  154,   94,  151,
 /*   170 */    26,  141,   25,  144,  171,  170,   24,   23,   89,   50,
 /*   180 */    40,   22,  133,  137,   18,  158,  157,  156,  155,  154,
 /*   190 */    94,  151,  134,  132,  125,  144,   56,  105,   24,   23,
 /*   200 */    89,   50,   48,   22,  162,   25,   71,  171,  170,  108,
 /*   210 */     5,   13,  124,   40,   66,  122,  122,  161,  158,  157,
 /*   220 */   156,  155,  154,   94,  151,    8,   17,   96,  144,  105,
 /*   230 */   122,   24,   23,   89,   50,   25,   22,  171,  170,   12,
 /*   240 */    68,    7,  114,   40,  122,  119,  122,   88,  158,  157,
 /*   250 */   156,  155,  154,   94,  151,  104,  149,   25,  144,  171,
 /*   260 */   170,   24,   23,   89,   50,   40,   22,   99,   41,  273,
 /*   270 */   158,  157,  156,  155,  154,   94,  151,   11,  147,   25,
 /*   280 */   144,  142,  122,   24,   23,   89,   50,   40,   22,  273,
 /*   290 */   138,  273,  158,  157,  156,  155,  154,   94,  151,  135,
 /*   300 */   273,  273,  144,  273,    1,   24,   23,   89,   50,  122,
 /*   310 */    22,  273,   57,  273,  273,  113,  174,  173,  172,  168,
 /*   320 */   273,    2,  107,  112,  128,  106,  122,  273,  273,  139,
 /*   330 */    57,  273,  131,  113,  174,  173,  172,  168,   73,   70,
 /*   340 */   107,  111,  128,  106,  273,  273,  273,  139,   39,  273,
 /*   350 */   131,  113,  174,  173,  172,  109,   73,   70,  107,   16,
 /*   360 */   128,  106,  129,  273,  122,  139,  273,  139,  131,  273,
 /*   370 */   131,  273,  228,  273,   73,   70,   73,   70,  273,  273,
 /*   380 */   228,  273,  273,   61,  273,  228,  228,  228,  228,  228,
 /*   390 */   228,  228,  273,   21,  273,  228,  175,  174,  173,  172,
 /*   400 */   168,  121,  168,  107,   55,  128,  106,  128,  273,  115,
 /*   410 */   139,  273,  139,  131,  273,  131,  273,  228,  273,   73,
 /*   420 */    70,   73,   70,  273,  273,  228,  273,  273,   61,  273,
 /*   430 */   228,  228,  228,  228,  228,  228,  228,  228,  273,  273,
 /*   440 */   228,  273,  273,  273,  273,  228,  273,  273,   60,  273,
 /*   450 */   228,  228,  228,  228,  228,  228,  228,  228,  273,  273,
 /*   460 */   228,  273,  273,  273,  273,  228,  273,  273,   59,  273,
 /*   470 */   228,  228,  228,  228,  228,  228,  228,   32,  150,   81,
 /*   480 */   228,  145,  273,  273,  273,  153,  273,  273,   70,  273,
 /*   490 */   158,  157,  156,  155,  154,  152,  151,   25,  273,  273,
 /*   500 */   144,  273,  273,  273,  273,   43,  273,  273,  273,  273,
 /*   510 */   158,  157,  156,  155,  154,  152,  151,   32,  273,  273,
 /*   520 */   144,  273,  273,  273,  273,  103,  273,  273,  273,  273,
 /*   530 */   158,  157,  156,  155,  154,  152,  151,  273,  150,   84,
 /*   540 */   144,  145,  273,  273,  273,  153,  273,  273,   70,  273,
 /*   550 */   158,  157,  156,  155,  154,  152,  151,  273,  273,  121,
 /*   560 */   168,  273,   53,  121,  168,  128,   51,  273,  273,  128,
 /*   570 */   139,  273,  273,  131,  139,  150,   74,  131,  145,   73,
 /*   580 */    70,  118,   69,   73,   70,   70,  273,  273,  121,  168,
 /*   590 */   130,   49,  273,  273,  128,  139,  273,  273,  131,  139,
 /*   600 */   121,  168,  131,   47,   73,   70,  128,  273,   73,   70,
 /*   610 */   273,  139,  273,  273,  131,  273,  273,  273,  273,  273,
 /*   620 */    73,   70,   30,   31,   27,   29,   28,  273,   85,  150,
 /*   630 */    75,  273,  145,  273,   58,  118,   67,  121,  273,   70,
 /*   640 */    44,  273,  273,  128,  273,  273,  273,  273,  139,   90,
 /*   650 */   273,  131,  273,  273,  160,  168,   54,   73,   70,  273,
 /*   660 */   128,  139,  273,  273,  131,  139,  273,  273,  131,  273,
 /*   670 */    73,   70,  273,  273,   73,   70,   37,   34,   33,   36,
 /*   680 */    35,  273,   86,   52,  273,  273,  273,  273,  139,  273,
 /*   690 */   273,  131,  273,  273,  123,  273,  273,   73,   70,  139,
 /*   700 */   273,  273,  131,  273,  273,  116,  273,  273,   73,   70,
 /*   710 */   139,  273,  273,  131,  150,   87,  273,  145,   46,   73,
 /*   720 */    70,  273,  273,  139,   70,  273,  131,  150,  102,  273,
 /*   730 */   145,  273,   73,   70,  273,  150,   83,   70,  145,  150,
 /*   740 */    82,  273,  145,  273,  273,   70,  273,  150,   97,   70,
 /*   750 */   145,  273,  273,  150,   80,  273,  145,   70,  150,   79,
 /*   760 */   273,  145,  273,   70,  150,   78,  273,  145,   70,  150,
 /*   770 */    77,  273,  145,  273,   70,  273,  273,  150,   76,   70,
 /*   780 */   145,  273,  273,  273,  273,  273,  273,   70,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    0,    8,    9,   10,    5,   12,    7,   14,   14,
 /*    10 */    16,    8,    9,   19,   20,   21,   22,   23,   24,   25,
 /*    20 */    43,    4,    5,   29,    7,   48,   32,   33,   34,   35,
 /*    30 */     6,   37,    8,    9,   31,   14,   12,   13,   14,   14,
 /*    40 */    16,    8,   14,   19,   20,   21,   22,   23,   24,   25,
 /*    50 */    60,   26,   62,   29,   26,   49,   32,   33,   34,   35,
 /*    60 */     6,   37,    8,    9,   27,   60,   12,   62,   14,   60,
 /*    70 */    16,   62,   66,   19,   20,   21,   22,   23,   24,   25,
 /*    80 */    60,   14,   62,   29,    8,    9,   32,   33,   34,   35,
 /*    90 */     6,   37,    8,    9,   17,    8,    9,   13,   14,    8,
 /*   100 */     9,   10,   15,   19,   20,   21,   22,   23,   24,   25,
 /*   110 */    60,    7,   62,   29,   39,   40,   32,   33,   34,   35,
 /*   120 */     6,   37,    8,    9,   43,   18,   43,   13,   14,   48,
 /*   130 */    60,   48,   62,   19,   20,   21,   22,   23,   24,   25,
 /*   140 */    43,   17,   14,   29,   18,   48,   32,   33,   34,   35,
 /*   150 */     6,   37,    8,    9,   43,   30,   43,   13,   14,   48,
 /*   160 */    60,   48,   62,   19,   20,   21,   22,   23,   24,   25,
 /*   170 */    27,   18,    6,   29,    8,    9,   32,   33,   34,   35,
 /*   180 */    14,   37,   60,   18,   62,   19,   20,   21,   22,   23,
 /*   190 */    24,   25,   18,   14,   14,   29,   57,   11,   32,   33,
 /*   200 */    34,   35,   36,   37,   18,    6,   17,    8,    9,   42,
 /*   210 */    43,   43,   13,   14,   56,   48,   48,   14,   19,   20,
 /*   220 */    21,   22,   23,   24,   25,   43,   69,   30,   29,   11,
 /*   230 */    48,   32,   33,   34,   35,    6,   37,    8,    9,   43,
 /*   240 */    49,   43,   13,   14,   48,   64,   48,   14,   19,   20,
 /*   250 */    21,   22,   23,   24,   25,   49,   18,    6,   29,    8,
 /*   260 */     9,   32,   33,   34,   35,   14,   37,   58,   58,   70,
 /*   270 */    19,   20,   21,   22,   23,   24,   25,   43,   18,    6,
 /*   280 */    29,   18,   48,   32,   33,   34,   35,   14,   37,   70,
 /*   290 */    18,   70,   19,   20,   21,   22,   23,   24,   25,   18,
 /*   300 */    70,   70,   29,   70,   43,   32,   33,   34,   35,   48,
 /*   310 */    37,   70,   41,   70,   70,   44,   45,   46,   47,   48,
 /*   320 */    70,   43,   51,   52,   53,   54,   48,   70,   70,   58,
 /*   330 */    41,   70,   61,   44,   45,   46,   47,   48,   67,   68,
 /*   340 */    51,   52,   53,   54,   70,   70,   70,   58,   41,   70,
 /*   350 */    61,   44,   45,   46,   47,   48,   67,   68,   51,   43,
 /*   360 */    53,   54,   53,   70,   48,   58,   70,   58,   61,   70,
 /*   370 */    61,   70,    6,   70,   67,   68,   67,   68,   70,   70,
 /*   380 */    14,   70,   70,   17,   70,   19,   20,   21,   22,   23,
 /*   390 */    24,   25,   70,   27,   70,   29,   44,   45,   46,   47,
 /*   400 */    48,   47,   48,   51,   50,   53,   54,   53,   70,   55,
 /*   410 */    58,   70,   58,   61,   70,   61,   70,    6,   70,   67,
 /*   420 */    68,   67,   68,   70,   70,   14,   70,   70,   17,   70,
 /*   430 */    19,   20,   21,   22,   23,   24,   25,    6,   70,   70,
 /*   440 */    29,   70,   70,   70,   70,   14,   70,   70,   17,   70,
 /*   450 */    19,   20,   21,   22,   23,   24,   25,    6,   70,   70,
 /*   460 */    29,   70,   70,   70,   70,   14,   70,   70,   17,   70,
 /*   470 */    19,   20,   21,   22,   23,   24,   25,    6,   58,   59,
 /*   480 */    29,   61,   70,   70,   70,   14,   70,   70,   68,   70,
 /*   490 */    19,   20,   21,   22,   23,   24,   25,    6,   70,   70,
 /*   500 */    29,   70,   70,   70,   70,   14,   70,   70,   70,   70,
 /*   510 */    19,   20,   21,   22,   23,   24,   25,    6,   70,   70,
 /*   520 */    29,   70,   70,   70,   70,   14,   70,   70,   70,   70,
 /*   530 */    19,   20,   21,   22,   23,   24,   25,   70,   58,   59,
 /*   540 */    29,   61,   70,   70,   70,   14,   70,   70,   68,   70,
 /*   550 */    19,   20,   21,   22,   23,   24,   25,   70,   70,   47,
 /*   560 */    48,   70,   50,   47,   48,   53,   50,   70,   70,   53,
 /*   570 */    58,   70,   70,   61,   58,   58,   59,   61,   61,   67,
 /*   580 */    68,   64,   65,   67,   68,   68,   70,   70,   47,   48,
 /*   590 */    53,   50,   70,   70,   53,   58,   70,   70,   61,   58,
 /*   600 */    47,   48,   61,   50,   67,   68,   53,   70,   67,   68,
 /*   610 */    70,   58,   70,   70,   61,   70,   70,   70,   70,   70,
 /*   620 */    67,   68,    1,    2,    3,    4,    5,   70,    7,   58,
 /*   630 */    59,   70,   61,   70,   63,   64,   65,   47,   70,   68,
 /*   640 */    50,   70,   70,   53,   70,   70,   70,   70,   58,   28,
 /*   650 */    70,   61,   70,   70,   47,   48,   53,   67,   68,   70,
 /*   660 */    53,   58,   70,   70,   61,   58,   70,   70,   61,   70,
 /*   670 */    67,   68,   70,   70,   67,   68,    1,    2,    3,    4,
 /*   680 */     5,   70,    7,   53,   70,   70,   70,   70,   58,   70,
 /*   690 */    70,   61,   70,   70,   53,   70,   70,   67,   68,   58,
 /*   700 */    70,   70,   61,   70,   70,   53,   70,   70,   67,   68,
 /*   710 */    58,   70,   70,   61,   58,   59,   70,   61,   53,   67,
 /*   720 */    68,   70,   70,   58,   68,   70,   61,   58,   59,   70,
 /*   730 */    61,   70,   67,   68,   70,   58,   59,   68,   61,   58,
 /*   740 */    59,   70,   61,   70,   70,   68,   70,   58,   59,   68,
 /*   750 */    61,   70,   70,   58,   59,   70,   61,   68,   58,   59,
 /*   760 */    70,   61,   70,   68,   58,   59,   70,   61,   68,   58,
 /*   770 */    59,   70,   61,   70,   68,   70,   70,   58,   59,   68,
 /*   780 */    61,   70,   70,   70,   70,   70,   70,   68,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (108)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (675)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   54,   54,   54,   24,   -6,  229,  251,  251,  251,
 /*    10 */   251,  199,  166,  144,  114,   84,  251,  273,  511,  511,
 /*    20 */   491,  491,  491,  491,  491,  491,  491,  471,  471,  471,
 /*    30 */   471,  471,  471,  471,  471,  471,  471,  471,  471,   91,
 /*    40 */   366,  451,  431,  411,    3,   87,   76,   76,   76,   76,
 /*    50 */    76,   76,   76,   76,   76,   76,   76,   76,  218,  281,
 /*    60 */   272,  263,  260,  238,  531,  531,  186,  218,  233,  218,
 /*    70 */   197,  203,  189,  621,  675,  675,  675,  675,  675,  675,
 /*    80 */   675,  675,   17,   17,   17,   28,   25,    0,   37,  180,
 /*    90 */   179,  174,  165,  153,  143,  125,  128,  104,  126,  124,
 /*   100 */   107,   77,  104,   37,   67,   33,   21,   -5,    1,
};
#define YY_REDUCE_USE_DFLT (-24)
#define YY_REDUCE_COUNT (72)
#define YY_REDUCE_MIN   (-23)
#define YY_REDUCE_MAX   (719)
static const short yy_reduce_ofst[] = {
 /*     0 */    75,  289,  271,  307,  352,  352,  354,  553,  541,  516,
 /*    10 */   512,  607,  607,  607,  607,  607,  607,  590,  571,  517,
 /*    20 */   665,  652,  641,  630,  603,  537,  309,  719,  711,  706,
 /*    30 */   700,  695,  689,  681,  677,  669,  656,  480,  420,  167,
 /*    40 */    70,  122,  100,   70,  316,  278,  261,  234,  198,  196,
 /*    50 */   182,  168,  113,  111,   97,   83,   81,  -23,    6,   50,
 /*    60 */    20,    9,    5,  -10,  210,  209,  206,  191,  181,  191,
 /*    70 */   157,  158,  139,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   184,  271,  271,  271,  271,  271,  271,  271,  271,  271,
 /*    10 */   271,  271,  271,  271,  271,  271,  271,  271,  271,  271,
 /*    20 */   271,  271,  271,  271,  271,  271,  271,  271,  271,  271,
 /*    30 */   271,  271,  271,  271,  271,  271,  271,  271,  271,  271,
 /*    40 */   211,  245,  241,  211,  271,  271,  271,  271,  271,  271,
 /*    50 */   271,  271,  271,  271,  271,  271,  271,  271,  234,  228,
 /*    60 */   228,  228,  228,  228,  271,  271,  271,  237,  271,  235,
 /*    70 */   262,  271,  202,  257,  229,  230,  256,  255,  254,  253,
 /*    80 */   252,  231,  219,  218,  215,  271,  271,  216,  271,  271,
 /*    90 */   271,  271,  271,  271,  212,  271,  271,  226,  271,  223,
 /*   100 */   271,  220,  217,  211,  271,  191,  271,  271,  271,  185,
 /*   110 */   186,  197,  196,  178,  205,  204,  268,  236,  233,  232,
 /*   120 */   263,  193,  189,  270,  267,  266,  265,  264,  259,  269,
 /*   130 */   258,  248,  244,  250,  247,  246,  249,  243,  242,  238,
 /*   140 */   251,  240,  239,  261,  260,  227,  225,  224,  222,  221,
 /*   150 */   214,  213,  212,  211,  210,  209,  208,  207,  206,  199,
 /*   160 */   192,  201,  203,  200,  190,  198,  195,  194,  188,  187,
 /*   170 */   183,  182,  181,  180,  179,  177,
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
  "DCOLON",        "LB",            "PIPE",          "RB",          
  "IF",            "UNLESS",        "IMPORT",        "TRY",         
  "RESCUE",        "RAISE",         "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "fin_m",         "comma",         "seq",           "class_start", 
  "class_body",    "s2",            "def_start",     "def_body",    
  "id_list",       "def_args",      "lit",           "np_arg",      
  "np_arg_list",   "lambda",        "np_arg_list_start",  "np_arg_list_elems",
  "np_kw_arg",     "np_kw_arg_list_elems",  "np_opt_kw_arg_list",  "np_recv",     
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
 /*  29 */ "def ::= def_start ID def_args fin END",
 /*  30 */ "lit ::= NUM",
 /*  31 */ "lit ::= NIL",
 /*  32 */ "lit ::= TRUE",
 /*  33 */ "lit ::= FALSE",
 /*  34 */ "lit ::= SELF",
 /*  35 */ "lit ::= ID",
 /*  36 */ "lit ::= IVAR",
 /*  37 */ "lit ::= LITSTR",
 /*  38 */ "np_arg ::= lit",
 /*  39 */ "np_arg ::= np_arg OP0 np_arg",
 /*  40 */ "np_arg ::= np_arg OP1 np_arg",
 /*  41 */ "np_arg ::= np_arg OP2 np_arg",
 /*  42 */ "np_arg ::= np_arg CAST np_arg",
 /*  43 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  44 */ "np_arg ::= np_arg DOT ID",
 /*  45 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  46 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  47 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  48 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  49 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  50 */ "np_arg ::= NOT np_arg",
 /*  51 */ "np_arg ::= lambda",
 /*  52 */ "np_arg_list_start ::=",
 /*  53 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  54 */ "np_arg_list_elems ::= np_arg",
 /*  55 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  56 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  57 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  58 */ "np_opt_kw_arg_list ::=",
 /*  59 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  60 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  61 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  62 */ "np_recv ::= lit",
 /*  63 */ "np_recv ::= ID LP RP",
 /*  64 */ "np_recv ::= ID LP np_arg_list RP",
 /*  65 */ "np_recv ::= np_recv DOT ID",
 /*  66 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  67 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  68 */ "np_recv ::= np_recv DCOLON ID",
 /*  69 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  70 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  71 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  72 */ "np_recv ::= lambda",
 /*  73 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  74 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  75 */ "s2 ::= ID np_arg_list",
 /*  76 */ "s2 ::= np_recv CAST np_arg",
 /*  77 */ "s2 ::= np_recv OP0 np_arg",
 /*  78 */ "s2 ::= np_recv OP1 np_arg",
 /*  79 */ "s2 ::= np_recv OP2 np_arg",
 /*  80 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  81 */ "s2 ::= np_recv",
 /*  82 */ "s2 ::= NOT s2",
 /*  83 */ "stmt ::= s2",
 /*  84 */ "lambda_start ::= LB",
 /*  85 */ "lambda_args ::= PIPE ID PIPE",
 /*  86 */ "lambda_args ::=",
 /*  87 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  88 */ "stmt ::= IF s2 fin seq fin END",
 /*  89 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  90 */ "stmt ::= IMPORT ID",
 /*  91 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  92 */ "stmt ::= ID EQUAL s2",
 /*  93 */ "stmt ::= IVAR EQUAL s2",
 /*  94 */ "stmt ::= RAISE s2",
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
  { 48, 1 },
  { 48, 1 },
  { 40, 0 },
  { 40, 2 },
  { 42, 1 },
  { 42, 2 },
  { 43, 2 },
  { 43, 1 },
  { 49, 2 },
  { 49, 1 },
  { 50, 3 },
  { 50, 1 },
  { 51, 1 },
  { 52, 3 },
  { 45, 4 },
  { 45, 6 },
  { 54, 1 },
  { 55, 3 },
  { 56, 3 },
  { 56, 1 },
  { 57, 0 },
  { 57, 3 },
  { 46, 5 },
  { 46, 5 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 58, 1 },
  { 59, 1 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 3 },
  { 59, 5 },
  { 59, 6 },
  { 59, 4 },
  { 59, 6 },
  { 59, 7 },
  { 59, 2 },
  { 59, 1 },
  { 62, 0 },
  { 63, 3 },
  { 63, 1 },
  { 64, 3 },
  { 65, 3 },
  { 65, 1 },
  { 66, 0 },
  { 66, 2 },
  { 60, 3 },
  { 60, 2 },
  { 67, 1 },
  { 67, 3 },
  { 67, 4 },
  { 67, 3 },
  { 67, 5 },
  { 67, 6 },
  { 67, 3 },
  { 67, 4 },
  { 67, 6 },
  { 67, 7 },
  { 67, 1 },
  { 53, 4 },
  { 53, 5 },
  { 53, 2 },
  { 53, 3 },
  { 53, 3 },
  { 53, 3 },
  { 53, 3 },
  { 53, 3 },
  { 53, 1 },
  { 53, 2 },
  { 47, 1 },
  { 68, 1 },
  { 69, 3 },
  { 69, 0 },
  { 61, 4 },
  { 47, 6 },
  { 47, 6 },
  { 47, 2 },
  { 47, 9 },
  { 47, 3 },
  { 47, 3 },
  { 47, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy88.a)); }
#line 1041 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1047 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 38: /* np_arg ::= lit */ yytestcase(yyruleno==38);
      case 51: /* np_arg ::= lambda */ yytestcase(yyruleno==51);
      case 62: /* np_recv ::= lit */ yytestcase(yyruleno==62);
      case 72: /* np_recv ::= lambda */ yytestcase(yyruleno==72);
      case 81: /* s2 ::= np_recv */ yytestcase(yyruleno==81);
      case 83: /* stmt ::= s2 */ yytestcase(yyruleno==83);
#line 33 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 1062 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1067 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 1073 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy88.a);
             }
#line 1080 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a);
             }
#line 1087 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1092 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1098 "vm/parser.c.inc"
        break;
      case 28: /* def ::= def_start ID def_args fin def_body */
#line 77 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy88.a);
            }
#line 1105 "vm/parser.c.inc"
        break;
      case 29: /* def ::= def_start ID def_args fin END */
#line 80 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(*yymsp[-3].minor.yy0.s, S->ast_nil());
            }
#line 1112 "vm/parser.c.inc"
        break;
      case 30: /* lit ::= NUM */
#line 84 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 1117 "vm/parser.c.inc"
        break;
      case 31: /* lit ::= NIL */
#line 85 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 1122 "vm/parser.c.inc"
        break;
      case 32: /* lit ::= TRUE */
#line 86 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 1127 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= FALSE */
#line 87 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 1132 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= SELF */
#line 88 "vm/parser.lm"
{ yygotominor.yy88.a = S->self(); }
#line 1137 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= ID */
#line 89 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1142 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= IVAR */
#line 90 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1147 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= LITSTR */
#line 91 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1152 "vm/parser.c.inc"
        break;
      case 39: /* np_arg ::= np_arg OP0 np_arg */
      case 40: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==40);
      case 41: /* np_arg ::= np_arg OP2 np_arg */ yytestcase(yyruleno==41);
      case 77: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==77);
      case 78: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==78);
      case 79: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==79);
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1162 "vm/parser.c.inc"
        break;
      case 42: /* np_arg ::= np_arg CAST np_arg */
      case 76: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==76);
#line 101 "vm/parser.lm"
{ yygotominor.yy88.a = S->cast(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1168 "vm/parser.c.inc"
        break;
      case 43: /* np_arg ::= np_arg NEQUAL np_arg */
      case 80: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==80);
#line 103 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a)); }
#line 1174 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg DOT ID */
      case 65: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==65);
#line 104 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 1180 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg DOT ID LP RP */
      case 66: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==66);
#line 105 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1186 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 67: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==67);
#line 107 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-5].minor.yy88.a, *yymsp[-3].minor.yy0.s); }
#line 1192 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 69: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==69);
#line 109 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-3].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 1198 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 70: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==70);
#line 111 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect(yymsp[-5].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1204 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 71: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==71);
#line 113 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-6].minor.yy88.a, yymsp[-3].minor.yy88.a); }
#line 1210 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= NOT np_arg */
      case 82: /* s2 ::= NOT s2 */ yytestcase(yyruleno==82);
#line 114 "vm/parser.lm"
{ yygotominor.yy88.a = S->not_(yymsp[0].minor.yy88.a); }
#line 1216 "vm/parser.c.inc"
        break;
      case 52: /* np_arg_list_start ::= */
#line 117 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1221 "vm/parser.c.inc"
        break;
      case 53: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 54: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==54);
#line 118 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1227 "vm/parser.c.inc"
        break;
      case 55: /* np_kw_arg ::= ID EQUAL np_arg */
#line 121 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1232 "vm/parser.c.inc"
        break;
      case 63: /* np_recv ::= ID LP RP */
#line 133 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(S->self(), *yymsp[-2].minor.yy0.s); }
#line 1237 "vm/parser.c.inc"
        break;
      case 64: /* np_recv ::= ID LP np_arg_list RP */
#line 134 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), *yymsp[-3].minor.yy0.s); }
#line 1242 "vm/parser.c.inc"
        break;
      case 68: /* np_recv ::= np_recv DCOLON ID */
#line 138 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1247 "vm/parser.c.inc"
        break;
      case 73: /* s2 ::= np_recv DOT ID np_arg_list */
#line 147 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-3].minor.yy88.a, *yymsp[-1].minor.yy0.s); }
#line 1252 "vm/parser.c.inc"
        break;
      case 74: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 149 "vm/parser.lm"
{ yygotominor.yy88.a = S->send_indirect_args(yymsp[-4].minor.yy88.a, yymsp[-1].minor.yy88.a); }
#line 1257 "vm/parser.c.inc"
        break;
      case 75: /* s2 ::= ID np_arg_list */
#line 150 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(S->self(), *yymsp[-1].minor.yy0.s); }
#line 1262 "vm/parser.c.inc"
        break;
      case 84: /* lambda_start ::= LB */
#line 164 "vm/parser.lm"
{ S->start_lambda(); }
#line 1267 "vm/parser.c.inc"
        break;
      case 85: /* lambda_args ::= PIPE ID PIPE */
#line 166 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1272 "vm/parser.c.inc"
        break;
      case 87: /* lambda ::= lambda_start lambda_args seq RB */
#line 169 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1277 "vm/parser.c.inc"
        break;
      case 88: /* stmt ::= IF s2 fin seq fin END */
#line 173 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1282 "vm/parser.c.inc"
        break;
      case 89: /* stmt ::= UNLESS s2 fin seq fin END */
#line 174 "vm/parser.lm"
{ yygotominor.yy88.a = S->unless(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1287 "vm/parser.c.inc"
        break;
      case 90: /* stmt ::= IMPORT ID */
#line 178 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1292 "vm/parser.c.inc"
        break;
      case 91: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 180 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1299 "vm/parser.c.inc"
        break;
      case 92: /* stmt ::= ID EQUAL s2 */
#line 184 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1304 "vm/parser.c.inc"
        break;
      case 93: /* stmt ::= IVAR EQUAL s2 */
#line 185 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1309 "vm/parser.c.inc"
        break;
      case 94: /* stmt ::= RAISE s2 */
#line 186 "vm/parser.lm"
{ yygotominor.yy88.a = S->raise(yymsp[0].minor.yy88.a); }
#line 1314 "vm/parser.c.inc"
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
      /* (56) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==56);
      /* (57) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==57);
      /* (58) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==58);
      /* (59) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==59);
      /* (60) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==60);
      /* (61) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==61);
      /* (86) lambda_args ::= */ yytestcase(yyruleno==86);
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
#line 1401 "vm/parser.c.inc"
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
