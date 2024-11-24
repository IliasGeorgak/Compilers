/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "cgen.h"
  
  #define MAX_COMP_FUNCS 100

  extern int yylex(void);
  extern int line_num;
  FILE *fptr; //file pointer for the generated c file
  char* comp_funcs[MAX_COMP_FUNCS]; //array to hold all member functions for the composite types in string format 
  char* conn = NULL; //string to hold all composite type declarations
  int comp,arr = 0; //flags to keep track of what composite type member variables/functions need to be declared 
  char* parent = NULL; //string to keep track of what function calls need a self argument passed
  int func_index=0; //index to keep track of how many functions have been declared in a composite type

  //Function to replace a substring with a given constant string used for array comprehension
  char *str_replace(char *orig, char *old, char *new_str) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int old_len;  // length of the string to be replaced 
    int new_len; // length of wthe new sub-string
    int len_front; // distance between two instances of the last sub-string
    int cnt;    // number of replacements

    // sanity checks and initialization
    if (!orig || !old || !new_str)
        return NULL;
    old_len = strlen(old);
    new_len = strlen(new_str);
    if (old_len == 0 || new_len == 0)
        return NULL;

    // count the number of replacements needed
    ins = orig;
    for (cnt = 0; (tmp = strstr(ins, old)); ++cnt) {
        ins = tmp + old_len;
    }

    tmp = result = malloc(strlen(orig) + (new_len - old_len) * cnt + 1);

    if (!result)
        return NULL;

    //    tmp points to the end of the result string
    //    ins points to the next occurrence of old in orig
    //    orig points to the remainder of orig after "end of old"
    while (cnt--) {
        ins = strstr(orig, old);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, new_str) + new_len;
        orig += len_front + old_len; // move to next "end of old"
    }
    strcpy(tmp, orig);
    return result;
}
   

#line 132 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TK_STRING = 258,
    TK_IDENT = 259,
    TK_INT = 260,
    TK_REAL = 261,
    KW_TRUE = 262,
    KW_FALSE = 263,
    KW_IF = 264,
    KW_ELSE = 265,
    TK_AND = 266,
    TK_OR = 267,
    TK_NOT = 268,
    TK_MOD = 269,
    TK_POWER = 270,
    TK_COMP_GR = 271,
    TK_COMP_LESS = 272,
    TK_COMP = 273,
    TK_COMP_NEQ = 274,
    TK_COMP_LEQ = 275,
    TK_COMP_GEQ = 276,
    TK_ASSGN_IN = 277,
    TK_ASSGN_DE = 278,
    TK_ASSGN_MU = 279,
    TK_ASSGN_DIV = 280,
    TK_ASSGN_MOD = 281,
    TK_ARROW = 282,
    TK_ARRAY_CR = 283,
    TK_MEMBER = 284,
    KW_INT = 285,
    KW_SCA = 286,
    KW_STR = 287,
    KW_BOOL = 288,
    KW_CONST = 289,
    KW_ENDIF = 290,
    KW_FOR = 291,
    KW_IN = 292,
    KW_ENDFOR = 293,
    KW_WHILE = 294,
    KW_ENDWHILE = 295,
    KW_BREAK = 296,
    KW_CONT = 297,
    KW_COMP = 298,
    KW_ENDCOMP = 299,
    KW_OF = 300,
    KW_DEF = 301,
    KW_ENDDEF = 302,
    KW_MAIN = 303,
    KW_RET = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parser.y"

  char* str;

#line 238 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   775

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,     2,     2,     2,     2,
      55,    56,    53,    51,    59,    52,    60,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    58,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   171,
     175,   176,   180,   181,   185,   186,   190,   205,   206,   210,
     221,   222,   223,   227,   235,   246,   247,   248,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     267,   268,   272,   273,   277,   278,   282,   283,   284,   288,
     289,   293,   294,   295,   296,   300,   310,   311,   315,   316,
     319,   320,   321,   325,   326,   330,   334,   338,   342,   343,
     347,   348,   352,   356,   370,   371,   382,   383,   384,   385,
     386,   387,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   414,   415,   416,   417,   418,   419,   420,   424,   425,
     426,   427,   428
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_STRING", "TK_IDENT", "TK_INT",
  "TK_REAL", "KW_TRUE", "KW_FALSE", "KW_IF", "KW_ELSE", "TK_AND", "TK_OR",
  "TK_NOT", "TK_MOD", "TK_POWER", "TK_COMP_GR", "TK_COMP_LESS", "TK_COMP",
  "TK_COMP_NEQ", "TK_COMP_LEQ", "TK_COMP_GEQ", "TK_ASSGN_IN",
  "TK_ASSGN_DE", "TK_ASSGN_MU", "TK_ASSGN_DIV", "TK_ASSGN_MOD", "TK_ARROW",
  "TK_ARRAY_CR", "TK_MEMBER", "KW_INT", "KW_SCA", "KW_STR", "KW_BOOL",
  "KW_CONST", "KW_ENDIF", "KW_FOR", "KW_IN", "KW_ENDFOR", "KW_WHILE",
  "KW_ENDWHILE", "KW_BREAK", "KW_CONT", "KW_COMP", "KW_ENDCOMP", "KW_OF",
  "KW_DEF", "KW_ENDDEF", "KW_MAIN", "KW_RET", "'#'", "'+'", "'-'", "'*'",
  "'/'", "'('", "')'", "':'", "';'", "','", "'.'", "'='", "'['", "']'",
  "$accept", "program", "global_space", "main_func", "mult_comp",
  "mult_func_dec", "func_dec", "composite", "comp_identifiers",
  "comp_var_dec", "comp_body", "comp_func_dec", "comp_arg_dec", "body",
  "mult_identifiers", "ret_statement", "single_arg_dec", "arg_dec",
  "ident", "identifiers", "var_dec", "mult_var_dec", "mult_args", "args",
  "mult_const_dec", "const_dec", "array_idx", "array_type", "for_cmd",
  "if_cmd", "while_cmd", "func_call", "comprehension", "assignment",
  "operations", "expr", "data_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      35,    43,    45,    42,    47,    40,    41,    58,    59,    44,
      46,    61,    91,    93
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -38,    56,    60,    11,    96,    77,  -147,  -147,    12,
      68,    58,    64,    -9,  -147,   -25,    74,    25,    22,    88,
    -147,   330,    70,    97,   101,   103,  -147,  -147,  -147,    68,
     106,    25,    22,  -147,   110,  -147,  -147,   547,    26,    96,
      96,  -147,  -147,    68,   116,  -147,    68,    25,   118,  -147,
    -147,  -147,  -147,  -147,  -147,   330,   330,   330,   330,   115,
    -147,   298,  -147,   203,  -147,    45,   122,  -147,  -147,  -147,
      68,  -147,    68,    25,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,   -25,  -147,  -147,  -147,  -147,  -147,  -147,    68,  -147,
     710,    95,    95,   590,   363,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,  -147,
     127,    69,   105,  -147,   -37,    73,   128,   129,  -147,  -147,
    -147,    68,  -147,  -147,    94,  -147,  -147,   669,   710,   681,
     164,   164,   109,   109,   109,   109,   109,   109,    95,    95,
      -7,    -7,   547,  -147,   184,    96,    42,   134,   135,   226,
       6,    45,   547,   547,  -147,  -147,  -147,   363,  -147,   139,
    -147,   547,   151,  -147,  -147,  -147,   547,  -147,  -147,  -147,
    -147,   400,  -147,     2,  -147,    96,   146,   418,   -18,   158,
     210,   160,   159,   163,   166,   330,   167,   714,   177,   178,
     179,   180,   183,   186,   196,   198,   162,   211,   212,  -147,
    -147,  -147,   213,   330,   205,   330,  -147,  -147,  -147,   669,
    -147,   330,   330,   330,   330,   330,   330,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,    47,    45,   439,   330,   601,
     220,   612,   669,   669,   669,   669,   669,   669,   547,  -147,
     214,  -147,   658,   217,   330,   223,   227,   457,   279,  -147,
     372,  -147,  -147,  -147,   229,   396,   330,   475,   493,   218,
     230,  -147,   248,  -147,  -147,   225,   253,  -147,   330,   234,
     235,   289,   514,   311,  -147,   547,   250,  -147,   239,   532,
    -147,   292,  -147,  -147,   240,   550,   241,  -147,   547,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    59,     0,     0,     0,     0,     0,     2,    18,     0,
       0,     0,     0,     0,    61,    50,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,    62,     1,    10,     0,
       0,     0,     0,    16,     0,    23,    21,     0,     0,     0,
       0,    66,    13,     0,     0,    14,     0,     0,     0,    74,
     115,   113,   114,   116,   117,     0,     0,     0,     0,   111,
     112,     0,    92,     0,    30,    56,     0,     8,    20,     5,
       0,     6,     0,     0,    22,   122,   118,   120,   121,   119,
      65,    51,    64,    63,    17,    67,    15,    12,     0,    73,
     102,   100,    99,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    59,    57,     0,     0,     0,     0,     9,     7,
       4,     0,    11,   101,     0,    69,    71,    72,   103,   104,
      93,    94,   107,   109,   105,   110,   108,   106,    95,    96,
      98,    97,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     3,    83,    70,    75,     0,
      27,     0,     0,    31,    32,    77,     0,    38,    58,    54,
      55,     0,    68,    35,    29,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,    52,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    28,
      38,    25,     0,     0,     0,     0,    46,    47,    19,    53,
      48,     0,     0,     0,     0,     0,     0,    40,    39,    43,
      42,    44,    45,    49,    41,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    86,     0,    38,
      37,    24,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    38,    38,    34,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    82,    33,     0,     0,    38,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    81,     0,     0,
      84,     0,    38,    79,     0,     0,     0,    78,     0,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,   173,  -147,    -4,    24,   295,  -147,  -147,
    -147,  -147,  -147,  -146,  -147,  -147,  -128,   133,    -3,     0,
     108,   148,  -147,   150,   299,   111,  -147,   -91,  -147,  -147,
    -147,  -120,  -147,  -147,   -16,   257,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    11,    12,   146,   147,
     111,   148,   196,   171,    13,   186,   113,   114,    14,    59,
     188,    17,   124,   125,    18,   189,    20,   116,   190,   191,
     192,    60,   194,   195,    61,    62,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,   158,    26,   126,    39,    29,   112,    97,    98,    15,
     202,   169,   170,    43,    46,    24,     1,    15,    15,   150,
     174,   177,   151,   168,    21,   176,     1,    70,    72,     1,
       1,    15,    15,   166,    34,    40,    82,    83,    81,    90,
      91,    92,    93,    88,    21,   197,     2,    15,    37,   112,
      38,   193,     5,    34,   227,     3,     2,   193,     4,    25,
      22,   -56,     5,   167,    23,   115,   126,    34,     4,   121,
      34,     4,     5,    15,   238,     5,     5,    27,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   247,    34,     5,    34,   246,   240,   161,
       1,   162,    39,   255,   239,   257,   258,   193,    16,    97,
      98,    19,    34,   143,     4,   144,    35,    16,   266,   145,
      19,   272,    36,    97,    98,    44,    16,   193,   279,    48,
     152,    63,    41,    40,   280,   193,   285,   193,   193,    44,
      16,   127,   160,    48,    39,    34,    49,   289,   107,   108,
     156,   115,   193,   157,    64,    44,    65,    31,    66,   193,
     105,   106,   107,   108,    68,   193,    47,   149,    74,   209,
      94,   187,   199,   115,    85,    40,    89,   187,   117,    98,
      73,    44,    28,    33,   142,   153,   154,   229,   159,   231,
      42,    45,   163,   164,   173,   232,   233,   234,   235,   236,
     237,   175,    67,   200,    69,    71,    50,     1,    51,    52,
      53,    54,   242,   203,   204,   205,    84,   206,   225,    86,
      87,   207,    75,   265,   208,   210,   115,   187,   250,    50,
       1,    51,    52,    53,    54,   217,   218,   219,   220,    55,
     262,   221,   230,   118,   222,   119,   120,   187,    76,    77,
      78,    79,   273,     5,   223,   187,   224,   187,   187,    95,
      96,   122,    97,    98,    99,   100,   101,   102,   103,   104,
     -57,   226,   187,   -58,   249,   228,     5,    56,    57,   187,
     251,    58,   244,   254,   252,   187,   259,   267,   270,   165,
     271,   274,   275,   276,   155,   281,   282,   284,   288,   105,
     106,   107,   108,   286,    30,   268,   198,   172,    32,    95,
      96,   269,    97,    98,    99,   100,   101,   102,   103,   104,
     110,     0,    95,    96,     0,    97,    98,    99,   100,   101,
     102,   103,   104,    50,     1,    51,    52,    53,    54,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   105,   106,   107,   108,    50,   112,    51,    52,
      53,    54,     0,     0,   278,     0,    55,     0,     0,     0,
       5,    56,    57,    95,    96,    58,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
     178,     0,     0,     0,   178,   179,   260,     0,     0,   179,
       0,     0,     0,     5,    56,    57,     0,     0,    58,     0,
       0,     0,   178,   105,   106,   107,   108,   179,     0,   256,
       2,   261,   180,     0,     2,   181,   180,   182,   183,   181,
       0,   182,   183,   178,     0,   185,     5,   184,   179,   185,
       5,     0,     2,     0,   180,     0,     0,   181,     0,   182,
     183,   178,     0,     0,     0,   201,   179,   185,     5,     0,
       0,     0,     0,     2,     0,   180,     0,     0,   181,   178,
     182,   183,     0,     0,   179,     0,   241,     0,   185,     5,
       0,     2,     0,   180,     0,     0,   181,   178,   182,   183,
       0,     0,   179,     0,   253,     0,   185,     5,     0,     2,
       0,   180,     0,     0,   181,   263,   182,   183,   178,     0,
       0,     0,     0,   179,   185,     5,     0,     2,     0,   180,
       0,     0,   181,     0,   182,   183,   178,     0,     0,     0,
     264,   179,   185,     5,     0,     0,     0,     0,     2,   277,
     180,    75,     0,   181,   178,   182,   183,     0,     0,   179,
       0,     0,     0,   185,     5,     0,     2,     0,   180,     0,
     283,   181,     0,   182,   183,     0,     0,    76,    77,    78,
      79,   185,     5,     0,     2,     0,   180,     0,   287,   181,
       0,   182,   183,     0,     0,     0,     0,     0,     0,   185,
       5,    95,    96,     0,    97,    98,    99,   100,   101,   102,
     103,   104,    95,    96,     0,    97,    98,    99,   100,   101,
     102,   103,   104,    95,    96,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,     0,   123,     0,     0,     0,
       0,     0,   105,   106,   107,   108,     0,   243,     0,     0,
       0,     0,     0,   105,   106,   107,   108,     0,   245,    95,
      96,     0,    97,    98,    99,   100,   101,   102,   103,   104,
      95,    96,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,    95,     0,   248,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   211,   212,   213,   214,
     215,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,     0,     0,     0,     0,    94,
       0,     0,     0,     0,    40,   216
};

static const yytype_int16 yycheck[] =
{
       0,   142,     5,    94,    29,     9,     4,    14,    15,     9,
      28,   152,   153,    17,    18,     4,     4,    17,    18,    56,
     161,   167,    59,   151,    62,   166,     4,    31,    32,     4,
       4,    31,    32,    27,    10,    60,    39,    40,    38,    55,
      56,    57,    58,    47,    62,   173,    34,    47,    57,     4,
      59,   171,    50,    29,   200,    43,    34,   177,    46,    48,
       4,    59,    50,    57,     4,    65,   157,    43,    46,    73,
      46,    46,    50,    73,    27,    50,    50,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   239,    70,    50,    72,   238,   226,    57,
       4,    59,    29,   249,    57,   251,   252,   227,     0,    14,
      15,     0,    88,    44,    46,    46,    58,     9,   259,    50,
       9,   267,    58,    14,    15,    17,    18,   247,   274,    18,
      57,    61,    58,    60,   275,   255,   282,   257,   258,    31,
      32,   157,   145,    32,    29,   121,    58,   288,    53,    54,
      56,   151,   272,    59,    57,    47,    55,     9,    55,   279,
      51,    52,    53,    54,    58,   285,    18,    62,    58,   185,
      55,   171,   175,   173,    58,    60,    58,   177,    56,    15,
      32,    73,     9,    10,    57,    57,    57,   203,     4,   205,
      17,    18,    58,    58,    55,   211,   212,   213,   214,   215,
     216,    50,    29,    57,    31,    32,     3,     4,     5,     6,
       7,     8,   228,    55,     4,    55,    43,    58,    56,    46,
      47,    58,     4,     5,    58,    58,   226,   227,   244,     3,
       4,     5,     6,     7,     8,    58,    58,    58,    58,    13,
     256,    58,    37,    70,    58,    72,    73,   247,    30,    31,
      32,    33,   268,    50,    58,   255,    58,   257,   258,    11,
      12,    88,    14,    15,    16,    17,    18,    19,    20,    21,
      59,    59,   272,    59,    57,    62,    50,    51,    52,   279,
      57,    55,    62,     4,    57,   285,    57,    57,    63,    63,
      37,    57,    57,     4,   121,    45,    57,     5,    57,    51,
      52,    53,    54,    63,     9,    57,   173,   157,     9,    11,
      12,    63,    14,    15,    16,    17,    18,    19,    20,    21,
      63,    -1,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    51,    52,    53,    54,     3,     4,     5,     6,
       7,     8,    -1,    -1,    63,    -1,    13,    -1,    -1,    -1,
      50,    51,    52,    11,    12,    55,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,     4,     9,    10,    -1,    -1,     9,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,     4,    51,    52,    53,    54,     9,    -1,    57,
      34,    35,    36,    -1,    34,    39,    36,    41,    42,    39,
      -1,    41,    42,     4,    -1,    49,    50,    47,     9,    49,
      50,    -1,    34,    -1,    36,    -1,    -1,    39,    -1,    41,
      42,     4,    -1,    -1,    -1,    47,     9,    49,    50,    -1,
      -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    39,     4,
      41,    42,    -1,    -1,     9,    -1,    47,    -1,    49,    50,
      -1,    34,    -1,    36,    -1,    -1,    39,     4,    41,    42,
      -1,    -1,     9,    -1,    47,    -1,    49,    50,    -1,    34,
      -1,    36,    -1,    -1,    39,    40,    41,    42,     4,    -1,
      -1,    -1,    -1,     9,    49,    50,    -1,    34,    -1,    36,
      -1,    -1,    39,    -1,    41,    42,     4,    -1,    -1,    -1,
      47,     9,    49,    50,    -1,    -1,    -1,    -1,    34,    35,
      36,     4,    -1,    39,     4,    41,    42,    -1,    -1,     9,
      -1,    -1,    -1,    49,    50,    -1,    34,    -1,    36,    -1,
      38,    39,    -1,    41,    42,    -1,    -1,    30,    31,    32,
      33,    49,    50,    -1,    34,    -1,    36,    -1,    38,    39,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    56,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    11,    -1,    36,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    14,    15,    16,    17,    18,    19,
      20,    21,    51,    52,    53,    54,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    34,    43,    46,    50,    65,    66,    67,    68,
      69,    70,    71,    78,    82,    83,    84,    85,    88,    89,
      90,    62,     4,     4,     4,    48,    82,     0,    67,    69,
      71,    85,    88,    67,    70,    58,    58,    57,    59,    29,
      60,    58,    67,    69,    84,    67,    69,    85,    89,    58,
       3,     5,     6,     7,     8,    13,    51,    52,    55,    83,
      95,    98,    99,    61,    57,    55,    55,    67,    58,    67,
      69,    67,    69,    85,    58,     4,    30,    31,    32,    33,
     100,    83,    82,    82,    67,    58,    67,    67,    69,    58,
      98,    98,    98,    98,    55,    11,    12,    14,    15,    16,
      17,    18,    19,    20,    21,    51,    52,    53,    54,    63,
      99,    74,     4,    80,    81,    83,    91,    56,    67,    67,
      67,    69,    67,    56,    86,    87,    91,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    57,    44,    46,    50,    72,    73,    75,    62,
      56,    59,    57,    57,    57,    67,    56,    59,   100,     4,
      82,    57,    59,    58,    58,    63,    27,    57,    80,   100,
     100,    77,    87,    55,   100,    50,   100,    77,     4,     9,
      36,    39,    41,    42,    47,    49,    79,    83,    84,    89,
      92,    93,    94,    95,    96,    97,    76,    80,    81,    82,
      57,    47,    28,    55,     4,    55,    58,    58,    58,    98,
      58,    22,    23,    24,    25,    26,    61,    58,    58,    58,
      58,    58,    58,    58,    58,    56,    59,    77,    62,    98,
      37,    98,    98,    98,    98,    98,    98,    98,    27,    57,
      80,    47,    98,    56,    62,    56,   100,    77,    36,    57,
      98,    57,    57,    47,     4,    77,    57,    77,    77,    57,
      10,    35,    98,    40,    47,     5,   100,    57,    57,    63,
      63,    37,    77,    98,    57,    57,     4,    35,    63,    77,
     100,    45,    57,    38,     5,    77,    63,    38,    57,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    72,    73,
      74,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    89,    90,    91,    92,    92,
      93,    93,    94,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     4,     3,     3,     4,     3,     4,
       2,     4,     3,     2,     2,     3,     2,     3,     1,     8,
       3,     2,     3,     2,    10,     8,     5,     2,     4,     3,
       0,     3,     3,    10,     8,     0,     1,     3,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     2,     3,     3,     0,     1,     3,     1,
       1,     1,     2,     3,     3,     3,     2,     3,     3,     1,
       0,     1,     1,     3,     2,     6,     4,     3,    13,    11,
       7,    10,     7,     4,    11,    15,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 149 "parser.y"
             {fptr = fopen("interpreted.c","w");fprintf(fptr,"%s\n%s",c_prologue,(yyvsp[0].str));}
#line 1707 "parser.tab.c"
    break;

  case 3:
#line 153 "parser.y"
                                                              {(yyval.str) = template("%s\n%s\n%s\n%s\n%s\n",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1713 "parser.tab.c"
    break;

  case 4:
#line 154 "parser.y"
                                                   {(yyval.str) = template("%s\n%s\n%s\n%s\n",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1719 "parser.tab.c"
    break;

  case 5:
#line 155 "parser.y"
                                             {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1725 "parser.tab.c"
    break;

  case 6:
#line 156 "parser.y"
                                               {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1731 "parser.tab.c"
    break;

  case 7:
#line 157 "parser.y"
                                                    {(yyval.str) = template("%s\n%s\n%s\n%s\n",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1737 "parser.tab.c"
    break;

  case 8:
#line 158 "parser.y"
                                                 {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1743 "parser.tab.c"
    break;

  case 9:
#line 159 "parser.y"
                                                  {(yyval.str) = template("%s\n%s\n%s\n%s\n",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1749 "parser.tab.c"
    break;

  case 10:
#line 160 "parser.y"
                                                  {(yyval.str) = template("%s\n%s\n",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1755 "parser.tab.c"
    break;

  case 11:
#line 161 "parser.y"
                                                      {(yyval.str) = template("%s\n%s\n%s\n%s\n",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1761 "parser.tab.c"
    break;

  case 12:
#line 162 "parser.y"
                                          {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1767 "parser.tab.c"
    break;

  case 13:
#line 163 "parser.y"
                                    {(yyval.str) = template("%s\n%s\n",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1773 "parser.tab.c"
    break;

  case 14:
#line 164 "parser.y"
                                      {(yyval.str) = template("%s\n%s\n",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1779 "parser.tab.c"
    break;

  case 15:
#line 165 "parser.y"
                                           {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1785 "parser.tab.c"
    break;

  case 16:
#line 166 "parser.y"
                                       {(yyval.str) = template("%s\n%s\n",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1791 "parser.tab.c"
    break;

  case 17:
#line 167 "parser.y"
                                        {(yyval.str) = template("%s\n%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1797 "parser.tab.c"
    break;

  case 18:
#line 168 "parser.y"
                                        {(yyval.str) = template("%s\n",(yyvsp[0].str));}
#line 1803 "parser.tab.c"
    break;

  case 19:
#line 171 "parser.y"
                                                          {(yyval.str) = template("void main(){\t%s\n}\n",(yyvsp[-2].str));}
#line 1809 "parser.tab.c"
    break;

  case 20:
#line 175 "parser.y"
                          {(yyval.str) = template("%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1815 "parser.tab.c"
    break;

  case 21:
#line 176 "parser.y"
                            {(yyval.str) = template("%s\n",(yyvsp[-1].str));}
#line 1821 "parser.tab.c"
    break;

  case 22:
#line 180 "parser.y"
                               {(yyval.str) = template("%s\n%s\n",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1827 "parser.tab.c"
    break;

  case 23:
#line 181 "parser.y"
                              {(yyval.str) = template("%s\n",(yyvsp[-1].str));}
#line 1833 "parser.tab.c"
    break;

  case 24:
#line 185 "parser.y"
                                                                     {(yyval.str) = template("%s %s(%s){%s};",(yyvsp[-3].str),(yyvsp[-8].str),(yyvsp[-6].str),(yyvsp[-1].str));}
#line 1839 "parser.tab.c"
    break;

  case 25:
#line 186 "parser.y"
                                                     {(yyval.str) = template("void %s(%s){%s};",(yyvsp[-6].str),(yyvsp[-4].str),(yyvsp[-1].str));}
#line 1845 "parser.tab.c"
    break;

  case 26:
#line 190 "parser.y"
                                          { char* total; //The final composite type declaration
                                               total = template("#define SELF struct %s *self\ntypedef struct %s{%s} %s;\n\n",(yyvsp[-3].str),(yyvsp[-3].str),(yyvsp[-1].str),(yyvsp[-3].str));
                                               for(int i=0;i<func_index;i++){
                                                  total = template("%s\n%s\n",total,comp_funcs[i]);//add each function with its body after the struct declartion
                                                  free(comp_funcs[i]);//free each string used
                                               }
                                               func_index = 0; // reset the function index after each use
                                               total = template("%s\nconst %s ctor_%s = {%s};",total,(yyvsp[-3].str),(yyvsp[-3].str),conn); //connect function declarations with definitions
                                               conn = NULL; 
                                               total = template("%s\n#undef SELF\n",total);
                                               (yyval.str) = total;
}
#line 1862 "parser.tab.c"
    break;

  case 27:
#line 205 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 1868 "parser.tab.c"
    break;

  case 28:
#line 206 "parser.y"
                                 {(yyval.str) = template("%s , %s",(yyvsp[-3].str),(yyvsp[0].str));}
#line 1874 "parser.tab.c"
    break;

  case 29:
#line 210 "parser.y"
                                {   if(comp == 1){ 
                                      if(conn != NULL)
                                        conn = template("%s, .%s=ctor_%s",conn,(yyvsp[-2].str),(yyvsp[0].str));
                                      else
                                        conn = template(".%s=ctor_%s",(yyvsp[-2].str),(yyvsp[0].str));//solution for checking if this the first assignment 
                                      comp = 0;
                                    }
                                    (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 1887 "parser.tab.c"
    break;

  case 30:
#line 221 "parser.y"
         {(yyval.str) = "";}
#line 1893 "parser.tab.c"
    break;

  case 31:
#line 222 "parser.y"
                             {(yyval.str) = template("%s\n%s;\n",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1899 "parser.tab.c"
    break;

  case 32:
#line 223 "parser.y"
                              {(yyval.str) = template("%s\n%s;\n",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1905 "parser.tab.c"
    break;

  case 33:
#line 227 "parser.y"
                                                                          {comp_funcs[func_index] = template("%s %s(SELF%s){\n%s\n}\n",(yyvsp[-3].str),(yyvsp[-8].str),(yyvsp[-6].str),(yyvsp[-1].str)); //Add the function definition to the array in order to place under the struct declaration
                                                                          if(conn != NULL) //same as before
                                                                            conn = template("%s, .%s=%s",conn,(yyvsp[-8].str),(yyvsp[-8].str));
                                                                          else
                                                                            conn = template(".%s=%s",(yyvsp[-8].str),(yyvsp[-8].str));
                                                                          func_index++;
                                                                          (yyval.str) = template("%s (*%s)(SELF %s)",(yyvsp[-3].str),(yyvsp[-8].str),(yyvsp[-6].str));
}
#line 1918 "parser.tab.c"
    break;

  case 34:
#line 235 "parser.y"
                                                          {comp_funcs[func_index] = template("void %s(SELF%s){\n%s\n}\n",(yyvsp[-6].str),(yyvsp[-4].str),(yyvsp[-1].str));
                                                                      if(conn != NULL)
                                                                            conn = template("%s, .%s=%s",conn,(yyvsp[-6].str),(yyvsp[-6].str));
                                                                      else
                                                                            conn = template(".%s=%s",(yyvsp[-6].str),(yyvsp[-6].str));
                                                                      func_index++;
                                                                      (yyval.str) = template("void (*%s)(SELF%s)",(yyvsp[-6].str),(yyvsp[-4].str));
}
#line 1931 "parser.tab.c"
    break;

  case 35:
#line 246 "parser.y"
       {(yyval.str) = "";}
#line 1937 "parser.tab.c"
    break;

  case 36:
#line 247 "parser.y"
                 {(yyval.str) = template(",%s",(yyvsp[0].str));}
#line 1943 "parser.tab.c"
    break;

  case 37:
#line 248 "parser.y"
                            {(yyval.str) = template(",%s,%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 1949 "parser.tab.c"
    break;

  case 38:
#line 252 "parser.y"
       {(yyval.str) = " ";}
#line 1955 "parser.tab.c"
    break;

  case 39:
#line 253 "parser.y"
                     {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1961 "parser.tab.c"
    break;

  case 40:
#line 254 "parser.y"
                    {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1967 "parser.tab.c"
    break;

  case 41:
#line 255 "parser.y"
                      {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1973 "parser.tab.c"
    break;

  case 42:
#line 256 "parser.y"
                     {(yyval.str) = template("%s\n%s",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1979 "parser.tab.c"
    break;

  case 43:
#line 257 "parser.y"
                      {(yyval.str) = template("%s\n%s",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1985 "parser.tab.c"
    break;

  case 44:
#line 258 "parser.y"
                        {(yyval.str) = template("%s\n%s",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1991 "parser.tab.c"
    break;

  case 45:
#line 259 "parser.y"
                       {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 1997 "parser.tab.c"
    break;

  case 46:
#line 260 "parser.y"
                       {(yyval.str) = template("%s\nbreak;",(yyvsp[-2].str));}
#line 2003 "parser.tab.c"
    break;

  case 47:
#line 261 "parser.y"
                      {(yyval.str) = template("%s\ncontinue;",(yyvsp[-2].str));}
#line 2009 "parser.tab.c"
    break;

  case 48:
#line 262 "parser.y"
                            {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 2015 "parser.tab.c"
    break;

  case 49:
#line 263 "parser.y"
                           {(yyval.str)= template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 2021 "parser.tab.c"
    break;

  case 50:
#line 267 "parser.y"
            {(yyval.str) = (yyvsp[0].str);}
#line 2027 "parser.tab.c"
    break;

  case 51:
#line 268 "parser.y"
                                   {(yyval.str) = template("%s , %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2033 "parser.tab.c"
    break;

  case 52:
#line 272 "parser.y"
       {(yyval.str) = template("return");}
#line 2039 "parser.tab.c"
    break;

  case 53:
#line 273 "parser.y"
                    {(yyval.str) = template("return %s",(yyvsp[0].str));}
#line 2045 "parser.tab.c"
    break;

  case 54:
#line 277 "parser.y"
                          {(yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2051 "parser.tab.c"
    break;

  case 55:
#line 278 "parser.y"
                           {(yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2057 "parser.tab.c"
    break;

  case 56:
#line 282 "parser.y"
       {(yyval.str) = "";}
#line 2063 "parser.tab.c"
    break;

  case 57:
#line 283 "parser.y"
                {(yyval.str) = (yyvsp[0].str);}
#line 2069 "parser.tab.c"
    break;

  case 58:
#line 284 "parser.y"
                            {(yyval.str) = template("%s,%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2075 "parser.tab.c"
    break;

  case 59:
#line 288 "parser.y"
         {(yyval.str) = (yyvsp[0].str);}
#line 2081 "parser.tab.c"
    break;

  case 60:
#line 289 "parser.y"
            {(yyval.str) = (yyvsp[0].str);}
#line 2087 "parser.tab.c"
    break;

  case 61:
#line 293 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 2093 "parser.tab.c"
    break;

  case 62:
#line 294 "parser.y"
            {(yyval.str) = template("self->%s",(yyvsp[0].str));}
#line 2099 "parser.tab.c"
    break;

  case 63:
#line 295 "parser.y"
                        {parent = (yyvsp[-2].str);(yyval.str) = template("%s.%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2105 "parser.tab.c"
    break;

  case 64:
#line 296 "parser.y"
                              {(yyval.str) = template("%s.%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2111 "parser.tab.c"
    break;

  case 65:
#line 300 "parser.y"
                                {
  if(comp == 1){
    (yyval.str) = template("%s %s = ctor_%s",(yyvsp[0].str),(yyvsp[-2].str),(yyvsp[0].str));
    comp = 0;
  }
  else
  (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2123 "parser.tab.c"
    break;

  case 66:
#line 310 "parser.y"
            {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2129 "parser.tab.c"
    break;

  case 67:
#line 311 "parser.y"
                           {(yyval.str) = template("%s\n%s;",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 2135 "parser.tab.c"
    break;

  case 68:
#line 315 "parser.y"
                    {(yyval.str) = template("%s , %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2141 "parser.tab.c"
    break;

  case 69:
#line 316 "parser.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 2147 "parser.tab.c"
    break;

  case 70:
#line 319 "parser.y"
            {(yyval.str)="";}
#line 2153 "parser.tab.c"
    break;

  case 71:
#line 320 "parser.y"
             {(yyval.str) = (yyvsp[0].str);}
#line 2159 "parser.tab.c"
    break;

  case 72:
#line 321 "parser.y"
             {(yyval.str) = (yyvsp[0].str);}
#line 2165 "parser.tab.c"
    break;

  case 73:
#line 325 "parser.y"
                             {(yyval.str) = template("%s , %s",(yyvsp[-2].str),(yyvsp[-1].str));}
#line 2171 "parser.tab.c"
    break;

  case 74:
#line 326 "parser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2177 "parser.tab.c"
    break;

  case 75:
#line 330 "parser.y"
                                          {(yyval.str) = template("const %s %s = %s;",(yyvsp[0].str),(yyvsp[-4].str),(yyvsp[-2].str));}
#line 2183 "parser.tab.c"
    break;

  case 76:
#line 334 "parser.y"
                            {(yyval.str) = template("%s[%s]",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 2189 "parser.tab.c"
    break;

  case 77:
#line 338 "parser.y"
                 {(yyval.str) = template("%s[]",(yyvsp[-2].str));}
#line 2195 "parser.tab.c"
    break;

  case 78:
#line 342 "parser.y"
                                                                                         {(yyval.str) = template("for(int %s=%s;%s<%s;%s+=%s){\t%s\n}\n",(yyvsp[-11].str),(yyvsp[-8].str),(yyvsp[-11].str),(yyvsp[-6].str),(yyvsp[-11].str),(yyvsp[-4].str),(yyvsp[-1].str));}
#line 2201 "parser.tab.c"
    break;

  case 79:
#line 343 "parser.y"
                                                                           {(yyval.str) = template("for(int %s=%s;%s<%s;%s++){\t%s\n}\n",(yyvsp[-9].str),(yyvsp[-6].str),(yyvsp[-9].str),(yyvsp[-4].str),(yyvsp[-9].str),(yyvsp[-1].str));}
#line 2207 "parser.tab.c"
    break;

  case 80:
#line 347 "parser.y"
                                            {(yyval.str) = template("if(%s){\t%s\n}\n",(yyvsp[-4].str),(yyvsp[-1].str));}
#line 2213 "parser.tab.c"
    break;

  case 81:
#line 348 "parser.y"
                                                              {(yyval.str) = template("if(%s){%s}\nelse\n{\t%s\n}\n",(yyvsp[-7].str),(yyvsp[-4].str),(yyvsp[-1].str));}
#line 2219 "parser.tab.c"
    break;

  case 82:
#line 352 "parser.y"
                                                 {(yyval.str) = template("while(%s){\t%s\n}\n",(yyvsp[-4].str),(yyvsp[-1].str));}
#line 2225 "parser.tab.c"
    break;

  case 83:
#line 356 "parser.y"
                              {
  if(parent!=NULL){ //is this is call refers to a composite member function pass the self argument
      if((yyvsp[-1].str) == ""){
        (yyval.str) = template("%s(&%s)",(yyvsp[-3].str),parent,(yyvsp[-1].str)); //No other arguments
      }
      else
        (yyval.str) = template("%s(&%s,%s)",(yyvsp[-3].str),parent,(yyvsp[-1].str)); //Multiple arguments
    parent = NULL;
  }
  else
    (yyval.str) = template("%s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 2241 "parser.tab.c"
    break;

  case 84:
#line 370 "parser.y"
                                                                                  {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s=0;%s<%s;++%s)\n\t%s[%s]=%s",(yyvsp[0].str),(yyvsp[-10].str),(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[0].str),(yyvsp[-5].str),(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-5].str),(yyvsp[-10].str),(yyvsp[-5].str),(yyvsp[-7].str));}
#line 2247 "parser.tab.c"
    break;

  case 85:
#line 371 "parser.y"
                                                                                                                  {
  char* rep= strdup((yyvsp[-5].str)); //Get a copy of the original string
  char* op = (yyvsp[-11].str);
  char* elm = (yyvsp[-9].str);
  strcat(rep,"[array_i]"); //In this case we need to replace the variable used in the expression with each array index 
  (yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int array_i=0;array_i<%s;++array_i)\n\t%s[array_i]=%s",(yyvsp[0].str),(yyvsp[-14].str),(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-14].str),str_replace(op,elm,rep));

}
#line 2260 "parser.tab.c"
    break;

  case 86:
#line 382 "parser.y"
                            {(yyval.str) = template("%s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2266 "parser.tab.c"
    break;

  case 87:
#line 383 "parser.y"
                                     {(yyval.str) = template("%s += %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2272 "parser.tab.c"
    break;

  case 88:
#line 384 "parser.y"
                                     {(yyval.str) = template("%s -= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2278 "parser.tab.c"
    break;

  case 89:
#line 385 "parser.y"
                                     {(yyval.str) = template("%s *= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2284 "parser.tab.c"
    break;

  case 90:
#line 386 "parser.y"
                                      {(yyval.str) = template("%s /= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2290 "parser.tab.c"
    break;

  case 91:
#line 387 "parser.y"
                                      {(yyval.str) = template("%s %%= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2296 "parser.tab.c"
    break;

  case 92:
#line 391 "parser.y"
       {(yyval.str) = (yyvsp[0].str);}
#line 2302 "parser.tab.c"
    break;

  case 93:
#line 392 "parser.y"
                               {(yyval.str) = template("%s %% %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2308 "parser.tab.c"
    break;

  case 94:
#line 393 "parser.y"
                                 {(yyval.str) = template("pow(%s,%s)",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2314 "parser.tab.c"
    break;

  case 95:
#line 394 "parser.y"
                            {(yyval.str) = template("%s + %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2320 "parser.tab.c"
    break;

  case 96:
#line 395 "parser.y"
                            {(yyval.str) = template("%s - %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2326 "parser.tab.c"
    break;

  case 97:
#line 396 "parser.y"
                            {(yyval.str) = template("%s / %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2332 "parser.tab.c"
    break;

  case 98:
#line 397 "parser.y"
                            {(yyval.str) = template("%s * %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2338 "parser.tab.c"
    break;

  case 99:
#line 398 "parser.y"
                 {(yyval.str) = template("-%s",(yyvsp[0].str));}
#line 2344 "parser.tab.c"
    break;

  case 100:
#line 399 "parser.y"
                 {(yyval.str) = template("+%s",(yyvsp[0].str));}
#line 2350 "parser.tab.c"
    break;

  case 101:
#line 400 "parser.y"
                     {(yyval.str) = template("(%s)",(yyvsp[-1].str));}
#line 2356 "parser.tab.c"
    break;

  case 102:
#line 401 "parser.y"
                    {(yyval.str) = template("!%s",(yyvsp[0].str));}
#line 2362 "parser.tab.c"
    break;

  case 103:
#line 402 "parser.y"
                               {(yyval.str) = template("%s && %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2368 "parser.tab.c"
    break;

  case 104:
#line 403 "parser.y"
                              {(yyval.str) = template("%s || %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2374 "parser.tab.c"
    break;

  case 105:
#line 404 "parser.y"
                                {(yyval.str) = template("%s == %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2380 "parser.tab.c"
    break;

  case 106:
#line 405 "parser.y"
                                    {(yyval.str) = template("%s >= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2386 "parser.tab.c"
    break;

  case 107:
#line 406 "parser.y"
                                   {(yyval.str) = template("%s > %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2392 "parser.tab.c"
    break;

  case 108:
#line 407 "parser.y"
                                    {(yyval.str) = template("%s <= %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2398 "parser.tab.c"
    break;

  case 109:
#line 408 "parser.y"
                                     {(yyval.str) = template("%s < %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2404 "parser.tab.c"
    break;

  case 110:
#line 409 "parser.y"
                                    {(yyval.str) = template("%s != %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2410 "parser.tab.c"
    break;

  case 111:
#line 414 "parser.y"
              {(yyval.str) = (yyvsp[0].str);}
#line 2416 "parser.tab.c"
    break;

  case 112:
#line 415 "parser.y"
            {(yyval.str) = (yyvsp[0].str);}
#line 2422 "parser.tab.c"
    break;

  case 113:
#line 416 "parser.y"
         {(yyval.str) = (yyvsp[0].str);}
#line 2428 "parser.tab.c"
    break;

  case 114:
#line 417 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 2434 "parser.tab.c"
    break;

  case 115:
#line 418 "parser.y"
            {(yyval.str) = (yyvsp[0].str);}
#line 2440 "parser.tab.c"
    break;

  case 116:
#line 419 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 2446 "parser.tab.c"
    break;

  case 117:
#line 420 "parser.y"
           {(yyval.str) = (yyvsp[0].str);}
#line 2452 "parser.tab.c"
    break;

  case 118:
#line 424 "parser.y"
       {comp=0;(yyval.str) = "int";}
#line 2458 "parser.tab.c"
    break;

  case 119:
#line 425 "parser.y"
          {comp=0;(yyval.str) = "int";}
#line 2464 "parser.tab.c"
    break;

  case 120:
#line 426 "parser.y"
          {comp=0;(yyval.str) = "float";}
#line 2470 "parser.tab.c"
    break;

  case 121:
#line 427 "parser.y"
          {comp=0;(yyval.str) = "char*";}
#line 2476 "parser.tab.c"
    break;

  case 122:
#line 428 "parser.y"
           {comp=1;(yyval.str) = (yyvsp[0].str);}
#line 2482 "parser.tab.c"
    break;


#line 2486 "parser.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 431 "parser.y"

int main () {
  
  if ( yyparse() == 0 )
    printf("Accepted!\n");
  else
    printf("Rejected!\n");

  fclose(fptr);
}
