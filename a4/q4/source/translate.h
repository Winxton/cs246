#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include "decorator.h"

class Translate: public Decorator {
    char source; // the source character (to be replaced)
    char dest; // the destination character (to replace the source)
public:
    Translate(TextProcessor *component, char source, char dest);
    std::string getWord();
};

#endif
