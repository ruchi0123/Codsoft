#include <iostream>
using namespace std;

char board[3][3];
char Player;

void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool isValidMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    return (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = Player;
}

bool checkWin() {
    // Rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == Player && board[i][1] == Player && board[i][2] == Player)
            return true;
        if (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player)
            return true;
    }
    if (board[0][0] == Player && board[1][1] == Player && board[2][2] == Player)
        return true;
    if (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    Player = (Player == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        Player = 'X';
        bool gameOver = false;

        cout << "Tic-Tac-Toe Game\n";
        cout << "Player 1: X\nPlayer 2: O\n";

        while (!gameOver) {
            displayBoard();
            int move;
            cout << "Player " << Player << ", enter your move (1-9): ";
            cin >> move;

            if (isValidMove(move)) {
                makeMove(move);
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << Player << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
