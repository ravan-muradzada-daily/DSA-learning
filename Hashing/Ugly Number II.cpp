#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
    a = (a < b)? a: b;
    return (a < c)? a: c;
}

int nthUglyNumber(int n){
    if (n == 1) return 1;
    
    vector<int> dp(n);
    dp[0] = 1;
    int ptr1, ptr2, ptr3;
    ptr1 = ptr2 = ptr3 = 0;
    
    for (int i = 1; i < n; ++i){
        dp[i] = min(dp[ptr1]*2, dp[ptr2]*3, dp[ptr3]*5);
        if (dp[i] == dp[ptr1]*2) ptr1++;
        if (dp[i] == dp[ptr2]*3) ptr2++;
        if (dp[i] == dp[ptr3]*5) ptr3++;
    }
    return dp.back();
}

int main(){
    int n = 10;
    
    int result = nthUglyNumber(n);
    
    cout << result;
    
    return 0;
}
