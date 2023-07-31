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
#line 1 "parser.y"

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include "node_types.h"
  #include "lex.yy.c"

  void yyerror(const char *s);
  int yylex();
  int yywrap();
  struct ExpressionNode *makeZeroExpressionNode();

  struct ProgramNode *head;


#line 87 "y.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IMPORT = 258,
    NAMESPACE = 259,
    STRUCT = 260,
    SELF = 261,
    TRUE = 262,
    FALSE = 263,
    TEXT = 264,
    LOGICAL = 265,
    NUMBERTOKEN = 266,
    VOID = 267,
    RETURN = 268,
    NUMBER = 269,
    SINGLEQUOTEDSTRING = 270,
    DOUBLEQUOTEDSTRING = 271,
    ID = 272,
    PLUS = 273,
    MINUS = 274,
    TIMES = 275,
    DIVIDE = 276,
    EQ = 277,
    NEQ = 278,
    LT = 279,
    GT = 280,
    LE = 281,
    GE = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    ASSIGN = 286,
    COMMA = 287,
    SEMICOLON = 288,
    COLON = 289,
    QUESTION = 290,
    DOT = 291,
    OPENPAREN = 292,
    CLOSEPAREN = 293,
    OPENCURLY = 294,
    CLOSECURLY = 295
  };
#endif
/* Tokens.  */
#define IMPORT 258
#define NAMESPACE 259
#define STRUCT 260
#define SELF 261
#define TRUE 262
#define FALSE 263
#define TEXT 264
#define LOGICAL 265
#define NUMBERTOKEN 266
#define VOID 267
#define RETURN 268
#define NUMBER 269
#define SINGLEQUOTEDSTRING 270
#define DOUBLEQUOTEDSTRING 271
#define ID 272
#define PLUS 273
#define MINUS 274
#define TIMES 275
#define DIVIDE 276
#define EQ 277
#define NEQ 278
#define LT 279
#define GT 280
#define LE 281
#define GE 282
#define AND 283
#define OR 284
#define NOT 285
#define ASSIGN 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define QUESTION 290
#define DOT 291
#define OPENPAREN 292
#define CLOSEPAREN 293
#define OPENCURLY 294
#define CLOSECURLY 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

  char *tokenText;
  struct IdentifierTextNode *identifierText;
  struct IdentifierNode *identifier;
  struct ImportsNode *imports;
  struct MultiplyExpressionNode *multiplyExpression;
  struct ExpressionNode *expression;
  struct BooleanExpressionNode *booleanExpression;
  struct TypeNode *type;
  struct VariableDeclarationNode *variableDeclaration;
  struct VariableDefinitionNode *variableDefinition;
  struct VariableAssignmentNode *variableAssignment;
  struct ArgListNode *argList;
  struct FunctionDeclarationNode *functionDeclaration;
  struct ExpressionListNode *exprList;
  struct FunctionCallNode *functionCall;
  struct VariableDeclarationListNode *variableDeclarationList;
  struct StructDeclarationNode *structDeclaration;
  struct StructInstantiationNode *structInstantiation;
  struct StringLiteralNode *stringLiteral;
  struct NamespaceDeclarationNode *namespaceDeclaration;
  struct ReturnStatementNode *returnStatement;
  struct TernaryNode *ternary;
  struct StatementNode *statement;
  struct BodyNode *body;
  struct ProgramNode *program;

#line 247 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    90,    90,    91,    94,    95,    98,    99,   102,   103,
     104,   105,   106,   107,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   136,   137,   138,   139,
     140,   143,   146,   149,   150,   153,   154,   155,   156,   159,
     160,   163,   164,   167,   168,   171,   172,   175,   178,   179,
     182,   185,   186,   189,   190,   193,   194,   195,   196,   197,
     198,   201,   202,   205,   206,   207,   208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "NAMESPACE", "STRUCT", "SELF",
  "TRUE", "FALSE", "TEXT", "LOGICAL", "NUMBERTOKEN", "VOID", "RETURN",
  "NUMBER", "SINGLEQUOTEDSTRING", "DOUBLEQUOTEDSTRING", "ID", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "GT", "LE", "GE", "AND",
  "OR", "NOT", "ASSIGN", "COMMA", "SEMICOLON", "COLON", "QUESTION", "DOT",
  "OPENPAREN", "CLOSEPAREN", "OPENCURLY", "CLOSECURLY", "$accept",
  "identifierText", "identifier", "imports", "multiplyExpression",
  "expression", "booleanExpression", "type", "variableDeclaration",
  "variableDefinition", "argList", "functionDeclaration", "exprList",
  "functionCall", "variableDeclarationList", "structDeclaration",
  "structInstantiation", "stringLiteral", "ternary",
  "namespaceDeclaration", "return", "statement", "body", "program", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     248,    48,     1,    -8,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   101,   -70,   -70,   -70,   -32,   316,   316,   316,   -70,
      -7,   282,    45,   362,    -2,     5,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   282,   -70,    27,    15,    -1,
      16,   -70,    10,   374,    40,   410,   410,    -4,   332,    21,
     299,   316,   -70,    44,    44,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   -70,   316,     6,   -70,   -70,
      64,   136,     2,   -70,   -70,   -70,   -70,   -70,   -70,   398,
      30,    33,    44,    37,    45,    45,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   349,   316,    14,   -70,
     -70,    35,   -70,   -70,    53,   148,    36,   316,   -70,   -70,
      -4,   316,   386,    38,    63,    55,   -70,    62,   -70,   -70,
     -70,   410,   -70,   173,    65,    57,   -70,   -70,    59,   148,
     210,   -70,   -70,   -70,    60,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      73,     0,     0,     0,     5,    23,    24,    36,    38,    37,
      39,     0,     8,    59,    58,     2,     0,     0,     0,     4,
       9,    75,    14,     0,    18,     0,    65,    69,    10,    66,
      19,    20,    21,    67,    70,    71,    74,     0,     0,     0,
       0,    63,     9,     0,     0,    17,    33,    14,     0,    18,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,    72,     1,
       6,     0,     0,    64,     3,    11,    22,    26,    51,    49,
       0,     0,     0,     9,    12,    13,    15,    16,    27,    28,
      29,    30,    31,    32,    34,    35,     0,     0,     0,     7,
      62,     0,    56,    40,     0,    53,     0,     0,    52,    57,
       0,     0,     0,     0,     0,     0,    61,     0,    54,    55,
      50,    60,    42,     0,    43,     0,    41,    46,     0,     0,
       0,    45,    44,    48,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,    58,     0,    31,   -13,    28,    86,   -69,   -70,   -70,
     -23,   -70,   -45,   -70,     7,   -70,   -70,   110,   -70,   -70,
     -70,   -70,   -20,   -70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    42,    21,    22,    23,    24,    25,   105,    26,
     115,    27,    80,    28,   106,    29,    30,    31,    32,    33,
      34,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    52,    39,   104,    44,    47,    81,     4,     4,    40,
     -40,     7,     8,     9,    10,    68,    53,    54,    15,    15,
       4,    20,    67,     7,     8,     9,    10,    69,   -25,   114,
      50,    15,    51,    66,    75,    20,   104,    97,    71,    43,
      84,    85,   102,    98,    45,    46,    48,    50,    70,    51,
       4,   101,   113,    83,    83,    72,    66,    15,    12,    77,
     114,    15,   120,    13,    14,    53,    54,     1,   108,   110,
     117,    20,   103,   109,    50,   116,   119,   123,    79,    79,
     124,    82,    83,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   125,    96,   126,   130,   129,   103,   131,
     135,    99,    74,   128,    49,   103,   132,     4,     5,     6,
     134,    38,   118,     0,     0,    12,    13,    14,    15,     0,
      16,     0,     0,    20,     0,   112,     0,     0,     0,   103,
      20,    17,     0,     0,    41,    79,     0,     0,    18,   121,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     4,    16,     0,     7,     8,     9,
      10,     0,     0,     0,     0,    15,    17,     0,     0,     0,
       0,     0,     0,    18,     0,     0,   100,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
      18,     0,     0,   127,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,    18,     0,     0,
     133,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    18,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     0,    17,    12,    13,    14,    15,     0,    16,    18,
       0,     0,     4,     5,     6,     0,     0,     0,     0,    17,
      12,    13,    14,    15,     0,    16,    18,    78,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
      55,    56,     0,    18,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,    55,    56,     0,
      76,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      55,    56,     0,   111,    57,    58,    59,    60,    61,    62,
      63,    64,    55,    56,     0,    65,    57,    58,    59,    60,
      61,    62,    63,    64,    55,    56,     0,    73,    57,    58,
      59,    60,    61,    62,    63,    64,    55,    56,     0,   122,
      57,    58,    59,    60,    61,    62,    63,    64,    55,    56,
     107,     0,    57,    58,    59,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       0,    21,     2,    72,    36,    18,    51,     6,     6,    17,
      17,     9,    10,    11,    12,    35,    20,    21,    17,    17,
       6,    21,    17,     9,    10,    11,    12,     0,    35,    98,
      37,    17,    39,    35,    38,    35,   105,    31,    39,    11,
      53,    54,    40,    37,    16,    17,    18,    37,    33,    39,
       6,    71,    38,    53,    54,    39,    35,    17,    14,    38,
     129,    17,   107,    15,    16,    20,    21,     3,    38,    82,
      17,    71,    72,    40,    37,    40,    40,    39,    50,    51,
      17,    37,    82,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    38,    66,    33,    39,    32,    98,    40,
      40,    70,    44,   123,    18,   105,   129,     6,     7,     8,
     130,     1,   105,    -1,    -1,    14,    15,    16,    17,    -1,
      19,    -1,    -1,   123,    -1,    97,    -1,    -1,    -1,   129,
     130,    30,    -1,    -1,    33,   107,    -1,    -1,    37,   111,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     6,    19,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    40,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    -1,    -1,     6,     7,     8,    -1,    -1,
      -1,    -1,    30,    14,    15,    16,    17,    -1,    19,    37,
      -1,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    30,
      14,    15,    16,    17,    -1,    19,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      18,    19,    -1,    37,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      38,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      18,    19,    -1,    34,    22,    23,    24,    25,    26,    27,
      28,    29,    18,    19,    -1,    33,    22,    23,    24,    25,
      26,    27,    28,    29,    18,    19,    -1,    33,    22,    23,
      24,    25,    26,    27,    28,    29,    18,    19,    -1,    33,
      22,    23,    24,    25,    26,    27,    28,    29,    18,    19,
      32,    -1,    22,    23,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    19,    30,    37,    42,
      43,    44,    45,    46,    47,    48,    50,    52,    54,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    58,    43,
      17,    33,    43,    46,    36,    46,    46,    45,    46,    47,
      37,    39,    63,    20,    21,    18,    19,    22,    23,    24,
      25,    26,    27,    28,    29,    33,    35,    17,    63,     0,
      33,    39,    39,    33,    42,    38,    38,    38,    38,    46,
      53,    53,    37,    43,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    31,    37,    44,
      40,    63,    40,    43,    48,    49,    55,    32,    38,    40,
      45,    34,    46,    38,    48,    51,    40,    17,    55,    40,
      53,    46,    33,    39,    17,    38,    33,    40,    63,    32,
      39,    40,    51,    40,    63,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    48,    48,
      48,    49,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     3,     4,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     1,     1,     1,     1,
       1,     3,     5,     2,     4,     7,     6,     8,     7,     1,
       3,     3,     4,     1,     2,     5,     4,     4,     1,     1,
       5,     5,     4,     2,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     0,     1,     1,     2
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
#line 90 "parser.y"
                   { (yyval.identifierText)=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); (yyval.identifierText)->text=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.identifierText)->text, (yyvsp[0].tokenText)); (yyval.identifierText)->next = NULL; }
#line 1577 "y.tab.c"
    break;

  case 3:
#line 91 "parser.y"
                          { (yyval.identifierText)=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); (yyval.identifierText)->text=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.identifierText)->text, (yyvsp[-2].tokenText)); (yyval.identifierText)->next = (yyvsp[0].identifierText); }
#line 1583 "y.tab.c"
    break;

  case 4:
#line 94 "parser.y"
                           {{ (yyval.identifier)=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); (yyval.identifier)->type=ID_NODE_TYPE_TEXT; (yyval.identifier)->text=(yyvsp[0].identifierText); }}
#line 1589 "y.tab.c"
    break;

  case 5:
#line 95 "parser.y"
         {{ (yyval.identifier)=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); (yyval.identifier)->type=ID_NODE_TYPE_SELF; (yyval.identifier)->text=NULL; }}
#line 1595 "y.tab.c"
    break;

  case 6:
#line 98 "parser.y"
                                        { (yyval.imports)=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); (yyval.imports)->path=(yyvsp[-1].stringLiteral); (yyval.imports)->next=NULL; }
#line 1601 "y.tab.c"
    break;

  case 7:
#line 99 "parser.y"
                                           { (yyval.imports)=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); (yyval.imports)->path=(yyvsp[-2].stringLiteral); (yyval.imports)->next=(yyvsp[0].imports); }
#line 1607 "y.tab.c"
    break;

  case 8:
#line 102 "parser.y"
                           { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_LITERAL; (yyval.multiplyExpression)->value.literalValue=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.multiplyExpression)->value.literalValue, (yyvsp[0].tokenText)); }
#line 1613 "y.tab.c"
    break;

  case 9:
#line 103 "parser.y"
               { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_IDENTIFIER; (yyval.multiplyExpression)->value.identifier = (yyvsp[0].identifier); }
#line 1619 "y.tab.c"
    break;

  case 10:
#line 104 "parser.y"
                 { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_FUNCTION_CALL; (yyval.multiplyExpression)->value.functionCall = (yyvsp[0].functionCall); }
#line 1625 "y.tab.c"
    break;

  case 11:
#line 105 "parser.y"
                                            { (yyval.multiplyExpression) = (yyvsp[-1].multiplyExpression); }
#line 1631 "y.tab.c"
    break;

  case 12:
#line 106 "parser.y"
                                                { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_TIMES; (yyval.multiplyExpression)->value.sides.left = (yyvsp[-2].multiplyExpression); (yyval.multiplyExpression)->value.sides.right = (yyvsp[0].multiplyExpression); }
#line 1637 "y.tab.c"
    break;

  case 13:
#line 107 "parser.y"
                                                 { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_DIVIDE; (yyval.multiplyExpression)->value.sides.left = (yyvsp[-2].multiplyExpression); (yyval.multiplyExpression)->value.sides.right = (yyvsp[0].multiplyExpression); }
#line 1643 "y.tab.c"
    break;

  case 14:
#line 110 "parser.y"
                               { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MULTIPLY_EXPRESSION; (yyval.expression)->value.multiplyExpression = (yyvsp[0].multiplyExpression); }
#line 1649 "y.tab.c"
    break;

  case 15:
#line 111 "parser.y"
                               { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_PLUS; (yyval.expression)->value.sides.left = (yyvsp[-2].expression); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1655 "y.tab.c"
    break;

  case 16:
#line 112 "parser.y"
                                { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MINUS; (yyval.expression)->value.sides.left = (yyvsp[-2].expression); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1661 "y.tab.c"
    break;

  case 17:
#line 113 "parser.y"
                     { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MINUS; (yyval.expression)->value.sides.left=makeZeroExpressionNode(); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1667 "y.tab.c"
    break;

  case 18:
#line 114 "parser.y"
                      {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_BOOLEAN; (yyval.expression)->value.booleanExpression=(yyvsp[0].booleanExpression); }}
#line 1673 "y.tab.c"
    break;

  case 19:
#line 115 "parser.y"
                        {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_STRUCT_INSTANTIATION; (yyval.expression)->value.structInstantiation=(yyvsp[0].structInstantiation); }}
#line 1679 "y.tab.c"
    break;

  case 20:
#line 116 "parser.y"
                  {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_STRING_LITERAL; (yyval.expression)->value.stringLiteral=(yyvsp[0].stringLiteral); }}
#line 1685 "y.tab.c"
    break;

  case 21:
#line 117 "parser.y"
            {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_TERNARY; (yyval.expression)->value.ternary=(yyvsp[0].ternary); }}
#line 1691 "y.tab.c"
    break;

  case 22:
#line 118 "parser.y"
                                    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1697 "y.tab.c"
    break;

  case 23:
#line 121 "parser.y"
                        { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_TRUE; }
#line 1703 "y.tab.c"
    break;

  case 24:
#line 122 "parser.y"
          { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_FALSE; }
#line 1709 "y.tab.c"
    break;

  case 25:
#line 123 "parser.y"
               { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_IDENTIFIER; (yyval.booleanExpression)->value.identifier = (yyvsp[0].identifier); }
#line 1715 "y.tab.c"
    break;

  case 26:
#line 124 "parser.y"
                                           { (yyval.booleanExpression) = (yyvsp[-1].booleanExpression); }
#line 1721 "y.tab.c"
    break;

  case 27:
#line 125 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_EQ; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1727 "y.tab.c"
    break;

  case 28:
#line 126 "parser.y"
                              { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_NEQ; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1733 "y.tab.c"
    break;

  case 29:
#line 127 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_LT; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1739 "y.tab.c"
    break;

  case 30:
#line 128 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_GT; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1745 "y.tab.c"
    break;

  case 31:
#line 129 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_LE; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1751 "y.tab.c"
    break;

  case 32:
#line 130 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_GE; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1757 "y.tab.c"
    break;

  case 33:
#line 131 "parser.y"
                   { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_NOT; (yyval.booleanExpression)->value.child = (yyvsp[0].expression); }
#line 1763 "y.tab.c"
    break;

  case 34:
#line 132 "parser.y"
                              { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_AND; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1769 "y.tab.c"
    break;

  case 35:
#line 133 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_OR; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1775 "y.tab.c"
    break;

  case 36:
#line 136 "parser.y"
           { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_TEXT; }
#line 1781 "y.tab.c"
    break;

  case 37:
#line 137 "parser.y"
                { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_NUMBER; }
#line 1787 "y.tab.c"
    break;

  case 38:
#line 138 "parser.y"
            { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_LOGICAL; }
#line 1793 "y.tab.c"
    break;

  case 39:
#line 139 "parser.y"
         { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_VOID; }
#line 1799 "y.tab.c"
    break;

  case 40:
#line 140 "parser.y"
               { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_IDENTIFIER; (yyval.type)->identifier = (yyvsp[0].identifier); }
#line 1805 "y.tab.c"
    break;

  case 41:
#line 143 "parser.y"
                                       { (yyval.variableDeclaration)=(struct VariableDeclarationNode *)malloc(sizeof(struct VariableDeclarationNode)); (yyval.variableDeclaration)->variableType=(yyvsp[-2].type); (yyval.variableDeclaration)->name=malloc(strlen((yyvsp[-1].tokenText))+1); strcpy((yyval.variableDeclaration)->name, (yyvsp[-1].tokenText)); }
#line 1811 "y.tab.c"
    break;

  case 42:
#line 146 "parser.y"
                                                        {{ (yyval.variableDefinition)=(struct VariableDefinitionNode *)malloc(sizeof(struct VariableDefinitionNode)); (yyval.variableDefinition)->variableType=(yyvsp[-4].type); (yyval.variableDefinition)->name=malloc(strlen((yyvsp[-3].tokenText))+1); strcpy((yyval.variableDefinition)->name, (yyvsp[-3].tokenText)); (yyval.variableDefinition)->expression=(yyvsp[-1].expression); }}
#line 1817 "y.tab.c"
    break;

  case 43:
#line 149 "parser.y"
                 { (yyval.argList)=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); (yyval.argList)->argumentType=(yyvsp[-1].type); (yyval.argList)->argumentName=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.argList)->argumentName, (yyvsp[0].tokenText)); (yyval.argList)->next=NULL; }
#line 1823 "y.tab.c"
    break;

  case 44:
#line 150 "parser.y"
                          { (yyval.argList)=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); (yyval.argList)->argumentType=(yyvsp[-3].type); (yyval.argList)->argumentName=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.argList)->argumentName, (yyvsp[-2].tokenText)); (yyval.argList)->next=(yyvsp[0].argList); }
#line 1829 "y.tab.c"
    break;

  case 45:
#line 153 "parser.y"
                                                                            { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-6].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-5].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-5].tokenText)); (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=(yyvsp[-1].body); }
#line 1835 "y.tab.c"
    break;

  case 46:
#line 154 "parser.y"
                                                      { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-5].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-4].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-4].tokenText)); (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=NULL; }
#line 1841 "y.tab.c"
    break;

  case 47:
#line 155 "parser.y"
                                                                   { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-7].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-6].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-6].tokenText)); (yyval.functionDeclaration)->argList=(yyvsp[-4].argList); (yyval.functionDeclaration)->body=(yyvsp[-1].body); }
#line 1847 "y.tab.c"
    break;

  case 48:
#line 156 "parser.y"
                                                              { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-6].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-5].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-5].tokenText)); (yyval.functionDeclaration)->argList=(yyvsp[-3].argList); (yyval.functionDeclaration)->body=NULL; }
#line 1853 "y.tab.c"
    break;

  case 49:
#line 159 "parser.y"
                     {{ (yyval.exprList)=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); (yyval.exprList)->expression=(yyvsp[0].expression); (yyval.exprList)->next=NULL; }}
#line 1859 "y.tab.c"
    break;

  case 50:
#line 160 "parser.y"
                              {{ (yyval.exprList)=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); (yyval.exprList)->expression=(yyvsp[-2].expression); (yyval.exprList)->next=(yyvsp[0].exprList); }}
#line 1865 "y.tab.c"
    break;

  case 51:
#line 163 "parser.y"
                                              {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-2].identifier); (yyval.functionCall)->arguments=NULL; }}
#line 1871 "y.tab.c"
    break;

  case 52:
#line 164 "parser.y"
                                             {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-3].identifier); (yyval.functionCall)->arguments=(yyvsp[-1].exprList); }}
#line 1877 "y.tab.c"
    break;

  case 53:
#line 167 "parser.y"
                                             {{ (yyval.variableDeclarationList)=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); (yyval.variableDeclarationList)->current=(yyvsp[0].variableDeclaration); (yyval.variableDeclarationList)->next=NULL; }}
#line 1883 "y.tab.c"
    break;

  case 54:
#line 168 "parser.y"
                                                {{ (yyval.variableDeclarationList)=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); (yyval.variableDeclarationList)->current=(yyvsp[-1].variableDeclaration); (yyval.variableDeclarationList)->next=(yyvsp[0].variableDeclarationList); }}
#line 1889 "y.tab.c"
    break;

  case 55:
#line 171 "parser.y"
                                                                          {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-3].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-3].tokenText)); (yyval.structDeclaration)->declarations=(yyvsp[-1].variableDeclarationList); }}
#line 1895 "y.tab.c"
    break;

  case 56:
#line 172 "parser.y"
                                   {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-2].tokenText)); (yyval.structDeclaration)->declarations=NULL; }}
#line 1901 "y.tab.c"
    break;

  case 57:
#line 175 "parser.y"
                                                              {{ (yyval.structInstantiation)=(struct StructInstantiationNode *)malloc(sizeof(struct StructInstantiationNode)); (yyval.structInstantiation)->identifier=(yyvsp[-3].identifier); (yyval.structInstantiation)->arguments=(yyvsp[-1].exprList); }}
#line 1907 "y.tab.c"
    break;

  case 58:
#line 178 "parser.y"
                                  {{ (yyval.stringLiteral)=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); (yyval.stringLiteral)->value=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.stringLiteral)->value, (yyvsp[0].tokenText)); }}
#line 1913 "y.tab.c"
    break;

  case 59:
#line 179 "parser.y"
                       {{ (yyval.stringLiteral)=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); (yyval.stringLiteral)->value=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.stringLiteral)->value, (yyvsp[0].tokenText)); }}
#line 1919 "y.tab.c"
    break;

  case 60:
#line 182 "parser.y"
                                                                {{ (yyval.ternary)=(struct TernaryNode *)malloc(sizeof(struct TernaryNode)); (yyval.ternary)->condition=(yyvsp[-4].booleanExpression); (yyval.ternary)->ifTrue=(yyvsp[-2].expression); (yyval.ternary)->ifFalse=(yyvsp[0].expression); }}
#line 1925 "y.tab.c"
    break;

  case 61:
#line 185 "parser.y"
                                                                     {{ (yyval.namespaceDeclaration)=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); (yyval.namespaceDeclaration)->identifier=(yyvsp[-3].identifier); (yyval.namespaceDeclaration)->body=(yyvsp[-1].body); }}
#line 1931 "y.tab.c"
    break;

  case 62:
#line 186 "parser.y"
                                              {{ (yyval.namespaceDeclaration)=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); (yyval.namespaceDeclaration)->identifier=(yyvsp[-2].identifier); (yyval.namespaceDeclaration)->body=NULL; }}
#line 1937 "y.tab.c"
    break;

  case 63:
#line 189 "parser.y"
                         {{ (yyval.returnStatement)=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); (yyval.returnStatement)->value=NULL; }}
#line 1943 "y.tab.c"
    break;

  case 64:
#line 190 "parser.y"
                                {{ (yyval.returnStatement)=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); (yyval.returnStatement)->value=(yyvsp[-1].expression); }}
#line 1949 "y.tab.c"
    break;

  case 65:
#line 193 "parser.y"
                              {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_VAR_DEFINITION; (yyval.statement)->value.varDefinition=(yyvsp[0].variableDefinition); }}
#line 1955 "y.tab.c"
    break;

  case 66:
#line 194 "parser.y"
                      {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_STRUCT_DECLARATION; (yyval.statement)->value.structDeclaration=(yyvsp[0].structDeclaration); }}
#line 1961 "y.tab.c"
    break;

  case 67:
#line 195 "parser.y"
                         {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_NAMESPACE_DECLARATION; (yyval.statement)->value.namespaceDeclaration=(yyvsp[0].namespaceDeclaration); }}
#line 1967 "y.tab.c"
    break;

  case 68:
#line 196 "parser.y"
                         {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_EXPRESSION; (yyval.statement)->value.expression=(yyvsp[-1].expression); }}
#line 1973 "y.tab.c"
    break;

  case 69:
#line 197 "parser.y"
                        {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_FUNCTION_DECLARATION; (yyval.statement)->value.functionDeclaration=(yyvsp[0].functionDeclaration); }}
#line 1979 "y.tab.c"
    break;

  case 70:
#line 198 "parser.y"
           {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_RETURN_STATEMENT; (yyval.statement)->value.returnStatement=(yyvsp[0].returnStatement); }}
#line 1985 "y.tab.c"
    break;

  case 71:
#line 201 "parser.y"
                {{ (yyval.body)=(struct BodyNode *)malloc(sizeof(struct BodyNode)); (yyval.body)->current=(yyvsp[0].statement); (yyval.body)->next=NULL; }}
#line 1991 "y.tab.c"
    break;

  case 72:
#line 202 "parser.y"
                   {{ (yyval.body)=(struct BodyNode *)malloc(sizeof(struct BodyNode)); (yyval.body)->current=(yyvsp[-1].statement); (yyval.body)->next=(yyvsp[0].body); }}
#line 1997 "y.tab.c"
    break;

  case 73:
#line 205 "parser.y"
         {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=NULL; (yyval.program)->body=NULL; head=(yyval.program); }}
#line 2003 "y.tab.c"
    break;

  case 74:
#line 206 "parser.y"
         {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=NULL; (yyval.program)->body=(yyvsp[0].body); head=(yyval.program); }}
#line 2009 "y.tab.c"
    break;

  case 75:
#line 207 "parser.y"
            {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=(yyvsp[0].imports); (yyval.program)->body=NULL; head=(yyval.program); }}
#line 2015 "y.tab.c"
    break;

  case 76:
#line 208 "parser.y"
                 {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=(yyvsp[-1].imports); (yyval.program)->body=(yyvsp[0].body); head=(yyval.program); }}
#line 2021 "y.tab.c"
    break;


#line 2025 "y.tab.c"

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
#line 211 "parser.y"


struct ExpressionNode *makeZeroExpressionNode(void) {
  struct ExpressionNode *expr = (struct ExpressionNode *)malloc(sizeof(struct ExpressionNode));
  expr->type = EXPR_NODE_TYPE_MULTIPLY_EXPRESSION;
  
  struct MultiplyExpressionNode *mul = (struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode));
  mul->type = MUL_NODE_TYPE_LITERAL;
  mul->value.literalValue = (char *)malloc(2);
  char *zero = "0";
  strcpy(mul->value.literalValue, zero);
  
  expr->value.multiplyExpression = mul;

  return expr;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
