// If (nums[i] == nums[j] and abs(i - j) <= k) return true, otherwise false
#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> mp; // num, index
    
    for (int i = 0; i < n; ++i){
        if (mp.find(nums[i]) != mp.end()){
            if (i - mp[nums[i]] <= k) return true;
        }
        mp[nums[i]] = i;
    }
    
    return false;
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    
    cout << boolalpha << containsNearbyDuplicate(nums, k);
    
    return 0;
}
