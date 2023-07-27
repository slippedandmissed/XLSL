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

  struct ProgramNode *head;

%}

%union {
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
}


%token <tokenText> IMPORT NAMESPACE STRUCT
%token <tokenText> IF ELSE
%token <tokenText> TRUE FALSE
%token <tokenText> TEXT LOGICAL NUMBERTOKEN VOID
%token <tokenText> RETURN
%token <tokenText> NUMBER SINGLEQUOTEDSTRING DOUBLEQUOTEDSTRING
%token <tokenText> ID
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
%type <arithmeticExpression> arithmeticExpression
%type <booleanExpression> booleanExpression
%type <type> type
%type <variableDeclaration> variableDeclaration
%type <variableDefinition> variableDefinition
%type <variableAssignment> variableAssignment
%type <argList> argList
%type <functionDeclaration> functionDeclaration
%type <exprList> exprList
%type <functionCall> functionCall
%type <variableDeclarationList> variableDeclarationList
%type <structDeclaration> structDeclaration
%type <structInstantiation> structInstantiation
%type <stringLiteral> stringLiteral
%type <expression> expression
%type <namespaceDeclaration> namespaceDeclaration
%type <returnStatement> return
%type <ifStatement> ifStatement
%type <statement> statement
%type <body> body
%type <program> program

%start program

%%

identifier: ID { $$=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); $$->text=malloc(sizeof($1)); strcpy($$->text, $1); $$->next = NULL; }
  | ID DOT identifier { $$=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); $$->text=malloc(sizeof($1)); strcpy($$->text, $1); $$->next = $3; }
  ;

imports: IMPORT identifier SEMICOLON { $$=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); $$->identifier=$2; $$->next=NULL; }
  | IMPORT identifier SEMICOLON imports { $$=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); $$->identifier=$2; $$->next=$4; }
  ;

multiplyExpression: NUMBER { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_LITERAL; $$->value.literalValue=malloc(sizeof($1)); strcpy($$->value.literalValue, $1); }
  | identifier { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_IDENTIFIER; $$->value.identifier = $1; }
  | OPENPAREN multiplyExpression CLOSEPAREN { $$ = $2; }
  | multiplyExpression TIMES multiplyExpression { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_TIMES; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | multiplyExpression DIVIDE multiplyExpression { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_DIVIDE; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  ;

arithmeticExpression: multiplyExpression { $$=(struct ArithmeticExpressionNode *)malloc(sizeof(struct ArithmeticExpressionNode)); $$->type = ARITH_NODE_TYPE_MULTIPLY_EXPRESSION; $$->value.child = $1; }
  | arithmeticExpression PLUS arithmeticExpression { $$=(struct ArithmeticExpressionNode *)malloc(sizeof(struct ArithmeticExpressionNode)); $$->type = ARITH_NODE_TYPE_PLUS; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | arithmeticExpression MINUS arithmeticExpression { $$=(struct ArithmeticExpressionNode *)malloc(sizeof(struct ArithmeticExpressionNode)); $$->type = ARITH_NODE_TYPE_MINUS; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | OPENPAREN arithmeticExpression CLOSEPAREN { $$ = $2; }
  ;

booleanExpression: TRUE { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_TRUE; }
  | FALSE { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_FALSE; }
  | identifier { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_IDENTIFIER; $$->value.identifier = $1; }
  | OPENPAREN booleanExpression CLOSEPAREN { $$ = $2; }
  | arithmeticExpression EQ arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_ARITH_EQ; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | arithmeticExpression NEQ arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_ARITH_NEQ; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | arithmeticExpression LT arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_LT; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | arithmeticExpression GT arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_GT; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | arithmeticExpression LE arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_LE; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | arithmeticExpression GE arithmeticExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_GE; $$->value.arithChildren.left = $1; $$->value.arithChildren.right = $3; }
  | booleanExpression AND booleanExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_AND; $$->value.boolChildren.left = $1; $$->value.boolChildren.right = $3; }
  | booleanExpression OR booleanExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_OR; $$->value.boolChildren.left = $1; $$->value.boolChildren.right = $3; }
  | NOT booleanExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_NOT; $$->value.child = $2; }
  | booleanExpression EQ booleanExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_BOOL_EQ; $$->value.boolChildren.left = $1; $$->value.boolChildren.right = $3; }
  | booleanExpression NEQ booleanExpression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_BOOL_NEQ; $$->value.boolChildren.left = $1; $$->value.boolChildren.right = $3; }
  ;

type: TEXT { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_TEXT; }
  | NUMBERTOKEN { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_NUMBER; }
  | LOGICAL { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_LOGICAL; }
  | VOID { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_VOID; }
  | identifier { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_IDENTIFIER; $$->identifier = $1; }
  ;

variableDeclaration: type ID SEMICOLON { $$=(struct VariableDeclarationNode *)malloc(sizeof(struct VariableDeclarationNode)); $$->variableType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); }
  ;

variableDefinition: type ID ASSIGN expression SEMICOLON {{ $$=(struct VariableDefinitionNode *)malloc(sizeof(struct VariableDefinitionNode)); $$->variableType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); $$->expression=$4; }}
  ;

variableAssignment: identifier ASSIGN expression SEMICOLON {{ $$=(struct VariableAssignmentNode *)malloc(sizeof(struct VariableAssignmentNode)); $$->identifier=$1; $$->expression=$3; }}
  ;

argList: type ID { $$=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); $$->argumentType=$1; $$->argumentName=malloc(sizeof($2)); strcpy($$->argumentName, $2); $$->next=NULL; }
  | type ID COMMA argList { $$=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); $$->argumentType=$1; $$->argumentName=malloc(sizeof($2)); strcpy($$->argumentName, $2); $$->next=$4; }
  ;

functionDeclaration: type ID OPENPAREN CLOSEPAREN OPENCURLY body CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); $$->argList=NULL; $$->body=$6; }
  | type ID OPENPAREN CLOSEPAREN OPENCURLY CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); $$->argList=NULL; $$->body=NULL; }
  | type ID OPENPAREN argList CLOSEPAREN OPENCURLY body CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); $$->argList=$4; $$->body=$7; }
  | type ID OPENPAREN argList CLOSEPAREN OPENCURLY CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(sizeof($2)); strcpy($$->name, $2); $$->argList=$4; $$->body=NULL; }
  ;

exprList: expression {{ $$=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); $$->expression=$1; $$->next=NULL; }}
  | expression COMMA exprList {{ $$=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); $$->expression=$1; $$->next=$3; }}
  ;

functionCall: identifier OPENPAREN CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$1; $$->arguments=NULL; }}
  | identifier OPENPAREN exprList CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$1; $$->arguments=$3; }}
  ;

variableDeclarationList: variableDeclaration {{ $$=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); $$->current=$1; $$->next=NULL; }}
  | variableDeclaration variableDeclarationList {{ $$=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); $$->current=$1; $$->next=$2; }}
  ;

structDeclaration: STRUCT ID OPENCURLY variableDeclarationList CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(sizeof($2)); strcpy($$->name,$2); $$->declarations=$4; }}
  | STRUCT ID OPENCURLY CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(sizeof($2)); strcpy($$->name,$2); $$->declarations=NULL; }}
  ;

structInstantiation: identifier OPENCURLY exprList CLOSECURLY {{ $$=(struct StructInstantiationNode *)malloc(sizeof(struct StructInstantiationNode)); $$->identifier=$1; $$->arguments=$3; }}
  ;

stringLiteral: DOUBLEQUOTEDSTRING {{ $$=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); $$->value=malloc(sizeof($1)); strcpy($$->value, $1); }}
  | SINGLEQUOTEDSTRING {{ $$=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); $$->value=malloc(sizeof($1)); strcpy($$->value, $1); }}
  ;

expression: arithmeticExpression {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_ARITHMETIC; $$->value.arithmeticExpression=$1; }}
  | booleanExpression {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_BOOLEAN; $$->value.booleanExpression=$1; }}
  | functionCall {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_FUNC_CALL; $$->value.functionCall=$1; }}
  | structInstantiation {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_STRUCT_INSTANTIATION; $$->value.structInstantiation=$1; }}
  | stringLiteral {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_STRING_LITERAL; $$->value.stringLiteral=$1; }}
  | OPENPAREN expression CLOSEPAREN {{ $$=$2; }}
  ;

namespaceDeclaration: NAMESPACE identifier OPENCURLY body CLOSECURLY {{ $$=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); $$->identifier=$2; $$->body=$4; }}
  | NAMESPACE identifier OPENCURLY CLOSECURLY {{ $$=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); $$->identifier=$2; $$->body=NULL; }}
  ;

return: RETURN SEMICOLON {{ $$=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); $$->value=NULL; }}
  | RETURN expression SEMICOLON {{ $$=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); $$->value=$2; }}
  ;

ifStatement: IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY body CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=$6; $$->elseBody=NULL; }}
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=NULL; $$->elseBody=NULL; }}
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY body CLOSECURLY ELSE OPENCURLY body CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=$6; $$->elseBody=$10; }}
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY body CLOSECURLY ELSE OPENCURLY CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=$6; $$->elseBody=NULL; }}
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY CLOSECURLY ELSE OPENCURLY body CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=NULL; $$->elseBody=$9; }}
  | IF OPENPAREN booleanExpression CLOSEPAREN OPENCURLY CLOSECURLY ELSE OPENCURLY CLOSECURLY {{ $$=(struct IfStatementNode *)malloc(sizeof(struct IfStatementNode)); $$->condition=$3; $$->ifBody=NULL; $$->elseBody=NULL; }}
  ;

statement: variableAssignment {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_VAR_ASSIGNMENT; $$->value.varAssignment=$1; }}
  | variableDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_VAR_DECLARATION; $$->value.varDeclaration=$1; }}
  | variableDefinition {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_VAR_DEFINITION; $$->value.varDefinition=$1; }}
  | structDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_STRUCT_DECLARATION; $$->value.structDeclaration=$1; }}
  | namespaceDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_NAMESPACE_DECLARATION; $$->value.namespaceDeclaration=$1; }}
  | expression SEMICOLON {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_EXPRESSION; $$->value.expression=$1; }}
  | functionDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_FUNCTION_DECLARATION; $$->value.functionDeclaration=$1; }}
  | ifStatement {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_IF_STATEMENT; $$->value.ifStatement=$1; }}
  | return {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_RETURN_STATEMENT; $$->value.returnStatement=$1; }}
  ;

body: statement {{ $$=(struct BodyNode *)malloc(sizeof(struct BodyNode)); $$->current=$1; $$->next=NULL; }}
  | statement body {{ $$=(struct BodyNode *)malloc(sizeof(struct BodyNode)); $$->current=$1; $$->next=$2; }}
  ;

program: {{ $$=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); $$->imports=NULL; $$->body=NULL; head=$$; }}
  | body {{ $$=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); $$->imports=NULL; $$->body=$1; head=$$; }}
  | imports {{ $$=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); $$->imports=$1; $$->body=NULL; head=$$; }}
  | imports body {{ $$=(struct ProgramNode *)malloc(sizeof(struct ProgramNode)); $$->imports=$1; $$->body=$2; head=$$; }}
  ;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
