#include <bits/stdc++.h>
using namespace std;

int numDecodings(string& s){
    if (s[0] == '0') return 0;
    int n = s.length();
    
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1; // dp[0] is additional
    
    for (int i = 2; i <= n; ++i){
        int one = s[i-1] - '0';
        int two = stoi(s.substr(i-2, 2));
        
        if (one > 0) dp[i] += dp[i-1];
        
        if (two >= 10 && two <= 26) dp[i] += dp[i-2];
    }
    
    return dp[n];
}

int main(){
    string s = "1123";
    
    cout << numDecodings(s) << endl;
    
    return 0;
}
