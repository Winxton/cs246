#ifndef __EXPRESSIONSTACK_H__
#define __EXPRESSIONSTACK_H__

#include "expression.h"

const int MAXSIZE = 10;

class ExpressionStack {
    Expression *expressions[MAXSIZE];
    int arrIdx;
 public:
    ExpressionStack();
    Expression *pop();
    void push(Expression *expr);
};

#endif
