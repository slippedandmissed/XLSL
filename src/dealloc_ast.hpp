#pragma once

#include "parser/node_types.h"

namespace AST {
  #define X(NodeType) void deallocTree(NodeType *);
  FOR_ALL_NODE_TYPES
  #undef X
}