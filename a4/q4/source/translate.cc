#include "translate.h"
#include <string>
using namespace std;

Translate::Translate(TextProcessor *component, char source, char dest): Decorator(component), source(source), dest(dest){}

string Translate::getWord() {
    string s = component->getWord();
    string sTranslated = "";
    for (unsigned int i =0; i < s.length(); i++) {
	if (s[i] == source) {
	    sTranslated = sTranslated + dest;
	} else {
	    sTranslated = sTranslated + s[i];
	}
    }
    return sTranslated;
}
