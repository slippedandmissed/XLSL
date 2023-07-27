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
    TEXT = 265,
    LOGICAL = 266,
    NUMBERTOKEN = 267,
    VOID = 268,
    RETURN = 269,
    NUMBER = 270,
    SINGLEQUOTEDSTRING = 271,
    DOUBLEQUOTEDSTRING = 272,
    ID = 273,
    PLUS = 274,
    MINUS = 275,
    TIMES = 276,
    DIVIDE = 277,
    EQ = 278,
    NEQ = 279,
    LT = 280,
    GT = 281,
    LE = 282,
    GE = 283,
    AND = 284,
    OR = 285,
    NOT = 286,
    ASSIGN = 287,
    COMMA = 288,
    SEMICOLON = 289,
    DOT = 290,
    OPENPAREN = 291,
    CLOSEPAREN = 292,
    OPENCURLY = 293,
    CLOSECURLY = 294
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
#define TEXT 265
#define LOGICAL 266
#define NUMBERTOKEN 267
#define VOID 268
#define RETURN 269
#define NUMBER 270
#define SINGLEQUOTEDSTRING 271
#define DOUBLEQUOTEDSTRING 272
#define ID 273
#define PLUS 274
#define MINUS 275
#define TIMES 276
#define DIVIDE 277
#define EQ 278
#define NEQ 279
#define LT 280
#define GT 281
#define LE 282
#define GE 283
#define AND 284
#define OR 285
#define NOT 286
#define ASSIGN 287
#define COMMA 288
#define SEMICOLON 289
#define DOT 290
#define OPENPAREN 291
#define CLOSEPAREN 292
#define OPENCURLY 293
#define CLOSECURLY 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

  char *tokenText;
  struct IdentifierNode *identifierNode;
  struct ImportsNode *imports;
  struct MultiplyExpressionNode *multiplyExpression;
  struct ArithmeticExpressionNode *arithmeticExpression;
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
  struct ExpressionNode *expression;
  struct NamespaceDeclarationNode *namespaceDeclaration;
  struct ReturnStatementNode *returnStatement;
  struct IfStatementNode *ifStatement;
  struct StatementNode *statement;
  struct BodyNode *body;
  struct ProgramNode *program;

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
