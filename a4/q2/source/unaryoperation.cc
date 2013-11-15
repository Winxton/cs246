#include "unaryoperation.h"
#include <stdlib.h>
using namespace std;

UnaryOperation::UnaryOperation(string type, Expression *expr): type(type), expr(expr) {}

int UnaryOperation::evaluate() {
    if (type == "NEG")
	return -expr->evaluate();
    else //if (type == "ABS"
	return abs(expr->evaluate());
}

string UnaryOperation::prettyprint() {
    if (type == "NEG")
	return "-"+expr->prettyprint();
    else //if (type == "ABS"
	return "|"+expr->prettyprint()+"|";
}

UnaryOperation::~UnaryOperation(){
    delete expr;
}
