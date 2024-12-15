// Given an array nums of distinct integers, find all the possible permutations.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPermutations;

void backtrack(vector<int>& nums, vector<int>& current, int currPermutaionSize, int mainArray_size, vector<bool>& used){
    if (currPermutaionSize == mainArray_size){
        allPermutations.push_back(current);
        return;
    }
    
    for (int i = 0; i < mainArray_size; ++i){
        if (used[i]) continue; // To check whether the number is in the current permutation or not.
        
        current.push_back(nums[i]); // We first add the number to the curr permutation,
        used[i] = true;
        backtrack(nums, current, currPermutaionSize + 1, mainArray_size, used); // send it to look for the next element
        current.pop_back(); // and now remove it for the next permutation
        used[i] = false;
    }
}
/*
Explanation of the given code. As example array, [1, 2, 3] will be used and each recursion
call will be named as "reality".

    We know that for the permutations of the array, for the determination of the first element, 
    we can pick any element of the array. And our for loop just do it. "Used" array helps us not
    to take the same element to our list twice. To generate all these permutations: [1,.,.]; [2, ., .]; 
    [3, ., .]. For that of course, we need to add each elements from the main array. However, because of
    not allowing to stack them, after creating one reality(such us, [1, ..]), we need to remove it 
    for afterhand permutations like [2, ..]; [3, ..]. 
    After that for each new permutations ([1..], [2..], [3..]), we need to add new elements. Don't forget
    that, now there are three realities and for our first reality, 1 is already choosen, then for the second
    element the new 2 realities will be generated, which are [1, 2, .] and [1, 3, .]. To replace numbers for the
    second index, we need popping.
    And the same rule works for others:
    For [2, ..], we have [2, 1, .] and [2, 3, .].
    For [3, ..], we have [3, 1, .] and [3, 2, .].
    
    And now, we have 6 realities: [1,2,.], [1, 3, .], [2, 1, .], [2, 3, .], [3, 1, .], [3, 2, .].
    For the last space, each lacking number is inserted and now, all the permutations are ready!

*/


int main(){
    vector<int> nums = {1, 2, 3}; // Example input
    int mainArray_size = nums.size();
    vector<int> current; // For the current permutation
    vector<bool> used(mainArray_size, false);
    backtrack(nums, current, 0, mainArray_size, used);
    
    for (auto i: allPermutations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
