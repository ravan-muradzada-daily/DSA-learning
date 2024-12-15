#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i = 0; i < n; ++i){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix){
    for (auto& i: matrix){
        for (int j: i){
            printf("%4d", j);
        }
        cout << endl;
    }
    cout << "\n\n\n";
}

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    
    cout << "Initial matrix:\n";
    printMatrix(matrix);
    rotate(matrix);
    cout << "Rotated matrix:\n";
    printMatrix(matrix);
    
    return 0;
}
