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

void flattenArguments(std::shared_ptr<Expression> argument, std::vector<std::shared_ptr<Expression>> &list)
{
  if (argument->type == Expression::ExpressionType::STRUCT_INSTANTIATION)
  {
    for (auto child : std::get<Expression::StructInstantiationData>(argument->value).arguments)
    {
      flattenArguments(child, list);
    }
  }
  else if (argument->type == Expression::ExpressionType::VARIABLE)
  {
    auto data = std::get<std::shared_ptr<Variable>>(argument->value);
    if (data->type.type == Type::TypeType::CUSTOM_STRUCT)
    {
      for (auto child : data->children)
      {
        auto newExpr = std::make_shared<Expression>();
        newExpr->type = Expression::ExpressionType::VARIABLE;
        newExpr->value = child;
        newExpr->scope = argument->scope;
        flattenArguments(newExpr, list);
      }
    }
    else
    {
      list.push_back(argument);
    }
  }
  else
  {
    list.push_back(argument);
  }
}

std::string referenceSheet(std::size_t sheetIndex)
{
  std::string sheetName = "Sheet" + std::to_string(sheetIndex + 2);
  return "INDIRECT(ADDRESS(ROW(),COLUMN(),1,1,\"" + sheetName + "\"))";
}

std::string Expression::getExcelFormula(bool shouldUseExcelHeaders, std::vector<std::pair<std::string, std::string>> &formulaDefinitions)
{
  std::string xlpm = shouldUseExcelHeaders ? "_xlpm." : "";
  std::string xlfn = shouldUseExcelHeaders ? "_xlfn." : "";
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
    std::string excelVarName = xlpm + "\\INNER";
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
          else if (expression->type == Expression::ExpressionType::STRUCT_INSTANTIATION || searchParts.size() > 1)
          {
            switch (expression->type)
            {
            case Expression::ExpressionType::STRUCT_INSTANTIATION:
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
              formula = expression->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
              break;
            }
            case Expression::ExpressionType::VARIABLE:
            {
              for (std::size_t j = 1; j < searchParts.size(); j++)
              {
                auto var = std::get<std::shared_ptr<Variable>>(expression->value);
                auto children = var->children;
                for (std::size_t i = 0; i < children.size(); i++)
                {
                  if (children[i]->name == searchParts[j])
                  {
                    var = children[i];
                    break;
                  }
                }
              }
              auto newExpr = std::make_shared<Expression>();
              newExpr->type = Expression::ExpressionType::VARIABLE;
              newExpr->value = variable;
              newExpr->scope = expression->scope;
              formula = newExpr->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
              break;
            }
            default:
              for (auto part : searchParts)
              {
                std::cerr << part << std::endl;
              }
              std::cerr << "Can't destructure expression of type " << expression->type << std::endl;
              exit(1);
            }
          }
          else
          {
            formula = expression->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
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
      formula = xlpm + "\\ME" + variableHeader + "(" + xlpm + "\\ME" + variableHeader + ",";
    }
    else
    {
      formula = data.function->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions) + "(";
    }
    std::vector<std::shared_ptr<Expression>> flatArguments;
    for (auto argument : data.arguments)
    {
      flattenArguments(argument, flatArguments);
    }
    for (std::size_t i = 0; i < flatArguments.size(); i++)
    {
      auto child = flatArguments[i]->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

      formula += child;
      if (i < flatArguments.size() - 1)
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
      auto child = data.arguments[i]->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

      formula += child;
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
    auto child1 = data.condition->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.ifTrue->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child3 = data.ifFalse->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    formula = xlfn + "IF(" + child1 + "," + child2 + "," + child3 + ")";
    break;
  }
  case Expression::ExpressionType::PLUS:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    auto type = data.left->getType().type;
    if (type == Type::TypeType::NUMBER)
    {
      formula = "(" + child1 + ")+(" + child2 + ")";
    }
    else
    {
      formula = xlfn + "CONCAT(" + child1 + "," + child2 + ")";
    }
    break;
  }
  case Expression::ExpressionType::MINUS:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")-(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::TIMES:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")*(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::DIVIDE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")/(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::EQ:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")=(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::NEQ:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")<>(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::LT:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")<(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::LE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")<=(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::GT:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")>(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::GE:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    formula = "(" + child1 + ")>=(" + child2 + ")";
    break;
  }
  case Expression::ExpressionType::AND:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    formula = xlfn + "AND(" + child1 + "," + child2 + ")";
    break;
  }
  case Expression::ExpressionType::OR:
  {
    auto data = std::get<Expression::BinaryOpData>(this->value);
    auto child1 = data.left->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
    auto child2 = data.right->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    formula = xlfn + "OR(" + child1 + "," + child2 + ")";
    break;
  }
  case Expression::ExpressionType::NOT:
  {
    auto data = std::get<std::shared_ptr<Expression>>(this->value);
    auto child = data->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    formula = xlfn + "NOT(" + child + ")";
    break;
  }
  }

  this->m_excelFormula = std::make_optional(formula);
  return formula;
}

std::string Function::getExcelFormula(bool shouldUseExcelHeaders, std::vector<std::pair<std::string, std::string>> &formulaDefinitions)
{
  std::string xlpm = shouldUseExcelHeaders ? "_xlpm." : "";
  std::string xlfn = shouldUseExcelHeaders ? "_xlfn." : "";

  if (this->m_excelFormula.has_value())
  {
    return this->m_excelFormula.value();
  }
  std::string formula;
  std::string variableHeader;
  auto currentNamespace = this->namespace_;
  while (currentNamespace->parent != nullptr)
  {
    variableHeader += "\\" + currentNamespace->name;
    currentNamespace = currentNamespace->parent;
  }
  variableHeader += "\\" + this->name;
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
    auto returnFormula = returnValue->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);

    if (this->arguments.size() == 0)
    {
      formula = xlfn + "LAMBDA(" + returnFormula + ")";
    }
    else
    {
      formula = xlfn + "LAMBDA(";
      std::vector<std::string> argumentNames;
      for (auto argument : this->arguments)
      {
        getAllArgumentNames(variableHeader, argument, argumentNames);
      }
      for (auto argumentName : argumentNames)
      {
        formula += xlpm + "\\OUTER" + argumentName + ",";
      }
      formula += xlfn + "LET(" + xlpm + "\\FUNC" + variableHeader + "," + xlfn + "LAMBDA(" + xlpm + "\\ME" + variableHeader + ",";
      for (auto argumentName : argumentNames)
      {
        formula += xlpm + "\\INNER" + argumentName + ",";
      }
      formula += returnFormula;
      formula += ")," + xlpm + "\\FUNC" + variableHeader + "(" + xlpm + "\\FUNC" + variableHeader;
      for (auto argumentName : argumentNames)
      {
        formula += "," + xlpm + "\\OUTER" + argumentName;
      }
      formula += ")))";
    }
  }

  auto functionName = "\\SHARED"+variableHeader;

  formulaDefinitions.push_back(std::make_pair(functionName, formula));
  formula = functionName;

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

std::string Program::getMainMethodFormula(bool shouldUseExcelHeaders, std::vector<std::pair<std::string, std::string>> &formulaDefinitions)
{
  if (this->m_mainMethodFormula.has_value())
  {
    return this->m_mainMethodFormula.value();
  }

  auto formula = this->getMainMethod()->getExcelFormula(shouldUseExcelHeaders, formulaDefinitions);
  this->m_mainMethodFormula = std::make_optional(formula);
  return formula;
}