#ifndef __DRONE_H__
#define __DRONE_H__

struct Position {
	Position();
	Position(int ew, int ns);
	int ew, ns;
	bool operator==(Position p);
};

struct Drone {
	Position p;
	Position positionsVisited[50];
	int visitedIdx;
	int distanceTravelled;
	int direction;

	Drone();
	void forward();
	void backward();
	void left();
	void right();
	Position current();
	int totalDistance();
	int manhattanDistance();
	bool repeated();
};

#endif
