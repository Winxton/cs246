#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include "textprocess.h"

/*
	Decorator for Echo
*/

class Decorator : public TextProcessor {
protected:
	TextProcessor *component;
public:
	Decorator(TextProcessor *component);
	void setSource(std::istream *inp); //overrides textprocessor's setSource
	bool fail() const; //overrides textprocessor's fail
	virtual ~Decorator();
};

#endif