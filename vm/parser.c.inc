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
#define YYNOCODE 75
#define YYACTIONTYPE unsigned short int
#define mariusParserTOKENTYPE  marius::ParserToken 
typedef union {
  int yyinit;
  mariusParserTOKENTYPE yy0;
  marius::ParserToken yy92;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define mariusParserARG_SDECL  marius::ParserState* S ;
#define mariusParserARG_PDECL , marius::ParserState* S 
#define mariusParserARG_FETCH  marius::ParserState* S  = yypParser->S 
#define mariusParserARG_STORE yypParser->S  = S 
#define YYNSTATE 191
#define YYNRULE 101
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
#define YY_ACTTAB_COUNT (894)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    30,  178,  186,  185,  184,   40,  182,   96,   45,  111,
 /*    10 */   180,  179,  191,  171,  170,  169,  168,  167,   95,  164,
 /*    20 */   100,   73,   20,   71,  157,  186,  185,   28,   27,   26,
 /*    30 */    99,   55,   22,  115,   25,   30,  177,  186,  185,   50,
 /*    40 */   175,  182,  181,   45,   47,  180,  186,  185,  171,  170,
 /*    50 */   169,  168,  167,   95,  164,  110,   72,   20,   71,  157,
 /*    60 */   293,    3,   28,   27,   26,   99,   55,  186,  185,   25,
 /*    70 */    30,  176,  186,  185,   41,   40,  182,   96,   45,  108,
 /*    80 */   180,   20,   43,  171,  170,  169,  168,  167,   95,  164,
 /*    90 */    31,  130,   70,   71,  157,   96,   21,   28,   27,   26,
 /*   100 */    99,   55,   29,  156,   25,   30,   69,  186,  185,  161,
 /*   110 */   117,    5,  172,   45,  127,  104,  132,   20,  171,  170,
 /*   120 */   169,  168,  167,   95,  164,  186,  185,  119,   71,  157,
 /*   130 */   159,  154,   28,   27,   26,   99,   55,  105,  150,   25,
 /*   140 */    30,   63,  186,  185,  103,  147,   20,  138,   45,  102,
 /*   150 */   153,   20,   20,  171,  170,  169,  168,  167,   95,  164,
 /*   160 */     4,    6,  145,   71,  157,  132,  132,   28,   27,   26,
 /*   170 */    99,   55,  143,  135,   25,   30,   17,  186,  185,   11,
 /*   180 */    80,  132,  137,   45,  132,  149,  174,   20,  171,  170,
 /*   190 */   169,  168,  167,   95,  164,   16,   10,   74,   71,  157,
 /*   200 */   132,  132,   28,   27,   26,   99,   55,  106,   19,   25,
 /*   210 */    30,   15,  186,  185,    9,  129,  132,  136,   45,  132,
 /*   220 */   146,  115,   20,  171,  170,  169,  168,  167,   95,  164,
 /*   230 */    14,    8,   77,   71,  157,  132,  132,   28,   27,   26,
 /*   240 */    99,   55,   98,   81,   25,   30,   13,  186,  185,    7,
 /*   250 */   114,  132,   12,   45,  132,  109,   46,  132,  171,  170,
 /*   260 */   169,  168,  167,   95,  164,    1,    2,  162,   71,  157,
 /*   270 */   132,  132,   28,   27,   26,   99,   55,   53,  160,   25,
 /*   280 */    30,   18,  186,  185,  155,  151,  132,  134,   45,  148,
 /*   290 */   294,  294,  294,  171,  170,  169,  168,  167,   95,  164,
 /*   300 */   294,  294,  294,   71,  157,  294,  294,   28,   27,   26,
 /*   310 */    99,   55,  294,  294,   25,   30,  294,  186,  185,  294,
 /*   320 */   294,  294,  123,   45,  294,  294,  294,  294,  171,  170,
 /*   330 */   169,  168,  167,   95,  164,  294,  294,  294,   71,  157,
 /*   340 */   294,  294,   28,   27,   26,   99,   55,  294,  294,   25,
 /*   350 */    30,  294,  186,  185,  294,  294,  294,  294,   45,  294,
 /*   360 */   294,  294,  294,  171,  170,  169,  168,  167,   95,  164,
 /*   370 */   294,  294,  294,   71,  157,   30,  294,   28,   27,   26,
 /*   380 */    99,   55,  294,   45,   25,  294,  294,  294,  171,  170,
 /*   390 */   169,  168,  167,   95,  164,  173,  183,  294,   71,  157,
 /*   400 */   294,  139,   28,   27,   26,   99,   55,  152,   64,   25,
 /*   410 */   144,  122,  189,  188,  187,  183,   82,   79,  116,  121,
 /*   420 */   139,   75,  294,  294,  294,  294,  152,  294,  294,  144,
 /*   430 */   294,  294,  294,  294,   64,   82,   79,  122,  189,  188,
 /*   440 */   187,  183,  294,  294,  116,  120,  139,   75,  141,  294,
 /*   450 */   294,  294,  152,  294,  152,  144,  294,  144,  294,  245,
 /*   460 */   294,   82,   79,   82,   79,  294,  294,  245,  294,  294,
 /*   470 */    68,  294,  245,  245,  245,  245,  245,  245,  245,  294,
 /*   480 */    24,   44,  294,  245,  122,  189,  188,  187,  118,  294,
 /*   490 */   294,  116,   23,  139,   75,  294,  294,  294,  294,  152,
 /*   500 */   294,  294,  144,  190,  189,  188,  187,  183,   82,   79,
 /*   510 */   116,  294,  139,   75,  142,  294,  294,  294,  152,  294,
 /*   520 */   152,  144,  294,  144,  294,  245,  294,   82,   79,   82,
 /*   530 */    79,  294,  294,  245,  294,  294,   68,  294,  245,  245,
 /*   540 */   245,  245,  245,  245,  245,  245,  294,  163,   90,  245,
 /*   550 */   158,  294,  294,  245,  294,  294,   67,   79,  245,  245,
 /*   560 */   245,  245,  245,  245,  245,  245,  294,  163,   93,  245,
 /*   570 */   158,  294,  294,  245,  294,  294,   66,   79,  245,  245,
 /*   580 */   245,  245,  245,  245,  245,   30,  294,  294,  294,  245,
 /*   590 */   294,  294,  294,   48,  294,  294,  294,  294,  171,  170,
 /*   600 */   169,  168,  167,  165,  164,   37,  294,  294,   71,  157,
 /*   610 */   294,  294,  294,  166,  294,  294,  294,  294,  171,  170,
 /*   620 */   169,  168,  167,  165,  164,   37,  294,  163,   97,  157,
 /*   630 */   158,  294,  294,  113,  294,  294,  294,   79,  171,  170,
 /*   640 */   169,  168,  167,  165,  164,  163,  112,  294,  158,  157,
 /*   650 */   131,  183,  294,   62,  294,   79,  139,  294,  124,  294,
 /*   660 */   294,  294,  152,  294,  294,  144,  294,  294,  166,  294,
 /*   670 */   294,   82,   79,  171,  170,  169,  168,  167,  165,  164,
 /*   680 */   131,  183,  140,   60,  131,  183,  139,   58,  152,  294,
 /*   690 */   139,  144,  152,  294,  294,  144,  152,   82,   79,  144,
 /*   700 */   294,   82,   79,  294,  294,   82,   79,  131,  183,  294,
 /*   710 */    56,  163,   92,  139,  158,  294,  294,  294,  294,  152,
 /*   720 */   294,   79,  144,  294,  131,  183,  294,   54,   82,   79,
 /*   730 */   139,  294,  131,  183,   61,   52,  152,  294,  139,  144,
 /*   740 */   152,  294,  294,  144,  152,   82,   79,  144,  294,   82,
 /*   750 */    79,  294,  294,   82,   79,   35,   36,   32,   34,   33,
 /*   760 */   294,   94,  163,   84,  294,  158,  294,   65,  128,   76,
 /*   770 */   294,  294,   79,  131,  163,   91,   49,  158,  294,  139,
 /*   780 */   294,  294,  101,  294,   79,  152,  294,  294,  144,  294,
 /*   790 */   294,  294,  294,  294,   82,   79,   42,   39,   38,   41,
 /*   800 */    40,  294,   96,   59,  294,  294,  294,  163,   83,  152,
 /*   810 */   158,  294,  144,  128,   78,   57,  294,   79,   82,   79,
 /*   820 */   133,  152,  163,  107,  144,  158,  152,  294,  294,  144,
 /*   830 */    82,   79,   79,  126,  294,   82,   79,  163,   89,  152,
 /*   840 */   158,  294,  144,  294,  294,  125,  294,   79,   82,   79,
 /*   850 */   294,  152,  294,   51,  144,  294,  294,  294,  294,  152,
 /*   860 */    82,   79,  144,  163,   88,  294,  158,  294,   82,   79,
 /*   870 */   294,  163,   87,   79,  158,  163,   86,  294,  158,  294,
 /*   880 */   294,   79,  294,  163,   85,   79,  158,  294,  294,  294,
 /*   890 */   294,  294,  294,   79,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,    4,    8,    9,   10,    5,   12,    7,   14,   14,
 /*    10 */    16,   14,    0,   19,   20,   21,   22,   23,   24,   25,
 /*    20 */    64,   26,   66,   29,   30,    8,    9,   33,   34,   35,
 /*    30 */    36,   37,   15,   11,   40,    6,    8,    8,    9,   14,
 /*    40 */    18,   12,   13,   14,   14,   16,    8,    9,   19,   20,
 /*    50 */    21,   22,   23,   24,   25,   64,   26,   66,   29,   30,
 /*    60 */    42,   43,   33,   34,   35,   36,   37,    8,    9,   40,
 /*    70 */     6,   14,    8,    9,    4,    5,   12,    7,   14,   64,
 /*    80 */    16,   66,   27,   19,   20,   21,   22,   23,   24,   25,
 /*    90 */    27,   32,   17,   29,   30,    7,   52,   33,   34,   35,
 /*   100 */    36,   37,   39,   31,   40,    6,   17,    8,    9,   18,
 /*   110 */    45,   46,   13,   14,   70,   64,   51,   66,   19,   20,
 /*   120 */    21,   22,   23,   24,   25,    8,    9,   10,   29,   30,
 /*   130 */    18,   18,   33,   34,   35,   36,   37,   14,   18,   40,
 /*   140 */     6,   60,    8,    9,   64,   18,   66,   13,   14,   64,
 /*   150 */    64,   66,   66,   19,   20,   21,   22,   23,   24,   25,
 /*   160 */    46,   46,   14,   29,   30,   51,   51,   33,   34,   35,
 /*   170 */    36,   37,   18,   14,   40,    6,   46,    8,    9,   46,
 /*   180 */    17,   51,   13,   14,   51,   64,   14,   66,   19,   20,
 /*   190 */    21,   22,   23,   24,   25,   46,   46,   59,   29,   30,
 /*   200 */    51,   51,   33,   34,   35,   36,   37,   31,   73,   40,
 /*   210 */     6,   46,    8,    9,   46,   68,   51,   13,   14,   51,
 /*   220 */    64,   11,   66,   19,   20,   21,   22,   23,   24,   25,
 /*   230 */    46,   46,   52,   29,   30,   51,   51,   33,   34,   35,
 /*   240 */    36,   37,   14,   61,   40,    6,   46,    8,    9,   46,
 /*   250 */    52,   51,   46,   14,   51,   62,   62,   51,   19,   20,
 /*   260 */    21,   22,   23,   24,   25,   46,   46,   18,   29,   30,
 /*   270 */    51,   51,   33,   34,   35,   36,   37,   38,   18,   40,
 /*   280 */     6,   46,    8,    9,   18,   18,   51,   13,   14,   18,
 /*   290 */    74,   74,   74,   19,   20,   21,   22,   23,   24,   25,
 /*   300 */    74,   74,   74,   29,   30,   74,   74,   33,   34,   35,
 /*   310 */    36,   37,   74,   74,   40,    6,   74,    8,    9,   74,
 /*   320 */    74,   74,   13,   14,   74,   74,   74,   74,   19,   20,
 /*   330 */    21,   22,   23,   24,   25,   74,   74,   74,   29,   30,
 /*   340 */    74,   74,   33,   34,   35,   36,   37,   74,   74,   40,
 /*   350 */     6,   74,    8,    9,   74,   74,   74,   74,   14,   74,
 /*   360 */    74,   74,   74,   19,   20,   21,   22,   23,   24,   25,
 /*   370 */    74,   74,   74,   29,   30,    6,   74,   33,   34,   35,
 /*   380 */    36,   37,   74,   14,   40,   74,   74,   74,   19,   20,
 /*   390 */    21,   22,   23,   24,   25,   50,   51,   74,   29,   30,
 /*   400 */    74,   56,   33,   34,   35,   36,   37,   62,   44,   40,
 /*   410 */    65,   47,   48,   49,   50,   51,   71,   72,   54,   55,
 /*   420 */    56,   57,   74,   74,   74,   74,   62,   74,   74,   65,
 /*   430 */    74,   74,   74,   74,   44,   71,   72,   47,   48,   49,
 /*   440 */    50,   51,   74,   74,   54,   55,   56,   57,   56,   74,
 /*   450 */    74,   74,   62,   74,   62,   65,   74,   65,   74,    6,
 /*   460 */    74,   71,   72,   71,   72,   74,   74,   14,   74,   74,
 /*   470 */    17,   74,   19,   20,   21,   22,   23,   24,   25,   74,
 /*   480 */    27,   44,   74,   30,   47,   48,   49,   50,   51,   74,
 /*   490 */    74,   54,   39,   56,   57,   74,   74,   74,   74,   62,
 /*   500 */    74,   74,   65,   47,   48,   49,   50,   51,   71,   72,
 /*   510 */    54,   74,   56,   57,   56,   74,   74,   74,   62,   74,
 /*   520 */    62,   65,   74,   65,   74,    6,   74,   71,   72,   71,
 /*   530 */    72,   74,   74,   14,   74,   74,   17,   74,   19,   20,
 /*   540 */    21,   22,   23,   24,   25,    6,   74,   62,   63,   30,
 /*   550 */    65,   74,   74,   14,   74,   74,   17,   72,   19,   20,
 /*   560 */    21,   22,   23,   24,   25,    6,   74,   62,   63,   30,
 /*   570 */    65,   74,   74,   14,   74,   74,   17,   72,   19,   20,
 /*   580 */    21,   22,   23,   24,   25,    6,   74,   74,   74,   30,
 /*   590 */    74,   74,   74,   14,   74,   74,   74,   74,   19,   20,
 /*   600 */    21,   22,   23,   24,   25,    6,   74,   74,   29,   30,
 /*   610 */    74,   74,   74,   14,   74,   74,   74,   74,   19,   20,
 /*   620 */    21,   22,   23,   24,   25,    6,   74,   62,   63,   30,
 /*   630 */    65,   74,   74,   14,   74,   74,   74,   72,   19,   20,
 /*   640 */    21,   22,   23,   24,   25,   62,   63,   74,   65,   30,
 /*   650 */    50,   51,   74,   53,   74,   72,   56,   74,   58,   74,
 /*   660 */    74,   74,   62,   74,   74,   65,   74,   74,   14,   74,
 /*   670 */    74,   71,   72,   19,   20,   21,   22,   23,   24,   25,
 /*   680 */    50,   51,   56,   53,   50,   51,   56,   53,   62,   74,
 /*   690 */    56,   65,   62,   74,   74,   65,   62,   71,   72,   65,
 /*   700 */    74,   71,   72,   74,   74,   71,   72,   50,   51,   74,
 /*   710 */    53,   62,   63,   56,   65,   74,   74,   74,   74,   62,
 /*   720 */    74,   72,   65,   74,   50,   51,   74,   53,   71,   72,
 /*   730 */    56,   74,   50,   51,   56,   53,   62,   74,   56,   65,
 /*   740 */    62,   74,   74,   65,   62,   71,   72,   65,   74,   71,
 /*   750 */    72,   74,   74,   71,   72,    1,    2,    3,    4,    5,
 /*   760 */    74,    7,   62,   63,   74,   65,   74,   67,   68,   69,
 /*   770 */    74,   74,   72,   50,   62,   63,   53,   65,   74,   56,
 /*   780 */    74,   74,   28,   74,   72,   62,   74,   74,   65,   74,
 /*   790 */    74,   74,   74,   74,   71,   72,    1,    2,    3,    4,
 /*   800 */     5,   74,    7,   56,   74,   74,   74,   62,   63,   62,
 /*   810 */    65,   74,   65,   68,   69,   56,   74,   72,   71,   72,
 /*   820 */    56,   62,   62,   63,   65,   65,   62,   74,   74,   65,
 /*   830 */    71,   72,   72,   56,   74,   71,   72,   62,   63,   62,
 /*   840 */    65,   74,   65,   74,   74,   56,   74,   72,   71,   72,
 /*   850 */    74,   62,   74,   56,   65,   74,   74,   74,   74,   62,
 /*   860 */    71,   72,   65,   62,   63,   74,   65,   74,   71,   72,
 /*   870 */    74,   62,   63,   72,   65,   62,   63,   74,   65,   74,
 /*   880 */    74,   72,   74,   62,   63,   72,   65,   74,   74,   74,
 /*   890 */    74,   74,   74,   72,
};
#define YY_SHIFT_USE_DFLT (-7)
#define YY_SHIFT_COUNT (117)
#define YY_SHIFT_MIN   (-6)
#define YY_SHIFT_MAX   (795)
static const short yy_shift_ofst[] = {
 /*     0 */    -7,   64,   64,   64,   29,   -6,  309,  344,  344,  344,
 /*    10 */   344,  344,  274,  239,  204,  169,  134,   99,  344,  369,
 /*    20 */   619,  619,  579,  579,  579,  579,  579,  579,  579,  579,
 /*    30 */   579,  579,  599,  599,  599,  599,  599,  599,  599,  599,
 /*    40 */   599,  599,  599,  599,  117,  453,  559,  539,  519,   59,
 /*    50 */    17,   38,   38,   38,   38,   38,   38,   38,   38,   38,
 /*    60 */    38,   38,   38,   38,   38,  210,  271,  267,  266,  260,
 /*    70 */   249,   -7,  654,  654,   22,   -3,  210,  228,  210,  176,
 /*    80 */   172,  163,  754,  795,  795,  795,  795,  795,  795,  795,
 /*    90 */   795,   70,   70,   70,   30,   63,   -5,    0,   55,  159,
 /*   100 */   154,  148,  127,  120,  113,   72,  123,   88,  112,   89,
 /*   110 */    91,   75,   88,   55,   57,   28,   25,   12,
};
#define YY_REDUCE_USE_DFLT (-45)
#define YY_REDUCE_COUNT (81)
#define YY_REDUCE_MIN   (-44)
#define YY_REDUCE_MAX   (821)
static const short yy_reduce_ofst[] = {
 /*     0 */    18,  390,  364,  437,  456,  456,  600,  682,  674,  657,
 /*    10 */   634,  630,  345,  345,  345,  345,  345,  345,  345,  723,
 /*    20 */   700,  745,  797,  789,  777,  764,  759,  747,  678,  626,
 /*    30 */   458,  392,  821,  813,  809,  801,  775,  760,  712,  649,
 /*    40 */   583,  565,  505,  485,   65,   86,  156,  121,   86,  235,
 /*    50 */   220,  219,  206,  203,  200,  185,  184,  168,  165,  150,
 /*    60 */   149,  133,  130,  115,  114,   44,   85,   80,   51,   15,
 /*    70 */    -9,  -44,  194,  193,  198,  182,  180,  147,  180,  135,
 /*    80 */   138,   81,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   199,  292,  292,  292,  292,  292,  292,  292,  292,  292,
 /*    10 */   292,  292,  292,  292,  292,  292,  292,  292,  292,  292,
 /*    20 */   292,  292,  292,  292,  292,  292,  292,  292,  292,  292,
 /*    30 */   292,  292,  292,  292,  292,  292,  292,  292,  292,  292,
 /*    40 */   292,  292,  292,  292,  292,  228,  262,  258,  228,  292,
 /*    50 */   292,  292,  292,  292,  292,  292,  292,  292,  292,  292,
 /*    60 */   292,  292,  292,  292,  292,  251,  245,  245,  245,  245,
 /*    70 */   245,  245,  292,  292,  292,  292,  254,  292,  252,  280,
 /*    80 */   292,  217,  275,  246,  247,  274,  273,  272,  271,  270,
 /*    90 */   248,  236,  235,  232,  292,  229,  292,  233,  292,  292,
 /*   100 */   292,  292,  292,  292,  292,  292,  292,  243,  292,  240,
 /*   110 */   292,  237,  234,  228,  292,  206,  292,  292,  200,  201,
 /*   120 */   212,  211,  193,  222,  221,  288,  287,  253,  250,  249,
 /*   130 */   281,  208,  204,  291,  286,  285,  284,  283,  282,  277,
 /*   140 */   290,  289,  276,  266,  265,  261,  268,  264,  263,  267,
 /*   150 */   260,  259,  255,  269,  257,  256,  279,  278,  244,  242,
 /*   160 */   241,  239,  238,  231,  230,  229,  228,  227,  226,  225,
 /*   170 */   224,  223,  214,  207,  216,  218,  215,  205,  220,  219,
 /*   180 */   213,  210,  209,  203,  202,  198,  197,  196,  195,  194,
 /*   190 */   192,
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
  "IMPORT",        "TRY",           "RESCUE",        "OP1_SET",     
  "RAISE",         "error",         "program",       "opt_fin",     
  "l1",            "last_fin",      "fin",           "l1e",         
  "class",         "def",           "stmt",          "fin_m",       
  "comma",         "seq",           "class_start",   "class_body",  
  "s2",            "def_start",     "def_body",      "id_list",     
  "def_args",      "def_name",      "lit",           "np_arg",      
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
 /*  28 */ "def_name ::= ID",
 /*  29 */ "def_name ::= OP1",
 /*  30 */ "def ::= def_start def_name def_args fin def_body",
 /*  31 */ "def ::= def_start def_name def_args fin END",
 /*  32 */ "lit ::= NUM",
 /*  33 */ "lit ::= NIL",
 /*  34 */ "lit ::= TRUE",
 /*  35 */ "lit ::= FALSE",
 /*  36 */ "lit ::= SELF",
 /*  37 */ "lit ::= ID",
 /*  38 */ "lit ::= IVAR",
 /*  39 */ "lit ::= LITSTR",
 /*  40 */ "np_arg ::= lit",
 /*  41 */ "np_arg ::= np_arg OP0 np_arg",
 /*  42 */ "np_arg ::= np_arg OP1 np_arg",
 /*  43 */ "np_arg ::= np_arg OP2 np_arg",
 /*  44 */ "np_arg ::= np_arg CAST np_arg",
 /*  45 */ "np_arg ::= np_arg NEQUAL np_arg",
 /*  46 */ "np_arg ::= np_arg DOT ID",
 /*  47 */ "np_arg ::= np_arg DOT ID LP RP",
 /*  48 */ "np_arg ::= np_arg DOT ID LP np_arg_list RP",
 /*  49 */ "np_arg ::= np_arg DOT DOLLAR lit",
 /*  50 */ "np_arg ::= np_arg DOT DOLLAR lit LP RP",
 /*  51 */ "np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP",
 /*  52 */ "np_arg ::= NOT np_arg",
 /*  53 */ "np_arg ::= lambda",
 /*  54 */ "np_arg_list_start ::=",
 /*  55 */ "np_arg_list_elems ::= np_arg_list_elems comma np_arg",
 /*  56 */ "np_arg_list_elems ::= np_arg",
 /*  57 */ "np_kw_arg ::= ID EQUAL np_arg",
 /*  58 */ "np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg",
 /*  59 */ "np_kw_arg_list_elems ::= np_kw_arg",
 /*  60 */ "np_opt_kw_arg_list ::=",
 /*  61 */ "np_opt_kw_arg_list ::= comma np_kw_arg_list_elems",
 /*  62 */ "np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list",
 /*  63 */ "np_arg_list ::= np_arg_list_start np_kw_arg_list_elems",
 /*  64 */ "np_recv ::= lit",
 /*  65 */ "np_recv ::= ID LP RP",
 /*  66 */ "np_recv ::= ID LP np_arg_list RP",
 /*  67 */ "np_recv ::= np_recv DOT ID",
 /*  68 */ "np_recv ::= np_recv DOT ID LP RP",
 /*  69 */ "np_recv ::= np_recv DOT ID LP np_arg_list RP",
 /*  70 */ "np_recv ::= np_recv DCOLON ID",
 /*  71 */ "np_recv ::= np_recv DOT DOLLAR lit",
 /*  72 */ "np_recv ::= np_recv DOT DOLLAR lit LP RP",
 /*  73 */ "np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP",
 /*  74 */ "np_recv ::= lambda",
 /*  75 */ "np_recv ::= TUPLE_START np_arg_list RP",
 /*  76 */ "s2 ::= np_recv DOT ID np_arg_list",
 /*  77 */ "s2 ::= np_recv DOT DOLLAR lit np_arg_list",
 /*  78 */ "s2 ::= ID np_arg_list",
 /*  79 */ "s2 ::= np_recv CAST np_arg",
 /*  80 */ "s2 ::= np_recv OP0 np_arg",
 /*  81 */ "s2 ::= np_recv OP1 np_arg",
 /*  82 */ "s2 ::= np_recv OP2 np_arg",
 /*  83 */ "s2 ::= np_recv NEQUAL np_arg",
 /*  84 */ "s2 ::= np_recv",
 /*  85 */ "s2 ::= NOT s2",
 /*  86 */ "stmt ::= s2",
 /*  87 */ "lambda_start ::= LB",
 /*  88 */ "lambda_args ::= PIPE ID PIPE",
 /*  89 */ "lambda_args ::=",
 /*  90 */ "lambda ::= lambda_start lambda_args seq RB",
 /*  91 */ "stmt ::= IF s2 fin seq fin END",
 /*  92 */ "stmt ::= UNLESS s2 fin seq fin END",
 /*  93 */ "stmt ::= WHILE s2 fin seq fin END",
 /*  94 */ "stmt ::= IMPORT ID",
 /*  95 */ "stmt ::= TRY fin seq fin RESCUE fin seq fin END",
 /*  96 */ "stmt ::= ID EQUAL s2",
 /*  97 */ "stmt ::= ID OP1_SET s2",
 /*  98 */ "stmt ::= IVAR EQUAL s2",
 /*  99 */ "stmt ::= IVAR OP1_SET s2",
 /* 100 */ "stmt ::= RAISE s2",
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
  { 42, 3 },
  { 44, 3 },
  { 44, 1 },
  { 47, 1 },
  { 47, 1 },
  { 47, 1 },
  { 51, 1 },
  { 51, 1 },
  { 43, 0 },
  { 43, 2 },
  { 45, 1 },
  { 45, 2 },
  { 46, 2 },
  { 46, 1 },
  { 52, 2 },
  { 52, 1 },
  { 53, 3 },
  { 53, 1 },
  { 54, 1 },
  { 55, 3 },
  { 48, 4 },
  { 48, 6 },
  { 57, 1 },
  { 58, 3 },
  { 59, 3 },
  { 59, 1 },
  { 60, 0 },
  { 60, 3 },
  { 61, 1 },
  { 61, 1 },
  { 49, 5 },
  { 49, 5 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 62, 1 },
  { 63, 1 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 3 },
  { 63, 5 },
  { 63, 6 },
  { 63, 4 },
  { 63, 6 },
  { 63, 7 },
  { 63, 2 },
  { 63, 1 },
  { 66, 0 },
  { 67, 3 },
  { 67, 1 },
  { 68, 3 },
  { 69, 3 },
  { 69, 1 },
  { 70, 0 },
  { 70, 2 },
  { 64, 3 },
  { 64, 2 },
  { 71, 1 },
  { 71, 3 },
  { 71, 4 },
  { 71, 3 },
  { 71, 5 },
  { 71, 6 },
  { 71, 3 },
  { 71, 4 },
  { 71, 6 },
  { 71, 7 },
  { 71, 1 },
  { 71, 3 },
  { 56, 4 },
  { 56, 5 },
  { 56, 2 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 3 },
  { 56, 1 },
  { 56, 2 },
  { 50, 1 },
  { 72, 1 },
  { 73, 3 },
  { 73, 0 },
  { 65, 4 },
  { 50, 6 },
  { 50, 6 },
  { 50, 6 },
  { 50, 2 },
  { 50, 9 },
  { 50, 3 },
  { 50, 3 },
  { 50, 3 },
  { 50, 3 },
  { 50, 2 },
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
{ S->set_top(S->ret(yymsp[-1].minor.yy92.a)); }
#line 1080 "vm/parser.c.inc"
        break;
      case 1: /* l1 ::= l1 fin l1e */
      case 16: /* seq ::= seq fin stmt */ yytestcase(yyruleno==16);
#line 32 "vm/parser.lm"
{ yygotominor.yy92.a = S->seq(yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a); }
#line 1086 "vm/parser.c.inc"
        break;
      case 2: /* l1 ::= l1e */
      case 3: /* l1e ::= class */ yytestcase(yyruleno==3);
      case 4: /* l1e ::= def */ yytestcase(yyruleno==4);
      case 5: /* l1e ::= stmt */ yytestcase(yyruleno==5);
      case 17: /* seq ::= stmt */ yytestcase(yyruleno==17);
      case 40: /* np_arg ::= lit */ yytestcase(yyruleno==40);
      case 53: /* np_arg ::= lambda */ yytestcase(yyruleno==53);
      case 64: /* np_recv ::= lit */ yytestcase(yyruleno==64);
      case 74: /* np_recv ::= lambda */ yytestcase(yyruleno==74);
      case 84: /* s2 ::= np_recv */ yytestcase(yyruleno==84);
      case 86: /* stmt ::= s2 */ yytestcase(yyruleno==86);
#line 33 "vm/parser.lm"
{ yygotominor.yy92.a = yymsp[0].minor.yy92.a; }
#line 1101 "vm/parser.c.inc"
        break;
      case 18: /* class_start ::= CLASS */
#line 57 "vm/parser.lm"
{ S->start_class(); }
#line 1106 "vm/parser.c.inc"
        break;
      case 19: /* class_body ::= l1 fin END */
      case 23: /* def_body ::= seq fin END */ yytestcase(yyruleno==23);
#line 58 "vm/parser.lm"
{ yygotominor.yy92.a = yymsp[-2].minor.yy92.a; }
#line 1112 "vm/parser.c.inc"
        break;
      case 20: /* class ::= class_start ID fin class_body */
#line 60 "vm/parser.lm"
{
               yygotominor.yy92.a = S->ast_class(yymsp[-2].minor.yy0.s, 0, yymsp[0].minor.yy92.a);
             }
#line 1119 "vm/parser.c.inc"
        break;
      case 21: /* class ::= class_start ID LT s2 fin class_body */
#line 64 "vm/parser.lm"
{
               yygotominor.yy92.a = S->ast_class(yymsp[-4].minor.yy0.s, yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a);
             }
#line 1126 "vm/parser.c.inc"
        break;
      case 22: /* def_start ::= DEF */
#line 68 "vm/parser.lm"
{ S->start_def(); }
#line 1131 "vm/parser.c.inc"
        break;
      case 24: /* id_list ::= id_list comma ID */
      case 25: /* id_list ::= ID */ yytestcase(yyruleno==25);
#line 71 "vm/parser.lm"
{ S->def_arg(yymsp[0].minor.yy0.s); }
#line 1137 "vm/parser.c.inc"
        break;
      case 28: /* def_name ::= ID */
      case 29: /* def_name ::= OP1 */ yytestcase(yyruleno==29);
#line 77 "vm/parser.lm"
{ yygotominor.yy92.s = yymsp[0].minor.yy0.s; }
#line 1143 "vm/parser.c.inc"
        break;
      case 30: /* def ::= def_start def_name def_args fin def_body */
#line 81 "vm/parser.lm"
{
              yygotominor.yy92.a = S->ast_def(yymsp[-3].minor.yy92.s, yymsp[0].minor.yy92.a);
            }
#line 1150 "vm/parser.c.inc"
        break;
      case 31: /* def ::= def_start def_name def_args fin END */
#line 84 "vm/parser.lm"
{
              yygotominor.yy92.a = S->ast_def(yymsp[-3].minor.yy92.s, S->ast_nil());
            }
#line 1157 "vm/parser.c.inc"
        break;
      case 32: /* lit ::= NUM */
#line 88 "vm/parser.lm"
{ yygotominor.yy92.a = S->number(yymsp[0].minor.yy0.i); }
#line 1162 "vm/parser.c.inc"
        break;
      case 33: /* lit ::= NIL */
#line 89 "vm/parser.lm"
{ yygotominor.yy92.a = S->ast_nil();  }
#line 1167 "vm/parser.c.inc"
        break;
      case 34: /* lit ::= TRUE */
#line 90 "vm/parser.lm"
{ yygotominor.yy92.a = S->ast_true();  }
#line 1172 "vm/parser.c.inc"
        break;
      case 35: /* lit ::= FALSE */
#line 91 "vm/parser.lm"
{ yygotominor.yy92.a = S->ast_false(); }
#line 1177 "vm/parser.c.inc"
        break;
      case 36: /* lit ::= SELF */
#line 92 "vm/parser.lm"
{ yygotominor.yy92.a = S->self(); }
#line 1182 "vm/parser.c.inc"
        break;
      case 37: /* lit ::= ID */
#line 93 "vm/parser.lm"
{ yygotominor.yy92.a = S->named(yymsp[0].minor.yy0.s); }
#line 1187 "vm/parser.c.inc"
        break;
      case 38: /* lit ::= IVAR */
#line 94 "vm/parser.lm"
{ yygotominor.yy92.a = S->ivar_read(yymsp[0].minor.yy0.s); }
#line 1192 "vm/parser.c.inc"
        break;
      case 39: /* lit ::= LITSTR */
#line 95 "vm/parser.lm"
{ yygotominor.yy92.a = S->lit_str(yymsp[0].minor.yy0.s); }
#line 1197 "vm/parser.c.inc"
        break;
      case 41: /* np_arg ::= np_arg OP0 np_arg */
      case 42: /* np_arg ::= np_arg OP1 np_arg */ yytestcase(yyruleno==42);
      case 80: /* s2 ::= np_recv OP0 np_arg */ yytestcase(yyruleno==80);
      case 81: /* s2 ::= np_recv OP1 np_arg */ yytestcase(yyruleno==81);
#line 99 "vm/parser.lm"
{ yygotominor.yy92.a = S->ast_binop(yymsp[-1].minor.yy0.s, yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a); }
#line 1205 "vm/parser.c.inc"
        break;
      case 43: /* np_arg ::= np_arg OP2 np_arg */
      case 82: /* s2 ::= np_recv OP2 np_arg */ yytestcase(yyruleno==82);
#line 103 "vm/parser.lm"
{ yygotominor.yy92.a = S->ast_binop(yymsp[-1].minor.yy0.cs, yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a); }
#line 1211 "vm/parser.c.inc"
        break;
      case 44: /* np_arg ::= np_arg CAST np_arg */
      case 79: /* s2 ::= np_recv CAST np_arg */ yytestcase(yyruleno==79);
#line 105 "vm/parser.lm"
{ yygotominor.yy92.a = S->cast(yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a); }
#line 1217 "vm/parser.c.inc"
        break;
      case 45: /* np_arg ::= np_arg NEQUAL np_arg */
      case 83: /* s2 ::= np_recv NEQUAL np_arg */ yytestcase(yyruleno==83);
#line 107 "vm/parser.lm"
{ yygotominor.yy92.a = S->not_(S->ast_binop("==", yymsp[-2].minor.yy92.a, yymsp[0].minor.yy92.a)); }
#line 1223 "vm/parser.c.inc"
        break;
      case 46: /* np_arg ::= np_arg DOT ID */
      case 67: /* np_recv ::= np_recv DOT ID */ yytestcase(yyruleno==67);
#line 108 "vm/parser.lm"
{ yygotominor.yy92.a = S->call(yymsp[-2].minor.yy92.a, yymsp[0].minor.yy0.s); }
#line 1229 "vm/parser.c.inc"
        break;
      case 47: /* np_arg ::= np_arg DOT ID LP RP */
      case 68: /* np_recv ::= np_recv DOT ID LP RP */ yytestcase(yyruleno==68);
#line 109 "vm/parser.lm"
{ yygotominor.yy92.a = S->call(yymsp[-4].minor.yy92.a, yymsp[-2].minor.yy0.s); }
#line 1235 "vm/parser.c.inc"
        break;
      case 48: /* np_arg ::= np_arg DOT ID LP np_arg_list RP */
      case 69: /* np_recv ::= np_recv DOT ID LP np_arg_list RP */ yytestcase(yyruleno==69);
#line 111 "vm/parser.lm"
{ yygotominor.yy92.a = S->call_args(yymsp[-5].minor.yy92.a, yymsp[-3].minor.yy0.s); }
#line 1241 "vm/parser.c.inc"
        break;
      case 49: /* np_arg ::= np_arg DOT DOLLAR lit */
      case 71: /* np_recv ::= np_recv DOT DOLLAR lit */ yytestcase(yyruleno==71);
#line 113 "vm/parser.lm"
{ yygotominor.yy92.a = S->send_indirect(yymsp[-3].minor.yy92.a, yymsp[0].minor.yy92.a); }
#line 1247 "vm/parser.c.inc"
        break;
      case 50: /* np_arg ::= np_arg DOT DOLLAR lit LP RP */
      case 72: /* np_recv ::= np_recv DOT DOLLAR lit LP RP */ yytestcase(yyruleno==72);
#line 115 "vm/parser.lm"
{ yygotominor.yy92.a = S->send_indirect(yymsp[-5].minor.yy92.a, yymsp[-2].minor.yy92.a); }
#line 1253 "vm/parser.c.inc"
        break;
      case 51: /* np_arg ::= np_arg DOT DOLLAR lit LP np_arg_list RP */
      case 73: /* np_recv ::= np_recv DOT DOLLAR lit LP np_arg_list RP */ yytestcase(yyruleno==73);
#line 117 "vm/parser.lm"
{ yygotominor.yy92.a = S->send_indirect_args(yymsp[-6].minor.yy92.a, yymsp[-3].minor.yy92.a); }
#line 1259 "vm/parser.c.inc"
        break;
      case 52: /* np_arg ::= NOT np_arg */
      case 85: /* s2 ::= NOT s2 */ yytestcase(yyruleno==85);
#line 118 "vm/parser.lm"
{ yygotominor.yy92.a = S->not_(yymsp[0].minor.yy92.a); }
#line 1265 "vm/parser.c.inc"
        break;
      case 54: /* np_arg_list_start ::= */
#line 121 "vm/parser.lm"
{ S->start_arg_list(); }
#line 1270 "vm/parser.c.inc"
        break;
      case 55: /* np_arg_list_elems ::= np_arg_list_elems comma np_arg */
      case 56: /* np_arg_list_elems ::= np_arg */ yytestcase(yyruleno==56);
#line 122 "vm/parser.lm"
{ S->add_arg(yymsp[0].minor.yy92.a); }
#line 1276 "vm/parser.c.inc"
        break;
      case 57: /* np_kw_arg ::= ID EQUAL np_arg */
#line 125 "vm/parser.lm"
{ S->add_kw_arg(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy92.a); }
#line 1281 "vm/parser.c.inc"
        break;
      case 65: /* np_recv ::= ID LP RP */
#line 137 "vm/parser.lm"
{ yygotominor.yy92.a = S->call(S->self(), yymsp[-2].minor.yy0.s); }
#line 1286 "vm/parser.c.inc"
        break;
      case 66: /* np_recv ::= ID LP np_arg_list RP */
#line 138 "vm/parser.lm"
{ yygotominor.yy92.a = S->call_args(S->self(), yymsp[-3].minor.yy0.s); }
#line 1291 "vm/parser.c.inc"
        break;
      case 70: /* np_recv ::= np_recv DCOLON ID */
#line 142 "vm/parser.lm"
{ yygotominor.yy92.a = S->dcolon(yymsp[-2].minor.yy92.a, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy0.s); }
#line 1296 "vm/parser.c.inc"
        break;
      case 75: /* np_recv ::= TUPLE_START np_arg_list RP */
#line 150 "vm/parser.lm"
{ yygotominor.yy92.a = S->tuple(); }
#line 1301 "vm/parser.c.inc"
        break;
      case 76: /* s2 ::= np_recv DOT ID np_arg_list */
#line 152 "vm/parser.lm"
{ yygotominor.yy92.a = S->call_args(yymsp[-3].minor.yy92.a, yymsp[-1].minor.yy0.s); }
#line 1306 "vm/parser.c.inc"
        break;
      case 77: /* s2 ::= np_recv DOT DOLLAR lit np_arg_list */
#line 154 "vm/parser.lm"
{ yygotominor.yy92.a = S->send_indirect_args(yymsp[-4].minor.yy92.a, yymsp[-1].minor.yy92.a); }
#line 1311 "vm/parser.c.inc"
        break;
      case 78: /* s2 ::= ID np_arg_list */
#line 155 "vm/parser.lm"
{ yygotominor.yy92.a = S->call_args(S->self(), yymsp[-1].minor.yy0.s); }
#line 1316 "vm/parser.c.inc"
        break;
      case 87: /* lambda_start ::= LB */
#line 169 "vm/parser.lm"
{ S->start_lambda(); }
#line 1321 "vm/parser.c.inc"
        break;
      case 88: /* lambda_args ::= PIPE ID PIPE */
#line 171 "vm/parser.lm"
{ S->def_arg(yymsp[-1].minor.yy0.s); }
#line 1326 "vm/parser.c.inc"
        break;
      case 90: /* lambda ::= lambda_start lambda_args seq RB */
#line 174 "vm/parser.lm"
{ yygotominor.yy92.a = S->lambda(yymsp[-1].minor.yy92.a); }
#line 1331 "vm/parser.c.inc"
        break;
      case 91: /* stmt ::= IF s2 fin seq fin END */
#line 178 "vm/parser.lm"
{ yygotominor.yy92.a = S->if_cond(yymsp[-4].minor.yy92.a, yymsp[-2].minor.yy92.a); }
#line 1336 "vm/parser.c.inc"
        break;
      case 92: /* stmt ::= UNLESS s2 fin seq fin END */
#line 179 "vm/parser.lm"
{ yygotominor.yy92.a = S->unless(yymsp[-4].minor.yy92.a, yymsp[-2].minor.yy92.a); }
#line 1341 "vm/parser.c.inc"
        break;
      case 93: /* stmt ::= WHILE s2 fin seq fin END */
#line 180 "vm/parser.lm"
{ yygotominor.yy92.a = S->while_(yymsp[-4].minor.yy92.a, yymsp[-2].minor.yy92.a); }
#line 1346 "vm/parser.c.inc"
        break;
      case 94: /* stmt ::= IMPORT ID */
#line 184 "vm/parser.lm"
{ yygotominor.yy92.a = S->import(yymsp[0].minor.yy0.s); }
#line 1351 "vm/parser.c.inc"
        break;
      case 95: /* stmt ::= TRY fin seq fin RESCUE fin seq fin END */
#line 186 "vm/parser.lm"
{
              yygotominor.yy92.a = S->ast_try(yymsp[-6].minor.yy92.a, yymsp[-2].minor.yy92.a);
            }
#line 1358 "vm/parser.c.inc"
        break;
      case 96: /* stmt ::= ID EQUAL s2 */
#line 190 "vm/parser.lm"
{ yygotominor.yy92.a = S->assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy92.a); }
#line 1363 "vm/parser.c.inc"
        break;
      case 97: /* stmt ::= ID OP1_SET s2 */
#line 191 "vm/parser.lm"
{ yygotominor.yy92.a = S->assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy92.a); }
#line 1368 "vm/parser.c.inc"
        break;
      case 98: /* stmt ::= IVAR EQUAL s2 */
#line 192 "vm/parser.lm"
{ yygotominor.yy92.a = S->ivar_assign(yymsp[-2].minor.yy0.s, yymsp[0].minor.yy92.a); }
#line 1373 "vm/parser.c.inc"
        break;
      case 99: /* stmt ::= IVAR OP1_SET s2 */
#line 194 "vm/parser.lm"
{ yygotominor.yy92.a = S->ivar_assign_op(yymsp[-2].minor.yy0.s, yymsp[-1].minor.yy0.s, yymsp[0].minor.yy92.a); }
#line 1378 "vm/parser.c.inc"
        break;
      case 100: /* stmt ::= RAISE s2 */
#line 195 "vm/parser.lm"
{ yygotominor.yy92.a = S->raise(yymsp[0].minor.yy92.a); }
#line 1383 "vm/parser.c.inc"
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
      /* (58) np_kw_arg_list_elems ::= np_kw_arg_list_elems comma np_kw_arg */ yytestcase(yyruleno==58);
      /* (59) np_kw_arg_list_elems ::= np_kw_arg */ yytestcase(yyruleno==59);
      /* (60) np_opt_kw_arg_list ::= */ yytestcase(yyruleno==60);
      /* (61) np_opt_kw_arg_list ::= comma np_kw_arg_list_elems */ yytestcase(yyruleno==61);
      /* (62) np_arg_list ::= np_arg_list_start np_arg_list_elems np_opt_kw_arg_list */ yytestcase(yyruleno==62);
      /* (63) np_arg_list ::= np_arg_list_start np_kw_arg_list_elems */ yytestcase(yyruleno==63);
      /* (89) lambda_args ::= */ yytestcase(yyruleno==89);
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
#line 1470 "vm/parser.c.inc"
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
