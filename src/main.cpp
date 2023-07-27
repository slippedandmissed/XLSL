#include <iostream>
#include "parser/node_types.h"

extern "C" ProgramNode *head;
extern "C" int yyparse();

int main() {
  yyparse();
  ProgramNode *program = head;
  std::cout << "Output: " << program->imports->identifier->text->text << std::endl;
  return 0;
}