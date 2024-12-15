// Given an array of integers nums and an integer k. A continuous subarray is called nice 
// if there are k odd numbers on it. Find the count of them.
#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays_1(vector<int>& nums, int k);

int numberOfSubarrays_2(vector<int>& nums, int k);

int helper_3(vector<int>& nums, int k);
int numberOfSubarrays_3(vector<int>& nums, int k);


int main(){
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    
    cout << numberOfSubarrays_1(nums, k) << "\n\n";
    cout << numberOfSubarrays_2(nums, k) << "\n\n";
    cout << numberOfSubarrays_3(nums, k) << "\n\n";
    
    return 0;
}

int numberOfSubarrays_1(vector<int>& nums, int k){
    int n = nums.size(), result = 0, prefixSum = 0;
    unordered_map<int, int> mp; // sum, count
    mp[0] = 1;
    for (int i = 0; i < n; ++i){
        prefixSum += (nums[i] % 2 == 1)? 1: 0;
        result += mp[prefixSum - k];
        mp[prefixSum]++;
    }
    return result;
}

int numberOfSubarrays_2(vector<int>& nums, int k){
    int n = nums.size();
    int left = 0, result = 0, currOddCount = 0, temp = 0;
    
    for (int i = 0; i < n; ++i){
        if (nums[i] % 2 == 1){
            currOddCount++;
            temp = 0;
        }
        
        while (currOddCount == k){
            temp++;
            if (nums[left] % 2 == 1) currOddCount--;
            left++;
        }
        
        result += temp;
    }
    
    return result;
}

int helper_3(vector<int>& nums, int k){
    int n = nums.size();
    int left = 0, count = 0, currOddCount = 0;
    
    for (int right = 0; right < n; ++right){
        if (nums[right] % 2 == 1) currOddCount++;
        
        while (currOddCount > k){
            if (nums[left] % 2 == 1) currOddCount--;
            left++;
        }
        count += (right - left + 1); // The number of subarrays ending with right
    }
    return count;
}
int numberOfSubarrays_3(vector<int>& nums, int k){
    return helper_3(nums, k) - helper_3(nums, k - 1);
}


/*
    Explanation for the first method: We consider odd nums as 1, and even nums as 0. So we just need to find
    the number of subarrays with the sum of k.
    For it we use prefix sum method.
    We just try to use this formula: (i, j) = (0, j) - (0, i).
*/

/*
    Explanation for the second method: That is pretty easy way actually for the problem.
    Just you can ask, why I have used temp. Imagine an array like: [2,4,1,6,1,8,4]
    Up to the last 1, there is 3 subarray, but we need to consider subarrays after the second 1.
    whose endings are [.., 8] and [.., 4] and [.., 8, 4].
    For each case we again use the last count, because our odd count was not updated.
*/

/*
    Explanation for the third method: First of all, we need to realize this formula:
    result(k) = f(k) - f(k-1). Where f(x) is the number of subarrays where exist at most x odd nums.
    The count may be less or equal to x.
    
    After understanding this logic, we can leverage this.
    And the code is pretty easy to understand.
    Just if you did not get the part count += (right - left + 1), that means the number of
    subarrays which end in the right index. 
    Whenever the number of odd nums exceed k, in the while loop, we try to decrease it.
*/
