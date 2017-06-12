/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "compilador.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#include "compilador.h"

	int num_vars;
	extern char *yytext;
	controle_t *controle;
	tabela_simbolos_t *pilha_proc_func;


#line 80 "compilador.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
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
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    INTEGER = 270,
    NUMERO = 271,
    MAIS = 272,
    MENOS = 273,
    OR = 274,
    MULT = 275,
    DIV = 276,
    AND = 277,
    ELSE = 278,
    IF = 279,
    IGUAL = 280,
    THEN = 281,
    DIFF = 282,
    MAIOR = 283,
    MAIOR_IGUAL = 284,
    MENOR = 285,
    MENOR_IGUAL = 286,
    WHILE = 287,
    DO = 288,
    PROCEDURE = 289,
    FUNCTION = 290,
    READ = 291,
    WRITE = 292,
    GOTO = 293,
    LABEL = 294,
    BOOLEAN = 295,
    TRUE = 296,
    FALSE = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 174 "compilador.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    32,    32,    32,    51,    58,    61,    65,    74,    83,
      92,    83,    98,   102,   102,   106,   106,   113,   132,   136,
     112,   152,   170,   151,   186,   190,   185,   194,   198,   199,
     200,   204,   204,   206,   206,   211,   215,   228,   244,   249,
     249,   251,   255,   256,   260,   263,   260,   288,   293,   300,
     313,   328,   329,   334,   339,   340,   341,   344,   347,   346,
     376,   377,   378,   379,   380,   381,   382,   392,   406,   413,
     414,   418,   439,   446,   450,   458,   462,   467,   475,   484,
     495,   495,   506,   509,   514,   527,   539,   540,   541,   549,
     548,   570,   570,   606,   622,   621,   630,   634,   640,   648,
     651,   652,   652,   657,   657,   662,   662,   667,   667,   672,
     672,   677,   677,   685,   686,   687,   688,   692,   693,   694,
     695,   699,   704,   705,   706,   707,   712,   711,   783,   795,
     782,   811
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "INTEGER", "NUMERO",
  "MAIS", "MENOS", "OR", "MULT", "DIV", "AND", "ELSE", "IF", "IGUAL",
  "THEN", "DIFF", "MAIOR", "MAIOR_IGUAL", "MENOR", "MENOR_IGUAL", "WHILE",
  "DO", "PROCEDURE", "FUNCTION", "READ", "WRITE", "GOTO", "LABEL",
  "BOOLEAN", "TRUE", "FALSE", "$accept", "programa", "$@1", "bloco",
  "parte_declara_rotulos", "lista_rotulos", "parte_subrotinas", "$@2",
  "$@3", "procedimento_funcao", "$@4", "$@5", "funcao", "$@6", "$@7",
  "$@8", "procedimento", "$@9", "$@10", "parametros_formais_1", "$@11",
  "$@12", "parametros_formais_2", "parametros_formais_3", "$@13", "$@14",
  "parametros_formais_4", "lista_parametros", "parte_declara_vars", "var",
  "$@15", "declara_vars", "declara_var", "$@16", "$@17", "tipo",
  "lista_id_var", "lista_idents", "comando_composto", "comandos",
  "comando", "$@18", "comando_sem_rotulo", "desvio", "comando_leitura",
  "parametros_leitura", "identificador_leitura", "comando_escrita",
  "parametros_escrita", "comando_repetitivo", "apos_inicio_while",
  "apos_expressao_while", "apos_end_while", "comando_condicional", "$@19",
  "if", "apos_expressao_if", "apos_comandos_if", "else",
  "atribuicao_procedimento", "$@20", "atribuicao_procedimento_2", "$@21",
  "chamada_de_procedimento", "$@22", "lista_parametros_chamada",
  "expressao", "expressao_simples_2", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "expressao_simples_1", "termo", "fator",
  "variavel_funcao", "$@29", "chamada_de_funcao", "$@30", "$@31", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -185

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -185,    10,    13,  -185,     0,    20,    14,  -185,    50,    27,
      28,     6,  -185,    54,    51,    71,  -185,    60,  -185,    61,
    -185,   103,   106,  -185,   124,   100,  -185,  -185,    -1,  -185,
    -185,   102,   104,   125,  -185,   127,  -185,  -185,  -185,   133,
     137,   126,  -185,   132,   138,  -185,  -185,  -185,  -185,  -185,
    -185,   120,  -185,    61,   134,   135,  -185,  -185,    24,    15,
     141,     1,   139,     1,  -185,  -185,    -1,     1,   123,  -185,
    -185,  -185,  -185,  -185,   140,    -7,  -185,  -185,   136,  -185,
      44,     1,  -185,  -185,  -185,  -185,    56,    96,    65,  -185,
    -185,  -185,    72,  -185,    93,    56,  -185,    56,    52,  -185,
     147,   147,  -185,  -185,  -185,  -185,     1,     1,  -185,    21,
     150,     1,     1,     1,   122,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,     1,     1,     1,  -185,   139,  -185,     1,   130,
      -1,  -185,  -185,   151,   149,   152,   105,    56,    56,  -185,
    -185,  -185,    65,    65,    65,    12,     1,     1,     1,     1,
       1,     1,  -185,  -185,  -185,  -185,    56,    59,   153,    46,
       6,    -7,  -185,  -185,     1,     1,    -1,  -185,    56,    89,
      89,    89,    89,    89,    89,    -1,  -185,  -185,   148,  -185,
    -185,  -185,   154,  -185,   155,    56,   107,   157,  -185,   158,
    -185,  -185,   154,   156,  -185,    46,    55,   159,  -185,  -185,
    -185,  -185,    46,  -185,  -185,   160,    -7,  -185,     6,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,   163,  -185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    52,     0,     0,
       0,     6,    51,     0,     0,    41,     8,     0,     3,     9,
      38,     0,     0,     5,     0,    13,    44,     7,    56,     4,
      10,     0,     0,    40,    43,     0,    89,    58,    77,     0,
       0,     0,    63,     0,    55,    57,    64,    65,    66,    62,
      61,     0,    60,     9,     0,     0,    42,    50,     0,    96,
       0,     0,     0,     0,    67,    53,    56,     0,    88,    11,
      21,    14,    17,    16,     0,     0,    94,    90,     0,    93,
      80,     0,   126,   121,   124,   125,    78,   100,   116,   120,
     123,    71,     0,    70,     0,    74,    54,    84,    80,    81,
      27,    27,    49,    47,    48,    45,     0,     0,    59,     0,
     131,     0,     0,     0,     0,   101,   103,   105,   107,   109,
     111,    99,     0,     0,     0,    68,     0,    72,     0,     0,
      56,    87,    24,     0,     0,     0,     0,    98,    92,   122,
     128,   127,   113,   114,   115,    80,     0,     0,     0,     0,
       0,     0,   117,   118,   119,    69,    73,    80,     0,    30,
       6,     0,    46,    95,     0,     0,    56,    79,     0,   102,
     104,   106,   108,   110,   112,    56,    85,    53,    33,    31,
      25,    29,     0,    22,     0,    97,     0,     0,    76,     0,
      83,    28,     0,     0,    37,    30,     0,     0,    18,   129,
      53,    53,    30,    26,    34,     0,     0,    23,     6,   130,
      75,    82,    32,    36,    35,    19,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,  -156,  -185,  -185,   110,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,    64,
    -185,  -185,  -184,    -6,  -185,  -185,   -17,  -185,  -185,  -185,
    -185,  -185,   143,  -185,  -185,  -155,  -185,  -185,   161,   -66,
      26,  -185,   -78,  -185,  -185,  -185,    48,  -185,  -185,  -185,
    -185,  -185,   -23,  -185,  -185,  -185,  -185,   -22,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,    16,   -60,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,   -18,   -19,   -21,  -185,  -185,  -185,
    -185,  -185
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    17,    24,    25,    53,    30,
      31,    32,    73,   101,   208,   216,    71,   100,   197,   133,
     159,   193,   180,   181,   192,   182,   195,   196,    19,    20,
      21,    33,    34,    35,   135,   105,    58,     8,    42,    43,
      44,    60,    45,    46,    47,    92,    93,    48,    94,    49,
      61,   114,   188,    50,    51,    68,   129,   190,    99,    52,
      59,    77,    78,    79,   106,   136,   168,   121,   146,   147,
     148,   149,   150,   151,    87,    88,    89,    90,   110,   141,
     165,   209
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    86,   108,    95,   183,    81,   184,    97,   103,    28,
       3,   204,    36,     5,    82,    37,     4,    83,   212,    76,
     131,   109,   166,   -80,     6,    36,   139,     7,    37,   -91,
      74,    38,    75,   104,    11,    39,    40,    41,   111,   112,
     113,    12,    84,    85,    38,    13,   137,   138,    39,    40,
      41,   214,   215,   178,    28,     9,    10,    36,   179,   -33,
      18,   205,   130,   206,   158,    36,    22,    23,   156,   175,
      16,   -12,    36,   111,   112,   113,    38,   125,   126,   176,
      39,    40,    41,   -39,    38,   122,   123,   124,    39,    40,
      41,    38,   142,   143,   144,    39,    40,    41,   127,   128,
     187,   152,   153,   154,   185,   137,  -100,  -100,  -100,   189,
     163,   164,   199,   164,   115,    26,   116,   117,   118,   119,
     120,   115,    27,   116,   117,   118,   119,   120,   169,   170,
     171,   172,   173,   174,    28,   -15,    54,    62,   -44,    55,
      57,    63,    64,    65,    67,    66,    98,    70,    72,    80,
     107,   132,    91,   102,   140,   145,   157,   161,   160,   162,
     179,   203,   198,    69,   177,   134,   207,   194,   200,   201,
     217,   167,   191,   213,   155,   202,    56,   210,     0,   211,
       0,   186,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
      66,    61,    80,    63,   160,     4,   161,    67,    15,    10,
       0,   195,    13,    13,    13,    16,     3,    16,   202,     4,
      98,    81,    10,    24,     4,    13,     5,    13,    16,    14,
       6,    32,     8,    40,     7,    36,    37,    38,    17,    18,
      19,    13,    41,    42,    32,    39,   106,   107,    36,    37,
      38,   206,   208,     7,    10,     5,     6,    13,    12,    13,
       9,     6,    10,     8,   130,    13,     6,     7,   128,    10,
      16,    10,    13,    17,    18,    19,    32,     5,     6,   157,
      36,    37,    38,    12,    32,    20,    21,    22,    36,    37,
      38,    32,   111,   112,   113,    36,    37,    38,     5,     6,
     166,   122,   123,   124,   164,   165,    17,    18,    19,   175,
       5,     6,     5,     6,    25,    12,    27,    28,    29,    30,
      31,    25,    16,    27,    28,    29,    30,    31,   146,   147,
     148,   149,   150,   151,    10,    35,    34,     4,    13,    35,
      13,     4,    16,    11,    24,     7,    23,    13,    13,     8,
      14,     4,    13,    13,     4,    33,    26,     8,     7,     7,
      12,     5,     7,    53,    11,   101,     7,    13,    11,    11,
       7,   145,   178,    13,   126,   192,    33,   200,    -1,   201,
      -1,   165,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     3,    13,     4,    13,    80,     5,
       6,     7,    13,    39,    46,    47,    16,    48,     9,    71,
      72,    73,     6,     7,    49,    50,    12,    16,    10,    81,
      52,    53,    54,    74,    75,    76,    13,    16,    32,    36,
      37,    38,    81,    82,    83,    85,    86,    87,    90,    92,
      96,    97,   102,    51,    34,    35,    75,    13,    79,   103,
      84,    93,     4,     4,    16,    11,     7,    24,    98,    49,
      13,    59,    13,    55,     6,     8,     4,   104,   105,   106,
       8,     4,    13,    16,    41,    42,   109,   117,   118,   119,
     120,    13,    88,    89,    91,   109,    82,   109,    23,   101,
      60,    56,    13,    15,    40,    78,   107,    14,    85,   109,
     121,    17,    18,    19,    94,    25,    27,    28,    29,    30,
      31,   110,    20,    21,    22,     5,     6,     5,     6,    99,
      10,    85,     4,    62,    62,    77,   108,   109,   109,     5,
       4,   122,   118,   118,   118,    33,   111,   112,   113,   114,
     115,   116,   119,   119,   119,    89,   109,    26,    82,    63,
       7,     8,     7,     5,     6,   123,    10,    83,   109,   117,
     117,   117,   117,   117,   117,    10,    85,    11,     7,    12,
      65,    66,    68,    46,    78,   109,   108,    82,    95,    82,
     100,    66,    67,    64,    13,    69,    70,    61,     7,     5,
      11,    11,    69,     5,    65,     6,     8,     7,    57,   124,
      95,   100,    65,    13,    78,    46,    58,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    47,    47,    48,    48,    50,
      51,    49,    49,    53,    52,    54,    52,    56,    57,    58,
      55,    60,    61,    59,    63,    64,    62,    62,    65,    65,
      65,    67,    66,    68,    66,    69,    70,    70,    71,    73,
      72,    72,    74,    74,    76,    77,    75,    78,    78,    79,
      79,    80,    80,    81,    82,    82,    82,    83,    84,    83,
      85,    85,    85,    85,    85,    85,    85,    86,    87,    88,
      88,    89,    90,    91,    91,    92,    92,    93,    94,    95,
      97,    96,    98,    98,    99,   100,   101,   101,   101,   103,
     102,   105,   104,   104,   107,   106,   106,   108,   108,   109,
     110,   111,   110,   112,   110,   113,   110,   114,   110,   115,
     110,   116,   110,   117,   117,   117,   117,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   121,   120,   123,   124,
     122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     4,     3,     0,     3,     1,     0,
       0,     4,     0,     0,     3,     0,     3,     0,     0,     0,
      10,     0,     0,     7,     0,     0,     5,     0,     2,     1,
       0,     0,     4,     0,     3,     3,     3,     1,     1,     0,
       3,     0,     2,     1,     0,     0,     6,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     0,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     3,
       1,     1,     4,     3,     1,     9,     7,     0,     0,     0,
       0,     3,     8,     6,     0,     0,     4,     2,     0,     0,
       3,     0,     3,     1,     0,     4,     0,     3,     1,     2,
       0,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     3,     1,     1,     1,     0,     3,     0,     0,
       5,     0
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 32 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo (NULL, "INPP");
	}
#line 1425 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "compilador.y" /* yacc.c:1646  */
    {
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}
		geraCodigo (NULL, "PARA");
	}
#line 1439 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simbolo_t *simb = criaSimbolo(yytext, 0, controle->nivel_lexico, label, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
#line 1449 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simbolo_t *simb = criaSimbolo(yytext, 0, controle->nivel_lexico, label, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
#line 1459 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "compilador.y" /* yacc.c:1646  */
    {
		controle->nivel_lexico++;
		controle->deslocamento = 0;
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVS %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
#line 1472 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "compilador.y" /* yacc.c:1646  */
    {
		removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);
		controle->nivel_lexico--;
		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");
	}
#line 1482 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 102 "compilador.y" /* yacc.c:1646  */
    { controle->dentro_funcao++; }
#line 1488 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "compilador.y" /* yacc.c:1646  */
    { controle->dentro_funcao--; }
#line 1494 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "compilador.y" /* yacc.c:1646  */
    { controle->dentro_funcao++; }
#line 1500 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "compilador.y" /* yacc.c:1646  */
    { controle->dentro_funcao--; }
#line 1506 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Funcao '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, funcao, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);

		geraCodigo(controle->rotulo_aux, "NADA");
		sprintf(controle->saida, "ENPR %d", controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
#line 1526 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "compilador.y" /* yacc.c:1646  */
    {
		corrigeFuncao(controle->tabela_simbolos, controle->tipo, controle->numero_parametros);
	}
#line 1534 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "compilador.y" /* yacc.c:1646  */
    {
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}

		sprintf(controle->saida, "RTPR %d, %d", controle->nivel_lexico, numeroParametrosFuncProcTopo(controle->tabela_simbolos));
		geraCodigo(NULL, controle->saida);
	}
#line 1550 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 152 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Procedimento '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, procedimento, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);

		geraCodigo(controle->rotulo_aux, "NADA");
		sprintf(controle->saida, "ENPR %d", controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
#line 1570 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "compilador.y" /* yacc.c:1646  */
    {
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}

		sprintf(controle->saida, "RTPR %d, %d", controle->nivel_lexico, numeroParametrosFuncProcTopo(controle->tabela_simbolos));
		geraCodigo(NULL, controle->saida);
	}
#line 1586 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 186 "compilador.y" /* yacc.c:1646  */
    {
		controle->numero_parametros = 0;
	}
#line 1594 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 190 "compilador.y" /* yacc.c:1646  */
    {
		corrigeParametros(controle->tabela_simbolos, controle->tipo, controle->numero_parametros);
	}
#line 1602 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "compilador.y" /* yacc.c:1646  */
    { controle->referencia = 1; }
#line 1608 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 206 "compilador.y" /* yacc.c:1646  */
    { controle->referencia = 0; }
#line 1614 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Parametro '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		//deslocamento vai com 0 porque nesse ponto ainda não sabemos quantos parâmetros a função tem
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, parametro_formal, indefinido, NULL, 0, controle->referencia);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
		controle->numero_parametros++;
	}
#line 1631 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Parametro '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		//deslocamento vai com 0 porque nesse ponto ainda não sabemos quantos parâmetros a função tem
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, parametro_formal, indefinido, NULL, 0, controle->referencia);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
		controle->numero_parametros++;
	}
#line 1648 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 249 "compilador.y" /* yacc.c:1646  */
    { }
#line 1654 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 260 "compilador.y" /* yacc.c:1646  */
    { }
#line 1660 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "compilador.y" /* yacc.c:1646  */
    { /* AMEM */
		int contador = 0;
		int i = controle->tabela_simbolos->topo - 1;

		if (controle->tipo == indefinido) {
			sprintf(controle->saida, "Tipo de variavel invalido\n");
			imprimeErro(controle->saida);
		}

		printf("chegou aqui\n");

		//atualiza todos os símbolos que estão com seu tipo == indefinido
		while (i >= 0 && controle->tabela_simbolos->simbolos[i]->tipo == indefinido && controle->tabela_simbolos->simbolos[i]->categoria == variavel_simples) {
			controle->tabela_simbolos->simbolos[i]->tipo = controle->tipo;
			i--;
			contador++;
		}

		sprintf(controle->saida, "AMEM %d", contador);
		geraCodigo(NULL, controle->saida);
	}
#line 1686 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 289 "compilador.y" /* yacc.c:1646  */
    {
		controle->tipo = inteiro;
	}
#line 1694 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 294 "compilador.y" /* yacc.c:1646  */
    {
		controle->tipo = boolean;
	}
#line 1702 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 301 "compilador.y" /* yacc.c:1646  */
    {
		/* insere última vars na tabela de símbolos */
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Variavel '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		simb = criaSimbolo(yytext, controle->deslocamento++, controle->nivel_lexico, variavel_simples, indefinido, NULL, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
#line 1718 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 314 "compilador.y" /* yacc.c:1646  */
    {
		/* insere vars na tabela de símbolos */
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Variavel '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		simb = criaSimbolo(yytext, controle->deslocamento++, controle->nivel_lexico, variavel_simples, indefinido, NULL, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
#line 1734 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 347 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "Rotulo '%s' nao foi declarado.\n", yytext);
			imprimeErro(controle->saida);
		}

		geraCodigo(simb->rotulo, "NADA");

		int i = 0;
		int nl = 0;

		while (i < controle->tabela_simbolos->topo) {
			simb = controle->tabela_simbolos->simbolos[i];
			if (simb->categoria == variavel_simples && simb->nivel_lexico == controle->nivel_lexico) {
				nl++;
			}
			i++;
		}

		
		sprintf(controle->saida, "ENRT %d, %d", controle->nivel_lexico, nl);
		geraCodigo(NULL, controle->saida);
	}
#line 1763 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 393 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "Label '%s' nao foi declarado.\n", yytext);
			imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "DSVR %s, %d, %d", simb->rotulo, simb->nivel_lexico, controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
#line 1778 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 419 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "identificador '%s' nao declarado.", yytext);
			imprimeErro(controle->saida);
		}

		if (simb->categoria == variavel_simples || simb->categoria == funcao ||
				(simb->categoria == parametro_formal && !simb->referencia)) {
			sprintf(controle->saida, "ARMZ %d, %d", simb->nivel_lexico, simb->deslocamento);
		} else if (simb->categoria == parametro_formal && simb->referencia) {
			sprintf(controle->saida, "ARMI %d, %d", simb->nivel_lexico, simb->deslocamento);
		}

		geraCodigo(NULL, "LEIT");
		geraCodigo(NULL, controle->saida);
	}
#line 1800 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 447 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "IMPR");
	}
#line 1808 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 451 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "IMPR");
	}
#line 1816 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 467 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		geraCodigo(controle->rotulo_aux, "NADA");
	}
#line 1826 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 475 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVF %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
#line 1837 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 484 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = desempilhaRotulo(controle->rotulos);

		sprintf(controle->saida, "DSVS %s", desempilhaRotulo(controle->rotulos));
		geraCodigo(NULL, controle->saida);

		geraCodigo(controle->rotulo_aux, "NADA");
	}
#line 1850 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 495 "compilador.y" /* yacc.c:1646  */
    {
		controle->eh_booleana = 0;
	}
#line 1858 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 500 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");
	}
#line 1866 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "compilador.y" /* yacc.c:1646  */
    {
		if (controle->eh_booleana == 0) {
			sprintf(controle->saida, "Esperava expressao booleana.\n");
    		imprimeErro(controle->saida);
		}
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVF %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
#line 1881 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 527 "compilador.y" /* yacc.c:1646  */
    {
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		sprintf(controle->saida, "DSVS %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);

		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");

		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
	}
#line 1895 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 549 "compilador.y" /* yacc.c:1646  */
    {
		//primeira parte da atribuição verifica se o destino existe
		controle->destino = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);

		if (controle->destino == NULL) {
			sprintf(controle->saida, "Simbolo '%s' nao declarado.\n", yytext);
            imprimeErro(controle->saida);
		}

		//empilha sempre, mas só vai usar caso seja um procedimento
		simbolo_t *simb_aux = (simbolo_t *) malloc(sizeof(simbolo_t));
		memcpy(simb_aux, controle->destino, sizeof(simbolo_t));
    	insereTabelaSimbolos(controle->pilha_proc_func, simb_aux);
    	int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada = 0;
	}
#line 1916 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 570 "compilador.y" /* yacc.c:1646  */
    {
		controle->eh_booleana = 0;
		controle->tipo_ultima_operacao = indefinido; //na real eu acho que isso não é útil
	}
#line 1925 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 575 "compilador.y" /* yacc.c:1646  */
    {
		if (controle->destino->tipo == inteiro && controle->eh_booleana) {
			sprintf(controle->saida, "Atribuicao invalida. Destino eh um inteiro e encontrou expressao booleana.\n");
			imprimeErro(controle->saida);
		}

		if (controle->destino->tipo == boolean &&  controle->tipo_ultima_operacao == inteiro) {
			sprintf(controle->saida, "Atribuicao invalida. Destino eh um booleano e encontrou expressao aritmetica.\n");
			imprimeErro(controle->saida);
		}

		//se for variável simples OU uma função OU parâmetro formal passado por valor
		if (controle->destino->categoria == variavel_simples || (controle->destino->categoria == funcao && controle->dentro_funcao > 0) ||
					(controle->destino->categoria == parametro_formal && controle->destino->referencia == 0)) {
			sprintf(controle->saida, "ARMZ %d, %d", controle->destino->nivel_lexico, controle->destino->deslocamento);
			geraCodigo(NULL, controle->saida);
		//se for parâmetro formal passado por referência
		} else if (controle->destino->categoria == parametro_formal && controle->destino->referencia == 1) {
			sprintf(controle->saida, "ARMI %d, %d", controle->destino->nivel_lexico, controle->destino->deslocamento);
			geraCodigo(NULL, controle->saida);
		//se for um procedimento gera mensagem de erro
		} else if (controle->destino->categoria == procedimento) {
			sprintf(controle->saida, "Procedimento '%s' nao pode receber atribuição.\n", yytext);
			imprimeErro(controle->saida);
		}

		//nesse caso desempilha só para limpar, não vai ser usado porque não era um procedimento
		removeTabelaSimbolos(controle->pilha_proc_func);
	}
#line 1959 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 607 "compilador.y" /* yacc.c:1646  */
    {
		simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);

		if (simb->count_param_chamada != simb->numero_parametros) {
			sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, controle->numero_parametros, simb->numero_parametros);
            imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
        geraCodigo(NULL, controle->saida);
	}
#line 1975 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 622 "compilador.y" /* yacc.c:1646  */
    {
		controle->verificando_param_chamada_funcao++;
	}
#line 1983 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 627 "compilador.y" /* yacc.c:1646  */
    {
		controle->verificando_param_chamada_funcao--;
	}
#line 1991 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 635 "compilador.y" /* yacc.c:1646  */
    {
		int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada++;
	}
#line 2000 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 641 "compilador.y" /* yacc.c:1646  */
    {
		int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada++;
	}
#line 2009 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 652 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2015 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 654 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMIG");
	}
#line 2023 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 657 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2029 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 659 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMDG");
	}
#line 2037 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 662 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2043 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 664 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMMA");
	}
#line 2051 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 667 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2057 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 669 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMAG");
	}
#line 2065 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 672 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2071 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 674 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMME");
	}
#line 2079 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 677 "compilador.y" /* yacc.c:1646  */
    {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
#line 2085 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 679 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo(NULL, "CMEG");
	}
#line 2093 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 685 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "SOMA"); controle->tipo_ultima_operacao = inteiro; }
#line 2099 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 686 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "SUBT"); controle->tipo_ultima_operacao = inteiro; }
#line 2105 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 687 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "OR"); controle->tipo_ultima_operacao = inteiro; }
#line 2111 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 692 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "MULT"); controle->tipo_ultima_operacao = inteiro; }
#line 2117 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 693 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "DIVI"); controle->tipo_ultima_operacao = inteiro; }
#line 2123 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 694 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "AND"); controle->tipo_ultima_operacao = inteiro; }
#line 2129 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 700 "compilador.y" /* yacc.c:1646  */
    {
		sprintf(controle->saida, "CRCT %s", yytext);
		geraCodigo(NULL, controle->saida);
	}
#line 2138 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 706 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "CRCT 1"); controle->eh_booleana = 1; }
#line 2144 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 707 "compilador.y" /* yacc.c:1646  */
    { geraCodigo(NULL, "CRCT 0"); controle->eh_booleana = 1; }
#line 2150 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 712 "compilador.y" /* yacc.c:1646  */
    {
		controle->origem = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);

		//se não encontrou encerra o programa e imprime mensagem de variável não declarada
		if (controle->origem == NULL) {
			sprintf(controle->saida, "Variavel '%s' nao declarada.\n", yytext);
            		imprimeErro(controle->saida);
		}

		if (controle->origem->tipo == boolean) {
			controle->eh_booleana = 1;
		}

		//se está verificando os parâmetros de uma chamada de função e controle->origem não é uma função
		if (controle->verificando_param_chamada_funcao > 0 && controle->origem->categoria != funcao) {
			int i_func = controle->pilha_proc_func->topo - 1;
			int i_param = controle->pilha_proc_func->simbolos[i_func]->count_param_chamada;

			//se o parâmetro deve ser passado por referência
			if (controle->pilha_proc_func->simbolos[i_func]->parametros[i_param].referencia) {
				//se é uma variável simples, carrega endereço
				if (controle->origem->categoria == variavel_simples) {
					sprintf(controle->saida, "CREN %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por referência, carrega valor
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por valor, carrega endereço
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0) {
					sprintf(controle->saida, "CREN %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				}
			//se o parâmetro deve ser passado por valor
			} else {
				//se é uma variável simples, carrega endereço
				if (controle->origem->categoria == variavel_simples) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por referência, carrega valor
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia) {
					sprintf(controle->saida, "CRVI %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por valor, carrega endereço
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				}
			}
		//se controle->origem não for uma função
		} else if (controle->origem->categoria != funcao) {
			//se é uma variável simples OU parâmetro formal passado por valor
			if (controle->origem->categoria == variavel_simples || (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0)) {
				sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
				geraCodigo(NULL, controle->saida);
			//se for parâmetro formal passado por referência
			} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 1) {
				sprintf(controle->saida, "CRVI %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
				geraCodigo(NULL, controle->saida);
			//se for um procedimento gera mensagem de erro
			} else if (controle->origem->categoria == procedimento) {
				sprintf(controle->saida, "Procedimento '%s' nao pode ser atribuido a uma variavel ou funcao.\n", yytext);
	            imprimeErro(controle->saida);
	        }
		}
	}
#line 2221 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 783 "compilador.y" /* yacc.c:1646  */
    {
		controle->verificando_param_chamada_funcao++;

		//se for uma chamada de função com parâmetros, empilha a função e AMEM 1
		simbolo_t *simb_aux = (simbolo_t *) malloc(sizeof(simbolo_t));
		memcpy(simb_aux, controle->origem, sizeof(simbolo_t));
		insereTabelaSimbolos(controle->pilha_proc_func, simb_aux);
		sprintf(controle->saida, "AMEM 1");
		geraCodigo(NULL, controle->saida);
	}
#line 2236 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 795 "compilador.y" /* yacc.c:1646  */
    {
		controle->verificando_param_chamada_funcao--;
	}
#line 2244 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 798 "compilador.y" /* yacc.c:1646  */
    {
		//desempilha a função
		simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);
		
		if (simb->numero_parametros != simb->count_param_chamada) {
			sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, simb->numero_parametros, simb->count_param_chamada);
            imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
#line 2261 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 811 "compilador.y" /* yacc.c:1646  */
    {
		//função sem parâmetros, nem precisa empilhar, é só dar AMEM 1 e chamar
		if (controle->dentro_funcao == 0 && controle->origem->categoria == funcao) {

			sprintf(controle->saida, "AMEM 1");
    		geraCodigo(NULL, controle->saida);
			simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);
			if (simb->numero_parametros != simb->count_param_chamada) {
				sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, simb->numero_parametros, simb->count_param_chamada);
	            imprimeErro(controle->saida);
			}

			sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
			geraCodigo(NULL, controle->saida);
		//se está dentro de uma função e o símbolo é uma função, então trata a "variável" função			
		} else if (controle->dentro_funcao == 1 && controle->origem->categoria == funcao) {
			sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
			geraCodigo(NULL, controle->saida);
		}
	}
#line 2286 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 2290 "compilador.tab.c" /* yacc.c:1646  */
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
  return yyresult;
}
#line 834 "compilador.y" /* yacc.c:1906  */


main (int argc, char** argv) {
FILE* fp;
extern FILE* yyin;

	if (argc < 2 || argc > 2) {
		printf("usage compilador <arq>a %d\n", argc);
		return(-1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("usage compilador <arq>b\n");
		return(-1);
	}


/* -------------------------------------------------------------------
*  Inicia a Tabela de Símbolos
* ------------------------------------------------------------------- */

	controle = iniciaVariaveisControle();

	yyin=fp;
	yyparse();

	return 0;
}