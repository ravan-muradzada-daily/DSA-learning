#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes_1(vector<int>& nums){
    int count = 0, maxCount = 0, n = nums.size();
    
    for (int i = 0; i < n; ++i){
        if (nums[i] == 1) count++;
        else count = 0;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
// findMaxConsecutiveOnes_2 is like the third one, but k = 1
int findMaxConsecutiveOnes_3(vector<int>& nums, int k){
    int n = nums.size();
    if (n <= k) return n;
    int left = 0, zeroCount = 0, maxLen = 0;
    
    for (int right = 0; right < n; ++right){
        if (nums[right] == 0) zeroCount++;
        
        if (zeroCount > k){
            zeroCount--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        // Or just maxLen = right - left + 1;
    }
    
    return maxLen;
}
/*
    The first problem is pretty easy, but for the third one, we need to think a little.
    First of all, I note that, we can replace if statement in the loop with while loop, 
    which makes it much more easier to understand. However, using if, it is more efficient.
    Why? Because, in that case, we do not let maxLen to increase because both pointers move
    simultaneously, so in any case we have the possible largest length.
*/
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;
    cout << findMaxConsecutiveOnes_1(nums) << "\n\n";
    cout << findMaxConsecutiveOnes_3(nums, k) << "\n\n";
    
    return 0;
}
