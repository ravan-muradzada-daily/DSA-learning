#include <bits/stdc++.h>
using namespace std;

int Count = 0;
vector<string> board;
int size = 12;
bool isSafe(int row, int col, int n){    
    for (int i = 0; i < n; ++i){
        if (col - i >= 0 && board[row][col - i] == 'Q') return false;
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
        if (row + i < n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
    }
    return true;
}

void backtrack(int col, int n){
    if (col == n){
        Count++; 
        return;
    }
    
    for (int row = 0; row < n; ++row){
        if (isSafe(row, col, n)){
            board[row][col] = 'Q';
            backtrack(col + 1, n);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4; 
    string s(n, '.');
    board.assign(n, s);
    backtrack(0, n);
    
    cout << Count;
    return 0;
}
