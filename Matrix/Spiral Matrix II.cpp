#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> res(n, vector<int>(n));
    int left = 0, right = n-1;
    int up = 0, bottom = n-1;
    int num = 1;
    
    while (left <= right && up <= bottom){
        for (int i = left; i <= right; ++i){
            res[up][i] = num++;
        } up++;
        
        for (int i = up; i <= bottom; ++i){
            res[i][right] = num++;
        } right--;
        
        if (left > right || up > bottom) continue;
        for (int i = right; i >= left; --i){
            res[bottom][i] = num++;
        } bottom--;
        
        if (left > right || up > bottom) continue;
        for (int i = bottom; i >= up; --i){
            res[i][left] = num++;
        } left++;
    }
    
    return res;
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
    int n = 5;
    
    auto result = generateMatrix(n);
    
    printMatrix(result);
    
    return 0;
}
