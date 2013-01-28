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
#define YYNOCODE 64
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
#define YYNSTATE 123
#define YYNRULE 67
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
#define YY_ACTTAB_COUNT (414)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   117,  118,  116,   43,   65,  114,   45,   44,   88,  106,
 /*    10 */   105,  104,  103,   54,   66,   99,   35,   85,   76,    9,
 /*    20 */    23,   24,   84,   20,   53,   33,   78,   28,  117,   87,
 /*    30 */   116,  115,   65,  114,   45,   44,   88,  106,  105,  104,
 /*    40 */   103,   54,   66,   99,   35,   85,   82,    9,   70,    4,
 /*    50 */    84,   20,   53,   33,   78,   38,   71,   77,  116,   75,
 /*    60 */    65,  114,   45,   44,  123,  106,  105,  104,  103,   54,
 /*    70 */    66,   99,   35,   85,   82,    9,   88,   72,   84,   20,
 /*    80 */    53,   33,   41,   67,  117,  112,  116,  113,   65,  114,
 /*    90 */    64,   61,   60,  106,  105,  104,  103,   54,   66,   99,
 /*   100 */   100,  117,   45,   48,  109,   65,   84,   20,   53,   33,
 /*   110 */   106,  105,  104,  103,   54,   66,   99,   16,  117,   19,
 /*   120 */    88,   81,   65,   84,   20,   53,   33,  106,  105,  104,
 /*   130 */   103,   54,   66,   99,   98,  117,   64,   61,   60,   65,
 /*   140 */    84,   20,   53,   33,  106,  105,  104,  103,   54,   66,
 /*   150 */    99,   25,   26,   23,   24,   45,   27,   84,   20,   53,
 /*   160 */    33,   31,   21,  117,   97,   17,   79,   65,   36,   56,
 /*   170 */    15,   55,  106,  105,  104,  103,   54,   66,   99,  117,
 /*   180 */    45,   44,   96,   89,   80,   84,   20,   53,   33,   92,
 /*   190 */    35,   85,   83,    9,   42,  191,    2,   74,  121,  120,
 /*   200 */   119,   91,   69,   73,   68,    1,   88,    3,   45,   44,
 /*   210 */    45,   47,   39,   37,   40,   57,   52,   94,   35,   85,
 /*   220 */    82,    9,  111,    5,  117,   64,   61,   60,   65,   90,
 /*   230 */    13,   93,   18,  106,  105,  104,  103,   54,   66,   99,
 /*   240 */    95,   58,   86,   29,   12,    7,   84,   20,   53,   33,
 /*   250 */    63,   11,    6,   10,   49,   22,  192,  192,   74,  121,
 /*   260 */   120,  119,  192,   69,   14,   68,   78,   34,    8,   45,
 /*   270 */    44,   45,   46,   51,   45,   44,   59,   50,   94,   35,
 /*   280 */    85,   82,    9,  108,   35,   85,   82,    9,  107,   65,
 /*   290 */   192,  192,  192,  192,  106,  105,  104,  103,   54,   66,
 /*   300 */    99,  192,  192,  192,  192,  192,  102,   84,   20,   53,
 /*   310 */    33,  106,  105,  104,  103,  101,   66,   99,  192,  122,
 /*   320 */   121,  120,  119,  192,   69,  192,   68,   62,  192,  192,
 /*   330 */    45,   44,  106,  105,  104,  103,  101,   66,   99,  192,
 /*   340 */    35,   85,   82,    9,  192,  192,  192,  192,  192,  192,
 /*   350 */   102,  192,  192,  192,  192,  106,  105,  104,  103,  101,
 /*   360 */    66,   99,   78,   32,  192,  192,   78,   30,   84,  192,
 /*   370 */    45,   44,  192,  192,   45,   44,  192,  192,  192,  192,
 /*   380 */    35,   85,   82,    9,   35,   85,   82,    9,  192,  192,
 /*   390 */   192,  192,  110,  192,  192,  192,  192,  192,  192,  192,
 /*   400 */    45,   44,  192,  192,  192,  192,  192,  192,  192,  192,
 /*   410 */    35,   85,   82,    9,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,    6,    7,    9,    9,   10,   49,   50,    5,   14,
 /*    10 */    15,   16,   17,   18,   19,   20,   59,   60,   61,   62,
 /*    20 */     3,    4,   27,   28,   29,   30,   41,   42,    5,   26,
 /*    30 */     7,    8,    9,   10,   49,   50,    5,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   59,   60,   61,   62,   36,   37,
 /*    50 */    27,   28,   29,   30,   41,   42,    5,   26,    7,   46,
 /*    60 */     9,   10,   49,   50,    0,   14,   15,   16,   17,   18,
 /*    70 */    19,   20,   59,   60,   61,   62,    5,    6,   27,   28,
 /*    80 */    29,   30,    9,   11,    5,   13,    7,    9,    9,   10,
 /*    90 */    21,   22,   23,   14,   15,   16,   17,   18,   19,   20,
 /*   100 */     9,    5,   49,   50,    8,    9,   27,   28,   29,   30,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   24,    5,    9,
 /*   120 */     5,    8,    9,   27,   28,   29,   30,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   13,    5,   21,   22,   23,    9,
 /*   140 */    27,   28,   29,   30,   14,   15,   16,   17,   18,   19,
 /*   150 */    20,    1,    2,    3,    4,   49,   50,   27,   28,   29,
 /*   160 */    30,   31,   24,    5,    9,   51,    8,    9,   11,   55,
 /*   170 */    24,   57,   14,   15,   16,   17,   18,   19,   20,    5,
 /*   180 */    49,   50,    9,    9,    9,   27,   28,   29,   30,   13,
 /*   190 */    59,   60,   61,   62,   35,   33,   34,   38,   39,   40,
 /*   200 */    41,   13,   43,   44,   45,   37,    5,   37,   49,   50,
 /*   210 */    49,   50,   48,   52,   12,   54,   47,   56,   59,   60,
 /*   220 */    61,   62,    9,   37,    5,   21,   22,   23,    9,   25,
 /*   230 */    37,   53,   11,   14,   15,   16,   17,   18,   19,   20,
 /*   240 */    56,    9,    9,   58,   37,   37,   27,   28,   29,   30,
 /*   250 */    12,   37,   37,   37,   37,   35,   63,   63,   38,   39,
 /*   260 */    40,   41,   63,   43,   37,   45,   41,   42,   37,   49,
 /*   270 */    50,   49,   50,   49,   49,   50,   54,   49,   56,   59,
 /*   280 */    60,   61,   62,   49,   59,   60,   61,   62,   49,    9,
 /*   290 */    63,   63,   63,   63,   14,   15,   16,   17,   18,   19,
 /*   300 */    20,   63,   63,   63,   63,   63,    9,   27,   28,   29,
 /*   310 */    30,   14,   15,   16,   17,   18,   19,   20,   63,   38,
 /*   320 */    39,   40,   41,   63,   43,   63,   45,    9,   63,   63,
 /*   330 */    49,   50,   14,   15,   16,   17,   18,   19,   20,   63,
 /*   340 */    59,   60,   61,   62,   63,   63,   63,   63,   63,   63,
 /*   350 */     9,   63,   63,   63,   63,   14,   15,   16,   17,   18,
 /*   360 */    19,   20,   41,   42,   63,   63,   41,   42,   27,   63,
 /*   370 */    49,   50,   63,   63,   49,   50,   63,   63,   63,   63,
 /*   380 */    59,   60,   61,   62,   59,   60,   61,   62,   63,   63,
 /*   390 */    63,   63,   41,   63,   63,   63,   63,   63,   63,   63,
 /*   400 */    49,   50,   63,   63,   63,   63,   63,   63,   63,   63,
 /*   410 */    59,   60,   61,   62,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (70)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (341)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   79,   51,   23,   -5,  219,  219,  219,  219,  280,
 /*    10 */   158,  130,  113,   96,  219,  341,  341,  318,  318,  238,
 /*    20 */   297,  297,   71,  297,  297,  297,  297,  115,   31,    3,
 /*    30 */   201,  201,  201,  201,  201,  233,  232,  221,  201,  201,
 /*    40 */   213,  202,  201,  201,  204,  150,   69,   69,   69,  174,
 /*    50 */    17,   17,   72,  175,  146,  188,  176,  157,  138,  157,
 /*    60 */   173,  155,  138,  121,  110,   93,   91,   78,   73,   -6,
 /*    70 */    64,
};
#define YY_REDUCE_USE_DFLT (-44)
#define YY_REDUCE_COUNT (43)
#define YY_REDUCE_MIN   (-43)
#define YY_REDUCE_MAX   (351)
static const short yy_reduce_ofst[] = {
 /*     0 */   162,  159,  220,  281,  281,   13,  325,  321,  225,  -15,
 /*    10 */   351,  351,  351,  351,  351,  131,  -43,  161,  222,  114,
 /*    20 */   106,   53,   12,  239,  234,  228,  224,  231,  227,  217,
 /*    30 */   216,  215,  214,  208,  207,  185,  184,  178,  193,  186,
 /*    40 */   169,  164,  170,  168,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   129,  190,  190,  190,  190,  190,  190,  190,  190,  190,
 /*    10 */   190,  190,  190,  190,  190,  190,  190,  190,  190,  160,
 /*    20 */   190,  190,  190,  190,  190,  190,  190,  190,  190,  190,
 /*    30 */   190,  190,  190,  190,  190,  190,  190,  166,  190,  190,
 /*    40 */   190,  144,  190,  190,  180,  159,  164,  165,  171,  190,
 /*    50 */   148,  147,  190,  190,  156,  190,  190,  174,  190,  167,
 /*    60 */   190,  190,  155,  163,  190,  155,  190,  190,  190,  190,
 /*    70 */   190,  130,  131,  139,  125,  146,  188,  183,  136,  187,
 /*    80 */   186,  185,  184,  189,  182,  181,  177,  179,  134,  176,
 /*    90 */   178,  175,  170,  168,  173,  172,  162,  161,  169,  158,
 /*   100 */   157,  156,  155,  154,  153,  152,  151,  150,  149,  141,
 /*   110 */   135,  143,  145,  142,  140,  138,  137,  133,  132,  128,
 /*   120 */   127,  126,  124,
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
  "TRUE",          "FALSE",         "IVAR",          "COLON",       
  "LITSTR",        "DOT",           "ATTR",          "DCOLON",      
  "EQUAL",         "CASCADE",       "RB",            "LB",          
  "IF",            "IMPORT",        "TRY",           "RESCUE",      
  "error",         "program",       "opt_fin",       "l1",          
  "last_fin",      "fin",           "l1e",           "class",       
  "def",           "stmt",          "seq",           "class_start", 
  "class_body",    "def_start",     "def_body",      "id_list",     
  "def_args",      "sexpr",         "send",          "arg_list_start",
  "arg_list_elems",  "opt_kw_arg_list",  "kw_arg_list_elems",  "arg_list",    
  "kw_arg",        "kw_arg_list",   "message_seq",   "cascade_start",
  "cascade",       "expr",          "lambda_start",
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
 /*  24 */ "sexpr ::= sexpr MINUS sexpr",
 /*  25 */ "sexpr ::= sexpr PLUS sexpr",
 /*  26 */ "sexpr ::= sexpr TIMES sexpr",
 /*  27 */ "sexpr ::= sexpr DIVIDE sexpr",
 /*  28 */ "sexpr ::= NUM",
 /*  29 */ "sexpr ::= NIL",
 /*  30 */ "sexpr ::= TRUE",
 /*  31 */ "sexpr ::= FALSE",
 /*  32 */ "sexpr ::= ID",
 /*  33 */ "sexpr ::= IVAR",
 /*  34 */ "sexpr ::= COLON ID",
 /*  35 */ "sexpr ::= LITSTR",
 /*  36 */ "send ::= sexpr",
 /*  37 */ "send ::= send DOT ID",
 /*  38 */ "send ::= send ATTR ID",
 /*  39 */ "send ::= send DCOLON ID",
 /*  40 */ "arg_list_start ::= LP",
 /*  41 */ "arg_list_elems ::= arg_list_elems COMMA send",
 /*  42 */ "arg_list_elems ::= send",
 /*  43 */ "opt_kw_arg_list ::=",
 /*  44 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  45 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  46 */ "send ::= send DOT ID LP RP",
 /*  47 */ "send ::= send DOT ID arg_list RP",
 /*  48 */ "kw_arg ::= ID EQUAL send",
 /*  49 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  50 */ "kw_arg_list_elems ::= kw_arg",
 /*  51 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  52 */ "send ::= send DOT ID kw_arg_list RP",
 /*  53 */ "message_seq ::= message_seq fin ID",
 /*  54 */ "message_seq ::= ID",
 /*  55 */ "cascade_start ::= send CASCADE",
 /*  56 */ "cascade ::= cascade_start message_seq RB",
 /*  57 */ "cascade ::= send",
 /*  58 */ "expr ::= cascade",
 /*  59 */ "lambda_start ::= LB",
 /*  60 */ "expr ::= lambda_start seq RB",
 /*  61 */ "stmt ::= expr",
 /*  62 */ "stmt ::= IF send fin seq fin END",
 /*  63 */ "stmt ::= IMPORT ID",
 /*  64 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  65 */ "stmt ::= ID EQUAL expr",
 /*  66 */ "stmt ::= IVAR EQUAL expr",
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
  { 33, 3 },
  { 35, 3 },
  { 35, 1 },
  { 38, 1 },
  { 38, 1 },
  { 38, 1 },
  { 34, 0 },
  { 34, 2 },
  { 36, 1 },
  { 36, 2 },
  { 37, 2 },
  { 37, 1 },
  { 42, 3 },
  { 42, 1 },
  { 43, 1 },
  { 44, 3 },
  { 39, 4 },
  { 45, 1 },
  { 46, 3 },
  { 47, 3 },
  { 47, 1 },
  { 48, 0 },
  { 48, 3 },
  { 40, 5 },
  { 49, 3 },
  { 49, 3 },
  { 49, 3 },
  { 49, 3 },
  { 49, 1 },
  { 49, 1 },
  { 49, 1 },
  { 49, 1 },
  { 49, 1 },
  { 49, 1 },
  { 49, 2 },
  { 49, 1 },
  { 50, 1 },
  { 50, 3 },
  { 50, 3 },
  { 50, 3 },
  { 51, 1 },
  { 52, 3 },
  { 52, 1 },
  { 53, 0 },
  { 53, 2 },
  { 55, 3 },
  { 50, 5 },
  { 50, 5 },
  { 56, 3 },
  { 54, 3 },
  { 54, 1 },
  { 57, 2 },
  { 50, 5 },
  { 58, 3 },
  { 58, 1 },
  { 59, 2 },
  { 60, 3 },
  { 60, 1 },
  { 61, 1 },
  { 62, 1 },
  { 61, 3 },
  { 41, 1 },
  { 41, 6 },
  { 41, 2 },
  { 41, 9 },
  { 41, 3 },
  { 41, 3 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy88.a)); }
#line 898 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 29 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 904 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 36: /* send ::= sexpr */ yytestcase(yyruleno==36);
      case 57: /* cascade ::= send */ yytestcase(yyruleno==57);
      case 58: /* expr ::= cascade */ yytestcase(yyruleno==58);
      case 61: /* stmt ::= expr */ yytestcase(yyruleno==61);
#line 30 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 917 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 48 "vm/parser.lm"
{ S->start_class(); }
#line 922 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 18: /* def_body ::= seq fin END */ yytestcase(yyruleno==18);
#line 49 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 928 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 51 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a);
             }
#line 935 "vm/parser.c.inc"
        break;
      case 17: /* def_start ::= DEF */
#line 55 "vm/parser.lm"
{ S->start_def(); }
#line 940 "vm/parser.c.inc"
        break;
      case 19: /* id_list ::= id_list COMMA ID */
      case 20: /* id_list ::= ID */ yytestcase(yyruleno==20);
#line 58 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 946 "vm/parser.c.inc"
        break;
      case 23: /* def ::= def_start ID def_args fin def_body */
#line 64 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy88.a);
            }
#line 953 "vm/parser.c.inc"
        break;
      case 24: /* sexpr ::= sexpr MINUS sexpr */
#line 68 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("-", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 958 "vm/parser.c.inc"
        break;
      case 25: /* sexpr ::= sexpr PLUS sexpr */
#line 69 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("+", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 963 "vm/parser.c.inc"
        break;
      case 26: /* sexpr ::= sexpr TIMES sexpr */
#line 70 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("*", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 968 "vm/parser.c.inc"
        break;
      case 27: /* sexpr ::= sexpr DIVIDE sexpr */
#line 71 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("/", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 973 "vm/parser.c.inc"
        break;
      case 28: /* sexpr ::= NUM */
#line 72 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 978 "vm/parser.c.inc"
        break;
      case 29: /* sexpr ::= NIL */
#line 73 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 983 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= TRUE */
#line 74 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 988 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= FALSE */
#line 75 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 993 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= ID */
#line 76 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(*yymsp[0].minor.yy0.s); }
#line 998 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= IVAR */
#line 77 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 1003 "vm/parser.c.inc"
        break;
      case 34: /* sexpr ::= COLON ID */
      case 35: /* sexpr ::= LITSTR */ yytestcase(yyruleno==35);
#line 78 "vm/parser.lm"
{ yygotominor.yy88.a = S->lit_str(*yymsp[0].minor.yy0.s); }
#line 1009 "vm/parser.c.inc"
        break;
      case 37: /* send ::= send DOT ID */
#line 82 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 1014 "vm/parser.c.inc"
        break;
      case 38: /* send ::= send ATTR ID */
#line 83 "vm/parser.lm"
{ yygotominor.yy88.a = S->attr(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 1019 "vm/parser.c.inc"
        break;
      case 39: /* send ::= send DCOLON ID */
#line 84 "vm/parser.lm"
{ yygotominor.yy88.a = S->dcolon(yymsp[-2].minor.yy88.a, *yymsp[-1].minor.yy0.s, *yymsp[0].minor.yy0.s); }
#line 1024 "vm/parser.c.inc"
        break;
      case 40: /* arg_list_start ::= LP */
#line 88 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1029 "vm/parser.c.inc"
        break;
      case 41: /* arg_list_elems ::= arg_list_elems COMMA send */
      case 42: /* arg_list_elems ::= send */ yytestcase(yyruleno==42);
#line 89 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 1035 "vm/parser.c.inc"
        break;
      case 46: /* send ::= send DOT ID LP RP */
#line 97 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1040 "vm/parser.c.inc"
        break;
      case 47: /* send ::= send DOT ID arg_list RP */
#line 98 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1045 "vm/parser.c.inc"
        break;
      case 48: /* kw_arg ::= ID EQUAL send */
#line 102 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1050 "vm/parser.c.inc"
        break;
      case 52: /* send ::= send DOT ID kw_arg_list RP */
#line 109 "vm/parser.lm"
{
              yygotominor.yy88.a = S->call_kw_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s);
            }
#line 1057 "vm/parser.c.inc"
        break;
      case 53: /* message_seq ::= message_seq fin ID */
      case 54: /* message_seq ::= ID */ yytestcase(yyruleno==54);
#line 115 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1063 "vm/parser.c.inc"
        break;
      case 55: /* cascade_start ::= send CASCADE */
#line 118 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy88.a); }
#line 1068 "vm/parser.c.inc"
        break;
      case 56: /* cascade ::= cascade_start message_seq RB */
#line 119 "vm/parser.lm"
{ yygotominor.yy88.a = S->end_cascade(); }
#line 1073 "vm/parser.c.inc"
        break;
      case 59: /* lambda_start ::= LB */
#line 125 "vm/parser.lm"
{ S->start_lambda(); }
#line 1078 "vm/parser.c.inc"
        break;
      case 60: /* expr ::= lambda_start seq RB */
#line 127 "vm/parser.lm"
{ yygotominor.yy88.a = S->lambda(yymsp[-1].minor.yy88.a); }
#line 1083 "vm/parser.c.inc"
        break;
      case 62: /* stmt ::= IF send fin seq fin END */
#line 135 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1088 "vm/parser.c.inc"
        break;
      case 63: /* stmt ::= IMPORT ID */
#line 139 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1093 "vm/parser.c.inc"
        break;
      case 64: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 141 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1100 "vm/parser.c.inc"
        break;
      case 65: /* stmt ::= ID EQUAL expr */
#line 145 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1105 "vm/parser.c.inc"
        break;
      case 66: /* stmt ::= IVAR EQUAL expr */
#line 146 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1110 "vm/parser.c.inc"
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
      /* (43) opt_kw_arg_list ::= */ yytestcase(yyruleno==43);
      /* (44) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==44);
      /* (45) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==45);
      /* (49) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==49);
      /* (50) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==50);
      /* (51) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==51);
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
#line 1192 "vm/parser.c.inc"
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
