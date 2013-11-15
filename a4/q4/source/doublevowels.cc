#include "doublevowels.h"
#include <string>
using namespace std;

DoubleVowels::DoubleVowels(TextProcessor *component) : Decorator(component) {}

string DoubleVowels::getWord() {
	string s = component->getWord();
	string sDoubledVowels = "";
	for (unsigned int i = 0; i < s.length(); i++) {
		//if a vowel, append it twice to the new string
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
			|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') 
		{
			sDoubledVowels = sDoubledVowels + s[i] + s[i];
		}
		//not a vowel, append it once
		else {
			sDoubledVowels = sDoubledVowels + s[i];
		}
	}
	return sDoubledVowels;
}
