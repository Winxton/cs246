#include "drone.h"
#include <iostream>
#include <cstdlib>

Drone::Drone() {
	visitedIdx = 0;
	distanceTravelled = 0;
	direction = 0;
}

Position::Position() {
	ew = ns = 0;
}

Position::Position(int ew, int ns){
	this->ew = ew;
	this->ns = ns;
}

bool Position::operator==(Position p) {
	return (ns == p.ns) && (ew == p.ew);
}

void Drone::forward() {
	
	if (!repeated()) {
		positionsVisited[visitedIdx].ew = p.ew;
		positionsVisited[visitedIdx].ns = p.ns;
		visitedIdx++;
	}
	
	if (0 == direction)
		p.ns += 1;
	else if (1 == direction)
		p.ew += 1;
	else if (2 == direction)
		p.ns -= 1;
	else //(3 == direction)
		p.ew -= 1;
	
	distanceTravelled += 1;
}

void Drone::backward() {
	
	if (!repeated()) {
		positionsVisited[visitedIdx].ew = p.ew;
		positionsVisited[visitedIdx].ns = p.ns;
		visitedIdx++;
	}
	
	if (0 == direction)
		p.ns -= 1;
	else if (1 == direction)
		p.ew -= 1;
	else if (2 == direction)
		p.ns += 1;
	else //(3 == direction)
		p.ew += 1;
	
	distanceTravelled += 1;
}

void Drone::left() {
	if (0 == direction)
		direction = 3;
	else
		direction -= 1;
}

void Drone::right() {
	if (3 == direction)
		direction = 0;
	else
		direction += 1;
}

Position Drone::current() {
	return p;
}

int Drone::totalDistance() {
	return distanceTravelled;
}

int Drone::manhattanDistance() {
    return std::abs(p.ns) + std::abs(p.ew);
}

bool Drone::repeated() {
	for (int i = 0; i < visitedIdx; i++) {
		if (p == positionsVisited[i]) {
			return true;
		}
	}
	return false;
}
