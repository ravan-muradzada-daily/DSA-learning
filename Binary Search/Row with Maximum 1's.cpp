#include <bits/stdc++.h>
using namespace std;

int checkRow(vector<vector<int>>& matrix, int index, int m){
    int i = INT_MAX;

    int left = 0, right = m-1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (matrix[index][mid] == 1){
            i = min(i, mid);
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return (i == INT_MAX)? 0: (m - i + 1);
}


int rowWithMax1s(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int maxOnes = INT_MIN, maxOnesIndex = -1;

    for (int i = n-1; i >= 0; --i){
        int currRes = checkRow(matrix, i, m);
        if (m == 1)

        if (currRes == 0) continue;

        if (currRes >= maxOnes){
            maxOnes = currRes;
            maxOnesIndex = i;
        }
    }

    return maxOnesIndex;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    
    int result = rowWithMax1s(matrix);
    
    cout << result << endl;
    
    return 0;
}
