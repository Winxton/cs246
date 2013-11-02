#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

struct ScoreBoard {
    static ScoreBoard *instance;
    int scoreA;
    int scoreB;
    int counter;
    int maxDeduction;
    
    ScoreBoard();
    ScoreBoard(int counter, int maxDeduction);
    static ScoreBoard *getInstance();
    static void cleanup();
    bool gameEnded();
    void updateScore(char winner);
    void makeMove(char player, int amount);
    void startGame(int counter, int maxDeduction);
};

#endif
