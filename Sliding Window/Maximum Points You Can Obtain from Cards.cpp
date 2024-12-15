#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k){
    int n = cardPoints.size(), prefixSum = 0, postfixSum = 0;
    
    for (int i = 0; i < k; ++i) prefixSum += cardPoints[i];
    int maxSum = prefixSum;
    
    for (int i = 0; i < k; ++i){
        prefixSum -= cardPoints[k - i - 1];
        postfixSum += cardPoints[n - i - 1];
        maxSum = max(maxSum, prefixSum + postfixSum);
    }
    
    return maxSum;
}
/*
    We just each possibility and find the result.
*/
int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    
    cout << maxScore(cardPoints, k) << endl;
    
    return 0;
}
