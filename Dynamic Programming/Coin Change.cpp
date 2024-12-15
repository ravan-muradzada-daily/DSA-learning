#include <bits/stdc++.h>
using namespace std;

int helperOfMemoization(vector<int>& coins, int amount, int indx, vector<vector<int>>& dp){
    if (amount == 0) return 0;

    if (indx == 0){
        return (amount % coins[indx] == 0)? (amount/coins[indx]): 1e9;
    }
    
    if (dp[indx][amount] != -1) return dp[indx][amount];
    
    int notTake = helperOfMemoization(coins, amount, indx - 1, dp);
    int take = 1e9;
    if (coins[indx] <= amount)
        take = 1 + helperOfMemoization(coins, amount-coins[indx], indx, dp);
    
    return dp[indx][amount] = min(take, notTake);
}

int coinChangeMemoization(vector<int>& coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int result = helperOfMemoization(coins, amount, n-1, dp);
    return (result == 1e9)? -1: result;
}

int coinChangeTabulation(vector<int>& coins, int amount){
    int n = coins.size();
    vector<int> dp(amount+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i){
        for (int j: coins){
            if (i - j >= 0){
                dp[i] = min(dp[i], 1 + dp[i-j]);
            }
        }
    }
    return (dp[amount] == 1e9)? -1: dp[amount];
}

int main(){
    vector<int> coins = {3, 4, 1, 6};
    int amount = 11;
    
    cout << coinChangeMemoization(coins, amount) << "\n\n";
    cout << coinChangeTabulation(coins, amount) << "\n\n";
    return 0;
}
