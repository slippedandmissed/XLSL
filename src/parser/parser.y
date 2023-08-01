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
  struct ExpressionNode *makeZeroExpressionNode();

  struct ProgramNode *head;

%}

%union {
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
}


%token <tokenText> IMPORT AS NAMESPACE STRUCT
%token <tokenText> SERIALIZE DESERIALIZE
%token <tokenText> SELF
%token <tokenText> TRUE FALSE
%token <tokenText> TEXT LOGICAL NUMBERTOKEN VOID
%token <tokenText> RETURN
%token <tokenText> NUMBER SINGLEQUOTEDSTRING DOUBLEQUOTEDSTRING
%token <tokenText> ID
%token <tokenText> PLUS MINUS TIMES DIVIDE
%token <tokenText> EQ NEQ LT GT LE GE
%token <tokenText> AND OR NOT
%token <tokenText> ASSIGN
%token <tokenText> COMMA SEMICOLON COLON QUESTION DOT DOLLAR
%token <tokenText> OPENPAREN CLOSEPAREN
%token <tokenText> OPENCURLY CLOSECURLY

%type <identifierText> identifierText
%type <identifier> identifier
%type <imports> imports
%type <multiplyExpression> multiplyExpression
%type <expression> expression
%type <booleanExpression> booleanExpression
%type <type> type
%type <variableDeclaration> variableDeclaration
%type <variableDefinition> variableDefinition
%type <argList> argList
%type <functionDeclaration> functionDeclaration
%type <exprList> exprList
%type <functionCall> functionCall
%type <variableDeclarationList> variableDeclarationList
%type <functionDeclaration> serializeBlock deserializeBlock
%type <structDeclaration> structDeclaration
%type <structInstantiation> structInstantiation
%type <stringLiteral> stringLiteral
%type <namespaceDeclaration> namespaceDeclaration
%type <returnStatement> return
%type <ternary> ternary
%type <statement> statement
%type <body> body
%type <program> program

%start program

%%

identifierText: ID { $$=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); $$->text=malloc(strlen($1)+1); strcpy($$->text, $1); $$->next = NULL; }
  | ID DOT identifierText { $$=(struct IdentifierTextNode *)malloc(sizeof(struct IdentifierTextNode)); $$->text=malloc(strlen($1)+1); strcpy($$->text, $1); $$->next = $3; }
  ;

identifier: identifierText {{ $$=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); $$->type=ID_NODE_TYPE_TEXT; $$->text=$1; }}
  | SELF {{ $$=(struct IdentifierNode *)malloc(sizeof(struct IdentifierNode)); $$->type=ID_NODE_TYPE_SELF; $$->text=NULL; }}
  ;

imports: IMPORT stringLiteral AS ID SEMICOLON { $$=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); $$->path=$2; $$->alias=malloc(strlen($4)+1); strcpy($$->alias, $4); $$->next=NULL; }
  | IMPORT stringLiteral AS ID SEMICOLON imports { $$=(struct ImportsNode *)malloc(sizeof(struct ImportsNode)); $$->path=$2; $$->alias=malloc(strlen($4)+1); strcpy($$->alias, $4); $$->next=$6; }
  ;

multiplyExpression: NUMBER { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_LITERAL; $$->value.literalValue=malloc(strlen($1)+1); strcpy($$->value.literalValue, $1); }
  | identifier { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_IDENTIFIER; $$->value.identifier = $1; }
  | functionCall { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_FUNCTION_CALL; $$->value.functionCall = $1; }
  | OPENPAREN multiplyExpression CLOSEPAREN { $$ = $2; }
  | multiplyExpression TIMES multiplyExpression { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_TIMES; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | multiplyExpression DIVIDE multiplyExpression { $$=(struct MultiplyExpressionNode *)malloc(sizeof(struct MultiplyExpressionNode)); $$->type = MUL_NODE_TYPE_DIVIDE; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  ;

expression: multiplyExpression { $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type = EXPR_NODE_TYPE_MULTIPLY_EXPRESSION; $$->value.multiplyExpression = $1; }
  | expression PLUS expression { $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type = EXPR_NODE_TYPE_PLUS; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | expression MINUS expression { $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type = EXPR_NODE_TYPE_MINUS; $$->value.sides.left = $1; $$->value.sides.right = $3; }
  | MINUS expression { $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type = EXPR_NODE_TYPE_MINUS; $$->value.sides.left=makeZeroExpressionNode(); $$->value.sides.right = $2; }
  | booleanExpression {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_BOOLEAN; $$->value.booleanExpression=$1; }}
  | structInstantiation {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_STRUCT_INSTANTIATION; $$->value.structInstantiation=$1; }}
  | stringLiteral {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_STRING_LITERAL; $$->value.stringLiteral=$1; }}
  | ternary {{ $$=(struct ExpressionNode *)malloc(sizeof(struct ExpressionNode)); $$->type=EXPR_NODE_TYPE_TERNARY; $$->value.ternary=$1; }}
  | OPENPAREN expression CLOSEPAREN { $$ = $2; }
  ;

booleanExpression: TRUE { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_TRUE; }
  | FALSE { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_FALSE; }
  | identifier { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_IDENTIFIER; $$->value.identifier = $1; }
  | OPENPAREN booleanExpression CLOSEPAREN { $$ = $2; }
  | expression EQ expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_EQ; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression NEQ expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_NEQ; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression LT expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_LT; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression GT expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_GT; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression LE expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_LE; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression GE expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_GE; $$->value.children.left = $1; $$->value.children.right = $3; }
  | NOT expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_NOT; $$->value.child = $2; }
  | expression AND expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_AND; $$->value.children.left = $1; $$->value.children.right = $3; }
  | expression OR expression { $$=(struct BooleanExpressionNode *)malloc(sizeof(struct BooleanExpressionNode)); $$->type = BOOL_NODE_TYPE_OR; $$->value.children.left = $1; $$->value.children.right = $3; }
  ;

type: TEXT { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_TEXT; }
  | NUMBERTOKEN { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_NUMBER; }
  | LOGICAL { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_LOGICAL; }
  | VOID { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_VOID; }
  | identifier { $$=(struct TypeNode *)malloc(sizeof(struct TypeNode)); $$->type = TYPE_NODE_TYPE_IDENTIFIER; $$->identifier = $1; }
  ;

variableDeclaration: type ID SEMICOLON { $$=(struct VariableDeclarationNode *)malloc(sizeof(struct VariableDeclarationNode)); $$->variableType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); }
  ;

variableDefinition: type ID ASSIGN expression SEMICOLON {{ $$=(struct VariableDefinitionNode *)malloc(sizeof(struct VariableDefinitionNode)); $$->variableType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); $$->expression=$4; }}
  ;

argList: type ID { $$=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); $$->argumentType=$1; $$->argumentName=malloc(strlen($2)+1); strcpy($$->argumentName, $2); $$->next=NULL; }
  | type ID COMMA argList { $$=(struct ArgListNode *)malloc(sizeof(struct ArgListNode)); $$->argumentType=$1; $$->argumentName=malloc(strlen($2)+1); strcpy($$->argumentName, $2); $$->next=$4; }
  ;

functionDeclaration: type ID OPENPAREN CLOSEPAREN OPENCURLY body CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); $$->argList=NULL; $$->body=$6; }
  | type ID OPENPAREN CLOSEPAREN OPENCURLY CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); $$->argList=NULL; $$->body=NULL; }
  | type ID OPENPAREN argList CLOSEPAREN OPENCURLY body CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); $$->argList=$4; $$->body=$7; }
  | type ID OPENPAREN argList CLOSEPAREN OPENCURLY CLOSECURLY { $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=$1; $$->name=malloc(strlen($2)+1); strcpy($$->name, $2); $$->argList=$4; $$->body=NULL; }
  ;

exprList: expression {{ $$=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); $$->expression=$1; $$->next=NULL; }}
  | expression COMMA exprList {{ $$=(struct ExpressionListNode *)malloc(sizeof(struct ExpressionListNode)); $$->expression=$1; $$->next=$3; }}
  ;

functionCall: identifier OPENPAREN CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$1; $$->arguments=NULL; $$->isDirectFormula=0; }}
  | identifier OPENPAREN exprList CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$1; $$->arguments=$3; $$->isDirectFormula=0; }}
  | DOLLAR identifier OPENPAREN CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$2; $$->arguments=NULL; $$->isDirectFormula=1; }}
  | DOLLAR identifier OPENPAREN exprList CLOSEPAREN {{ $$=(struct FunctionCallNode *)malloc(sizeof(struct FunctionCallNode)); $$->functionIdentifier=$2; $$->arguments=$4; $$->isDirectFormula=1; }}
  ;

variableDeclarationList: variableDeclaration {{ $$=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); $$->current=$1; $$->next=NULL; }}
  | variableDeclaration variableDeclarationList {{ $$=(struct VariableDeclarationListNode *)malloc(sizeof(struct VariableDeclarationListNode)); $$->current=$1; $$->next=$2; }}
  ;

serializeBlock: SERIALIZE OPENCURLY body CLOSECURLY {{ $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=NULL; $$->name=NULL; $$->argList=NULL; $$->body=$3; }}
  ;

deserializeBlock: DESERIALIZE OPENCURLY body CLOSECURLY {{ $$=(struct FunctionDeclarationNode *)malloc(sizeof(struct FunctionDeclarationNode)); $$->returnType=NULL; $$->name=NULL; $$->argList=NULL; $$->body=$3; }}
  ;

structDeclaration: STRUCT ID OPENCURLY variableDeclarationList CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(strlen($2)+1); strcpy($$->name,$2); $$->declarations=$4; $$->serialize=NULL; $$->deserialize=NULL; }}
  | STRUCT ID OPENCURLY CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(strlen($2)+1); strcpy($$->name,$2); $$->declarations=NULL; $$->serialize=NULL; $$->deserialize=NULL; }}
  | STRUCT ID OPENCURLY variableDeclarationList serializeBlock deserializeBlock CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(strlen($2)+1); strcpy($$->name,$2); $$->declarations=$4; $$->serialize=$5; $$->deserialize=$6; }}
  | STRUCT ID OPENCURLY serializeBlock deserializeBlock CLOSECURLY {{ $$=(struct StructDeclarationNode *)malloc(sizeof(struct StructDeclarationNode)); $$->name=malloc(strlen($2)+1); strcpy($$->name,$2); $$->declarations=NULL; $$->serialize=$4; $$->deserialize=$5;  }}
  ;

structInstantiation: identifier OPENCURLY exprList CLOSECURLY {{ $$=(struct StructInstantiationNode *)malloc(sizeof(struct StructInstantiationNode)); $$->identifier=$1; $$->arguments=$3; }}
  ;

stringLiteral: DOUBLEQUOTEDSTRING {{ $$=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); $$->value=malloc(strlen($1)+1); strcpy($$->value, $1); }}
  | SINGLEQUOTEDSTRING {{ $$=(struct StringLiteralNode *)malloc(sizeof(struct StringLiteralNode)); $$->value=malloc(strlen($1)+1); strcpy($$->value, $1); }}
  ;

ternary: booleanExpression QUESTION expression COLON expression {{ $$=(struct TernaryNode *)malloc(sizeof(struct TernaryNode)); $$->condition=$1; $$->ifTrue=$3; $$->ifFalse=$5; }}
  ;

namespaceDeclaration: NAMESPACE identifier OPENCURLY body CLOSECURLY {{ $$=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); $$->identifier=$2; $$->body=$4; }}
  | NAMESPACE identifier OPENCURLY CLOSECURLY {{ $$=(struct NamespaceDeclarationNode *)malloc(sizeof(struct NamespaceDeclarationNode)); $$->identifier=$2; $$->body=NULL; }}
  ;

return: RETURN SEMICOLON {{ $$=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); $$->value=NULL; }}
  | RETURN expression SEMICOLON {{ $$=(struct ReturnStatementNode *)malloc(sizeof(struct ReturnStatementNode)); $$->value=$2; }}
  ;

statement: variableDefinition {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_VAR_DEFINITION; $$->value.varDefinition=$1; }}
  | structDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_STRUCT_DECLARATION; $$->value.structDeclaration=$1; }}
  | namespaceDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_NAMESPACE_DECLARATION; $$->value.namespaceDeclaration=$1; }}
  | expression SEMICOLON {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_EXPRESSION; $$->value.expression=$1; }}
  | functionDeclaration {{ $$=(struct StatementNode *)malloc(sizeof(struct StatementNode)); $$->type=STMT_NODE_TYPE_FUNCTION_DECLARATION; $$->value.functionDeclaration=$1; }}
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
