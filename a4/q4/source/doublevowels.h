#ifndef __DOUBLEVOWELS_H__
#define __DOUBLEVOWELS_H__

#include "textprocess.h"
#include "decorator.h"
#include <string>

//double the vowels in the word replace word with 
class DoubleVowels : public Decorator {
public:
	DoubleVowels(TextProcessor *component);
	std::string getWord(); //overrides textprocessor's getword
};

#endif
