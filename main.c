#include <stdio.h>
#include "node_types.h"
#include "y.tab.h"

extern struct ProgramNode *head;

int main(void) {
  yyparse();
  struct ProgramNode *program = head;
  printf("Output: %s\n", program->imports->identifier->text);
  return 0;
}