%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%token IMPORT NAMESPACE STRUCT
%token IF ELSE
%token TRUE FALSE NULLTOKEN
%token UINT8 INT8 UINT16 INT16 UINT32 INT32 UINT64 INT64 BOOL VOID
%token RETURN
%token NUMBER ID
%token PLUS MINUS TIMES DIVIDE
%token EQ NEQ LT GT LE GE
%token AND OR NOT
%token ASSIGN
%token COMMA SEMICOLON DOT
%token OPENPAREN CLOSEPAREN
%token OPENCURLY CLOSECURLY
%start program

%%

identifier: ID
  | ID DOT identifier
  ;

import: IMPORT identifier
  | import import
  ;

multiplyExpression: NUMBER
  | identifier
  | OPENPAREN multiplyExpression CLOSEPAREN
  | multiplyExpression TIMES multiplyExpression
  | multiplyExpression DIVIDE multiplyExpression
  ;

arithmeticExpression: multiplyExpression
  | arithmeticExpression PLUS arithmeticExpression
  | arithmeticExpression MINUS arithmeticExpression
  | OPENPAREN arithmeticExpression CLOSEPAREN
  ;

booleanExpression: TRUE
  | FALSE
  | identifier
  | OPENPAREN booleanExpression CLOSEPAREN
  | arithmeticExpression EQ arithmeticExpression
  | arithmeticExpression NEQ arithmeticExpression
  | arithmeticExpression LT arithmeticExpression
  | arithmeticExpression GT arithmeticExpression
  | arithmeticExpression LE arithmeticExpression
  | arithmeticExpression GE arithmeticExpression
  | booleanExpression AND booleanExpression
  | booleanExpression OR booleanExpression
  | NOT booleanExpression
  | booleanExpression EQ booleanExpression
  | booleanExpression NEQ booleanExpression
  ;

type: UINT8
  | INT8
  | UINT16
  | INT16
  | UINT32
  | INT32
  | UINT64
  | INT64
  | BOOL
  | VOID
  | identifier
  ;

variableDeclaration: type ID SEMICOLON
  ;

variableDefinition: type ID ASSIGN expression SEMICOLON
  ;

variableAssignment: identifier ASSIGN expression SEMICOLON
  ;

argList: type ID
  | argList COMMA argList
  ;

functionDeclaration: type ID OPENPAREN CLOSEPAREN OPENCURLY body CLOSECURLY
  | type ID OPENPAREN argList CLOSEPAREN OPENCURLY body CLOSECURLY
  ;

exprList: expression
  | exprList COMMA exprList
  ;

functionCall: identifier OPENPAREN CLOSEPAREN
  | identifier OPENPAREN exprList CLOSEPAREN
  ;

declarationList:
  | variableDeclaration declarationList
  ;

structDeclaration: STRUCT ID OPENCURLY declarationList CLOSECURLY
  ;

structCreation: identifier OPENCURLY exprList CLOSECURLY
  ;

expression: arithmeticExpression
  | booleanExpression
  | functionCall
  | structCreation
  | NULLTOKEN
  | OPENPAREN expression CLOSEPAREN
  ;

namespaceDeclaration: NAMESPACE identifier OPENCURLY body CLOSECURLY
  ;

return: RETURN SEMICOLON
  | RETURN expression SEMICOLON
  ;

statement: variableAssignment
  | variableDeclaration
  | variableDefinition
  | structDeclaration
  | namespaceDeclaration
  | expression SEMICOLON
  | functionDeclaration
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY body CLOSECURLY
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY body CLOSECURLY ELSE OPENCURLY body CLOSECURLY
  | return
  ;

body:
  | statement body
  ;

program: body
  | import body
  ;

%%

int main() {
    yyparse();
}
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
