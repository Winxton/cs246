#include <cstdlib>
#include <iostream>
#include <fstream>
#include "player.h"
#include "scoreboard.h"
using namespace std;

ScoreBoard *Player::scoreboard = ScoreBoard::getInstance();
Player *Player::playerA = NULL;
Player *Player::playerB = NULL;

Player::Player(char playerID) {
    this->in = NULL;
    this->playerID = playerID;
}

Player *Player::getInstance(char playerID) {
    if (playerA == NULL && playerB == NULL) {
	atexit(cleanup);
    }
    if (playerID == 'A') {
	if (playerA == NULL)
	    playerA = new Player(playerID);
	return playerA;
    }
    else {
	if (playerB == NULL)
	    playerB = new Player(playerID);
	return playerB;
    }
}

void Player::cleanup() {
    delete playerA;
    delete playerB;
}

void Player::readNewInput(istream *in) {
    this->in = in;
}

void Player::makeMove() {
    int amount;
    *in >> amount;
    scoreboard->makeMove(this->playerID, amount);
}

