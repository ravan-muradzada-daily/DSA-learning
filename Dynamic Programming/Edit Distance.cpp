#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
    a = (a < b)? a: b;
    return (a < c)? a: c;
}

int solveMemoization(string& word1, string& word2, int i1, int i2, vector<vector<int>>& dp){
    if (i1 == 0){
        return i2; // inserting chars
    }
    
    if (i2 == 0){
        return i1; // deleting chars
    }
    
    if (dp[i1][i2] != -1) return dp[i1][i2];
    
    if (word1[i1-1] == word2[i2-1]){
        return dp[i1][i2] = solveMemoization(word1, word2, i1-1, i2-1, dp);
    }
    else{
        return 1 + min(
                solveMemoization(word1, word2, i1-1, i2, dp), // while deleting
                solveMemoization(word1, word2, i1, i2-1, dp), // while insering
                solveMemoization(word1, word2, i1-1, i2-1, dp) // while replacing
            );
    }
}

int solveTabulation_1(string& word1, string& word2){
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = 0; i < n; ++i) dp[i][0] = i; // To create null word2, with the word1, we delete i chars
    for (int i = 0; i < m; ++i) dp[0][i] = i; // To create word2, with the null word1, we insert i chars
    
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    
    return dp[n][m];
}

int solveTabulation_2(string& word1, string& word2){
    int n = word1.length(), m = word2.length();
    vector<int> curr(m+1, 0), prev(m+1, 0);
    
    for (int i = 0; i <= m; ++i) prev[i] = i;
    
    for (int i = 1; i <= n; ++i){
        curr[0] = i;
        for (int j = 1; j <= m; ++j){
            if (word1[i-1] == word2[j-1]){
                curr[j] = prev[j-1];
            }else{
                curr[j] = 1 + min(curr[j-1], prev[j], prev[j-1]);
            }
        }
        prev = curr;
    }
    
    return curr[m];
}

int main(){
    string word1 = "horse", word2 = "ros";
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << "Memoization: " << solveMemoization(word1, word2, n, m, dp) << "\n\n";
    
    cout << "Tabulation 1: " << solveTabulation_1(word1, word2) << "\n\n";
    
    cout << "Tabulation 2: " << solveTabulation_2(word1, word2) << "\n\n";
    
    return 0;
}
