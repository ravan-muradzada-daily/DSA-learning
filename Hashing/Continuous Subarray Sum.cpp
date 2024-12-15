#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k){
    int n = nums.size(), Remainder, prefixSum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1; // Just default value to handle case where subarray starting from 0(index) is divisible by k.
    for (int i = 0; i < n; ++i){
        prefixSum += nums[i];
        Remainder = prefixSum % k;
        if (mp.find(Remainder) != mp.end()){
            if ((i - mp[Remainder]) >= 2) return true;
        }else{
            mp[Remainder] = i;
        }
    }
    return false;
}
/*
    The remainder is a part of the number which precludes it to be divisible by k.
    To make it divisible we need to just substract the remainder, not anymore.
    By traversing array, we find the remainder parts of the prefix sums and store it in the
    hash map. If we currently find the specific remainder which already exists in the hash map,
    that refers we can just substract this from the current prefix sum and find the solution. In that
    case, we just return true.
    mp[0] = -1(any default value). We do it to handle case where subarray starting from 0(index) is divisible by k,
    because in that case, up to this point, there is no 0 in hashmap, so if we do not add it beforehand, our function
    cannot understand to have to return.
*/
int main(){
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 7;
    
    cout << boolalpha << checkSubarraySum(nums, k);
    
    return 0;
}
