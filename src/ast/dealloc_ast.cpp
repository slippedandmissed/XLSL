#include <iostream>
#include "dealloc_ast.hpp"

void AST::deallocTree(IdentifierTextNode *node)
{
  free(node->text);
  if (node->next != nullptr)
  {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(IdentifierNode *node)
{
  switch (node->type)
  {
  case ID_NODE_TYPE_SELF:
    break;
  case ID_NODE_TYPE_TEXT:
    deallocTree(node->text);
    break;
  }
  free(node);
}

void AST::deallocTree(ImportsNode *node)
{
  AST::deallocTree(node->identifier);
  if (node->next != nullptr)
  {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(MultiplyExpressionNode *node)
{
  switch (node->type)
  {
  case MUL_NODE_TYPE_DIVIDE:
  case MUL_NODE_TYPE_TIMES:
    AST::deallocTree(node->value.sides.left);
    AST::deallocTree(node->value.sides.right);
    break;
  case MUL_NODE_TYPE_FUNCTION_CALL:
    AST::deallocTree(node->value.functionCall);
    break;
  case MUL_NODE_TYPE_IDENTIFIER:
    AST::deallocTree(node->value.identifier);
    break;
  case MUL_NODE_TYPE_LITERAL:
    free(node->value.literalValue);
    break;
  }
  free(node);
}

void AST::deallocTree(ExpressionNode *node)
{
  switch (node->type)
  {
  case EXPR_NODE_TYPE_BOOLEAN:
    AST::deallocTree(node->value.booleanExpression);
    break;
  case EXPR_NODE_TYPE_PLUS:
  case EXPR_NODE_TYPE_MINUS:
    AST::deallocTree(node->value.sides.left);
    AST::deallocTree(node->value.sides.right);
    break;
  case EXPR_NODE_TYPE_MULTIPLY_EXPRESSION:
    AST::deallocTree(node->value.multiplyExpression);
    break;
  case EXPR_NODE_TYPE_STRING_LITERAL:
    AST::deallocTree(node->value.stringLiteral);
    break;
  case EXPR_NODE_TYPE_STRUCT_INSTANTIATION:
    AST::deallocTree(node->value.structInstantiation);
    break;
  case EXPR_NODE_TYPE_TERNARY:
    AST::deallocTree(node->value.ternary);
    break;
  }
  free(node);
}

void AST::deallocTree(BooleanExpressionNode *node)
{
  switch (node->type)
  {
  case BOOL_NODE_TYPE_AND:
  case BOOL_NODE_TYPE_OR:
  case BOOL_NODE_TYPE_EQ:
  case BOOL_NODE_TYPE_NEQ:
  case BOOL_NODE_TYPE_LE:
  case BOOL_NODE_TYPE_LT:
  case BOOL_NODE_TYPE_GE:
  case BOOL_NODE_TYPE_GT:
    AST::deallocTree(node->value.children.left);
    AST::deallocTree(node->value.children.right);
    break;
  case BOOL_NODE_TYPE_NOT:
    AST::deallocTree(node->value.child);
    break;
  case BOOL_NODE_TYPE_IDENTIFIER:
    AST::deallocTree(node->value.identifier);
    break;
  case BOOL_NODE_TYPE_FALSE:
  case BOOL_NODE_TYPE_TRUE:
    break;
  }
  free(node);
}

void AST::deallocTree(TypeNode *node)
{
  switch (node->type)
  {
  case TYPE_NODE_TYPE_IDENTIFIER:
    AST::deallocTree(node->identifier);
    break;
  case TYPE_NODE_TYPE_LOGICAL:
  case TYPE_NODE_TYPE_NUMBER:
  case TYPE_NODE_TYPE_TEXT:
  case TYPE_NODE_TYPE_VOID:
    break;
  }
  free(node);
}

void AST::deallocTree(VariableDeclarationNode *node)
{
  AST::deallocTree(node->variableType);
  free(node->name);
  free(node);
}

void AST::deallocTree(VariableDefinitionNode *node)
{
  AST::deallocTree(node->variableType);
  free(node->name);
  AST::deallocTree(node->expression);
  free(node);
}

void AST::deallocTree(ArgListNode *node)
{
  AST::deallocTree(node->argumentType);
  free(node->argumentName);
  if (node->next != nullptr)
  {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(FunctionDeclarationNode *node)
{
  AST::deallocTree(node->returnType);
  free(node->name);
  if (node->argList != nullptr)
  {
    AST::deallocTree(node->argList);
  }
  if (node->body != nullptr)
  {
    AST::deallocTree(node->body);
  }
  free(node);
}

void AST::deallocTree(ExpressionListNode *node)
{
  AST::deallocTree(node->expression);
  if (node->next != nullptr) {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(FunctionCallNode *node)
{
  AST::deallocTree(node->functionIdentifier);
  if (node->arguments != nullptr) {
    AST::deallocTree(node->arguments);
  }
  free(node);
}

void AST::deallocTree(VariableDeclarationListNode *node)
{
  AST::deallocTree(node->current);
  if (node->next != nullptr) {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(StructDeclarationNode *node)
{
  free(node->name);
  if (node->declarations != nullptr) {
    AST::deallocTree(node->declarations);
  }
  free(node);
}

void AST::deallocTree(StructInstantiationNode *node)
{
  AST::deallocTree(node->identifier);
  if (node->arguments != nullptr) {
    AST::deallocTree(node->arguments);
  }
  free(node);
}

void AST::deallocTree(StringLiteralNode *node)
{
  free(node->value);
  free(node);
}

void AST::deallocTree(TernaryNode *node)
{
  AST::deallocTree(node->condition);
  AST::deallocTree(node->ifTrue);
  AST::deallocTree(node->ifFalse);
  free(node);
}

void AST::deallocTree(NamespaceDeclarationNode *node)
{
  AST::deallocTree(node->identifier);
  if (node->body != nullptr)
  {
    AST::deallocTree(node->body);
  }
  free(node);
}

void AST::deallocTree(ReturnStatementNode *node)
{
  if (node->value != nullptr)
  {
    AST::deallocTree(node->value);
  }
  free(node);
}

void AST::deallocTree(StatementNode *node)
{
  switch (node->type)
  {
  case STMT_NODE_TYPE_EXPRESSION:
    AST::deallocTree(node->value.expression);
    break;
  case STMT_NODE_TYPE_FUNCTION_DECLARATION:
    AST::deallocTree(node->value.functionDeclaration);
    break;
  case STMT_NODE_TYPE_NAMESPACE_DECLARATION:
    AST::deallocTree(node->value.namespaceDeclaration);
    break;
  case STMT_NODE_TYPE_RETURN_STATEMENT:
    AST::deallocTree(node->value.returnStatement);
    break;
  case STMT_NODE_TYPE_STRUCT_DECLARATION:
    AST::deallocTree(node->value.structDeclaration);

    break;
  case STMT_NODE_TYPE_VAR_DEFINITION:
    AST::deallocTree(node->value.varDefinition);
    break;
  }
  free(node);
}

void AST::deallocTree(BodyNode *node)
{
  AST::deallocTree(node->current);
  if (node->next != nullptr)
  {
    AST::deallocTree(node->next);
  }
  free(node);
}

void AST::deallocTree(ProgramNode *node)
{
  if (node->imports != nullptr)
  {
    AST::deallocTree(node->imports);
  }
  if (node->body != nullptr)
  {
    AST::deallocTree(node->body);
  }
  free(node);
}
