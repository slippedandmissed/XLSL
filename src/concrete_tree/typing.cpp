#include <iostream>
#include "concrete_tree.hpp"

using namespace ConcreteTree;

Type Expression::getType()
{
  if (this->m_type.has_value())
  {
    return this->m_type.value();
  }

  Type type;
  switch (this->type)
  {
  case Expression::ExpressionType::NUMBER_LITERAL:
  {
    type.type = Type::TypeType::NUMBER;
    break;
  }
  case Expression::ExpressionType::STRING_LITERAL:
  {
    type.type = Type::TypeType::TEXT;
    break;
  }
  case Expression::ExpressionType::TRUE_LITERAL:
  {
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::FALSE_LITERAL:
  {
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::VARIABLE:
  {
    type = std::get<std::shared_ptr<Variable>>(this->value)->type;
    break;
  }
  case Expression::ExpressionType::FUNCTION_CALL:
  {
    type = std::get<Expression::FunctionCallData>(this->value).function->returnType;
    break;
  }
  case Expression::ExpressionType::DIRECT_FORMULA_ACCESS:
  {
    // TODO: implement
    break;
  }
  case Expression::ExpressionType::STRUCT_INSTANTIATION:
  {
    type.type = Type::TypeType::CUSTOM_STRUCT;
    type.struct_ = std::get<Expression::StructInstantiationData>(this->value).struct_;
    break;
  }
  case Expression::ExpressionType::TERNARY:
  {
    auto data = std::get<Expression::TernaryData>(this->value);
    auto ifTrueType = data.ifTrue->getType();
    // TODO: Should make sure that the "if false" type matches
    type = ifTrueType;
    break;
  }
  case Expression::ExpressionType::PLUS:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto leftType = data.left->getType();
    switch (leftType.type)
    {
    case Type::TypeType::NUMBER:
      type.type = Type::TypeType::NUMBER;
      break;
    case Type::TypeType::TEXT:
      type.type = Type::TypeType::TEXT;
      break;
    default:
      std::cerr << "Cannot use '+' operator with the following type: " << std::endl
                << data.left->toString(0) << std::endl;
      exit(1);
    }
    // TODO: Should make sure that the "right" type matches
    break;
  }
  case Expression::ExpressionType::MINUS:
      // TODO: should check that both sides are `NUMBER` type
      type.type = Type::TypeType::NUMBER;
  {
    break;
  }
  case Expression::ExpressionType::TIMES:
      // TODO: should check that both sides are `NUMBER` type
      type.type = Type::TypeType::NUMBER;
  {
    break;
  }
  case Expression::ExpressionType::DIVIDE:
      // TODO: should check that both sides are `NUMBER` type
      type.type = Type::TypeType::NUMBER;
  {
    break;
  }
  case Expression::ExpressionType::EQ:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::NEQ:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::LT:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::LE:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::GT:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::GE:
  {
    // TODO: should check that both operands are appropriate types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::AND:
  {
    // TODO: should check that both operands are `LOGICAL` types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::OR:
  {
    // TODO: should check that both operands are `LOGICAL` types
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  case Expression::ExpressionType::NOT:
  {
    // TODO: should check that the operand is `LOGICAL` type
    type.type = Type::TypeType::LOGICAL;
    break;
  }
  }

  this->m_type = std::make_optional(type);
  return type;
}