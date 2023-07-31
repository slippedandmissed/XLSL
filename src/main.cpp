#include <iostream>
#include "ast/print_ast.hpp"
#include "ast/dealloc_ast.hpp"
#include "ast/generate_ast.hpp"
#include "concrete_tree/concrete_tree.hpp"

int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    std::cerr << "Usage: " << (argc == 0 ? "compile" : argv[0]) << " [input_file.xlsl]" << std::endl;
    exit(1);
  }

  auto ast = AST::generateFromFile(argv[1]);
  auto program = ConcreteTree::Program::fromAST(argv[1], ast);
  AST::deallocTree(ast);

  std::cout << "Concrete Tree:" << std::endl
            << *program << std::endl << std::endl;

  auto formula = program->getMainMethodFormula();
  std::cout << formula << std::endl;

  return 0;
}