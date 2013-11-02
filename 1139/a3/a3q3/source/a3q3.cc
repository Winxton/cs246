#include <iostream>
#include <fstream>
#include <string>
#include "family.h"
using namespace std;

void readCommands(istream &in, FTree &tree) {
    string cmd;
    
    while (in >> cmd) {
	if (cmd=="!") {
	    string name;
	    in >> name;
	    tree.addToTop(name);
	} else if (cmd=="+") {
	    string parent;
	    string child;
	    in >> parent;
	    in >> child;
	    tree.addChild(parent, child);
	} else if (cmd == "?") {
	    string name;
	    in >> name;
	    tree.printName(name);
	} else if (cmd == "*") {
	    string name;
	    in >> name;
	    tree.remove(name);
	} else if (cmd == "p") {
	    tree.print();
	} else if (cmd == "include") {
	    string fileName;
	    in >> fileName;
	    ifstream infile;
	    infile.open(fileName.c_str());
	    
	    readCommands(infile, tree);
	    infile.close();
	} else {
	    break;
	}
    }
}

int main() 
{
    FTree tree;
    readCommands(cin, tree);
}
