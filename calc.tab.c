/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "TS.h"
#include "funciones.h"

#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

extern FILE *yyin;
int yylex();
void yyerror(const char *s);
extern void liberarMemoria();
extern char* yytext;

int echo=1; /*Variable la cual nos dira si el output se muestra o no
1-> se muestra a no se que se acaba en ;
0-> No se muestra nunca el output
NOTA: Este el echo activado o no la salida de los distintos comandos siempre se mostrarán por pantalla*/


int procesandoArchivo=0; /*Variable la cual nos dira si el estamos procesando el contenido de un archivo o no
1-> estamos procesando un archivo
0-> no estamos procesando un archivo
Inicialmente no estamos procesando un archivo, por lo que la bandera es 0*/

#line 100 "calc.tab.c"

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

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNC = 3,                       /* FUNC  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_CONS = 5,                       /* CONS  */
  YYSYMBOL_NUM = 6,                        /* NUM  */
  YYSYMBOL_FinalFichero = 7,               /* FinalFichero  */
  YYSYMBOL_COMANDO = 8,                    /* COMANDO  */
  YYSYMBOL_LOAD = 9,                       /* LOAD  */
  YYSYMBOL_10_ = 10,                       /* '-'  */
  YYSYMBOL_11_ = 11,                       /* '+'  */
  YYSYMBOL_12_ = 12,                       /* '*'  */
  YYSYMBOL_13_ = 13,                       /* '/'  */
  YYSYMBOL_NEG = 14,                       /* NEG  */
  YYSYMBOL_15_ = 15,                       /* '^'  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_17_n_ = 17,                     /* '\n'  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 22,                  /* $accept  */
  YYSYMBOL_input = 23,                     /* input  */
  YYSYMBOL_line = 24,                      /* line  */
  YYSYMBOL_comando = 25,                   /* comando  */
  YYSYMBOL_asignacion = 26,                /* asignacion  */
  YYSYMBOL_funcion = 27,                   /* funcion  */
  YYSYMBOL_exp = 28                        /* exp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  56

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   265


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
      19,    20,    12,    11,     2,    10,     2,    13,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    14
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    61,    65,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    83,   109,   116,   129,   140,   143,
     149,   170,   171,   186,   194,   195,   196,   197,   204,   211,
     212,   213
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUNC", "VAR", "CONS",
  "NUM", "FinalFichero", "COMANDO", "LOAD", "'-'", "'+'", "'*'", "'/'",
  "NEG", "'^'", "';'", "'\\n'", "'='", "'('", "')'", "'%'", "$accept",
  "input", "line", "comando", "asignacion", "funcion", "exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-15)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -15,    26,   -15,    -5,    22,    24,    31,   -15,   -15,   -15,
     -15,    42,   -15,    42,   -15,    33,    -1,     1,    47,   -15,
      42,    34,    34,   -15,   -15,   -14,    -7,   -15,    37,   -15,
      38,   -15,    42,    42,    42,    42,    42,    39,   -15,    42,
      59,   -15,    71,   -15,    71,   -15,   -15,   -15,    75,    75,
     -14,   -14,   -14,   -15,    71,   -15
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,    22,    23,    21,     4,    14,
      15,     0,     5,     0,     3,     0,     0,     0,     0,    13,
       0,     0,     0,    22,    23,    29,     0,    10,     0,     8,
       0,    11,     0,     0,     0,     0,     0,     0,     6,     0,
       0,    17,    16,    19,    18,    31,     9,    12,    25,    24,
      26,    27,    30,     7,    28,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -15,   -15,   -15,   -15,   -15,    -2,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    14,    15,    16,    17,    18
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    36,    26,    32,    33,    34,    35,    39,    36,    40,
      42,    44,    19,    45,    39,    28,    29,    30,    31,    41,
      43,    48,    49,    50,    51,    52,     2,     3,    54,     4,
       5,     6,     7,     8,     9,    10,    11,     4,    23,    24,
       7,    20,    21,    12,    11,    13,    23,    24,     7,    22,
      27,     0,    11,    13,    46,    47,    53,    32,    33,    34,
      35,    13,    36,    37,    38,     0,     0,     0,    39,    32,
      33,    34,    35,     0,    36,     0,     0,     0,     0,    55,
      39,    32,    33,    34,    35,     0,    36,    34,    35,     0,
      36,     0,    39,     0,     0,     0,    39
};

static const yytype_int8 yycheck[] =
{
      11,    15,    13,    10,    11,    12,    13,    21,    15,    20,
      21,    22,    17,    20,    21,    16,    17,    16,    17,    21,
      22,    32,    33,    34,    35,    36,     0,     1,    39,     3,
       4,     5,     6,     7,     8,     9,    10,     3,     4,     5,
       6,    19,    18,    17,    10,    19,     4,     5,     6,    18,
      17,    -1,    10,    19,    17,    17,    17,    10,    11,    12,
      13,    19,    15,    16,    17,    -1,    -1,    -1,    21,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    10,    11,    12,    13,    -1,    15,    12,    13,    -1,
      15,    -1,    21,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    17,    19,    24,    25,    26,    27,    28,    17,
      19,    18,    18,     4,     5,    28,    28,    17,    16,    17,
      16,    17,    10,    11,    12,    13,    15,    16,    17,    21,
      28,    27,    28,    27,    28,    20,    17,    17,    28,    28,
      28,    28,    28,    17,    28,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    22,    23,    23,    23,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    25,    25,    26,    26,    26,    26,
      27,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     2,     3,
       2,     2,     3,     2,     1,     1,     3,     3,     3,     3,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     2,
       3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 3: /* input: input line  */
#line 61 "calc.y"
                   { 
										if(procesandoArchivo) printf(">> "); //Diferenciando asi los printfs, podemos distinguir si estamos en un archivo o no
										else printf("> ");
										}
#line 1149 "calc.tab.c"
    break;

  case 4: /* input: input FinalFichero  */
#line 65 "calc.y"
                                             {
									  printf("Archivo introducido por terminal correctamente procesado\n"); 
										procesandoArchivo=0; 
										printf("> "); 
										}
#line 1159 "calc.tab.c"
    break;

  case 6: /* line: exp '\n'  */
#line 73 "calc.y"
               {if(echo==1 && !isnan((yyvsp[-1].val))) printf ("Resultado de la expresión -> %.2f\n", (yyvsp[-1].val)); }
#line 1165 "calc.tab.c"
    break;

  case 7: /* line: exp ';' '\n'  */
#line 74 "calc.y"
                   {/*No se hace nada*/}
#line 1171 "calc.tab.c"
    break;

  case 8: /* line: asignacion '\n'  */
#line 75 "calc.y"
                      {if(echo==1 && !isnan((yyvsp[-1].token).contenido)) printf("Asignado: %s = %.2f\n", (yyvsp[-1].token).cadena, (yyvsp[-1].token).contenido); free((yyvsp[-1].token).cadena); }
#line 1177 "calc.tab.c"
    break;

  case 9: /* line: asignacion ';' '\n'  */
#line 76 "calc.y"
                          {free((yyvsp[-2].token).cadena);}
#line 1183 "calc.tab.c"
    break;

  case 11: /* line: funcion '\n'  */
#line 78 "calc.y"
                   {if(echo==1 && !isnan((yyvsp[-1].token).contenido)) printf("Resultado obtenido con %s -> %.2f\n", (yyvsp[-1].token).cadena ,(yyvsp[-1].token).contenido); free((yyvsp[-1].token).cadena);}
#line 1189 "calc.tab.c"
    break;

  case 12: /* line: funcion ';' '\n'  */
#line 79 "calc.y"
                                   {free((yyvsp[-2].token).cadena);}
#line 1195 "calc.tab.c"
    break;

  case 13: /* line: error '\n'  */
#line 80 "calc.y"
                             {yyerrok;}
#line 1201 "calc.tab.c"
    break;

  case 14: /* comando: COMANDO  */
#line 83 "calc.y"
                 {
	if (strcmp((yyvsp[0].lexema), "HELP")==0){
		help(); /*Mostramos la ayuda*/
	}
	else if(strcmp((yyvsp[0].lexema), "EXIT")==0){
		 printf("Exit: Salir del programa.\n");
		 if(yyin!=stdin && yyin !=NULL){ //Este if se hace por si acaso se ha ejecutado un EXIT dentro de un archivo, asi nos aseguramos de liberar la memoria
				fclose(yyin);
				yyin=NULL;
		 } 
		 free((yyvsp[0].lexema)); liberarTS(); finalizarLexico(); exit(0);
	}
	else if(strcmp((yyvsp[0].lexema), "CLEAR")==0){
		clear(); /*Eliminamos de la TS y liberamos su memoria, las variables, ya que si eliminamos las funciones al ser estáticas después no se podrán usar*/
	}
	else if(strcmp((yyvsp[0].lexema), "WORKSPACE")==0){
		imprimirTablaSimbolos(); /*Imprimimos nuestro entorno de trabajo, es decir, la tabla de simbolos*/
	}
	else if(strcmp((yyvsp[0].lexema), "ECHO(ON)")==0){/*En el caso de que echo se ponga en ON (esta activado por defecto) se mostrará el output a no ser que se acaba en ;*/
		echo=1;
	}
	else{
		echo=0; /*En cualquier otro caso sabemos que estamos en el caso de desactivar el echo, no se mostrará nunca el output*/
	}
	free((yyvsp[0].lexema));
	}
#line 1232 "calc.tab.c"
    break;

  case 15: /* comando: LOAD  */
#line 109 "calc.y"
               {
		procesandoArchivo=1; /*Activamos la bandera de que estamos procesando un archivo*/
		leer_archivo((yyvsp[0].lexema));
		free((yyvsp[0].lexema));
	}
#line 1242 "calc.tab.c"
    break;

  case 16: /* asignacion: VAR '=' exp  */
#line 116 "calc.y"
                         {
		if(!isnan((yyvsp[0].val))){ /*Si la expresion recibida es un número, podemos realizar la asignación*/
			(yyvsp[-2].token).contenido = (yyvsp[0].val);
			int valida = buscarVariable((yyvsp[-2].token).cadena, (yyvsp[-2].token).contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			if(valida==1) (yyval.token)=(yyvsp[-2].token);
			else{
				printf(RED"El nombre de la variable coincide con la de una función o constante\n"RESET);
				(yyval.token).contenido=NAN;
				free((yyvsp[-2].token).cadena);
			}
		}
		else printf(RED"No se puede hacer la asignación de la expresión a la variable\n"RESET);
	 }
#line 1260 "calc.tab.c"
    break;

  case 17: /* asignacion: VAR '=' funcion  */
#line 129 "calc.y"
                           {
		 if(!isnan((yyvsp[0].token).contenido)){
			(yyvsp[-2].token).contenido = (yyvsp[0].token).contenido;
			buscarVariable((yyvsp[-2].token).cadena, (yyvsp[-2].token).contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			(yyval.token)=(yyvsp[-2].token);
		}
		else printf(RED"No se pudo asignar el resultado de la función a la variable\n"RESET);
		free((yyvsp[0].token).cadena);
	 }
#line 1274 "calc.tab.c"
    break;

  case 18: /* asignacion: CONS '=' exp  */
#line 140 "calc.y"
                        {
		 printf(RED"No se puede asignar una expresión a una constante\n"RESET); (yyval.token).contenido=NAN;
	 }
#line 1282 "calc.tab.c"
    break;

  case 19: /* asignacion: CONS '=' funcion  */
#line 143 "calc.y"
                            {
		 printf(RED"No se puede asignar el resultado de una función a una constante\n"RESET); (yyval.token).contenido=NAN; free((yyvsp[0].token).cadena);
	 }
#line 1290 "calc.tab.c"
    break;

  case 20: /* funcion: FUNC '(' exp ')'  */
#line 149 "calc.y"
                          {
	if(!isnan((yyvsp[-1].val))){ /*Si la expresión es distinta de NAN, proecedemos a mirar si existe la función que se ha reconocido*/
		double(*funcion)() = recuperarContenidoFuncion((yyvsp[-3].lexema)); /*Pedimos a TS.c que nos devuelva el valor de la función*/
		int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
		if (bandera == 1){ /*La función está en la TS y hemos recuperado su correspondiente valor*/
			printf("Valor recuperado de %s en la TS -> %p\n",(yyvsp[-3].lexema), funcion);
			(yyval.token).contenido=funcion((yyvsp[-1].val));
			(yyval.token).cadena = (yyvsp[-3].lexema);
		}
		else{ /*La función no está en la TS, por lo que daremos un error por pantalla de que la función solicitada no se ha encontrado*/
			printf(RED"La función %s no se ha encontrado en la TS\n"RESET,(yyvsp[-3].lexema));
			setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
			(yyval.token).cadena = (yyvsp[-3].lexema);
			(yyval.token).contenido=NAN;
		}
	}
	else printf(RED"El argumento de la función no es un número o es una variable que no está definido\n"RESET);
	
	}
#line 1314 "calc.tab.c"
    break;

  case 21: /* exp: NUM  */
#line 170 "calc.y"
         { (yyval.val) = (yyvsp[0].val); }
#line 1320 "calc.tab.c"
    break;

  case 22: /* exp: VAR  */
#line 171 "calc.y"
          {
      	   	(yyvsp[0].token).contenido = recuperarContenidoVarCons((yyvsp[0].token).cadena); /*Pedimos a TS.c que nos devuelva el valor de la variable*/
      	   	int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
      	   	if (bandera == 1){ 
							/*La variable está en la TS y hemos recuperado su correspondiente valor*/
      	   		printf("Valor recuperado de %s en la TS -> %.2f\n",(yyvsp[0].token).cadena,(yyvsp[0].token).contenido);
      	   		(yyval.val)=(yyvsp[0].token).contenido;
      	   	}
      	   	else{ /*La variable no está en la TS, por lo que daremos un error por pantalla de que la variable solicitada no se ha encontrado*/
      	   		printf(RED"La variable %s no se ha encontrado en la TS\n"RESET,(yyvsp[0].token).cadena);
      	   		setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
      	   		(yyval.val)=NAN;
      	   	}
						free((yyvsp[0].token).cadena); /*Liberamos la memoria de la cadena que hemos usado*/
      	   }
#line 1340 "calc.tab.c"
    break;

  case 23: /* exp: CONS  */
#line 186 "calc.y"
                       {
      (yyvsp[0].token).contenido = recuperarContenidoVarCons((yyvsp[0].token).cadena); /*Pedimos a TS.c que nos devuelva el valor de la variable*/
			/*En el caso de que sea una constante, siempre entraremos aquí ya que las constantes siempre están en la TS
			*/
			printf("Valor recuperado de %s en la TS -> %.2f\n",(yyvsp[0].token).cadena,(yyvsp[0].token).contenido);
			(yyval.val)=(yyvsp[0].token).contenido;
			free((yyvsp[0].token).cadena); /*Liberamos la memoria de la cadena que hemos usado*/
		}
#line 1353 "calc.tab.c"
    break;

  case 24: /* exp: exp '+' exp  */
#line 194 "calc.y"
                  { (yyval.val) = (yyvsp[-2].val) + (yyvsp[0].val); }
#line 1359 "calc.tab.c"
    break;

  case 25: /* exp: exp '-' exp  */
#line 195 "calc.y"
                  { (yyval.val) = (yyvsp[-2].val) - (yyvsp[0].val); }
#line 1365 "calc.tab.c"
    break;

  case 26: /* exp: exp '*' exp  */
#line 196 "calc.y"
                  { (yyval.val) = (yyvsp[-2].val) * (yyvsp[0].val); }
#line 1371 "calc.tab.c"
    break;

  case 27: /* exp: exp '/' exp  */
#line 197 "calc.y"
                  {
										if((yyvsp[0].val)==0){
											printf(RED"No se puede dividir entre 0\n"RESET);
											(yyval.val)=NAN;
										}
										else (yyval.val) = (yyvsp[-2].val) / (yyvsp[0].val); 
									}
#line 1383 "calc.tab.c"
    break;

  case 28: /* exp: exp '%' exp  */
#line 204 "calc.y"
                              {
										if((yyvsp[0].val)==0){
											printf(RED"No se puede hacer el módulo entre 0\n"RESET);
											(yyval.val)=NAN;
										}
										else (yyval.val) = fmod((yyvsp[-2].val), (yyvsp[0].val)); 
									}
#line 1395 "calc.tab.c"
    break;

  case 29: /* exp: '-' exp  */
#line 211 "calc.y"
                        { (yyval.val) = -(yyvsp[0].val); }
#line 1401 "calc.tab.c"
    break;

  case 30: /* exp: exp '^' exp  */
#line 212 "calc.y"
                  { (yyval.val) = pow((yyvsp[-2].val), (yyvsp[0].val)); }
#line 1407 "calc.tab.c"
    break;

  case 31: /* exp: '(' exp ')'  */
#line 213 "calc.y"
                  { (yyval.val) = (yyvsp[-1].val); }
#line 1413 "calc.tab.c"
    break;


#line 1417 "calc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 216 "calc.y"


void yyerror(const char *s) {
    fprintf(stderr, RED"Error: %s\n"RESET, s);
}

int main() {
    initTS();
    printf("> ");
    yyparse(); 
    liberarTS(); /*Liberamos los recursos consumidos por la TS*/
		finalizarLexico(); /*Liberamos los recursos consumidos por el analizador lexico*/
    return 0;
}
