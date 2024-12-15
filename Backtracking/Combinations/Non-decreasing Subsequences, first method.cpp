/*
    Given an integer array nums, return all the different possible non-decreasing 
    subsequences of the given array with at least two elements.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allSubsequences;

void findSubsequences(vector<int>& nums);

void backtrack(vector<int>& nums, vector<int>& curr, int indx, int n);


int main(){
    vector<int> nums = {4, 6, 7, 7};
    
    findSubsequences(nums);
    
    for (auto i: allSubsequences){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}

void findSubsequences(vector<int>& nums){
    vector<int> curr;
    int n = nums.size(), indx = 0;
    backtrack(curr, nums, indx, n);
}

void backtrack(vector<int>& curr, vector<int>& nums, int indx, int n){
    if (curr.size() >= 2) allSubsequences.push_back(curr);
    if (indx == n) return;
    
    unordered_set<int> usedSet;
    for (int i = indx; i < n; ++i){
        if ((curr.empty() || curr.back() <= nums[i]) && usedSet.find(nums[i]) == usedSet.end()){
            curr.push_back(nums[i]);
            usedSet.insert(nums[i]);
            backtrack(curr, nums, i + 1, n);
            curr.pop_back();
        }
    }
}
