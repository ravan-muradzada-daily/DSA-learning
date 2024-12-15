#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<vector<int>> frequency(n+1);
    for (int i: nums) mp[i]++;
    
    for (auto i: mp){
        frequency[i.second].push_back(i.first);
    }
    
    vector<int> result;
    for (int i = n; i >= 1; --i){
        for (int j: frequency[i]){
            result.push_back(j);    
        }
        if (result.size() == k) break;
    }
  
    return result;
}
/*
    Basic usage bucket sort.
    So in the array, the potential maximum frequency of the element from this array is equal to
    the size of array. Thus, we create matrix frequency to keep track for the elements according to
    their frequency. In this example (in main func), the frequency matrix is like that:
      0      1       2    3    4   5   6    7  (frequencies)
    [[], [1, 3, 5], [6], [4], [], [], [],  []].
*/
int main(){
    vector<int> nums = {4, 5, 1, 6, 4, 3, 4, 6};
    int k = 2;
    
    auto result = topKFrequent(nums, k);
    
    for (int i: result) cout << i << " ";
    
    return 0;
}
