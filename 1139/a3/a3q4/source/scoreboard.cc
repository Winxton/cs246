#include "scoreboard.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ScoreBoard *ScoreBoard::instance = NULL;

ScoreBoard *ScoreBoard::getInstance() {
    if (instance == NULL) {
	instance = new ScoreBoard();
	atexit(cleanup);
    } 
    return instance;
}

void ScoreBoard::cleanup() {
    delete instance;
}

ScoreBoard::ScoreBoard(): counter(0), maxDeduction(0),
			  scoreA(0), scoreB(0) {}

ScoreBoard::ScoreBoard(int counter, int maxDeduction) {
    this->counter = counter;
    this->maxDeduction = maxDeduction;
    scoreA = 0;
    scoreB = 0;
}

bool ScoreBoard::gameEnded() {
    return counter <= 0;
}

void ScoreBoard::updateScore(char winner) {
    if (winner == 'A')
	scoreA ++;
    else
	scoreB ++;
}

void ScoreBoard::makeMove(char player, int amount) {
    if (amount > maxDeduction) {
	counter -= maxDeduction;
    } else if (amount <= 0) {
	counter -= 1;
    } else {
	counter -= amount;
    }
    cout << "Total is " << counter << endl;

    if (gameEnded()) {
	updateScore(player);
	cout << "Player " << player << " wins" << endl;
	cout << "Score is" << endl;
	cout << "A " << scoreA << endl;
	cout << "B " << scoreB << endl;
    }
}
     
void ScoreBoard::startGame(int counter, int maxDeduction) {
    this->counter = counter;
    this->maxDeduction = maxDeduction;
    cout << "Total is " << counter << ", max deduction is " << maxDeduction << endl;
}
