#include <bits/stdc++.h>
using namespace std;

int max(int a, int b, int c){
    a = (a > b)? a: b;
    return (a > c)? a: c;
}

int maxProduct(vector<int>& nums){
    int pref = 1, suf = 1, Max = INT_MIN;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i){
        if (pref == 0) pref = 1;
        if (suf == 0) suf = 1;
        pref *= nums[i];
        suf *= nums[n-1-i];
        Max = max(Max, suf, pref);
    }
    
    return Max;
}

int main(){
    vector<int> nums = {2,3,-2,4};
    
    cout << maxProduct(nums) << endl;
    
    return 0;
}
