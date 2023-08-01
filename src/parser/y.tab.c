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
    AS = 259,
    NAMESPACE = 260,
    STRUCT = 261,
    SERIALIZE = 262,
    DESERIALIZE = 263,
    SELF = 264,
    TRUE = 265,
    FALSE = 266,
    TEXT = 267,
    LOGICAL = 268,
    NUMBERTOKEN = 269,
    VOID = 270,
    RETURN = 271,
    NUMBER = 272,
    SINGLEQUOTEDSTRING = 273,
    DOUBLEQUOTEDSTRING = 274,
    ID = 275,
    PLUS = 276,
    MINUS = 277,
    TIMES = 278,
    DIVIDE = 279,
    EQ = 280,
    NEQ = 281,
    LT = 282,
    GT = 283,
    LE = 284,
    GE = 285,
    AND = 286,
    OR = 287,
    NOT = 288,
    ASSIGN = 289,
    COMMA = 290,
    SEMICOLON = 291,
    COLON = 292,
    QUESTION = 293,
    DOT = 294,
    DOLLAR = 295,
    OPENPAREN = 296,
    CLOSEPAREN = 297,
    OPENCURLY = 298,
    CLOSECURLY = 299
  };
#endif
/* Tokens.  */
#define IMPORT 258
#define AS 259
#define NAMESPACE 260
#define STRUCT 261
#define SERIALIZE 262
#define DESERIALIZE 263
#define SELF 264
#define TRUE 265
#define FALSE 266
#define TEXT 267
#define LOGICAL 268
#define NUMBERTOKEN 269
#define VOID 270
#define RETURN 271
#define NUMBER 272
#define SINGLEQUOTEDSTRING 273
#define DOUBLEQUOTEDSTRING 274
#define ID 275
#define PLUS 276
#define MINUS 277
#define TIMES 278
#define DIVIDE 279
#define EQ 280
#define NEQ 281
#define LT 282
#define GT 283
#define LE 284
#define GE 285
#define AND 286
#define OR 287
#define NOT 288
#define ASSIGN 289
#define COMMA 290
#define SEMICOLON 291
#define COLON 292
#define QUESTION 293
#define DOT 294
#define DOLLAR 295
#define OPENPAREN 296
#define CLOSEPAREN 297
#define OPENCURLY 298
#define CLOSECURLY 299

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

#line 255 "y.tab.c"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,    93,    96,    97,   100,   101,   104,   105,
     106,   107,   108,   109,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   138,   139,   140,   141,
     142,   145,   148,   151,   152,   155,   156,   157,   158,   161,
     162,   165,   166,   167,   168,   171,   172,   175,   178,   181,
     182,   183,   184,   187,   190,   191,   194,   197,   198,   201,
     202,   205,   206,   207,   208,   209,   210,   213,   214,   217,
     218,   219,   220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "AS", "NAMESPACE", "STRUCT",
  "SERIALIZE", "DESERIALIZE", "SELF", "TRUE", "FALSE", "TEXT", "LOGICAL",
  "NUMBERTOKEN", "VOID", "RETURN", "NUMBER", "SINGLEQUOTEDSTRING",
  "DOUBLEQUOTEDSTRING", "ID", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ",
  "NEQ", "LT", "GT", "LE", "GE", "AND", "OR", "NOT", "ASSIGN", "COMMA",
  "SEMICOLON", "COLON", "QUESTION", "DOT", "DOLLAR", "OPENPAREN",
  "CLOSEPAREN", "OPENCURLY", "CLOSECURLY", "$accept", "identifierText",
  "identifier", "imports", "multiplyExpression", "expression",
  "booleanExpression", "type", "variableDeclaration", "variableDefinition",
  "argList", "functionDeclaration", "exprList", "functionCall",
  "variableDeclarationList", "serializeBlock", "deserializeBlock",
  "structDeclaration", "structInstantiation", "stringLiteral", "ternary",
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     259,    26,     1,   -13,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   101,   -72,   -72,   -72,   -22,   343,   343,     1,   343,
     -72,    -4,   292,    55,   391,   -11,    39,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   292,   -72,    54,    61,
      25,    43,   -72,    34,   403,    52,   439,   439,    41,     9,
     360,    29,   309,   343,   -72,    40,    40,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   -72,   343,    -6,
     -72,   -72,    67,   145,    -1,   -72,   -72,   326,   -72,   -72,
     -72,   -72,   427,    56,    58,    40,    59,    55,    55,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   378,
     343,    11,    69,   -72,    62,    60,   -72,   -72,    87,    49,
       2,   105,   -72,    72,   343,   -72,   -72,     9,   343,   415,
      73,    97,    82,   123,   -72,   292,    92,   -72,   -72,   105,
      86,    88,   -72,   -72,   439,   -72,   182,    95,    90,   -72,
      91,   -72,    94,   292,   -72,   -72,    96,    49,   219,   -72,
     -72,   100,   -72,   -72,   -72,   102,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      79,     0,     0,     0,     5,    23,    24,    36,    38,    37,
      39,     0,     8,    65,    64,     2,     0,     0,     0,     0,
       4,     9,    81,    14,     0,    18,     0,    71,    75,    10,
      72,    19,    20,    21,    73,    76,    77,    80,     0,     0,
       0,     0,    69,     9,     0,     0,    17,    33,     0,    14,
       0,    18,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
      78,     1,     0,     0,     0,    70,     3,     0,    11,    22,
      26,    51,    49,     0,     0,     0,     9,    12,    13,    15,
      16,    27,    28,    29,    30,    31,    32,    34,    35,     0,
       0,     0,     0,    68,     0,     0,    60,    40,     0,    55,
       0,     0,    53,     0,     0,    52,    63,     0,     0,     0,
       0,     0,     0,     6,    67,     0,     0,    56,    59,     0,
       0,     0,    54,    50,    66,    42,     0,    43,     0,     7,
       0,    41,     0,     0,    62,    46,     0,     0,     0,    57,
      61,     0,    45,    44,    48,     0,    58,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   107,     0,    16,   -15,    31,   134,   -71,   -72,   -72,
      19,   -72,   -48,   -72,    63,    64,    42,   -72,   -72,   167,
     -72,   -72,   -72,   -72,   -21,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    43,    22,    23,    24,    25,    26,   109,    27,
     122,    28,    83,    29,   110,   111,   131,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    54,    40,   108,    49,    84,   105,    41,     4,   105,
       4,     7,     8,     9,    10,    70,   -40,    45,    48,    15,
       4,    15,    21,     7,     8,     9,    10,    68,   100,   113,
     121,    15,    55,    56,   -25,   101,    21,    52,   108,    53,
      87,    88,    44,   106,    13,    14,   128,    46,    47,     4,
      50,    78,   104,   120,    71,    86,    86,    12,     4,    69,
      15,     7,     8,     9,    10,    72,   133,    68,    73,    15,
     117,    80,    15,    21,   107,    52,   121,    53,    55,    56,
      18,    85,    77,    82,    82,    86,    74,   102,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   115,    99,
      52,   107,   116,   125,   140,   123,   124,   126,    82,   107,
       4,     5,     6,   130,   132,   146,   136,   137,    12,    13,
      14,    15,   151,    16,   138,    21,     1,   155,   141,   143,
     147,   119,   144,   148,    17,   149,    21,    42,   150,   139,
     152,    18,    19,    21,   156,    82,   157,   107,    21,   134,
       2,     3,    76,    51,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   153,    16,    39,     0,
       0,   142,   127,     0,   129,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    18,    19,     2,     3,   103,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    18,    19,     2,     3,   145,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    18,
      19,     0,     1,   154,     2,     3,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     2,     3,    18,
      19,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,     0,     0,     4,     5,
       6,     0,     0,     0,     0,    17,    12,    13,    14,    15,
       0,    16,    18,    19,     0,     4,     5,     6,     0,     0,
       0,     0,    17,    12,    13,    14,    15,     0,    16,    18,
      19,    81,     4,     5,     6,     0,     0,     0,     0,    17,
      12,    13,    14,    15,     0,    16,    18,    19,   112,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    57,    58,    18,    19,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,    57,
      58,     0,    79,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    57,    58,     0,   118,    59,    60,    61,    62,
      63,    64,    65,    66,    57,    58,     0,    67,    59,    60,
      61,    62,    63,    64,    65,    66,    57,    58,     0,    75,
      59,    60,    61,    62,    63,    64,    65,    66,    57,    58,
       0,   135,    59,    60,    61,    62,    63,    64,    65,    66,
      57,    58,   114,     0,    59,    60,    61,    62,    63,    64,
      65,    66
};

static const yytype_int16 yycheck[] =
{
       0,    22,     2,    74,    19,    53,     7,    20,     9,     7,
       9,    12,    13,    14,    15,    36,    20,    39,    18,    20,
       9,    20,    22,    12,    13,    14,    15,    38,    34,    77,
     101,    20,    23,    24,    38,    41,    36,    41,   109,    43,
      55,    56,    11,    44,    18,    19,    44,    16,    17,     9,
      19,    42,    73,    42,     0,    55,    56,    17,     9,    20,
      20,    12,    13,    14,    15,     4,   114,    38,    43,    20,
      85,    42,    20,    73,    74,    41,   147,    43,    23,    24,
      40,    41,    41,    52,    53,    85,    43,    20,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    42,    68,
      41,   101,    44,    43,   125,    36,    44,    20,    77,   109,
       9,    10,    11,     8,    42,   136,    43,    20,    17,    18,
      19,    20,   143,    22,    42,   125,     3,   148,    36,    43,
      35,   100,    44,    43,    33,    44,   136,    36,    44,   123,
      44,    40,    41,   143,    44,   114,    44,   147,   148,   118,
       5,     6,    45,    19,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   147,    22,     1,    -1,
      -1,   129,   109,    -1,   110,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,     5,     6,    44,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,     5,     6,    44,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,     3,    44,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,     5,     6,    40,
      41,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    33,    17,    18,    19,    20,
      -1,    22,    40,    41,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    33,    17,    18,    19,    20,    -1,    22,    40,
      41,    42,     9,    10,    11,    -1,    -1,    -1,    -1,    33,
      17,    18,    19,    20,    -1,    22,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    21,    22,    40,    41,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    42,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    21,    22,    -1,    37,    25,    26,    27,    28,
      29,    30,    31,    32,    21,    22,    -1,    36,    25,    26,
      27,    28,    29,    30,    31,    32,    21,    22,    -1,    36,
      25,    26,    27,    28,    29,    30,    31,    32,    21,    22,
      -1,    36,    25,    26,    27,    28,    29,    30,    31,    32,
      21,    22,    35,    -1,    25,    26,    27,    28,    29,    30,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    33,    40,    41,
      46,    47,    48,    49,    50,    51,    52,    54,    56,    58,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    64,
      47,    20,    36,    47,    50,    39,    50,    50,    47,    49,
      50,    51,    41,    43,    69,    23,    24,    21,    22,    25,
      26,    27,    28,    29,    30,    31,    32,    36,    38,    20,
      69,     0,     4,    43,    43,    36,    46,    41,    42,    42,
      42,    42,    50,    57,    57,    41,    47,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      34,    41,    20,    44,    69,     7,    44,    47,    52,    53,
      59,    60,    42,    57,    35,    42,    44,    49,    37,    50,
      42,    52,    55,    36,    44,    43,    20,    59,    44,    60,
       8,    61,    42,    57,    50,    36,    43,    20,    42,    48,
      69,    36,    61,    43,    44,    44,    69,    35,    43,    44,
      44,    69,    44,    55,    44,    69,    44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    53,    54,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    59,    59,    60,    61,    62,
      62,    62,    62,    63,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     5,     6,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     1,     1,     1,     1,
       1,     3,     5,     2,     4,     7,     6,     8,     7,     1,
       3,     3,     4,     4,     5,     1,     2,     4,     4,     5,
       4,     7,     6,     4,     1,     1,     5,     5,     4,     2,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     0,
       1,     1,     2
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
#line 92 "parser.y"
                   { (yyval.identifierText)=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); (yyval.identifierText)->text=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.identifierText)->text, (yyvsp[0].tokenText)); (yyval.identifierText)->next = NULL; }
#line 1603 "y.tab.c"
    break;

  case 3:
#line 93 "parser.y"
                          { (yyval.identifierText)=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); (yyval.identifierText)->text=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.identifierText)->text, (yyvsp[-2].tokenText)); (yyval.identifierText)->next = (yyvsp[0].identifierText); }
#line 1609 "y.tab.c"
    break;

  case 4:
#line 96 "parser.y"
                           {{ (yyval.identifier)=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); (yyval.identifier)->type=ID_NODE_TYPE_TEXT; (yyval.identifier)->text=(yyvsp[0].identifierText); }}
#line 1615 "y.tab.c"
    break;

  case 5:
#line 97 "parser.y"
         {{ (yyval.identifier)=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); (yyval.identifier)->type=ID_NODE_TYPE_SELF; (yyval.identifier)->text=NULL; }}
#line 1621 "y.tab.c"
    break;

  case 6:
#line 100 "parser.y"
                                              { (yyval.imports)=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); (yyval.imports)->path=(yyvsp[-3].stringLiteral); (yyval.imports)->alias=malloc(strlen((yyvsp[-1].tokenText))+1); strcpy((yyval.imports)->alias, (yyvsp[-1].tokenText)); (yyval.imports)->next=NULL; }
#line 1627 "y.tab.c"
    break;

  case 7:
#line 101 "parser.y"
                                                 { (yyval.imports)=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); (yyval.imports)->path=(yyvsp[-4].stringLiteral); (yyval.imports)->alias=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.imports)->alias, (yyvsp[-2].tokenText)); (yyval.imports)->next=(yyvsp[0].imports); }
#line 1633 "y.tab.c"
    break;

  case 8:
#line 104 "parser.y"
                           { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_LITERAL; (yyval.multiplyExpression)->value.literalValue=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.multiplyExpression)->value.literalValue, (yyvsp[0].tokenText)); }
#line 1639 "y.tab.c"
    break;

  case 9:
#line 105 "parser.y"
               { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_IDENTIFIER; (yyval.multiplyExpression)->value.identifier = (yyvsp[0].identifier); }
#line 1645 "y.tab.c"
    break;

  case 10:
#line 106 "parser.y"
                 { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_FUNCTION_CALL; (yyval.multiplyExpression)->value.functionCall = (yyvsp[0].functionCall); }
#line 1651 "y.tab.c"
    break;

  case 11:
#line 107 "parser.y"
                                            { (yyval.multiplyExpression) = (yyvsp[-1].multiplyExpression); }
#line 1657 "y.tab.c"
    break;

  case 12:
#line 108 "parser.y"
                                                { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_TIMES; (yyval.multiplyExpression)->value.sides.left = (yyvsp[-2].multiplyExpression); (yyval.multiplyExpression)->value.sides.right = (yyvsp[0].multiplyExpression); }
#line 1663 "y.tab.c"
    break;

  case 13:
#line 109 "parser.y"
                                                 { (yyval.multiplyExpression)=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); (yyval.multiplyExpression)->type = MUL_NODE_TYPE_DIVIDE; (yyval.multiplyExpression)->value.sides.left = (yyvsp[-2].multiplyExpression); (yyval.multiplyExpression)->value.sides.right = (yyvsp[0].multiplyExpression); }
#line 1669 "y.tab.c"
    break;

  case 14:
#line 112 "parser.y"
                               { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MULTIPLY_EXPRESSION; (yyval.expression)->value.multiplyExpression = (yyvsp[0].multiplyExpression); }
#line 1675 "y.tab.c"
    break;

  case 15:
#line 113 "parser.y"
                               { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_PLUS; (yyval.expression)->value.sides.left = (yyvsp[-2].expression); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1681 "y.tab.c"
    break;

  case 16:
#line 114 "parser.y"
                                { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MINUS; (yyval.expression)->value.sides.left = (yyvsp[-2].expression); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1687 "y.tab.c"
    break;

  case 17:
#line 115 "parser.y"
                     { (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type = EXPR_NODE_TYPE_MINUS; (yyval.expression)->value.sides.left=makeZeroExpressionNode(); (yyval.expression)->value.sides.right = (yyvsp[0].expression); }
#line 1693 "y.tab.c"
    break;

  case 18:
#line 116 "parser.y"
                      {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_BOOLEAN; (yyval.expression)->value.booleanExpression=(yyvsp[0].booleanExpression); }}
#line 1699 "y.tab.c"
    break;

  case 19:
#line 117 "parser.y"
                        {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_STRUCT_INSTANTIATION; (yyval.expression)->value.structInstantiation=(yyvsp[0].structInstantiation); }}
#line 1705 "y.tab.c"
    break;

  case 20:
#line 118 "parser.y"
                  {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_STRING_LITERAL; (yyval.expression)->value.stringLiteral=(yyvsp[0].stringLiteral); }}
#line 1711 "y.tab.c"
    break;

  case 21:
#line 119 "parser.y"
            {{ (yyval.expression)=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); (yyval.expression)->type=EXPR_NODE_TYPE_TERNARY; (yyval.expression)->value.ternary=(yyvsp[0].ternary); }}
#line 1717 "y.tab.c"
    break;

  case 22:
#line 120 "parser.y"
                                    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1723 "y.tab.c"
    break;

  case 23:
#line 123 "parser.y"
                        { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_TRUE; }
#line 1729 "y.tab.c"
    break;

  case 24:
#line 124 "parser.y"
          { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_FALSE; }
#line 1735 "y.tab.c"
    break;

  case 25:
#line 125 "parser.y"
               { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_IDENTIFIER; (yyval.booleanExpression)->value.identifier = (yyvsp[0].identifier); }
#line 1741 "y.tab.c"
    break;

  case 26:
#line 126 "parser.y"
                                           { (yyval.booleanExpression) = (yyvsp[-1].booleanExpression); }
#line 1747 "y.tab.c"
    break;

  case 27:
#line 127 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_EQ; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1753 "y.tab.c"
    break;

  case 28:
#line 128 "parser.y"
                              { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_NEQ; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1759 "y.tab.c"
    break;

  case 29:
#line 129 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_LT; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1765 "y.tab.c"
    break;

  case 30:
#line 130 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_GT; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1771 "y.tab.c"
    break;

  case 31:
#line 131 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_LE; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1777 "y.tab.c"
    break;

  case 32:
#line 132 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_GE; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1783 "y.tab.c"
    break;

  case 33:
#line 133 "parser.y"
                   { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_NOT; (yyval.booleanExpression)->value.child = (yyvsp[0].expression); }
#line 1789 "y.tab.c"
    break;

  case 34:
#line 134 "parser.y"
                              { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_AND; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1795 "y.tab.c"
    break;

  case 35:
#line 135 "parser.y"
                             { (yyval.booleanExpression)=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); (yyval.booleanExpression)->type = BOOL_NODE_TYPE_OR; (yyval.booleanExpression)->value.children.left = (yyvsp[-2].expression); (yyval.booleanExpression)->value.children.right = (yyvsp[0].expression); }
#line 1801 "y.tab.c"
    break;

  case 36:
#line 138 "parser.y"
           { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_TEXT; }
#line 1807 "y.tab.c"
    break;

  case 37:
#line 139 "parser.y"
                { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_NUMBER; }
#line 1813 "y.tab.c"
    break;

  case 38:
#line 140 "parser.y"
            { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_LOGICAL; }
#line 1819 "y.tab.c"
    break;

  case 39:
#line 141 "parser.y"
         { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_VOID; }
#line 1825 "y.tab.c"
    break;

  case 40:
#line 142 "parser.y"
               { (yyval.type)=(struct TypeNode *)malloc(sizeof(struct TypeNode)); (yyval.type)->type = TYPE_NODE_TYPE_IDENTIFIER; (yyval.type)->identifier = (yyvsp[0].identifier); }
#line 1831 "y.tab.c"
    break;

  case 41:
#line 145 "parser.y"
                                       { (yyval.variableDeclaration)=(struct VariableDeclarationNode *)malloc(sizeof(struct VariableDeclarationNode)); (yyval.variableDeclaration)->variableType=(yyvsp[-2].type); (yyval.variableDeclaration)->name=malloc(strlen((yyvsp[-1].tokenText))+1); strcpy((yyval.variableDeclaration)->name, (yyvsp[-1].tokenText)); }
#line 1837 "y.tab.c"
    break;

  case 42:
#line 148 "parser.y"
                                                        {{ (yyval.variableDefinition)=(struct VariableDefinitionNode *)malloc(sizeof(struct VariableDefinitionNode)); (yyval.variableDefinition)->variableType=(yyvsp[-4].type); (yyval.variableDefinition)->name=malloc(strlen((yyvsp[-3].tokenText))+1); strcpy((yyval.variableDefinition)->name, (yyvsp[-3].tokenText)); (yyval.variableDefinition)->expression=(yyvsp[-1].expression); }}
#line 1843 "y.tab.c"
    break;

  case 43:
#line 151 "parser.y"
                 { (yyval.argList)=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); (yyval.argList)->argumentType=(yyvsp[-1].type); (yyval.argList)->argumentName=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.argList)->argumentName, (yyvsp[0].tokenText)); (yyval.argList)->next=NULL; }
#line 1849 "y.tab.c"
    break;

  case 44:
#line 152 "parser.y"
                          { (yyval.argList)=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); (yyval.argList)->argumentType=(yyvsp[-3].type); (yyval.argList)->argumentName=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.argList)->argumentName, (yyvsp[-2].tokenText)); (yyval.argList)->next=(yyvsp[0].argList); }
#line 1855 "y.tab.c"
    break;

  case 45:
#line 155 "parser.y"
                                                                            { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-6].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-5].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-5].tokenText)); (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=(yyvsp[-1].body); }
#line 1861 "y.tab.c"
    break;

  case 46:
#line 156 "parser.y"
                                                      { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-5].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-4].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-4].tokenText)); (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=NULL; }
#line 1867 "y.tab.c"
    break;

  case 47:
#line 157 "parser.y"
                                                                   { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-7].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-6].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-6].tokenText)); (yyval.functionDeclaration)->argList=(yyvsp[-4].argList); (yyval.functionDeclaration)->body=(yyvsp[-1].body); }
#line 1873 "y.tab.c"
    break;

  case 48:
#line 158 "parser.y"
                                                              { (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=(yyvsp[-6].type); (yyval.functionDeclaration)->name=malloc(strlen((yyvsp[-5].tokenText))+1); strcpy((yyval.functionDeclaration)->name, (yyvsp[-5].tokenText)); (yyval.functionDeclaration)->argList=(yyvsp[-3].argList); (yyval.functionDeclaration)->body=NULL; }
#line 1879 "y.tab.c"
    break;

  case 49:
#line 161 "parser.y"
                     {{ (yyval.exprList)=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); (yyval.exprList)->expression=(yyvsp[0].expression); (yyval.exprList)->next=NULL; }}
#line 1885 "y.tab.c"
    break;

  case 50:
#line 162 "parser.y"
                              {{ (yyval.exprList)=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); (yyval.exprList)->expression=(yyvsp[-2].expression); (yyval.exprList)->next=(yyvsp[0].exprList); }}
#line 1891 "y.tab.c"
    break;

  case 51:
#line 165 "parser.y"
                                              {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-2].identifier); (yyval.functionCall)->arguments=NULL; (yyval.functionCall)->isDirectFormula=0; }}
#line 1897 "y.tab.c"
    break;

  case 52:
#line 166 "parser.y"
                                             {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-3].identifier); (yyval.functionCall)->arguments=(yyvsp[-1].exprList); (yyval.functionCall)->isDirectFormula=0; }}
#line 1903 "y.tab.c"
    break;

  case 53:
#line 167 "parser.y"
                                           {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-2].identifier); (yyval.functionCall)->arguments=NULL; (yyval.functionCall)->isDirectFormula=1; }}
#line 1909 "y.tab.c"
    break;

  case 54:
#line 168 "parser.y"
                                                    {{ (yyval.functionCall)=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); (yyval.functionCall)->functionIdentifier=(yyvsp[-3].identifier); (yyval.functionCall)->arguments=(yyvsp[-1].exprList); (yyval.functionCall)->isDirectFormula=1; }}
#line 1915 "y.tab.c"
    break;

  case 55:
#line 171 "parser.y"
                                             {{ (yyval.variableDeclarationList)=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); (yyval.variableDeclarationList)->current=(yyvsp[0].variableDeclaration); (yyval.variableDeclarationList)->next=NULL; }}
#line 1921 "y.tab.c"
    break;

  case 56:
#line 172 "parser.y"
                                                {{ (yyval.variableDeclarationList)=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); (yyval.variableDeclarationList)->current=(yyvsp[-1].variableDeclaration); (yyval.variableDeclarationList)->next=(yyvsp[0].variableDeclarationList); }}
#line 1927 "y.tab.c"
    break;

  case 57:
#line 175 "parser.y"
                                                    {{ (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=NULL; (yyval.functionDeclaration)->name=NULL; (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=(yyvsp[-1].body); }}
#line 1933 "y.tab.c"
    break;

  case 58:
#line 178 "parser.y"
                                                        {{ (yyval.functionDeclaration)=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); (yyval.functionDeclaration)->returnType=NULL; (yyval.functionDeclaration)->name=NULL; (yyval.functionDeclaration)->argList=NULL; (yyval.functionDeclaration)->body=(yyvsp[-1].body); }}
#line 1939 "y.tab.c"
    break;

  case 59:
#line 181 "parser.y"
                                                                          {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-3].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-3].tokenText)); (yyval.structDeclaration)->declarations=(yyvsp[-1].variableDeclarationList); (yyval.structDeclaration)->serialize=NULL; (yyval.structDeclaration)->deserialize=NULL; }}
#line 1945 "y.tab.c"
    break;

  case 60:
#line 182 "parser.y"
                                   {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-2].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-2].tokenText)); (yyval.structDeclaration)->declarations=NULL; (yyval.structDeclaration)->serialize=NULL; (yyval.structDeclaration)->deserialize=NULL; }}
#line 1951 "y.tab.c"
    break;

  case 61:
#line 183 "parser.y"
                                                                                           {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-5].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-5].tokenText)); (yyval.structDeclaration)->declarations=(yyvsp[-3].variableDeclarationList); (yyval.structDeclaration)->serialize=(yyvsp[-2].functionDeclaration); (yyval.structDeclaration)->deserialize=(yyvsp[-1].functionDeclaration); }}
#line 1957 "y.tab.c"
    break;

  case 62:
#line 184 "parser.y"
                                                                   {{ (yyval.structDeclaration)=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); (yyval.structDeclaration)->name=malloc(strlen((yyvsp[-4].tokenText))+1); strcpy((yyval.structDeclaration)->name,(yyvsp[-4].tokenText)); (yyval.structDeclaration)->declarations=NULL; (yyval.structDeclaration)->serialize=(yyvsp[-2].functionDeclaration); (yyval.structDeclaration)->deserialize=(yyvsp[-1].functionDeclaration);  }}
#line 1963 "y.tab.c"
    break;

  case 63:
#line 187 "parser.y"
                                                              {{ (yyval.structInstantiation)=(struct StructInstantiationNode *)malloc(sizeof(struct StructInstantiationNode)); (yyval.structInstantiation)->identifier=(yyvsp[-3].identifier); (yyval.structInstantiation)->arguments=(yyvsp[-1].exprList); }}
#line 1969 "y.tab.c"
    break;

  case 64:
#line 190 "parser.y"
                                  {{ (yyval.stringLiteral)=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); (yyval.stringLiteral)->value=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.stringLiteral)->value, (yyvsp[0].tokenText)); }}
#line 1975 "y.tab.c"
    break;

  case 65:
#line 191 "parser.y"
                       {{ (yyval.stringLiteral)=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); (yyval.stringLiteral)->value=malloc(strlen((yyvsp[0].tokenText))+1); strcpy((yyval.stringLiteral)->value, (yyvsp[0].tokenText)); }}
#line 1981 "y.tab.c"
    break;

  case 66:
#line 194 "parser.y"
                                                                {{ (yyval.ternary)=(struct TernaryNode *)malloc(sizeof(struct TernaryNode)); (yyval.ternary)->condition=(yyvsp[-4].booleanExpression); (yyval.ternary)->ifTrue=(yyvsp[-2].expression); (yyval.ternary)->ifFalse=(yyvsp[0].expression); }}
#line 1987 "y.tab.c"
    break;

  case 67:
#line 197 "parser.y"
                                                                     {{ (yyval.namespaceDeclaration)=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); (yyval.namespaceDeclaration)->identifier=(yyvsp[-3].identifier); (yyval.namespaceDeclaration)->body=(yyvsp[-1].body); }}
#line 1993 "y.tab.c"
    break;

  case 68:
#line 198 "parser.y"
                                              {{ (yyval.namespaceDeclaration)=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); (yyval.namespaceDeclaration)->identifier=(yyvsp[-2].identifier); (yyval.namespaceDeclaration)->body=NULL; }}
#line 1999 "y.tab.c"
    break;

  case 69:
#line 201 "parser.y"
                         {{ (yyval.returnStatement)=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); (yyval.returnStatement)->value=NULL; }}
#line 2005 "y.tab.c"
    break;

  case 70:
#line 202 "parser.y"
                                {{ (yyval.returnStatement)=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); (yyval.returnStatement)->value=(yyvsp[-1].expression); }}
#line 2011 "y.tab.c"
    break;

  case 71:
#line 205 "parser.y"
                              {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_VAR_DEFINITION; (yyval.statement)->value.varDefinition=(yyvsp[0].variableDefinition); }}
#line 2017 "y.tab.c"
    break;

  case 72:
#line 206 "parser.y"
                      {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_STRUCT_DECLARATION; (yyval.statement)->value.structDeclaration=(yyvsp[0].structDeclaration); }}
#line 2023 "y.tab.c"
    break;

  case 73:
#line 207 "parser.y"
                         {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_NAMESPACE_DECLARATION; (yyval.statement)->value.namespaceDeclaration=(yyvsp[0].namespaceDeclaration); }}
#line 2029 "y.tab.c"
    break;

  case 74:
#line 208 "parser.y"
                         {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_EXPRESSION; (yyval.statement)->value.expression=(yyvsp[-1].expression); }}
#line 2035 "y.tab.c"
    break;

  case 75:
#line 209 "parser.y"
                        {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_FUNCTION_DECLARATION; (yyval.statement)->value.functionDeclaration=(yyvsp[0].functionDeclaration); }}
#line 2041 "y.tab.c"
    break;

  case 76:
#line 210 "parser.y"
           {{ (yyval.statement)=(struct StatementNode *)malloc(sizeof(struct StatementNode)); (yyval.statement)->type=STMT_NODE_TYPE_RETURN_STATEMENT; (yyval.statement)->value.returnStatement=(yyvsp[0].returnStatement); }}
#line 2047 "y.tab.c"
    break;

  case 77:
#line 213 "parser.y"
                {{ (yyval.body)=(struct BodyNode *)malloc(sizeof(struct BodyNode)); (yyval.body)->current=(yyvsp[0].statement); (yyval.body)->next=NULL; }}
#line 2053 "y.tab.c"
    break;

  case 78:
#line 214 "parser.y"
                   {{ (yyval.body)=(struct BodyNode *)malloc(sizeof(struct BodyNode)); (yyval.body)->current=(yyvsp[-1].statement); (yyval.body)->next=(yyvsp[0].body); }}
#line 2059 "y.tab.c"
    break;

  case 79:
#line 217 "parser.y"
         {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=NULL; (yyval.program)->body=NULL; head=(yyval.program); }}
#line 2065 "y.tab.c"
    break;

  case 80:
#line 218 "parser.y"
         {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=NULL; (yyval.program)->body=(yyvsp[0].body); head=(yyval.program); }}
#line 2071 "y.tab.c"
    break;

  case 81:
#line 219 "parser.y"
            {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=(yyvsp[0].imports); (yyval.program)->body=NULL; head=(yyval.program); }}
#line 2077 "y.tab.c"
    break;

  case 82:
#line 220 "parser.y"
                 {{ (yyval.program)=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); (yyval.program)->imports=(yyvsp[-1].imports); (yyval.program)->body=(yyvsp[0].body); head=(yyval.program); }}
#line 2083 "y.tab.c"
    break;


#line 2087 "y.tab.c"

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
#line 223 "parser.y"


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
