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
#define YYNOCODE 59
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
#define YYNSTATE 113
#define YYNRULE 62
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
#define YY_ACTTAB_COUNT (313)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   107,  108,  106,  113,   61,  104,   41,   42,   40,   96,
 /*    10 */    95,   94,   93,   51,   21,   22,   32,   78,   77,   18,
 /*    20 */    50,   30,  107,   71,   31,  107,   82,  106,  105,   61,
 /*    30 */   104,   41,   42,   81,   96,   95,   94,   93,   51,   41,
 /*    40 */    42,   32,   78,   75,   18,   50,   30,   60,   57,   32,
 /*    50 */    78,   76,   39,   60,   57,   69,  111,  110,  109,   38,
 /*    60 */    64,   68,   63,   71,   35,  103,   41,   42,   70,   14,
 /*    70 */    15,   41,   42,   53,   17,   52,   32,   78,   75,   65,
 /*    80 */     4,   32,   78,   75,   20,   81,   67,   69,  111,  110,
 /*    90 */   109,   90,   64,   62,   63,  102,   19,   92,   41,   42,
 /*   100 */    41,   46,   96,   95,   94,   93,   91,   89,   32,   78,
 /*   110 */    75,   13,   60,   57,   66,   83,  106,   33,   61,  104,
 /*   120 */   176,    2,   81,   96,   95,   94,   93,   51,   23,   24,
 /*   130 */    21,   22,   85,   18,   50,   30,   84,   71,   29,  107,
 /*   140 */    80,  106,   73,   61,  104,   41,   42,    1,   96,   95,
 /*   150 */    94,   93,   51,   81,    3,   32,   78,   75,   18,   50,
 /*   160 */    30,   71,   27,   37,  107,   41,   25,   99,   61,   41,
 /*   170 */    42,  101,   36,   96,   95,   94,   93,   51,   49,   32,
 /*   180 */    78,   75,   16,   18,   50,   30,  100,    5,   12,  107,
 /*   190 */    86,   88,   74,   61,   41,   42,   55,   26,   96,   95,
 /*   200 */    94,   93,   51,   79,   32,   78,   75,  107,   18,   50,
 /*   210 */    30,   61,   11,    7,   10,    6,   96,   95,   94,   93,
 /*   220 */    51,    9,   43,    8,   59,  177,   18,   50,   30,   28,
 /*   230 */    48,   47,  107,  177,  177,   72,   61,   98,   97,  177,
 /*   240 */   177,   96,   95,   94,   93,   51,  177,  177,  177,  177,
 /*   250 */   177,   18,   50,   30,  112,  111,  110,  109,  177,   64,
 /*   260 */   107,   63,  177,  177,   61,   41,   42,  177,  177,   96,
 /*   270 */    95,   94,   93,   51,  177,   32,   78,   75,  177,   18,
 /*   280 */    50,   30,   58,  177,  177,  177,  177,   96,   95,   94,
 /*   290 */    93,   91,  177,  177,  177,  177,  177,   41,   45,  177,
 /*   300 */    34,  177,   54,  177,   87,   41,   44,  177,  177,  177,
 /*   310 */    56,  177,   87,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,    6,    7,    0,    9,   10,   45,   46,    9,   14,
 /*    10 */    15,   16,   17,   18,    3,    4,   55,   56,   57,   24,
 /*    20 */    25,   26,    5,   37,   38,    5,    9,    7,    8,    9,
 /*    30 */    10,   45,   46,    5,   14,   15,   16,   17,   18,   45,
 /*    40 */    46,   55,   56,   57,   24,   25,   26,   19,   20,   55,
 /*    50 */    56,   57,   31,   19,   20,   34,   35,   36,   37,    9,
 /*    60 */    39,   40,   41,   37,   38,    9,   45,   46,   42,   47,
 /*    70 */    21,   45,   46,   51,    9,   53,   55,   56,   57,   32,
 /*    80 */    33,   55,   56,   57,   31,    5,    6,   34,   35,   36,
 /*    90 */    37,   13,   39,   11,   41,   13,   21,    9,   45,   46,
 /*   100 */    45,   46,   14,   15,   16,   17,   18,    9,   55,   56,
 /*   110 */    57,   21,   19,   20,    5,   22,    7,   11,    9,   10,
 /*   120 */    29,   30,    5,   14,   15,   16,   17,   18,    1,    2,
 /*   130 */     3,    4,   13,   24,   25,   26,   13,   37,   38,    5,
 /*   140 */    23,    7,    9,    9,   10,   45,   46,   33,   14,   15,
 /*   150 */    16,   17,   18,    5,   33,   55,   56,   57,   24,   25,
 /*   160 */    26,   37,   38,   12,    5,   45,   46,    8,    9,   45,
 /*   170 */    46,    9,   44,   14,   15,   16,   17,   18,   43,   55,
 /*   180 */    56,   57,   11,   24,   25,   26,   37,   33,   33,    5,
 /*   190 */    49,   52,    8,    9,   45,   46,    9,   54,   14,   15,
 /*   200 */    16,   17,   18,    9,   55,   56,   57,    5,   24,   25,
 /*   210 */    26,    9,   33,   33,   33,   33,   14,   15,   16,   17,
 /*   220 */    18,   33,   33,   33,   12,   58,   24,   25,   26,   27,
 /*   230 */    45,   45,    5,   58,   58,    8,    9,   45,   45,   58,
 /*   240 */    58,   14,   15,   16,   17,   18,   58,   58,   58,   58,
 /*   250 */    58,   24,   25,   26,   34,   35,   36,   37,   58,   39,
 /*   260 */     5,   41,   58,   58,    9,   45,   46,   58,   58,   14,
 /*   270 */    15,   16,   17,   18,   58,   55,   56,   57,   58,   24,
 /*   280 */    25,   26,    9,   58,   58,   58,   58,   14,   15,   16,
 /*   290 */    17,   18,   58,   58,   58,   58,   58,   45,   46,   58,
 /*   300 */    48,   58,   50,   58,   52,   45,   46,   58,   58,   58,
 /*   310 */    50,   58,   52,
};
#define YY_SHIFT_USE_DFLT (-6)
#define YY_SHIFT_COUNT (65)
#define YY_SHIFT_MIN   (-5)
#define YY_SHIFT_MAX   (273)
static const short yy_shift_ofst[] = {
 /*     0 */    -6,  134,  109,   20,   -5,  255,  255,  255,  255,  227,
 /*    10 */   202,  184,  159,   88,  273,   88,  273,  212,   88,   88,
 /*    20 */    80,   88,   88,   88,   88,   28,  117,  148,  148,  148,
 /*    30 */   148,  148,  194,  187,  171,  148,  148,  162,  151,  148,
 /*    40 */   148,  127,   93,   17,   34,   34,   34,   11,   11,   82,
 /*    50 */   133,   90,  123,  119,  106,   75,  106,   98,   75,   78,
 /*    60 */    65,   49,   56,   50,   -1,    3,
};
#define YY_REDUCE_USE_DFLT (-40)
#define YY_REDUCE_COUNT (40)
#define YY_REDUCE_MIN   (-39)
#define YY_REDUCE_MAX   (260)
static const short yy_reduce_ofst[] = {
 /*     0 */    91,   21,   53,  220,  220,   26,  124,  100,  -14,  149,
 /*    10 */   149,  149,  149,   -6,  252,  -39,  260,   22,  120,   55,
 /*    20 */    47,  193,  192,  186,  185,  190,  189,  188,  182,  181,
 /*    30 */   180,  179,  143,  139,  141,  155,  154,  135,  128,  121,
 /*    40 */   114,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   119,  175,  175,  175,  175,  175,  175,  175,  175,  175,
 /*    10 */   175,  175,  175,  175,  175,  175,  175,  148,  175,  175,
 /*    20 */   175,  175,  175,  175,  175,  175,  175,  175,  175,  175,
 /*    30 */   175,  175,  175,  175,  153,  175,  175,  175,  134,  175,
 /*    40 */   175,  147,  167,  175,  151,  152,  158,  138,  137,  175,
 /*    50 */   175,  146,  175,  175,  161,  175,  154,  175,  145,  150,
 /*    60 */   175,  145,  175,  175,  175,  175,  120,  121,  129,  115,
 /*    70 */   136,  126,  172,  171,  170,  169,  174,  173,  168,  164,
 /*    80 */   166,  124,  163,  165,  162,  157,  155,  160,  159,  149,
 /*    90 */   156,  146,  145,  144,  143,  142,  141,  140,  139,  131,
 /*   100 */   125,  133,  135,  132,  130,  128,  127,  123,  122,  118,
 /*   110 */   117,  116,  114,
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
  "TRUE",          "FALSE",         "IVAR",          "DOT",         
  "ATTR",          "EQUAL",         "CASCADE",       "RB",          
  "IF",            "IMPORT",        "TRY",           "RESCUE",      
  "error",         "program",       "opt_fin",       "l1",          
  "last_fin",      "fin",           "l1e",           "class",       
  "def",           "stmt",          "seq",           "class_start", 
  "class_body",    "def_start",     "def_body",      "id_list",     
  "def_args",      "sexpr",         "send",          "arg_list_start",
  "arg_list_elems",  "opt_kw_arg_list",  "kw_arg_list_elems",  "arg_list",    
  "kw_arg",        "kw_arg_list",   "message_seq",   "cascade_start",
  "cascade",       "expr",        
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
 /*  34 */ "send ::= sexpr",
 /*  35 */ "send ::= send DOT ID",
 /*  36 */ "send ::= send ATTR ID",
 /*  37 */ "arg_list_start ::= LP",
 /*  38 */ "arg_list_elems ::= arg_list_elems COMMA send",
 /*  39 */ "arg_list_elems ::= send",
 /*  40 */ "opt_kw_arg_list ::=",
 /*  41 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  42 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  43 */ "send ::= send DOT ID LP RP",
 /*  44 */ "send ::= send DOT ID arg_list RP",
 /*  45 */ "kw_arg ::= ID EQUAL send",
 /*  46 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  47 */ "kw_arg_list_elems ::= kw_arg",
 /*  48 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  49 */ "send ::= send DOT ID kw_arg_list RP",
 /*  50 */ "message_seq ::= message_seq fin ID",
 /*  51 */ "message_seq ::= ID",
 /*  52 */ "cascade_start ::= send CASCADE",
 /*  53 */ "cascade ::= cascade_start message_seq RB",
 /*  54 */ "cascade ::= send",
 /*  55 */ "expr ::= cascade",
 /*  56 */ "stmt ::= expr",
 /*  57 */ "stmt ::= IF send fin seq fin END",
 /*  58 */ "stmt ::= IMPORT ID",
 /*  59 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  60 */ "stmt ::= ID EQUAL expr",
 /*  61 */ "stmt ::= IVAR EQUAL expr",
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
  { 29, 3 },
  { 31, 3 },
  { 31, 1 },
  { 34, 1 },
  { 34, 1 },
  { 34, 1 },
  { 30, 0 },
  { 30, 2 },
  { 32, 1 },
  { 32, 2 },
  { 33, 2 },
  { 33, 1 },
  { 38, 3 },
  { 38, 1 },
  { 39, 1 },
  { 40, 3 },
  { 35, 4 },
  { 41, 1 },
  { 42, 3 },
  { 43, 3 },
  { 43, 1 },
  { 44, 0 },
  { 44, 3 },
  { 36, 5 },
  { 45, 3 },
  { 45, 3 },
  { 45, 3 },
  { 45, 3 },
  { 45, 1 },
  { 45, 1 },
  { 45, 1 },
  { 45, 1 },
  { 45, 1 },
  { 45, 1 },
  { 46, 1 },
  { 46, 3 },
  { 46, 3 },
  { 47, 1 },
  { 48, 3 },
  { 48, 1 },
  { 49, 0 },
  { 49, 2 },
  { 51, 3 },
  { 46, 5 },
  { 46, 5 },
  { 52, 3 },
  { 50, 3 },
  { 50, 1 },
  { 53, 2 },
  { 46, 5 },
  { 54, 3 },
  { 54, 1 },
  { 55, 2 },
  { 56, 3 },
  { 56, 1 },
  { 57, 1 },
  { 37, 1 },
  { 37, 6 },
  { 37, 2 },
  { 37, 9 },
  { 37, 3 },
  { 37, 3 },
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
#line 865 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 12: /* seq ::= seq fin stmt */ yytestcase(yyruleno==12);
#line 29 "vm/parser.lm"
{ yygotominor.yy88.a = S->seq(yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 871 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 13: /* seq ::= stmt */ yytestcase(yyruleno==13);
      case 34: /* send ::= sexpr */ yytestcase(yyruleno==34);
      case 54: /* cascade ::= send */ yytestcase(yyruleno==54);
      case 55: /* expr ::= cascade */ yytestcase(yyruleno==55);
      case 56: /* stmt ::= expr */ yytestcase(yyruleno==56);
#line 30 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[0].minor.yy88.a; }
#line 884 "vm/parser.c.inc"
        break;
      case 14: /* class_start ::= CLASS */
#line 48 "vm/parser.lm"
{ S->start_class(); }
#line 889 "vm/parser.c.inc"
        break;
      case 15: /* class_body ::= l1 fin END */
      case 18: /* def_body ::= seq fin END */ yytestcase(yyruleno==18);
#line 49 "vm/parser.lm"
{ yygotominor.yy88.a = yymsp[-2].minor.yy88.a; }
#line 895 "vm/parser.c.inc"
        break;
      case 16: /* class ::= class_start ID fin class_body */
#line 51 "vm/parser.lm"
{
               yygotominor.yy88.a = S->ast_class(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a);
             }
#line 902 "vm/parser.c.inc"
        break;
      case 17: /* def_start ::= DEF */
#line 55 "vm/parser.lm"
{ S->start_def(); }
#line 907 "vm/parser.c.inc"
        break;
      case 19: /* id_list ::= id_list COMMA ID */
      case 20: /* id_list ::= ID */ yytestcase(yyruleno==20);
#line 58 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 913 "vm/parser.c.inc"
        break;
      case 23: /* def ::= def_start ID def_args fin def_body */
#line 64 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy88.a);
            }
#line 920 "vm/parser.c.inc"
        break;
      case 24: /* sexpr ::= sexpr MINUS sexpr */
#line 68 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("-", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 925 "vm/parser.c.inc"
        break;
      case 25: /* sexpr ::= sexpr PLUS sexpr */
#line 69 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("+", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 930 "vm/parser.c.inc"
        break;
      case 26: /* sexpr ::= sexpr TIMES sexpr */
#line 70 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("*", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 935 "vm/parser.c.inc"
        break;
      case 27: /* sexpr ::= sexpr DIVIDE sexpr */
#line 71 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_binop("/", yymsp[-2].minor.yy88.a, yymsp[0].minor.yy88.a); }
#line 940 "vm/parser.c.inc"
        break;
      case 28: /* sexpr ::= NUM */
#line 72 "vm/parser.lm"
{ yygotominor.yy88.a = S->number(yymsp[0].minor.yy0.i); }
#line 945 "vm/parser.c.inc"
        break;
      case 29: /* sexpr ::= NIL */
#line 73 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_nil();  }
#line 950 "vm/parser.c.inc"
        break;
      case 30: /* sexpr ::= TRUE */
#line 74 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_true();  }
#line 955 "vm/parser.c.inc"
        break;
      case 31: /* sexpr ::= FALSE */
#line 75 "vm/parser.lm"
{ yygotominor.yy88.a = S->ast_false(); }
#line 960 "vm/parser.c.inc"
        break;
      case 32: /* sexpr ::= ID */
#line 76 "vm/parser.lm"
{ yygotominor.yy88.a = S->named(*yymsp[0].minor.yy0.s); }
#line 965 "vm/parser.c.inc"
        break;
      case 33: /* sexpr ::= IVAR */
#line 77 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_read(*yymsp[0].minor.yy0.s); }
#line 970 "vm/parser.c.inc"
        break;
      case 35: /* send ::= send DOT ID */
#line 80 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 975 "vm/parser.c.inc"
        break;
      case 36: /* send ::= send ATTR ID */
#line 81 "vm/parser.lm"
{ yygotominor.yy88.a = S->attr(yymsp[-2].minor.yy88.a, *yymsp[0].minor.yy0.s); }
#line 980 "vm/parser.c.inc"
        break;
      case 37: /* arg_list_start ::= LP */
#line 85 "vm/parser.lm"
{ S->start_arg_list(); }
#line 985 "vm/parser.c.inc"
        break;
      case 38: /* arg_list_elems ::= arg_list_elems COMMA send */
      case 39: /* arg_list_elems ::= send */ yytestcase(yyruleno==39);
#line 86 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy88.a); }
#line 991 "vm/parser.c.inc"
        break;
      case 43: /* send ::= send DOT ID LP RP */
#line 94 "vm/parser.lm"
{ yygotominor.yy88.a = S->call(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 996 "vm/parser.c.inc"
        break;
      case 44: /* send ::= send DOT ID arg_list RP */
#line 95 "vm/parser.lm"
{ yygotominor.yy88.a = S->call_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s); }
#line 1001 "vm/parser.c.inc"
        break;
      case 45: /* kw_arg ::= ID EQUAL send */
#line 99 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1006 "vm/parser.c.inc"
        break;
      case 49: /* send ::= send DOT ID kw_arg_list RP */
#line 106 "vm/parser.lm"
{
              yygotominor.yy88.a = S->call_kw_args(yymsp[-4].minor.yy88.a, *yymsp[-2].minor.yy0.s);
            }
#line 1013 "vm/parser.c.inc"
        break;
      case 50: /* message_seq ::= message_seq fin ID */
      case 51: /* message_seq ::= ID */ yytestcase(yyruleno==51);
#line 112 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 1019 "vm/parser.c.inc"
        break;
      case 52: /* cascade_start ::= send CASCADE */
#line 115 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy88.a); }
#line 1024 "vm/parser.c.inc"
        break;
      case 53: /* cascade ::= cascade_start message_seq RB */
#line 116 "vm/parser.lm"
{ yygotominor.yy88.a = S->end_cascade(); }
#line 1029 "vm/parser.c.inc"
        break;
      case 57: /* stmt ::= IF send fin seq fin END */
#line 128 "vm/parser.lm"
{ yygotominor.yy88.a = S->if_cond(yymsp[-4].minor.yy88.a, yymsp[-2].minor.yy88.a); }
#line 1034 "vm/parser.c.inc"
        break;
      case 58: /* stmt ::= IMPORT ID */
#line 132 "vm/parser.lm"
{ yygotominor.yy88.a = S->import(*yymsp[0].minor.yy0.s); }
#line 1039 "vm/parser.c.inc"
        break;
      case 59: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 134 "vm/parser.lm"
{
              yygotominor.yy88.a = S->ast_try(yymsp[-6].minor.yy88.a, yymsp[-2].minor.yy88.a);
            }
#line 1046 "vm/parser.c.inc"
        break;
      case 60: /* stmt ::= ID EQUAL expr */
#line 138 "vm/parser.lm"
{ yygotominor.yy88.a = S->assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1051 "vm/parser.c.inc"
        break;
      case 61: /* stmt ::= IVAR EQUAL expr */
#line 139 "vm/parser.lm"
{ yygotominor.yy88.a = S->ivar_assign(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy88.a); }
#line 1056 "vm/parser.c.inc"
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
      /* (40) opt_kw_arg_list ::= */ yytestcase(yyruleno==40);
      /* (41) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==41);
      /* (42) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==42);
      /* (46) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==46);
      /* (47) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==47);
      /* (48) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==48);
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
#line 1138 "vm/parser.c.inc"
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
