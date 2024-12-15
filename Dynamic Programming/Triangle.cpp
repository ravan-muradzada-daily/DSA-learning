#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size(), m;
    
    for (int i = n-2; i >= 0; --i){
        m = triangle[i].size();
        for (int j = 0; j < m; ++j){
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    
    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    
    cout << minimumTotal(triangle) << endl;
    
    return 0;
}
