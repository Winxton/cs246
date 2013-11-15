#include "cell.h"
#include "window.h"
using namespace std;

Cell::Cell(): isAlive(false), numNeighbours(0), r(0),c(0), numNeighboursAlive(0){
}

void Cell::draw() {
	w->fillRectangle(c*width, r*height, width, height, Xwindow::Black);
}
void Cell::undraw() {
	w->fillRectangle(c*width, r*height, width, height, Xwindow::White);
}

void Cell::setLiving() {
	isAlive = true;
	draw();
}

void Cell::setDead() {
	isAlive = false;
	undraw();
}

void Cell::setCoords(int r, int c) {
	this->r = r;
	this->c = c;
}

void Cell::setCoords(int x, int y, int width, int height, Xwindow *w) {
	this->r = x;
	this->c = y;
	this->width = width;
	this->height = height;
	this->w = w;
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
		setDead();
	} else { //is dead
		if (numNeighboursAlive == 3) {
			setLiving();
		}
	}
	//reset number of live neighbours
	numNeighboursAlive = 0;
}