#include <vector>
#include "print_ast.hpp"

#define ADD_NODE(X) stringVal += "\n" + AST::nodeToString((X), indent + 2);

std::string AST::nodeToString(IdentifierTextNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "IdentifierTextNode: " + node.text;
  if (node.next != nullptr)
  {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(IdentifierNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "IdentifierNode";
  switch (node.type)
  {
  case ID_NODE_TYPE_SELF:
    stringVal += ": SELF";
    break;
  case ID_NODE_TYPE_TEXT:
    ADD_NODE(*node.text)
    break;
  }
  return stringVal;
}

std::string AST::nodeToString(ImportsNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ImportsNode (" + node.alias + ")";
  ADD_NODE(*node.path);
  if (node.next != nullptr)
  {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(MultiplyExpressionNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "MultiplyExpressionNode";
  switch (node.type) {
    case MUL_NODE_TYPE_DIVIDE:
      stringVal += ": DIVIDE";
      ADD_NODE(*node.value.sides.left)
      ADD_NODE(*node.value.sides.right)
      break;
    case MUL_NODE_TYPE_FUNCTION_CALL:
      ADD_NODE(*node.value.functionCall)
      break;
    case MUL_NODE_TYPE_IDENTIFIER:
      ADD_NODE(*node.value.identifier)
      break;
    case MUL_NODE_TYPE_LITERAL:
      stringVal += ": LITERAL(";
      stringVal += node.value.literalValue;
      stringVal += ")";
      break;
    case MUL_NODE_TYPE_TIMES:
      stringVal += ": TIMES";
      ADD_NODE(*node.value.sides.left)
      ADD_NODE(*node.value.sides.right)
      break;
  }
  return stringVal;
}

std::string AST::nodeToString(ExpressionNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ExpressionNode";
  switch (node.type) {
    case EXPR_NODE_TYPE_BOOLEAN:
      ADD_NODE(*node.value.booleanExpression)
      break;
    case EXPR_NODE_TYPE_MINUS:
      stringVal += ": MINUS";
      ADD_NODE(*node.value.sides.left)
      ADD_NODE(*node.value.sides.right)
      break;
    case EXPR_NODE_TYPE_MULTIPLY_EXPRESSION:
      ADD_NODE(*node.value.multiplyExpression)
      break;
    case EXPR_NODE_TYPE_PLUS:
      stringVal += ": PLUS";
      ADD_NODE(*node.value.sides.left)
      ADD_NODE(*node.value.sides.right)
      break;
    case EXPR_NODE_TYPE_STRING_LITERAL:
      ADD_NODE(*node.value.stringLiteral)
      break;
    case EXPR_NODE_TYPE_STRUCT_INSTANTIATION:
      ADD_NODE(*node.value.structInstantiation)
      break;
    case EXPR_NODE_TYPE_TERNARY:
      ADD_NODE(*node.value.ternary)
      break;
  }
  return stringVal;
}

std::string AST::nodeToString(BooleanExpressionNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "BooleanExpressionNode";
  switch (node.type) {
    case BOOL_NODE_TYPE_AND:
      stringVal += ": AND";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_EQ:
      stringVal += ": EQ";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_FALSE:
      stringVal += ": FALSE";
      break;
    case BOOL_NODE_TYPE_GE:
      stringVal += ": GE";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_GT:
      stringVal += ": GT";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_IDENTIFIER:
      ADD_NODE(*node.value.identifier)
      break;
    case BOOL_NODE_TYPE_LE:
      stringVal += ": LE";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_LT:
      stringVal += ": LT";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_NEQ:
      stringVal += ": NEQ";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_NOT:
      stringVal += ": NOT";
      ADD_NODE(*node.value.child)
      break;
    case BOOL_NODE_TYPE_OR:
      stringVal += ": OR";
      ADD_NODE(*node.value.children.left)
      ADD_NODE(*node.value.children.right)
      break;
    case BOOL_NODE_TYPE_TRUE:
      stringVal += ": TRUE";
      break;
  }
  return stringVal;
}

std::string AST::nodeToString(TypeNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "TypeNode";
  switch (node.type) {
    case TYPE_NODE_TYPE_IDENTIFIER:
      ADD_NODE(*node.identifier)
      break;
    case TYPE_NODE_TYPE_LOGICAL:
      stringVal += ": LOGICAL";
      break;
    case TYPE_NODE_TYPE_NUMBER:
      stringVal += ": NUMBER";
      break;
    case TYPE_NODE_TYPE_TEXT:
      stringVal += ": TEXT";
      break;
    case TYPE_NODE_TYPE_VOID:
      stringVal += ": VOID";
      break;
  }
  return stringVal;
}

std::string AST::nodeToString(VariableDeclarationNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "VariableDeclarationNode: " + node.name;
  ADD_NODE(*node.variableType)
  return stringVal;
}

std::string AST::nodeToString(VariableDefinitionNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "VariableDefinitionNode: " + node.name;
  ADD_NODE(*node.variableType)
  ADD_NODE(*node.expression)
  return stringVal;
}

std::string AST::nodeToString(ArgListNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ArgListNode: " + node.argumentName;
  ADD_NODE(*node.argumentType)
  if (node.next != nullptr)
  {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(FunctionDeclarationNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "FunctionDeclarationNode: " + node.name;
  if (node.argList != nullptr)
  {
    ADD_NODE(*node.argList)
  }
  if (node.body != nullptr)
  {
    ADD_NODE(*node.body)
  }
  return stringVal;
}

std::string AST::nodeToString(ExpressionListNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ExpressionListNode";
  ADD_NODE(*node.expression);
  if (node.next != nullptr) {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(FunctionCallNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "FunctionCallNode";
  ADD_NODE(*node.functionIdentifier)
  if (node.arguments != nullptr) {
    ADD_NODE(*node.arguments)
  }
  return stringVal;
}

std::string AST::nodeToString(VariableDeclarationListNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "VariableDeclarationListNode";
  ADD_NODE(*node.current)
  if (node.next != nullptr) {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(StructDeclarationNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "StructDeclarationNode: " + node.name;
  if (node.declarations != nullptr) {
    ADD_NODE(*node.declarations)
  }
  return stringVal;
}

std::string AST::nodeToString(StructInstantiationNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "StructInstantiationNode";
  ADD_NODE(*node.identifier)
  if (node.arguments != nullptr) {
    ADD_NODE(*node.arguments)
  }
  return stringVal;
}

std::string AST::nodeToString(StringLiteralNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "StringLiteralNode: \""+node.value;
  stringVal += "\"";
  return stringVal;
}

std::string AST::nodeToString(TernaryNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "TernaryNode";
  ADD_NODE(*node.condition)
  ADD_NODE(*node.ifTrue)
  ADD_NODE(*node.ifFalse)
  return stringVal;
}

std::string AST::nodeToString(NamespaceDeclarationNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "NamespaceDeclarationNode";
  ADD_NODE(*node.identifier)
  if (node.body != nullptr)
  {
    ADD_NODE(*node.body)
  }
  return stringVal;
}

std::string AST::nodeToString(ReturnStatementNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ReturnStatementNode";
  if (node.value != nullptr) {
    ADD_NODE(*node.value)
  }
  return stringVal;
}

std::string AST::nodeToString(StatementNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "StatementNode";
  switch (node.type)
  {
  case STMT_NODE_TYPE_EXPRESSION:
    ADD_NODE(*node.value.expression)
    break;
  case STMT_NODE_TYPE_FUNCTION_DECLARATION:
    ADD_NODE(*node.value.functionDeclaration)
    break;
  case STMT_NODE_TYPE_NAMESPACE_DECLARATION:
    ADD_NODE(*node.value.namespaceDeclaration)
    break;
  case STMT_NODE_TYPE_RETURN_STATEMENT:
    ADD_NODE(*node.value.returnStatement)
    break;
  case STMT_NODE_TYPE_STRUCT_DECLARATION:
    ADD_NODE(*node.value.structDeclaration)
    break;
  case STMT_NODE_TYPE_VAR_DEFINITION:
    ADD_NODE(*node.value.varDefinition)
    break;
  }
  return stringVal;
}

std::string AST::nodeToString(BodyNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "BodyNode";
  ADD_NODE(*node.current)
  if (node.next != nullptr)
  {
    ADD_NODE(*node.next)
  }
  return stringVal;
}

std::string AST::nodeToString(ProgramNode const &node, int indent)
{
  auto stringVal = std::string(indent, ' ') + "ProgramNode";
  if (node.imports != nullptr)
  {
    ADD_NODE(*node.imports)
  }
  if (node.body != nullptr)
  {
    ADD_NODE(*node.body)
  }
  return stringVal;
}

#define X(NodeType)                                                \
  std::ostream &operator<<(std::ostream &os, NodeType const &node) \
  {                                                                \
    return os << AST::nodeToString(node, 0);                       \
  }
FOR_ALL_NODE_TYPES
#undef X

#undef ADD_NODE