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
#define YYNOCODE 68
#define YYACTIONTYPE unsigned char
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy78;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 132
#define YYNRULE 71
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
#define YY_ACTTAB_COUNT (555)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   126,  127,  125,   75,   64,  121,  123,   73,   70,   69,
 /*    10 */   115,  114,  113,  112,  111,   63,   74,  107,  132,  126,
 /*    20 */    33,  125,  124,   64,   95,  123,   26,   62,   37,  115,
 /*    30 */   114,  113,  112,  111,   63,   74,  107,  126,   79,   46,
 /*    40 */   125,  100,   64,   95,  123,   26,   62,   37,  115,  114,
 /*    50 */   113,  112,  111,   63,   74,  107,  122,  126,  108,  125,
 /*    60 */    25,   64,   95,  123,   26,   62,   37,  115,  114,  113,
 /*    70 */   112,  111,   63,   74,  107,  105,  126,   21,   22,  118,
 /*    80 */    64,   95,   27,   26,   62,   37,  115,  114,  113,  112,
 /*    90 */   111,   63,   74,  107,  104,  126,   99,   99,   93,   64,
 /*   100 */    95,   18,   26,   62,   37,  115,  114,  113,  112,  111,
 /*   110 */    63,   74,  107,  103,  126,   73,   70,   69,   64,   95,
 /*   120 */    41,   26,   62,   37,  115,  114,  113,  112,  111,   63,
 /*   130 */    74,  107,   23,   24,   21,   22,   99,   65,   95,   99,
 /*   140 */    26,   62,   37,   35,  126,   94,   99,   91,   64,   23,
 /*   150 */    24,   21,   22,   20,  115,  114,  113,  112,  111,   63,
 /*   160 */    74,  107,   98,  126,   78,    5,   19,   64,   95,   89,
 /*   170 */    26,   62,   37,  115,  114,  113,  112,  111,   63,   74,
 /*   180 */   107,   99,   80,   87,   73,   70,   69,   95,   85,   26,
 /*   190 */    62,   37,   92,   47,   86,   99,   83,  130,  129,  128,
 /*   200 */     4,   77,   82,   53,   76,  106,   54,   57,  106,   52,
 /*   210 */    45,    7,  106,   52,   44,   60,   58,   59,   40,   96,
 /*   220 */    39,  120,   40,   96,   39,    6,   47,  106,   30,   83,
 /*   230 */   130,  129,  128,   16,   77,   81,   53,   76,   88,   56,
 /*   240 */    12,  106,   52,   67,  106,   52,  204,    3,   32,  102,
 /*   250 */    97,   40,   96,   39,   40,   96,   39,   66,   11,   15,
 /*   260 */     9,   64,   14,    8,   13,    2,   55,  115,  114,  113,
 /*   270 */   112,  111,   63,   74,  107,   17,   10,    1,   72,  205,
 /*   280 */   205,   95,  205,   26,   62,   37,  205,  205,  205,  205,
 /*   290 */   205,   28,  205,  205,   83,  130,  129,  128,  205,   77,
 /*   300 */   205,   53,   76,  205,  117,  205,  106,   52,  205,  106,
 /*   310 */    52,  205,  205,  205,  205,  205,   40,   96,   39,   40,
 /*   320 */    96,   39,  205,  131,  130,  129,  128,  205,   77,  205,
 /*   330 */    53,   76,  205,  205,  205,  106,   52,  205,  205,   90,
 /*   340 */    31,  205,  205,   53,  205,   40,   96,   39,  106,   52,
 /*   350 */   205,  205,  205,  205,  205,  110,  205,  205,   40,   96,
 /*   360 */    39,  115,  114,  113,  112,  111,  109,   74,  107,  205,
 /*   370 */   205,   71,  205,  205,  205,   95,  205,  115,  114,  113,
 /*   380 */   112,  111,  109,   74,  107,  205,  205,  110,  205,  205,
 /*   390 */   205,   95,  205,  115,  114,  113,  112,  111,  109,   74,
 /*   400 */   107,  205,  205,  205,   51,  205,  205,  205,  205,  106,
 /*   410 */    52,  205,   42,  205,   61,  205,  101,  205,  205,   40,
 /*   420 */    96,   39,  205,   90,   43,  205,  205,   53,  205,   84,
 /*   430 */   205,  205,  106,   52,  205,  205,  205,  205,  205,  205,
 /*   440 */    50,  205,   40,   96,   39,  106,   52,  205,  205,  205,
 /*   450 */    68,  205,  101,  205,  205,   40,   96,   39,  205,   90,
 /*   460 */    38,  205,  205,   53,  205,  205,   90,   36,  106,   52,
 /*   470 */    53,  205,  205,  205,  205,  106,   52,  205,   40,   96,
 /*   480 */    39,  205,  205,  205,  205,   40,   96,   39,   90,   34,
 /*   490 */   205,  119,   53,  205,  205,   53,  205,  106,   52,  116,
 /*   500 */   106,   52,  205,  205,  106,   52,  205,   40,   96,   39,
 /*   510 */    40,   96,   39,  205,   40,   96,   39,   49,  205,  205,
 /*   520 */   205,  205,  106,   52,   48,  205,  205,  205,  205,  106,
 /*   530 */    52,  205,   40,   96,   39,  205,  205,   29,  205,   40,
 /*   540 */    96,   39,  106,   52,  205,  205,  205,  205,  205,  205,
 /*   550 */   205,  205,   40,   96,   39,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,    6,    7,   12,    9,   14,   11,   23,   24,   25,
 /*    10 */    15,   16,   17,   18,   19,   20,   21,   22,    0,    5,
 /*    20 */     9,    7,    8,    9,   29,   11,   31,   32,   33,   15,
 /*    30 */    16,   17,   18,   19,   20,   21,   22,    5,    5,    9,
 /*    40 */     7,    9,    9,   29,   11,   31,   32,   33,   15,   16,
 /*    50 */    17,   18,   19,   20,   21,   22,    9,    5,    9,    7,
 /*    60 */     9,    9,   29,   11,   31,   32,   33,   15,   16,   17,
 /*    70 */    18,   19,   20,   21,   22,   14,    5,    3,    4,    8,
 /*    80 */     9,   29,   26,   31,   32,   33,   15,   16,   17,   18,
 /*    90 */    19,   20,   21,   22,    9,    5,    5,    5,    8,    9,
 /*   100 */    29,   10,   31,   32,   33,   15,   16,   17,   18,   19,
 /*   110 */    20,   21,   22,    9,    5,   23,   24,   25,    9,   29,
 /*   120 */    12,   31,   32,   33,   15,   16,   17,   18,   19,   20,
 /*   130 */    21,   22,    1,    2,    3,    4,    5,    9,   29,    5,
 /*   140 */    31,   32,   33,   34,    5,   30,    5,    8,    9,    1,
 /*   150 */     2,    3,    4,   26,   15,   16,   17,   18,   19,   20,
 /*   160 */    21,   22,   28,    5,   39,   40,   26,    9,   29,   28,
 /*   170 */    31,   32,   33,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    5,    6,   14,   23,   24,   25,   29,   27,   31,
 /*   190 */    32,   33,    9,   38,   14,    5,   41,   42,   43,   44,
 /*   200 */    40,   46,   47,   48,   49,   53,   54,   48,   53,   54,
 /*   210 */    13,   55,   53,   54,   52,   59,   51,   61,   63,   64,
 /*   220 */    65,    9,   63,   64,   65,   40,   38,   53,   54,   41,
 /*   230 */    42,   43,   44,   40,   46,   47,   48,   49,   57,   48,
 /*   240 */    12,   53,   54,    9,   53,   54,   36,   37,   62,   60,
 /*   250 */     9,   63,   64,   65,   63,   64,   65,   30,   66,   40,
 /*   260 */    40,    9,   40,   40,   40,   40,   40,   15,   16,   17,
 /*   270 */    18,   19,   20,   21,   22,   40,   40,   40,   13,   67,
 /*   280 */    67,   29,   67,   31,   32,   33,   67,   67,   67,   67,
 /*   290 */    67,   38,   67,   67,   41,   42,   43,   44,   67,   46,
 /*   300 */    67,   48,   49,   67,   48,   67,   53,   54,   67,   53,
 /*   310 */    54,   67,   67,   67,   67,   67,   63,   64,   65,   63,
 /*   320 */    64,   65,   67,   41,   42,   43,   44,   67,   46,   67,
 /*   330 */    48,   49,   67,   67,   67,   53,   54,   67,   67,   44,
 /*   340 */    45,   67,   67,   48,   67,   63,   64,   65,   53,   54,
 /*   350 */    67,   67,   67,   67,   67,    9,   67,   67,   63,   64,
 /*   360 */    65,   15,   16,   17,   18,   19,   20,   21,   22,   67,
 /*   370 */    67,    9,   67,   67,   67,   29,   67,   15,   16,   17,
 /*   380 */    18,   19,   20,   21,   22,   67,   67,    9,   67,   67,
 /*   390 */    67,   29,   67,   15,   16,   17,   18,   19,   20,   21,
 /*   400 */    22,   67,   67,   67,   48,   67,   67,   67,   67,   53,
 /*   410 */    54,   67,   56,   67,   58,   67,   60,   67,   67,   63,
 /*   420 */    64,   65,   67,   44,   45,   67,   67,   48,   67,   50,
 /*   430 */    67,   67,   53,   54,   67,   67,   67,   67,   67,   67,
 /*   440 */    48,   67,   63,   64,   65,   53,   54,   67,   67,   67,
 /*   450 */    58,   67,   60,   67,   67,   63,   64,   65,   67,   44,
 /*   460 */    45,   67,   67,   48,   67,   67,   44,   45,   53,   54,
 /*   470 */    48,   67,   67,   67,   67,   53,   54,   67,   63,   64,
 /*   480 */    65,   67,   67,   67,   67,   63,   64,   65,   44,   45,
 /*   490 */    67,   44,   48,   67,   67,   48,   67,   53,   54,   48,
 /*   500 */    53,   54,   67,   67,   53,   54,   67,   63,   64,   65,
 /*   510 */    63,   64,   65,   67,   63,   64,   65,   48,   67,   67,
 /*   520 */    67,   67,   53,   54,   48,   67,   67,   67,   67,   53,
 /*   530 */    54,   67,   63,   64,   65,   67,   67,   48,   67,   63,
 /*   540 */    64,   65,   53,   54,   67,   67,   67,   67,   67,   67,
 /*   550 */    67,   67,   63,   64,   65,
};
#define YY_SHIFT_USE_DFLT (-17)
#define YY_SHIFT_COUNT (78)
#define YY_SHIFT_MIN   (-16)
#define YY_SHIFT_MAX   (378)
static const short yy_shift_ofst[] = {
 /*     0 */   -17,   52,   52,   33,   14,   -5,  158,  362,  158,  158,
 /*    10 */   158,  252,  362,  139,  109,   90,   71,  158,  346,  346,
 /*    20 */   346,  346,  346,  346,  346,  265,  378,  378,  176,  131,
 /*    30 */    92,  141,  134,   91,  190,  190,  190,  190,  190,  227,
 /*    40 */   241,  234,  228,  190,  190,  212,  197,  190,  148,  148,
 /*    50 */   148,  148,  161,  148,  -16,   32,   74,   74,   -9,  180,
 /*    60 */   169,  108,  183,  140,  127,  115,  128,   56,  108,  104,
 /*    70 */    85,   56,   61,   51,   49,   47,   30,   11,   18,
};
#define YY_REDUCE_USE_DFLT (-1)
#define YY_REDUCE_COUNT (47)
#define YY_REDUCE_MIN   (0)
#define YY_REDUCE_MAX   (489)
static const short yy_reduce_ofst[] = {
 /*     0 */   210,  188,  155,  253,  282,  282,  379,  356,  444,  422,
 /*    10 */   415,  295,  392,  447,  447,  447,  447,  447,  489,  476,
 /*    20 */   469,  451,  256,  191,  159,  156,  174,  152,  125,  237,
 /*    30 */   236,  235,  226,  225,  224,  223,  222,  220,  219,  192,
 /*    40 */   186,  189,  181,  193,  185,  165,  162,  160,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   138,  203,  203,  203,  203,  203,  203,  203,  203,  203,
 /*    10 */   203,  203,  203,  203,  203,  203,  203,  203,  203,  203,
 /*    20 */   203,  203,  203,  203,  203,  171,  203,  203,  203,  203,
 /*    30 */   203,  203,  203,  203,  203,  203,  203,  203,  203,  195,
 /*    40 */   203,  203,  177,  203,  203,  203,  154,  203,  202,  201,
 /*    50 */   175,  176,  191,  197,  182,  203,  158,  157,  203,  203,
 /*    60 */   203,  185,  203,  167,  166,  203,  203,  203,  178,  203,
 /*    70 */   203,  166,  174,  203,  203,  203,  203,  203,  203,  139,
 /*    80 */   140,  149,  148,  134,  156,  189,  186,  181,  179,  196,
 /*    90 */   145,  200,  199,  198,  194,  193,  192,  188,  190,  143,
 /*   100 */   187,  184,  183,  173,  172,  180,  170,  169,  168,  167,
 /*   110 */   166,  165,  164,  163,  162,  161,  160,  159,  151,  144,
 /*   120 */   153,  155,  152,  150,  147,  146,  142,  141,  137,  136,
 /*   130 */   135,  133,
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
  "TIMES",         "FIN",           "EOF",           "CLASS",       
  "END",           "ID",            "LT",            "DEF",         
  "COMMA",         "LP",            "RP",            "NUM",         
  "NIL",           "TRUE",          "FALSE",         "SELF",        
  "IVAR",          "COLON",         "LITSTR",        "DOT",         
  "ATTR",          "DCOLON",        "EQUAL",         "CASCADE",     
  "RB",            "LB",            "PIPE",          "IF",          
  "IMPORT",        "TRY",           "RESCUE",        "error",       
  "program",       "opt_fin",       "l1",            "last_fin",    
  "fin",           "l1e",           "class",         "def",         
  "stmt",          "seq",           "class_start",   "class_body",  
  "expr",          "def_start",     "def_body",      "id_list",     
  "def_args",      "sexpr",         "send",          "arg_list_start",
  "arg_list_elems",  "opt_kw_arg_list",  "kw_arg_list_elems",  "arg_list",    
  "kw_arg",        "kw_arg_list",   "message_seq",   "cascade_start",
  "cascade",       "lambda_start",  "lambda_args", 
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
 /*  29 */ "sexpr ::= NUM",
 /*  30 */ "sexpr ::= NIL",
 /*  31 */ "sexpr ::= TRUE",
 /*  32 */ "sexpr ::= FALSE",
 /*  33 */ "sexpr ::= SELF",
 /*  34 */ "sexpr ::= ID",
 /*  35 */ "sexpr ::= IVAR",
 /*  36 */ "sexpr ::= COLON ID",
 /*  37 */ "sexpr ::= LITSTR",
 /*  38 */ "send ::= sexpr",
 /*  39 */ "send ::= send DOT ID",
 /*  40 */ "send ::= send ATTR ID",
 /*  41 */ "send ::= send DCOLON ID",
 /*  42 */ "arg_list_start ::= LP",
 /*  43 */ "arg_list_elems ::= arg_list_elems COMMA expr",
 /*  44 */ "arg_list_elems ::= expr",
 /*  45 */ "opt_kw_arg_list ::=",
 /*  46 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  47 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  48 */ "send ::= send DOT ID LP RP",
 /*  49 */ "send ::= send DOT ID arg_list RP",
 /*  50 */ "kw_arg ::= ID EQUAL send",
 /*  51 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  52 */ "kw_arg_list_elems ::= kw_arg",
 /*  53 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  54 */ "send ::= send DOT ID kw_arg_list RP",
 /*  55 */ "message_seq ::= message_seq fin ID",
 /*  56 */ "message_seq ::= ID",
 /*  57 */ "cascade_start ::= send CASCADE",
 /*  58 */ "cascade ::= cascade_start message_seq RB",
 /*  59 */ "cascade ::= send",
 /*  60 */ "expr ::= cascade",
 /*  61 */ "lambda_start ::= LB",
 /*  62 */ "lambda_args ::= PIPE ID PIPE",
 /*  63 */ "lambda_args ::=",
 /*  64 */ "expr ::= lambda_start lambda_args seq RB",
 /*  65 */ "stmt ::= expr",
 /*  66 */ "stmt ::= IF send fin seq fin END",
 /*  67 */ "stmt ::= IMPORT ID",
 /*  68 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  69 */ "stmt ::= ID EQUAL expr",
 /*  70 */ "stmt ::= IVAR EQUAL expr",
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
  { 36, 3 },
  { 38, 3 },
  { 38, 1 },
  { 41, 1 },
  { 41, 1 },
  { 41, 1 },
  { 37, 0 },
  { 37, 2 },
  { 39, 1 },
  { 39, 2 },
  { 40, 2 },
  { 40, 1 },
  { 45, 3 },
  { 45, 1 },
  { 46, 1 },
  { 47, 3 },
  { 42, 4 },
  { 42, 6 },
  { 49, 1 },
  { 50, 3 },
  { 51, 3 },
  { 51, 1 },
  { 52, 0 },
  { 52, 3 },
  { 43, 5 },
  { 48, 3 },
  { 48, 3 },
  { 48, 3 },
  { 48, 3 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 1 },
  { 53, 2 },
  { 53, 1 },
  { 54, 1 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 55, 1 },
  { 56, 3 },
  { 56, 1 },
  { 57, 0 },
  { 57, 2 },
  { 59, 3 },
  { 54, 5 },
  { 54, 5 },
  { 60, 3 },
  { 58, 3 },
  { 58, 1 },
  { 61, 2 },
  { 54, 5 },
  { 62, 3 },
  { 62, 1 },
  { 63, 2 },
  { 64, 3 },
  { 64, 1 },
  { 48, 1 },
  { 65, 1 },
  { 66, 3 },
  { 66, 0 },
  { 48, 4 },
  { 44, 1 },
  { 44, 6 },
  { 44, 2 },
  { 44, 9 },
  { 44, 3 },
  { 44, 3 },
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
#line 27 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy78.a)); }
#line 936 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 29 "vm/parser.lm"
{ yygotominor.yy78.a = S->seq(yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a); }
#line 942 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 38: /* send ::= sexpr */ yytestcase(yyruleno==38);
      case 59: /* cascade ::= send */ yytestcase(yyruleno==59);
      case 60: /* expr ::= cascade */ yytestcase(yyruleno==60);
      case 65: /* stmt ::= expr */ yytestcase(yyruleno==65);
#line 30 "vm/parser.lm"
{ yygotominor.yy78.a = yymsp[0].minor.yy78.a; }
#line 955 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 48 "vm/parser.lm"
{ S->start_class(); }
#line 960 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 19: /* def_body ::= seq fin END */ yytestcase(yyruleno==19);
#line 49 "vm/parser.lm"
{ yygotominor.yy78.a = yymsp[-2].minor.yy78.a; }
#line 966 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 51 "vm/parser.lm"
{
               yygotominor.yy78.a = S->ast_class(*yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy78.a);
             }
#line 973 "vm/parser.c.inc"
        break;
      case 17: /* class ::= class_start ID LT expr fin class_body */
#line 55 "vm/parser.lm"
{
               yygotominor.yy78.a = S->ast_class(*yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a);
             }
#line 980 "vm/parser.c.inc"
        break;
      case 18: /* def_start ::= DEF */
#line 59 "vm/parser.lm"
{ S->start_def(); }
#line 985 "vm/parser.c.inc"
        break;
      case 20: /* id_list ::= id_list COMMA ID */
      case 21: /* id_list ::= ID */ yytestcase(yyruleno==21);
#line 62 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 991 "vm/parser.c.inc"
        break;
      case 24: /* def ::= def_start ID def_args fin def_body */
#line 68 "vm/parser.lm"
{
              yygotominor.yy78.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy78.a);
            }
#line 998 "vm/parser.c.inc"
        break;
      case 25: /* expr ::= expr MINUS expr */
#line 72 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_binop("-", yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a); }
#line 1003 "vm/parser.c.inc"
        break;
      case 26: /* expr ::= expr PLUS expr */
#line 73 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_binop("+", yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a); }
#line 1008 "vm/parser.c.inc"
        break;
      case 27: /* expr ::= expr TIMES expr */
#line 74 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_binop("*", yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a); }
#line 1013 "vm/parser.c.inc"
        break;
      case 28: /* expr ::= expr DIVIDE expr */
#line 75 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_binop("/", yymsp[-2].minor.yy78.a, yymsp[0].minor.yy78.a); }
#line 1018 "vm/parser.c.inc"
        break;
      case 29: /* sexpr ::= NUM */
#line 77 "vm/parser.lm"
{ yygotominor.yy78.a = S->number(yymsp[0].minor.yy0.i); }
#line 1023 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= NIL */
#line 78 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_nil();  }
#line 1028 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= TRUE */
#line 79 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_true();  }
#line 1033 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= FALSE */
#line 80 "vm/parser.lm"
{ yygotominor.yy78.a = S->ast_false(); }
#line 1038 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= SELF */
#line 81 "vm/parser.lm"
{ yygotominor.yy78.a = S->self(); }
#line 1043 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= ID */
#line 82 "vm/parser.lm"
{ yygotominor.yy78.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1048 "vm/parser.c.inc"
        break;
      case 35: /* sexpr ::= IVAR */
#line 83 "vm/parser.lm"
{ yygotominor.yy78.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1053 "vm/parser.c.inc"
        break;
      case 36: /* sexpr ::= COLON ID */
      case 37: /* sexpr ::= LITSTR */ yytestcase(yyruleno==37);
#line 84 "vm/parser.lm"
{ yygotominor.yy78.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1059 "vm/parser.c.inc"
        break;
      case 39: /* send ::= send DOT ID */
#line 88 "vm/parser.lm"
{ yygotominor.yy78.a = S->call(yymsp[-2].minor.yy78.a, *yymsp[0].minor.yy0.s); }
#line 1064 "vm/parser.c.inc"
        break;
      case 40: /* send ::= send ATTR ID */
#line 89 "vm/parser.lm"
{ yygotominor.yy78.a = S->attr(yymsp[-2].minor.yy78.a, *yymsp[0].minor.yy0.s); }
#line 1069 "vm/parser.c.inc"
        break;
      case 41: /* send ::= send DCOLON ID */
#line 90 "vm/parser.lm"
{ yygotominor.yy78.a = S->dcolon(yymsp[-2].minor.yy78.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1074 "vm/parser.c.inc"
        break;
      case 42: /* arg_list_start ::= LP */
#line 94 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1079 "vm/parser.c.inc"
        break;
      case 43: /* arg_list_elems ::= arg_list_elems COMMA expr */
      case 44: /* arg_list_elems ::= expr */ yytestcase(yyruleno==44);
#line 95 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy78.a); }
#line 1085 "vm/parser.c.inc"
        break;
      case 48: /* send ::= send DOT ID LP RP */
#line 103 "vm/parser.lm"
{ yygotominor.yy78.a = S->call(yymsp[-4].minor.yy78.a, *yymsp[-2].minor.yy0.s); }
#line 1090 "vm/parser.c.inc"
        break;
      case 49: /* send ::= send DOT ID arg_list RP */
#line 104 "vm/parser.lm"
{ yygotominor.yy78.a = S->call_args(yymsp[-4].minor.yy78.a, *yymsp[-2].minor.yy0.s); }
#line 1095 "vm/parser.c.inc"
        break;
      case 50: /* kw_arg ::= ID EQUAL send */
#line 108 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy78.a); }
#line 1100 "vm/parser.c.inc"
        break;
      case 54: /* send ::= send DOT ID kw_arg_list RP */
#line 115 "vm/parser.lm"
{
              yygotominor.yy78.a = S->call_kw_args(yymsp[-4].minor.yy78.a, *yymsp[-2].minor.yy0.s);
            }
#line 1107 "vm/parser.c.inc"
        break;
      case 55: /* message_seq ::= message_seq fin ID */
      case 56: /* message_seq ::= ID */ yytestcase(yyruleno==56);
#line 121 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1113 "vm/parser.c.inc"
        break;
      case 57: /* cascade_start ::= send CASCADE */
#line 124 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy78.a); }
#line 1118 "vm/parser.c.inc"
        break;
      case 58: /* cascade ::= cascade_start message_seq RB */
#line 125 "vm/parser.lm"
{ yygotominor.yy78.a = S->end_cascade(); }
#line 1123 "vm/parser.c.inc"
        break;
      case 61: /* lambda_start ::= LB */
#line 133 "vm/parser.lm"
{ S->start_lambda(); }
#line 1128 "vm/parser.c.inc"
        break;
      case 62: /* lambda_args ::= PIPE ID PIPE */
#line 135 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1133 "vm/parser.c.inc"
        break;
      case 64: /* expr ::= lambda_start lambda_args seq RB */
#line 138 "vm/parser.lm"
{ yygotominor.yy78.a = S->lambda(yymsp[-1].minor.yy78.a); }
#line 1138 "vm/parser.c.inc"
        break;
      case 66: /* stmt ::= IF send fin seq fin END */
#line 146 "vm/parser.lm"
{ yygotominor.yy78.a = S->if_cond(yymsp[-4].minor.yy78.a, yymsp[-2].minor.yy78.a); }
#line 1143 "vm/parser.c.inc"
        break;
      case 67: /* stmt ::= IMPORT ID */
#line 150 "vm/parser.lm"
{ yygotominor.yy78.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1148 "vm/parser.c.inc"
        break;
      case 68: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 152 "vm/parser.lm"
{
              yygotominor.yy78.a = S->ast_try(yymsp[-6].minor.yy78.a, yymsp[-2].minor.yy78.a);
            }
#line 1155 "vm/parser.c.inc"
        break;
      case 69: /* stmt ::= ID EQUAL expr */
#line 156 "vm/parser.lm"
{ yygotominor.yy78.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy78.a); }
#line 1160 "vm/parser.c.inc"
        break;
      case 70: /* stmt ::= IVAR EQUAL expr */
#line 157 "vm/parser.lm"
{ yygotominor.yy78.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy78.a); }
#line 1165 "vm/parser.c.inc"
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
      /* (45) opt_kw_arg_list ::= */ yytestcase(yyruleno==45);
      /* (46) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==46);
      /* (47) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==47);
      /* (51) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==51);
      /* (52) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==52);
      /* (53) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==53);
      /* (63) lambda_args ::= */ yytestcase(yyruleno==63);
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
#line 20 "vm/parser.lm"

  S->set_syntax_error();

  std::cout << "Syntax error at line " << S->line()
            << ", column " << S->column() << std::endl;
#line 1248 "vm/parser.c.inc"
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
