#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> all;
vector<bool> rowHash;
vector<bool> firstDiagonalHash; // The diogonal which is -> /
vector<bool> secondDiagonalHash; // The diogonal which is-> \

void backtrack(vector<string>& board, int col, int n){
    if (col == n){
        all.push_back(board); return;
    }
    
    for (int row = 0; row < n; ++row){
        if (!rowHash[row] && !firstDiagonalHash[row + col] && !secondDiagonalHash[n + col - row - 1]){
            board[row][col] = 'Q';
            rowHash[row] = firstDiagonalHash[row + col] = secondDiagonalHash[n + col - row - 1] = true;
            backtrack(board, col + 1, n);
            board[row][col] = '.';
            rowHash[row] = firstDiagonalHash[row + col] = secondDiagonalHash[n + col - row - 1] = false;
        }
    }
}

int main(){
    int n = 4;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; ++i) board[i] = s;
    rowHash.assign(n, false);
    firstDiagonalHash.assign(2*n - 1, false);
    secondDiagonalHash.assign(2*n - 1, false);
    
    backtrack(board, 0, n);
    
    for (auto i: all){
        for (string j: i){
            cout << j << endl;
        } cout << endl << endl << endl;
    }
      
    return 0;
}
