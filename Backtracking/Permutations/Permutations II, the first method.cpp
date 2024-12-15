// Given an array that might contain duplicates, find all possible unique permutations. No sorted array guaranty.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPermutations;

void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, int size, int indx){
    if (indx == size){
        allPermutations.push_back(curr);
    }
    
    for (int i = 0; i < size; ++i){
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        
        curr.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, curr, used, size, indx + 1);
        curr.pop_back();
        used[i] = false;
    }
}

/*
    The logic here is too similar to the previous problem (the first solution).
    However, because here in the given array it is possible to have duplicates, the result
    could also have duplicates and we should prevent it.
    For that, I add the new if statement her. (in the 13th line)
    
    Before that, let's understand, when we don't care the duplicates?
    Imagine we have two permutations currently, first is [2, 1, .] and the second is
    [2, . .]. For the first permutation, if we see the duplicate of 1, we need to add it,
    because it will help to complete the permutation.
    However, for the second element we need not to care one of them. Why?
    If we care, two new realities will be generated: [2, 1(first), .] and [2, 1(second), .].
    Althrought 1's there are different 1's, but for us, they are completly the same numbers.
    So, for the current index, we can just select one of the duplicates and in the next index
    we can select it's dublicate (no problem).
    
    To be able not to care the duplicates, we need to have them together, but how to do it?
    Of course, sorting! Because in the problem, there is no guaranty for the given array to be
    sorted, we need to sort it ourselves.
    
    i > 0 && nums[i] == nums[i - 1], this part of the if statement plays role not to take duplicates, 
    but if it is the first occurrenct of that number, it will choose it. !used[i - 1], that part shows
    us whether for the previous index, the number's duplicate is used or not. If it is used, that means, 
    we want to just add these to our permutation, thus we can let it to continue. Otherwise, that wants
    to create two the same realities, thus we do not allow it.

*/
int main(){
    vector<int> nums = {1, 1, 2};
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<int> curr;
    vector<bool> used(size, false);
    
    backtrack(nums, curr, used, size, 0);
    
    for (auto i: allPermutations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
