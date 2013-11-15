#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid(Xwindow* w) : theGrid(NULL), gridSize(0), w(w), td(NULL) {}

void Grid::clearGrid() {
	for (int row =0; row < gridSize; row++) {
		delete [] theGrid[row];
	}
	delete [] theGrid;
}

Grid::~Grid() {
	clearGrid();
	delete td;
}

void Grid::init(int n) {
	if (theGrid != NULL) {
		clearGrid();
	}
	//create a new grid and textdisplay
	theGrid = new Cell *[n];
	gridSize = n;
	td = new TextDisplay(n);

	//width depends on size of grid
	int width = 500/n;

	for (int row = 0; row < n; row ++) {
		theGrid[row] = new Cell[n];

		for (int col = 0; col < n; col ++) {
			theGrid[row][col].setCoords(row,col, width, width, w);
		}
	}

	//go through every cell in the grid, and
	//set it's neighbors accordingly
	for (int row =0; row < gridSize ; row++) {
		for (int col =0; col < gridSize ; col++) {
			//all the cells around the current one
			for (int i=-1; i<=1; i++) {
				for (int j=-1; j<=1; j++) {
					if (!(i==0 && j==0)) {
						int nRow = row + i;
						int nCol = col + j; 
						//filter to within bounds
						if (nRow >= 0 && nRow < gridSize
							&& nCol >=0 && nCol < gridSize) 
						{
							theGrid[row][col].addNeighbour(&theGrid[nRow][nCol]);
						}
					}
				}
			}
		}
	}
}

void Grid::tick() {
	for (int row =0; row < gridSize ; row++) {
		for (int col =0; col < gridSize ; col++) {
			theGrid[row][col].notifyNeighbours();
		}
	}
	for (int row =0; row < gridSize ; row++) {
		for (int col =0; col < gridSize ; col++) {
			theGrid[row][col].recalculate();
			theGrid[row][col].notifyDisplay(*td);
		}
	}
}

void Grid::turnOn(int r, int c) {
	theGrid[r][c].setLiving();
	theGrid[r][c].notifyDisplay(*td);
}

ostream& operator<<(ostream &out, const Grid &g) {
	out << *g.td;
	return out;
}