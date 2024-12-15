#include <bits/stdc++.h>
using namespace std;

int HouseRobber(vector<int>& nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    
    nums[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i){
        nums[i] = max(nums[i] + nums[i-2], nums[i-1]);
    }
    
    return nums[n-1];
}

int main(){
    vector<int> nums = {1, 2, 9, 8, 7};
    
    cout << HouseRobber(nums) << endl;
    
    return 0;
}
