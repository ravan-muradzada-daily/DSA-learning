#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums){
    int n = nums.size();
    if (n == 1) return 1;
    
    int count = 0, majority = 0;
    
    for (int i = 0; i < n; ++i){
        if (count == 0) majority = nums[i];
        if (nums[i] == majority) count++;
        else count--;
    }
    return majority;
}

int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    int result = majorityElement(nums);
    
    cout << result;
    
    return 0;
}
