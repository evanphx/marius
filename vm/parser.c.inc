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
#define YYNOCODE 45
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
#define YYNSTATE 77
#define YYNRULE 45
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
#define YY_ACTTAB_COUNT (130)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    24,   13,   14,   49,   44,   47,   43,   42,   25,   68,
 /*    10 */    26,   28,   20,   74,   77,   49,   44,   54,   43,   48,
 /*    20 */    17,   50,   26,   28,   45,    6,   74,   75,   72,   23,
 /*    30 */    62,   70,   17,   50,   11,   63,   62,   49,   44,   69,
 /*    40 */    43,   63,   53,   76,   26,   28,   41,    7,   55,   73,
 /*    50 */    44,   33,   43,   32,   17,   50,   26,   28,   26,   39,
 /*    60 */    74,   53,   72,   71,   62,   70,   17,   50,   74,   63,
 /*    70 */    72,   66,   62,   70,   52,   40,    9,   63,   26,   38,
 /*    80 */    63,   19,   57,   34,   46,   59,   72,   10,   62,   70,
 /*    90 */    74,   18,   72,   63,   62,   70,  123,    3,    2,   63,
 /*   100 */    56,   15,   16,   13,   14,   26,   37,   53,   41,   21,
 /*   110 */    36,   22,   59,    5,   31,   67,    1,   58,    4,    8,
 /*   120 */    35,   60,   51,   30,   12,   27,   61,   29,   65,   64,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    22,    3,    4,   25,   26,   27,   28,   11,    9,   13,
 /*    10 */    32,   33,   22,    5,    0,   25,   26,    9,   28,   29,
 /*    20 */    42,   43,   32,   33,   23,   24,    5,    6,    7,    9,
 /*    30 */     9,   10,   42,   43,   22,   14,    9,   25,   26,    9,
 /*    40 */    28,   14,    5,    6,   32,   33,   15,   34,   17,   25,
 /*    50 */    26,   38,   28,   40,   42,   43,   32,   33,   32,   33,
 /*    60 */     5,    5,    7,    8,    9,   10,   42,   43,    5,   14,
 /*    70 */     7,    8,    9,   10,   18,    9,    9,   14,   32,   33,
 /*    80 */    14,   35,   13,   37,    5,   39,    7,   16,    9,   10,
 /*    90 */     5,   11,    7,   14,    9,   10,   20,   21,   24,   14,
 /*   100 */    13,    1,    2,    3,    4,   32,   33,    5,   15,   31,
 /*   110 */    37,   12,   39,   24,   30,    9,   24,   36,   24,   11,
 /*   120 */     9,   39,    9,   32,   41,   24,   12,   32,   32,   32,
};
#define YY_SHIFT_USE_DFLT (-5)
#define YY_SHIFT_COUNT (45)
#define YY_SHIFT_MIN   (-4)
#define YY_SHIFT_MAX   (114)
static const signed char yy_shift_ofst[] = {
 /*     0 */    -5,   85,   85,   79,   63,   55,   21,   66,   66,  114,
 /*    10 */    27,   37,   56,   27,   27,   27,   27,  113,  111,  108,
 /*    20 */   102,  102,  106,   99,  102,  102,  100,    8,   31,   -2,
 /*    30 */    -2,   -4,   87,   69,   80,   71,   80,   93,   93,   93,
 /*    40 */    71,   67,   30,   20,   -1,   14,
};
#define YY_REDUCE_USE_DFLT (-23)
#define YY_REDUCE_COUNT (25)
#define YY_REDUCE_MIN   (-22)
#define YY_REDUCE_MAX   (101)
static const signed char yy_reduce_ofst[] = {
 /*     0 */    76,  -10,  -22,   12,   24,   24,   24,   46,   73,   13,
 /*    10 */    26,    1,  101,   97,   96,   95,   91,   83,   82,   81,
 /*    20 */    94,   92,   84,   78,   89,   74,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    78,  122,  122,  122,  122,  122,  122,  122,  122,  103,
 /*    10 */   122,  122,  122,  122,  122,  122,  122,  122,  122,  107,
 /*    20 */   122,  122,  122,   93,  122,  122,  102,  122,  120,   97,
 /*    30 */    96,  122,  122,  122,  114,  122,  108,  105,  106,  111,
 /*    40 */   101,  122,  122,  122,  122,  122,   79,   88,   95,   85,
 /*    50 */   121,  117,  119,   83,  116,  118,  115,  110,  109,  113,
 /*    60 */   112,  104,  101,  100,   99,   98,   90,   92,   94,   91,
 /*    70 */    89,   87,   86,   84,   82,   81,   80,
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
  "LP",            "RP",            "NUM",           "DOT",         
  "EQUAL",         "CASCADE",       "RB",            "error",       
  "program",       "opt_fin",       "seq",           "last_fin",    
  "fin",           "expr",          "class_start",   "class_body",  
  "def_start",     "def_body",      "id_list",       "def_args",    
  "sexpr",         "send",          "arg_list_start",  "arg_list_elems",
  "opt_kw_arg_list",  "kw_arg_list_elems",  "arg_list",      "kw_arg",      
  "kw_arg_list",   "message_seq",   "cascade_start",  "cascade",     
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= opt_fin seq last_fin",
 /*   1 */ "opt_fin ::=",
 /*   2 */ "opt_fin ::= opt_fin FIN",
 /*   3 */ "last_fin ::= EOF",
 /*   4 */ "last_fin ::= fin EOF",
 /*   5 */ "fin ::= fin FIN",
 /*   6 */ "fin ::= FIN",
 /*   7 */ "seq ::= seq fin expr",
 /*   8 */ "seq ::= expr",
 /*   9 */ "class_start ::= CLASS",
 /*  10 */ "class_body ::= seq fin END",
 /*  11 */ "expr ::= class_start ID fin class_body",
 /*  12 */ "def_start ::= DEF",
 /*  13 */ "def_body ::= seq fin END",
 /*  14 */ "id_list ::= id_list COMMA ID",
 /*  15 */ "id_list ::= ID",
 /*  16 */ "def_args ::=",
 /*  17 */ "def_args ::= LP id_list RP",
 /*  18 */ "expr ::= def_start ID def_args fin def_body",
 /*  19 */ "sexpr ::= sexpr MINUS sexpr",
 /*  20 */ "sexpr ::= sexpr PLUS sexpr",
 /*  21 */ "sexpr ::= sexpr TIMES sexpr",
 /*  22 */ "sexpr ::= sexpr DIVIDE sexpr",
 /*  23 */ "sexpr ::= NUM",
 /*  24 */ "sexpr ::= ID",
 /*  25 */ "send ::= sexpr",
 /*  26 */ "send ::= send DOT ID",
 /*  27 */ "arg_list_start ::= LP",
 /*  28 */ "arg_list_elems ::= arg_list_elems COMMA send",
 /*  29 */ "arg_list_elems ::= send",
 /*  30 */ "opt_kw_arg_list ::=",
 /*  31 */ "opt_kw_arg_list ::= COMMA kw_arg_list_elems",
 /*  32 */ "arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list",
 /*  33 */ "send ::= send DOT ID arg_list RP",
 /*  34 */ "kw_arg ::= ID EQUAL send",
 /*  35 */ "kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg",
 /*  36 */ "kw_arg_list_elems ::= kw_arg",
 /*  37 */ "kw_arg_list ::= arg_list_start kw_arg_list_elems",
 /*  38 */ "send ::= send DOT ID kw_arg_list RP",
 /*  39 */ "message_seq ::= message_seq fin ID",
 /*  40 */ "message_seq ::= ID",
 /*  41 */ "cascade_start ::= send CASCADE",
 /*  42 */ "cascade ::= cascade_start message_seq RB",
 /*  43 */ "cascade ::= send",
 /*  44 */ "expr ::= cascade",
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
  { 20, 3 },
  { 21, 0 },
  { 21, 2 },
  { 23, 1 },
  { 23, 2 },
  { 24, 2 },
  { 24, 1 },
  { 22, 3 },
  { 22, 1 },
  { 26, 1 },
  { 27, 3 },
  { 25, 4 },
  { 28, 1 },
  { 29, 3 },
  { 30, 3 },
  { 30, 1 },
  { 31, 0 },
  { 31, 3 },
  { 25, 5 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 1 },
  { 32, 1 },
  { 33, 1 },
  { 33, 3 },
  { 34, 1 },
  { 35, 3 },
  { 35, 1 },
  { 36, 0 },
  { 36, 2 },
  { 38, 3 },
  { 33, 5 },
  { 39, 3 },
  { 37, 3 },
  { 37, 1 },
  { 40, 2 },
  { 33, 5 },
  { 41, 3 },
  { 41, 1 },
  { 42, 2 },
  { 43, 3 },
  { 43, 1 },
  { 25, 1 },
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
      case 0: /* program ::= opt_fin seq last_fin */
#line 27 "vm/parser.lm"
{ S->set_top(S->ret(yymsp[-1].minor.yy32.a)); }
#line 781 "vm/parser.c.inc"
        break;
      case 7: /* seq ::= seq fin expr */
#line 38 "vm/parser.lm"
{ yygotominor.yy32.a = S->seq(yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 786 "vm/parser.c.inc"
        break;
      case 8: /* seq ::= expr */
      case 25: /* send ::= sexpr */ yytestcase(yyruleno==25);
      case 43: /* cascade ::= send */ yytestcase(yyruleno==43);
      case 44: /* expr ::= cascade */ yytestcase(yyruleno==44);
#line 39 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[0].minor.yy32.a; }
#line 794 "vm/parser.c.inc"
        break;
      case 9: /* class_start ::= CLASS */
#line 41 "vm/parser.lm"
{ S->start_class(); }
#line 799 "vm/parser.c.inc"
        break;
      case 10: /* class_body ::= seq fin END */
      case 13: /* def_body ::= seq fin END */ yytestcase(yyruleno==13);
#line 42 "vm/parser.lm"
{ yygotominor.yy32.a = yymsp[-2].minor.yy32.a; }
#line 805 "vm/parser.c.inc"
        break;
      case 11: /* expr ::= class_start ID fin class_body */
#line 44 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_class(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a);
            }
#line 812 "vm/parser.c.inc"
        break;
      case 12: /* def_start ::= DEF */
#line 48 "vm/parser.lm"
{ S->start_def(); }
#line 817 "vm/parser.c.inc"
        break;
      case 14: /* id_list ::= id_list COMMA ID */
      case 15: /* id_list ::= ID */ yytestcase(yyruleno==15);
#line 51 "vm/parser.lm"
{ S->def_arg(*yymsp[0].minor.yy0.s); }
#line 823 "vm/parser.c.inc"
        break;
      case 18: /* expr ::= def_start ID def_args fin def_body */
#line 57 "vm/parser.lm"
{
              yygotominor.yy32.a = S->ast_def(*yymsp[-3].minor.yy0.s, yymsp[0].minor.yy32.a);
            }
#line 830 "vm/parser.c.inc"
        break;
      case 19: /* sexpr ::= sexpr MINUS sexpr */
#line 61 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("-", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 835 "vm/parser.c.inc"
        break;
      case 20: /* sexpr ::= sexpr PLUS sexpr */
#line 62 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("+", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 840 "vm/parser.c.inc"
        break;
      case 21: /* sexpr ::= sexpr TIMES sexpr */
#line 63 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("*", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 845 "vm/parser.c.inc"
        break;
      case 22: /* sexpr ::= sexpr DIVIDE sexpr */
#line 64 "vm/parser.lm"
{ yygotominor.yy32.a = S->ast_binop("/", yymsp[-2].minor.yy32.a, yymsp[0].minor.yy32.a); }
#line 850 "vm/parser.c.inc"
        break;
      case 23: /* sexpr ::= NUM */
#line 65 "vm/parser.lm"
{ yygotominor.yy32.a = S->number(yymsp[0].minor.yy0.i); }
#line 855 "vm/parser.c.inc"
        break;
      case 24: /* sexpr ::= ID */
#line 66 "vm/parser.lm"
{ yygotominor.yy32.a = S->named(*yymsp[0].minor.yy0.s); }
#line 860 "vm/parser.c.inc"
        break;
      case 26: /* send ::= send DOT ID */
#line 69 "vm/parser.lm"
{ yygotominor.yy32.a = S->call(yymsp[-2].minor.yy32.a, *yymsp[0].minor.yy0.s); }
#line 865 "vm/parser.c.inc"
        break;
      case 27: /* arg_list_start ::= LP */
#line 73 "vm/parser.lm"
{ S->start_arg_list(); }
#line 870 "vm/parser.c.inc"
        break;
      case 28: /* arg_list_elems ::= arg_list_elems COMMA send */
      case 29: /* arg_list_elems ::= send */ yytestcase(yyruleno==29);
#line 74 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy32.a); }
#line 876 "vm/parser.c.inc"
        break;
      case 33: /* send ::= send DOT ID arg_list RP */
#line 82 "vm/parser.lm"
{ yygotominor.yy32.a = S->call_args(yymsp[-4].minor.yy32.a, *yymsp[-2].minor.yy0.s); }
#line 881 "vm/parser.c.inc"
        break;
      case 34: /* kw_arg ::= ID EQUAL send */
#line 86 "vm/parser.lm"
{ S->add_kw_arg(*yymsp[-2].minor.yy0.s, yymsp[0].minor.yy32.a); }
#line 886 "vm/parser.c.inc"
        break;
      case 38: /* send ::= send DOT ID kw_arg_list RP */
#line 93 "vm/parser.lm"
{
              yygotominor.yy32.a = S->call_kw_args(yymsp[-4].minor.yy32.a, *yymsp[-2].minor.yy0.s);
            }
#line 893 "vm/parser.c.inc"
        break;
      case 39: /* message_seq ::= message_seq fin ID */
      case 40: /* message_seq ::= ID */ yytestcase(yyruleno==40);
#line 99 "vm/parser.lm"
{ S->cascade(*yymsp[0].minor.yy0.s); }
#line 899 "vm/parser.c.inc"
        break;
      case 41: /* cascade_start ::= send CASCADE */
#line 102 "vm/parser.lm"
{ S->start_cascade(yymsp[-1].minor.yy32.a); }
#line 904 "vm/parser.c.inc"
        break;
      case 42: /* cascade ::= cascade_start message_seq RB */
#line 103 "vm/parser.lm"
{ yygotominor.yy32.a = S->end_cascade(); }
#line 909 "vm/parser.c.inc"
        break;
      default:
      /* (1) opt_fin ::= */ yytestcase(yyruleno==1);
      /* (2) opt_fin ::= opt_fin FIN */ yytestcase(yyruleno==2);
      /* (3) last_fin ::= EOF */ yytestcase(yyruleno==3);
      /* (4) last_fin ::= fin EOF */ yytestcase(yyruleno==4);
      /* (5) fin ::= fin FIN */ yytestcase(yyruleno==5);
      /* (6) fin ::= FIN */ yytestcase(yyruleno==6);
      /* (16) def_args ::= */ yytestcase(yyruleno==16);
      /* (17) def_args ::= LP id_list RP */ yytestcase(yyruleno==17);
      /* (30) opt_kw_arg_list ::= */ yytestcase(yyruleno==30);
      /* (31) opt_kw_arg_list ::= COMMA kw_arg_list_elems */ yytestcase(yyruleno==31);
      /* (32) arg_list ::= arg_list_start arg_list_elems opt_kw_arg_list */ yytestcase(yyruleno==32);
      /* (35) kw_arg_list_elems ::= kw_arg_list_elems COMMA kw_arg */ yytestcase(yyruleno==35);
      /* (36) kw_arg_list_elems ::= kw_arg */ yytestcase(yyruleno==36);
      /* (37) kw_arg_list ::= arg_list_start kw_arg_list_elems */ yytestcase(yyruleno==37);
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
#line 991 "vm/parser.c.inc"
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
