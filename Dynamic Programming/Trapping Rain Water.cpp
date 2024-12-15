#include <bits/stdc++.h>
using namespace std;

int trap_1(vector<int>& height){
    int n = height.size(), result = 0;
    vector<int> pref(n), suf(n);
    pref[0] = height[0];
    suf[n-1] = height[n-1];
    
    for (int i = 1; i < n; ++i){
        pref[i] = max(pref[i-1], height[i]);
        suf[n-1-i] = max(suf[n-i], height[n-1-i]);
    }
    
    for (int i = 0; i < n; ++i){
        int temp = min(pref[i], suf[i]) - height[i];
        result += (temp < 0)? 0: temp;
    }
    // O(n) space complexity
    return result;
}

int trap_2(vector<int>& height){
    int n = height.size();
    int l = 0, r = n - 1;
    int leftMax = height[0], rightMax = height[n-1];
    
    while (l < r){
        if (leftMax <= rightMax){
            result += (leftMax - height[l]);
            l++;
            leftMax = max(leftMax, height[l]);
        }else{
            result += (rightMax - height[r]);
            r--;
            rightMax = max(rightMax, height[r]);
        }
    }
    // O(1) space complexity
    return result;
}
int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    cout << trap_1(height) << "\n\n";
    
    cout << trap_2(height) << "\n\n";
    
    return 0;
}
