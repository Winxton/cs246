#include "binaryoperation.h"
using namespace std;

BinaryOperation::BinaryOperation(char op, Expression *expr1, Expression *expr2): op(op),expr1(expr1),expr2(expr2) {}

int BinaryOperation::evaluate() {
    if (op == '+') {
	return expr1->evaluate() + expr2->evaluate();
    } else if (op == '-') {
	return expr1->evaluate() - expr2->evaluate();
    } else if (op == '*') {
	return expr1->evaluate() * expr2->evaluate();
    } else { //if (first == '/') {
	return expr1->evaluate() / expr2->evaluate();
    }
}

string BinaryOperation::prettyprint() {
    if (op == '+') {
	return "("+expr1->prettyprint() + " + " + expr2->prettyprint()+")";
    } else if (op == '-') {
	return "("+expr1->prettyprint() + " - " + expr2->prettyprint()+")";
    } else if (op == '*') {
	return "("+expr1->prettyprint() + " * " + expr2->prettyprint()+")";
    } else {//if (first == '/') {
	return "("+expr1->prettyprint() + " / " + expr2->prettyprint()+")";
    }
}

BinaryOperation::~BinaryOperation() {
    delete expr1;
    delete expr2;
}
