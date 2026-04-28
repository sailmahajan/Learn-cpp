#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';
int moves = 0;

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

void playerMove() {
    int choice;
    cout << "Player " << currentPlayer << " ki baari. 1-9 dabao: ";
    cin >> choice;
    if(choice < 1 || choice > 9) {
        cout << "1 se 9 ke beech dabao!" << endl;
        playerMove(); return;
    }
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if(board[row][col]!= 'X' && board[row][col]!= 'O') {
        board[row][col] = currentPlayer;
        moves++;
    } else {
        cout << "Galat move! Jagah bhari hai." << endl;
        playerMove();
    }
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
}

int main() {
    cout << "=== TIC TAC TOE ===\n";
    while(true) {
        drawBoard();
        playerMove();
        if(checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " JEET GAYA!" << endl;
            break;
        }
        if(moves == 9) {
            drawBoard();
            cout << "GAME DRAW!" << endl;
            break;
        }
        switchPlayer();
    }
    return 0;
}
