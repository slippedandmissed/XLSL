#include <sstream>
#include <algorithm>
#include "concrete_tree.hpp"

using namespace ConcreteTree;

std::string Namespace::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Namespace ";
  std::stringstream ss;
  ss << static_cast<const void *>(this);
  strValue += ss.str();

  std::vector<std::string> parts;
  auto current = this->parent;
  while (current != nullptr)
  {
    parts.push_back(current->name);
    current = current->parent;
  }
  std::reverse(parts.begin(), parts.end());

  strValue += "\n" + std::string(indent + 2, ' ') + "NAME: ";
  for (auto part : parts)
  {
    strValue += part + ".";
  }
  strValue += this->name;
  return strValue;
}

std::string Type::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Type";
  switch (this->type)
  {
  case Type::TypeType::CUSTOM_STRUCT:
    strValue += "\n" + this->struct_->toString(indent + 2);
    break;
  case Type::TypeType::LOGICAL:
    strValue += "\n" + std::string(indent + 2, ' ') + "LOGICAL";
    break;
  case Type::TypeType::NUMBER:
    strValue += "\n" + std::string(indent + 2, ' ') + "NUMBER";
    break;
  case Type::TypeType::TEXT:
    strValue += "\n" + std::string(indent + 2, ' ') + "TEXT";
    break;
  case Type::TypeType::VOID:
    strValue += "\n" + std::string(indent + 2, ' ') + "VOID";
    break;
  }
  return strValue;
}

std::string Variable::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Variable ";
  std::stringstream ss;
  ss << static_cast<const void *>(this);
  strValue += ss.str();
  strValue += "\n" + std::string(indent + 2, ' ') + "NAME: " + this->name;
  strValue += "\n" + this->type.toString(indent + 2);
  if (this->namespace_ != nullptr)
  {
    strValue += "\n" + this->namespace_->toString(indent + 2);
  }
  if (this->children.size() != 0)
  {
    strValue += "\n" + std::string(indent + 2, ' ') + "MEMBERS";
    for (auto child : this->children)
    {
      strValue += "\n" + child->toString(indent + 4);
    }
  }
  return strValue;
}

std::string Function::toString(int indent, bool brief) const
{
  std::string strValue = std::string(indent, ' ') + "Function ";
  std::stringstream ss;
  ss << static_cast<const void *>(this);
  strValue += ss.str();
  strValue += "\n" + this->namespace_->toString(indent + 2);
  strValue += "\n" + this->returnType.toString(indent + 2);
  strValue += "\n" + std::string(indent + 2, ' ') + "NAME: " + this->name;
  strValue += "\n" + std::string(indent + 2, ' ') + "ARGUMENTS";
  if (this->arguments.size() == 0)
  {
    strValue += "\n" + std::string(indent + 4, ' ') + "(Empty)";
  }
  else
  {
    for (auto arg : this->arguments)
    {
      strValue += "\n" + arg->toString(indent + 4);
    }
  }
  if (!brief)
  {
    strValue += "\n" + this->block->toString(indent + 2);
  }
  else
  {
    strValue += "\n" + std::string(indent + 2, ' ') + "[Function body omitted]";
  }
  return strValue;
}

std::string Struct::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Struct ";
  std::stringstream ss;
  ss << static_cast<const void *>(this);
  strValue += ss.str();
  strValue += "\n" + this->namespace_->toString(indent + 2);
  strValue += "\n" + std::string(indent + 2, ' ') + "NAME: " + this->name;
  strValue += "\n" + std::string(indent + 2, ' ') + "MEMBERS";
  if (this->members.size() == 0)
  {
    strValue += "\n" + std::string(indent + 4, ' ') + "(Empty)";
  }
  else
  {
    for (auto member : this->members)
    {
      strValue += "\n" + member.toString(indent + 4);
    }
  }

  return strValue;
}

std::string Scope::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Scope";
  if (this->functions.size() == 0 && this->structs.size() == 0 && this->variables.size() == 0)
  {
    strValue += "\n" + std::string(indent + 2, ' ') + "(Empty)";
  }
  else
  {
    for (auto function : this->functions)
    {
      strValue += "\n" + function->toString(indent + 2);
    }
    for (auto struct_ : this->structs)
    {
      strValue += "\n" + struct_->toString(indent + 2);
    }
    for (auto variable : this->variables)
    {
      strValue += "\n" + variable->toString(indent + 2);
    }
  }
  return strValue;
}

std::string Expression::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Expression";
  strValue += "\n" + std::string(indent + 2, ' ');
  switch (this->type)
  {
  case Expression::ExpressionType::NUMBER_LITERAL:
  {
    strValue += "NUMBER LITERAL";
    strValue += "\n" + std::string(indent + 4, ' ') + std::get<std::string>(this->value);
    break;
  }
  case Expression::ExpressionType::STRING_LITERAL:
  {
    strValue += "STRING LITERAL";
    strValue += "\n" + std::string(indent + 4, ' ') + "\"" + std::get<std::string>(this->value) + "\"";
    break;
  }
  case Expression::ExpressionType::TRUE_LITERAL:
  {
    strValue += "TRUE LITERAL";
    break;
  }
  case Expression::ExpressionType::FALSE_LITERAL:
  {
    strValue += "FALSE LITERAL";
    break;
  }
  case Expression::ExpressionType::VARIABLE:
  {
    strValue += "VARIABLE REFERENCE";
    auto data = std::get<std::shared_ptr<Variable>>(this->value);
    strValue += "\n" + data->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::FUNCTION_CALL:
  {
    strValue += "FUNCTION CALL";
    auto data = std::get<Expression::FunctionCallData>(this->value);
    strValue += "\n" + data.function->toString(indent + 4, true);
    strValue += "\n" + std::string(indent + 4, ' ') + "ARGUMENTS";
    if (data.arguments.size() == 0)
    {
      strValue += "\n" + std::string(indent + 6, ' ') + "(Empty)";
    }
    else
    {
      for (auto arg : data.arguments)
      {
        strValue += "\n" + arg->toString(indent + 6);
      }
    }
    break;
  }
  case Expression::ExpressionType::STRUCT_INSTANTIATION:
  {
    strValue += "STRUCT INSTANTIATION";
    auto data = std::get<Expression::StructInstantiationData>(this->value);
    strValue += "\n" + data.struct_->toString(indent + 4);
    strValue += "\n" + std::string(indent + 4, ' ') + "ARGUMENTS";
    if (data.arguments.size() == 0)
    {
      strValue += "\n" + std::string(indent + 6, ' ') + "(Empty)";
    }
    else
    {
      for (auto arg : data.arguments)
      {
        strValue += "\n" + arg->toString(indent + 6);
      }
    }
    break;
  }
  case Expression::ExpressionType::TERNARY:
  {
    strValue += "TERNARY";
    auto data = std::get<Expression::TernaryData>(this->value);
    strValue += "\n" + std::string(indent + 4, ' ') + "CONDITION";
    strValue += "\n" + data.condition->toString(indent + 6);
    strValue += "\n" + std::string(indent + 4, ' ') + "IF TRUE";
    strValue += "\n" + data.ifTrue->toString(indent + 6);
    strValue += "\n" + std::string(indent + 4, ' ') + "IF FALSE";
    strValue += "\n" + data.ifFalse->toString(indent + 6);
    break;
  }
  case Expression::ExpressionType::PLUS:
  {
    strValue += "PLUS";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::MINUS:
  {
    strValue += "MINUS";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::TIMES:
  {
    strValue += "TIMES";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::DIVIDE:
  {
    strValue += "DIVIDE";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::EQ:
  {
    strValue += "EQ";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::NEQ:
  {
    strValue += "NEQ";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::LT:
  {
    strValue += "LT";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::LE:
  {
    strValue += "LE";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::GT:
  {
    strValue += "GT";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::GE:
  {
    strValue += "GE";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::AND:
  {
    strValue += "AND";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::OR:
  {
    strValue += "OR";
    auto data = std::get<Expression::BinaryOpData>(this->value);
    strValue += "\n" + data.left->toString(indent + 4);
    strValue += "\n" + data.right->toString(indent + 4);
    break;
  }
  case Expression::ExpressionType::NOT:
  {
    strValue += "NOT";
    auto data = std::get<std::shared_ptr<Expression>>(this->value);
    strValue += "\n" + data->toString(indent + 4);
    break;
  }
  }
  return strValue;
}

std::string Statement::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Statement";
  switch (this->type)
  {
  case Statement::StatementType::EXPRESSION:
    strValue += "\n" + this->expression->toString(indent + 2);
    break;
  case Statement::StatementType::RETURN:
    strValue += "\n" + std::string(indent + 2, ' ') + "RETURN";
    if (this->expression != nullptr)
    {
      strValue += "\n" + this->expression->toString(indent + 4);
    }
    break;
  }
  return strValue;
}

std::string Block::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Block";
  if (this->statements.size() == 0)
  {
    strValue += "\n" + std::string(indent + 2, ' ') + "(Empty)";
  }
  else
  {
    for (auto statement : this->statements)
    {
      strValue += "\n" + statement->toString(indent + 2);
    }
  }
  return strValue;
}

std::string Program::toString(int indent) const
{
  std::string strValue = std::string(indent, ' ') + "Program";
  strValue += "\n" + this->block->toString(indent + 2);
  strValue += "\n" + this->scope.toString(indent + 2);
  return strValue;
}

std::ostream &operator<<(std::ostream &os, Program const &program)
{
  return os << program.toString(0);
}
