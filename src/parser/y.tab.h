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

#line 173 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
