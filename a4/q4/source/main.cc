#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "skipword.h"
#include "swapcase.h"
#include "translate.h"
#include "textprocess.h"
#include "doublevowels.h"
#include "echo.h"

int main() {
    string s;

    while (1) {
	getline(cin, s);
	if (cin.fail()) break;
	istringstream iss(s);
	string fname;
	iss >> fname;
	istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

	TextProcessor *tp = new Echo;
	string dec;
	while (iss >> dec) {
	    if (dec == "swapcase") {
		tp = new SwapCase(tp);
	    }
	    else if (dec == "doublevowels") {
		tp = new DoubleVowels(tp);
	    }
	    else if (dec == "skipword") {
		tp = new SkipWord(tp);
	    }
	    else if (dec == "translate") {
		char from, to;
		iss >> from >> to;
		tp = new Translate(tp, from, to);
	    }
	}

	tp->setSource(in);

	string word;

	while (word = tp->getWord(), !tp->fail()) {
	    if (word != "") {
		cout << word << endl;
	    }
	}

	if (in != &cin) delete in;

	delete tp;
	cout << "continue?" << endl;
	int cont;
	cin >> cont;
	if (cont == 0) {
	    break;
	}
    }
}
