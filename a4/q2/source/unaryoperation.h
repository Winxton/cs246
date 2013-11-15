#ifndef __UNARYEXPRESSION_H__
#define __UNARYEXPRESSION_H__

#include "expression.h"

class UnaryOperation : public Expression {
    std::string type;
    Expression *expr;
 public:
    UnaryOperation(std::string type, Expression* expr);
    int evaluate();
    std::string prettyprint();
    ~UnaryOperation();
};

#endif
