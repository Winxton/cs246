#include "expression.h"
#include "expressionstack.h"
#include "unaryoperation.h"
#include "binaryoperation.h"
#include "loneint.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

/*
  reads from stdin until end of input
  Pops 1 or 2 items from the stack if it is a Unary or Binary Operation
  Creates a new Expression with those items, and pushes it back onto the stack
  
  Evaluates the last expression, and deletes it to free memory.
 */

int main() {
    string s;
    ExpressionStack stack;

    while (cin >> s) {
	istringstream ss(s);
	int num;
	if (ss >> num) {
	    stack.push(new LoneInt(num));
	} else {
	    if (s == "NEG") {
		Expression *expr = stack.pop();
		stack.push(new UnaryOperation("NEG", expr));
	    } else if (s == "ABS") {
		Expression *expr = stack.pop();
		stack.push(new UnaryOperation("ABS", expr));
	    } else if (s == "+") {
		Expression *expr1 = stack.pop();
		Expression *expr2 = stack.pop();
		stack.push(new BinaryOperation('+', expr2, expr1));
	    } else if (s == "-") {
		Expression *expr1 = stack.pop();
		Expression *expr2 = stack.pop();
		stack.push(new BinaryOperation('-', expr2, expr1));
		
	    } else if (s == "*") {
		Expression *expr1 = stack.pop();
		Expression *expr2 = stack.pop();
		stack.push(new BinaryOperation('*', expr2, expr1));
		
	    } else if (s == "/") {
		Expression *expr1 = stack.pop();
		Expression *expr2 = stack.pop();
		stack.push(new BinaryOperation('/', expr2, expr1));
		
	    } else {break;}
	}
    }
    Expression *expr = stack.pop();
    cout << expr->prettyprint() << endl;
    cout << "= " << expr->evaluate() << endl;
    delete expr;
}

