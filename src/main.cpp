#include <iostream>
#include "ast/print_ast.hpp"
#include "ast/dealloc_ast.hpp"
#include "ast/generate_ast.hpp"
#include "concrete_tree/concrete_tree.hpp"

void addAllArgumentLabels(std::string header, const ConcreteTree::Variable &argument, std::vector<std::string> &list)
{
  if (argument.type.type == ConcreteTree::Type::TypeType::CUSTOM_STRUCT)
  {
    auto newHeader = header + argument.name + ".";
    for (auto member : argument.type.struct_->members)
    {
      addAllArgumentLabels(newHeader, member, list);
    }
  }
  else
  {
    list.push_back(header + argument.name);
  }
}

int main(int argc, char *argv[])
{

  if (argc < 3 || (std::string(argv[2]) != "y" && std::string(argv[2]) != "n"))
  {
    std::cerr << "Usage: " << (argc == 0 ? "compile" : argv[0]) << " [input_file.xlsl] [should_use_excel_headers(y/n)] [Input cell addr 1] [Input cell addr 2] ..." << std::endl;
    exit(1);
  }

  bool shouldUseExcelHeaders = std::string(argv[2]) == "y";

  auto ast = AST::generateFromFile(argv[1]);
  auto program = ConcreteTree::Program::fromAST(argv[1], ast);
  AST::deallocTree(ast);

  auto mainMethod = program->getMainMethod();

  std::vector<std::string> inputCells;
  for (int i = 3; i < argc; i++)
  {
    inputCells.push_back(argv[i]);
  }

  std::vector<std::string> argumentLabels;
  for (auto arg : mainMethod->arguments)
  {
    addAllArgumentLabels("", *arg, argumentLabels);
  }

  if (argumentLabels.size() != inputCells.size())
  {
    std::cerr << "Main method has "
              << argumentLabels.size()
              << " input" << (argumentLabels.size() == 1 ? "" : "s")
              << ", but "
              << inputCells.size()
              << " input cell"
              << (inputCells.size() == 1 ? " was" : "s were")
              << " provided"
              << std::endl;
    exit(1);
  }

  std::vector<std::pair<std::string, std::string>> formulaDefinitions;

  auto formula = program->getMainMethodFormula(shouldUseExcelHeaders, formulaDefinitions) + "(";
  for (std::size_t i = 0; i < inputCells.size(); i++)
  {
    formula += inputCells[i];
    if (i < inputCells.size() - 1)
    {
      formula += ",";
    }
  }
  formula += ")";

  std::cout << argumentLabels.size() << std::endl;
  for (auto argumentLabel : argumentLabels)
  {
    std::cout << argumentLabel << std::endl;
  }
  std::cout << formula << std::endl;
  std::cout << formulaDefinitions.size() << std::endl;
  for (auto formula : formulaDefinitions)
  {
    std::cout << formula.first << std::endl << formula.second << std::endl;
  }

  return 0;
}