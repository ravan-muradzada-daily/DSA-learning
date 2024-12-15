#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mp = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
int MOD = 1000000000 + 7;

int knightDialer_Tabulation_1(int n){
    if (n == 1) return 10;
    
    vector<vector<int>> dp(n+1, vector<int>(10));
    
    for (int i = 0; i <= 9; ++i){
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= n; ++i){
        for (int j = 0; j <= 9; ++j){
            int currRes = 0;
            for (int digit: mp[j]){
                currRes = (currRes + dp[i-1][digit]) % MOD; 
            }
            dp[i][j] = currRes;
        }
    }
    
    int result = 0;
    
    for (int i = 0; i <= 9; ++i){
        result = (result + dp[n][i]) % MOD;    
    }
    
    return result;
}

int knightDialer_Tabulation_2(int n){
    if (n == 1) return 10;
    
    vector<int> curr(10), prev(10, 1);
    
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= 9; ++j){
            int currRes = 0;
            for (int digit: mp[j]){
                currRes = (currRes + prev[digit]) % MOD;
            }
            curr[j] = currRes;
        }
        prev = curr;
    }
    
    int result = 0;
    
    for (int i = 0; i <= 9; ++i){
        result = (result + curr[i]) % MOD;
    }
    
    return result;
}

int main(){
    int n = 3131;
    
    cout << "Tabulation 1: " << knightDialer_Tabulation_1(n) << "\n\n";
    cout << "Tabulation 2: " << knightDialer_Tabulation_2(n) << "\n\n";
    
    return 0;
}
