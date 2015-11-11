/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "mwrap.y"

/*
 * mwrap.y
 *   Parser for mwrap.
 *
 * Copyright (c) 2007  David Bindel
 * See the file COPYING for copying permissions
 */

#include <stdlib.h>
#include <string.h>
#include <string>
#include "mwrap-ast.h"

extern "C" {
    int yylex();
    int yywrap();
    int yyerror(const char* s);
}

using std::string;

bool  mw_generate_catch = false;  // Catch C++ exceptions?
bool  mw_use_cpp_complex = false; // Use C++ complex types?
bool  mw_use_c99_complex = false; // Use C99 complex types?
bool  mw_promote_int = false;     // Convert integer types to mwSize?
int   listing_flag = 0;           // Output filenames from @ commands?
int   mbatching_flag = 0;         // Output on @ commands?
int   linenum = 0;                // Lexer line number
FILE* outfp   = 0;                // MATLAB output file
FILE* outcfp  = 0;                // C output file

static int    type_errs = 0;            // Number of typecheck errors
static int    func_id = 0;              // Assign stub numbers
static Func*  funcs   = 0;              // AST - linked list of functions
static Func*  lastfunc = 0;             // Last link in funcs list
static const char*  mexfunc = "mexfunction";  // Name of mex function
static string current_ifname;           // Current input file name


#define MAX_INCLUDE_DEPTH 10
static string include_stack_names[MAX_INCLUDE_DEPTH];
extern int include_stack_ptr;

extern "C" void set_include_name(const char* s)
{
    include_stack_names[include_stack_ptr] = current_ifname;
    current_ifname = s;
}

extern "C" void get_include_name()
{
    current_ifname = include_stack_names[include_stack_ptr].c_str();
}


inline void add_func(Func* func)
{
    static std::map<string,Func*> func_lookup;
    if (!funcs) {
        funcs = func;
        lastfunc = func;
        return;
    } 

    Func*& func_ptr = func_lookup[id_string(func)];
    if (func_ptr) {
        func_ptr->same_next = func;
    } else {
        lastfunc->next = func;
        lastfunc = func;
    }
    func_ptr = func;
}



/* Line 268 of yacc.c  */
#line 149 "mwrap.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     NON_C_LINE = 258,
     NEW = 259,
     TYPEDEF = 260,
     CLASS = 261,
     FORTRAN = 262,
     ID = 263,
     NUMBER = 264,
     STRING = 265,
     INPUT = 266,
     OUTPUT = 267,
     INOUT = 268
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 78 "mwrap.y"

    char* string;
    struct Func* func;
    struct Var* var;
    struct TypeQual* qual;
    struct Expr* expr;
    struct InheritsDecl* inherits;
    char c;



/* Line 293 of yacc.c  */
#line 210 "mwrap.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 222 "mwrap.cc"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   75

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   268

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    21,     2,
      18,    19,    20,     2,    17,    24,    26,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,    15,
       2,    14,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    11,    13,    15,    17,    19,
      22,    27,    33,    36,    40,    41,    47,    50,    51,    55,
      56,    59,    63,    67,    71,    76,    81,    85,    90,    94,
      99,   101,   103,   105,   106,   108,   110,   112,   114,   117,
     121,   124,   125,   129,   130,   132,   134,   141,   143,   146
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      28,     0,    -1,    29,    28,    -1,    -1,    37,    14,    34,
      -1,    34,    -1,    30,    -1,    31,    -1,     3,    -1,     1,
      15,    -1,     5,     8,     8,    15,    -1,     6,     8,    16,
      32,    15,    -1,     8,    33,    -1,    17,     8,    33,    -1,
      -1,    46,    18,    35,    19,    15,    -1,    38,    36,    -1,
      -1,    17,    38,    36,    -1,    -1,     8,     8,    -1,     8,
      40,     8,    -1,     8,     8,    41,    -1,    39,     8,     8,
      -1,    39,     8,    40,     8,    -1,    39,     8,     8,    41,
      -1,    39,     8,     9,    -1,    39,     8,    40,     9,    -1,
      39,     8,    10,    -1,    39,     8,    40,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,    -1,    20,    -1,    21,    -1,
      41,    -1,    42,    -1,    42,    21,    -1,    22,    43,    23,
      -1,    45,    44,    -1,    -1,    17,    45,    44,    -1,    -1,
       8,    -1,     9,    -1,     8,    24,    25,     8,    26,     8,
      -1,     8,    -1,     7,     8,    -1,     4,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   104,   104,   104,   107,   115,   122,   123,   124,   125,
     128,   146,   153,   156,   157,   159,   162,   163,   166,   167,
     169,   170,   171,   173,   174,   175,   177,   178,   180,   181,
     184,   185,   186,   187,   190,   191,   192,   195,   196,   198,
     201,   202,   205,   206,   209,   210,   213,   214,   215,   218
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NON_C_LINE", "NEW", "TYPEDEF", "CLASS",
  "FORTRAN", "ID", "NUMBER", "STRING", "INPUT", "OUTPUT", "INOUT", "'='",
  "';'", "':'", "','", "'('", "')'", "'*'", "'&'", "'['", "']'", "'-'",
  "'>'", "'.'", "$accept", "statements", "statement", "tdef", "classdef",
  "inheritslist", "inheritsrest", "funcall", "args", "argsrest", "basevar",
  "var", "iospec", "quals", "aqual", "arrayspec", "exprs", "exprrest",
  "expr", "func", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    61,    59,    58,    44,    40,    41,
      42,    38,    91,    93,    45,    62,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    28,    29,    29,    29,    29,    29,    29,
      30,    31,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    40,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     1,     1,     1,     2,
       4,     5,     2,     3,     0,     5,     2,     0,     3,     0,
       2,     3,     3,     3,     4,     4,     3,     4,     3,     4,
       1,     1,     1,     0,     1,     1,     1,     1,     2,     3,
       2,     0,     3,     0,     1,     1,     6,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,     0,    47,     0,     0,
       6,     7,     5,     0,     0,     9,    49,     0,     0,    48,
      20,    34,    35,    41,     0,     0,    36,    37,     1,     2,
       0,    17,     0,     0,    22,    44,    45,     0,    43,     0,
      21,    38,    47,     4,    30,    31,    32,     0,    19,     0,
      10,    14,     0,    39,     0,    40,     0,     0,    33,    16,
       0,     0,    12,    11,    43,     0,    15,    19,    23,    26,
      28,     0,    14,    42,    46,    18,    25,    24,    27,    29,
      13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    52,    62,    12,    47,    59,
      13,    48,    49,    25,    26,    27,    37,    55,    38,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -21
static const yytype_int8 yypact[] =
{
      21,   -10,   -21,     4,     8,    15,    29,    -7,    38,    21,
     -21,   -21,   -21,    27,    24,   -21,   -21,    35,    28,   -21,
      25,   -21,   -21,    23,    20,    41,   -21,    30,   -21,   -21,
      32,    22,    31,    42,   -21,   -21,   -21,    33,    36,    44,
     -21,   -21,    34,   -21,   -21,   -21,   -21,    40,    37,    47,
     -21,    43,    46,   -21,    23,   -21,    39,    48,    -9,   -21,
      -2,    49,   -21,   -21,    36,    54,   -21,    37,    25,   -21,
     -21,     1,    43,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,    55,   -21,   -21,   -21,   -21,    -6,    45,   -21,     0,
     -21,    10,   -21,     9,   -20,   -21,   -21,     6,    17,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -34
static const yytype_int8 yytable[] =
{
      34,    20,    44,    45,    46,    15,    68,    69,    70,    77,
      78,    79,    16,    21,    22,    23,    17,    24,    21,    22,
      23,    -3,     1,    18,     2,     3,     4,     5,     6,     7,
     -33,    35,    36,    44,    45,    46,     3,    19,    28,     6,
      42,    30,    31,    32,    33,    39,    50,    23,    76,    40,
      51,    41,    56,    54,    58,    60,    53,    72,    24,    57,
      61,    63,    74,    66,    29,    65,    80,    75,    67,    71,
      73,    64,     0,     0,     0,    43
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-21))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      20,     8,    11,    12,    13,    15,     8,     9,    10,     8,
       9,    10,     8,    20,    21,    22,     8,    24,    20,    21,
      22,     0,     1,     8,     3,     4,     5,     6,     7,     8,
       8,     8,     9,    11,    12,    13,     4,     8,     0,     7,
       8,    14,    18,     8,    16,    25,    15,    22,    68,     8,
       8,    21,     8,    17,    17,     8,    23,     8,    24,    19,
      17,    15,     8,    15,     9,    26,    72,    67,    58,    60,
      64,    54,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    28,    29,
      30,    31,    34,    37,    46,    15,     8,     8,     8,     8,
       8,    20,    21,    22,    24,    40,    41,    42,     0,    28,
      14,    18,     8,    16,    41,     8,     9,    43,    45,    25,
       8,    21,     8,    34,    11,    12,    13,    35,    38,    39,
      15,     8,    32,    23,    17,    44,     8,    19,    17,    36,
       8,    17,    33,    15,    45,    26,    15,    38,     8,     9,
      10,    40,     8,    44,     8,    36,    41,     8,     9,    10,
      33
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 107 "mwrap.y"
    { 
      (yyvsp[(3) - (3)].func)->ret = (yyvsp[(1) - (3)].var); 
      (yyvsp[(3) - (3)].func)->id = ++func_id;
      type_errs += typecheck((yyvsp[(3) - (3)].func), linenum);
      if (outfp)
          print_matlab_call(outfp, (yyvsp[(3) - (3)].func), mexfunc); 
      add_func((yyvsp[(3) - (3)].func));
  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 115 "mwrap.y"
    { 
      (yyvsp[(1) - (1)].func)->id = ++func_id;
      type_errs += typecheck((yyvsp[(1) - (1)].func), linenum);
      if (outfp)
          print_matlab_call(outfp, (yyvsp[(1) - (1)].func), mexfunc); 
      add_func((yyvsp[(1) - (1)].func));
  }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 125 "mwrap.y"
    { yyerrok; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 128 "mwrap.y"
    { 
      if (strcmp((yyvsp[(2) - (4)].string), "numeric") == 0) {
          add_scalar_type((yyvsp[(3) - (4)].string));
      } else if (strcmp((yyvsp[(2) - (4)].string), "dcomplex") == 0) {
          add_zscalar_type((yyvsp[(3) - (4)].string));
      } else if (strcmp((yyvsp[(2) - (4)].string), "fcomplex") == 0) {
          add_cscalar_type((yyvsp[(3) - (4)].string));
      } else if (strcmp((yyvsp[(2) - (4)].string), "mxArray") == 0) {
          add_mxarray_type((yyvsp[(3) - (4)].string));
      } else {
          fprintf(stderr, "Unrecognized typespace: %s\n", (yyvsp[(2) - (4)].string));
          ++type_errs;
      }
      delete[] (yyvsp[(2) - (4)].string);
      delete[] (yyvsp[(3) - (4)].string);
  }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 146 "mwrap.y"
    {
      add_inherits((yyvsp[(2) - (5)].string), (yyvsp[(4) - (5)].inherits));
      delete[] (yyvsp[(2) - (5)].string);
      destroy((yyvsp[(4) - (5)].inherits));
  }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 153 "mwrap.y"
    { (yyval.inherits) = new InheritsDecl((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].inherits)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 156 "mwrap.y"
    { (yyval.inherits) = new InheritsDecl((yyvsp[(2) - (3)].string), (yyvsp[(3) - (3)].inherits)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 157 "mwrap.y"
    { (yyval.inherits) = NULL; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 159 "mwrap.y"
    { (yyval.func) = (yyvsp[(1) - (5)].func); (yyval.func)->args = (yyvsp[(3) - (5)].var); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 162 "mwrap.y"
    { (yyval.var) = (yyvsp[(1) - (2)].var); (yyval.var)->next = (yyvsp[(2) - (2)].var); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 163 "mwrap.y"
    { (yyval.var) = NULL; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 166 "mwrap.y"
    {(yyval.var) = (yyvsp[(2) - (3)].var); (yyval.var)->next = (yyvsp[(3) - (3)].var); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 167 "mwrap.y"
    { (yyval.var) = NULL; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 169 "mwrap.y"
    { (yyval.var) = new Var('o', promote_int((yyvsp[(1) - (2)].string)), NULL, (yyvsp[(2) - (2)].string)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 170 "mwrap.y"
    { (yyval.var) = new Var('o', promote_int((yyvsp[(1) - (3)].string)), (yyvsp[(2) - (3)].qual),   (yyvsp[(3) - (3)].string)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 171 "mwrap.y"
    { (yyval.var) = new Var('o', promote_int((yyvsp[(1) - (3)].string)), (yyvsp[(3) - (3)].qual),   (yyvsp[(2) - (3)].string)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 173 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (3)].c),  promote_int((yyvsp[(2) - (3)].string)), NULL, (yyvsp[(3) - (3)].string)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 174 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (4)].c),  promote_int((yyvsp[(2) - (4)].string)), (yyvsp[(3) - (4)].qual),   (yyvsp[(4) - (4)].string)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 175 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (4)].c),  promote_int((yyvsp[(2) - (4)].string)), (yyvsp[(4) - (4)].qual),   (yyvsp[(3) - (4)].string)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 177 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (3)].c),  promote_int((yyvsp[(2) - (3)].string)), NULL, (yyvsp[(3) - (3)].string)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 178 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (4)].c),  promote_int((yyvsp[(2) - (4)].string)), (yyvsp[(3) - (4)].qual),   (yyvsp[(4) - (4)].string)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 180 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (3)].c),  promote_int((yyvsp[(2) - (3)].string)), NULL, (yyvsp[(3) - (3)].string)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 181 "mwrap.y"
    { (yyval.var) = new Var((yyvsp[(1) - (4)].c),  promote_int((yyvsp[(2) - (4)].string)), (yyvsp[(3) - (4)].qual),   (yyvsp[(4) - (4)].string)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 184 "mwrap.y"
    { (yyval.c) = 'i'; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 185 "mwrap.y"
    { (yyval.c) = 'o'; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 186 "mwrap.y"
    { (yyval.c) = 'b'; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 187 "mwrap.y"
    { (yyval.c) = 'i'; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 190 "mwrap.y"
    { (yyval.qual) = new TypeQual('*', NULL); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 191 "mwrap.y"
    { (yyval.qual) = new TypeQual('&', NULL); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 192 "mwrap.y"
    { (yyval.qual) = (yyvsp[(1) - (1)].qual); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 195 "mwrap.y"
    { (yyval.qual) = new TypeQual('a', (yyvsp[(1) - (1)].expr)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 196 "mwrap.y"
    { (yyval.qual) = new TypeQual('r', (yyvsp[(1) - (2)].expr)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 198 "mwrap.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 201 "mwrap.y"
    { (yyval.expr) = (yyvsp[(1) - (2)].expr); (yyval.expr)->next = (yyvsp[(2) - (2)].expr); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 202 "mwrap.y"
    { (yyval.expr) = NULL; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 205 "mwrap.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); (yyval.expr)->next = (yyvsp[(3) - (3)].expr); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 206 "mwrap.y"
    { (yyval.expr) = NULL; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 209 "mwrap.y"
    { (yyval.expr) = new Expr((yyvsp[(1) - (1)].string)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 210 "mwrap.y"
    { (yyval.expr) = new Expr((yyvsp[(1) - (1)].string)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 213 "mwrap.y"
    { (yyval.func) = new Func((yyvsp[(1) - (6)].string), (yyvsp[(4) - (6)].string), (yyvsp[(6) - (6)].string), current_ifname, linenum); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 214 "mwrap.y"
    { (yyval.func) = new Func(NULL, NULL, (yyvsp[(1) - (1)].string), current_ifname, linenum); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 215 "mwrap.y"
    { (yyval.func) = new Func(NULL, NULL, (yyvsp[(2) - (2)].string), current_ifname, linenum); 
                  (yyval.func)->fort = true;
                }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 218 "mwrap.y"
    { (yyval.func) = new Func(NULL, (yyvsp[(2) - (2)].string), mwrap_strdup("new"), 
                          current_ifname, linenum); 
            }
    break;



/* Line 1806 of yacc.c  */
#line 1846 "mwrap.cc"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 223 "mwrap.y"

#include <stdio.h>
#include <string.h>

extern FILE* yyin;

int yywrap()
{
    return 1;
}

int yyerror(const char* s)
{
    fprintf(stderr, "Parse error (%s:%d): %s\n", current_ifname.c_str(),
            linenum, s);
    return 0;
}

char* mwrap_strdup(const char* s)
{
    char* result = new char[strlen(s)+1];
    strcpy(result, s);
    return result;
}

const char* help_string = 
"mwrap 0.33.3 - MEX file generator for MATLAB and Octave\n"
"\n"
"Syntax:\n"
"  mwrap [-mex outputmex] [-m output.m] [-c outputmex.c] [-mb]\n"
"        [-list] [-catch] infile1 infile2 ...\n"
"\n"
"  -mex outputmex -- specify the MATLAB mex function name\n"
"  -m output.m    -- generate the MATLAB stub called output.m\n"
"  -c outputmex.c -- generate the C file outputmex.c\n"
"  -mb            -- generate .m files specified with @ redirections\n"
"  -list          -- list files specified with @ redirections\n"
"  -catch         -- generate C++ exception handling code\n"
"  -im            -- convert int, long, uint, and ulong types to mwSize\n"
"  -c99complex    -- add support code for C99 complex types\n"
"  -cppcomplex    -- add support code for C++ complex types\n"
"\n";

int main(int argc, char** argv)
{
    int j;
    int err_flag = 0;
    init_scalar_types();

    if (argc == 1) {
        fprintf(stderr, "%s", help_string);
        return 0;
    } else {
        for (j = 1; j < argc; ++j) {
            if (strcmp(argv[j], "-m") == 0 && j+1 < argc)
                outfp = fopen(argv[j+1], "w+");
            if (strcmp(argv[j], "-c") == 0 && j+1 < argc)
                outcfp = fopen(argv[j+1], "w+");
            if (strcmp(argv[j], "-mex") == 0 && j+1 < argc)
                mexfunc = argv[j+1];
            if (strcmp(argv[j], "-mb") == 0)
                mbatching_flag = 1;
            if (strcmp(argv[j], "-list") == 0)
                listing_flag = 1;
            if (strcmp(argv[j], "-catch") == 0)
                mw_generate_catch = true;
            if (strcmp(argv[j], "-im") == 0)
                mw_promote_int = true;
            if (strcmp(argv[j], "-c99complex") == 0) 
                mw_use_c99_complex = true;
            if (strcmp(argv[j], "-cppcomplex") == 0) 
                mw_use_cpp_complex = true;
        }

        if (mw_use_c99_complex || mw_use_cpp_complex) {
            add_zscalar_type("dcomplex");
            add_cscalar_type("fcomplex");
        }

        for (j = 1; j < argc; ++j) {
            if (strcmp(argv[j], "-m") == 0 ||
                strcmp(argv[j], "-c") == 0 ||
                strcmp(argv[j], "-mex") == 0)
                ++j;
            else if (strcmp(argv[j], "-mb") == 0 ||
                     strcmp(argv[j], "-list") == 0 ||
                     strcmp(argv[j], "-catch") == 0 ||
                     strcmp(argv[j], "-im") == 0 ||
                     strcmp(argv[j], "-c99complex") == 0 ||
                     strcmp(argv[j], "-cppcomplex") == 0);
            else {
                linenum = 1;
                type_errs = 0;
                yyin = fopen(argv[j], "r");
                if (yyin) {
                    current_ifname = argv[j];
                    err_flag += yyparse();
                    fclose(yyin);
                } else {
                    fprintf(stderr, "Could not read %s\n", argv[j]);
                }
                if (type_errs)
                    fprintf(stderr, "%s: %d type errors detected\n", 
                            argv[j], type_errs);
                err_flag += type_errs;
            }
        }
    }
    if (!err_flag && outcfp)
        print_mex_file(outcfp, funcs);
    destroy(funcs);
    destroy_inherits();
    if (outfp)
        fclose(outfp);
    if (outcfp)
        fclose(outcfp);
    return err_flag;
}

