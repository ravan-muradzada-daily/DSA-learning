#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = n-1;
    int up = 0, bottom = m-1;
    int indx = 0;
    vector<int> res (m*n);
    
    while (left <= right && up <= bottom){
        for (int i = left; i <= right; ++i){
            res[indx++] = matrix[up][i];    
        } up++;
        
        for (int i = up; i <= bottom; ++i){
            res[indx++] = matrix[i][right]; 
        } right--;
        
        if (left > right && up > bottom) continue;
        for (int i = right; i >= left; --i){
            res[indx++] = matrix[bottom][i]; 
        } bottom--;
        
        if (left > right && up > bottom) continue;
        for (int i = bottom; i >= up; --i){
            res[indx++] = matrix[i][left]; 
        } left++;
    }
    
    return res;
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
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrix(matrix);
    
    auto result = spiralOrder(matrix);
    
    for (int i: result) cout << i << " ";
    
    return 0;
}
