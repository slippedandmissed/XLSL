#include "../parser/node_types.h"
#include <iostream>
#include <string>

extern "C" ProgramNode *head;
extern "C" int yyparse();
extern "C" void yyrestart(FILE *);

namespace AST {
  ProgramNode *generateFromFile(std::string);
}