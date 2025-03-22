#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

bool checkWin(const vector<char>& board, char player) {

    for (int i = 0; i < 3; ++i) {
        if ((board[i*3] == player && board[i*3 + 1] == player && board[i*3 + 2] == player) ||  
            (board[i] == player && board[i + 3] == player && board[i + 6] == player)) {  
            return true
        }
    }
    
    if ((board[0] == player && board[4] == player && board[8] == player) || 
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

bool checkTie(const vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            return false; 
        }
    }
    return true;  
}

void takeTurn(vector<char>& board, char player) {
    int position;
    cout << "Player " << player << "'s turn. Enter a position (1-9): ";
    while (true) {
        cin >> position;
        
        if (cin.fail() || position < 1 || position > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin.clear();  
            cin.ignore(10000, '\n');  
        } else {
            position -= 1;  
            if (board[position] != ' ') {
                cout << "That position is already taken. Choose another one: ";
            } else {
                board[position] = player;
                break;
            }
        }
    }
}


void startNewGame() {
    vector<char> board(9, ' ');  
    char currentPlayer = 'X';
    bool gameOver = false;
    
    while (!gameOver) {
        printBoard(board);
        takeTurn(board, currentPlayer);
        
        
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } 

        else if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } 
        
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    char playAgain;
    

    do {
        startNewGame();
        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        
    } while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Thanks for playing!" << endl;
    return 0;
}

