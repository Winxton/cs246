#ifndef __LONEINT_H__
#define __LONEINT_H__

#include "expression.h"
#include <string>

class LoneInt : public Expression {
    int num;
 public:
    LoneInt(int num);
    int evaluate();
    std::string prettyprint();
    ~LoneInt();
};

#endif
