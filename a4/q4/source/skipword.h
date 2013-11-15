#ifndef __SKIPWORD_H__
#define __SKIPWORD_H__

#include "decorator.h"

class SkipWord : public Decorator {
    int wordNum; // the number of words that have been iterated so far
public:
    SkipWord(TextProcessor *component);
    std::string getWord();
};

#endif
