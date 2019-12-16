/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c++2python.y" /* yacc.c:339  */

#include "c++2python.h"

#line 70 "c++2python.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c++2python.tab.h".  */
#ifndef YY_YY_C_2PYTHON_TAB_H_INCLUDED
# define YY_YY_C_2PYTHON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SHL_OP = 258,
    SHR_OP = 259,
    LE_OP = 260,
    GE_OP = 261,
    EQ_OP = 262,
    NE_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    ADD_ASSIGN = 266,
    IDENTIFIER = 267,
    CONSTANT = 268,
    CONSTANT_STRING = 269,
    CONSTANT_F = 270,
    INT = 271,
    FLOAT = 272,
    STRING = 273,
    CIN = 274,
    COUT = 275,
    IF = 276,
    ELSE = 277,
    FOR = 278,
    CONTINUE = 279,
    BREAK = 280,
    RETURN = 281,
    READ = 282,
    DO = 283,
    WHILE = 284,
    EXTDEFS = 285,
    PARAS = 286,
    STMTS = 287,
    DEFS = 288,
    DECS = 289,
    ARGS = 290,
    LIB1 = 291,
    LIB2 = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 6 "c++2python.y" /* yacc.c:355  */

    int i;
    struct ast_node *n;
	char* s;
	float f;

#line 155 "c++2python.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_C_2PYTHON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "c++2python.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   529

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,     2,     2,     2,
      38,    39,    51,    49,    40,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
      48,    46,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    41,    45,    46,    50,    51,    52,    53,
      58,    59,    63,    64,    68,    69,    70,    74,    75,    79,
      80,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    97,    98,    99,   100,   101,   105,   106,   107,   108,
     109,   113,   117,   121,   122,   126,   130,   131,   135,   136,
     137,   138,   139,   140,   141,   142,   146,   150,   154,   155,
     159,   160,   161,   165,   166,   167,   171,   172,   177,   178,
     182,   183,   187,   191,   195,   196,   197,   201,   202,   206,
     207,   211,   212,   213,   217,   218,   219,   220,   221,   225,
     229,   230,   231,   235,   236,   237,   241,   242,   246,   247,
     248,   252,   253,   254,   255,   259,   260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SHL_OP", "SHR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "ADD_ASSIGN", "IDENTIFIER",
  "CONSTANT", "CONSTANT_STRING", "CONSTANT_F", "INT", "FLOAT", "STRING",
  "CIN", "COUT", "IF", "ELSE", "FOR", "CONTINUE", "BREAK", "RETURN",
  "READ", "DO", "WHILE", "EXTDEFS", "PARAS", "STMTS", "DEFS", "DECS",
  "ARGS", "LIB1", "LIB2", "'('", "')'", "','", "'['", "']'", "'{'", "'}'",
  "';'", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'!'", "$accept",
  "program", "extdefs", "extdef", "func", "paras", "para", "var", "stmts",
  "stmt", "compound_stmt", "compound_stmt_func", "jump_stmt", "in_stmt",
  "out_stmt", "expr_stmt", "selection_stmt", "iteration_stmt", "do_stmt",
  "while_stmt", "defs", "def", "real", "str", "decs", "dec", "init",
  "expr", "assignment", "logical_or", "logical_and", "equality",
  "relational", "shift", "additive", "multi", "unary", "postfix",
  "primary", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
      44,    91,    93,   123,   125,    59,    61,    62,    60,    43,
      45,    42,    47,    33
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,     1,    48,    97,   -61,    46,    46,    46,    97,   -61,
     -61,    21,    38,    17,     4,   -61,    38,    24,     8,    38,
      29,    62,   -61,    -6,    73,   164,   -61,   -61,   -61,   238,
      99,   -61,   -61,    95,   -61,   -61,   114,   -61,    99,    99,
      99,   -61,   -15,   -61,    79,   -61,   -61,   -61,    99,    99,
      99,   128,   135,   110,   117,   238,   476,   121,   238,   203,
     -61,   238,   242,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   281,   -61,   116,   -61,   158,   162,    35,
       3,   -61,    52,    90,    10,   148,   -61,   -61,   -61,   150,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   113,   -61,
     182,   125,   238,     7,   154,   238,   171,   118,   238,   165,
     320,   359,   -61,   238,   -61,   -61,   238,   -61,   398,   -61,
     -61,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,     2,   -61,   156,   160,   161,
     174,    19,   180,   159,   183,   189,   -61,   191,   -61,   437,
     188,   190,   238,   -61,   162,   -61,    35,     3,     3,   -61,
     -61,   -61,   -61,    90,    90,   -61,   -61,   -61,   -61,   -61,
     -61,    77,   -61,   -61,   -61,   476,    65,   194,   112,   -61,
     -61,   238,   476,   192,   196,   197,   -61,   238,   212,   476,
     204,   107,   157,   200,   205,   -61,   -61,   -61,   220,   -61,
     476,   -61,   476,   476,   210,   476,   227,   199,   222,   -61,
     -61,   -61,   -61,   476,   -61,   476,   476,   230,   -61,   -61,
     -61,   -61,   476,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     1,     0,     0,     0,     3,     4,
       6,    17,     0,    70,     0,    68,     0,    63,     0,     0,
      66,     0,     5,     0,     0,     0,    35,    36,     7,     0,
       0,    60,     8,     0,    61,     9,     0,    62,     0,     0,
       0,    11,     0,    12,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,    19,    21,    29,    22,    23,    24,    25,
      26,    27,    28,     0,    58,     0,    73,    74,    77,    79,
      81,    84,    89,    90,    93,    96,    98,    71,    72,    17,
      69,    65,    64,    67,    14,    15,    16,    10,     0,    18,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,    97,     0,    33,    20,     0,    32,     0,    58,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,    41,     0,     0,    59,     0,   104,     0,
       0,     0,     0,    31,    78,    93,    80,    82,    83,    88,
      86,    85,    87,    91,    92,    94,    95,    76,    75,   100,
     105,     0,    42,    43,    44,     0,     0,     0,     0,    40,
      41,     0,     0,    41,    41,     0,    99,     0,    46,     0,
       0,     0,     0,     0,     0,    57,    39,    38,    41,   106,
       0,    55,     0,     0,     0,     0,     0,     0,     0,    37,
      47,    54,    53,     0,    51,     0,     0,     0,    56,    52,
      50,    49,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   264,   137,   -61,   175,    -3,   -57,   -49,
      11,    66,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -20,    -2,   -61,   -61,   -61,   244,   -61,   -29,    41,   -61,
     163,   153,    74,   -60,   -61,    59,   -33,   -61,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    12,    42,    43,    13,    62,    63,
      64,    28,    65,    66,    67,    68,    69,    70,    71,    72,
     107,    74,    18,    21,    14,    15,    87,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    10,   110,    17,    20,    73,    10,   106,   125,   126,
      38,    39,    40,   115,    45,    46,   118,    47,     1,    45,
      46,   133,    47,    27,    97,    98,   104,    27,   112,   109,
      27,    45,    46,    41,    47,    94,    95,    96,     3,   111,
      58,   169,   123,   124,    30,    58,    17,    20,     4,    31,
     127,   128,   141,    34,   149,    61,   134,    58,    11,    23,
      61,   115,    24,    29,   176,   159,   160,   161,   162,   115,
      33,   119,    61,   140,   142,    36,   144,    45,    46,   147,
      47,    25,    32,    26,   150,    35,    44,   151,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   165,   166,
     115,   129,   130,    58,   189,   146,   170,    37,    91,   119,
      92,    89,   177,     5,     6,     7,   186,   187,    61,    45,
      46,    99,    47,   185,    45,    46,   188,    47,    93,    38,
      39,    40,   100,   195,    48,    49,    50,   138,   101,   139,
     201,   131,   132,    16,    19,    58,   203,   190,   102,   193,
      58,   210,   194,   211,   212,   103,   214,   192,   199,   108,
      61,   120,   204,   206,   219,    61,   220,   221,   121,    45,
      46,   122,    47,   223,   167,   168,    45,    46,   217,    47,
      48,    49,    50,    51,    52,    53,   135,    54,   163,   164,
      55,    24,    56,    57,   137,    58,   205,   157,   158,   143,
     145,   172,    58,   179,   148,   173,   174,    59,    60,    26,
      61,    45,    46,   175,    47,    45,    46,    61,    47,    48,
      49,    50,    51,    52,    53,   178,    54,   181,   180,   105,
     182,    56,    57,   183,   200,   184,   196,    58,   216,   191,
     197,    58,   198,   202,   208,   207,    59,    60,    26,   213,
      45,    46,    61,    47,    45,    46,    61,    47,    48,    49,
      50,    51,    52,    53,   209,    54,   215,   218,   113,   222,
      56,    57,    22,   136,    90,   156,    58,     0,     0,     0,
      58,     0,     0,     0,   154,    59,   114,    26,     0,     0,
       0,    61,     0,    45,    46,    61,    47,    48,    49,    50,
      51,    52,    53,     0,    54,     0,     0,   116,     0,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,    59,   117,    26,     0,     0,     0,
       0,     0,    45,    46,    61,    47,    48,    49,    50,    51,
      52,    53,     0,    54,     0,     0,   105,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,     0,    59,   114,    26,     0,     0,     0,     0,
       0,    45,    46,    61,    47,    48,    49,    50,    51,    52,
      53,     0,    54,     0,     0,   105,     0,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,    59,   117,    26,     0,     0,     0,     0,     0,
      45,    46,    61,    47,    48,    49,    50,    51,    52,    53,
       0,    54,     0,     0,   152,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,    59,   153,    26,     0,     0,     0,     0,     0,    45,
      46,    61,    47,    48,    49,    50,    51,    52,    53,     0,
      54,     0,     0,   105,     0,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
      59,   153,    26,     0,     0,     0,     0,     0,    45,    46,
      61,    47,    48,    49,    50,    51,    52,    53,     0,    54,
       0,     0,   105,     0,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,    59,
       0,    26,     0,     0,     0,     0,     0,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      29,     3,    59,     6,     7,    25,     8,    56,     5,     6,
      16,    17,    18,    62,    12,    13,    73,    15,    36,    12,
      13,    11,    15,    12,    39,    40,    55,    16,    61,    58,
      19,    12,    13,    39,    15,    38,    39,    40,    37,    59,
      38,    39,     7,     8,    40,    38,    49,    50,     0,    45,
      47,    48,    45,    45,   111,    53,    46,    38,    12,    38,
      53,   110,    41,    46,    45,   125,   126,   127,   128,   118,
      46,    73,    53,   102,   103,    46,   105,    12,    13,   108,
      15,    43,    16,    45,   113,    19,    13,   116,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     149,    49,    50,    38,    39,   107,   135,    45,    13,   111,
      15,    12,   141,    16,    17,    18,    39,    40,    53,    12,
      13,    42,    15,   152,    12,    13,   175,    15,    14,    16,
      17,    18,     4,   182,    16,    17,    18,    12,     3,    14,
     189,    51,    52,     6,     7,    38,    39,   176,    38,   178,
      38,   200,   181,   202,   203,    38,   205,    45,   187,    38,
      53,    45,   191,   192,   213,    53,   215,   216,    10,    12,
      13,     9,    15,   222,   133,   134,    12,    13,   207,    15,
      16,    17,    18,    19,    20,    21,    38,    23,   129,   130,
      26,    41,    28,    29,    12,    38,    39,   123,   124,    45,
      29,    45,    38,    44,    39,    45,    45,    43,    44,    45,
      53,    12,    13,    39,    15,    12,    13,    53,    15,    16,
      17,    18,    19,    20,    21,    45,    23,    38,    45,    26,
      39,    28,    29,    45,    22,    45,    44,    38,    39,    45,
      44,    38,    45,    39,    39,    45,    43,    44,    45,    39,
      12,    13,    53,    15,    12,    13,    53,    15,    16,    17,
      18,    19,    20,    21,    44,    23,    39,    45,    26,    39,
      28,    29,     8,    98,    30,   122,    38,    -1,    -1,    -1,
      38,    -1,    -1,    -1,   121,    43,    44,    45,    -1,    -1,
      -1,    53,    -1,    12,    13,    53,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    12,    13,    53,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    12,    13,    53,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    26,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      12,    13,    53,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    12,
      13,    53,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    12,    13,
      53,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    55,    37,     0,    16,    17,    18,    56,    57,
      75,    12,    58,    61,    78,    79,    58,    61,    76,    58,
      61,    77,    57,    38,    41,    43,    45,    64,    65,    46,
      40,    45,    65,    46,    45,    65,    46,    45,    16,    17,
      18,    39,    59,    60,    13,    12,    13,    15,    16,    17,
      18,    19,    20,    21,    23,    26,    28,    29,    38,    43,
      44,    53,    62,    63,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    80,    81,    12,
      79,    13,    15,    14,    61,    61,    61,    39,    40,    42,
       4,     3,    38,    38,    81,    26,    63,    74,    38,    81,
      62,    74,    90,    26,    44,    63,    26,    44,    62,    75,
      45,    10,     9,     7,     8,     5,     6,    47,    48,    49,
      50,    51,    52,    11,    46,    38,    60,    12,    12,    14,
      81,    45,    81,    45,    81,    29,    75,    81,    39,    62,
      81,    81,    26,    44,    84,    90,    85,    86,    86,    87,
      87,    87,    87,    89,    89,    90,    90,    82,    82,    39,
      81,    93,    45,    45,    45,    39,    45,    81,    45,    44,
      45,    38,    39,    45,    45,    81,    39,    40,    63,    39,
      81,    45,    45,    81,    81,    63,    44,    44,    45,    81,
      22,    63,    39,    39,    81,    39,    81,    45,    39,    44,
      63,    63,    63,    39,    63,    39,    39,    81,    45,    63,
      63,    63,    39,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    67,    68,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    81,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    86,    86,    86,    86,    86,    87,
      88,    88,    88,    89,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     1,     3,     3,     3,
       4,     3,     1,     3,     2,     2,     2,     1,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     2,     1,     1,     7,     6,     6,
       5,     3,     4,     4,     4,     2,     5,     7,     9,     8,
       8,     7,     8,     7,     7,     6,     7,     5,     1,     2,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     1,     3,     3,     1,     2,     1,     4,
       3,     1,     1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 40 "c++2python.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = NULL); }
#line 1573 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 41 "c++2python.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = (yyvsp[0].n)); }
#line 1579 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 45 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(EXTDEFS, (yyvsp[0].n), NULL); }
#line 1585 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 46 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(EXTDEFS, (yyvsp[0].n), NULL)); }
#line 1591 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1597 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(int_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1603 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(float_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1609 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(string_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1615 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 58 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-3].i), (yyvsp[-1].n)); }
#line 1621 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 59 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-2].i), NULL); }
#line 1627 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(PARAS, (yyvsp[0].n), NULL); }
#line 1633 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(PARAS, (yyvsp[0].n), NULL)); }
#line 1639 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 68 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(int_type(), (yyvsp[0].n)); }
#line 1645 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(float_type(), (yyvsp[0].n)); }
#line 1651 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(string_type(), (yyvsp[0].n)); }
#line 1657 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 74 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = var_new((yyvsp[0].i), 0); }
#line 1663 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = var_new((yyvsp[-3].i), (yyvsp[-1].i)); }
#line 1669 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(STMTS, (yyvsp[0].n), NULL); }
#line 1675 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(STMTS, (yyvsp[0].n), NULL)); }
#line 1681 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1687 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1693 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1699 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1705 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1711 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1717 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1723 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1729 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1735 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1741 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 97 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-2].n), (yyvsp[-1].n), NULL); }
#line 1747 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 98 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-1].n), NULL, NULL); }
#line 1753 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 99 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, (yyvsp[-1].n),  NULL); }
#line 1759 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 100 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL,  NULL); }
#line 1765 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 101 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL, NULL); }
#line 1771 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1777 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-5].n), (yyvsp[-4].n),  (yyvsp[-2].n)); }
#line 1783 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-4].n), NULL,  (yyvsp[-2].n)); }
#line 1789 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, (yyvsp[-4].n),  (yyvsp[-2].n)); }
#line 1795 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL,  (yyvsp[-2].n)); }
#line 1801 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 113 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = return_stmt_new((yyvsp[-1].n)); }
#line 1807 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = in_stmt_new((yyvsp[-1].i)); }
#line 1813 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = out_stmt_new((yyvsp[-1].i),NULL); }
#line 1819 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 122 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = out_stmt_new(0,(yyvsp[-1].s)); }
#line 1825 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 126 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = expr_stmt_new((yyvsp[-1].n)); }
#line 1831 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-2].n), (yyvsp[0].n), NULL); }
#line 1837 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-4].n), (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1843 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-6].n),   (yyvsp[-4].n),   (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1849 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-5].n),   (yyvsp[-3].n),   NULL, (yyvsp[0].n)); }
#line 1855 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-5].n),   NULL, (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1861 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-4].n),   NULL, NULL, (yyvsp[0].n)); }
#line 1867 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[-4].n),   (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1873 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 140 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[-3].n),   NULL, (yyvsp[0].n)); }
#line 1879 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 141 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, NULL, (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1885 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 142 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, NULL, NULL, (yyvsp[0].n)); }
#line 1891 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 146 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = do_stmt_new((yyvsp[-5].n),   (yyvsp[-2].n)); }
#line 1897 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = while_stmt_new((yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1903 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 154 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DEFS, (yyvsp[0].n), NULL); }
#line 1909 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 155 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(DEFS, (yyvsp[0].n), NULL)); }
#line 1915 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 159 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = def_new(int_type(), (yyvsp[-1].n)); }
#line 1921 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 160 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = def_f_new(float_type(), (yyvsp[-1].n)); }
#line 1927 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 161 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = def_s_new(string_type(), (yyvsp[-1].n)); }
#line 1933 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 165 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = real_new((yyvsp[0].n), 0); }
#line 1939 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 166 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = real_new((yyvsp[-2].n), (yyvsp[0].f)); }
#line 1945 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 167 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = real_new((yyvsp[-2].n), (yyvsp[0].i)); }
#line 1951 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 171 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = str_new((yyvsp[0].n), NULL); }
#line 1957 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 172 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = str_new((yyvsp[-2].n), (yyvsp[0].s)); }
#line 1963 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 177 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DECS, (yyvsp[0].n), NULL); }
#line 1969 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 178 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(DECS, (yyvsp[0].n), NULL)); }
#line 1975 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 182 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[0].n), NULL); }
#line 1981 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 183 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1987 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 187 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1993 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 191 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1999 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 195 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2005 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 196 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('=', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2011 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 197 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(ADD_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2017 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 201 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2023 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 202 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(OR_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2029 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 206 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2035 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 207 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(AND_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2041 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 211 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2047 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 212 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(EQ_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2053 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 213 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(NE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2059 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 217 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2065 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 218 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('>', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2071 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 219 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(GE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2077 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 220 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('<', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2083 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 221 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(LE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2089 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 225 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2095 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 229 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2101 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 230 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('+', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2107 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 231 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('-', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2113 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 235 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2119 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 236 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('*', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2125 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 237 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('/', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2131 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 241 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2137 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 242 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('!', (yyvsp[0].n)); }
#line 2143 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 246 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2149 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 247 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 2155 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 248 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-2].n), NULL); }
#line 2161 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 252 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = id_new((yyvsp[0].i)); }
#line 2167 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 253 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = const_new((yyvsp[0].i)); }
#line 2173 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 254 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = const_new((yyvsp[0].f)); }
#line 2179 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 255 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 2185 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 259 "c++2python.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(ARGS, (yyvsp[0].n), NULL); }
#line 2191 "c++2python.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 260 "c++2python.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(ARGS, (yyvsp[0].n), NULL)); }
#line 2197 "c++2python.tab.c" /* yacc.c:1646  */
    break;


#line 2201 "c++2python.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
