#include <iostream>
#include <algorithm>
#include "concrete_tree.hpp"

using namespace ConcreteTree;

void getAllArgumentNames(std::string header, std::shared_ptr<Variable> argument, std::vector<std::string> &list)
{
  auto argumentName = header + "\\" + argument->name;
  if (argument->children.size() == 0)
  {
    list.push_back(argumentName);
  }
  else
  {
    for (auto child : argument->children)
    {
      getAllArgumentNames(argumentName, child, list);
    }
  }
}

std::string Expression::getExcelFormula()
{
  if (this->m_excelFormula.has_value())
  {
    return this->m_excelFormula.value();
  }
  std::string formula;
  switch (this->type)
  {
  case Expression::ExpressionType::NUMBER_LITERAL:
  case Expression::ExpressionType::STRING_LITERAL:
  {
    formula = std::get<std::string>(this->value);
    break;
  }
  case Expression::ExpressionType::TRUE_LITERAL:
  {
    formula = "TRUE";
    break;
  }
  case Expression::ExpressionType::FALSE_LITERAL:
  {
    formula = "FALSE";
    break;
  }
  case Expression::ExpressionType::VARIABLE:
  {
    auto data = std::get<std::shared_ptr<Variable>>(this->value);
    auto currentlySearchingForVariable = data;
    bool found = false;
    std::string excelVarName = "_xlpm.\\INNER";
    auto currentNamespace = this->scope.context->namespace_;
    while (currentNamespace->parent != nullptr)
    {
      excelVarName += "\\" + currentNamespace->name;
      currentNamespace = currentNamespace->parent;
    }
    excelVarName += "\\" + this->scope.context->name;
    std::vector<std::string> searchParts;
    while (currentlySearchingForVariable != nullptr)
    {
      searchParts.push_back(currentlySearchingForVariable->name);
      for (auto variableDefinition : this->scope.variables)
      {
        auto variable = variableDefinition.first;
        if (variable == currentlySearchingForVariable)
        {
          found = true;
          auto expression = variableDefinition.second;
          std::reverse(searchParts.begin(), searchParts.end());
          if (expression == nullptr)
          {
            formula = excelVarName;
            for (auto part : searchParts)
            {
              formula += "\\" + part;
            }
          }
          else
          {
            for (std::size_t j = 1; j < searchParts.size(); j++)
            {
              auto exprData = std::get<Expression::StructInstantiationData>(expression->value);
              auto members = exprData.struct_->members;
              for (std::size_t i = 0; i < members.size(); i++)
              {
                if (members[i].name == searchParts[j])
                {
                  expression = exprData.arguments[i];
                  break;
                }
              }
            }
            formula = expression->getExcelFormula();
          }
          break;
        }
      }
      if (found)
      {
        break;
      }
      currentlySearchingForVariable = currentlySearchingForVariable->parent;
    }
    break;
  }
  case Expression::ExpressionType::FUNCTION_CALL:
  {
    auto data = std::get<Expression::FunctionCallData>(this->value);

    std::string variableHeader;
    auto currentNamespace = data.function->namespace_;
    while (currentNamespace->parent != nullptr)
    {
      variableHeader += "\\" + currentNamespace->name;
      currentNamespace = currentNamespace->parent;
    }
    variableHeader += "\\" + data.function->name;
    if (data.function == this->scope.context)
    {
      formula = "_xlpm.\\ME" + variableHeader + "(_xlpm.\\ME" + variableHeader + ",";
    }
    else
    {
      formula = data.function->getExcelFormula() + "(";
    }
    for (std::size_t i = 0; i < data.arguments.size(); i++)
    {
      formula += data.arguments[i]->getExcelFormula();
      if (i < data.arguments.size() - 1)
      {
        formula += ",";
      }
    }
    formula += ")";
    break;
  }
  case Expression::ExpressionType::DIRECT_FORMULA_ACCESS:
  {
    auto data = std::get<Expression::DirectFormulaAccessData>(this->value);
    formula = data.formulaName + "(";
    for (std::size_t i = 0; i < data.arguments.size(); i++)
    {
      formula += data.arguments[i]->getExcelFormula();
      if (i < data.arguments.size() - 1)
      {
        formula += ",";
      }
    }
    formula += ")";
    break;
  }
  case Expression::ExpressionType::STRUCT_INSTANTIATION:
  {
    std::cerr << "Cannot construct an Excel formula for a struct instantiation" << std::endl;
    exit(1);
  }
  case Expression::ExpressionType::TERNARY:
  {
    auto data = std::get<Expression::TernaryData>(this->value);
    formula = "_xlfn.IF(" + data.condition->getExcelFormula() + "," + data.ifTrue->getExcelFormula() + "," + data.ifFalse->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::PLUS:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto type = data.left->getType().type;
    if (type == Type::TypeType::NUMBER)
    {
      formula = "(" + data.left->getExcelFormula() + ")+(" + data.right->getExcelFormula() + ")";
    }
    else
    {
      formula = "_xlfn.CONCAT(" + data.left->getExcelFormula() + "," + data.right->getExcelFormula() + ")";
    }
    break;
  }
  case Expression::ExpressionType::MINUS:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")-(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::TIMES:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")*(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::DIVIDE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")/(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::EQ:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")=(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::NEQ:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")<>(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::LT:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")<(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::LE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")<=(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::GT:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")>(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::GE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "(" + data.left->getExcelFormula() + ")>=(" + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::AND:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "_xlfn.AND(" + data.left->getExcelFormula() + "," + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::OR:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    formula = "_xlfn.OR(" + data.left->getExcelFormula() + "," + data.right->getExcelFormula() + ")";
    break;
  }
  case Expression::ExpressionType::NOT:
  {
    auto data = std::get<std::shared_ptr<Expression>>(this->value);
    formula = "_xlfn.NOT(" + data->getExcelFormula() + ")";
    break;
  }
  }

  this->m_excelFormula = std::make_optional(formula);
  return formula;
}

std::string Function::getExcelFormula()
{
  if (this->m_excelFormula.has_value())
  {
    return this->m_excelFormula.value();
  }
  std::string formula;
  std::shared_ptr<Expression> returnValue;
  for (auto stmt : this->block->statements)
  {
    if (stmt->type == Statement::StatementType::RETURN)
    {
      returnValue = stmt->expression;
      break;
    }
  }
  if (returnValue == nullptr)
  {
    formula = "0";
  }
  else
  {
    auto returnFormula = returnValue->getExcelFormula();

    if (this->arguments.size() == 0)
    {
      formula = "_xlfn.LAMBDA(" + returnFormula + ")";
    }
    else
    {
      formula = "_xlfn.LAMBDA(";
      std::string variableHeader;
      auto currentNamespace = this->namespace_;
      while (currentNamespace->parent != nullptr)
      {
        variableHeader += "\\" + currentNamespace->name;
        currentNamespace = currentNamespace->parent;
      }
      variableHeader += "\\" + this->name;
      std::vector<std::string> argumentNames;
      for (auto argument : this->arguments)
      {
        getAllArgumentNames(variableHeader, argument, argumentNames);
      }
      for (auto argumentName : argumentNames)
      {
        formula += "_xlpm.\\OUTER" + argumentName + ",";
      }
      formula += "_xlfn.LET(_xlpm.\\FUNC" + variableHeader + ",_xlfn.LAMBDA(_xlpm.\\ME" + variableHeader + ",";
      for (auto argumentName : argumentNames)
      {
        formula += "_xlpm.\\INNER" + argumentName + ",";
      }
      formula += returnFormula;
      formula += "),_xlpm.\\FUNC" + variableHeader + "(_xlpm.\\FUNC" + variableHeader;
      for (auto argumentName : argumentNames)
      {
        formula += ",_xlpm.\\OUTER" + argumentName;
      }
      formula += ")))";
    }
  }

  this->m_excelFormula = std::make_optional(formula);
  return formula;
}

std::shared_ptr<Function> Program::getMainMethod()
{
  if (this->m_mainMethod.has_value())
  {
    return this->m_mainMethod.value();
  }

  std::shared_ptr<Function> mainMethod;
  for (auto func : this->scope.functions)
  {
    if (func->name == "main" && func->namespace_ == this->globalNamespace)
    {
      mainMethod = func;
      break;
    }
  }

  this->m_mainMethod = std::make_optional(mainMethod);
  return mainMethod;
}

std::string Program::getMainMethodFormula()
{
  if (this->m_mainMethodFormula.has_value())
  {
    return this->m_mainMethodFormula.value();
  }

  auto formula = this->getMainMethod()->getExcelFormula();
  this->m_mainMethodFormula = std::make_optional(formula);
  return formula;
}