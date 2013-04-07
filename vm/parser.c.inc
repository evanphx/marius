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
#define YYNSTATE 216
#define YYNRULE 111
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
#define YY_ACTTAB_COUNT (945)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    32,  216,  211,  210,  211,  210,  209,   53,  207,   22,
 /*    10 */    48,   43,  205,  108,  125,   78,  200,  199,  198,  197,
 /*    20 */   196,  103,  193,  109,  119,   77,   76,   75,   34,  184,
 /*    30 */    29,   26,   25,   24,  115,   60,   32,  211,  210,   23,
 /*    40 */   211,  210,   28,   27,  207,  206,   48,  131,  205,  108,
 /*    50 */   125,   78,  200,  199,  198,  197,  196,  103,  193,   73,
 /*    60 */    79,  152,   76,   75,  124,  184,   20,   26,   25,   24,
 /*    70 */   115,   60,   32,  129,   72,   23,  211,  210,  192,   98,
 /*    80 */   207,  185,   48,  118,  205,   20,   81,   88,  200,  199,
 /*    90 */   198,  197,  196,  103,  193,   46,  134,    5,   76,   75,
 /*   100 */    21,  184,  154,   26,   25,   24,  115,   60,   32,   50,
 /*   110 */   190,   23,  211,  210,  211,  210,  136,  160,   48,  117,
 /*   120 */   148,   20,   80,  188,  200,  199,  198,  197,  196,  103,
 /*   130 */   193,  114,  211,  210,   76,   75,   71,  184,  144,   26,
 /*   140 */    25,   24,  115,   60,   32,  187,    4,   23,  211,  210,
 /*   150 */   116,  154,   20,  159,   48,  143,  112,   83,   20,  122,
 /*   160 */   200,  199,  198,  197,  196,  103,  193,   11,  180,  186,
 /*   170 */    76,   75,  154,  184,  175,   26,   25,   24,  115,   60,
 /*   180 */    32,  183,   17,   23,  211,  210,  128,  154,   20,  158,
 /*   190 */    48,  126,  179,   20,   20,  173,  200,  199,  198,  197,
 /*   200 */   196,  103,  193,  121,  170,   20,   76,   75,  172,  184,
 /*   210 */   169,   26,   25,   24,  115,   60,   32,   10,   16,   23,
 /*   220 */   211,  210,  154,  154,   44,   43,   48,  108,  125,   78,
 /*   230 */   328,    3,  200,  199,  198,  197,  196,  103,  193,    9,
 /*   240 */   157,   15,   76,   75,  154,  184,  154,   26,   25,   24,
 /*   250 */   115,   60,   58,  151,   32,   23,  146,   69,  211,  210,
 /*   260 */   120,   70,   20,  156,   48,  177,  174,   20,   20,   56,
 /*   270 */   200,  199,  198,  197,  196,  103,  193,    8,   74,   14,
 /*   280 */    76,   75,  154,  184,  154,   26,   25,   24,  115,   60,
 /*   290 */    32,    7,   19,   23,  211,  210,  154,   13,    6,  142,
 /*   300 */    48,  123,  154,  154,  114,  150,  200,  199,  198,  197,
 /*   310 */   196,  103,  193,   86,  113,   12,   76,   75,  145,  184,
 /*   320 */   154,   26,   25,   24,  115,   60,   32,    1,    2,   23,
 /*   330 */   211,  210,  154,  154,   18,  140,   48,  132,   84,  154,
 /*   340 */    89,  329,  200,  199,  198,  197,  196,  103,  193,  127,
 /*   350 */   147,   49,   76,   75,  111,  184,  191,   26,   25,   24,
 /*   360 */   115,   60,   32,  189,  181,   23,  211,  210,  176,  329,
 /*   370 */   329,  329,   48,  329,  329,  329,  329,  329,  200,  199,
 /*   380 */   198,  197,  196,  103,  193,  329,  329,  329,   76,   75,
 /*   390 */    32,  184,  329,   26,   25,   24,  115,   60,  329,  329,
 /*   400 */    48,   23,  329,  329,  329,  329,  200,  199,  198,  197,
 /*   410 */   196,  103,  193,  329,  329,  329,   76,   75,  276,  184,
 /*   420 */   329,   26,   25,   24,  115,   60,  329,  329,  276,   23,
 /*   430 */   329,   70,  329,  329,  276,  276,  276,  276,  276,  276,
 /*   440 */   276,  329,  195,   33,  329,  329,  329,  276,  200,  199,
 /*   450 */   198,  197,  196,  194,  193,   31,   30,   67,  329,  329,
 /*   460 */   139,  214,  213,  212,  208,  329,  329,  133,  138,  161,
 /*   470 */    82,  329,  203,   97,  329,  202,  329,  178,   67,  329,
 /*   480 */   171,  139,  214,  213,  212,  208,   88,  204,  133,  137,
 /*   490 */   161,   82,  201,  329,   97,  329,  329,  329,  178,  329,
 /*   500 */   329,  171,  329,  329,  329,   47,  329,   88,  139,  214,
 /*   510 */   213,  212,  135,  329,  329,  133,  167,  161,   82,   32,
 /*   520 */    97,   97,  329,  329,  178,  178,  329,  171,  171,   51,
 /*   530 */   329,  329,  329,   88,   88,  200,  199,  198,  197,  196,
 /*   540 */   194,  193,  329,  329,  329,   76,   75,  329,  184,  329,
 /*   550 */   329,  215,  214,  213,  212,  208,  192,  101,  133,  185,
 /*   560 */   161,   82,  276,  329,   97,   88,  329,  329,  178,  329,
 /*   570 */   329,  171,  276,  329,  329,   70,  329,   88,  276,  276,
 /*   580 */   276,  276,  276,  276,  276,  276,   45,   42,   41,   44,
 /*   590 */    43,  276,  108,  125,   78,  276,  329,  329,   73,  329,
 /*   600 */   329,  276,  276,  276,  276,  276,  276,  276,  276,   38,
 /*   610 */    39,   35,   37,   36,  276,  107,  119,   77,  276,  329,
 /*   620 */   329,   69,  329,  329,  276,  276,  276,  276,  276,  276,
 /*   630 */   276,  192,  102,  329,  185,  110,  329,  276,  329,  329,
 /*   640 */    88,  200,  199,  198,  197,  196,  194,  193,   40,  106,
 /*   650 */   329,   76,   75,  178,  184,  329,  171,  329,  195,  329,
 /*   660 */   329,  329,   88,  329,  200,  199,  198,  197,  196,  194,
 /*   670 */   193,   40,  329,  192,   91,  329,  185,  184,   68,  149,
 /*   680 */    85,  130,   88,  329,  329,  329,  329,  200,  199,  198,
 /*   690 */   197,  196,  194,  193,  192,  105,  329,  185,  153,  208,
 /*   700 */   184,   55,  329,   88,  161,  329,  141,  329,   97,  329,
 /*   710 */   153,  208,  178,   65,  329,  171,  161,  329,  329,  329,
 /*   720 */    97,   88,  153,  208,  178,   63,  329,  171,  161,  329,
 /*   730 */   329,  329,   97,   88,  329,  329,  178,  153,  208,  171,
 /*   740 */    61,  329,  329,  161,  329,   88,  329,   97,  329,  153,
 /*   750 */   208,  178,   59,  329,  171,  161,  329,  329,  329,   97,
 /*   760 */    88,  329,  329,  178,  153,  208,  171,   57,  192,  100,
 /*   770 */   161,  185,   88,  329,   97,  329,  153,   88,  178,   52,
 /*   780 */   329,  171,  161,  329,  329,  329,   97,   88,  182,  208,
 /*   790 */   178,  329,  329,  171,  161,  329,  329,  329,   97,   88,
 /*   800 */   329,  329,  178,  192,   90,  171,  185,  329,  329,  149,
 /*   810 */    87,   88,   88,  168,  166,  329,  329,   97,   97,  329,
 /*   820 */   329,  178,  178,  329,  171,  171,  329,  329,  165,  164,
 /*   830 */    88,   88,   97,   97,  329,  329,  178,  178,  329,  171,
 /*   840 */   171,  329,  329,  163,  162,   88,   88,   97,   97,  329,
 /*   850 */   329,  178,  178,  329,  171,  171,  329,  329,  329,  329,
 /*   860 */    88,   88,  329,  329,   66,   64,   62,  329,   97,   97,
 /*   870 */    97,  329,  178,  178,  178,  171,  171,  171,  329,  329,
 /*   880 */   155,   88,   88,   88,   97,  329,  329,  329,  178,  329,
 /*   890 */    54,  171,  329,  329,   97,  329,  329,   88,  178,  192,
 /*   900 */    99,  171,  185,  192,  104,  329,  185,   88,   88,  329,
 /*   910 */   192,   96,   88,  185,  192,   95,  329,  185,  329,   88,
 /*   920 */   329,  192,   94,   88,  185,  192,   93,  329,  185,  329,
 /*   930 */    88,  329,  329,  329,   88,  192,   92,  329,  185,  329,
 /*   940 */   329,  329,  329,  329,   88,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    0,   10,   11,   10,   11,   12,   16,   14,   17,
 /*    10 */    16,    5,   18,    7,    8,    9,   22,   23,   24,   25,
 /*    20 */    26,   27,   28,    7,    8,    9,   32,   33,    2,   35,
 /*    30 */    31,   37,   38,   39,   40,   41,    6,   10,   11,   45,
 /*    40 */    10,   11,   43,   44,   14,   15,   16,   16,   18,    7,
 /*    50 */     8,    9,   22,   23,   24,   25,   26,   27,   28,   19,
 /*    60 */    29,   34,   32,   33,   71,   35,   73,   37,   38,   39,
 /*    70 */    40,   41,    6,   16,   19,   45,   10,   11,   69,   70,
 /*    80 */    14,   72,   16,   71,   18,   73,   29,   78,   22,   23,
 /*    90 */    24,   25,   26,   27,   28,   31,   50,   51,   32,   33,
 /*   100 */    57,   35,   56,   37,   38,   39,   40,   41,    6,   16,
 /*   110 */    20,   45,   10,   11,   10,   11,   12,   15,   16,   71,
 /*   120 */    77,   73,   29,   20,   22,   23,   24,   25,   26,   27,
 /*   130 */    28,   13,   10,   11,   32,   33,   19,   35,   20,   37,
 /*   140 */    38,   39,   40,   41,    6,   16,   51,   45,   10,   11,
 /*   150 */    71,   56,   73,   15,   16,   64,   71,   66,   73,   16,
 /*   160 */    22,   23,   24,   25,   26,   27,   28,   51,   20,   30,
 /*   170 */    32,   33,   56,   35,   20,   37,   38,   39,   40,   41,
 /*   180 */     6,   36,   51,   45,   10,   11,   71,   56,   73,   15,
 /*   190 */    16,   71,   71,   73,   73,   16,   22,   23,   24,   25,
 /*   200 */    26,   27,   28,   71,   20,   73,   32,   33,   30,   35,
 /*   210 */    34,   37,   38,   39,   40,   41,    6,   51,   51,   45,
 /*   220 */    10,   11,   56,   56,    4,    5,   16,    7,    8,    9,
 /*   230 */    47,   48,   22,   23,   24,   25,   26,   27,   28,   51,
 /*   240 */    16,   51,   32,   33,   56,   35,   56,   37,   38,   39,
 /*   250 */    40,   41,   42,   10,    6,   45,   20,   19,   10,   11,
 /*   260 */    71,   19,   73,   15,   16,   71,   71,   73,   73,   67,
 /*   270 */    22,   23,   24,   25,   26,   27,   28,   51,   19,   51,
 /*   280 */    32,   33,   56,   35,   56,   37,   38,   39,   40,   41,
 /*   290 */     6,   51,   79,   45,   10,   11,   56,   51,   51,   15,
 /*   300 */    16,   36,   56,   56,   13,   75,   22,   23,   24,   25,
 /*   310 */    26,   27,   28,   57,   16,   51,   32,   33,   64,   35,
 /*   320 */    56,   37,   38,   39,   40,   41,    6,   51,   51,   45,
 /*   330 */    10,   11,   56,   56,   51,   15,   16,   16,   57,   56,
 /*   340 */    68,   80,   22,   23,   24,   25,   26,   27,   28,   69,
 /*   350 */    20,   69,   32,   33,   69,   35,   20,   37,   38,   39,
 /*   360 */    40,   41,    6,   20,   20,   45,   10,   11,   20,   80,
 /*   370 */    80,   80,   16,   80,   80,   80,   80,   80,   22,   23,
 /*   380 */    24,   25,   26,   27,   28,   80,   80,   80,   32,   33,
 /*   390 */     6,   35,   80,   37,   38,   39,   40,   41,   80,   80,
 /*   400 */    16,   45,   80,   80,   80,   80,   22,   23,   24,   25,
 /*   410 */    26,   27,   28,   80,   80,   80,   32,   33,    6,   35,
 /*   420 */    80,   37,   38,   39,   40,   41,   80,   80,   16,   45,
 /*   430 */    80,   19,   80,   80,   22,   23,   24,   25,   26,   27,
 /*   440 */    28,   80,   16,   31,   80,   80,   80,   35,   22,   23,
 /*   450 */    24,   25,   26,   27,   28,   43,   44,   49,   80,   80,
 /*   460 */    52,   53,   54,   55,   56,   80,   80,   59,   60,   61,
 /*   470 */    62,   80,    1,   65,   80,    4,   80,   69,   49,   80,
 /*   480 */    72,   52,   53,   54,   55,   56,   78,   16,   59,   60,
 /*   490 */    61,   62,   21,   80,   65,   80,   80,   80,   69,   80,
 /*   500 */    80,   72,   80,   80,   80,   49,   80,   78,   52,   53,
 /*   510 */    54,   55,   56,   80,   80,   59,   61,   61,   62,    6,
 /*   520 */    65,   65,   80,   80,   69,   69,   80,   72,   72,   16,
 /*   530 */    80,   80,   80,   78,   78,   22,   23,   24,   25,   26,
 /*   540 */    27,   28,   80,   80,   80,   32,   33,   80,   35,   80,
 /*   550 */    80,   52,   53,   54,   55,   56,   69,   70,   59,   72,
 /*   560 */    61,   62,    6,   80,   65,   78,   80,   80,   69,   80,
 /*   570 */    80,   72,   16,   80,   80,   19,   80,   78,   22,   23,
 /*   580 */    24,   25,   26,   27,   28,    6,    1,    2,    3,    4,
 /*   590 */     5,   35,    7,    8,    9,   16,   80,   80,   19,   80,
 /*   600 */    80,   22,   23,   24,   25,   26,   27,   28,    6,    1,
 /*   610 */     2,    3,    4,    5,   35,    7,    8,    9,   16,   80,
 /*   620 */    80,   19,   80,   80,   22,   23,   24,   25,   26,   27,
 /*   630 */    28,   69,   70,   80,   72,   16,   80,   35,   80,   80,
 /*   640 */    78,   22,   23,   24,   25,   26,   27,   28,    6,   65,
 /*   650 */    80,   32,   33,   69,   35,   80,   72,   80,   16,   80,
 /*   660 */    80,   80,   78,   80,   22,   23,   24,   25,   26,   27,
 /*   670 */    28,    6,   80,   69,   70,   80,   72,   35,   74,   75,
 /*   680 */    76,   16,   78,   80,   80,   80,   80,   22,   23,   24,
 /*   690 */    25,   26,   27,   28,   69,   70,   80,   72,   55,   56,
 /*   700 */    35,   58,   80,   78,   61,   80,   63,   80,   65,   80,
 /*   710 */    55,   56,   69,   58,   80,   72,   61,   80,   80,   80,
 /*   720 */    65,   78,   55,   56,   69,   58,   80,   72,   61,   80,
 /*   730 */    80,   80,   65,   78,   80,   80,   69,   55,   56,   72,
 /*   740 */    58,   80,   80,   61,   80,   78,   80,   65,   80,   55,
 /*   750 */    56,   69,   58,   80,   72,   61,   80,   80,   80,   65,
 /*   760 */    78,   80,   80,   69,   55,   56,   72,   58,   69,   70,
 /*   770 */    61,   72,   78,   80,   65,   80,   55,   78,   69,   58,
 /*   780 */    80,   72,   61,   80,   80,   80,   65,   78,   55,   56,
 /*   790 */    69,   80,   80,   72,   61,   80,   80,   80,   65,   78,
 /*   800 */    80,   80,   69,   69,   70,   72,   72,   80,   80,   75,
 /*   810 */    76,   78,   78,   61,   61,   80,   80,   65,   65,   80,
 /*   820 */    80,   69,   69,   80,   72,   72,   80,   80,   61,   61,
 /*   830 */    78,   78,   65,   65,   80,   80,   69,   69,   80,   72,
 /*   840 */    72,   80,   80,   61,   61,   78,   78,   65,   65,   80,
 /*   850 */    80,   69,   69,   80,   72,   72,   80,   80,   80,   80,
 /*   860 */    78,   78,   80,   80,   61,   61,   61,   80,   65,   65,
 /*   870 */    65,   80,   69,   69,   69,   72,   72,   72,   80,   80,
 /*   880 */    61,   78,   78,   78,   65,   80,   80,   80,   69,   80,
 /*   890 */    61,   72,   80,   80,   65,   80,   80,   78,   69,   69,
 /*   900 */    70,   72,   72,   69,   70,   80,   72,   78,   78,   80,
 /*   910 */    69,   70,   78,   72,   69,   70,   80,   72,   80,   78,
 /*   920 */    80,   69,   70,   78,   72,   69,   70,   80,   72,   80,
 /*   930 */    78,   80,   80,   80,   78,   69,   70,   80,   72,   80,
 /*   940 */    80,   80,   80,   80,   78,
};
#define YY_SHIFT_USE_DFLT (-10)
#define YY_SHIFT_COUNT (134)
#define YY_SHIFT_MIN   (-9)
#define YY_SHIFT_MAX   (665)
static const short yy_shift_ofst[] = {
 /*     0 */   -10,   66,   66,   66,   30,   -6,  320,  356,  356,  356,
 /*    10 */   356,  356,  284,  248,  210,  174,  138,  102,  356,  384,
 /*    20 */   665,  665,  513,  513,  513,  513,  513,  513,  513,  513,
 /*    30 */   513,  513,  513,  513,  619,  642,  642,  642,  642,  642,
 /*    40 */   642,  642,  642,  642,  642,  642,  642,  104,  412,  602,
 /*    50 */   579,  556,   27,   -8,  122,  122,  122,  122,  122,  122,
 /*    60 */   122,  122,  122,  122,  122,  122,  122,  122,  291,  348,
 /*    70 */   344,  343,  336,  330,  321,  -10,  -10,  -10,  -10,  426,
 /*    80 */   426,  426,  471,  118,  321,  291,  298,  291,  265,  259,
 /*    90 */   585,  585,  585,  585,  585,  585,  585,  608,  585,  220,
 /*   100 */   220,  220,    6,   -1,   42,   42,   16,   93,   57,   31,
 /*   110 */   242,  238,  236,   64,  243,  224,  176,  184,  178,  179,
 /*   120 */   154,  148,  145,  143,  139,  129,  103,  117,   90,   55,
 /*   130 */    64,   40,   26,   -9,    1,
};
#define YY_REDUCE_USE_DFLT (-8)
#define YY_REDUCE_COUNT (89)
#define YY_REDUCE_MIN   (-7)
#define YY_REDUCE_MAX   (866)
static const short yy_reduce_ofst[] = {
 /*     0 */   183,  429,  408,  456,  499,  499,  643,  709,  694,  682,
 /*    10 */   667,  655,  733,  733,  733,  733,  733,  733,  733,  721,
 /*    20 */   604,  734,  829,  819,  805,  804,  803,  783,  782,  768,
 /*    30 */   767,  753,  752,  455,  584,  866,  856,  852,  845,  841,
 /*    40 */   834,  830,  699,  625,  562,  487,    9,   46,  121,  195,
 /*    50 */   194,  121,  283,  277,  276,  264,  247,  246,  240,  228,
 /*    60 */   226,  190,  188,  167,  166,  131,  116,   95,   43,  189,
 /*    70 */   132,  120,  115,   85,   91,   79,   48,   12,   -7,  285,
 /*    80 */   282,  280,  272,  281,  254,  256,  230,  256,  213,  202,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   224,  327,  327,  327,  327,  327,  327,  327,  327,  327,
 /*    10 */   327,  327,  327,  327,  327,  327,  327,  327,  327,  327,
 /*    20 */   327,  327,  327,  327,  327,  327,  327,  327,  327,  327,
 /*    30 */   327,  327,  327,  327,  327,  327,  327,  327,  327,  327,
 /*    40 */   327,  327,  327,  327,  327,  327,  327,  327,  257,  293,
 /*    50 */   289,  257,  327,  327,  327,  327,  327,  327,  327,  327,
 /*    60 */   327,  327,  327,  327,  327,  327,  327,  327,  282,  276,
 /*    70 */   276,  276,  276,  276,  327,  276,  276,  276,  276,  327,
 /*    80 */   327,  327,  327,  327,  327,  285,  327,  283,  313,  244,
 /*    90 */   277,  278,  307,  306,  305,  304,  303,  308,  279,  265,
 /*   100 */   264,  261,  262,  258,  273,  263,  241,  327,  327,  327,
 /*   110 */   257,  293,  327,  327,  231,  327,  327,  327,  327,  327,
 /*   120 */   327,  327,  327,  327,  327,  327,  327,  270,  327,  266,
 /*   130 */   257,  289,  240,  327,  327,  225,  226,  237,  236,  218,
 /*   140 */   251,  250,  239,  243,  245,  242,  291,  290,  284,  281,
 /*   150 */   280,  230,  314,  233,  229,  326,  319,  318,  317,  316,
 /*   160 */   315,  310,  325,  324,  323,  322,  321,  320,  309,  298,
 /*   170 */   297,  296,  299,  292,  301,  295,  294,  300,  286,  302,
 /*   180 */   288,  287,  232,  312,  311,  274,  275,  269,  272,  271,
 /*   190 */   268,  267,  260,  259,  258,  257,  256,  255,  254,  253,
 /*   200 */   252,  249,  248,  247,  246,  238,  235,  234,  228,  227,
 /*   210 */   223,  222,  221,  220,  219,  217,
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
  "DCOLON",        "LSB",           "NL",            "SEMI",        
  "EOF",           "COMMA",         "CLASS",         "END",         
  "ID",            "LT",            "DEF",           "LP",          
  "RP",            "SQUARE",        "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "LITSTR",        "DOLLAR",        "RSB",           "EQUAL",       
  "TUPLE_START",   "DICT_START",    "RB",            "LB",          
  "PIPE",          "IF",            "UNLESS",        "WHILE",       
  "IMPORT",        "TRY",           "RESCUE",        "OP1_SET",     
  "OP0_SET",       "RAISE",         "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "fin_m",         "comma",         "seq",           "class_start", 
  "class_body",    "s2",            "def_start",     "def_body",    
  "arg",           "np_recv",       "id_list",       "def_args",    
  "def_name",      "lit",           "np_arg",        "np_arg_list", 
  "lambda",        "np_arg_list_start",  "np_arg_list_elems",  "np_kw_arg",   
  "np_kw_arg_list_elems",  "np_opt_kw_arg_list",  "lambda_start",  "lambda_args", 
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
 /*  59 */ "np_arg ::= np_arg LSB np_arg_list RSB",
 /*  60 */ "np_arg_list_start ::=",
 /*  61 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  62 */ "np_arg_list_elems ::= np_arg",
 /*  63 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  64 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  65 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  66 */ "np_opt_kw_arg_list ::=",
 /*  67 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  68 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  69 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  70 */ "np_recv ::= lit",
 /*  71 */ "np_recv ::= ID LP RP",
 /*  72 */ "np_recv ::= ID LP np_arg_list RP",
 /*  73 */ "np_recv ::= np_recv DOT ID",
 /*  74 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  75 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  76 */ "np_recv ::= np_recv DCOLON ID",
 /*  77 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  78 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  79 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  80 */ "np_recv ::= lambda",
 /*  81 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  82 */ "np_recv ::= DICT_START np_arg_list RB",
 /*  83 */ "np_recv ::= np_recv LSB np_arg_list RSB",
 /*  84 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  85 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  86 */ "s2 ::= ID np_arg_list",
 /*  87 */ "s2 ::= np_recv CAST np_arg",
 /*  88 */ "s2 ::= np_recv OP0 np_arg",
 /*  89 */ "s2 ::= np_recv OP1 np_arg",
 /*  90 */ "s2 ::= np_recv OP2 np_arg",
 /*  91 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  92 */ "s2 ::= np_recv",
 /*  93 */ "s2 ::= NOT s2",
 /*  94 */ "stmt ::= s2",
 /*  95 */ "lambda_start ::= LB",
 /*  96 */ "lambda_args ::= PIPE ID PIPE",
 /*  97 */ "lambda_args ::=",
 /*  98 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  99 */ "stmt ::= IF s2 fin seq fin END",
 /* 100 */ "stmt ::= UNLESS s2 fin seq fin END",
 /* 101 */ "stmt ::= WHILE s2 fin seq fin END",
 /* 102 */ "stmt ::= IMPORT ID",
 /* 103 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /* 104 */ "stmt ::= ID EQUAL s2",
 /* 105 */ "stmt ::= ID OP1_SET s2",
 /* 106 */ "stmt ::= ID OP0_SET s2",
 /* 107 */ "stmt ::= IVAR EQUAL s2",
 /* 108 */ "stmt ::= IVAR OP1_SET s2",
 /* 109 */ "stmt ::= IVAR OP0_SET s2",
 /* 110 */ "stmt ::= RAISE s2",
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
  { 66, 3 },
  { 66, 1 },
  { 67, 0 },
  { 67, 3 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 68, 1 },
  { 54, 5 },
  { 54, 5 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 70, 1 },
  { 70, 3 },
  { 70, 3 },
  { 70, 3 },
  { 70, 3 },
  { 70, 3 },
  { 70, 3 },
  { 70, 5 },
  { 70, 6 },
  { 70, 3 },
  { 70, 4 },
  { 70, 6 },
  { 70, 7 },
  { 70, 2 },
  { 70, 1 },
  { 70, 4 },
  { 73, 0 },
  { 74, 3 },
  { 74, 1 },
  { 75, 3 },
  { 76, 3 },
  { 76, 1 },
  { 77, 0 },
  { 77, 2 },
  { 71, 3 },
  { 71, 2 },
  { 65, 1 },
  { 65, 3 },
  { 65, 4 },
  { 65, 3 },
  { 65, 5 },
  { 65, 6 },
  { 65, 3 },
  { 65, 4 },
  { 65, 6 },
  { 65, 7 },
  { 65, 1 },
  { 65, 3 },
  { 65, 3 },
  { 65, 4 },
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
  { 72, 4 },
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
#line 31 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy128.a)); }
#line 1115 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 33 "vm/parser.lm"
{ yygotominor.yy128.a = S->seq(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1121 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 44: /* np_arg ::= lit */ yytestcase(yyruleno==44);
      case 58: /* np_arg ::= lambda */ yytestcase(yyruleno==58);
      case 70: /* np_recv ::= lit */ yytestcase(yyruleno==70);
      case 80: /* np_recv ::= lambda */ yytestcase(yyruleno==80);
      case 92: /* s2 ::= np_recv */ yytestcase(yyruleno==92);
      case 94: /* stmt ::= s2 */ yytestcase(yyruleno==94);
#line 34 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[0].minor.yy128.a; }
#line 1136 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 58 "vm/parser.lm"
{ S->start_class(); }
#line 1141 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 59 "vm/parser.lm"
{ yygotominor.yy128.a = yymsp[-2].minor.yy128.a; }
#line 1147 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 61 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy128.a);
             }
#line 1154 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 65 "vm/parser.lm"
{
               yygotominor.yy128.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a);
             }
#line 1161 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 69 "vm/parser.lm"
{ S->start_def(); }
#line 1166 "vm/parser.c.inc"
        break;
      case 24: /* arg ::= ID */
#line 72 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1171 "vm/parser.c.inc"
        break;
      case 25: /* arg ::= ID CAST np_recv */
#line 73 "vm/parser.lm"
{ S->def_arg_cast(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1176 "vm/parser.c.inc"
        break;
      case 30: /* def_name ::= ID */
      case 31: /* def_name ::= OP0 */ yytestcase(yyruleno==31);
      case 32: /* def_name ::= OP1 */ yytestcase(yyruleno==32);
      case 33: /* def_name ::= SQUARE */ yytestcase(yyruleno==33);
#line 81 "vm/parser.lm"
{ yygotominor.yy128.s = yymsp[0].minor.yy0.s; }
#line 1184 "vm/parser.c.inc"
        break;
      case 34: /* def ::= def_start def_name def_args fin def_body */
#line 87 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, yymsp[0].minor.yy128.a);
            }
#line 1191 "vm/parser.c.inc"
        break;
      case 35: /* def ::= def_start def_name def_args fin END */
#line 90 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_def(yymsp[-3].minor.yy128.s, S->ast_nil());
            }
#line 1198 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= NUM */
#line 94 "vm/parser.lm"
{ yygotominor.yy128.a = S->number(yymsp[0].minor.yy0.i); }
#line 1203 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= NIL */
#line 95 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_nil();  }
#line 1208 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= TRUE */
#line 96 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_true();  }
#line 1213 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= FALSE */
#line 97 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_false(); }
#line 1218 "vm/parser.c.inc"
        break;
      case 40: /* lit ::= SELF */
#line 98 "vm/parser.lm"
{ yygotominor.yy128.a = S->self(); }
#line 1223 "vm/parser.c.inc"
        break;
      case 41: /* lit ::= ID */
#line 99 "vm/parser.lm"
{ yygotominor.yy128.a = S->named(yymsp[0].minor.yy0.s); }
#line 1228 "vm/parser.c.inc"
        break;
      case 42: /* lit ::= IVAR */
#line 100 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1233 "vm/parser.c.inc"
        break;
      case 43: /* lit ::= LITSTR */
#line 101 "vm/parser.lm"
{ yygotominor.yy128.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1238 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg OP0 np_arg */
      case 46: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==46);
      case 88: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==88);
      case 89: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==89);
#line 105 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1246 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg OP2 np_arg */
      case 90: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==90);
#line 109 "vm/parser.lm"
{ yygotominor.yy128.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1252 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg CAST np_arg */
      case 87: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==87);
#line 111 "vm/parser.lm"
{ yygotominor.yy128.a = S->cast(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1258 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg NEQUAL np_arg */
      case 91: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==91);
#line 113 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy128.a, yymsp[0].minor.yy128.a)); }
#line 1264 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DOT ID */
      case 73: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==73);
#line 114 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-2].minor.yy128.a, yymsp[0].minor.yy0.s); }
#line 1270 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT ID LP RP */
      case 74: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==74);
#line 115 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy0.s); }
#line 1276 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 75: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==75);
#line 117 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-5].minor.yy128.a, yymsp[-3].minor.yy0.s); }
#line 1282 "vm/parser.c.inc"
        break;
      case 53: /* np_arg ::= np_arg DCOLON ID */
      case 76: /* np_recv ::= np_recv DCOLON ID */ yytestcase(yyruleno==76);
#line 118 "vm/parser.lm"
{ yygotominor.yy128.a = S->dcolon(yymsp[-2].minor.yy128.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1288 "vm/parser.c.inc"
        break;
      case 54: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 77: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==77);
#line 120 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-3].minor.yy128.a, yymsp[0].minor.yy128.a); }
#line 1294 "vm/parser.c.inc"
        break;
      case 55: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 78: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==78);
#line 122 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect(yymsp[-5].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1300 "vm/parser.c.inc"
        break;
      case 56: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 79: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==79);
#line 124 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-6].minor.yy128.a, yymsp[-3].minor.yy128.a); }
#line 1306 "vm/parser.c.inc"
        break;
      case 57: /* np_arg ::= NOT np_arg */
      case 93: /* s2 ::= NOT s2 */ yytestcase(yyruleno==93);
#line 125 "vm/parser.lm"
{ yygotominor.yy128.a = S->not_(yymsp[0].minor.yy128.a); }
#line 1312 "vm/parser.c.inc"
        break;
      case 59: /* np_arg ::= np_arg LSB np_arg_list RSB */
      case 83: /* np_recv ::= np_recv LSB np_arg_list RSB */ yytestcase(yyruleno==83);
#line 128 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-3].minor.yy128.a, "[]"); }
#line 1318 "vm/parser.c.inc"
        break;
      case 60: /* np_arg_list_start ::= */
#line 130 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1323 "vm/parser.c.inc"
        break;
      case 61: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 62: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==62);
#line 131 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy128.a); }
#line 1329 "vm/parser.c.inc"
        break;
      case 63: /* np_kw_arg ::= ID EQUAL np_arg */
#line 134 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1334 "vm/parser.c.inc"
        break;
      case 71: /* np_recv ::= ID LP RP */
#line 146 "vm/parser.lm"
{ yygotominor.yy128.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1339 "vm/parser.c.inc"
        break;
      case 72: /* np_recv ::= ID LP np_arg_list RP */
#line 147 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1344 "vm/parser.c.inc"
        break;
      case 81: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 159 "vm/parser.lm"
{ yygotominor.yy128.a = S->tuple(); }
#line 1349 "vm/parser.c.inc"
        break;
      case 82: /* np_recv ::= DICT_START np_arg_list RB */
#line 160 "vm/parser.lm"
{ yygotominor.yy128.a = S->dict(); }
#line 1354 "vm/parser.c.inc"
        break;
      case 84: /* s2 ::= np_recv DOT ID np_arg_list */
#line 164 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(yymsp[-3].minor.yy128.a, yymsp[-1].minor.yy0.s); }
#line 1359 "vm/parser.c.inc"
        break;
      case 85: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 166 "vm/parser.lm"
{ yygotominor.yy128.a = S->send_indirect_args(yymsp[-4].minor.yy128.a, yymsp[-1].minor.yy128.a); }
#line 1364 "vm/parser.c.inc"
        break;
      case 86: /* s2 ::= ID np_arg_list */
#line 167 "vm/parser.lm"
{ yygotominor.yy128.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1369 "vm/parser.c.inc"
        break;
      case 95: /* lambda_start ::= LB */
#line 181 "vm/parser.lm"
{ S->start_lambda(); }
#line 1374 "vm/parser.c.inc"
        break;
      case 96: /* lambda_args ::= PIPE ID PIPE */
#line 183 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1379 "vm/parser.c.inc"
        break;
      case 98: /* lambda ::= lambda_start lambda_args seq RB */
#line 186 "vm/parser.lm"
{ yygotominor.yy128.a = S->lambda(yymsp[-1].minor.yy128.a); }
#line 1384 "vm/parser.c.inc"
        break;
      case 99: /* stmt ::= IF s2 fin seq fin END */
#line 190 "vm/parser.lm"
{ yygotominor.yy128.a = S->if_cond(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1389 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= UNLESS s2 fin seq fin END */
#line 191 "vm/parser.lm"
{ yygotominor.yy128.a = S->unless(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1394 "vm/parser.c.inc"
        break;
      case 101: /* stmt ::= WHILE s2 fin seq fin END */
#line 192 "vm/parser.lm"
{ yygotominor.yy128.a = S->while_(yymsp[-4].minor.yy128.a, yymsp[-2].minor.yy128.a); }
#line 1399 "vm/parser.c.inc"
        break;
      case 102: /* stmt ::= IMPORT ID */
#line 196 "vm/parser.lm"
{ yygotominor.yy128.a = S->import(yymsp[0].minor.yy0.s); }
#line 1404 "vm/parser.c.inc"
        break;
      case 103: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 198 "vm/parser.lm"
{
              yygotominor.yy128.a = S->ast_try(yymsp[-6].minor.yy128.a, yymsp[-2].minor.yy128.a);
            }
#line 1411 "vm/parser.c.inc"
        break;
      case 104: /* stmt ::= ID EQUAL s2 */
#line 202 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1416 "vm/parser.c.inc"
        break;
      case 105: /* stmt ::= ID OP1_SET s2 */
      case 106: /* stmt ::= ID OP0_SET s2 */ yytestcase(yyruleno==106);
#line 203 "vm/parser.lm"
{ yygotominor.yy128.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1422 "vm/parser.c.inc"
        break;
      case 107: /* stmt ::= IVAR EQUAL s2 */
#line 205 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1427 "vm/parser.c.inc"
        break;
      case 108: /* stmt ::= IVAR OP1_SET s2 */
      case 109: /* stmt ::= IVAR OP0_SET s2 */ yytestcase(yyruleno==109);
#line 207 "vm/parser.lm"
{ yygotominor.yy128.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy128.a); }
#line 1433 "vm/parser.c.inc"
        break;
      case 110: /* stmt ::= RAISE s2 */
#line 210 "vm/parser.lm"
{ yygotominor.yy128.a = S->raise(yymsp[0].minor.yy128.a); }
#line 1438 "vm/parser.c.inc"
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
      /* (64) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==64);
      /* (65) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==65);
      /* (66) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==66);
      /* (67) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==67);
      /* (68) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==68);
      /* (69) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==69);
      /* (97) lambda_args ::= */ yytestcase(yyruleno==97);
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
#line 1527 "vm/parser.c.inc"
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
