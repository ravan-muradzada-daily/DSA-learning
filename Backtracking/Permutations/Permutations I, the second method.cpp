// Given an array nums of distinct integers, find all the possible permutations.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPermutations;

void backtrack(vector<int>& nums, int indx, int mainArray_size){
    if (indx == mainArray_size){
        allPermutations.push_back(nums);
        return;
    }
    
    for (int i = indx; i < mainArray_size; ++i){
        swap(nums[indx], nums[i]);
        backtrack(nums, indx + 1, mainArray_size);
        swap(nums[indx], nums[i]);
    }
}
/*
That is a litte bit better algorithm than previous one, in terms of space complexity.
    Imagine our main array: [1, 2, 3]
    There is a specific algorithm to find all the permutations of that. So we need to
    swap each element with the element after itself(starting from itself) and continue it up to the last element.
    Let's start with 1. 
    From the swapping 1 with itself, 2 and 3, we will get [1, 2, 3], [2, 1, 3] and [3, 2, 1]. 
    The first swapping wave finished.
    Now let's do it for the second element of each array, so we need the swap each the second element with
    itself and the third one. The result: [1, 2, 3], [1, 3, 2]; [2, 1, 3], [2, 3, 1]; [3, 2, 1], [3, 1, 2].
    Now, let's do it for the third 
    element of the array. There is just one number for swapping for the third element (in our example) and that is itself,
    so the permutations will not change.
    Thus, we can say our permutations are [1, 2, 3], [1, 3, 2]; [2, 1, 3], [2, 3, 1]; [3, 2, 1], [3, 1, 2].
    
    You can ask, why in the each iteration of the loop, why we swap twice? 
    The answer: Actually after swapping and sending it to the new reality where it will be added to the allPermutations 
    array, we need to set it back to the previous version to be able to have new permutation from the source one.

*/


int main(){
    vector<int> nums = {1, 2, 3}; // Example input
    int mainArray_size = nums.size();
    backtrack(nums, 0, mainArray_size);
    
    for (auto i: allPermutations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
