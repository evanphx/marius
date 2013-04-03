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
#define YYNOCODE 73
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy16;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 185
#define YYNRULE 97
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
#define YY_ACTTAB_COUNT (883)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    28,  185,  180,  179,  178,   38,  176,   92,   43,   48,
 /*    10 */   174,  180,  179,  167,  166,  165,  164,  163,  101,  160,
 /*    20 */   180,  179,  117,   69,  153,  180,  179,   27,   26,   25,
 /*    30 */    95,   53,   22,   24,   28,  127,  180,  179,  112,   78,
 /*    40 */   176,  175,   43,  108,  174,  171,  172,  167,  166,  165,
 /*    50 */   164,  163,  101,  160,   96,   71,   20,   69,  153,  180,
 /*    60 */   179,   27,   26,   25,   95,   53,  173,   24,   28,   41,
 /*    70 */   180,  179,   39,   38,  176,   92,   43,  107,  174,   20,
 /*    80 */    92,  167,  166,  165,  164,  163,  101,  160,   45,   21,
 /*    90 */   157,   69,  153,  283,    3,   27,   26,   25,   95,   53,
 /*   100 */    70,   24,   28,   68,  180,  179,  124,  115,    5,  168,
 /*   110 */    43,   67,  105,  129,   20,  167,  166,  165,  164,  163,
 /*   120 */   101,  160,    4,  155,  102,   69,  153,  129,  152,   27,
 /*   130 */    26,   25,   95,   53,   29,   24,   28,  150,  180,  179,
 /*   140 */   100,  146,   20,  135,   43,   99,   98,   20,   20,  167,
 /*   150 */   166,  165,  164,  163,  101,  160,    6,  143,  141,   69,
 /*   160 */   153,  129,  132,   27,   26,   25,   95,   53,  139,   24,
 /*   170 */    28,   17,  180,  179,   61,   77,  129,  134,   43,  149,
 /*   180 */   145,   20,   20,  167,  166,  165,  164,  163,  101,  160,
 /*   190 */    11,   16,   72,   69,  153,  129,  129,   27,   26,   25,
 /*   200 */    95,   53,  170,   24,   28,   10,  180,  179,   19,  103,
 /*   210 */   129,  133,   43,  142,   74,   20,  112,  167,  166,  165,
 /*   220 */   164,  163,  101,  160,   15,  126,   94,   69,  153,  129,
 /*   230 */   106,   27,   26,   25,   95,   53,  111,   24,   28,    9,
 /*   240 */   180,  179,   14,   44,  129,    8,   43,  129,  158,  156,
 /*   250 */   129,  167,  166,  165,  164,  163,  101,  160,   13,  151,
 /*   260 */   147,   69,  153,  129,  144,   27,   26,   25,   95,   53,
 /*   270 */    51,   24,   28,    7,  180,  179,  284,  284,  129,  131,
 /*   280 */    43,  284,  284,  284,  284,  167,  166,  165,  164,  163,
 /*   290 */   101,  160,   12,    1,  284,   69,  153,  129,  129,   27,
 /*   300 */    26,   25,   95,   53,  284,   24,   28,    2,  180,  179,
 /*   310 */   284,  284,  129,  121,   43,  284,  284,  284,  284,  167,
 /*   320 */   166,  165,  164,  163,  101,  160,   18,  284,  284,   69,
 /*   330 */   153,  129,  284,   27,   26,   25,   95,   53,  284,   24,
 /*   340 */    28,  284,  180,  179,  284,  284,  284,  284,   43,  284,
 /*   350 */   284,  284,  284,  167,  166,  165,  164,  163,  101,  160,
 /*   360 */   284,  284,  284,   69,  153,  284,   28,   27,   26,   25,
 /*   370 */    95,   53,  284,   24,   43,  284,  284,  284,  284,  167,
 /*   380 */   166,  165,  164,  163,  101,  160,  284,  284,  284,   69,
 /*   390 */   153,  284,  284,   27,   26,   25,   95,   53,   62,   24,
 /*   400 */   284,  120,  183,  182,  181,  177,  284,  284,  114,  119,
 /*   410 */   136,  113,  284,  284,  284,  148,  284,  284,  140,  284,
 /*   420 */   284,  284,  284,   62,   79,   76,  120,  183,  182,  181,
 /*   430 */   177,  284,  284,  114,  118,  136,  113,  284,  284,  284,
 /*   440 */   148,   42,  284,  140,  120,  183,  182,  181,  116,   79,
 /*   450 */    76,  114,  284,  136,  113,  284,  159,   80,  148,  154,
 /*   460 */   284,  140,  125,   75,  284,  237,   76,   79,   76,  284,
 /*   470 */   284,  284,  284,  237,  284,  284,   66,  284,  237,  237,
 /*   480 */   237,  237,  237,  237,  237,  284,   23,  284,  284,  237,
 /*   490 */   184,  183,  182,  181,  177,  128,  177,  114,   60,  136,
 /*   500 */   113,  136,  284,  122,  148,  284,  148,  140,  284,  140,
 /*   510 */   284,  237,  284,   79,   76,   79,   76,  284,  284,  237,
 /*   520 */   284,  284,   66,  284,  237,  237,  237,  237,  237,  237,
 /*   530 */   237,  237,  284,  284,  284,  237,  284,  284,  284,  237,
 /*   540 */   284,  284,   65,  284,  237,  237,  237,  237,  237,  237,
 /*   550 */   237,  237,  284,  159,   87,  237,  154,  284,  284,  237,
 /*   560 */   284,  284,   64,   76,  237,  237,  237,  237,  237,  237,
 /*   570 */   237,   28,  284,  284,  284,  237,  284,  284,  284,   46,
 /*   580 */   284,  284,  284,  284,  167,  166,  165,  164,  163,  161,
 /*   590 */   160,   35,  284,  284,   69,  153,  284,  284,  284,  162,
 /*   600 */   284,  284,  284,  284,  167,  166,  165,  164,  163,  161,
 /*   610 */   160,   35,  284,  284,  284,  153,  284,  284,  284,  110,
 /*   620 */   284,  284,  284,  284,  167,  166,  165,  164,  163,  161,
 /*   630 */   160,  284,  284,  284,  162,  153,  284,  284,  284,  167,
 /*   640 */   166,  165,  164,  163,  161,  160,  284,  284,  284,  128,
 /*   650 */   177,  284,   58,  284,  284,  136,  284,  284,  284,  284,
 /*   660 */   148,  128,  177,  140,   56,  128,  177,  136,   54,   79,
 /*   670 */    76,  136,  148,  284,  284,  140,  148,  128,  177,  140,
 /*   680 */    52,   79,   76,  136,  284,   79,   76,  284,  148,  128,
 /*   690 */   177,  140,   50,  284,  284,  136,  284,   79,   76,  284,
 /*   700 */   148,  284,  284,  140,  284,  284,  284,  284,  284,   79,
 /*   710 */    76,   33,   34,   30,   32,   31,  284,   91,  284,  284,
 /*   720 */   284,  159,   81,  284,  154,  284,   63,  125,   73,  128,
 /*   730 */   284,   76,   47,  169,  177,  136,  284,  137,   97,  136,
 /*   740 */   148,  284,  148,  140,  148,  140,  284,  140,  284,   79,
 /*   750 */    76,   79,   76,   79,   76,   40,   37,   36,   39,   38,
 /*   760 */   284,   92,  284,  284,  284,  284,  138,  284,   59,  284,
 /*   770 */    57,  148,  284,  148,  140,  148,  140,  284,  140,  284,
 /*   780 */    79,   76,   79,   76,   79,   76,  284,   55,  284,  130,
 /*   790 */   284,  123,  148,  284,  148,  140,  148,  140,  284,  140,
 /*   800 */   284,   79,   76,   79,   76,   79,   76,   49,  159,   90,
 /*   810 */   284,  154,  148,  159,   93,  140,  154,  284,   76,  284,
 /*   820 */   284,   79,   76,   76,  284,  284,  284,  159,  109,  284,
 /*   830 */   154,  159,   89,  284,  154,  159,   88,   76,  154,  159,
 /*   840 */   104,   76,  154,  159,   86,   76,  154,  284,  284,   76,
 /*   850 */   284,  284,  284,   76,  284,  159,   85,  284,  154,  284,
 /*   860 */   159,   84,  284,  154,  284,   76,  159,   83,  284,  154,
 /*   870 */    76,  284,  159,   82,  284,  154,   76,  284,  284,  284,
 /*   880 */   284,  284,   76,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    0,    8,    9,   10,    5,   12,    7,   14,   14,
 /*    10 */    16,    8,    9,   19,   20,   21,   22,   23,   24,   25,
 /*    20 */     8,    9,   10,   29,   30,    8,    9,   33,   34,   35,
 /*    30 */    36,   37,   15,   39,    6,   32,    8,    9,   11,   14,
 /*    40 */    12,   13,   14,   14,   16,   18,   14,   19,   20,   21,
 /*    50 */    22,   23,   24,   25,   62,   26,   64,   29,   30,    8,
 /*    60 */     9,   33,   34,   35,   36,   37,    8,   39,    6,   27,
 /*    70 */     8,    9,    4,    5,   12,    7,   14,   62,   16,   64,
 /*    80 */     7,   19,   20,   21,   22,   23,   24,   25,   14,   51,
 /*    90 */    18,   29,   30,   41,   42,   33,   34,   35,   36,   37,
 /*   100 */    26,   39,    6,   17,    8,    9,   68,   44,   45,   13,
 /*   110 */    14,   17,   62,   50,   64,   19,   20,   21,   22,   23,
 /*   120 */    24,   25,   45,   18,   14,   29,   30,   50,   31,   33,
 /*   130 */    34,   35,   36,   37,   27,   39,    6,   18,    8,    9,
 /*   140 */    62,   18,   64,   13,   14,   62,   62,   64,   64,   19,
 /*   150 */    20,   21,   22,   23,   24,   25,   45,   18,   14,   29,
 /*   160 */    30,   50,   14,   33,   34,   35,   36,   37,   18,   39,
 /*   170 */     6,   45,    8,    9,   59,   17,   50,   13,   14,   62,
 /*   180 */    62,   64,   64,   19,   20,   21,   22,   23,   24,   25,
 /*   190 */    45,   45,   58,   29,   30,   50,   50,   33,   34,   35,
 /*   200 */    36,   37,   14,   39,    6,   45,    8,    9,   71,   31,
 /*   210 */    50,   13,   14,   62,   51,   64,   11,   19,   20,   21,
 /*   220 */    22,   23,   24,   25,   45,   66,   14,   29,   30,   50,
 /*   230 */    60,   33,   34,   35,   36,   37,   51,   39,    6,   45,
 /*   240 */     8,    9,   45,   60,   50,   45,   14,   50,   18,   18,
 /*   250 */    50,   19,   20,   21,   22,   23,   24,   25,   45,   18,
 /*   260 */    18,   29,   30,   50,   18,   33,   34,   35,   36,   37,
 /*   270 */    38,   39,    6,   45,    8,    9,   72,   72,   50,   13,
 /*   280 */    14,   72,   72,   72,   72,   19,   20,   21,   22,   23,
 /*   290 */    24,   25,   45,   45,   72,   29,   30,   50,   50,   33,
 /*   300 */    34,   35,   36,   37,   72,   39,    6,   45,    8,    9,
 /*   310 */    72,   72,   50,   13,   14,   72,   72,   72,   72,   19,
 /*   320 */    20,   21,   22,   23,   24,   25,   45,   72,   72,   29,
 /*   330 */    30,   50,   72,   33,   34,   35,   36,   37,   72,   39,
 /*   340 */     6,   72,    8,    9,   72,   72,   72,   72,   14,   72,
 /*   350 */    72,   72,   72,   19,   20,   21,   22,   23,   24,   25,
 /*   360 */    72,   72,   72,   29,   30,   72,    6,   33,   34,   35,
 /*   370 */    36,   37,   72,   39,   14,   72,   72,   72,   72,   19,
 /*   380 */    20,   21,   22,   23,   24,   25,   72,   72,   72,   29,
 /*   390 */    30,   72,   72,   33,   34,   35,   36,   37,   43,   39,
 /*   400 */    72,   46,   47,   48,   49,   50,   72,   72,   53,   54,
 /*   410 */    55,   56,   72,   72,   72,   60,   72,   72,   63,   72,
 /*   420 */    72,   72,   72,   43,   69,   70,   46,   47,   48,   49,
 /*   430 */    50,   72,   72,   53,   54,   55,   56,   72,   72,   72,
 /*   440 */    60,   43,   72,   63,   46,   47,   48,   49,   50,   69,
 /*   450 */    70,   53,   72,   55,   56,   72,   60,   61,   60,   63,
 /*   460 */    72,   63,   66,   67,   72,    6,   70,   69,   70,   72,
 /*   470 */    72,   72,   72,   14,   72,   72,   17,   72,   19,   20,
 /*   480 */    21,   22,   23,   24,   25,   72,   27,   72,   72,   30,
 /*   490 */    46,   47,   48,   49,   50,   49,   50,   53,   52,   55,
 /*   500 */    56,   55,   72,   57,   60,   72,   60,   63,   72,   63,
 /*   510 */    72,    6,   72,   69,   70,   69,   70,   72,   72,   14,
 /*   520 */    72,   72,   17,   72,   19,   20,   21,   22,   23,   24,
 /*   530 */    25,    6,   72,   72,   72,   30,   72,   72,   72,   14,
 /*   540 */    72,   72,   17,   72,   19,   20,   21,   22,   23,   24,
 /*   550 */    25,    6,   72,   60,   61,   30,   63,   72,   72,   14,
 /*   560 */    72,   72,   17,   70,   19,   20,   21,   22,   23,   24,
 /*   570 */    25,    6,   72,   72,   72,   30,   72,   72,   72,   14,
 /*   580 */    72,   72,   72,   72,   19,   20,   21,   22,   23,   24,
 /*   590 */    25,    6,   72,   72,   29,   30,   72,   72,   72,   14,
 /*   600 */    72,   72,   72,   72,   19,   20,   21,   22,   23,   24,
 /*   610 */    25,    6,   72,   72,   72,   30,   72,   72,   72,   14,
 /*   620 */    72,   72,   72,   72,   19,   20,   21,   22,   23,   24,
 /*   630 */    25,   72,   72,   72,   14,   30,   72,   72,   72,   19,
 /*   640 */    20,   21,   22,   23,   24,   25,   72,   72,   72,   49,
 /*   650 */    50,   72,   52,   72,   72,   55,   72,   72,   72,   72,
 /*   660 */    60,   49,   50,   63,   52,   49,   50,   55,   52,   69,
 /*   670 */    70,   55,   60,   72,   72,   63,   60,   49,   50,   63,
 /*   680 */    52,   69,   70,   55,   72,   69,   70,   72,   60,   49,
 /*   690 */    50,   63,   52,   72,   72,   55,   72,   69,   70,   72,
 /*   700 */    60,   72,   72,   63,   72,   72,   72,   72,   72,   69,
 /*   710 */    70,    1,    2,    3,    4,    5,   72,    7,   72,   72,
 /*   720 */    72,   60,   61,   72,   63,   72,   65,   66,   67,   49,
 /*   730 */    72,   70,   52,   49,   50,   55,   72,   55,   28,   55,
 /*   740 */    60,   72,   60,   63,   60,   63,   72,   63,   72,   69,
 /*   750 */    70,   69,   70,   69,   70,    1,    2,    3,    4,    5,
 /*   760 */    72,    7,   72,   72,   72,   72,   55,   72,   55,   72,
 /*   770 */    55,   60,   72,   60,   63,   60,   63,   72,   63,   72,
 /*   780 */    69,   70,   69,   70,   69,   70,   72,   55,   72,   55,
 /*   790 */    72,   55,   60,   72,   60,   63,   60,   63,   72,   63,
 /*   800 */    72,   69,   70,   69,   70,   69,   70,   55,   60,   61,
 /*   810 */    72,   63,   60,   60,   61,   63,   63,   72,   70,   72,
 /*   820 */    72,   69,   70,   70,   72,   72,   72,   60,   61,   72,
 /*   830 */    63,   60,   61,   72,   63,   60,   61,   70,   63,   60,
 /*   840 */    61,   70,   63,   60,   61,   70,   63,   72,   72,   70,
 /*   850 */    72,   72,   72,   70,   72,   60,   61,   72,   63,   72,
 /*   860 */    60,   61,   72,   63,   72,   70,   60,   61,   72,   63,
 /*   870 */    70,   72,   60,   61,   72,   63,   70,   72,   72,   72,
 /*   880 */    72,   72,   70,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (115)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (754)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   62,   62,   62,   28,   -6,  300,  334,  334,  334,
 /*    10 */   334,  334,  266,  232,  198,  164,  130,   96,  334,  360,
 /*    20 */   605,  605,  565,  565,  565,  565,  565,  565,  565,  565,
 /*    30 */   585,  585,  585,  585,  585,  585,  585,  585,  585,  585,
 /*    40 */   585,  585,   12,  459,  545,  525,  505,    3,   17,   51,
 /*    50 */    51,   51,   51,   51,   51,   51,   51,   51,   51,   51,
 /*    60 */    51,   51,   51,  205,  246,  242,  241,  231,  230,   -7,
 /*    70 */   620,  620,   27,  205,  212,  205,  178,  188,  158,  710,
 /*    80 */   754,  754,  754,  754,  754,  754,  754,  754,   68,   68,
 /*    90 */    68,   74,   29,    0,   42,  148,  150,  144,  139,  123,
 /*   100 */   119,  107,   97,  110,   73,  105,   94,   72,   86,   73,
 /*   110 */    42,   32,   58,   25,   -5,    1,
};
#define YY_REDUCE_USE_DFLT (-9)
#define YY_REDUCE_COUNT (78)
#define YY_REDUCE_MIN   (-8)
#define YY_REDUCE_MAX   (812)
static const short yy_reduce_ofst[] = {
 /*     0 */    52,  380,  355,  398,  444,  444,  446,  640,  628,  616,
 /*    10 */   612,  600,  684,  684,  684,  684,  684,  684,  684,  680,
 /*    20 */   661,  396,  752,  736,  734,  732,  715,  713,  711,  682,
 /*    30 */   812,  806,  800,  795,  783,  779,  775,  771,  767,  753,
 /*    40 */   748,  493,   63,  117,  151,  118,  117,  281,  262,  248,
 /*    50 */   247,  228,  213,  200,  197,  194,  179,  160,  146,  145,
 /*    60 */   126,  111,   77,   38,   84,   83,   78,   50,   15,   -8,
 /*    70 */   183,  170,  185,  163,  159,  163,  137,  134,  115,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   193,  282,  282,  282,  282,  282,  282,  282,  282,  282,
 /*    10 */   282,  282,  282,  282,  282,  282,  282,  282,  282,  282,
 /*    20 */   282,  282,  282,  282,  282,  282,  282,  282,  282,  282,
 /*    30 */   282,  282,  282,  282,  282,  282,  282,  282,  282,  282,
 /*    40 */   282,  282,  282,  220,  254,  250,  220,  282,  282,  282,
 /*    50 */   282,  282,  282,  282,  282,  282,  282,  282,  282,  282,
 /*    60 */   282,  282,  282,  243,  237,  237,  237,  237,  237,  237,
 /*    70 */   282,  282,  282,  246,  282,  244,  272,  282,  211,  267,
 /*    80 */   238,  239,  266,  265,  264,  263,  262,  240,  228,  227,
 /*    90 */   224,  282,  282,  225,  282,  282,  282,  282,  282,  282,
 /*   100 */   282,  221,  282,  282,  235,  282,  232,  282,  229,  226,
 /*   110 */   220,  282,  200,  282,  282,  282,  194,  195,  206,  205,
 /*   120 */   187,  214,  213,  279,  245,  242,  241,  273,  202,  198,
 /*   130 */   281,  278,  277,  276,  275,  274,  269,  280,  268,  258,
 /*   140 */   257,  253,  260,  256,  255,  259,  252,  251,  247,  261,
 /*   150 */   249,  248,  271,  270,  236,  234,  233,  231,  230,  223,
 /*   160 */   222,  221,  220,  219,  218,  217,  216,  215,  208,  201,
 /*   170 */   210,  212,  209,  199,  207,  204,  203,  197,  196,  192,
 /*   180 */   191,  190,  189,  188,  186,
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
 /*  73 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  74 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  75 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  76 */ "s2 ::= ID np_arg_list",
 /*  77 */ "s2 ::= np_recv CAST np_arg",
 /*  78 */ "s2 ::= np_recv OP0 np_arg",
 /*  79 */ "s2 ::= np_recv OP1 np_arg",
 /*  80 */ "s2 ::= np_recv OP2 np_arg",
 /*  81 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  82 */ "s2 ::= np_recv",
 /*  83 */ "s2 ::= NOT s2",
 /*  84 */ "stmt ::= s2",
 /*  85 */ "lambda_start ::= LB",
 /*  86 */ "lambda_args ::= PIPE ID PIPE",
 /*  87 */ "lambda_args ::=",
 /*  88 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  89 */ "stmt ::= IF s2 fin seq fin END",
 /*  90 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  91 */ "stmt ::= WHILE s2 fin seq fin END",
 /*  92 */ "stmt ::= IMPORT ID",
 /*  93 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  94 */ "stmt ::= ID EQUAL s2",
 /*  95 */ "stmt ::= IVAR EQUAL s2",
 /*  96 */ "stmt ::= RAISE s2",
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
  { 48, 5 },
  { 48, 5 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 60, 1 },
  { 61, 1 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 3 },
  { 61, 5 },
  { 61, 6 },
  { 61, 4 },
  { 61, 6 },
  { 61, 7 },
  { 61, 2 },
  { 61, 1 },
  { 64, 0 },
  { 65, 3 },
  { 65, 1 },
  { 66, 3 },
  { 67, 3 },
  { 67, 1 },
  { 68, 0 },
  { 68, 2 },
  { 62, 3 },
  { 62, 2 },
  { 69, 1 },
  { 69, 3 },
  { 69, 4 },
  { 69, 3 },
  { 69, 5 },
  { 69, 6 },
  { 69, 3 },
  { 69, 4 },
  { 69, 6 },
  { 69, 7 },
  { 69, 1 },
  { 69, 3 },
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
  { 70, 1 },
  { 71, 3 },
  { 71, 0 },
  { 63, 4 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy16.a)); }
#line 1067 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy16.a = S->seq(yymsp[-2].minor.yy16.a, yymsp[0].minor.yy16.a); }
#line 1073 "vm/parser.c.inc"
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
      case 82: /* s2 ::= np_recv */ yytestcase(yyruleno==82);
      case 84: /* stmt ::= s2 */ yytestcase(yyruleno==84);
#line 33 "vm/parser.lm"
{ yygotominor.yy16.a = yymsp[0].minor.yy16.a; }
#line 1088 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1093 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy16.a = yymsp[-2].minor.yy16.a; }
#line 1099 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy16.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy16.a);
             }
#line 1106 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy16.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy16.a, yymsp[0].minor.yy16.a);
             }
#line 1113 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1118 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 1124 "vm/parser.c.inc"
        break;
      case 28: /* def ::= def_start ID def_args fin def_body */
#line 77 "vm/parser.lm"
{
              yygotominor.yy16.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy16.a);
            }
#line 1131 "vm/parser.c.inc"
        break;
      case 29: /* def ::= def_start ID def_args fin END */
#line 80 "vm/parser.lm"
{
              yygotominor.yy16.a = S->ast_def(*yymsp[-3].minor.yy0.s, S->ast_nil());
            }
#line 1138 "vm/parser.c.inc"
        break;
      case 30: /* lit ::= NUM */
#line 84 "vm/parser.lm"
{ yygotominor.yy16.a = S->number(yymsp[0].minor.yy0.i); }
#line 1143 "vm/parser.c.inc"
        break;
      case 31: /* lit ::= NIL */
#line 85 "vm/parser.lm"
{ yygotominor.yy16.a = S->ast_nil();  }
#line 1148 "vm/parser.c.inc"
        break;
      case 32: /* lit ::= TRUE */
#line 86 "vm/parser.lm"
{ yygotominor.yy16.a = S->ast_true();  }
#line 1153 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= FALSE */
#line 87 "vm/parser.lm"
{ yygotominor.yy16.a = S->ast_false(); }
#line 1158 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= SELF */
#line 88 "vm/parser.lm"
{ yygotominor.yy16.a = S->self(); }
#line 1163 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= ID */
#line 89 "vm/parser.lm"
{ yygotominor.yy16.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1168 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= IVAR */
#line 90 "vm/parser.lm"
{ yygotominor.yy16.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1173 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= LITSTR */
#line 91 "vm/parser.lm"
{ yygotominor.yy16.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1178 "vm/parser.c.inc"
        break;
      case 39: /* np_arg ::= np_arg OP0 np_arg */
      case 40: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==40);
      case 41: /* np_arg ::= np_arg OP2 np_arg */ yytestcase(yyruleno==41);
      case 78: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==78);
      case 79: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==79);
      case 80: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==80);
#line 95 "vm/parser.lm"
{ yygotominor.yy16.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy16.a, yymsp[0].minor.yy16.a); }
#line 1188 "vm/parser.c.inc"
        break;
      case 42: /* np_arg ::= np_arg CAST np_arg */
      case 77: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==77);
#line 101 "vm/parser.lm"
{ yygotominor.yy16.a = S->cast(yymsp[-2].minor.yy16.a, yymsp[0].minor.yy16.a); }
#line 1194 "vm/parser.c.inc"
        break;
      case 43: /* np_arg ::= np_arg NEQUAL np_arg */
      case 81: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==81);
#line 103 "vm/parser.lm"
{ yygotominor.yy16.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy16.a, yymsp[0].minor.yy16.a)); }
#line 1200 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg DOT ID */
      case 65: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==65);
#line 104 "vm/parser.lm"
{ yygotominor.yy16.a = S->call(yymsp[-2].minor.yy16.a, *yymsp[0].minor.yy0.s); }
#line 1206 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg DOT ID LP RP */
      case 66: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==66);
#line 105 "vm/parser.lm"
{ yygotominor.yy16.a = S->call(yymsp[-4].minor.yy16.a, *yymsp[-2].minor.yy0.s); }
#line 1212 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 67: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==67);
#line 107 "vm/parser.lm"
{ yygotominor.yy16.a = S->call_args(yymsp[-5].minor.yy16.a, *yymsp[-3].minor.yy0.s); }
#line 1218 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 69: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==69);
#line 109 "vm/parser.lm"
{ yygotominor.yy16.a = S->send_indirect(yymsp[-3].minor.yy16.a, yymsp[0].minor.yy16.a); }
#line 1224 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 70: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==70);
#line 111 "vm/parser.lm"
{ yygotominor.yy16.a = S->send_indirect(yymsp[-5].minor.yy16.a, yymsp[-2].minor.yy16.a); }
#line 1230 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 71: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==71);
#line 113 "vm/parser.lm"
{ yygotominor.yy16.a = S->send_indirect_args(yymsp[-6].minor.yy16.a, yymsp[-3].minor.yy16.a); }
#line 1236 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= NOT np_arg */
      case 83: /* s2 ::= NOT s2 */ yytestcase(yyruleno==83);
#line 114 "vm/parser.lm"
{ yygotominor.yy16.a = S->not_(yymsp[0].minor.yy16.a); }
#line 1242 "vm/parser.c.inc"
        break;
      case 52: /* np_arg_list_start ::= */
#line 117 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1247 "vm/parser.c.inc"
        break;
      case 53: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 54: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==54);
#line 118 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy16.a); }
#line 1253 "vm/parser.c.inc"
        break;
      case 55: /* np_kw_arg ::= ID EQUAL np_arg */
#line 121 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy16.a); }
#line 1258 "vm/parser.c.inc"
        break;
      case 63: /* np_recv ::= ID LP RP */
#line 133 "vm/parser.lm"
{ yygotominor.yy16.a = S->call(S->self(), *yymsp[-2].minor.yy0.s); }
#line 1263 "vm/parser.c.inc"
        break;
      case 64: /* np_recv ::= ID LP np_arg_list RP */
#line 134 "vm/parser.lm"
{ yygotominor.yy16.a = S->call_args(S->self(), *yymsp[-3].minor.yy0.s); }
#line 1268 "vm/parser.c.inc"
        break;
      case 68: /* np_recv ::= np_recv DCOLON ID */
#line 138 "vm/parser.lm"
{ yygotominor.yy16.a = S->dcolon(yymsp[-2].minor.yy16.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1273 "vm/parser.c.inc"
        break;
      case 73: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 146 "vm/parser.lm"
{ yygotominor.yy16.a = S->tuple(); }
#line 1278 "vm/parser.c.inc"
        break;
      case 74: /* s2 ::= np_recv DOT ID np_arg_list */
#line 148 "vm/parser.lm"
{ yygotominor.yy16.a = S->call_args(yymsp[-3].minor.yy16.a, *yymsp[-1].minor.yy0.s); }
#line 1283 "vm/parser.c.inc"
        break;
      case 75: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 150 "vm/parser.lm"
{ yygotominor.yy16.a = S->send_indirect_args(yymsp[-4].minor.yy16.a, yymsp[-1].minor.yy16.a); }
#line 1288 "vm/parser.c.inc"
        break;
      case 76: /* s2 ::= ID np_arg_list */
#line 151 "vm/parser.lm"
{ yygotominor.yy16.a = S->call_args(S->self(), *yymsp[-1].minor.yy0.s); }
#line 1293 "vm/parser.c.inc"
        break;
      case 85: /* lambda_start ::= LB */
#line 165 "vm/parser.lm"
{ S->start_lambda(); }
#line 1298 "vm/parser.c.inc"
        break;
      case 86: /* lambda_args ::= PIPE ID PIPE */
#line 167 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1303 "vm/parser.c.inc"
        break;
      case 88: /* lambda ::= lambda_start lambda_args seq RB */
#line 170 "vm/parser.lm"
{ yygotominor.yy16.a = S->lambda(yymsp[-1].minor.yy16.a); }
#line 1308 "vm/parser.c.inc"
        break;
      case 89: /* stmt ::= IF s2 fin seq fin END */
#line 174 "vm/parser.lm"
{ yygotominor.yy16.a = S->if_cond(yymsp[-4].minor.yy16.a, yymsp[-2].minor.yy16.a); }
#line 1313 "vm/parser.c.inc"
        break;
      case 90: /* stmt ::= UNLESS s2 fin seq fin END */
#line 175 "vm/parser.lm"
{ yygotominor.yy16.a = S->unless(yymsp[-4].minor.yy16.a, yymsp[-2].minor.yy16.a); }
#line 1318 "vm/parser.c.inc"
        break;
      case 91: /* stmt ::= WHILE s2 fin seq fin END */
#line 176 "vm/parser.lm"
{ yygotominor.yy16.a = S->while_(yymsp[-4].minor.yy16.a, yymsp[-2].minor.yy16.a); }
#line 1323 "vm/parser.c.inc"
        break;
      case 92: /* stmt ::= IMPORT ID */
#line 180 "vm/parser.lm"
{ yygotominor.yy16.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1328 "vm/parser.c.inc"
        break;
      case 93: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 182 "vm/parser.lm"
{
              yygotominor.yy16.a = S->ast_try(yymsp[-6].minor.yy16.a, yymsp[-2].minor.yy16.a);
            }
#line 1335 "vm/parser.c.inc"
        break;
      case 94: /* stmt ::= ID EQUAL s2 */
#line 186 "vm/parser.lm"
{ yygotominor.yy16.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy16.a); }
#line 1340 "vm/parser.c.inc"
        break;
      case 95: /* stmt ::= IVAR EQUAL s2 */
#line 187 "vm/parser.lm"
{ yygotominor.yy16.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy16.a); }
#line 1345 "vm/parser.c.inc"
        break;
      case 96: /* stmt ::= RAISE s2 */
#line 188 "vm/parser.lm"
{ yygotominor.yy16.a = S->raise(yymsp[0].minor.yy16.a); }
#line 1350 "vm/parser.c.inc"
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
      /* (87) lambda_args ::= */ yytestcase(yyruleno==87);
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
#line 1437 "vm/parser.c.inc"
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
