%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include "node_types.h"
  #include "lex.yy.c"

  void yyerror(const char *s);
  int yylex();
  int yywrap();

%}

%union {
  char *tokenText;
  struct IdentifierNode identifierNode;
  struct ImportsNode imports;
  struct MultiplyExpressionNode multiplyExpression;
}


%token <tokenText> IMPORT NAMESPACE STRUCT
%token <tokenText> IF ELSE
%token <tokenText> TRUE FALSE NULLTOKEN
%token <tokenText> UINT8 INT8 UINT16 INT16 UINT32 INT32 UINT64 INT64 BOOL VOID
%token <tokenText> RETURN
%token <tokenText> NUMBER ID
%token <tokenText> PLUS MINUS TIMES DIVIDE
%token <tokenText> EQ NEQ LT GT LE GE
%token <tokenText> AND OR NOT
%token <tokenText> ASSIGN
%token <tokenText> COMMA SEMICOLON DOT
%token <tokenText> OPENPAREN CLOSEPAREN
%token <tokenText> OPENCURLY CLOSECURLY

%type <identifierNode> identifier
%type <imports> imports
%type <multiplyExpression> multiplyExpression

%start program

%%

identifier: ID { $$.text=malloc(sizeof($1)); strcpy($$.text, $1); $$.next = NULL; }
  | ID DOT identifier { $$.text=malloc(sizeof($1)); strcpy($$.text, $1); $$.next = &$3; }
  ;

imports: IMPORT identifier SEMICOLON { $$.identifier=&$2; $$.next=NULL; }
  | IMPORT identifier SEMICOLON imports { $$.identifier=&$2; $$.next=&$4; }
  ;

multiplyExpression: NUMBER { $$.type = MUL_NODE_TYPE_NUMBER; $$.value.rawValue=malloc(sizeof($1)); strcpy($$.value.rawValue, $1); }
  | identifier { $$.type = MUL_NODE_TYPE_IDENTIFIER; $$.value.identifier = &$1; }
  | OPENPAREN multiplyExpression CLOSEPAREN { $$ = $2; }
  | multiplyExpression TIMES multiplyExpression { $$.type = MUL_NODE_TYPE_TIMES; $$.value.sides.left = &$1; $$.value.sides.right = &$3; }
  | multiplyExpression DIVIDE multiplyExpression { $$.type = MUL_NODE_TYPE_DIVIDE; $$.value.sides.left = &$1; $$.value.sides.right = &$3; }
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
  | imports body
  ;

%%

int main() {
    yyparse();
}
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
