#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>

class Expression {
 public:
    virtual int evaluate() =0;
    virtual std::string prettyprint() =0;
    virtual ~Expression() =0;
};

#endif
