#pragma once


struct IdentifierTextNode {
  char *text;
  struct IdentifierTextNode *next;
};

enum IdentifierNodeType {
  ID_NODE_TYPE_TEXT,
  ID_NODE_TYPE_SELF,
};

struct IdentifierNode {
  enum IdentifierNodeType type;
  struct IdentifierTextNode *text;
};

struct ImportsNode {
  struct StringLiteralNode *path;
  char *alias;
  struct ImportsNode *next;
};

enum MultiplyExpressionType {
  MUL_NODE_TYPE_LITERAL,
  MUL_NODE_TYPE_IDENTIFIER,
  MUL_NODE_TYPE_FUNCTION_CALL,
  MUL_NODE_TYPE_TIMES,
  MUL_NODE_TYPE_DIVIDE,
};

struct MultiplyExpressionNode {
  enum MultiplyExpressionType type;
  union {
    char *literalValue;
    struct IdentifierNode *identifier;
    struct FunctionCallNode *functionCall;
    struct {
      struct MultiplyExpressionNode *left;
      struct MultiplyExpressionNode *right;
    } sides;
  } value;
};

enum ExpressionNodeType {
  EXPR_NODE_TYPE_MULTIPLY_EXPRESSION,
  EXPR_NODE_TYPE_PLUS,
  EXPR_NODE_TYPE_MINUS,
  EXPR_NODE_TYPE_BOOLEAN,
  EXPR_NODE_TYPE_STRUCT_INSTANTIATION,
  EXPR_NODE_TYPE_STRING_LITERAL,
  EXPR_NODE_TYPE_TERNARY
};

struct ExpressionNode {
  enum ExpressionNodeType type;
  union {
    struct MultiplyExpressionNode *multiplyExpression;
    struct BooleanExpressionNode *booleanExpression;
    struct StructInstantiationNode *structInstantiation;
    struct StringLiteralNode *stringLiteral;
    struct TernaryNode *ternary;
    struct {
      struct ExpressionNode *left;
      struct ExpressionNode *right;
    } sides;
  } value;
};

enum BooleanExpressionNodeType {
  BOOL_NODE_TYPE_TRUE,
  BOOL_NODE_TYPE_FALSE,
  BOOL_NODE_TYPE_IDENTIFIER,
  BOOL_NODE_TYPE_EQ,
  BOOL_NODE_TYPE_NEQ,
  BOOL_NODE_TYPE_LT,
  BOOL_NODE_TYPE_GT,
  BOOL_NODE_TYPE_LE,
  BOOL_NODE_TYPE_GE,
  BOOL_NODE_TYPE_AND,
  BOOL_NODE_TYPE_OR,
  BOOL_NODE_TYPE_NOT,
};

struct BooleanExpressionNode {
  enum BooleanExpressionNodeType type;
  union {
    struct IdentifierNode *identifier;
    struct {
      struct ExpressionNode *left;
      struct ExpressionNode *right;
    } children;
    struct ExpressionNode *child;
  } value;
};

enum TypeNodeType {
  TYPE_NODE_TYPE_TEXT,
  TYPE_NODE_TYPE_NUMBER,
  TYPE_NODE_TYPE_LOGICAL,
  TYPE_NODE_TYPE_VOID,
  TYPE_NODE_TYPE_IDENTIFIER,
};

struct TypeNode {
  enum TypeNodeType type;
  struct IdentifierNode *identifier;
};

struct VariableDeclarationNode {
  struct TypeNode *variableType;
  char *name;
};

struct VariableDefinitionNode {
  struct TypeNode *variableType;
  char *name;
  struct ExpressionNode *expression;
};

struct ArgListNode {
  struct TypeNode *argumentType;
  char *argumentName;
  struct ArgListNode *next;
};

struct FunctionDeclarationNode {
  struct TypeNode *returnType;
  char *name;
  struct ArgListNode *argList;
  struct BodyNode *body;
};

struct ExpressionListNode {
  struct ExpressionNode *expression;
  struct ExpressionListNode *next;
};

struct FunctionCallNode {
  struct IdentifierNode *functionIdentifier;
  struct ExpressionListNode *arguments; 
  unsigned char isDirectFormula;
};

struct VariableDeclarationListNode {
  struct VariableDeclarationNode *current;
  struct VariableDeclarationListNode *next;
};

struct StructDeclarationNode {
  char *name;
  struct VariableDeclarationListNode *declarations;
};

struct StructInstantiationNode {
  struct IdentifierNode *identifier;
  struct ExpressionListNode *arguments;
};

struct StringLiteralNode {
  char *value;
};

struct TernaryNode {
  struct BooleanExpressionNode *condition;
  struct ExpressionNode *ifTrue;
  struct ExpressionNode *ifFalse;
};

struct NamespaceDeclarationNode {
  struct IdentifierNode *identifier;
  struct BodyNode *body;
};

struct ReturnStatementNode {
  struct ExpressionNode *value;
};

enum StatementNodeType {
  STMT_NODE_TYPE_VAR_DEFINITION,
  STMT_NODE_TYPE_STRUCT_DECLARATION,
  STMT_NODE_TYPE_NAMESPACE_DECLARATION,
  STMT_NODE_TYPE_EXPRESSION,
  STMT_NODE_TYPE_FUNCTION_DECLARATION,
  STMT_NODE_TYPE_RETURN_STATEMENT,
};

struct StatementNode {
  enum StatementNodeType type;
  union {
    struct VariableDefinitionNode *varDefinition;
    struct StructDeclarationNode *structDeclaration;
    struct NamespaceDeclarationNode *namespaceDeclaration;
    struct ExpressionNode *expression;
    struct FunctionDeclarationNode *functionDeclaration;
    struct ReturnStatementNode *returnStatement;
  } value;
};

struct BodyNode {
  struct StatementNode *current;
  struct BodyNode *next;
};

struct ProgramNode {
  struct ImportsNode *imports;
  struct BodyNode *body;
};

#define FOR_ALL_NODE_TYPES \
  X(IdentifierTextNode) \
  X(IdentifierNode) \
  X(ImportsNode) \
  X(MultiplyExpressionNode) \
  X(ExpressionNode) \
  X(BooleanExpressionNode) \
  X(TypeNode) \
  X(VariableDeclarationNode) \
  X(VariableDefinitionNode) \
  X(ArgListNode) \
  X(FunctionDeclarationNode) \
  X(ExpressionListNode) \
  X(FunctionCallNode) \
  X(VariableDeclarationListNode) \
  X(StructDeclarationNode) \
  X(StructInstantiationNode) \
  X(StringLiteralNode) \
  X(TernaryNode) \
  X(NamespaceDeclarationNode) \
  X(ReturnStatementNode) \
  X(StatementNode) \
  X(BodyNode) \
  X(ProgramNode)
