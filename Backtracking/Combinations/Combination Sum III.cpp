// Find all valid combinations of k numbers that sum up to n. 
// Only numbers 1 through 9 are used, and each number is used at most once.
#include <bits/stdc++.h>
using namespace std;

const int maxBoundary = 9;
vector<vector<int>> allCombinations;

void backtrack(vector<int>& curr, int indx, int k, int target){
    int size = curr.size();
    if (size == k){
        if (target == 0) allCombinations.push_back(curr);
        return;
    }
    if (target < 0) return;
    
    for (int i = indx; i <= maxBoundary; ++i){
        curr.push_back(i);
        backtrack(curr, i + 1, k, target - i);
        curr.pop_back();
    }
    
}
/*
    Very similar logic to previous problems, just the main difference is the maxBoundary is 9,
    that is all.
*/
int main(){
    int k = 3, target = 9;
    vector<int> curr;
    backtrack(curr, 1, k, target);
    
    for (auto i: allCombinations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
