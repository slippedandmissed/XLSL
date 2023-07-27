#pragma once

struct IdentifierNode {
  char *text;
  struct IdentifierNode *next;
};

struct ImportsNode {
  struct IdentifierNode *identifier;
  struct ImportsNode *next;
};

enum MultiplyExpressionType {
  MUL_NODE_TYPE_NUMBER,
  MUL_NODE_TYPE_IDENTIFIER,
  MUL_NODE_TYPE_TIMES,
  MUL_NODE_TYPE_DIVIDE
};

struct MultiplyExpressionNode {
  enum MultiplyExpressionType type;
  union {
    char *rawValue;
    struct IdentifierNode *identifier;
    struct {
      struct MultiplyExpressionNode *left;
      struct MultiplyExpressionNode *right;
    } sides;
  } value;
};
