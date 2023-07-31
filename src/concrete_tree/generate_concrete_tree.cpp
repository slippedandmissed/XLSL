#include <iostream>
#include <algorithm>
#include <filesystem>
#include <string.h>
#include "concrete_tree.hpp"
#include "../ast/print_ast.hpp"
#include "../ast/dealloc_ast.hpp"
#include "../ast/generate_ast.hpp"

using namespace ConcreteTree;

std::string unescapeString(std::string);
std::string resolvePath(std::string path, std::string relativeToFile);

std::unique_ptr<Program> Program::fromAST(std::string srcPath, ProgramNode *node)
{
  auto program = std::make_unique<Program>();
  program->globalNamespace = std::make_shared<Namespace>();
  program->globalNamespace->name = "(GLOBAL)";
  program->globalNamespace->parent = nullptr;

  std::vector<std::pair<std::string, std::string>> importData;
  auto currentImport = node->imports;
  while (currentImport != nullptr)
  {
    importData.push_back(std::pair<std::string, std::string>(unescapeString(currentImport->path->value), currentImport->alias));
    currentImport = currentImport->next;
  }

  for (auto importDatum : importData)
  {
    auto importPath = resolvePath(importDatum.first, srcPath);
    auto importAlias = importDatum.second;
    auto importHead = AST::generateFromFile(importPath);
    auto importProgram = Program::fromAST(importPath, importHead);
    AST::deallocTree(importHead);
    importProgram->globalNamespace->name = importAlias;
    importProgram->globalNamespace->parent = program->globalNamespace;
    program->globalNamespace->children.push_back(importProgram->globalNamespace);
    program->scope.addAll(importProgram->scope);
  }

  program->block = std::make_unique<Block>();

  if (node->body != nullptr)
  {
    program->scope.context = nullptr;
    program->block->populateFromAST(program->globalNamespace, program->scope, node->body);
  }
  return program;
}

void Block::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope &currentScope, BodyNode *node)
{
  auto body = node;

  while (body != nullptr)
  {
    auto stmtNode = body->current;

    switch (stmtNode->type)
    {
    case STMT_NODE_TYPE_FUNCTION_DECLARATION:
    {
      auto function = std::make_shared<Function>();
      function->namespace_ = currentNamespace;
      auto newScope = currentScope;
      newScope.context = function;
      function->populateFromAST(newScope, stmtNode->value.functionDeclaration);
      currentScope.functions.push_back(function);
      break;
    }
    case STMT_NODE_TYPE_STRUCT_DECLARATION:
    {
      auto struct_ = std::make_shared<Struct>();
      struct_->namespace_ = currentNamespace;
      struct_->populateFromAST(currentScope, stmtNode->value.structDeclaration);
      currentScope.structs.push_back(struct_);
      break;
    }
    case STMT_NODE_TYPE_NAMESPACE_DECLARATION:
    {
      if (stmtNode->value.namespaceDeclaration->identifier->type != ID_NODE_TYPE_TEXT)
      {
        std::cerr << "Tried to declare namespace with keyword identifier" << std::endl;
        exit(1);
      }
      auto newNamespace = Namespace::createFromAST(currentNamespace, stmtNode->value.namespaceDeclaration->identifier->text);
      auto subBlock = std::make_unique<Block>();
      subBlock->populateFromAST(newNamespace, currentScope, stmtNode->value.namespaceDeclaration->body);
      this->statements.insert(this->statements.end(), subBlock->statements.begin(), subBlock->statements.end());
      break;
    }
    case STMT_NODE_TYPE_VAR_DEFINITION:
    {
      auto variable = std::make_shared<Variable>();
      variable->namespace_ = currentNamespace;
      variable->name = stmtNode->value.varDefinition->name;
      variable->type.populateFromAST(currentNamespace, currentScope, stmtNode->value.varDefinition->variableType);
      variable->populateChildrenFromStruct(variable);
      auto expression = std::make_shared<Expression>();
      expression->populateFromAST(currentNamespace, currentScope, stmtNode->value.varDefinition->expression);
      currentScope.variables.push_back(std::make_pair(variable, expression));
      break;
    }
    case STMT_NODE_TYPE_EXPRESSION:
    {
      auto stmt = std::make_shared<Statement>();
      stmt->populateFromAST(currentNamespace, currentScope, stmtNode->value.expression);
      this->statements.push_back(stmt);
      break;
    }
    case STMT_NODE_TYPE_RETURN_STATEMENT:
    {
      auto stmt = std::make_shared<Statement>();
      stmt->populateFromAST(currentNamespace, currentScope, stmtNode->value.returnStatement);
      this->statements.push_back(stmt);
      break;
    }
    }

    body = body->next;
  }
}

void Variable::populateChildrenFromStruct(std::shared_ptr<Variable> self)
{
  if (this->type.type == Type::TypeType::CUSTOM_STRUCT)
  {
    for (auto member : this->type.struct_->members)
    {
      auto child = std::make_shared<Variable>();
      child->namespace_ = nullptr;
      child->name = member.name;
      child->type = member.type;
      child->parent = self;
      child->populateChildrenFromStruct(child);
      this->children.push_back(child);
    }
  }
}

std::shared_ptr<Namespace> Namespace::createFromAST(std::shared_ptr<Namespace> currentNamespace, IdentifierTextNode *node, bool canBacktrack)
{
  auto searchingNamespace = currentNamespace;
  std::shared_ptr<Namespace> found = nullptr;
  while (searchingNamespace != nullptr)
  {

    for (auto childNamespace : searchingNamespace->children)
    {
      if (childNamespace->name == node->text)
      {
        found = childNamespace;
        break;
      }
    }
    if (found != nullptr)
    {
      break;
    }
    if (canBacktrack)
    {
      searchingNamespace = searchingNamespace->parent;
    }
    else
    {
      break;
    }
  }
  if (found == nullptr)
  {
    auto parentNamespace = currentNamespace;
    auto currentNode = node;
    while (currentNode != nullptr)
    {
      auto newNamespace = std::make_shared<Namespace>();

      newNamespace->parent = parentNamespace;
      parentNamespace->children.push_back(newNamespace);

      newNamespace->name = currentNode->text;

      parentNamespace = newNamespace;
      currentNode = currentNode->next;
    }
    return parentNamespace;
  }
  if (node->next == nullptr)
  {
    return found;
  }
  return Namespace::createFromAST(found, node->next, false);
}

std::vector<std::string> Namespace::toPartsList()
{
  std::vector<std::string> result;
  auto current = this;
  while (current != nullptr)
  {
    result.push_back(current->name);
    current = current->parent.get();
  }
  std::reverse(result.begin(), result.end());
  return result;
}

bool Namespace::matchesFromAST(std::shared_ptr<Namespace> currentNamespace, IdentifierTextNode *node)
{
  auto myParts = this->toPartsList();

  std::vector<std::string> queryParts;
  auto current = node;
  while (current->next != nullptr)
  {
    queryParts.push_back(current->text);
    current = current->next;
  }

  auto searching = currentNamespace;
  while (searching != nullptr)
  {
    auto searchingParts = searching->toPartsList();
    searchingParts.insert(searchingParts.end(), queryParts.begin(), queryParts.end());

    if (searchingParts == myParts)
    {
      return true;
    }

    searching = searching->parent;
  }
  return false;
}

IdentifierTextNode *cloneIdentifierTextNode(IdentifierTextNode *src)
{
  // NOTE: we use `malloc` here rather than `new` because `deallocTree` uses `free` rather than `delete`
  // Idk whether this actually makes a difference but we move
  auto newNode = (IdentifierTextNode *)malloc(sizeof(IdentifierTextNode));
  newNode->text = (char *)malloc(strlen(src->text) + 1);
  strcpy(newNode->text, src->text);
  if (src->next == nullptr)
  {
    newNode->next = nullptr;
  }
  else
  {
    newNode->next = cloneIdentifierTextNode(src->next);
  }
  return newNode;
}

std::shared_ptr<Variable> Variable::localizeFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, IdentifierNode *node)
{
  if (node->type != ID_NODE_TYPE_TEXT)
  {
    std::cerr << "Tried to use variable with keyword identifier" << std::endl;
    exit(1);
  }
  std::shared_ptr<Variable> found = nullptr;
  auto checkingNode = cloneIdentifierTextNode(node->text);
  std::vector<std::string> assumedStructMembers;
  while (true)
  {
    auto current = checkingNode;
    while (current->next != nullptr)
    {
      current = current->next;
    }
    std::string variableName = current->text;
    for (auto variableDefinition : currentScope.variables)
    {
      auto variable = variableDefinition.first;
      if (variable->name == variableName && (variable->namespace_ == nullptr || variable->namespace_->matchesFromAST(currentNamespace, checkingNode)))
      {
        found = variable;
        break;
      }
    }
    if (found != nullptr)
    {
      break;
    }
    if (checkingNode->next == nullptr)
    {
      break;
    }
    auto newCheckingNode = cloneIdentifierTextNode(checkingNode);
    AST::deallocTree(checkingNode);
    current = newCheckingNode;
    while (current->next->next != nullptr)
    {
      current = current->next;
    }
    assumedStructMembers.push_back(current->next->text);
    AST::deallocTree(current->next);
    current->next = nullptr;
    checkingNode = newCheckingNode;
  }
  AST::deallocTree(checkingNode);

  if (found == nullptr)
  {
    std::cerr << "Could not find variable with identifier:" << std::endl
              << AST::nodeToString(*node->text, 2) << std::endl;
    exit(1);
  }
  for (auto part : assumedStructMembers)
  {
    std::shared_ptr<Variable> foundChild = nullptr;
    for (auto child : found->children)
    {
      if (child->name == part)
      {
        foundChild = child;
        break;
      }
    }
    if (foundChild == nullptr)
    {
      std::cerr << "Variable \"" << found->name << "\" has no member \"" << part << "\"" << std::endl;
      exit(1);
    }
    found = foundChild;
  }

  return found;
}

std::shared_ptr<Struct> Struct::localizeFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, IdentifierNode *node)
{
  if (node->type != ID_NODE_TYPE_TEXT)
  {
    std::cerr << "Tried to use struct with keyword identifier" << std::endl;
    exit(1);
  }
  auto current = node->text;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  std::string structName = current->text;
  std::shared_ptr<Struct> found = nullptr;
  for (auto struct_ : currentScope.structs)
  {
    if (struct_->name == structName && struct_->namespace_->matchesFromAST(currentNamespace, node->text))
    {
      found = struct_;
      break;
    }
  }
  if (found == nullptr)
  {
    std::cerr << "Could not find struct with identifier:" << std::endl
              << AST::nodeToString(*node->text, 2) << std::endl;
    exit(1);
  }
  return found;
}

std::shared_ptr<Function> Function::localizeFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, IdentifierNode *node)
{
  if (node->type == ID_NODE_TYPE_SELF)
  {
    if (currentScope.context == nullptr)
    {
      std::cerr << "Tried to use \"self\" when not in a function" << std::endl;
      exit(1);
    }
    return currentScope.context;
  }
  if (node->type != ID_NODE_TYPE_TEXT)
  {
    std::cerr << "Tried to use function with keyword identifier" << std::endl;
    exit(1);
  }
  auto current = node->text;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  std::string functionName = current->text;
  std::shared_ptr<Function> found = nullptr;
  for (auto function : currentScope.functions)
  {
    if (function->name == functionName && function->namespace_->matchesFromAST(currentNamespace, node->text))
    {
      found = function;
      break;
    }
  }
  if (found == nullptr)
  {
    std::cerr << "Could not find function with identifier:" << std::endl
              << AST::nodeToString(*node->text, 2) << std::endl;
    exit(1);
  }
  return found;
}

void Type::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, TypeNode *node)
{
  this->struct_ = nullptr;
  switch (node->type)
  {
  case TYPE_NODE_TYPE_LOGICAL:
    this->type = TypeType::LOGICAL;
    break;
  case TYPE_NODE_TYPE_NUMBER:
    this->type = TypeType::NUMBER;
    break;
  case TYPE_NODE_TYPE_TEXT:
    this->type = TypeType::TEXT;
    break;
  case TYPE_NODE_TYPE_VOID:
    this->type = TypeType::VOID;
    break;
  case TYPE_NODE_TYPE_IDENTIFIER:
  {
    this->type = TypeType::CUSTOM_STRUCT;
    this->struct_ = Struct::localizeFromAST(currentNamespace, currentScope, node->identifier);
    break;
  }
  }
}

void Function::populateFromAST(Scope currentScope, FunctionDeclarationNode *node)
{
  this->returnType.populateFromAST(this->namespace_, currentScope, node->returnType);
  this->name = node->name;
  auto currentArg = node->argList;
  while (currentArg != nullptr)
  {
    auto argument = std::make_shared<Variable>();
    argument->namespace_ = nullptr;
    argument->name = currentArg->argumentName;
    argument->type.populateFromAST(this->namespace_, currentScope, currentArg->argumentType);
    argument->populateChildrenFromStruct(argument);
    this->arguments.push_back(argument);
    currentScope.variables.push_back(std::make_pair(argument, nullptr));
    currentArg = currentArg->next;
  }
  this->block = std::make_unique<Block>();
  if (node->body != nullptr)
  {
    this->block->populateFromAST(this->namespace_, currentScope, node->body);
  }
}

void Struct::populateFromAST(Scope const &currentScope, StructDeclarationNode *node)
{
  this->name = node->name;
  auto currentDeclaration = node->declarations;
  while (currentDeclaration != nullptr)
  {
    Variable member;
    member.namespace_ = nullptr;
    member.name = currentDeclaration->current->name;
    member.type.populateFromAST(this->namespace_, currentScope, currentDeclaration->current->variableType);
    member.populateChildrenFromStruct(nullptr); // X?
    this->members.push_back(member);
    currentDeclaration = currentDeclaration->next;
  }
}

void Statement::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, ExpressionNode *node)
{
  this->type = Statement::StatementType::EXPRESSION;
  this->expression = std::make_shared<Expression>();
  this->expression->populateFromAST(currentNamespace, currentScope, node);
}

void Statement::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, ReturnStatementNode *node)
{
  this->type = Statement::StatementType::RETURN;
  if (node->value == nullptr)
  {
    this->expression = nullptr;
  }
  else
  {
    this->expression = std::make_shared<Expression>();
    this->expression->populateFromAST(currentNamespace, currentScope, node->value);
  }
}

void Expression::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, ExpressionNode *node)
{
  this->scope = currentScope;
  switch (node->type)
  {
  case EXPR_NODE_TYPE_BOOLEAN:
  {
    this->populateFromAST(currentNamespace, currentScope, node->value.booleanExpression);
    break;
  }
  case EXPR_NODE_TYPE_MULTIPLY_EXPRESSION:
  {
    this->populateFromAST(currentNamespace, currentScope, node->value.multiplyExpression);
    break;
  }
  case EXPR_NODE_TYPE_MINUS:
  {
    this->type = Expression::ExpressionType::MINUS;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.sides.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.sides.right);
    this->value = value;
    break;
  }
  case EXPR_NODE_TYPE_PLUS:
  {
    this->type = Expression::ExpressionType::PLUS;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.sides.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.sides.right);
    this->value = value;
    break;
  }
  case EXPR_NODE_TYPE_STRING_LITERAL:
  {
    this->type = Expression::ExpressionType::STRING_LITERAL;
    this->value = unescapeString(node->value.stringLiteral->value);
    break;
  }
  case EXPR_NODE_TYPE_STRUCT_INSTANTIATION:
  {
    this->type = Expression::ExpressionType::STRUCT_INSTANTIATION;
    Expression::StructInstantiationData value;
    value.struct_ = Struct::localizeFromAST(currentNamespace, currentScope, node->value.structInstantiation->identifier);
    auto currentArg = node->value.structInstantiation->arguments;
    while (currentArg != nullptr)
    {
      auto argument = std::make_shared<Expression>();
      argument->populateFromAST(currentNamespace, currentScope, currentArg->expression);
      value.arguments.push_back(argument);
      currentArg = currentArg->next;
    }
    this->value = value;
    break;
  }
  case EXPR_NODE_TYPE_TERNARY:
  {
    this->type = Expression::ExpressionType::TERNARY;
    Expression::TernaryData value;
    value.condition = std::make_shared<Expression>();
    value.ifTrue = std::make_shared<Expression>();
    value.ifFalse = std::make_shared<Expression>();

    value.condition->populateFromAST(currentNamespace, currentScope, node->value.ternary->condition);
    value.ifTrue->populateFromAST(currentNamespace, currentScope, node->value.ternary->ifTrue);
    value.ifFalse->populateFromAST(currentNamespace, currentScope, node->value.ternary->ifFalse);
    this->value = value;
    break;
  }
  }
}

void Expression::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, MultiplyExpressionNode *node)
{
  this->scope = currentScope;
  switch (node->type)
  {
  case MUL_NODE_TYPE_DIVIDE:
  {
    this->type = Expression::ExpressionType::DIVIDE;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.sides.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.sides.right);
    this->value = value;
    break;
  }
  case MUL_NODE_TYPE_TIMES:
  {
    this->type = Expression::ExpressionType::TIMES;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.sides.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.sides.right);
    this->value = value;
    break;
  }
  case MUL_NODE_TYPE_FUNCTION_CALL:
  {
    if (node->value.functionCall->isDirectFormula)
    {
      this->type = Expression::ExpressionType::DIRECT_FORMULA_ACCESS;
      Expression::DirectFormulaAccessData value;
      switch (node->value.functionCall->functionIdentifier->type)
      {
      case ID_NODE_TYPE_SELF:
        value.formulaName = "self";
        break;
      case ID_NODE_TYPE_TEXT:
      {

        value.formulaName = "";
        auto currentIdentifierNode = node->value.functionCall->functionIdentifier->text;
        while (currentIdentifierNode != nullptr)
        {
          value.formulaName += currentIdentifierNode->text;
          if (currentIdentifierNode->next != nullptr)
          {
            value.formulaName += ".";
          }
          currentIdentifierNode = currentIdentifierNode->next;
        }
      }
      }
      auto currentArg = node->value.functionCall->arguments;
      while (currentArg != nullptr)
      {
        auto argument = std::make_shared<Expression>();
        argument->populateFromAST(currentNamespace, currentScope, currentArg->expression);
        value.arguments.push_back(argument);
        currentArg = currentArg->next;
      }
      this->value = value;
    }
    else
    {
      this->type = Expression::ExpressionType::FUNCTION_CALL;
      Expression::FunctionCallData value;
      value.function = Function::localizeFromAST(currentNamespace, currentScope, node->value.functionCall->functionIdentifier);
      auto currentArg = node->value.functionCall->arguments;
      while (currentArg != nullptr)
      {
        auto argument = std::make_shared<Expression>();
        argument->populateFromAST(currentNamespace, currentScope, currentArg->expression);
        value.arguments.push_back(argument);
        currentArg = currentArg->next;
      }
      this->value = value;
    }
    break;
  }
  case MUL_NODE_TYPE_IDENTIFIER:
  {
    this->type = Expression::ExpressionType::VARIABLE;
    this->value = Variable::localizeFromAST(currentNamespace, currentScope, node->value.identifier);
    break;
  }
  case MUL_NODE_TYPE_LITERAL:
  {
    this->type = Expression::ExpressionType::NUMBER_LITERAL;
    this->value = node->value.literalValue;
    break;
  }
  }
}

void Expression::populateFromAST(std::shared_ptr<Namespace> currentNamespace, Scope const &currentScope, BooleanExpressionNode *node)
{
  this->scope = currentScope;
  switch (node->type)
  {
  case BOOL_NODE_TYPE_TRUE:
  {
    this->type = Expression::ExpressionType::TRUE_LITERAL;
    break;
  }
  case BOOL_NODE_TYPE_FALSE:
  {
    this->type = Expression::ExpressionType::FALSE_LITERAL;
    break;
  }
  case BOOL_NODE_TYPE_EQ:
  {
    this->type = Expression::ExpressionType::EQ;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_NEQ:
  {
    this->type = Expression::ExpressionType::NEQ;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_GT:
  {
    this->type = Expression::ExpressionType::GT;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_GE:
  {
    this->type = Expression::ExpressionType::GE;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_LT:
  {
    this->type = Expression::ExpressionType::LT;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_LE:
  {
    this->type = Expression::ExpressionType::LE;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_AND:
  {
    this->type = Expression::ExpressionType::AND;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_OR:
  {
    this->type = Expression::ExpressionType::OR;
    Expression::BinaryOpData value;
    value.left = std::make_unique<Expression>();
    value.right = std::make_unique<Expression>();
    value.left->populateFromAST(currentNamespace, currentScope, node->value.children.left);
    value.right->populateFromAST(currentNamespace, currentScope, node->value.children.right);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_NOT:
  {
    this->type = Expression::ExpressionType::NOT;
    auto value = std::make_shared<Expression>();
    value->populateFromAST(currentNamespace, currentScope, node->value.child);
    this->value = value;
    break;
  }
  case BOOL_NODE_TYPE_IDENTIFIER:
  {
    this->type = Expression::ExpressionType::VARIABLE;
    this->value = Variable::localizeFromAST(currentNamespace, currentScope, node->value.identifier);
    break;
  }
  }
}

void Scope::addAll(Scope const &other)
{
  this->functions.insert(this->functions.end(), other.functions.begin(), other.functions.end());
  this->structs.insert(this->structs.end(), other.structs.begin(), other.structs.end());
  this->variables.insert(this->variables.end(), other.variables.begin(), other.variables.end());
}

std::string unescapeString(std::string escapedString)
{
  // TODO: implement
  return escapedString;
}

std::string resolvePath(std::string path, std::string relativeToFile)
{
  auto findingPath = std::filesystem::path(path);
  auto srcPath = std::filesystem::path(relativeToFile);
  auto resolved = srcPath.parent_path();
  resolved /= findingPath;
  return resolved;
}