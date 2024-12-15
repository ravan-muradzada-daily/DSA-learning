#include <bits/stdc++.h>
using namespace std;

void findMinMax(vector<int>& boards, int& left, int& right){
    left = right = boards[0];

    for (int i = 1; i < boards.size(); ++i){
        left = max(left, boards[i]);
        right += boards[i];
    }
}

bool calculate(vector<int>& boards, int maxPossibleSum, int k){
    int currSum = 0, count = 1;

    for (int i = 0; i < boards.size(); ++i){
        if (currSum + boards[i] > maxPossibleSum){
            count++;
            currSum = 0;
        }

        currSum += boards[i];
    }

    return count <= k;
}


int findLargestMinDistance(vector<int> &boards, int k){
    int n = boards.size();
    int left, right, mid, res;
    findMinMax(boards, left, right);

    while (left <= right){
        mid = (left + right) / 2;

        if (calculate(boards, mid, k)){
            right = mid - 1;
            res = mid;
        }else{
            left = mid + 1;
        }
    }   

    return res;
}

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    
    int result = findLargestMinDistance(boards, k);
    
    cout << "Result: " << result;
    
    
    return 0;
}
