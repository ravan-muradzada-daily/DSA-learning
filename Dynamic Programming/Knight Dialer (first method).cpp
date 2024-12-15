#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
const int MOD = 1000000000 + 7;

int helper(int currDigit, int len, vector<vector<int>>& dp){
    if (len == 0) return 1;
    
    if (dp[currDigit][len] != 0) return dp[currDigit][len];
    
    int sumOfPossibleWays = 0;
    
    for (int i: mp[currDigit]){
        sumOfPossibleWays = (sumOfPossibleWays + helper(i, len-1, dp)) % MOD;    
    }
    dp[currDigit][len] = sumOfPossibleWays;
    
    return sumOfPossibleWays;
}

int knightDialer(int n){
    if (n == 1) return 10;
    vector<vector<int>> dp(10, vector<int> (n + 1, 0));
    
    int result = 0;
    
    for (int i = 0; i <= 9; ++i){
        result = (result + helper(i, n-1, dp)) % MOD;
    }
    
    return result;
}

int main(){
    int n = 3131;
   
    cout << knightDialer(n) << endl;
    
    return 0;
}
