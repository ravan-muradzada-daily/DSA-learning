// Uncompleted sudoku is given, complete it.
#include <bits/stdc++.h>
using namespace std;

const int maxSize = 9;
vector<vector<char>> board;
void printSudoku();
bool isValid(int row, int col, char num);
bool findEmptyCell(int& row, int& col);
bool solveSudoku();

int main(){
    board.assign({
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    });    
    printSudoku();
    solveSudoku();
    printSudoku();
        
    return 0;
}

void printSudoku(){
    for (int i = 0; i < maxSize; ++i){
        for (int j = 0; j < maxSize; ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}
bool isValid(int row, int col, char num){
    for (int i = 0; i < maxSize; ++i){
        if (board[row][i] == num || board[i][col] == num) return false;
        
        if (board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num) return false;
    }
    return true;
}
bool findEmptyCell(int& row, int& col){
    for (row = 0; row < maxSize; ++row){
        for (col = 0; col < maxSize; ++col){
            if (board[row][col] == '.'){
                return true;
            }
        }
    }
    return false;
}
bool solveSudoku(){
    int row, col;
    if (!findEmptyCell(row, col)){
        return true;
    }
    
    for (char i = '1'; i <= '9'; ++i){
        if (isValid(row, col, i)){
            board[row][col] = i;
            if (solveSudoku()) return true;
            board[row][col] = '.';
        }
    }
    return false;
}
