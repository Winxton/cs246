#include "swapcase.h"
#include <string>
using namespace std;

SwapCase::SwapCase(TextProcessor *component) : Decorator(component) {}

string SwapCase::getWord() {
    string s = component->getWord();
    string sCaseSwapped = "";
    for (unsigned int i = 0; i < s.length(); i++) {
	if (s[i] >= 'a' && s[i] <= 'z') {
	    //append character converted to upper case
	    sCaseSwapped = sCaseSwapped + (char)(s[i]+'A'-'a');
	}
	else if (s[i] >= 'A' && s[i] <= 'Z') {
	    //append character converted to upper case
	    sCaseSwapped = sCaseSwapped + (char)(s[i]+'a'-'A');
	}
	else {
	    //no change
	    sCaseSwapped = sCaseSwapped + s[i];
	}
    }
    return sCaseSwapped;
}
