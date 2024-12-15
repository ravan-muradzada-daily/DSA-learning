#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums){
    int n = nums.size();
    int left = 0, prefixSum = 0;
    int minSize = INT_MAX;
    for (int right = 0; right < n; ++right){
        prefixSum += nums[right];
        while (prefixSum >= target){
            minSize = min(minSize, right - left + 1);
            prefixSum -= nums[left];
            left++;
        }
    }
    
    return minSize % INT_MAX;
}
/*
    While checking up to the current index, the sum is already calculated, and if 
    it can be possible to have less size subarrays ahead, we try to minimize our current array.
*/

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    
    cout << minSubArrayLen(target, nums) << endl;
    
    return 0;
}
