#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
   
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    
    if (col == 8) {
        return true;
    }
    
    for (int i = 0; i < 8; i++) {
        if (isSafe(board, i, col)) {
            
            board[i][col] = 1;
            
            if (solveNQueens(board, col + 1)) {
                return true;
            }
           
            board[i][col] = 0;
        }
    }
   
    return false;
}

int main() {
    vector<vector<int>> board(8, vector<int>(8, 0));
    if (solveNQueens(board, 0)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    cout << "| Q ";
                } else {
                    cout << "|   ";
                }
            }
            cout << "|" << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}