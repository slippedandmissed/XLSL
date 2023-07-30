#include <iostream>
#include "parser/node_types.h"
#include "print_ast.hpp"
#include "dealloc_ast.hpp"

extern "C" ProgramNode *head;
extern "C" int yyparse();

int main() {
  yyparse();
  if (head == nullptr) {
    return 1;
  }
  ProgramNode *program = head;
  std::cout << "AST:" << std::endl << *program << std::endl;
  std::cout << std::endl;
  AST::deallocTree(program);
  return 0;
}