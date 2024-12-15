/* Given an array of distinct integers candidates and a target integer target, 
   return a list of all unique combinations of candidates where the chosen numbers sum to target.
   The same number may be chosen from candidates an unlimited number of times. */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombination;

void backtrack(vector<int>& candidates, vector<int>& curr, int indx, int size, int target){
    if (target < 0) return;
    if (target == 0){
        allCombination.push_back(curr);
        return;
    }
    
    for (int i = indx; i < size; ++i){
        curr.push_back(candidates[i]);
        backtrack(candidates, curr, i, size, target - candidates[i]);
        curr.pop_back();
    }
}
/*
        Remember for combinations, [a, b, c] = [b, a, c], and because we should remove duplicates
    of the sequence, we need to pay attention to it. To determine whether we would get to the target
    or not, we start from target and try to make it reach to 0. If it happens, that is one combination,
    but if it would be less than 0, that is not.
    First, let's come some logical assurements. We need to recurse a number up to target <= 0. 
    If it is zero, we add it to allCombination array, otherwise not.
    [2, 3, 6, 7]; target = 7
    What happens in the loop according to input in the example? (The sums will be given in () )
    indx is 0 and it creates new realities which are [2, ..](5), [3, ..](4), [6, ..](1), [7, ..](0).
    For [2,..], the new reality starts and it creates realities like [2, 2, ..](3), [2, 3, ..] ....
    The others also do the same. If you paid attention, in the first iteration for [7, ..], the target became
    0 and that means that is one combination.
    
*/

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7, size = candidates.size();
    vector<int> curr;
    backtrack(candidates, curr, 0, size, target);
    
    for (auto i: allCombination){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
