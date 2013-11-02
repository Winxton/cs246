#include <iostream>
#include <fstream>
#include "scoreboard.h"
#include "player.h"
using namespace std;

char updateTurn(char &turn) {
    turn = turn == 'A' ? 'B' : 'A';
}

int main () {
    string input;

    //the number of games that have been played so far
    int gameNumber = 1;
    
    while (cin >> input) {
	if (input == "game") {
	    int n; //total points
	    int k; //maximum deduction
	    cin >> n >> k;
	    
	    //get scoreboard instance and start game
	    ScoreBoard *scoreboard = ScoreBoard::getInstance();
	    scoreboard->startGame(n, k);

	    //get the appropriate input streams
	    //based on "stdin" or "filename" input
	    string sourceA;
	    string sourceB;
	    cin >> sourceA >> sourceB;
	    
	    istream *inputA;
	    istream *inputB;

	    if (sourceA == "stdin")
		inputA = &cin;
	    else {
		ifstream *infile = new ifstream;
		infile->open(sourceA.c_str());
		inputA = infile;
	    }
	    
	    if (sourceB == "stdin")
		inputB = &cin;
	    else {
		ifstream *infile = new ifstream;
		infile->open(sourceB.c_str());
		inputB = infile;
	    }
	    
	    Player *playerA = Player::getInstance('A');
	    Player *playerB = Player::getInstance('B');
	    playerA->readNewInput(inputA);
	    playerB->readNewInput(inputB);
	    
	    char turn = gameNumber % 2 == 1 ? 'A' : 'B';
	    
	    //while the game has not ended, keep playing
	    while (!scoreboard->gameEnded()) {
		cout << "Player " << turn << "\'s move" << endl;
		if (turn=='A')
		    playerA->makeMove();
		else //(turn == 'B')
		    playerB->makeMove();
		updateTurn(turn);
	    }
	    gameNumber ++;
	    
	} else if (input == "quit") {
	    break;
	} else {
	    continue;
	}
    }
}
