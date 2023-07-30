#include "concrete_tree.hpp"

using namespace ConcreteTree;

std::string Namespace::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Namespace";
  return strValue;
}

std::string Type::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Type";
  return strValue;
}

std::string Variable::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Variable";
  return strValue;
}

std::string Function::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Function";
  return strValue;
}

std::string Struct::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Struct";
  return strValue;
}

std::string Scope::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Scope";
  return strValue;
}

std::string Expression::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Expression";
  return strValue;
}

std::string Statement::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Statement";
  return strValue;
}

std::string Block::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Block";
  return strValue;
}

std::string Program::toString(int indent) const
{
  // TODO: implement
  std::string strValue = std::string(indent, ' ') + "Program";
  return strValue;
}

std::ostream &operator<<(std::ostream &os, Program const &program)
{
  return os << program.toString(0);
}
