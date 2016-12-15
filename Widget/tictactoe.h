#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "dialogtictactoe.h"

using namespace std;

const int ARRAY_SIZE = 3;

class TicTacToe {
private:
    char _ticTacToeBoard[ARRAY_SIZE][ARRAY_SIZE];
    char position;
    char player;
    char winner;
public:
    TicTacToe();
    void initializeBoard ();
    void printBoard ();
    bool insertIntoBoard (char position, char player);
    bool checkIfWinner ();
    int playTicTacToe ();
    int ticTacToeMain ();

};

#endif // TICTACTOE_H
