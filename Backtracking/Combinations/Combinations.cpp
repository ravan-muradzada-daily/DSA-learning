// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombinations;

void backtrack(int indx, int n, int k, vector<int>& curr){
    if (curr.size() == k){ // To check whether the current sequence is full or not.
        allCombinations.push_back(curr);
        return;
    }
    
    for (int i = indx; i <= n; ++i){
        curr.push_back(i);
        backtrack(i + 1, n, k, curr);
        curr.pop_back();
    }
}

/*
    Consider that, [a, b] = [b, a] for combinations and we need to remove duplicates.
    In our case, we have numbers [1, 2, 3, 4] and we should get subsequences containing
    with two elements.
    My approach is that from the beginning, we take each number with the numbers after that,
    such us, if we take 2 we take both [2, 3] and [2, 4]. And continue it up to the last possible
    subsequence.
    If k was more than 2, such us 3, we take any number from the array and generate a new sequence with it
    and two numbers after that, like with 2: [2, 3, 4] {no possible combination for the current input}.
    And for each reality we wait for the k elements and when there are k elements in each sequence, we 
    add it to allCombinations array and finish the reality here.

*/
int main(){
    int n = 4, k = 2; // Example inputs
    vector<int> curr;
    backtrack(1, n, k, curr);
    
    for (auto i: allCombinations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
