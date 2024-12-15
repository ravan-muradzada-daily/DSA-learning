#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCombinations;

void backtrack1(vector<int>& nums, vector<int>& curr, int target, int indx){
    if (target <= 0){
        if (target == 0)
            allCombinations.push_back(curr);
        return;
    }


    for (int i = indx; i < nums.size(); ++i){
        if (i > 0 && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        backtrack1(nums, curr, target-nums[i], i);
        curr.pop_back();
    }
}

void backtrack2(vector<int>& nums, vector<int>& curr, int target, int indx){
    if (target <= 0){
        if (target == 0){
            allCombinations.push_back(curr);
        }
        return;
    }

    for (int i = indx; i < nums.size(); ++i){
       // if (i > 0 && nums[i] == nums[i-1]) continue;

        curr.push_back(nums[i]);
        backtrack2(nums, curr, target-nums[i], i+1);
        curr.pop_back();
    }
}

int main(){
    vector<int> nums = {1, 2, 4, 5, 1, 6};
    //sort(nums.begin(), nums.end());
    int target = 7;
    vector<int> curr;
    backtrack2(nums, curr, target, 0);

    for (auto& i: allCombinations){
        for (int j: i){
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}