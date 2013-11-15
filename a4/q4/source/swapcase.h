#ifndef __SWAPCASE_H__
#define __SWAPCASE_H__

#include "decorator.h"

//swaps the case of all alphabetical characters
class SwapCase : public Decorator {
 public:
    SwapCase(TextProcessor *component);
    std::string getWord();
};

#endif
