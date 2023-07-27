#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a winner
char checkWinner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // If no winner yet
    return ' ';
}

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int row, col;
    int moves = 0;
    char player = 'X';
    char winner = ' ';

    cout << "Tic Tac Toe" << endl;

    do {
        // Display current board
        displayBoard(board);

        // Switch between players
        player = (player == 'X') ? 'O' : 'X';

        // Get current player's move
        cout << "Player " << player << ", choose a position (1-9): ";
        cin >> move;

        // Convert the position to matrix indices
        row = (move - 1) / 3;
        col = (move - 1) % 3;

        // Check if the chosen position is available
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            moves++;
        }
        else {
            cout << "Invalid position. Try again." << endl;
        }

        // Check for a winner after at least 5 moves
        if (moves >= 5) {
            winner = checkWinner(board);
        }
    } while (moves < 9 && winner == ' ');

    // Display the game result
    displayBoard(board);
    if (winner != ' ') {
        cout << "Congratulations! Player " << winner << " wins!" << endl;
    }
    else {
        cout << "The game ended in a draw!" << endl;
    }

    return 0;
}
