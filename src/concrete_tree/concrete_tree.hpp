#pragma once

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include "../parser/node_types.h"

namespace ConcreteTree
{
  struct Scope;
  struct Struct;
  struct Block;

  struct Namespace
  {
    std::string toString(int indent) const;
    inline static std::shared_ptr<Namespace> createFromAST(std::shared_ptr<Namespace> currentNamespace, IdentifierTextNode *node)
    {
      return Namespace::createFromAST(currentNamespace, node, true);
    }
    static std::shared_ptr<Namespace> createFromAST(std::shared_ptr<Namespace>, IdentifierTextNode *, bool canBacktrack);

    bool matchesFromAST(std::shared_ptr<Namespace>, IdentifierTextNode *);
    std::vector<std::string> toPartsList();

    std::string name;
    std::shared_ptr<Namespace> parent;
    std::vector<std::shared_ptr<Namespace>> children;
  };

  struct Type
  {
    std::string toString(int indent) const;
    enum TypeType
    {
      NUMBER,
      TEXT,
      LOGICAL,
      CUSTOM_STRUCT,
      VOID,
    };
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, TypeNode *);
    TypeType type;
    std::shared_ptr<Struct> struct_;
  };

  struct Variable
  {
    std::string toString(int indent) const;
    static std::shared_ptr<Variable> localizeFromAST(std::shared_ptr<Namespace>, Scope const &, IdentifierNode *);
    void populateChildrenFromStruct();
    std::shared_ptr<Namespace> namespace_;
    Type type;
    std::string name;
    std::vector<std::shared_ptr<Variable>> children;
  };

  struct Function
  {
    std::string toString(int indent) const;
    static std::shared_ptr<Function> localizeFromAST(std::shared_ptr<Namespace>, Scope const &, IdentifierNode *);
    void populateFromAST(Scope, FunctionDeclarationNode *);
    std::shared_ptr<Namespace> namespace_;
    Type returnType;
    std::string name;
    std::vector<std::shared_ptr<Variable>> arguments;
    std::unique_ptr<Block> block;
  };

  struct Struct
  {
    std::string toString(int indent) const;
    static std::shared_ptr<Struct> localizeFromAST(std::shared_ptr<Namespace>, Scope const &, IdentifierNode *);
    void populateFromAST(Scope const &, StructDeclarationNode *);
    std::shared_ptr<Namespace> namespace_;
    std::string name;
    std::vector<Variable> members;
  };

  struct Scope
  {
    std::string toString(int indent) const;
    std::vector<std::shared_ptr<Function>> functions;
    std::vector<std::shared_ptr<Struct>> structs;
    std::vector<std::shared_ptr<Variable>> variables;
    std::shared_ptr<Function> context;
  };

  struct Expression
  {
    std::string toString(int indent) const;
    enum ExpressionType
    {
      TRUE_LITERAL,
      FALSE_LITERAL,
      STRING_LITERAL,
      NUMBER_LITERAL,
      VARIABLE,
      FUNCTION_CALL,
      PLUS,
      MINUS,
      TIMES,
      DIVIDE,
      EQ,
      NEQ,
      LT,
      GT,
      LE,
      GE,
      AND,
      OR,
      NOT,
      STRUCT_INSTANTIATION,
      TERNARY,
    };
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, ExpressionNode *);
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, MultiplyExpressionNode *);
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, BooleanExpressionNode *);
    ExpressionType type;

    struct FunctionCallData
    {
      std::shared_ptr<Function> function;
      std::vector<std::unique_ptr<Expression>> arguments;
    };
    struct BinaryOpData
    {
      std::unique_ptr<Expression> left;
      std::unique_ptr<Expression> right;
    };
    struct StructInstantiationData
    {
      std::shared_ptr<Struct> struct_;
      std::vector<std::unique_ptr<Expression>> arguments;
    };
    struct TernaryData
    {
      std::unique_ptr<Expression> condition;
      std::unique_ptr<Expression> ifTrue;
      std::unique_ptr<Expression> ifFalse;
    };

    std::variant<
        std::string,
        std::shared_ptr<Variable>,
        std::unique_ptr<FunctionCallData>,
        std::unique_ptr<BinaryOpData>,
        std::unique_ptr<Expression>,
        std::unique_ptr<StructInstantiationData>,
        std::unique_ptr<TernaryData>>
        value;
  };

  struct Statement
  {
    std::string toString(int indent) const;
    enum StatementType
    {
      RETURN,
      EXPRESSION,
    };
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, ExpressionNode *);
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, ReturnStatementNode *);
    StatementType type;
    std::unique_ptr<Expression> expression;
  };

  struct Block
  {
    std::string toString(int indent) const;
    void populateFromAST(std::shared_ptr<Namespace>, Scope &, BodyNode *);
    std::vector<std::shared_ptr<Statement>> statements;
  };

  struct Program
  {
    std::string toString(int indent) const;
    std::shared_ptr<Namespace> globalNamespace;
    std::unique_ptr<Block> block;
    Scope scope;
    static std::unique_ptr<Program> fromAST(ProgramNode *);
  };

}

std::ostream &operator<<(std::ostream &, ConcreteTree::Program const &);