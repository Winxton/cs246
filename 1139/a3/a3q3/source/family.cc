#include <iostream>
#include "family.h"
using namespace std;

string join(string a, string b) {
    if ("" == a) {
	return b;
    } else if ("" == b) {
	return a;
    }else {
	return a+','+b;
    }
}

FTree::FTree() {
    name = "";
    numChildren =0;
}

FTree::FTree(string name)
{
    this->name = name;
    for (int i =0; i<maxChildren; i++) {
	children[i] = NULL;
    }

    numChildren = 0;
}

void FTree::addToTop(string name) 
{
    //empty family tree
    if (""==this->name) {
	this->name = name;
    }
    else {
	FTree *top = new FTree(this->name);
	//create a new node, attach children to current node's children
	for (int i = 0; i<numChildren; i++) {
	    top->children[i] = children[i];
	    children[i] = NULL;
	}

	top->numChildren = numChildren;

	this->name = name;
	children[0] = top;
	numChildren = 1;
    }
}

void FTree::print() {
    //print current node
    if (name != "") {
	if (numChildren > 0) {
	    std::cout << name << " is parent of ";
	    for (int i=0; i<numChildren; i++) {
		std::cout << children[i]->name;
		if (i!=numChildren-1) std::cout << ',';
	    }
	    std::cout << endl;
	}
	else
	    {
		std::cout << name << " has no children" << endl;
	    }
	for (int i=0; i<numChildren; i++) {
	    children[i]->print();
	}
    }
}

FTree* FTree::getName(string name, bool printSequence /*=false*/, string sequence /*=""*/) {
    //arrived at the desired name
    if (this->name == name) {
	if (printSequence) {
	    cout << join(sequence, name) << endl;
	}
	return this;
    }
    else {
	//check each child recursively
	for (int i =0; i<numChildren; i++) {

	    FTree *child = children[i]->getName(name, printSequence, join(sequence, this->name));
	   
	    if (child != NULL) {
		return child;
	    }
	}
       	return NULL;
    }
}

void FTree::addChild(string parentName, string childName) {
    FTree *parentNode = getName(parentName);
    if (NULL == parentNode) {
	cout << "Failed" << endl;
    } else {
	FTree *childNode = new FTree(childName);
	parentNode->children[parentNode->numChildren] = childNode;
	parentNode->numChildren ++;
    }
}

void FTree::printName(string name) {
    FTree *node = getName(name, true);
    if (node == NULL) {
	cout << "Not found" << endl;
    }
}

void FTree::remove(string name) {
    //topnode is the one to remove
    if (this->name == name) {
	this->name = "";
	for (int i=0; i<numChildren; i++) {
	    delete children[i];
	}
	numChildren = 0;
    }
    else {
	//look through child nodes to find given name
	for (int i=0; i<numChildren; i++) {
	    if (children[i]->name == name) {
		delete children[i];
		//move indices
		for (int j=i+1; j<numChildren; j++) {
		    children[j-1] = children[j];
		}
		//decrement the amount of children
		numChildren --;
	    
		break;
	    } else {
		children[i]->remove(name);
	    }
	}
    }
}

FTree::~FTree() {
    for (int i=0; i<numChildren; i++) {
	delete children[i];
    }
}
