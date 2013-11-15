#ifndef __BINARYOPERATION_H__
#define __BINARYOPERATION_H__

#include "expression.h"

class BinaryOperation : public Expression {
    char op;
    Expression *expr1;
    Expression *expr2;
public:
    BinaryOperation(char op, Expression *expr1, Expression *expr2);
    int evaluate();
    std::string prettyprint();
    ~BinaryOperation();
};

#endif
