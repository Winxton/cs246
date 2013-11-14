#include <iostream>
#include "cell.h"
#include "grid.h"
#include "textdisplay.h"
#include <sstream>
#include <string>
using namespace std;

int main() {
	string input;
	Grid grid;

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