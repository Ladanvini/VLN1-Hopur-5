#include "tictactoe.h"

using namespace std;

TicTacToe::TicTacToe() {

}

void TicTacToe::initializeBoard () {
    char counter = '1';
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            _ticTacToeBoard[i][j] = counter;
            counter++;
        }
    }
}

void TicTacToe::printBoard () {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            cout << _ticTacToeBoard[i][j] << " ";
        }
        cout << endl;
    }
}

bool TicTacToe::insertIntoBoard (char position, char player) {
    bool valid = false;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if(_ticTacToeBoard[i][j] == position) {
                _ticTacToeBoard[i][j] = player;
                valid = true;
            }
        }
    }
    return valid;
}

bool TicTacToe::checkIfWinner () {
    // check horizontal
    for (int i = 0; i < 3; i++) {
        if (_ticTacToeBoard[i][i] != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9) {
            if (_ticTacToeBoard[i][0] == _ticTacToeBoard[i][1] && _ticTacToeBoard[i][1] == _ticTacToeBoard[i][2]) {
                 winner = _ticTacToeBoard[i][0];
                 cout << "Winner is: " << winner << endl;
                 return true;
            }
        }
    }
    // check vertical
    for (int i = 0; i < 3; i++) {
        if (_ticTacToeBoard[i][i] != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9) {
            if (_ticTacToeBoard[0][i] == _ticTacToeBoard[1][i] && _ticTacToeBoard[1][i] == _ticTacToeBoard[2][i]) {
                 winner = _ticTacToeBoard[0][i];
                 cout << "Winner is: " << winner << endl;
                 return true;
            }
        }
    }
    // check right cross
    if (_ticTacToeBoard[0][0] != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9) {
        if (_ticTacToeBoard[0][0] == _ticTacToeBoard[1][1] && _ticTacToeBoard[1][1] == _ticTacToeBoard[2][2]) {
            winner = _ticTacToeBoard[0][0];
            cout << "Winner is: " << winner << endl;
            return true;
        }
    }
    // check left cross
    if (_ticTacToeBoard[0][2] != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9) {
        if (_ticTacToeBoard[0][2] == _ticTacToeBoard[1][1] && _ticTacToeBoard[1][1] == _ticTacToeBoard[2][0]) {
            winner = _ticTacToeBoard[0][2];
            cout << "Winner is: " << winner << endl;
            return true;
        }
    }
    return false;
}

int TicTacToe::playTicTacToe () {
    int draw = 0;
    char player = 'X';

    while (draw < 9) {
        cout << player << " position: ";
        char position;
        cin >> position;

        bool isValid = insertIntoBoard(position, player);

        if(!isValid) {
            cout << "Illegal move!" << endl;
        }
        else if(player == 'X') {
            printBoard ();
            player = 'O';
            draw++;
        }
        else {
            printBoard ();
            player = 'X';
            draw++;
        }

        if (checkIfWinner() == true) {
            return 0;
        }
    }
    cout << "Draw!" << endl;
    return 0;
}

int TicTacToe::ticTacToeMain() {
    initializeBoard ();
    printBoard ();
    playTicTacToe ();

    return 0;
}
