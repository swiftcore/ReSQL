
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "resql.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdarg.h>
  #include <string.h>
  #include "resql.h"
  #include "parser.h"
  


/* Line 189 of yacc.c  */
#line 84 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     STRING = 259,
     INTNUM = 260,
     BOOL = 261,
     APPROXNUM = 262,
     OR = 263,
     ANDOP = 264,
     REGEXP = 265,
     LIKE = 266,
     IS = 267,
     IN = 268,
     NOT = 269,
     BETWEEN = 270,
     COMPARISON = 271,
     MOD = 272,
     UMINUS = 273,
     ADD = 274,
     ALL = 275,
     AND = 276,
     AS = 277,
     ASC = 278,
     BY = 279,
     COLUMN = 280,
     CROSS = 281,
     DATE = 282,
     DATETIME = 283,
     DECIMAL = 284,
     DEFAULT = 285,
     DESC = 286,
     DISTINCT = 287,
     DISTINCTROW = 288,
     DIV = 289,
     EXISTS = 290,
     FLOAT = 291,
     FOR = 292,
     FROM = 293,
     GROUP = 294,
     HAVING = 295,
     INDEX = 296,
     INNER = 297,
     INT = 298,
     INTEGER = 299,
     JOIN = 300,
     KEY = 301,
     LEFT = 302,
     NATURAL = 303,
     NULLX = 304,
     NUMBER = 305,
     ON = 306,
     ORDER = 307,
     OUTER = 308,
     RIGHT = 309,
     SELECT = 310,
     STRAIGHT_JOIN = 311,
     TABLE = 312,
     TIME = 313,
     UNION = 314,
     UNIQUE = 315,
     USE = 316,
     USING = 317,
     VARCHAR = 318,
     WHERE = 319,
     FCOUNT = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 16 "resql.y"

     int intval;        /* the integer value */
     double floatval;   /* the float value */
     char *strval;      /* the string value */
     int subtok;        /* which kind of comparition and exists */
     struct ast* a;



/* Line 214 of yacc.c  */
#line 195 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    14,     2,     2,     2,    24,    19,     2,
      78,    79,    22,    20,    76,    21,    77,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    75,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    15,
      16,    17,    25,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    16,    26,    27,    30,
      31,    35,    38,    43,    44,    46,    48,    49,    52,    53,
      57,    59,    63,    64,    67,    70,    73,    76,    81,    83,
      85,    87,    91,    95,    99,   105,   109,   113,   115,   116,
     119,   121,   122,   128,   134,   139,   144,   151,   158,   164,
     170,   171,   173,   175,   176,   178,   180,   182,   185,   188,
     189,   191,   192,   195,   200,   207,   208,   211,   212,   214,
     218,   222,   224,   228,   230,   232,   234,   236,   240,   244,
     248,   252,   256,   260,   263,   267,   271,   275,   281,   284,
     287,   291,   296,   300,   305,   311,   313,   317,   318,   320,
     326,   333,   339,   346,   351,   356,   361,   366,   370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      81,     0,    -1,    82,    75,    -1,    81,    82,    75,    -1,
      83,    -1,    64,    91,    92,    -1,    64,    91,    92,    47,
      93,    84,    85,    88,    89,    -1,    -1,    73,   108,    -1,
      -1,    48,    33,    86,    -1,   108,    87,    -1,    86,    76,
     108,    87,    -1,    -1,    32,    -1,    40,    -1,    -1,    49,
     108,    -1,    -1,    61,    33,    86,    -1,     3,    -1,    90,
      76,     3,    -1,    -1,    91,    29,    -1,    91,    41,    -1,
      91,    42,    -1,   108,    96,    -1,    92,    76,   108,    96,
      -1,    22,    -1,    94,    -1,    97,    -1,    93,    76,    94,
      -1,    93,    76,    97,    -1,     3,    96,   104,    -1,     3,
      77,     3,    96,   104,    -1,   107,    95,     3,    -1,    78,
      93,    79,    -1,    31,    -1,    -1,    31,     3,    -1,     3,
      -1,    -1,    94,    98,    54,    94,   102,    -1,    97,    98,
      54,    94,   102,    -1,    94,    65,    94,   102,    -1,    97,
      65,    94,   102,    -1,    94,   100,    99,    54,    94,   103,
      -1,    97,   100,    99,    54,    94,   103,    -1,    94,    57,
     101,    54,    94,    -1,    97,    57,   101,    54,    94,    -1,
      -1,    51,    -1,    35,    -1,    -1,    62,    -1,    56,    -1,
      63,    -1,    56,    99,    -1,    63,    99,    -1,    -1,   103,
      -1,    -1,    60,   108,    -1,    71,    78,    90,    79,    -1,
      70,    55,   105,    78,   106,    79,    -1,    -1,    46,    54,
      -1,    -1,     3,    -1,   106,    76,     3,    -1,    78,    83,
      79,    -1,     3,    -1,     3,    77,     3,    -1,     4,    -1,
       5,    -1,     7,    -1,     6,    -1,   108,    20,   108,    -1,
     108,    21,   108,    -1,   108,    22,   108,    -1,   108,    23,
     108,    -1,   108,    24,   108,    -1,   108,    25,   108,    -1,
      21,   108,    -1,   108,     9,   108,    -1,   108,     8,   108,
      -1,   108,    17,   108,    -1,   108,    17,    78,    83,    79,
      -1,    15,   108,    -1,    14,   108,    -1,   108,    12,    58,
      -1,   108,    12,    15,    58,    -1,   108,    12,     6,    -1,
     108,    12,    15,     6,    -1,   108,    16,   108,    30,   108,
      -1,   108,    -1,   108,    76,   109,    -1,    -1,   109,    -1,
     108,    13,    78,   109,    79,    -1,   108,    15,    13,    78,
     109,    79,    -1,   108,    13,    78,    83,    79,    -1,   108,
      15,    13,    78,    83,    79,    -1,    44,    78,    83,    79,
      -1,     3,    78,   110,    79,    -1,    74,    78,    22,    79,
      -1,    74,    78,   108,    79,    -1,   108,    11,   108,    -1,
     108,    15,    11,   108,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   118,   123,   126,   128,   133,   134,   137,
     138,   142,   144,   148,   149,   150,   153,   154,   157,   158,
     161,   162,   165,   166,   167,   168,   171,   172,   173,   176,
     177,   178,   179,   183,   184,   185,   186,   189,   190,   193,
     194,   195,   199,   201,   203,   205,   207,   209,   211,   213,
     217,   218,   219,   222,   223,   226,   227,   230,   231,   232,
     235,   236,   240,   241,   245,   247,   250,   251,   254,   255,
     258,   263,   264,   265,   266,   267,   268,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     286,   287,   288,   289,   292,   296,   297,   300,   301,   304,
     305,   306,   307,   308,   314,   320,   321,   324,   325
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "OR", "ANDOP", "REGEXP", "LIKE", "IS", "IN", "'!'", "NOT",
  "BETWEEN", "COMPARISON", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "MOD", "'^'", "UMINUS", "ADD", "ALL", "AND", "AS", "ASC", "BY", "COLUMN",
  "CROSS", "DATE", "DATETIME", "DECIMAL", "DEFAULT", "DESC", "DISTINCT",
  "DISTINCTROW", "DIV", "EXISTS", "FLOAT", "FOR", "FROM", "GROUP",
  "HAVING", "INDEX", "INNER", "INT", "INTEGER", "JOIN", "KEY", "LEFT",
  "NATURAL", "NULLX", "NUMBER", "ON", "ORDER", "OUTER", "RIGHT", "SELECT",
  "STRAIGHT_JOIN", "TABLE", "TIME", "UNION", "UNIQUE", "USE", "USING",
  "VARCHAR", "WHERE", "FCOUNT", "';'", "','", "'.'", "'('", "')'",
  "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "opt_groupby", "groupby_list", "opt_asc_desc", "opt_having",
  "opt_orderby", "column_list", "select_opts", "select_expr_list",
  "table_references", "table_factor", "opt_as", "opt_as_alias",
  "join_table", "opt_inner_cross", "opt_outer", "left_or_right",
  "opt_left_or_right_outer", "opt_join_condition", "join_condition",
  "index_hint", "opt_for_join", "index_list", "table_subquery", "expr",
  "val_list", "opt_val_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    33,   269,   270,   271,   124,    38,
      43,    45,    42,    47,    37,   272,    94,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,    59,    44,    46,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     3,     9,     0,     2,     0,
       3,     2,     4,     0,     1,     1,     0,     2,     0,     3,
       1,     3,     0,     2,     2,     2,     2,     4,     1,     1,
       1,     3,     3,     3,     5,     3,     3,     1,     0,     2,
       1,     0,     5,     5,     4,     4,     6,     6,     5,     5,
       0,     1,     1,     0,     1,     1,     1,     2,     2,     0,
       1,     0,     2,     4,     6,     0,     2,     0,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     5,     2,     2,
       3,     4,     3,     4,     5,     1,     3,     0,     1,     5,
       6,     5,     6,     4,     4,     4,     4,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,     0,     0,     4,     0,     1,     0,     2,    71,
      73,    74,    76,    75,     0,     0,     0,    28,    23,    24,
      25,     0,     0,     5,    41,     3,     0,    97,    89,    88,
      83,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    72,    95,    98,     0,     0,     0,     0,    41,
       0,     7,    29,    30,    38,    41,    85,    84,   107,    92,
       0,    90,     0,     0,     0,     0,     0,    86,    77,    78,
      79,    80,    81,    82,    39,     0,   104,   103,   105,   106,
       0,    65,     0,     0,     0,     0,     9,    52,    51,    55,
      59,    56,     0,     0,    53,    59,     0,     0,    53,    37,
       0,    27,    93,    91,     0,     0,   108,     0,     0,     0,
      96,    41,     0,    33,    70,    36,     8,    31,    32,     0,
      16,    53,    53,     0,    61,     0,    54,     0,     0,    61,
       0,     0,    35,   101,    99,     0,     0,    94,    87,    65,
      67,     0,     0,    18,    57,    58,     0,     0,     0,    44,
      60,    61,     0,     0,    45,    61,     0,   102,   100,    34,
       0,     0,    10,    13,    17,     0,     6,    48,    62,     0,
      42,     0,    49,    43,     0,    66,     0,     0,    14,    15,
      11,     0,    20,     0,    46,    47,    68,     0,    13,    19,
       0,    63,     0,    64,    12,    21,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    96,   130,   172,   190,   153,   176,
     193,     5,    23,    61,    62,   110,    51,    63,   103,   137,
     104,   133,   159,   160,   123,   171,   197,    64,    53,    54,
      55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
     -42,  -115,     3,   -47,  -115,   113,  -115,   -21,  -115,   -12,
    -115,  -115,  -115,  -115,   190,   190,   190,  -115,  -115,  -115,
    -115,    16,    20,   -28,   284,  -115,    33,   190,   382,   382,
    -115,   -42,   118,    -1,   190,  -115,   190,   190,   190,     2,
      24,    73,   190,     9,   190,   190,   190,   190,   190,   190,
      58,  -115,  -115,   207,  -115,    32,    47,    51,    84,     4,
      -2,   -17,   221,   225,    49,   284,   342,   357,   372,  -115,
      12,  -115,   162,   190,    53,   305,   -42,   178,    50,    50,
    -115,  -115,  -115,  -115,  -115,   190,  -115,  -115,  -115,  -115,
     126,    66,    65,    36,   190,    -1,    89,  -115,  -115,  -115,
       1,  -115,    -1,    91,    87,     1,    -1,    97,    87,  -115,
     153,  -115,  -115,  -115,    79,    80,   372,   162,   190,    81,
    -115,    18,   106,  -115,  -115,  -115,   325,   221,   225,   139,
     124,    87,    87,   121,    -8,    -1,  -115,   125,   127,    -8,
      -1,   130,  -115,  -115,  -115,    99,   101,   391,  -115,    66,
     142,   190,   190,   128,  -115,  -115,    -1,   190,   107,  -115,
    -115,    -8,    -1,    -1,  -115,    -8,    -1,  -115,  -115,  -115,
     136,   129,   115,   229,   325,   175,  -115,  -115,   325,   206,
    -115,    -8,  -115,  -115,    -8,  -115,   209,   190,  -115,  -115,
    -115,   190,  -115,    62,  -115,  -115,  -115,    74,   229,   115,
     210,  -115,   211,  -115,  -115,  -115,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   208,   -26,  -115,  -115,    26,    23,  -115,  -115,
    -115,  -115,  -115,   165,     8,  -115,   -39,   138,   -59,   -53,
     -57,   134,  -114,   -96,    86,  -115,  -115,  -115,    -5,   -27,
    -115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      24,    59,    59,     6,   107,    56,   108,    35,    69,    28,
      29,    30,     9,    10,    11,    12,    13,    70,   112,    33,
      91,    35,     1,    14,    15,   164,   111,    58,     8,    65,
      16,    66,    67,    68,    92,    50,    52,    75,    77,    78,
      79,    80,    81,    82,    83,   115,   114,   180,    34,    50,
     119,   183,   157,    21,    25,   141,    94,   131,   120,    95,
      71,    84,     1,   158,   132,    26,    27,     1,   116,   107,
     113,   108,    46,    47,    48,    49,    60,    60,   154,   155,
     109,    90,   149,    22,    73,   194,    74,    76,   195,   126,
     146,   145,    36,    37,    31,    38,    39,    40,    32,    41,
      42,    43,    72,   127,    44,    45,    46,    47,    48,    49,
     134,    86,    95,   147,   139,   125,     9,    10,    11,    12,
      13,     9,    10,    11,    12,    13,    87,    14,    15,   121,
      88,   117,    14,    15,    16,    17,   122,   129,   200,    16,
      57,   201,    18,   161,   124,   135,   173,   174,   165,   136,
     202,   140,   178,   203,    19,    20,   142,    21,   143,   144,
     148,   150,    21,    89,   177,     9,    10,    11,    12,    13,
     181,   182,   151,   152,   184,   156,    14,    15,   167,   162,
     168,   163,   198,    16,   166,   179,   173,    22,   170,   175,
     185,   187,    22,     9,    10,    11,    12,    13,    44,    45,
      46,    47,    48,    49,    14,    15,    21,   186,   191,   192,
       7,    16,   196,   205,   206,    36,    37,   199,    38,    39,
      40,   204,    41,    42,    43,    93,     1,    44,    45,    46,
      47,    48,    49,   128,    21,   169,    22,    36,    37,   138,
      38,    39,    40,     0,    41,    42,    43,     0,     0,    44,
      45,    46,    47,    48,    49,     0,    97,     0,     0,     0,
      97,   188,     0,     0,    22,     0,     0,     0,     0,   189,
       0,     0,    98,     0,     0,   -50,    98,    99,   100,   -50,
       0,    99,   105,    85,   101,     0,   102,    35,   101,     0,
     106,     0,    36,    37,     0,    38,    39,    40,     0,    41,
      42,    43,     0,     0,    44,    45,    46,    47,    48,    49,
       0,     0,     0,    36,    37,    50,    38,    39,    40,     0,
      41,    42,    43,     0,     0,    44,    45,    46,    47,    48,
      49,     0,     0,    36,    37,   118,    38,    39,    40,     0,
      41,    42,    43,     0,     0,    44,    45,    46,    47,    48,
      49,    37,     0,    38,    39,    40,     0,    41,    42,    43,
       0,     0,    44,    45,    46,    47,    48,    49,    38,    39,
      40,     0,    41,    42,    43,     0,     0,    44,    45,    46,
      47,    48,    49,   -51,   -51,   -51,     0,    41,    42,    43,
       0,     0,    44,    45,    46,    47,    48,    49,    42,    43,
       0,     0,    44,    45,    46,    47,    48,    49,    43,     0,
       0,    44,    45,    46,    47,    48,    49
};

static const yytype_int16 yycheck[] =
{
       5,     3,     3,     0,    63,    31,    63,     3,     6,    14,
      15,    16,     3,     4,     5,     6,     7,    15,     6,    47,
      59,     3,    64,    14,    15,   139,    65,    32,    75,    34,
      21,    36,    37,    38,    60,    31,     3,    42,    43,    44,
      45,    46,    47,    48,    49,    72,    72,   161,    76,    31,
      76,   165,    60,    44,    75,   108,    73,    56,    85,    76,
      58,     3,    64,    71,    63,    77,    78,    64,    73,   128,
      58,   128,    22,    23,    24,    25,    78,    78,   131,   132,
      31,    77,   121,    74,    11,   181,    13,    78,   184,    94,
     117,   117,     8,     9,    78,    11,    12,    13,    78,    15,
      16,    17,    78,    95,    20,    21,    22,    23,    24,    25,
     102,    79,    76,   118,   106,    79,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    79,    14,    15,     3,
      79,    78,    14,    15,    21,    22,    70,    48,    76,    21,
      22,    79,    29,   135,    79,    54,   151,   152,   140,    62,
      76,    54,   157,    79,    41,    42,     3,    44,    79,    79,
      79,    55,    44,    79,   156,     3,     4,     5,     6,     7,
     162,   163,    33,    49,   166,    54,    14,    15,    79,    54,
      79,    54,   187,    21,    54,    78,   191,    74,    46,    61,
      54,    76,    74,     3,     4,     5,     6,     7,    20,    21,
      22,    23,    24,    25,    14,    15,    44,    78,    33,     3,
       2,    21,     3,     3,     3,     8,     9,   191,    11,    12,
      13,   198,    15,    16,    17,    60,    64,    20,    21,    22,
      23,    24,    25,    95,    44,   149,    74,     8,     9,   105,
      11,    12,    13,    -1,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    35,    -1,    -1,    -1,
      35,    32,    -1,    -1,    74,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    51,    -1,    -1,    54,    51,    56,    57,    54,
      -1,    56,    57,    76,    63,    -1,    65,     3,    63,    -1,
      65,    -1,     8,     9,    -1,    11,    12,    13,    -1,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,     8,     9,    31,    11,    12,    13,    -1,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,     8,     9,    30,    11,    12,    13,    -1,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,     9,    -1,    11,    12,    13,    -1,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,    11,    12,
      13,    -1,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    11,    12,    13,    -1,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,    17,    -1,
      -1,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    81,    82,    83,    91,     0,    82,    75,     3,
       4,     5,     6,     7,    14,    15,    21,    22,    29,    41,
      42,    44,    74,    92,   108,    75,    77,    78,   108,   108,
     108,    78,    78,    47,    76,     3,     8,     9,    11,    12,
      13,    15,    16,    17,    20,    21,    22,    23,    24,    25,
      31,    96,     3,   108,   109,   110,    83,    22,   108,     3,
      78,    93,    94,    97,   107,   108,   108,   108,   108,     6,
      15,    58,    78,    11,    13,   108,    78,   108,   108,   108,
     108,   108,   108,   108,     3,    76,    79,    79,    79,    79,
      77,    96,    83,    93,    73,    76,    84,    35,    51,    56,
      57,    63,    65,    98,   100,    57,    65,    98,   100,    31,
      95,    96,     6,    58,    83,   109,   108,    78,    30,    83,
     109,     3,    70,   104,    79,    79,   108,    94,    97,    48,
      85,    56,    63,   101,    94,    54,    62,    99,   101,    94,
      54,    99,     3,    79,    79,    83,   109,   108,    79,    96,
      55,    33,    49,    88,    99,    99,    54,    60,    71,   102,
     103,    94,    54,    54,   102,    94,    54,    79,    79,   104,
      46,   105,    86,   108,   108,    61,    89,    94,   108,    78,
     102,    94,    94,   102,    94,    54,    78,    76,    32,    40,
      87,    33,     3,    90,   103,   103,     3,   106,   108,    86,
      76,    79,    76,    79,    87,     3,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 123 "resql.y"
    { if(rewrite_kind) on_rewrite_aggr((yyvsp[(1) - (1)].a)); else on_rewrite_join((yyvsp[(1) - (1)].a)); emit_expr((yyvsp[(1) - (1)].a)); printf(";\n"); free_ast((yyvsp[(1) - (1)].a)); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 127 "resql.y"
    { (yyval.a) = newselect_stmt((yyvsp[(2) - (3)].intval),(yyvsp[(3) - (3)].a),NULL,NULL,NULL,NULL,NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 130 "resql.y"
    {(yyval.a) = newselect_stmt((yyvsp[(2) - (9)].intval),(yyvsp[(3) - (9)].a),(yyvsp[(5) - (9)].a),(yyvsp[(6) - (9)].a),(yyvsp[(7) - (9)].a),(yyvsp[(8) - (9)].a),(yyvsp[(9) - (9)].a)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 133 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 134 "resql.y"
    { (yyval.a) = (yyvsp[(2) - (2)].a); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 137 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 139 "resql.y"
    { (yyval.a) = (yyvsp[(3) - (3)].a); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 143 "resql.y"
    { (yyval.a) = newgroupby_list((yyvsp[(2) - (2)].intval),(yyvsp[(1) - (2)].a),NULL); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 145 "resql.y"
    { (yyval.a) = newgroupby_list((yyvsp[(4) - (4)].intval),(yyvsp[(3) - (4)].a),(yyvsp[(1) - (4)].a)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 148 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 149 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 150 "resql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 154 "resql.y"
    { (yyval.a) = (yyvsp[(2) - (2)].a); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 157 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 158 "resql.y"
    { (yyval.a) = (yyvsp[(3) - (3)].a); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 161 "resql.y"
    { (yyval.a) = newast('v',newsymref(newsymbol((yyvsp[(1) - (1)].strval))),NULL,NULL); free((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 162 "resql.y"
    { (yyval.a) = newast('v',newsymref(newsymbol((yyvsp[(3) - (3)].strval))),(yyvsp[(1) - (3)].a),NULL); free((yyvsp[(3) - (3)].strval)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 165 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 166 "resql.y"
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 01; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 167 "resql.y"
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 02; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 168 "resql.y"
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 04; ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 171 "resql.y"
    { (yyval.a) = newselect_expr_list((yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a),NULL); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 172 "resql.y"
    { (yyval.a) = newselect_expr_list((yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a),(yyvsp[(1) - (4)].a)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 173 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 176 "resql.y"
    { (yyval.a) = newtable_references(1,(yyvsp[(1) - (1)].a),NULL); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 177 "resql.y"
    { (yyval.a) = newtable_references(2,(yyvsp[(1) - (1)].a),NULL); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 178 "resql.y"
    { (yyval.a) = newtable_references(1,(yyvsp[(3) - (3)].a),(yyvsp[(1) - (3)].a)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 179 "resql.y"
    { (yyval.a) = newtable_references(2,(yyvsp[(3) - (3)].a),(yyvsp[(1) - (3)].a)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 183 "resql.y"
    { (yyval.a) = newtable_factor(1,newsymref(newsymbol((yyvsp[(1) - (3)].strval))),(yyvsp[(2) - (3)].a),NULL,(yyvsp[(3) - (3)].a));free((yyvsp[(1) - (3)].strval)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 184 "resql.y"
    { (yyval.a) = newtable_factor(2,newsymref(newsymbol((yyvsp[(1) - (5)].strval))),newsymref(newsymbol((yyvsp[(3) - (5)].strval))),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a)); free((yyvsp[(1) - (5)].strval)); free((yyvsp[(3) - (5)].strval)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 185 "resql.y"
    { (yyval.a) = newtable_factor(3,newsymref(newsymbol((yyvsp[(3) - (3)].strval))),NULL,NULL,(yyvsp[(1) - (3)].a)); free((yyvsp[(3) - (3)].strval));  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 186 "resql.y"
    { (yyval.a) = newtable_factor(4,NULL,NULL,NULL,(yyvsp[(2) - (3)].a)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 193 "resql.y"
    { (yyval.a) = newsymref(newsymbol((yyvsp[(2) - (2)].strval))); free((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 194 "resql.y"
    { (yyval.a) = newsymref(newsymbol((yyvsp[(1) - (1)].strval))); free((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 195 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 200 "resql.y"
    { (yyval.a) = newjoin_table(0100+(yyvsp[(2) - (5)].intval),(yyvsp[(1) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 202 "resql.y"
    { (yyval.a) = newjoin_table(0100+(yyvsp[(2) - (5)].intval),(yyvsp[(1) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 204 "resql.y"
    { (yyval.a) = newjoin_table(0200,(yyvsp[(1) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 206 "resql.y"
    { (yyval.a) = newjoin_table(0200,(yyvsp[(1) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 208 "resql.y"
    { (yyval.a) = newjoin_table(0300+(yyvsp[(2) - (6)].intval)+(yyvsp[(3) - (6)].intval),(yyvsp[(1) - (6)].a),(yyvsp[(5) - (6)].a),(yyvsp[(6) - (6)].a)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 210 "resql.y"
    { (yyval.a) = newjoin_table(0300+(yyvsp[(2) - (6)].intval)+(yyvsp[(3) - (6)].intval),(yyvsp[(1) - (6)].a),(yyvsp[(5) - (6)].a),(yyvsp[(6) - (6)].a)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 212 "resql.y"
    { (yyval.a) = newjoin_table(0400+(yyvsp[(3) - (5)].intval),(yyvsp[(1) - (5)].a),(yyvsp[(5) - (5)].a),NULL); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 214 "resql.y"
    { (yyval.a) = newjoin_table(0400+(yyvsp[(3) - (5)].intval),(yyvsp[(1) - (5)].a),(yyvsp[(5) - (5)].a),NULL); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 217 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 218 "resql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 219 "resql.y"
    { (yyval.intval) = 2; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 222 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 223 "resql.y"
    {(yyval.intval) = 4; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 226 "resql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 227 "resql.y"
    { (yyval.intval) = 2; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 230 "resql.y"
    { (yyval.intval) = 1 + (yyvsp[(2) - (2)].intval); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 231 "resql.y"
    { (yyval.intval) = 2 + (yyvsp[(2) - (2)].intval); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 232 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 235 "resql.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 236 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 240 "resql.y"
    { (yyval.a) = newjoin_condition(1,(yyvsp[(2) - (2)].a)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 241 "resql.y"
    { (yyval.a) = newjoin_condition(2,(yyvsp[(3) - (4)].a)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 246 "resql.y"
    { (yyval.a) = (yyvsp[(5) - (6)].a); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 247 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 250 "resql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 251 "resql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 254 "resql.y"
    { (yyval.a) = newindex_list(newsymref(newsymbol((yyvsp[(1) - (1)].strval))),NULL); free((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 255 "resql.y"
    { (yyval.a) = newindex_list(newsymref(newsymbol((yyvsp[(3) - (3)].strval))),(yyvsp[(1) - (3)].a)); free((yyvsp[(3) - (3)].strval)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 258 "resql.y"
    { (yyval.a) = (yyvsp[(2) - (3)].a); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 263 "resql.y"
    { (yyval.a) = newsymref(newsymbol((yyvsp[(1) - (1)].strval))); free((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 264 "resql.y"
    { (yyval.a) = newast('D',newsymref(newsymbol((yyvsp[(1) - (3)].strval))),newsymref(newsymbol((yyvsp[(3) - (3)].strval))),NULL); free((yyvsp[(1) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 265 "resql.y"
    { (yyval.a) = newstring((yyvsp[(1) - (1)].strval)); free((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 266 "resql.y"
    { (yyval.a) = newint((yyvsp[(1) - (1)].intval)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 267 "resql.y"
    { (yyval.a) = newfloat((yyvsp[(1) - (1)].floatval)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 268 "resql.y"
    { (yyval.a) = newint(0); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 271 "resql.y"
    { (yyval.a) = newast('+',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 272 "resql.y"
    { (yyval.a) = newast('-',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 273 "resql.y"
    { (yyval.a) = newast('*',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 274 "resql.y"
    { (yyval.a) = newast('/',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 275 "resql.y"
    { (yyval.a) = newast('%',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 276 "resql.y"
    { (yyval.a) = newast('%',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 277 "resql.y"
    { (yyval.a) = newast('M',(yyvsp[(2) - (2)].a),NULL,NULL); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 278 "resql.y"
    { (yyval.a) = newast('A',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 279 "resql.y"
    { (yyval.a) = newast('O',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 280 "resql.y"
    { (yyval.a) = newcmp((yyvsp[(2) - (3)].subtok),(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 281 "resql.y"
    { (yyval.a) = newcmp((yyvsp[(2) - (5)].subtok),(yyvsp[(1) - (5)].a),(yyvsp[(4) - (5)].a)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 282 "resql.y"
    { (yyval.a) = newast('T',(yyvsp[(2) - (2)].a),NULL,NULL); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 283 "resql.y"
    { (yyval.a) = newast('T',(yyvsp[(2) - (2)].a),NULL,NULL); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 286 "resql.y"
    { (yyval.a) = newast('U',(yyvsp[(1) - (3)].a),NULL,NULL); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 287 "resql.y"
    { (yyval.a) = newast('T',newast('U',(yyvsp[(1) - (4)].a),NULL,NULL),NULL,NULL); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 288 "resql.y"
    { (yyval.a) = newast('B',(yyvsp[(1) - (3)].a),NULL,NULL); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 289 "resql.y"
    { (yyval.a) = newast('T',newast('B',(yyvsp[(1) - (4)].a),NULL,NULL),NULL,NULL); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 292 "resql.y"
    { (yyval.a) = newast('W',(yyvsp[(1) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 296 "resql.y"
    { (yyval.a) = newast('v',(yyvsp[(1) - (1)].a),NULL,NULL); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 297 "resql.y"
    { (yyval.a) = newast('v',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 300 "resql.y"
    { (yyval.a) = NULL; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 301 "resql.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 304 "resql.y"
    { (yyval.a) = newast('Q',(yyvsp[(1) - (5)].a),(yyvsp[(4) - (5)].a),NULL); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 305 "resql.y"
    { (yyval.a) = newast('T',newast('Q',(yyvsp[(1) - (6)].a),(yyvsp[(5) - (6)].a),NULL),NULL,NULL); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 306 "resql.y"
    { (yyval.a) = newast('Q',(yyvsp[(1) - (5)].a),(yyvsp[(4) - (5)].a),NULL); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 307 "resql.y"
    { (yyval.a) = newast('T',newast('Q',(yyvsp[(1) - (6)].a),(yyvsp[(5) - (6)].a),NULL),NULL,NULL); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 308 "resql.y"
    { if((yyvsp[(1) - (4)].subtok))
	                                  (yyval.a) = newast('T',newast('E',(yyvsp[(3) - (4)].a),NULL,NULL),NULL,NULL);
	                               else
	                                  (yyval.a) = newast('E',(yyvsp[(3) - (4)].a),NULL,NULL);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 314 "resql.y"
    {  (yyval.a) = newcall(newsymref(newsymbol((yyvsp[(1) - (4)].strval))),(yyvsp[(3) - (4)].a));
	                            rewrite_kind=1;
				    free((yyvsp[(1) - (4)].strval)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 320 "resql.y"
    { (yyval.a) = newfunc(NULL); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 321 "resql.y"
    { (yyval.a) = newfunc((yyvsp[(3) - (4)].a));  ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 324 "resql.y"
    { (yyval.a) = newast('K',(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a),NULL); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 325 "resql.y"
    { (yyval.a) = newast('T',newast('K',(yyvsp[(1) - (4)].a),(yyvsp[(4) - (4)].a),NULL),NULL,NULL); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2365 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 328 "resql.y"



void sparse(int ac, char **av)
{
  extern FILE *yyin;

  if(ac > 1 && !strcmp(av[1], "-d")) {
    ac--; av++;
  }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }

  yyparse();
  /*
  if(!yyparse())
    printf("SQL parse worked\n");
  else
    printf("SQL parse failed\n");
  */
}

