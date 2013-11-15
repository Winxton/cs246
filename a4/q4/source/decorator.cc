#include "textprocess.h"
#include "decorator.h"
#include <iostream>
using namespace std;

Decorator::Decorator(TextProcessor *component) : component(component) {};

void Decorator::setSource(istream *inp) {
	component->setSource(inp);
}

bool Decorator::fail() const {
	return component->fail();
}

Decorator::~Decorator() {
	delete component;
};
