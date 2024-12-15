#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    
    vector<vector<int>> result (n, vector<int>(m));
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};
    cout << "Initial matrix:\n";
    printMatrix(matrix);
    
    auto result = transpose(matrix);
    cout << "Transposed matrix:\n";
    printMatrix(result);
    
    return 0;
}
