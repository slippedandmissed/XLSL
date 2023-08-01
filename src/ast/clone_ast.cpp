#include <iostream>
#include <string.h>
#include "clone_ast.hpp"

#define MALLOC_ME(NodeType) (NodeType *)malloc(sizeof(NodeType))

IdentifierTextNode *AST::cloneTree(IdentifierTextNode *src)
{
  auto newNode = MALLOC_ME(IdentifierTextNode);
  newNode->text = (char *)malloc(strlen(src->text) + 1);
  strcpy(newNode->text, src->text);
  if (src->next == nullptr)
  {
    newNode->next = nullptr;
  }
  else
  {
    newNode->next = AST::cloneTree(src->next);
  }
  return newNode;
}

IdentifierNode *AST::cloneTree(IdentifierNode *src)
{
  auto newNode = MALLOC_ME(IdentifierNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case ID_NODE_TYPE_SELF:
    break;
  case ID_NODE_TYPE_TEXT:
    newNode->text = AST::cloneTree(src->text);
    break;
  }
  return newNode;
}

ImportsNode *AST::cloneTree(ImportsNode *src)
{
  auto newNode = MALLOC_ME(ImportsNode);
  newNode->alias = (char *)malloc(strlen(src->alias)+1);
  strcpy(newNode->alias, src->alias);
  newNode->path = AST::cloneTree(src->path);
  if (src->next != nullptr) {
    newNode->next = AST::cloneTree(src->next);
  } else {
    newNode->next = nullptr;
  }
  return newNode;
}

MultiplyExpressionNode *AST::cloneTree(MultiplyExpressionNode *src)
{
  auto newNode = MALLOC_ME(MultiplyExpressionNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case MUL_NODE_TYPE_DIVIDE:
  case MUL_NODE_TYPE_TIMES:
    newNode->value.sides.left = AST::cloneTree(src->value.sides.left);
    newNode->value.sides.right = AST::cloneTree(src->value.sides.right);
    break;
  case MUL_NODE_TYPE_FUNCTION_CALL:
    newNode->value.functionCall = AST::cloneTree(src->value.functionCall);
    break;
  case MUL_NODE_TYPE_IDENTIFIER:
    newNode->value.identifier = AST::cloneTree(src->value.identifier);
    break;
  case MUL_NODE_TYPE_LITERAL:
    newNode->value.literalValue = (char *)malloc(strlen(src->value.literalValue)+1);
    strcpy(newNode->value.literalValue, src->value.literalValue);
    break;
  }
  return newNode;
}

ExpressionNode *AST::cloneTree(ExpressionNode *src)
{
  auto newNode = MALLOC_ME(ExpressionNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case EXPR_NODE_TYPE_BOOLEAN:
    newNode->value.booleanExpression = AST::cloneTree(src->value.booleanExpression);
    break;
  case EXPR_NODE_TYPE_PLUS:
  case EXPR_NODE_TYPE_MINUS:
    newNode->value.sides.left = AST::cloneTree(src->value.sides.left);
    newNode->value.sides.right = AST::cloneTree(src->value.sides.right);
    break;
  case EXPR_NODE_TYPE_MULTIPLY_EXPRESSION:
    newNode->value.multiplyExpression = AST::cloneTree(src->value.multiplyExpression);
    break;
  case EXPR_NODE_TYPE_STRING_LITERAL:
    newNode->value.stringLiteral = AST::cloneTree(src->value.stringLiteral);
    break;
  case EXPR_NODE_TYPE_STRUCT_INSTANTIATION:
    newNode->value.structInstantiation = AST::cloneTree(src->value.structInstantiation);
    break;
  case EXPR_NODE_TYPE_TERNARY:
    newNode->value.ternary = AST::cloneTree(src->value.ternary);
    break;
  }
  return newNode;
}

BooleanExpressionNode *AST::cloneTree(BooleanExpressionNode *src)
{
  auto newNode = MALLOC_ME(BooleanExpressionNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case BOOL_NODE_TYPE_AND:
  case BOOL_NODE_TYPE_OR:
  case BOOL_NODE_TYPE_EQ:
  case BOOL_NODE_TYPE_NEQ:
  case BOOL_NODE_TYPE_LE:
  case BOOL_NODE_TYPE_LT:
  case BOOL_NODE_TYPE_GE:
  case BOOL_NODE_TYPE_GT:
    newNode->value.children.left = AST::cloneTree(src->value.children.left);
    newNode->value.children.right = AST::cloneTree(src->value.children.right);
    break;
  case BOOL_NODE_TYPE_NOT:
    newNode->value.child = AST::cloneTree(src->value.child);
    break;
  case BOOL_NODE_TYPE_IDENTIFIER:
    newNode->value.identifier = AST::cloneTree(src->value.identifier);
    break;
  case BOOL_NODE_TYPE_FALSE:
  case BOOL_NODE_TYPE_TRUE:
    break;
  }
  return newNode;
}

TypeNode *AST::cloneTree(TypeNode *src)
{
  auto newNode = MALLOC_ME(TypeNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case TYPE_NODE_TYPE_IDENTIFIER:
    newNode->identifier = AST::cloneTree(src->identifier);
    break;
  case TYPE_NODE_TYPE_LOGICAL:
  case TYPE_NODE_TYPE_NUMBER:
  case TYPE_NODE_TYPE_TEXT:
  case TYPE_NODE_TYPE_VOID:
    break;
  }
  return newNode;
}

VariableDeclarationNode *AST::cloneTree(VariableDeclarationNode *src)
{
  auto newNode = MALLOC_ME(VariableDeclarationNode);
  newNode->name = (char *)malloc(strlen(src->name)+1);
  strcpy(newNode->name, src->name);
  newNode->variableType = AST::cloneTree(src->variableType);
  return newNode;
}

VariableDefinitionNode *AST::cloneTree(VariableDefinitionNode *src)
{
  auto newNode = MALLOC_ME(VariableDefinitionNode);
  newNode->name = (char *)malloc(strlen(src->name)+1);
  strcpy(newNode->name, src->name);
  newNode->variableType = AST::cloneTree(src->variableType);
  newNode->expression = AST::cloneTree(src->expression);
  return newNode;
}

ArgListNode *AST::cloneTree(ArgListNode *src)
{
  auto newNode = MALLOC_ME(ArgListNode);
  newNode->argumentType = AST::cloneTree(src->argumentType);
  newNode->argumentName = (char *)malloc(strlen(src->argumentName)+1);
  strcpy(newNode->argumentName, src->argumentName);
  if (src->next != nullptr)
  {
    newNode->next = AST::cloneTree(src->next);
  } else {
    newNode->next = nullptr;
  }
  return newNode;
}

FunctionDeclarationNode *AST::cloneTree(FunctionDeclarationNode *src)
{
  auto newNode = MALLOC_ME(FunctionDeclarationNode);
  if (src->returnType != nullptr) {
    newNode->returnType = AST::cloneTree(src->returnType);
  } else {
    newNode->returnType = nullptr;
  }
  if (src->name != nullptr) {
    newNode->name = (char *)malloc(strlen(src->name)+1);
    strcpy(newNode->name, src->name);
  } else {
    newNode->name = nullptr;
  }
  if (src->argList != nullptr)
  {
    newNode->argList = AST::cloneTree(src->argList);
  } else {
    newNode->argList = nullptr;
  }
  if (src->body != nullptr)
  {
    newNode->body = AST::cloneTree(src->body);
  } else {
    newNode->body = nullptr;
  }
  return newNode;
}

ExpressionListNode *AST::cloneTree(ExpressionListNode *src)
{
  auto newNode = MALLOC_ME(ExpressionListNode);
  newNode->expression = AST::cloneTree(src->expression);
  if (src->next != nullptr) {
    newNode->next = AST::cloneTree(src->next);
  } else {
    newNode->next = nullptr;
  }
  return newNode;
}

FunctionCallNode *AST::cloneTree(FunctionCallNode *src)
{
  auto newNode = MALLOC_ME(FunctionCallNode);
  newNode->functionIdentifier = AST::cloneTree(src->functionIdentifier);
  if (src->arguments != nullptr) {
    newNode->arguments = AST::cloneTree(src->arguments);
  } else {
    newNode->arguments = nullptr;
  }
  return newNode;
}

VariableDeclarationListNode *AST::cloneTree(VariableDeclarationListNode *src)
{
  auto newNode = MALLOC_ME(VariableDeclarationListNode);
  newNode->current = AST::cloneTree(src->current);
  if (src->next != nullptr) {
    newNode->next = AST::cloneTree(src->next);
  } else {
    newNode->next = nullptr;
  }
  return newNode;
}

StructDeclarationNode *AST::cloneTree(StructDeclarationNode *src)
{
  auto newNode = MALLOC_ME(StructDeclarationNode);
  newNode->name = (char *)malloc(strlen(src->name)+1);
  strcpy(newNode->name, src->name);
  if (src->declarations != nullptr) {
    newNode->declarations = AST::cloneTree(src->declarations);
  } else {
    newNode->declarations = nullptr;
  }
  if (src->serialize != nullptr) {
    newNode->serialize = AST::cloneTree(src->serialize);
    newNode->deserialize = AST::cloneTree(src->deserialize);
  } else {
    newNode->serialize = nullptr;
    newNode->deserialize = nullptr;
  }
  return newNode;
}

StructInstantiationNode *AST::cloneTree(StructInstantiationNode *src)
{
  auto newNode = MALLOC_ME(StructInstantiationNode);
  newNode->identifier = AST::cloneTree(src->identifier);
  if (src->arguments != nullptr) {
    newNode->arguments = AST::cloneTree(src->arguments);
  } else {
    newNode->arguments = nullptr;
  }
  return newNode;
}

StringLiteralNode *AST::cloneTree(StringLiteralNode *src)
{
  auto newNode = MALLOC_ME(StringLiteralNode);
  newNode->value = (char *)malloc(strlen(src->value)+1);
  strcpy(newNode->value, src->value);
  return newNode;
}

TernaryNode *AST::cloneTree(TernaryNode *src)
{
  auto newNode = MALLOC_ME(TernaryNode);
  newNode->condition = AST::cloneTree(src->condition);
  newNode->ifTrue = AST::cloneTree(src->ifTrue);
  newNode->ifFalse = AST::cloneTree(src->ifFalse);
  return newNode;
}

NamespaceDeclarationNode *AST::cloneTree(NamespaceDeclarationNode *src)
{
  auto newNode = MALLOC_ME(NamespaceDeclarationNode);
  newNode->identifier = AST::cloneTree(src->identifier);
  if (src->body != nullptr)
  {
    newNode->body =AST::cloneTree(src->body);
  } else {
    newNode->body = nullptr;
  }
  return newNode;
}

ReturnStatementNode *AST::cloneTree(ReturnStatementNode *src)
{
  auto newNode = MALLOC_ME(ReturnStatementNode);
  if (src->value != nullptr)
  {
    newNode->value = AST::cloneTree(src->value);
  } else {
    newNode->value = nullptr;
  }
  return newNode;
}

StatementNode *AST::cloneTree(StatementNode *src)
{
  auto newNode = MALLOC_ME(StatementNode);
  newNode->type = src->type;
  switch (newNode->type)
  {
  case STMT_NODE_TYPE_EXPRESSION:
    newNode->value.expression = AST::cloneTree(src->value.expression);
    break;
  case STMT_NODE_TYPE_FUNCTION_DECLARATION:
    newNode->value.functionDeclaration = AST::cloneTree(src->value.functionDeclaration);
    break;
  case STMT_NODE_TYPE_NAMESPACE_DECLARATION:
    newNode->value.namespaceDeclaration = AST::cloneTree(src->value.namespaceDeclaration);
    break;
  case STMT_NODE_TYPE_RETURN_STATEMENT:
    newNode->value.returnStatement = AST::cloneTree(src->value.returnStatement);
    break;
  case STMT_NODE_TYPE_STRUCT_DECLARATION:
    newNode->value.structDeclaration = AST::cloneTree(src->value.structDeclaration);
    break;
  case STMT_NODE_TYPE_VAR_DEFINITION:
    newNode->value.varDefinition = AST::cloneTree(src->value.varDefinition);
    break;
  }
  return newNode;
}

BodyNode *AST::cloneTree(BodyNode *src)
{
  auto newNode = MALLOC_ME(BodyNode);
  newNode->current = cloneTree(src->current);
  if (src->next != nullptr) {
    newNode->next = cloneTree(src->next);
  } else {
    newNode->next = nullptr;
  }
  return newNode;
}

ProgramNode *AST::cloneTree(ProgramNode *src)
{
  auto newNode = MALLOC_ME(ProgramNode);
  if (src->imports != nullptr)
  {
    newNode->imports = AST::cloneTree(src->imports);
  } else {
    newNode->imports = nullptr;
  }
  if (src->body != nullptr)
  {
    newNode->body = AST::cloneTree(src->body);
  } else {
    newNode->body = nullptr;
  }
  return newNode;
}

#undef MALLOC_ME