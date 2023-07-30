#include <iostream>
#include "parser/node_types.h"
#include "ast/print_ast.hpp"
#include "ast/dealloc_ast.hpp"
#include "concrete_tree/program.hpp"

extern "C" ProgramNode *head;
extern "C" int yyparse();

int main() {
  yyparse();
  if (head == nullptr) {
    return 1;
  }
  ProgramNode *ast = head;
  std::cout << "AST:" << std::endl << *ast << std::endl;
  std::cout << std::endl;

  auto program = ConcreteTree::Program::fromAST(ast);

  AST::deallocTree(ast);
  return 0;
}