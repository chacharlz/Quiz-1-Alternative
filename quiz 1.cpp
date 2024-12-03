#include <iostream>
#include <vector>

using namespace std;

// Function to print the board
void printBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i*3] == player && board[i*3 + 1] == player && board[i*3 + 2] == player) ||  // Row
            (board[i] == player && board[i + 3] == player && board[i + 6] == player)) {  // Column
            return true;
        }
    }
    // Check diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) || 
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a tie (board is full)
bool checkTie(const vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            return false;  // Board is not full
        }
    }
    return true;  // Board is full, it's a tie
}

// Function to get the player's move and update the board
void takeTurn(vector<char>& board, char player) {
    int position;
    cout << "Player " << player << "'s turn. Enter a position (1-9): ";
    while (true) {
        cin >> position;
        
        // Check if the input is valid
        if (cin.fail() || position < 1 || position > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin.clear();  // Clear the input error flag
            cin.ignore(10000, '\n');  // Ignore invalid input up to 10000 characters
        } else {
            position -= 1;  // Convert to 0-based index
            if (board[position] != ' ') {
                cout << "That position is already taken. Choose another one: ";
            } else {
                board[position] = player;
                break;
            }
        }
    }
}

// Function to start a new game
void startNewGame() {
    vector<char> board(9, ' ');  // Initialize board with empty spaces
    char currentPlayer = 'X';
    bool gameOver = false;
    
    while (!gameOver) {
        printBoard(board);
        takeTurn(board, currentPlayer);
        
        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } 
        // Check if the game is a tie
        else if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } 
        // Switch players
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    char playAgain;
    
    // Main game loop
    do {
        startNewGame();
        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        
    } while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Thanks for playing!" << endl;
    return 0;
}

