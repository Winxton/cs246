#include <iostream>
#include "cell.h"
#include "grid.h"
#include "textdisplay.h"
#include "window.h"
#include <sstream>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
	string input;
	
	// create a new window and grid
	// both declared on stack for automatic destructor calls 
	// when as program terminates
	Xwindow w;
	Grid grid(&w);

	while (cin >> input) {
		if (input == "new") {
			int size;
			cin >> size;
			grid.init(size);
		}
		if (input == "init") {
			int col, row;
			while (true) {
				cin >> row;
				cin >> col;
				if (row == -1 && col == -1) break;
				grid.turnOn(row, col);
			}
		}
		if (input == "print") {
			cout << grid << endl;
		}
		if (input == "step") {
			grid.tick();
		}
		if (input == "steps") {
			int ticks;
			cin >> ticks;
			while (ticks > 0) {
				grid.tick();
				ticks --;
			}	
		}
	}
}