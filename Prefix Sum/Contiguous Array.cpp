#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums){
    unordered_map<int, int> mp; // sum, index
    int Result = 0, n = nums.size(), prefixSum = 0;
    mp[0] = -1; // If the contigious array is from 0th index up to the current one,
    // this helps to handle this. Like, if in the inverval of [0 - 4], the sum is 0,
    // we need to have mp[0]. U can ask, why -1? Because, in this case, there is 5 nums
    // between 0 and 4. To handle it we take its value -1.
    
    
    // Imagine 0 as -1, so while finding prefix sum, we will consider it as -1.
    
    for (int i = 0; i < n; ++i){
        prefixSum += (nums[i] == 1)? 1: -1;
        
        if (mp.find(prefixSum) != mp.end()){
            Result = max(Result, i - mp[prefixSum]);
            // If up to specific point there is also the same prefix sum with the
            // current one, that means among these points, the sum is 0, which refers there
            // are the same number of 0s and 1s. Like, if between [0 - i] and [0 - j] the sums are
            // equal, that refers the sum between [i - j] is 0.
        }else{
            mp[prefixSum] = i;
        }
    }
    
    return Result;
}

int main(){
    vector<int> nums = {0, 1, 1, 0, 1, 1, 1, 0};
    
    cout << findMaxLength(nums);
    
    return 0;
}
