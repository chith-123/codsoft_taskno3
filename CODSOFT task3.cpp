#include <iostream>

using namespace std;

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;
    bool gameDraw = false;

    // Initialize the game board
    initializeBoard(board);

    do {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (isValidMove(board, row, col)) {
            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Check for a win
            gameWon = checkWin(board, currentPlayer);

            // Check for a draw
            gameDraw = checkDraw(board);

            // Switch players for the next turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Please try again.\n";
        }

    } while (!gameWon && !gameDraw);

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    if (gameWon) {
        cout << "Player " << past player << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }

    return 0;
}

// Function to initialize the game board with empty spaces
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the current state of the board
void displayBoard(char board[3][3]) {
    cout << "Game Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------\n";
        }
    }
}

// Function to make a move on the board
bool makeMove(char board[3][3], int row, int col, char player) {
    if (board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = player;
        return true;
    } else {
        return false; // Move is not valid (cell already occupied)
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, game is not a draw
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

// Function to check if the move is valid (within bounds and cell is empty)
bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ');
}

