/* Given an integer array of unique elements, find all possible 
subsets. The solution set must not contain duplicate subsets. */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombinations;

void backtrack(vector<int>& nums, vector<int>& curr, int indx, int size){
    if (indx <= size){
        allCombinations.push_back(curr);
    }
    if (indx == size) return;
    
    for (int i = indx; i < size; ++i){
        curr.push_back(nums[i]);
        backtrack(nums, curr, i + 1, size);
        curr.pop_back();
    }
}
/*
    Here, the logic is so similar to the combination problem. So we try to 
    get realities for each number. However, the only difference is that,
    the size of the combinations can be less than the size of the main array.
    To resolve that problem up to reaching the full combination, we add
    each little combinations to allCombinations array.
*/
int main(){
    vector<int> nums = {0};
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
