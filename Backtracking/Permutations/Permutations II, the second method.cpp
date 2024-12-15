// Given a collection of numbers, that might contain duplicates, find all possible unique permutations.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPermutations;

void backtrack(unordered_map<int, int>& mp, vector<int>& curr, int sizeOf_CurrArray, int size){
    if (sizeOf_CurrArray == size){
        allPermutations.push_back(curr);
        return;
    }
    
    for (auto i: mp){
        if (i.second <= 0) continue;
        curr.push_back(i.first); mp[i.first]--;
        backtrack(mp, curr, sizeOf_CurrArray + 1, size);
        curr.pop_back(); mp[i.first]++;
    }
    
}
// (Each method for Permutations II can be used for Permutations I)
/*
    That is another method to find permutations for the array which may contaion duplicates.
    Let's remember what is the problem related to duplicates. So, for the specific index,
    if two or more the same numbers can come, the multiple and the same realities will be generated.
    Like, we have three 1's in our main array. So in the starting, there can be permutations Like
    [1(first), ..]; [1(second), ..]; [1(third), ..]. Although these 1's are different 1's, for using
    they are completely the same and we need to prevent it. That process can happen each loop for each recursive call.
    So we need to organize the loop again and we use hash map for that.

*/

int main(){
    vector<int> nums = {1, 2, 2};
    unordered_map<int, int> mp; // num, count
    for (int i: nums) mp[i]++;
    vector<int> curr;
    int size = nums.size();
    backtrack(mp, curr, 0, size);
    for (auto i: allPermutations){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}
