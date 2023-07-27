/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    IF = 261,
    ELSE = 262,
    TRUE = 263,
    FALSE = 264,
    NULLTOKEN = 265,
    UINT8 = 266,
    INT8 = 267,
    UINT16 = 268,
    INT16 = 269,
    UINT32 = 270,
    INT32 = 271,
    UINT64 = 272,
    INT64 = 273,
    BOOL = 274,
    VOID = 275,
    RETURN = 276,
    NUMBER = 277,
    ID = 278,
    PLUS = 279,
    MINUS = 280,
    TIMES = 281,
    DIVIDE = 282,
    EQ = 283,
    NEQ = 284,
    LT = 285,
    GT = 286,
    LE = 287,
    GE = 288,
    AND = 289,
    OR = 290,
    NOT = 291,
    ASSIGN = 292,
    COMMA = 293,
    SEMICOLON = 294,
    DOT = 295,
    OPENPAREN = 296,
    CLOSEPAREN = 297,
    OPENCURLY = 298,
    CLOSECURLY = 299
  };
#endif
/* Tokens.  */
#define IMPORT 258
#define NAMESPACE 259
#define STRUCT 260
#define IF 261
#define ELSE 262
#define TRUE 263
#define FALSE 264
#define NULLTOKEN 265
#define UINT8 266
#define INT8 267
#define UINT16 268
#define INT16 269
#define UINT32 270
#define INT32 271
#define UINT64 272
#define INT64 273
#define BOOL 274
#define VOID 275
#define RETURN 276
#define NUMBER 277
#define ID 278
#define PLUS 279
#define MINUS 280
#define TIMES 281
#define DIVIDE 282
#define EQ 283
#define NEQ 284
#define LT 285
#define GT 286
#define LE 287
#define GE 288
#define AND 289
#define OR 290
#define NOT 291
#define ASSIGN 292
#define COMMA 293
#define SEMICOLON 294
#define DOT 295
#define OPENPAREN 296
#define CLOSEPAREN 297
#define OPENCURLY 298
#define CLOSECURLY 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
