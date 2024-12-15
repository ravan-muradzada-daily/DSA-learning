// Given an m x n integer matrix matrix, if an element is 0, 
// set its entire row and column to 0's. O(1) extra space complexity.
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size();
    bool firstRow = false, firstCol = false;
    if (matrix[0][0] == 0) firstCol = firstRow = true;
    else{
        for (int i = 1; i < m; ++i){
            if (matrix[0][i] == 0) firstRow = true;
        }
        for (int i = 1; i < n; ++i){
            if (matrix[i][0] == 0) firstCol = true;
        }
    }
    
    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            if (matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
        }
    }
    
    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    
    if (firstRow){
        for (int i = 0; i < m; ++i) matrix[0][i] = 0;
    }
    if (firstCol){
        for (int i = 0; i < n; ++i) matrix[i][0] = 0;
    }
}

void printMatrix(vector<vector<int>>& matrix){
    for (auto& i: matrix){
        for (int& j: i){
            cout << j << " ";
        } cout << endl;
    }
    cout << "\n\n\n";
}

int main(){
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    printMatrix(matrix);
    setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}
