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
#define YYNOCODE 67
#define YYACTIONTYPE unsigned char
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy76;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 128
#define YYNRULE 70
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
#define YY_ACTTAB_COUNT (463)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   122,  123,  121,  128,   61,  119,   54,  102,   49,  111,
 /*    10 */   110,  109,  108,  107,   60,   71,  103,   36,   92,   35,
 /*    20 */    70,   67,   66,   91,   81,   24,   59,   33,   72,  122,
 /*    30 */   117,  121,  120,   61,  119,   53,  102,   49,  111,  110,
 /*    40 */   109,  108,  107,   60,   71,  103,   36,   92,   35,   70,
 /*    50 */    67,   66,   91,    6,   24,   59,   33,   57,   76,   56,
 /*    60 */   121,   95,   61,  119,  113,  102,   49,  111,  110,  109,
 /*    70 */   108,  107,   60,   71,  103,   36,   92,   35,   70,   67,
 /*    80 */    66,   91,  122,   24,   59,   33,   96,  122,   44,  121,
 /*    90 */    42,   61,  119,  112,  102,   49,  111,  110,  109,  108,
 /*   100 */   107,   60,   71,  103,   36,   92,   35,   19,   20,  101,
 /*   110 */    91,  118,   24,   59,   33,  104,  122,   23,   95,  114,
 /*   120 */    61,  100,   46,  102,   49,  111,  110,  109,  108,  107,
 /*   130 */    60,   71,  103,   36,   92,   35,   75,    4,   99,   91,
 /*   140 */    94,   24,   59,   33,   25,  122,   95,   77,   89,   61,
 /*   150 */    37,   45,  102,   49,  111,  110,  109,  108,  107,   60,
 /*   160 */    71,  103,   36,   92,   35,  122,   62,   95,   91,   61,
 /*   170 */    24,   59,   33,   90,  111,  110,  109,  108,  107,   60,
 /*   180 */    71,  103,   21,   22,   19,   20,  102,   51,   91,   85,
 /*   190 */    24,   59,   33,   31,  122,  102,   27,   87,   61,  199,
 /*   200 */     2,   18,   17,  111,  110,  109,  108,  107,   60,   71,
 /*   210 */   103,   88,   83,   82,  122,   95,   40,   91,   61,   24,
 /*   220 */    59,   33,    1,  111,  110,  109,  108,  107,   60,   71,
 /*   230 */   103,    3,   41,   55,  116,    5,   15,   91,   84,   24,
 /*   240 */    59,   33,   43,   11,   98,   79,  126,  125,  124,   64,
 /*   250 */    74,   78,   73,   93,   29,   10,   50,  102,   49,   63,
 /*   260 */    14,    8,   13,    7,   69,   12,   61,   36,   92,   35,
 /*   270 */    52,  111,  110,  109,  108,  107,   60,   71,  103,  200,
 /*   280 */    16,    9,  200,  200,  200,   91,  200,   24,   59,   33,
 /*   290 */    26,  200,  200,   79,  126,  125,  124,  200,   74,  200,
 /*   300 */    73,  200,  200,  200,   50,  102,   49,  127,  126,  125,
 /*   310 */   124,  200,   74,  200,   73,   36,   92,   35,   50,  102,
 /*   320 */    49,  200,  200,  200,  200,  200,  200,  106,  200,   36,
 /*   330 */    92,   35,  111,  110,  109,  108,  107,  105,   71,  103,
 /*   340 */   200,  200,   68,  200,  200,  200,   91,  111,  110,  109,
 /*   350 */   108,  107,  105,   71,  103,  200,  200,  106,  200,  200,
 /*   360 */   200,   91,  111,  110,  109,  108,  107,  105,   71,  103,
 /*   370 */    48,  102,   49,  200,   38,  200,   58,  200,   97,   86,
 /*   380 */    39,   36,   92,   35,   80,  200,  200,   50,  102,   49,
 /*   390 */   200,  200,  200,  200,  200,  200,   86,   28,   36,   92,
 /*   400 */    35,   47,  102,   49,   50,  102,   49,   65,  200,   97,
 /*   410 */    86,   34,   36,   92,   35,   36,   92,   35,   50,  102,
 /*   420 */    49,  200,  200,  200,   86,   32,  200,   86,   30,   36,
 /*   430 */    92,   35,   50,  102,   49,   50,  102,   49,  200,  200,
 /*   440 */   200,  115,  200,   36,   92,   35,   36,   92,   35,   50,
 /*   450 */   102,   49,  200,  200,  200,  200,  200,  200,  200,  200,
 /*   460 */    36,   92,   35,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,    6,    7,    0,    9,   10,   51,   52,   53,   14,
 /*    10 */    15,   16,   17,   18,   19,   20,   21,   62,   63,   64,
 /*    20 */    22,   23,   24,   28,   26,   30,   31,   32,   11,    5,
 /*    30 */    13,    7,    8,    9,   10,   51,   52,   53,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   21,   62,   63,   64,   22,
 /*    50 */    23,   24,   28,   54,   30,   31,   32,   58,    5,   60,
 /*    60 */     7,    5,    9,   10,   51,   52,   53,   14,   15,   16,
 /*    70 */    17,   18,   19,   20,   21,   62,   63,   64,   22,   23,
 /*    80 */    24,   28,    5,   30,   31,   32,    9,    5,    9,    7,
 /*    90 */     9,    9,   10,   51,   52,   53,   14,   15,   16,   17,
 /*   100 */    18,   19,   20,   21,   62,   63,   64,    3,    4,   13,
 /*   110 */    28,    9,   30,   31,   32,    9,    5,    9,    5,    8,
 /*   120 */     9,    9,   51,   52,   53,   14,   15,   16,   17,   18,
 /*   130 */    19,   20,   21,   62,   63,   64,   38,   39,    9,   28,
 /*   140 */    27,   30,   31,   32,   25,    5,    5,    6,    8,    9,
 /*   150 */    11,   51,   52,   53,   14,   15,   16,   17,   18,   19,
 /*   160 */    20,   21,   62,   63,   64,    5,    9,    5,   28,    9,
 /*   170 */    30,   31,   32,   29,   14,   15,   16,   17,   18,   19,
 /*   180 */    20,   21,    1,    2,    3,    4,   52,   53,   28,   27,
 /*   190 */    30,   31,   32,   33,    5,   52,   53,    8,    9,   35,
 /*   200 */    36,   25,   25,   14,   15,   16,   17,   18,   19,   20,
 /*   210 */    21,    9,   13,   13,    5,    5,   50,   28,    9,   30,
 /*   220 */    31,   32,   39,   14,   15,   16,   17,   18,   19,   20,
 /*   230 */    21,   39,   12,   49,    9,   39,   39,   28,   56,   30,
 /*   240 */    31,   32,   37,   11,   59,   40,   41,   42,   43,    9,
 /*   250 */    45,   46,   47,    9,   61,   65,   51,   52,   53,   29,
 /*   260 */    39,   39,   39,   39,   12,   39,    9,   62,   63,   64,
 /*   270 */    39,   14,   15,   16,   17,   18,   19,   20,   21,   66,
 /*   280 */    39,   39,   66,   66,   66,   28,   66,   30,   31,   32,
 /*   290 */    37,   66,   66,   40,   41,   42,   43,   66,   45,   66,
 /*   300 */    47,   66,   66,   66,   51,   52,   53,   40,   41,   42,
 /*   310 */    43,   66,   45,   66,   47,   62,   63,   64,   51,   52,
 /*   320 */    53,   66,   66,   66,   66,   66,   66,    9,   66,   62,
 /*   330 */    63,   64,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   340 */    66,   66,    9,   66,   66,   66,   28,   14,   15,   16,
 /*   350 */    17,   18,   19,   20,   21,   66,   66,    9,   66,   66,
 /*   360 */    66,   28,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   370 */    51,   52,   53,   66,   55,   66,   57,   66,   59,   43,
 /*   380 */    44,   62,   63,   64,   48,   66,   66,   51,   52,   53,
 /*   390 */    66,   66,   66,   66,   66,   66,   43,   44,   62,   63,
 /*   400 */    64,   51,   52,   53,   51,   52,   53,   57,   66,   59,
 /*   410 */    43,   44,   62,   63,   64,   62,   63,   64,   51,   52,
 /*   420 */    53,   66,   66,   66,   43,   44,   66,   43,   44,   62,
 /*   430 */    63,   64,   51,   52,   53,   51,   52,   53,   66,   66,
 /*   440 */    66,   43,   66,   62,   63,   64,   62,   63,   64,   51,
 /*   450 */    52,   53,   66,   66,   66,   66,   66,   66,   66,   66,
 /*   460 */    62,   63,   64,
};
#define YY_SHIFT_USE_DFLT (-6)
#define YY_SHIFT_COUNT (75)
#define YY_SHIFT_MIN   (-5)
#define YY_SHIFT_MAX   (348)
static const short yy_shift_ofst[] = {
 /*     0 */    -6,   82,   53,   24,   -5,  209,  333,  209,  209,  209,
 /*    10 */   257,  333,  189,  160,  140,  111,  209,  318,  318,  318,
 /*    20 */   318,  318,  318,  252,  348,  348,  141,   56,  162,  113,
 /*    30 */   210,  210,  210,  210,  210,  230,  244,  240,  232,  210,
 /*    40 */   210,  225,  220,  210,  210,  181,  181,  181,  181,   -2,
 /*    50 */   181,   27,   77,  104,  104,   17,  200,  199,  139,  202,
 /*    60 */   177,  176,  144,  157,  119,  139,  129,  112,  119,   96,
 /*    70 */   108,  106,  102,   81,   79,    3,
};
#define YY_REDUCE_USE_DFLT (-46)
#define YY_REDUCE_COUNT (44)
#define YY_REDUCE_MIN   (-45)
#define YY_REDUCE_MAX   (398)
static const short yy_reduce_ofst[] = {
 /*     0 */   164,  205,  253,  267,  267,  336,  319,  384,  381,  367,
 /*    10 */   353,  350,  398,  398,  398,  398,  398,  100,   71,   42,
 /*    20 */    13,  -16,  -45,   -1,  143,  134,   98,  242,  241,  231,
 /*    30 */   226,  224,  223,  222,  221,  190,  193,  185,  182,  197,
 /*    40 */   196,  184,  166,  192,  183,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   134,  198,  198,  198,  198,  198,  198,  198,  198,  198,
 /*    10 */   198,  198,  198,  198,  198,  198,  198,  198,  198,  198,
 /*    20 */   198,  198,  198,  166,  198,  198,  198,  198,  198,  198,
 /*    30 */   198,  198,  198,  198,  198,  190,  198,  198,  172,  198,
 /*    40 */   198,  198,  149,  198,  198,  197,  196,  170,  171,  186,
 /*    50 */   192,  177,  198,  153,  152,  198,  198,  198,  180,  198,
 /*    60 */   162,  161,  198,  198,  198,  173,  198,  198,  161,  169,
 /*    70 */   198,  198,  198,  198,  198,  198,  135,  136,  144,  130,
 /*    80 */   151,  184,  181,  176,  174,  191,  141,  195,  194,  193,
 /*    90 */   189,  188,  187,  183,  185,  139,  182,  179,  178,  168,
 /*   100 */   167,  175,  165,  164,  163,  162,  161,  160,  159,  158,
 /*   110 */   157,  156,  155,  154,  146,  140,  148,  150,  147,  145,
 /*   120 */   143,  142,  138,  137,  133,  132,  131,  129,
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
  "END",           "ID",            "DEF",           "COMMA",       
  "LP",            "RP",            "NUM",           "NIL",         
  "TRUE",          "FALSE",         "SELF",          "IVAR",        
  "COLON",         "LITSTR",        "DOT",           "ATTR",        
  "DCOLON",        "EQUAL",         "CASCADE",       "RB",          
  "LB",            "PIPE",          "IF",            "IMPORT",      
  "TRY",           "RESCUE",        "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "seq",           "class_start",   "class_body",    "def_start",   
  "def_body",      "id_list",       "def_args",      "expr",        
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
 /*  17 */ "def_start ::= DEF",
 /*  18 */ "def_body ::= seq fin END",
 /*  19 */ "id_list ::= id_list COMMA ID",
 /*  20 */ "id_list ::= ID",
 /*  21 */ "def_args ::=",
 /*  22 */ "def_args ::= LP id_list RP",
 /*  23 */ "def ::= def_start ID def_args fin def_body",
 /*  24 */ "expr ::= expr MINUS expr",
 /*  25 */ "expr ::= expr PLUS expr",
 /*  26 */ "expr ::= expr TIMES expr",
 /*  27 */ "expr ::= expr DIVIDE expr",
 /*  28 */ "sexpr ::= NUM",
 /*  29 */ "sexpr ::= NIL",
 /*  30 */ "sexpr ::= TRUE",
 /*  31 */ "sexpr ::= FALSE",
 /*  32 */ "sexpr ::= SELF",
 /*  33 */ "sexpr ::= ID",
 /*  34 */ "sexpr ::= IVAR",
 /*  35 */ "sexpr ::= COLON ID",
 /*  36 */ "sexpr ::= LITSTR",
 /*  37 */ "send ::= sexpr",
 /*  38 */ "send ::= send DOT ID",
 /*  39 */ "send ::= send ATTR ID",
 /*  40 */ "send ::= send DCOLON ID",
 /*  41 */ "arg_list_start ::= LP",
 /*  42 */ "arg_list_elems ::= arg_list_elems COMMA expr",
 /*  43 */ "arg_list_elems ::= expr",
 /*  44 */ "opt_kw_arg_list ::=",
 /*  45 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  46 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  47 */ "send ::= send DOT ID LP RP",
 /*  48 */ "send ::= send DOT ID arg_list RP",
 /*  49 */ "kw_arg ::= ID EQUAL send",
 /*  50 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  51 */ "kw_arg_list_elems ::= kw_arg",
 /*  52 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  53 */ "send ::= send DOT ID kw_arg_list RP",
 /*  54 */ "message_seq ::= message_seq fin ID",
 /*  55 */ "message_seq ::= ID",
 /*  56 */ "cascade_start ::= send CASCADE",
 /*  57 */ "cascade ::= cascade_start message_seq RB",
 /*  58 */ "cascade ::= send",
 /*  59 */ "expr ::= cascade",
 /*  60 */ "lambda_start ::= LB",
 /*  61 */ "lambda_args ::= PIPE ID PIPE",
 /*  62 */ "lambda_args ::=",
 /*  63 */ "expr ::= lambda_start lambda_args seq RB",
 /*  64 */ "stmt ::= expr",
 /*  65 */ "stmt ::= IF send fin seq fin END",
 /*  66 */ "stmt ::= IMPORT ID",
 /*  67 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  68 */ "stmt ::= ID EQUAL expr",
 /*  69 */ "stmt ::= IVAR EQUAL expr",
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
  { 35, 3 },
  { 37, 3 },
  { 37, 1 },
  { 40, 1 },
  { 40, 1 },
  { 40, 1 },
  { 36, 0 },
  { 36, 2 },
  { 38, 1 },
  { 38, 2 },
  { 39, 2 },
  { 39, 1 },
  { 44, 3 },
  { 44, 1 },
  { 45, 1 },
  { 46, 3 },
  { 41, 4 },
  { 47, 1 },
  { 48, 3 },
  { 49, 3 },
  { 49, 1 },
  { 50, 0 },
  { 50, 3 },
  { 42, 5 },
  { 51, 3 },
  { 51, 3 },
  { 51, 3 },
  { 51, 3 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 1 },
  { 52, 2 },
  { 52, 1 },
  { 53, 1 },
  { 53, 3 },
  { 53, 3 },
  { 53, 3 },
  { 54, 1 },
  { 55, 3 },
  { 55, 1 },
  { 56, 0 },
  { 56, 2 },
  { 58, 3 },
  { 53, 5 },
  { 53, 5 },
  { 59, 3 },
  { 57, 3 },
  { 57, 1 },
  { 60, 2 },
  { 53, 5 },
  { 61, 3 },
  { 61, 1 },
  { 62, 2 },
  { 63, 3 },
  { 63, 1 },
  { 51, 1 },
  { 64, 1 },
  { 65, 3 },
  { 65, 0 },
  { 51, 4 },
  { 43, 1 },
  { 43, 6 },
  { 43, 2 },
  { 43, 9 },
  { 43, 3 },
  { 43, 3 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy76.a)); }
#line 915 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 29 "vm/parser.lm"
{ yygotominor.yy76.a = S->seq(yymsp[-2].minor.yy76.a, yymsp[0].minor.yy76.a); }
#line 921 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 37: /* send ::= sexpr */ yytestcase(yyruleno==37);
      case 58: /* cascade ::= send */ yytestcase(yyruleno==58);
      case 59: /* expr ::= cascade */ yytestcase(yyruleno==59);
      case 64: /* stmt ::= expr */ yytestcase(yyruleno==64);
#line 30 "vm/parser.lm"
{ yygotominor.yy76.a = yymsp[0].minor.yy76.a; }
#line 934 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 48 "vm/parser.lm"
{ S->start_class(); }
#line 939 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 18: /* def_body ::= seq fin END */ yytestcase(yyruleno==18);
#line 49 "vm/parser.lm"
{ yygotominor.yy76.a = yymsp[-2].minor.yy76.a; }
#line 945 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 51 "vm/parser.lm"
{
               yygotominor.yy76.a = S->ast_class(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy76.a);
             }
#line 952 "vm/parser.c.inc"
        break;
      case 17: /* def_start ::= DEF */
#line 55 "vm/parser.lm"
{ S->start_def(); }
#line 957 "vm/parser.c.inc"
        break;
      case 19: /* id_list ::= id_list COMMA ID */
      case 20: /* id_list ::= ID */ yytestcase(yyruleno==20);
#line 58 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 963 "vm/parser.c.inc"
        break;
      case 23: /* def ::= def_start ID def_args fin def_body */
#line 64 "vm/parser.lm"
{
              yygotominor.yy76.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy76.a);
            }
#line 970 "vm/parser.c.inc"
        break;
      case 24: /* expr ::= expr MINUS expr */
#line 68 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_binop("-", yymsp[-2].minor.yy76.a, yymsp[0].minor.yy76.a); }
#line 975 "vm/parser.c.inc"
        break;
      case 25: /* expr ::= expr PLUS expr */
#line 69 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_binop("+", yymsp[-2].minor.yy76.a, yymsp[0].minor.yy76.a); }
#line 980 "vm/parser.c.inc"
        break;
      case 26: /* expr ::= expr TIMES expr */
#line 70 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_binop("*", yymsp[-2].minor.yy76.a, yymsp[0].minor.yy76.a); }
#line 985 "vm/parser.c.inc"
        break;
      case 27: /* expr ::= expr DIVIDE expr */
#line 71 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_binop("/", yymsp[-2].minor.yy76.a, yymsp[0].minor.yy76.a); }
#line 990 "vm/parser.c.inc"
        break;
      case 28: /* sexpr ::= NUM */
#line 73 "vm/parser.lm"
{ yygotominor.yy76.a = S->number(yymsp[0].minor.yy0.i); }
#line 995 "vm/parser.c.inc"
        break;
      case 29: /* sexpr ::= NIL */
#line 74 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_nil();  }
#line 1000 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= TRUE */
#line 75 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_true();  }
#line 1005 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= FALSE */
#line 76 "vm/parser.lm"
{ yygotominor.yy76.a = S->ast_false(); }
#line 1010 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= SELF */
#line 77 "vm/parser.lm"
{ yygotominor.yy76.a = S->self(); }
#line 1015 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= ID */
#line 78 "vm/parser.lm"
{ yygotominor.yy76.a = S->named(*yymsp[0].minor.yy0.s); }
#line 1020 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= IVAR */
#line 79 "vm/parser.lm"
{ yygotominor.yy76.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1025 "vm/parser.c.inc"
        break;
      case 35: /* sexpr ::= COLON ID */
      case 36: /* sexpr ::= LITSTR */ yytestcase(yyruleno==36);
#line 80 "vm/parser.lm"
{ yygotominor.yy76.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1031 "vm/parser.c.inc"
        break;
      case 38: /* send ::= send DOT ID */
#line 84 "vm/parser.lm"
{ yygotominor.yy76.a = S->call(yymsp[-2].minor.yy76.a, *yymsp[0].minor.yy0.s); }
#line 1036 "vm/parser.c.inc"
        break;
      case 39: /* send ::= send ATTR ID */
#line 85 "vm/parser.lm"
{ yygotominor.yy76.a = S->attr(yymsp[-2].minor.yy76.a, *yymsp[0].minor.yy0.s); }
#line 1041 "vm/parser.c.inc"
        break;
      case 40: /* send ::= send DCOLON ID */
#line 86 "vm/parser.lm"
{ yygotominor.yy76.a = S->dcolon(yymsp[-2].minor.yy76.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1046 "vm/parser.c.inc"
        break;
      case 41: /* arg_list_start ::= LP */
#line 90 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1051 "vm/parser.c.inc"
        break;
      case 42: /* arg_list_elems ::= arg_list_elems COMMA expr */
      case 43: /* arg_list_elems ::= expr */ yytestcase(yyruleno==43);
#line 91 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy76.a); }
#line 1057 "vm/parser.c.inc"
        break;
      case 47: /* send ::= send DOT ID LP RP */
#line 99 "vm/parser.lm"
{ yygotominor.yy76.a = S->call(yymsp[-4].minor.yy76.a, *yymsp[-2].minor.yy0.s); }
#line 1062 "vm/parser.c.inc"
        break;
      case 48: /* send ::= send DOT ID arg_list RP */
#line 100 "vm/parser.lm"
{ yygotominor.yy76.a = S->call_args(yymsp[-4].minor.yy76.a, *yymsp[-2].minor.yy0.s); }
#line 1067 "vm/parser.c.inc"
        break;
      case 49: /* kw_arg ::= ID EQUAL send */
#line 104 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy76.a); }
#line 1072 "vm/parser.c.inc"
        break;
      case 53: /* send ::= send DOT ID kw_arg_list RP */
#line 111 "vm/parser.lm"
{
              yygotominor.yy76.a = S->call_kw_args(yymsp[-4].minor.yy76.a, *yymsp[-2].minor.yy0.s);
            }
#line 1079 "vm/parser.c.inc"
        break;
      case 54: /* message_seq ::= message_seq fin ID */
      case 55: /* message_seq ::= ID */ yytestcase(yyruleno==55);
#line 117 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1085 "vm/parser.c.inc"
        break;
      case 56: /* cascade_start ::= send CASCADE */
#line 120 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy76.a); }
#line 1090 "vm/parser.c.inc"
        break;
      case 57: /* cascade ::= cascade_start message_seq RB */
#line 121 "vm/parser.lm"
{ yygotominor.yy76.a = S->end_cascade(); }
#line 1095 "vm/parser.c.inc"
        break;
      case 60: /* lambda_start ::= LB */
#line 129 "vm/parser.lm"
{ S->start_lambda(); }
#line 1100 "vm/parser.c.inc"
        break;
      case 61: /* lambda_args ::= PIPE ID PIPE */
#line 131 "vm/parser.lm"
{ S->def_arg(*yymsp[-1].minor.yy0.s); }
#line 1105 "vm/parser.c.inc"
        break;
      case 63: /* expr ::= lambda_start lambda_args seq RB */
#line 134 "vm/parser.lm"
{ yygotominor.yy76.a = S->lambda(yymsp[-1].minor.yy76.a); }
#line 1110 "vm/parser.c.inc"
        break;
      case 65: /* stmt ::= IF send fin seq fin END */
#line 142 "vm/parser.lm"
{ yygotominor.yy76.a = S->if_cond(yymsp[-4].minor.yy76.a, yymsp[-2].minor.yy76.a); }
#line 1115 "vm/parser.c.inc"
        break;
      case 66: /* stmt ::= IMPORT ID */
#line 146 "vm/parser.lm"
{ yygotominor.yy76.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1120 "vm/parser.c.inc"
        break;
      case 67: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 148 "vm/parser.lm"
{
              yygotominor.yy76.a = S->ast_try(yymsp[-6].minor.yy76.a, yymsp[-2].minor.yy76.a);
            }
#line 1127 "vm/parser.c.inc"
        break;
      case 68: /* stmt ::= ID EQUAL expr */
#line 152 "vm/parser.lm"
{ yygotominor.yy76.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy76.a); }
#line 1132 "vm/parser.c.inc"
        break;
      case 69: /* stmt ::= IVAR EQUAL expr */
#line 153 "vm/parser.lm"
{ yygotominor.yy76.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy76.a); }
#line 1137 "vm/parser.c.inc"
        break;
      default:
      /* (6) opt_fin ::= */ yytestcase(yyruleno==6);
      /* (7) opt_fin ::= opt_fin FIN */ yytestcase(yyruleno==7);
      /* (8) last_fin ::= EOF */ yytestcase(yyruleno==8);
      /* (9) last_fin ::= fin EOF */ yytestcase(yyruleno==9);
      /* (10) fin ::= fin FIN */ yytestcase(yyruleno==10);
      /* (11) fin ::= FIN */ yytestcase(yyruleno==11);
      /* (21) def_args ::= */ yytestcase(yyruleno==21);
      /* (22) def_args ::= LP id_list RP */ yytestcase(yyruleno==22);
      /* (44) opt_kw_arg_list ::= */ yytestcase(yyruleno==44);
      /* (45) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==45);
      /* (46) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==46);
      /* (50) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==50);
      /* (51) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==51);
      /* (52) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==52);
      /* (62) lambda_args ::= */ yytestcase(yyruleno==62);
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
#line 1220 "vm/parser.c.inc"
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
