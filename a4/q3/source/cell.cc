#include "cell.h"
using namespace std;

Cell::Cell(): isAlive(false), numNeighbours(0), r(0),c(0), numNeighboursAlive(0){
}

void Cell::setLiving() {
	isAlive = true;
}

void Cell::setCoords(int r, int c) {
	this->r = r;
	this->c = c;
}

void Cell::notifyDisplay(TextDisplay &t) {
	t.notify(r, c, isAlive);
}

void Cell::addNeighbour(Cell *neighbour) {
	neighbours[numNeighbours] = neighbour;
	numNeighbours ++;
}

void Cell::notify() {
	numNeighboursAlive ++;
}

void Cell::notifyNeighbours() {
	for (int i=0; i<numNeighbours; i++) {
		if (isAlive)
			neighbours[i]->notify();
	}
}

void Cell::recalculate() {
	//computer dead or alive based on the rules
	if (isAlive && (numNeighboursAlive < 2 || numNeighboursAlive > 3)) {
		isAlive = false;
	} else { //dead
		if (numNeighboursAlive == 3) {
			isAlive = true;
		}
	}
	//reset number of live neighbours
	numNeighboursAlive = 0;
}