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
#include "funcoes.h"

int n_vars_local, nivel_lexico, deslocamento, n_vars_global = 0, numVars, varsProc = 0;
int numeroRotulos, numeroParametros, proc_func = 0, i, flag = 0, flag1 = 0, chamadaProcedimento = 0, relation = 0, func = 0, parametrosChamada = 0, id_num;
char *rotulo_if, *rotulo_else, *rotulo_while, *rotulo_while2, *rotulo_procedimento, *rotulo_procedimento2, *rotulo_bloco, *labelName;

char procedureName[100], functionName[100], chr, idEsquerdo[100];

TTabela *tabela;
TSimbolo *simboloAux, *simboloAux1, *elementoEsquerdo;
TPilhaRotulos pilhaRotulos;
TPilhaTipos pilhaTipos;
TTipo tipo;
TParametro tipoParametros[100];


#define geraCodigoDMEM() \
    if (n_vars_global) { \
		geraCodigoArgumentos (NULL, "DMEM %d", n_vars_global); }


#line 94 "compilador.tab.c" /* yacc.c:339  */

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
    BOOLEAN = 271,
    SOMA = 272,
    SUBTRACAO = 273,
    MULTIPLICACAO = 274,
    DIVISAO = 275,
    OR = 276,
    AND = 277,
    MAIOR_QUE = 278,
    MENOR_QUE = 279,
    MAIOR_OU_IGUAL = 280,
    MENOR_OU_IGUAL = 281,
    IGUAL = 282,
    NUMERO = 283,
    IF = 284,
    THEN = 285,
    ELSE = 286,
    WHILE = 287,
    DO = 288,
    READ = 289,
    WRITE = 290,
    PROCEDURE = 291,
    FUNCTION = 292,
    LABEL = 293,
    GOTO = 294,
    TRUE = 295,
    FALSE = 296,
    LOWER_THAN_ELSE = 297
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

#line 188 "compilador.tab.c" /* yacc.c:358  */

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
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

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
       0,    47,    47,    47,    61,    62,    71,    77,    67,    87,
      90,    94,    95,   100,   108,   113,   112,   119,   122,   122,
     123,   123,   128,   126,   139,   137,   148,   149,   150,   154,
     165,   176,   184,   190,   196,   203,   204,   208,   220,   221,
     226,   227,   231,   232,   235,   236,   237,   238,   239,   240,
     241,   248,   246,   257,   267,   268,   269,   272,   273,   279,
     293,   277,   310,   311,   318,   332,   316,   348,   373,   380,
     348,   398,   398,   406,   414,   412,   423,   423,   435,   443,
     449,   454,   465,   474,   477,   482,   490,   500,   502,   507,
     517,   517,   539,   537,   548,   552,   552,   578,   586,   588,
     591,   598,   607,   608,   609,   610,   611,   616,   639,   642,
     648,   654,   660,   666,   669,   675,   681,   687,   692,   704,
     708,   710,   714,   722,   733,   731,   742,   759,   742,   770,
     785,   797,   783,   815,   822,   830,   820,   854,   861
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "INTEGER", "BOOLEAN",
  "SOMA", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "OR", "AND",
  "MAIOR_QUE", "MENOR_QUE", "MAIOR_OU_IGUAL", "MENOR_OU_IGUAL", "IGUAL",
  "NUMERO", "IF", "THEN", "ELSE", "WHILE", "DO", "READ", "WRITE",
  "PROCEDURE", "FUNCTION", "LABEL", "GOTO", "TRUE", "FALSE",
  "LOWER_THAN_ELSE", "$accept", "programa", "$@1", "entrada", "bloco",
  "$@2", "$@3", "declara_labels", "labels", "label", "parte_declara_vars",
  "var", "$@4", "declara_vars", "$@5", "$@6", "declara_var", "$@7",
  "conjunto_variaveis", "$@8", "mais_variaveis", "tipo", "tipo_retorno",
  "lista_id_var", "variavel", "lista_idents", "comando_composto",
  "comandos", "comando", "chamada_label", "$@9", "goto",
  "procedimentos_funcoes", "funcoes", "funcao", "$@10", "$@11",
  "procedimentos", "procedimento", "$@12", "$@13", "bloco_proc_func",
  "$@14", "$@15", "$@16", "parametros_procedimento", "$@17",
  "conjunto_parametros", "$@18", "$@19", "lista_parametros", "parametro",
  "leitura", "imprime", "parametros_leitura", "parametros_imprime",
  "parametro_imprime", "atribuicao", "$@20", "atribuicao_procedimento",
  "$@21", "atrib_proc", "$@22", "chamada_procedimento",
  "parametros_chamada", "relacao", "expressao", "expressao_simples",
  "termo", "fator", "booleano", "funcao_variavel", "$@23", "verifica",
  "$@24", "$@25", "repeticao", "$@26", "$@27", "condicional", "if_then",
  "$@28", "$@29", "cond_else", YY_NULLPTR
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

#define YYPACT_NINF -184

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-184)))

#define YYTABLE_NINF -127

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -184,    24,    27,  -184,    44,    41,    48,    60,  -184,     5,
      63,  -184,    89,    58,    95,    91,  -184,  -184,    14,  -184,
    -184,  -184,  -184,  -184,    58,  -184,  -184,    15,  -184,  -184,
      93,    96,    98,  -184,    70,  -184,    72,  -184,    93,  -184,
    -184,  -184,     9,  -184,  -184,  -184,    21,  -184,  -184,  -184,
      93,    93,  -184,   105,    97,    30,  -184,  -184,  -184,  -184,
     109,   110,    87,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,    85,  -184,    93,  -184,     3,  -184,   113,  -184,
       2,  -184,   104,   111,    -1,    -1,   107,   112,  -184,    21,
    -184,  -184,  -184,  -184,  -184,   115,   116,    39,   118,    30,
    -184,  -184,   114,  -184,   120,    30,    -1,  -184,  -184,  -184,
    -184,  -184,    66,  -184,     6,  -184,  -184,  -184,  -184,    32,
    -184,    73,  -184,  -184,  -184,  -184,    61,    83,    20,  -184,
      -1,     1,  -184,  -184,   122,   125,   100,    -1,    -1,    -1,
      -1,  -184,  -184,  -184,  -184,  -184,    -1,    -1,    -1,    -1,
      99,  -184,   121,  -184,   112,  -184,    63,  -184,  -184,   123,
    -184,    68,  -184,  -184,  -184,  -184,   124,  -184,  -184,    92,
    -184,  -184,  -184,   129,    21,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,    21,  -184,  -184,    91,    83,  -184,    83,
       3,  -184,  -184,    -1,    -1,  -184,  -184,  -184,    69,  -184,
    -184,  -184,  -184,    94,    15,     3,  -184,  -184,  -184,  -184,
      21,   128,  -184
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     5,     0,     0,    39,     0,
      10,     4,     0,     0,     0,    17,    38,    13,     0,    11,
       3,    15,     6,    14,     0,     9,    20,    56,    12,    16,
       0,     0,     0,     7,    55,    58,    54,    63,     0,    37,
      21,    22,     0,    36,    64,    59,     0,    57,    62,    19,
      28,     0,    24,    71,    71,     0,    92,    51,   134,   130,
       0,     0,     0,     8,    40,    50,    49,    45,    46,    44,
      48,    47,   138,    27,    23,    35,     0,    65,     0,    60,
       0,    43,    95,     0,     0,     0,     0,     0,    53,     0,
     133,    26,    31,    29,    30,     0,     0,    76,     0,     0,
      41,    94,     0,    93,    99,     0,     0,   124,   118,   122,
     123,   135,   108,   113,   117,   119,   120,   131,    86,     0,
      89,     0,    88,   137,    25,    67,     0,     0,     0,    42,
       0,     0,    96,    52,     0,   129,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,    83,     0,    84,     0,    66,    10,    72,    74,     0,
      81,     0,    80,    34,    32,    33,     0,    91,    98,     0,
     101,   121,   125,     0,     0,   109,   110,   111,   112,   107,
     114,   115,   116,     0,    85,    87,    17,     0,    82,     0,
       0,    67,    97,     0,     0,   136,   132,    68,     0,    79,
      77,    61,   100,     0,    56,     0,   127,    69,    75,   128,
       0,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -184,  -184,  -184,   -19,  -184,   117,
     -48,  -184,  -184,  -184,  -184,  -184,   101,  -184,   -42,  -184,
    -184,  -183,  -184,  -184,   102,  -184,   -89,  -184,   -51,  -184,
    -184,  -184,   -64,  -184,   108,  -184,  -184,  -184,   119,  -184,
    -184,   -47,  -184,  -184,  -184,   103,  -184,  -184,  -184,  -184,
     -44,   -43,  -184,  -184,  -184,  -184,    -9,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,   -46,  -184,   -83,  -184,   -67,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    14,    27,    46,    15,    18,    19,
      22,    23,    26,    29,    38,    30,    40,    50,    41,    76,
      74,    95,   166,    42,    43,     9,    63,    80,    64,    65,
      83,    66,    33,    34,    35,    54,    98,    36,    37,    53,
      96,   155,   156,   204,   210,    77,    78,   126,   187,   127,
     161,   162,    67,    68,   119,   121,   122,   101,   102,    69,
      82,   103,   104,   132,   169,   146,   170,   112,   113,   114,
     115,   116,   135,   172,   173,   209,    70,    85,   150,    71,
      72,    84,   136,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   111,   117,   106,    81,   106,   168,   200,    73,    99,
      11,    12,   107,   100,   107,    51,    92,    52,    93,    94,
      24,    25,   208,   134,     3,   147,   148,   108,   149,   108,
       4,    55,    91,   163,    56,   164,   165,   151,   152,   109,
     110,   109,   110,    56,   -78,     6,   -78,   167,   129,    57,
      58,    31,    32,    59,   133,    60,    61,     5,    57,    58,
      62,     8,    59,   179,    60,    61,   157,    10,   158,    62,
     175,   176,   177,   178,   189,   189,   190,   205,   153,   154,
     180,   181,   182,   137,   138,   195,    17,   139,   140,   141,
     142,   143,   144,   145,   196,   159,   160,   192,   193,   206,
     193,    13,    16,    21,    20,   -73,    39,    32,    31,    44,
     202,    45,   -73,    86,    87,    88,    89,    97,   -90,   105,
     118,   211,   124,   125,   131,   120,   128,   171,   130,  -126,
     174,   191,   183,   194,   184,   212,   188,   186,   197,    49,
     207,    28,    47,   198,   201,   185,   199,     0,   203,     0,
       0,     0,     0,    75,     0,    48,     0,    79
};

static const yytype_int16 yycheck[] =
{
      89,    84,    85,     4,    55,     4,     5,   190,    50,     7,
       5,     6,    13,    11,    13,     6,    13,     8,    15,    16,
       6,     7,   205,   106,     0,    19,    20,    28,    22,    28,
       3,    10,    74,    13,    13,    15,    16,     5,     6,    40,
      41,    40,    41,    13,     5,     4,     7,   130,    99,    28,
      29,    36,    37,    32,   105,    34,    35,    13,    28,    29,
      39,    13,    32,   146,    34,    35,     5,     7,     7,    39,
     137,   138,   139,   140,     6,     6,     8,     8,     5,     6,
     147,   148,   149,    17,    18,   174,    28,    21,    22,    23,
      24,    25,    26,    27,   183,    12,    13,     5,     6,     5,
       6,    38,    13,    12,     9,     8,    13,    37,    36,    13,
     193,    13,     7,     4,     4,    28,    31,     4,    14,     8,
      13,   210,     7,     7,     4,    13,     8,     5,    14,     4,
      30,     7,    33,     4,    13,     7,    13,   156,   186,    38,
     204,    24,    34,   187,   191,   154,   189,    -1,   194,    -1,
      -1,    -1,    -1,    51,    -1,    36,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     3,    13,     4,    46,    13,    68,
       7,     5,     6,    38,    47,    50,    13,    28,    51,    52,
       9,    12,    53,    54,     6,     7,    55,    48,    52,    56,
      58,    36,    37,    75,    76,    77,    80,    81,    57,    13,
      59,    61,    66,    67,    13,    13,    49,    77,    81,    59,
      60,     6,     8,    82,    78,    10,    13,    28,    29,    32,
      34,    35,    39,    69,    71,    72,    74,    95,    96,   102,
     119,   122,   123,    61,    63,    67,    62,    88,    89,    88,
      70,    71,   103,    73,   124,   120,     4,     4,    28,    31,
     126,    61,    13,    15,    16,    64,    83,     4,    79,     7,
      11,   100,   101,   104,   105,     8,     4,    13,    28,    40,
      41,   109,   110,   111,   112,   113,   114,   109,    13,    97,
      13,    98,    99,    69,     7,     7,    90,    92,     8,    71,
      14,     4,   106,    71,   109,   115,   125,    17,    18,    21,
      22,    23,    24,    25,    26,    27,   108,    19,    20,    22,
     121,     5,     6,     5,     6,    84,    85,     5,     7,    12,
      13,    93,    94,    13,    15,    16,    65,   109,     5,   107,
     109,     5,   116,   117,    30,   111,   111,   111,   111,   109,
     111,   111,   111,    33,    13,    99,    50,    91,    13,     6,
       8,     7,     5,     6,     4,    69,    69,    53,    93,    94,
      64,    84,   109,   107,    86,     8,     5,    75,    64,   118,
      87,    69,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    48,    49,    47,    50,
      50,    51,    51,    52,    53,    55,    54,    54,    57,    56,
      58,    56,    60,    59,    62,    61,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    73,    72,    74,    75,    75,    75,    76,    76,    78,
      79,    77,    80,    80,    82,    83,    81,    85,    86,    87,
      84,    89,    88,    88,    91,    90,    92,    90,    90,    93,
      93,    94,    94,    95,    96,    97,    97,    98,    98,    99,
     101,   100,   103,   102,   104,   105,   104,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   113,   115,   114,   117,   118,   116,   116,
     120,   121,   119,   122,   124,   125,   123,   126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     3,     0,     0,     0,     6,     3,
       0,     1,     3,     1,     1,     0,     3,     0,     0,     3,
       0,     2,     0,     3,     0,     5,     2,     1,     0,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     2,     1,     1,     0,     2,     1,     0,
       0,     9,     2,     1,     0,     0,     7,     0,     0,     0,
       8,     0,     4,     0,     0,     6,     0,     4,     0,     3,
       1,     1,     2,     4,     4,     3,     1,     3,     1,     1,
       0,     3,     0,     3,     1,     0,     2,     3,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     0,     3,     0,     0,     5,     0,
       0,     0,     6,     2,     0,     0,     6,     2,     0
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
#line 47 "compilador.y" /* yacc.c:1646  */
    {
                geraCodigo (NULL, "INPP");
             }
#line 1433 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "compilador.y" /* yacc.c:1646  */
    {
                 geraCodigoDMEM();
                 geraCodigo(NULL,"PARA");
             }
#line 1442 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "compilador.y" /* yacc.c:1646  */
    {
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }
#line 1450 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "compilador.y" /* yacc.c:1646  */
    {
                rotulo_bloco = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_bloco, "NADA");
            }
#line 1459 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 101 "compilador.y" /* yacc.c:1646  */
    {
            geraRotulo(&numeroRotulos, &pilhaRotulos);
            labelName = desempilhaRotulo(&pilhaRotulos);
            insereRT(tabela, token, nivel_lexico, labelName);
        }
#line 1469 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "compilador.y" /* yacc.c:1646  */
    {
                deslocamento=0; numVars=0;
                if (proc_func)
                    varsProc = 0;
            }
#line 1479 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 122 "compilador.y" /* yacc.c:1646  */
    { n_vars_local = 0; }
#line 1485 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "compilador.y" /* yacc.c:1646  */
    { n_vars_local = 0; }
#line 1491 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 128 "compilador.y" /* yacc.c:1646  */
    {
				n_vars_local = 0;
            }
#line 1499 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "compilador.y" /* yacc.c:1646  */
    {
                atualizaDeslocamento (tabela, numVars);
                geraCodigoArgumentos(NULL, "AMEM %d", n_vars_local); /* AMEM */
            }
#line 1508 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "compilador.y" /* yacc.c:1646  */
    {
                atualizaTipos(tabela, T_INTEGER, n_vars_local);
                if (proc_func){
                    for (i = 0; i < n_vars_local; i++){
                        tipoParametros[i].tipo = T_INTEGER;
                    }
                }
            }
#line 1521 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "compilador.y" /* yacc.c:1646  */
    {
                atualizaTipos(tabela, T_BOOLEAN, n_vars_local);
                if (proc_func){
                    for (i = 0; i < n_vars_local; i++){
                        tipoParametros[i].tipo = T_BOOLEAN;
                    }
                }
            }
#line 1534 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "compilador.y" /* yacc.c:1646  */
    {
                atualizaTipos(tabela, T_UNKNOWN, n_vars_local);
            }
#line 1542 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 186 "compilador.y" /* yacc.c:1646  */
    {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }
#line 1550 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "compilador.y" /* yacc.c:1646  */
    {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }
#line 1558 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "compilador.y" /* yacc.c:1646  */
    {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }
#line 1566 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 209 "compilador.y" /* yacc.c:1646  */
    {
                n_vars_local++; numVars++;
                if (proc_func)
                    varsProc++;
                if (proc_func == 0)
                    n_vars_global++;
                if (insereVS(tabela, token, nivel_lexico, T_VALOR))
                    exit (1);
            }
#line 1580 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 248 "compilador.y" /* yacc.c:1646  */
    {
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraCodigoArgumentos(simboloAux->rotulo, "ENRT %d %d", nivel_lexico, n_vars_local);
            }
#line 1589 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 258 "compilador.y" /* yacc.c:1646  */
    {
            simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
            geraCodigoArgumentos(NULL, "DSVR %s, %d, %d", simboloAux->rotulo, simboloAux->nivel_lexico, nivel_lexico);
            //geraCodigoDesvio("DSVR", simboloAux->rotulo, simboloAux->nivel_lexico, nivel_lexico);
        }
#line 1599 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "compilador.y" /* yacc.c:1646  */
    {
                proc_func = 1;
                func = 1;
                strcpy (procedureName, token);
                nivel_lexico++;
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if (insereFN(tabela, procedureName, nivel_lexico, rotulo_procedimento))
                    exit(1);
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
            }
#line 1615 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 293 "compilador.y" /* yacc.c:1646  */
    {
                atualizaProcedimento(tabela, procedureName, nivel_lexico, numeroParametros, tipoParametros);
                if (numeroParametros)
                    atualizaDeslocamentoParametros(tabela, numeroParametros);
            }
#line 1625 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 303 "compilador.y" /* yacc.c:1646  */
    {
                proc_func = 0;
                func = 0;
            }
#line 1634 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 318 "compilador.y" /* yacc.c:1646  */
    {
                proc_func = 1;
                strcpy (procedureName, token);
                nivel_lexico++;
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if (inserePR(tabela, procedureName, nivel_lexico, rotulo_procedimento)){
                    exit(1);
                };
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
            }
#line 1650 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 332 "compilador.y" /* yacc.c:1646  */
    {
                atualizaProcedimento(tabela, procedureName, nivel_lexico, numeroParametros, tipoParametros);
                if (numeroParametros)
                    atualizaDeslocamentoParametros(tabela, numeroParametros);
            }
#line 1660 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 341 "compilador.y" /* yacc.c:1646  */
    {
                proc_func = 0;
            }
#line 1668 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 348 "compilador.y" /* yacc.c:1646  */
    {
                /*  DESVIA SEMPRE       */
                rotulo_procedimento2 = desempilhaRotulo(&pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if ((strcmp(rotulo_procedimento, "R00") == 0) && (flag == 0)){
                    flag = 1;
                    geraCodigoArgumentos (NULL, "DSVS %s", rotulo_procedimento);
                }
                else{
                    if ((strcmp(rotulo_procedimento, "R00") != 0) && (flag == 1)){
                        geraCodigoArgumentos (NULL, "DSVS %s", rotulo_procedimento);
                    }
                }
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento2);

                /*  GERA ROTULO E ENTRA PROCEDIMENTO */
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos(rotulo_procedimento, "ENPR %d", nivel_lexico);
            }
#line 1693 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 373 "compilador.y" /* yacc.c:1646  */
    {
                atualizaNumVarsLocal (tabela, procedureName, varsProc);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }
#line 1702 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 380 "compilador.y" /* yacc.c:1646  */
    {
                rotulo_bloco = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_bloco, "NADA");
            }
#line 1711 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 387 "compilador.y" /* yacc.c:1646  */
    {
                simboloAux = procuraSimbolo(tabela, procedureName, nivel_lexico, 1);
                if (simboloAux->nVarsLocal)
                    geraCodigoArgumentos (NULL, "DMEM %d", simboloAux->nVarsLocal);
                geraCodigoArgumentos (NULL, "RTPR %d, %d", nivel_lexico, numeroParametros);
                nivel_lexico--;
            }
#line 1723 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 398 "compilador.y" /* yacc.c:1646  */
    {
                numeroParametros = 0;
            }
#line 1731 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 414 "compilador.y" /* yacc.c:1646  */
    {
                n_vars_local = 0;
            }
#line 1739 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 423 "compilador.y" /* yacc.c:1646  */
    {
                n_vars_local = 0;
            }
#line 1747 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 429 "compilador.y" /* yacc.c:1646  */
    {
                //atualiza tipos
            }
#line 1755 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 456 "compilador.y" /* yacc.c:1646  */
    {
                n_vars_local++;
                numeroParametros++;
                inserePF(tabela, token, nivel_lexico, T_VALOR);
                tipoParametros[numeroParametros-1].passagem = T_VALOR;
            }
#line 1766 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 466 "compilador.y" /* yacc.c:1646  */
    {
                n_vars_local++;
                numeroParametros++;
                inserePF(tabela, token, nivel_lexico, T_REFERENCIA);
                tipoParametros[numeroParametros-1].passagem = T_REFERENCIA;
            }
#line 1777 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 484 "compilador.y" /* yacc.c:1646  */
    {
                geraCodigo (NULL, "LEIT");
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraArmazena (*simboloAux);
            }
#line 1787 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 492 "compilador.y" /* yacc.c:1646  */
    {
                geraCodigo (NULL, "LEIT");
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraArmazena (*simboloAux);

            }
#line 1798 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 509 "compilador.y" /* yacc.c:1646  */
    {
                simboloAux = procuraSimbolo(tabela, token,nivel_lexico, proc_func);
                geraCarregaValor(*simboloAux);
                geraCodigo (NULL, "IMPR");
            }
#line 1808 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 517 "compilador.y" /* yacc.c:1646  */
    {
                elementoEsquerdo = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, proc_func);
                if (elementoEsquerdo == NULL){
                    printf ("Erro, variável não encontrada na Tabela de Símbolos\n");
                    exit(1);
                }
                empilhaTipo(&pilhaTipos, elementoEsquerdo->tipo);
            }
#line 1821 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 528 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_ATRIBUICAO))
                    exit(1);
                geraArmazena(*elementoEsquerdo);
            }
#line 1831 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 539 "compilador.y" /* yacc.c:1646  */
    {
                strcpy (idEsquerdo, token);
            }
#line 1839 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 552 "compilador.y" /* yacc.c:1646  */
    {
                chamadaProcedimento = 1;
                elementoEsquerdo = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, 1);
                if (elementoEsquerdo == NULL){
                    printf ("Erro, procedimento/funcao não encontrado na Tabela de Símbolos\n");
                    exit(1);
                }
            }
#line 1852 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 563 "compilador.y" /* yacc.c:1646  */
    {
                strcpy(rotulo_procedimento, elementoEsquerdo->rotulo);
                if (numeroRotulos > 9){
                    geraCodigoArgumentos (NULL, "CHPR R%c%c, %d", rotulo_procedimento[1], rotulo_procedimento[2], nivel_lexico);
                }
                else{
                    geraCodigoArgumentos (NULL, "CHPR R0%c, %d", rotulo_procedimento[2], nivel_lexico);
                }
                chamadaProcedimento = 0;
            }
#line 1867 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 592 "compilador.y" /* yacc.c:1646  */
    {
            if (flag1){
                parametrosChamada++;
                verificaAssinatura(*simboloAux, *simboloAux1, parametrosChamada, id_num);
                }
            }
#line 1878 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 599 "compilador.y" /* yacc.c:1646  */
    {
            if (flag1){
                parametrosChamada++;
                verificaAssinatura(*simboloAux, *simboloAux1, parametrosChamada, id_num);
                }
            }
#line 1889 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 607 "compilador.y" /* yacc.c:1646  */
    {  relation = 0; }
#line 1895 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 608 "compilador.y" /* yacc.c:1646  */
    { relation = 1; }
#line 1901 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 609 "compilador.y" /* yacc.c:1646  */
    { relation = 2; }
#line 1907 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 610 "compilador.y" /* yacc.c:1646  */
    { relation = 3; }
#line 1913 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 611 "compilador.y" /* yacc.c:1646  */
    {  relation = 4; }
#line 1919 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 617 "compilador.y" /* yacc.c:1646  */
    {
                switch (relation){
                    case 0:
                        geraCodigo(NULL,"CMMA");
                    break;
                    case 1:
                        geraCodigo(NULL,"CMME");
                    break;
                    case 2:
                        geraCodigo(NULL,"CMAG");
                    break;
                    case 3:
                        geraCodigo(NULL,"CMEG");
                    break;
                    case 4:
                        geraCodigo(NULL,"CMIG");
                    break;
                }

                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
            }
#line 1946 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 643 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "SOMA");
			}
#line 1956 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 649 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "SUBT");
            }
#line 1966 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 655 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "OR");
            }
#line 1976 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 661 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "AND");
            }
#line 1986 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 670 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "MULT");
            }
#line 1996 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 676 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "DIVI");
            }
#line 2006 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 682 "compilador.y" /* yacc.c:1646  */
    {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "AND");
            }
#line 2016 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 694 "compilador.y" /* yacc.c:1646  */
    {
                empilhaTipo(&pilhaTipos, T_INTEGER);
                geraCodigoArgumentos(NULL, "CRCT %d", atoi(token));
                if (flag1){
                    id_num = 0;
                }
            }
#line 2028 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 715 "compilador.y" /* yacc.c:1646  */
    {
				geraCodigo(NULL, "CRCT 1");
				empilhaTipo(&pilhaTipos, T_BOOLEAN);
			}
#line 2037 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 723 "compilador.y" /* yacc.c:1646  */
    {
				geraCodigo(NULL, "CRCT 0");
				empilhaTipo(&pilhaTipos, T_BOOLEAN);
			}
#line 2046 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 733 "compilador.y" /* yacc.c:1646  */
    {
                strcpy(idEsquerdo, token);
            }
#line 2054 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 742 "compilador.y" /* yacc.c:1646  */
    {
                simboloAux1 = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, 1);
                //GERA CODIGO AMEM SE FOR FUNCAO
                if (simboloAux1->categoria == FUNCAO){
                    empilhaTipo(&pilhaTipos, simboloAux1->tipo);
                    geraCodigo(NULL, "AMEM 1");
                }
                flag1 = 1;
                parametrosChamada = 0;
            }
#line 2069 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 759 "compilador.y" /* yacc.c:1646  */
    {
                flag1 = 0;
            }
#line 2077 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 763 "compilador.y" /* yacc.c:1646  */
    {
                strcpy(rotulo_procedimento, simboloAux1->rotulo);
                geraCodigoArgumentos (NULL, "CHPR R0%c, %d", rotulo_procedimento[2], nivel_lexico);
            }
#line 2086 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 770 "compilador.y" /* yacc.c:1646  */
    {
                simboloAux = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, proc_func);
                if (flag1){
                    id_num = 1;
                }
                else{
                    geraCarregaValor(*simboloAux);
                }
                empilhaTipo(&pilhaTipos, simboloAux->tipo);
            }
#line 2101 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 785 "compilador.y" /* yacc.c:1646  */
    {
                /*  GERA DOIS ROTULOS           */
                /*  ESCREVE ROTULO INICIO WHILE */
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                geraCodigo (rotulo_while, "NADA");
                empilhaRotulo(&pilhaRotulos, rotulo_while);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }
#line 2115 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 797 "compilador.y" /* yacc.c:1646  */
    {
                /*  DESVIA SE FALSO */
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVF %s", rotulo_while);
                empilhaRotulo(&pilhaRotulos, rotulo_while);
            }
#line 2126 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 806 "compilador.y" /* yacc.c:1646  */
    {
                /*  ESCREVE ROTULO FIM DO WHILE */
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                rotulo_while2 = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVS %s", rotulo_while2);
                geraCodigo (rotulo_while, "NADA");
            }
#line 2138 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 822 "compilador.y" /* yacc.c:1646  */
    {
                /*  GERA DOIS ROTULOS   */
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }
#line 2148 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 830 "compilador.y" /* yacc.c:1646  */
    {   /*  DESVIA SE FALSO */
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVF %s", rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_if);
            }
#line 2158 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 838 "compilador.y" /* yacc.c:1646  */
    {
                /*  DESVIA SEMPRE   */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVS %s", rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_else);

                /*  ESCREVE ROTULO DO IF    */
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_if, "NADA");
            }
#line 2175 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 855 "compilador.y" /* yacc.c:1646  */
    {
                /*  ESCREVE ROTULO DO ELSE  */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_else, "NADA");
            }
#line 2185 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 863 "compilador.y" /* yacc.c:1646  */
    {
                /*  DESEMPILHA ROTULO DESNECESSARIO DO ELSE  */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_else, "NADA");
            }
#line 2195 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 2199 "compilador.tab.c" /* yacc.c:1646  */
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
#line 870 "compilador.y" /* yacc.c:1906  */


main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }
/* -------------------------------------------------------------------
 *  Inicia Pilhas Auxiliares
 * ------------------------------------------------------------------- */

  iniciaPilhaRotulos(&pilhaRotulos);
  iniciaPilhaTipos(&pilhaTipos);

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */

 tabela = malloc (sizeof(TTabela));
 tabela->primeiro = tabela->ultimo = NULL;

 /* ------------------------------------------------------------------- */


   yyin=fp;
   yyparse();

   return 0;
}
