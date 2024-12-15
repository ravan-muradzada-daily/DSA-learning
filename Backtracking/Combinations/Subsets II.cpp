/*  Given an integer array nums that may contain duplicates, find all possible 
    subsets. The solution set must not contain duplicate subsets. There is no guaranty
    that the given array is sorted */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombinations;

void backtrack(vector<int>& nums, vector<int>& curr, int indx, int size){
    allCombinations.push_back(curr);
    
    for (int i = indx; i < size; ++i){
        if (i > indx && nums[i] == nums[i - 1]) continue;
        curr.push_back(nums[i]);
        backtrack(nums, curr, i + 1, size);
        curr.pop_back();
    }
}
/*
    For each element:
    If it's the first occurrence of the element or if the element is different from the previous element,
    add it to the current subset.
    Recur with the updated subset and the remaining elements starting from the next index.
    Backtrack by removing the last added element before moving to the next iteration.
    Skip adding an element to the current subset if it's a duplicate of the previous 
    element at the same level of recursion. (the process in if condition)
*/
int main(){
    vector<int> nums = {1, 2, 3};
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<int> curr;
    backtrack(nums, curr, 0, size);
    
    for (auto i: allCombinations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }

    return 0;
}
