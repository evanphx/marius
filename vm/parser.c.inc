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
#define YYNOCODE 57
#define YYACTIONTYPE unsigned char
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy32;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 106
#define YYNRULE 58
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
#define YY_ACTTAB_COUNT (322)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    38,   20,   21,   65,  104,  103,  102,  100,   60,   64,
 /*    10 */    59,   77,   76,   85,   40,   42,   61,    4,   89,   88,
 /*    20 */    87,   86,   40,   52,   31,   73,   71,   51,   75,   82,
 /*    30 */   100,  101,   99,  106,   57,   97,   39,   76,   37,   89,
 /*    40 */    88,   87,   86,   22,   23,   20,   21,   17,   46,   29,
 /*    50 */    56,   58,  100,   95,   99,   98,   57,   97,   76,   63,
 /*    60 */    96,   89,   88,   87,   86,   14,   56,   16,   78,   17,
 /*    70 */    46,   29,   19,   40,   54,   65,  104,  103,  102,   18,
 /*    80 */    60,   56,   59,   32,   40,   24,   40,   42,  105,  104,
 /*    90 */   103,  102,   80,   60,   79,   59,   31,   73,   71,   40,
 /*   100 */    42,  165,    2,   62,   69,   99,    1,   57,   97,   31,
 /*   110 */    73,   71,   89,   88,   87,   86,   76,    3,   35,   36,
 /*   120 */    17,   46,   29,   13,   45,   94,  100,   48,   99,   47,
 /*   130 */    57,   97,    5,   12,   81,   89,   88,   87,   86,   15,
 /*   140 */    83,   50,   74,   17,   46,   29,   25,   44,   11,  100,
 /*   150 */     7,   10,   92,   57,    6,    9,   41,    8,   89,   88,
 /*   160 */    87,   86,   84,  166,  166,   43,   17,   46,   29,  166,
 /*   170 */    91,  166,  100,   90,  166,   70,   57,  166,  166,  166,
 /*   180 */   166,   89,   88,   87,   86,  166,  166,  166,  100,   17,
 /*   190 */    46,   29,   57,  166,  166,  166,  166,   89,   88,   87,
 /*   200 */    86,  166,  166,  166,  166,   17,   46,   29,   27,  166,
 /*   210 */   166,  100,  166,  166,   68,   57,  166,  166,  166,  166,
 /*   220 */    89,   88,   87,   86,  166,  166,  166,  100,   17,   46,
 /*   230 */    29,   57,  166,  166,  166,  166,   89,   88,   87,   86,
 /*   240 */   166,  166,   67,   34,   17,   46,   29,   66,  166,  166,
 /*   250 */    40,   42,  166,  166,  166,  166,   67,   30,   40,   42,
 /*   260 */    31,   73,   71,  166,   40,   42,  166,  166,   31,   73,
 /*   270 */    72,  166,   67,   28,   31,   73,   71,  166,   67,   26,
 /*   280 */    40,   42,  166,  166,  166,  166,   40,   42,  166,  166,
 /*   290 */    31,   73,   71,   93,  166,  166,   31,   73,   71,  166,
 /*   300 */    55,   40,   42,  166,  166,   89,   88,   87,   86,  166,
 /*   310 */   166,   31,   73,   71,   40,   53,  166,   33,  166,   49,
 /*   320 */   166,   82,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    29,    3,    4,   32,   33,   34,   35,    5,   37,   38,
 /*    10 */    39,    9,    5,    9,   43,   44,   30,   31,   14,   15,
 /*    20 */    16,   17,   43,   44,   53,   54,   55,   48,   21,   50,
 /*    30 */     5,    6,    7,    0,    9,   10,    9,    5,    9,   14,
 /*    40 */    15,   16,   17,    1,    2,    3,    4,   22,   23,   24,
 /*    50 */    18,   11,    5,   13,    7,    8,    9,   10,    5,    6,
 /*    60 */     9,   14,   15,   16,   17,   19,   18,    9,   20,   22,
 /*    70 */    23,   24,   29,   43,   44,   32,   33,   34,   35,   19,
 /*    80 */    37,   18,   39,   11,   43,   44,   43,   44,   32,   33,
 /*    90 */    34,   35,   13,   37,   13,   39,   53,   54,   55,   43,
 /*   100 */    44,   27,   28,    5,    9,    7,   31,    9,   10,   53,
 /*   110 */    54,   55,   14,   15,   16,   17,    5,   31,   42,   12,
 /*   120 */    22,   23,   24,   45,   41,    9,    5,   49,    7,   51,
 /*   130 */     9,   10,   31,   31,   47,   14,   15,   16,   17,   11,
 /*   140 */    50,    9,    9,   22,   23,   24,   52,   43,   31,    5,
 /*   150 */    31,   31,    8,    9,   31,   31,   31,   31,   14,   15,
 /*   160 */    16,   17,   12,   56,   56,   43,   22,   23,   24,   56,
 /*   170 */    43,   56,    5,   43,   56,    8,    9,   56,   56,   56,
 /*   180 */    56,   14,   15,   16,   17,   56,   56,   56,    5,   22,
 /*   190 */    23,   24,    9,   56,   56,   56,   56,   14,   15,   16,
 /*   200 */    17,   56,   56,   56,   56,   22,   23,   24,   25,   56,
 /*   210 */    56,    5,   56,   56,    8,    9,   56,   56,   56,   56,
 /*   220 */    14,   15,   16,   17,   56,   56,   56,    5,   22,   23,
 /*   230 */    24,    9,   56,   56,   56,   56,   14,   15,   16,   17,
 /*   240 */    56,   56,   35,   36,   22,   23,   24,   40,   56,   56,
 /*   250 */    43,   44,   56,   56,   56,   56,   35,   36,   43,   44,
 /*   260 */    53,   54,   55,   56,   43,   44,   56,   56,   53,   54,
 /*   270 */    55,   56,   35,   36,   53,   54,   55,   56,   35,   36,
 /*   280 */    43,   44,   56,   56,   56,   56,   43,   44,   56,   56,
 /*   290 */    53,   54,   55,   35,   56,   56,   53,   54,   55,   56,
 /*   300 */     9,   43,   44,   56,   56,   14,   15,   16,   17,   56,
 /*   310 */    56,   53,   54,   55,   43,   44,   56,   46,   56,   48,
 /*   320 */    56,   50,
};
#define YY_SHIFT_USE_DFLT (-3)
#define YY_SHIFT_COUNT (61)
#define YY_SHIFT_MIN   (-2)
#define YY_SHIFT_MAX   (291)
static const short yy_shift_ofst[] = {
 /*     0 */    -3,  121,   98,   47,   25,  222,  222,  222,  222,  206,
 /*    10 */   183,  167,  144,  291,    4,  291,  150,    4,    4,   53,
 /*    20 */     4,    4,    4,    4,   32,    7,  111,  111,  111,  111,
 /*    30 */   111,  133,  132,  128,  111,  111,  116,  107,  111,  111,
 /*    40 */    42,    2,   48,   -2,   -2,   40,   95,   81,   79,   72,
 /*    50 */    60,   72,   63,   63,   63,   60,   58,   46,   51,   29,
 /*    60 */    27,   33,
};
#define YY_REDUCE_USE_DFLT (-30)
#define YY_REDUCE_COUNT (39)
#define YY_REDUCE_MIN   (-29)
#define YY_REDUCE_MAX   (271)
static const short yy_reduce_ofst[] = {
 /*     0 */    74,  -29,   43,   56,   56,  207,  243,  237,  221,  258,
 /*    10 */   258,  258,  258,  271,  215,  -21,   78,   41,   30,  -14,
 /*    20 */   130,  127,  122,  104,  126,  125,  124,  123,  120,  119,
 /*    30 */   117,   94,   90,   87,  102,  101,   83,   76,   86,   75,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   112,  164,  164,  164,  164,  164,  164,  164,  164,  164,
 /*    10 */   164,  164,  164,  164,  164,  164,  140,  164,  164,  164,
 /*    20 */   164,  164,  164,  164,  164,  164,  164,  164,  164,  164,
 /*    30 */   164,  164,  164,  144,  164,  164,  164,  127,  164,  164,
 /*    40 */   139,  164,  157,  131,  130,  164,  164,  164,  164,  151,
 /*    50 */   164,  145,  142,  143,  148,  138,  164,  138,  164,  164,
 /*    60 */   164,  164,  113,  114,  122,  108,  129,  119,  162,  161,
 /*    70 */   160,  159,  163,  158,  154,  156,  117,  153,  155,  152,
 /*    80 */   147,  146,  150,  149,  141,  138,  137,  136,  135,  134,
 /*    90 */   133,  132,  124,  118,  126,  128,  125,  123,  121,  120,
 /*   100 */   116,  115,  111,  110,  109,  107,
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
  "TRUE",          "FALSE",         "DOT",           "EQUAL",       
  "CASCADE",       "RB",            "IF",            "IMPORT",      
  "TRY",           "RESCUE",        "error",         "program",     
  "opt_fin",       "l1",            "last_fin",      "fin",         
  "l1e",           "class",         "def",           "stmt",        
  "seq",           "class_start",   "class_body",    "def_start",   
  "def_body",      "id_list",       "def_args",      "sexpr",       
  "send",          "arg_list_start",  "arg_list_elems",  "opt_kw_arg_list",
  "kw_arg_list_elems",  "arg_list",      "kw_arg",        "kw_arg_list", 
  "message_seq",   "cascade_start",  "cascade",       "expr",        
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
 /*  33 */ "send ::= sexpr",
 /*  34 */ "send ::= send DOT ID",
 /*  35 */ "arg_list_start ::= LP",
 /*  36 */ "arg_list_elems ::= arg_list_elems COMMA send",
 /*  37 */ "arg_list_elems ::= send",
 /*  38 */ "opt_kw_arg_list ::=",
 /*  39 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  40 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  41 */ "send ::= send DOT ID arg_list RP",
 /*  42 */ "kw_arg ::= ID EQUAL send",
 /*  43 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  44 */ "kw_arg_list_elems ::= kw_arg",
 /*  45 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  46 */ "send ::= send DOT ID kw_arg_list RP",
 /*  47 */ "message_seq ::= message_seq fin ID",
 /*  48 */ "message_seq ::= ID",
 /*  49 */ "cascade_start ::= send CASCADE",
 /*  50 */ "cascade ::= cascade_start message_seq RB",
 /*  51 */ "cascade ::= send",
 /*  52 */ "expr ::= cascade",
 /*  53 */ "stmt ::= expr",
 /*  54 */ "stmt ::= IF send fin seq fin END",
 /*  55 */ "stmt ::= IMPORT ID",
 /*  56 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  57 */ "stmt ::= ID EQUAL expr",
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
  { 27, 3 },
  { 29, 3 },
  { 29, 1 },
  { 32, 1 },
  { 32, 1 },
  { 32, 1 },
  { 28, 0 },
  { 28, 2 },
  { 30, 1 },
  { 30, 2 },
  { 31, 2 },
  { 31, 1 },
  { 36, 3 },
  { 36, 1 },
  { 37, 1 },
  { 38, 3 },
  { 33, 4 },
  { 39, 1 },
  { 40, 3 },
  { 41, 3 },
  { 41, 1 },
  { 42, 0 },
  { 42, 3 },
  { 34, 5 },
  { 43, 3 },
  { 43, 3 },
  { 43, 3 },
  { 43, 3 },
  { 43, 1 },
  { 43, 1 },
  { 43, 1 },
  { 43, 1 },
  { 43, 1 },
  { 44, 1 },
  { 44, 3 },
  { 45, 1 },
  { 46, 3 },
  { 46, 1 },
  { 47, 0 },
  { 47, 2 },
  { 49, 3 },
  { 44, 5 },
  { 50, 3 },
  { 48, 3 },
  { 48, 1 },
  { 51, 2 },
  { 44, 5 },
  { 52, 3 },
  { 52, 1 },
  { 53, 2 },
  { 54, 3 },
  { 54, 1 },
  { 55, 1 },
  { 35, 1 },
  { 35, 6 },
  { 35, 2 },
  { 35, 9 },
  { 35, 3 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy32.a)); }
#line 856 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 29 "vm/parser.lm"
{ yygotominor.yy32.a = S->seq(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 862 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 33: /* send ::= sexpr */ yytestcase(yyruleno==33);
      case 51: /* cascade ::= send */ yytestcase(yyruleno==51);
      case 52: /* expr ::= cascade */ yytestcase(yyruleno==52);
      case 53: /* stmt ::= expr */ yytestcase(yyruleno==53);
#line 30 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[0].minor.yy32.a; }
#line 875 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 48 "vm/parser.lm"
{ S->start_class(); }
#line 880 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 18: /* def_body ::= seq fin END */ yytestcase(yyruleno==18);
#line 49 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[-2].minor.yy32.a; }
#line 886 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 51 "vm/parser.lm"
{
               yygotominor.yy32.a = S->ast_class(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a);
             }
#line 893 "vm/parser.c.inc"
        break;
      case 17: /* def_start ::= DEF */
#line 55 "vm/parser.lm"
{ S->start_def(); }
#line 898 "vm/parser.c.inc"
        break;
      case 19: /* id_list ::= id_list COMMA ID */
      case 20: /* id_list ::= ID */ yytestcase(yyruleno==20);
#line 58 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 904 "vm/parser.c.inc"
        break;
      case 23: /* def ::= def_start ID def_args fin def_body */
#line 64 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy32.a);
            }
#line 911 "vm/parser.c.inc"
        break;
      case 24: /* sexpr ::= sexpr MINUS sexpr */
#line 68 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("-", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 916 "vm/parser.c.inc"
        break;
      case 25: /* sexpr ::= sexpr PLUS sexpr */
#line 69 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("+", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 921 "vm/parser.c.inc"
        break;
      case 26: /* sexpr ::= sexpr TIMES sexpr */
#line 70 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("*", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 926 "vm/parser.c.inc"
        break;
      case 27: /* sexpr ::= sexpr DIVIDE sexpr */
#line 71 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("/", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 931 "vm/parser.c.inc"
        break;
      case 28: /* sexpr ::= NUM */
#line 72 "vm/parser.lm"
{ yygotominor.yy32.a = S->number(yymsp[0].minor.yy0.i); }
#line 936 "vm/parser.c.inc"
        break;
      case 29: /* sexpr ::= NIL */
#line 73 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_nil();  }
#line 941 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= TRUE */
#line 74 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_true();  }
#line 946 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= FALSE */
#line 75 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_false(); }
#line 951 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= ID */
#line 76 "vm/parser.lm"
{ yygotominor.yy32.a = S->named(*yymsp[0].minor.yy0.s); }
#line 956 "vm/parser.c.inc"
        break;
      case 34: /* send ::= send DOT ID */
#line 79 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-2].minor.yy32.a, *yymsp[0].minor.yy0.s); }
#line 961 "vm/parser.c.inc"
        break;
      case 35: /* arg_list_start ::= LP */
#line 83 "vm/parser.lm"
{ S->start_arg_list(); }
#line 966 "vm/parser.c.inc"
        break;
      case 36: /* arg_list_elems ::= arg_list_elems COMMA send */
      case 37: /* arg_list_elems ::= send */ yytestcase(yyruleno==37);
#line 84 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy32.a); }
#line 972 "vm/parser.c.inc"
        break;
      case 41: /* send ::= send DOT ID arg_list RP */
#line 92 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-4].minor.yy32.a, *yymsp[-2].minor.yy0.s); }
#line 977 "vm/parser.c.inc"
        break;
      case 42: /* kw_arg ::= ID EQUAL send */
#line 96 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 982 "vm/parser.c.inc"
        break;
      case 46: /* send ::= send DOT ID kw_arg_list RP */
#line 103 "vm/parser.lm"
{
              yygotominor.yy32.a = S->call_kw_args(yymsp[-4].minor.yy32.a, *yymsp[-2].minor.yy0.s);
            }
#line 989 "vm/parser.c.inc"
        break;
      case 47: /* message_seq ::= message_seq fin ID */
      case 48: /* message_seq ::= ID */ yytestcase(yyruleno==48);
#line 109 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 995 "vm/parser.c.inc"
        break;
      case 49: /* cascade_start ::= send CASCADE */
#line 112 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy32.a); }
#line 1000 "vm/parser.c.inc"
        break;
      case 50: /* cascade ::= cascade_start message_seq RB */
#line 113 "vm/parser.lm"
{ yygotominor.yy32.a = S->end_cascade(); }
#line 1005 "vm/parser.c.inc"
        break;
      case 54: /* stmt ::= IF send fin seq fin END */
#line 125 "vm/parser.lm"
{ yygotominor.yy32.a = S->if_cond(yymsp[-4].minor.yy32.a, yymsp[-2].minor.yy32.a); }
#line 1010 "vm/parser.c.inc"
        break;
      case 55: /* stmt ::= IMPORT ID */
#line 129 "vm/parser.lm"
{ yygotominor.yy32.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1015 "vm/parser.c.inc"
        break;
      case 56: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 131 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_try(yymsp[-6].minor.yy32.a, yymsp[-2].minor.yy32.a);
            }
#line 1022 "vm/parser.c.inc"
        break;
      case 57: /* stmt ::= ID EQUAL expr */
#line 135 "vm/parser.lm"
{ yygotominor.yy32.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 1027 "vm/parser.c.inc"
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
      /* (38) opt_kw_arg_list ::= */ yytestcase(yyruleno==38);
      /* (39) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==39);
      /* (40) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==40);
      /* (43) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==43);
      /* (44) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==44);
      /* (45) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==45);
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
#line 1109 "vm/parser.c.inc"
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
