#include "skipword.h"
#include <string>
using namespace std;

SkipWord::SkipWord(TextProcessor *component) : Decorator(component), wordNum(0) {}

string SkipWord::getWord() {
    string s = component->getWord();
    if (s != "") {
	wordNum ++;
    }
    //return every second word, empty string otherwise
    if (wordNum % 2 == 0) {
	return s;
    } else {
	return "";
    }
}
