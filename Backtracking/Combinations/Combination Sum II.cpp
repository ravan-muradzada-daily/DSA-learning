/*  Find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination. The solution set must 
not contain duplicate combinations. The given array can contain duplicates. */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombinations;

void backtrack(vector<int>& candidates, vector<int>& curr, int indx, int size, int target){
    if (target == 0){
        allCombinations.push_back(curr); return;
    }
    if (target < 0) return;
    
    for (int i = indx; i < size; ++i){
        if (i > indx && candidates[i] == candidates[i - 1]) continue;
        
        curr.push_back(candidates[i]);
        backtrack(candidates, curr, i + 1, size, target - candidates[i]);
        curr.pop_back();
    }
}
/*
    First, understand that if multiple realities starts or continues with the same numbers
    in the same index, they will generate duplicates and because of avoiding them, we 
    need to prevent to have the same numbers in the same indices in different realities.
    Such us, if there are realities like [1, ..] and again [1, ..], of course they will 
    generate duplicates. To prevent that I add there a new if condition, which checks if the
    for the current reality is the same number is used or not.

*/
int main(){
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    sort(candidates.begin(), candidates.end()); // [1, 1, 2, 5, 6, 7, 10]
    int target = 8, size = candidates.size();
    vector<int> curr;
    backtrack(candidates, curr, 0, size ,target);
    
    for (auto i: allCombinations){
        for (int j: i) cout << j << " ";
        cout << endl;
    }
    
    return 0;
}
