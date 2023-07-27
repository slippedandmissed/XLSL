#pragma once

struct IdentifierNode {
  char *text;
  struct IdentifierNode *next;
};

struct ImportsNode {
  struct IdentifierNode *identifier;
  struct ImportsNode *next;
};

enum MultiplyExpressionType {
  MUL_NODE_TYPE_LITERAL,
  MUL_NODE_TYPE_IDENTIFIER,
  MUL_NODE_TYPE_TIMES,
  MUL_NODE_TYPE_DIVIDE
};

struct MultiplyExpressionNode {
  enum MultiplyExpressionType type;
  union {
    char *literalValue;
    struct IdentifierNode *identifier;
    struct {
      struct MultiplyExpressionNode *left;
      struct MultiplyExpressionNode *right;
    } sides;
  } value;
};

enum ArithmeticExpressionNodeType {
  ARITH_NODE_TYPE_MULTIPLY_EXPRESSION,
  ARITH_NODE_TYPE_PLUS,
  ARITH_NODE_TYPE_MINUS,
};

struct ArithmeticExpressionNode {
  enum ArithmeticExpressionNodeType type;
  union {
    struct MultiplyExpressionNode *child;
    struct {
      struct ArithmeticExpressionNode *left;
      struct ArithmeticExpressionNode *right;
    } sides;
  } value;
};

enum BooleanExpressionNodeType {
  BOOL_NODE_TYPE_TRUE,
  BOOL_NODE_TYPE_FALSE,
  BOOL_NODE_TYPE_IDENTIFIER,
  BOOL_NODE_TYPE_ARITH_EQ,
  BOOL_NODE_TYPE_ARITH_NEQ,
  BOOL_NODE_TYPE_LT,
  BOOL_NODE_TYPE_GT,
  BOOL_NODE_TYPE_LE,
  BOOL_NODE_TYPE_GE,
  BOOL_NODE_TYPE_AND,
  BOOL_NODE_TYPE_OR,
  BOOL_NODE_TYPE_NOT,
  BOOL_NODE_TYPE_BOOL_EQ,
  BOOL_NODE_TYPE_BOOL_NEQ,
};

struct BooleanExpressionNode {
  enum BooleanExpressionNodeType type;
  union {
    struct IdentifierNode *identifier;
    struct {
      struct ArithmeticExpressionNode *left;
      struct ArithmeticExpressionNode *right;
    } arithChildren;
    struct {
      struct BooleanExpressionNode *left;
      struct BooleanExpressionNode *right;
    } boolChildren;
    struct BooleanExpressionNode *child;
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

struct VariableAssignmentNode {
  struct IdentifierNode *identifier;
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

enum ExpressionNodeType {
  EXPR_NODE_TYPE_ARITHMETIC,
  EXPR_NODE_TYPE_BOOLEAN,
  EXPR_NODE_TYPE_FUNC_CALL,
  EXPR_NODE_TYPE_STRUCT_INSTANTIATION,
  EXPR_NODE_TYPE_STRING_LITERAL,
};

struct ExpressionNode {
  enum ExpressionNodeType type;
  union {
    struct ArithmeticExpressionNode *arithmeticExpression;
    struct BooleanExpressionNode *booleanExpression;
    struct FunctionCallNode *functionCall;
    struct StructInstantiationNode *structInstantiation;
    struct StringLiteralNode *stringLiteral;
  } value;
};

struct NamespaceDeclarationNode {
  struct IdentifierNode *identifier;
  struct BodyNode *body;
};

struct ReturnStatementNode {
  struct ExpressionNode *value;
};

struct IfStatementNode {
  struct BooleanExpressionNode *condition;
  struct BodyNode *ifBody;
  struct BodyNode *elseBody;
};

enum StatementNodeType {
  STMT_NODE_TYPE_VAR_ASSIGNMENT,
  STMT_NODE_TYPE_VAR_DECLARATION,
  STMT_NODE_TYPE_VAR_DEFINITION,
  STMT_NODE_TYPE_STRUCT_DECLARATION,
  STMT_NODE_TYPE_NAMESPACE_DECLARATION,
  STMT_NODE_TYPE_EXPRESSION,
  STMT_NODE_TYPE_FUNCTION_DECLARATION,
  STMT_NODE_TYPE_IF_STATEMENT,
  STMT_NODE_TYPE_RETURN_STATEMENT,
};

struct StatementNode {
  enum StatementNodeType type;
  union {
    struct VariableAssignmentNode *varAssignment;
    struct VariableDeclarationNode *varDeclaration;
    struct VariableDefinitionNode *varDefinition;
    struct StructDeclarationNode *structDeclaration;
    struct NamespaceDeclarationNode *namespaceDeclaration;
    struct ExpressionNode *expression;
    struct FunctionDeclarationNode *functionDeclaration;
    struct IfStatementNode *ifStatement;
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