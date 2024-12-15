#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int start, int end){
    int a = 0, b = 0, temp;
    
    for (int i = start; i < end; ++i){
        temp = max(a + nums[i], b);
        a = b;
        b = temp;
    }
    
    return b;
}
/*
    We just use similar logic to the HouseRobber 1 here. Only we divide it two parts and 
    compare them.
*/
int HouseRobber(vector<int>& nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    
    return max(helper(nums, 1, n), helper(nums, 0, n-1));
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    
    cout << HouseRobber(nums);
    
    return 0;
}
