#include "expressionstack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//constructor - initializes an empty stack
ExpressionStack::ExpressionStack(): arrIdx(0) {
    for (int i =0; i<MAXSIZE; i++) {
	expressions[i] = NULL;
    }
}

//removes and returns the top element from the stack
Expression *ExpressionStack::pop() {
    arrIdx --;
    Expression *expr = expressions[arrIdx];
    expressions[arrIdx] = NULL;
    return expr;
}

//pushes an element to the top of the stack
//terminates program if maximum stack size exceeded
void ExpressionStack::push(Expression *expr) {
    if (arrIdx == MAXSIZE) {
	cerr << "Stack overflow" << endl;
	for (int i =0; i<arrIdx ; i++) {
	    delete expressions[i];
	}
	delete expr;
	exit(0);
    }
    expressions[arrIdx] = expr;
    arrIdx++;
}
