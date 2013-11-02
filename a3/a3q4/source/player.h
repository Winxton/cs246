#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "scoreboard.h"
#include <iostream>

struct Player {

    //only two players
    static Player *playerA;
    static Player *playerB;
    //one scoreboard
    static ScoreBoard *scoreboard;

    char playerID;
    std::istream *in;

    Player(char PlayerID);
    static Player *getInstance(char playerID);
    static void cleanup();
    
    void readNewInput(std::istream *in);
    void makeMove();
    
};

#endif
