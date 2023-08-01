#pragma once

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include <optional>
#include "../parser/node_types.h"

namespace ConcreteTree
{
  struct Scope;
  struct Struct;
  struct Block;
  struct Expression;

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
    void populateChildrenFromStruct(std::shared_ptr<Variable> self);
    std::shared_ptr<Namespace> namespace_;
    Type type;
    std::string name;
    std::vector<std::shared_ptr<Variable>> children;
    std::shared_ptr<Variable> parent;
  };

  struct Function
  {
  private:
    std::optional<std::string> m_excelFormula;

  public:
    std::string getExcelFormula();
    inline std::string toString(int indent) const { return this->toString(indent, false); }
    std::string toString(int indent, bool brief) const;
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
    void populateFromAST(std::shared_ptr<Struct> self, std::shared_ptr<Namespace>, Scope const &, StructDeclarationNode *);
    std::shared_ptr<Namespace> namespace_;
    std::string name;
    std::vector<Variable> members;
    std::optional<std::pair<std::shared_ptr<Function>,std::vector<std::shared_ptr<Function>>>> serializers;
  };

  struct Scope
  {
    void addAll(Scope const &);
    std::string toString(int indent) const;
    std::vector<std::shared_ptr<Function>> functions;
    std::vector<std::shared_ptr<Struct>> structs;
    std::vector<std::pair<std::shared_ptr<Variable>, std::shared_ptr<Expression>>> variables;
    std::shared_ptr<Function> context;
  };

  struct Expression
  {
  private:
    std::optional<Type> m_type;
    std::optional<std::string> m_excelFormula;

  public:
    Type getType();
    Scope scope;
    std::string getExcelFormula();
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
      DIRECT_FORMULA_ACCESS,
    };
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, ExpressionNode *);
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, MultiplyExpressionNode *);
    void populateFromAST(std::shared_ptr<Namespace>, Scope const &, BooleanExpressionNode *);
    ExpressionType type;

    struct FunctionCallData
    {
      std::shared_ptr<Function> function;
      std::vector<std::shared_ptr<Expression>> arguments;
    };
    struct DirectFormulaAccessData
    {
      std::string formulaName;
      std::vector<std::shared_ptr<Expression>> arguments;
    };
    struct BinaryOpData
    {
      std::shared_ptr<Expression> left;
      std::shared_ptr<Expression> right;
    };
    struct StructInstantiationData
    {
      std::shared_ptr<Struct> struct_;
      std::vector<std::shared_ptr<Expression>> arguments;
    };
    struct TernaryData
    {
      std::shared_ptr<Expression> condition;
      std::shared_ptr<Expression> ifTrue;
      std::shared_ptr<Expression> ifFalse;
    };

    std::variant<
        std::string,
        std::shared_ptr<Variable>,
        FunctionCallData,
        DirectFormulaAccessData,
        BinaryOpData,
        std::shared_ptr<Expression>,
        StructInstantiationData,
        TernaryData>
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
    std::shared_ptr<Expression> expression;
  };

  struct Block
  {
    std::string toString(int indent) const;
    void populateFromAST(std::shared_ptr<Namespace>, Scope &, BodyNode *);
    std::vector<std::shared_ptr<Statement>> statements;
  };

  struct Program
  {
  private:
    std::optional<std::string> m_mainMethodFormula;

  public:
    std::string getMainMethodFormula();
    std::string toString(int indent) const;
    std::shared_ptr<Namespace> globalNamespace;
    std::unique_ptr<Block> block;
    Scope scope;
    static std::unique_ptr<Program> fromAST(std::string srcPath, ProgramNode *);
  };

}

std::ostream &operator<<(std::ostream &, ConcreteTree::Program const &);