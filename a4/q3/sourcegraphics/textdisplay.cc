#include "textdisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(int n): gridSize(n) {
	theDisplay = new char *[n];
	for (int row =0; row <n ; row++) {
		theDisplay[row] = new char[n];
	}
	//set default
	for (int row =0; row < gridSize ; row++) {
		for (int col =0; col < gridSize ; col++) {
			theDisplay[row][col] = '_';
		}
	}
}

void TextDisplay::notify(int r, int c, bool alive) {
	char displayChar = alive ? 'X' : '_';
	theDisplay[r][c] = displayChar;
}

TextDisplay::~TextDisplay() {
	for (int row =0; row < gridSize ; row++) {
		delete [] theDisplay[row];
	}
	delete [] theDisplay;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int row =0; row < td.gridSize ; row++) {
		for (int col =0; col < td.gridSize ; col++) {
			cout << td.theDisplay[row][col];
		}
		if (row < (td.gridSize-1)) cout << endl;
	}
	return out;
}