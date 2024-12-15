/* Given an array of distinct integers candidates and a target integer target, 
   return a list of all unique combinations of candidates where the chosen numbers sum to target.
   The same number may be chosen from candidates an unlimited number of times. */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombination;

void backtrack(vector<int>& candidates, vector<int>& curr, int indx, int size, int target){
    if (target < 0) return;
    if (indx == size){
        if (target == 0){
            allCombination.push_back(curr);
        }
        return;
    }
    
    if (target >= candidates[indx]){
        curr.push_back(candidates[indx]);
        backtrack(candidates, curr, indx, size, target - candidates[indx]);
        curr.pop_back();
    }
    backtrack(candidates, curr, indx + 1, size, target);
}
/*
    In that case, if the indx is equal to size and at the same time target is 0, 
    that refers, this is proper combination. If target < 0, that is not.
    If target >= candidates[indx], that means this candidate migth be proper for us.
    To check it first we add it to our curr and recurse it.
    Then we pop it and recurse the potential combination without it.
    In example: [2, 3, 6]; target = 8
    
    8 >= 2, thus 2 is added and then new reality is generated which is [2,..] (6) and then it is popped
    and there is new reality like []. Our first reality comes and creates new two realities, first
    is [2, 2, ..] and the second is [2, ..]. As you can see, in one reality the same number is not added, but
    in the other, it is. And it is happening up to indx == size and target < 0.
*/

int main(){
    vector<int> candidates = {2, 3, 6};
    int target = 8, size = candidates.size();
    vector<int> curr;
    backtrack(candidates, curr, 0, size, target);
    
    for (auto i: allCombination){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
