#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
    int count = 0, n = nums1.size();
    unordered_map<int, int> mp; // Sum, Count 
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            mp[nums1[i] + nums2[j]]++;
        }
    }
    int target;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            target = -(nums3[i] + nums4[j]);
            if (mp.find(target) != mp.end()) count += mp[target];
        }
    }
    
    return count;   
}

int main(){
    vector<int> nums1 = {1,2}, nums2 = {-2,-1}, nums3 = {-1,2}, nums4 = {0,2};
    
    int count = fourSumCount(nums1, nums2, nums3, nums4);
    
    cout << count;
    
    return 0;
}
