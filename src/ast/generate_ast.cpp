#include "generate_ast.hpp"

ProgramNode *AST::generateFromFile(std::string path)
{
  FILE *fp = fopen(path.c_str(), "r");
  if (fp == nullptr)
  {
    std::cerr << "Failed to open file: " << path << std::endl;
    exit(1);
  }

  yyrestart(fp);
  yyparse();

  fclose(fp);

  if (head == nullptr)
  {
    // We assume that lex or yacc will print an error message before we get here
    exit(1);
  }

  return head;
}