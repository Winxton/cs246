#ifndef __FAMILY_H__
#define __FAMILY_H__
#include <string>

const int maxChildren = 10;

struct FTree {
    std::string name;
    int numChildren;
    FTree *children[maxChildren];

    FTree();
    FTree(std::string name);
    //add a new name to the top of the tree
    void addToTop(std::string name);
    
    //returns a pointer to the tree node given the name
    FTree* getName(std::string name, bool printSequence=false, std::string sequence="");

    //add a child to the given parent name
    void addChild(std::string parentName, std::string childName);

    //print the tree preorder
    void print();

    //prints the sequence from topmost ancestor if name is found in tree, "Not found" otherwise
    void printName(std::string name);

    void remove(std::string name);
    ~FTree();
};

#endif
