#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    bool one_present = false;

    for (int i = 0; i < n; ++i){
        if (nums[i] == 1) one_present = true;
        if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
    }

    if (!one_present) return 1;

    for (int i = 0; i < n; ++i){
        int ind = abs(nums[i]);
        if (nums[ind-1] > 0){
            nums[ind-1] = -nums[ind-1];
        }
    }

    for (int i = 0; i < n; ++i){
        if (nums[i] > 0){
            return i+1;
        }
    }

    return n+1;
}

int main(){
    vector<int> nums = {100000, 3, 4000, 2, 15, 1, 99999};

    int result = firstMissingPositive(nums);

    cout << result << endl;
}