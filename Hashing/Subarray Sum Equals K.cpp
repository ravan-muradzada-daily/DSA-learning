#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    int n = nums.size(), prefixSum, count, target;
    prefixSum = count = 0;
    
    unordered_map<int, int> mp; // sum, count of sum
    mp[0] = 1;
    
    for (int i = 0; i < n; ++i){
        prefixSum += nums[i];
        
        target = prefixSum - k;
        
        count += mp[target];
        
        mp[prefixSum]++;
    }
    
    return count;
}

/*
    To get the proper sequences we need this formula: sumBetween(i, j) = sumBetween(0, i) - sumBetween(0, j). Imagine, 
    i > j and they are indices of the array.
    
    Up to the specific points, the sum is (0, j) and current prefix sum is (0, i). We just need to count += mp[current - previousOnes]
    Let's call (0, j) sum as P.
    It is possible to have the P sum multiple times. Such us in the array of [1, 2, 3, -2, -3, 3, 2, 124], here the sum in
    the interval of (1, 2) is 5 and also it is correct for (1, 6). If our k is 129, we have two subarrays.

*/

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    
    cout << subarraySum(nums, k);
    
    return 0;
}
