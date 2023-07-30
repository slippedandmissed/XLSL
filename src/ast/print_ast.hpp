#pragma once

#include <iostream>
#include <string>
#include "../parser/node_types.h"

namespace AST {
  #define X(NodeType) std::string nodeToString(NodeType const &, int indent);
  FOR_ALL_NODE_TYPES
  #undef X
}

#define X(NodeType) std::ostream &operator<<(std::ostream &, NodeType const &);
FOR_ALL_NODE_TYPES
#undef X