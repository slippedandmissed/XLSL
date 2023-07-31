#include <iostream>
#include "parser/node_types.h"
#include "ast/print_ast.hpp"
#include "ast/dealloc_ast.hpp"
#include "concrete_tree/concrete_tree.hpp"

extern "C" ProgramNode *head;
extern "C" int yyparse();
extern "C" void yyrestart(FILE *);

int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    std::cerr << "Usage: " << (argc == 0 ? "compile" : argv[0]) << " [input_file.xlsl]" << std::endl;
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == nullptr)
  {
    std::cerr << "Failed to open file: " << argv[1] << std::endl;
    exit(1);
  }

  yyrestart(fp);
  yyparse();

  fclose(fp);

  if (head == nullptr)
  {
    return 1;
  }
  ProgramNode *ast = head;
  std::cout << "AST:" << std::endl
            << *ast << std::endl;
  std::cout << std::endl;

  auto program = ConcreteTree::Program::fromAST(ast);

  AST::deallocTree(ast);

  std::cout << "Concrete Tree:" << std::endl
            << *program << std::endl;
  std::cout << std::endl;

  return 0;
}