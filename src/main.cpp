#include <iostream>
#include "parser/node_types.h"
#include "print_ast.hpp"

extern "C" ProgramNode *head;
extern "C" int yyparse();

int main() {
  yyparse();
  ProgramNode *program = head;
  std::cout << "AST:" << std::endl << *program << std::endl;
  return 0;
}