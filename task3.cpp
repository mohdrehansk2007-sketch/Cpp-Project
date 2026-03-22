#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
    currentPlayer = 'X';
}

int main() {
    char playAgain;

    do {
        resetBoard();
        int choice;
        bool gameOver = false;

        cout << "=== Tic-Tac-Toe Game ===\n";

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9) {
                cout << "Invalid choice! Enter a number between 1 and 9.\n";
                continue;
            }

            if (!makeMove(choice)) {
                cout << "That position is already taken. Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}