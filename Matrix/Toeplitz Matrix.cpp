#include <bits/stdc++.h>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    
    for (int i = 0; i < m-1; ++i){
        for (int j = 0; j < n-1; ++j){
            if (matrix[i][j] != matrix[i+1][j+1])
                return false;
        }
    }
    
    return true;
}

void printMatrix(vector<vector<int>>& matrix){
    for (auto& i: matrix){
        for (int j: i){
            printf("%5d", j);
        }
        cout << endl;
    }
    cout << "\n\n\n";
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    printMatrix(matrix);
    
    cout << boolalpha << isToeplitzMatrix(matrix);
    
    return 0;
}
