#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums){
    int n = nums.size();
    
    int elements[2] = {0}, counts[2] = {0};
    
    for (int i = 0; i < n; ++i){
        if (counts[0] == 0 && nums[i] != elements[1]){
            elements[0] = nums[i]; counts[0] = 1;    
        }else if (counts[1] == 0 && nums[i] != elements[0]){
            elements[1] = nums[i]; counts[1] = 1;
        }else if (elements[0] == nums[i]){
            counts[0]++;
        }else if (elements[1] == nums[i]){
            counts[1]++;
        }else{
            elements[0]--;
            elements[1]--;
        }
    }
    int x = n / 3;
    counts[0] = counts[1] = 0;
    vector<int> Result(2);
    for (int i = 0; i < n; ++i){
        if (elements[0] == nums[i]) counts[0]++;
        else if (elements[1] == nums[i]) counts[1]++;
    }
    if (counts[0] > x) Result[0] = elements[0];
    if (counts[1] > x) Result[1] = elements[1];
    return Result;
}

int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    auto result = majorityElement(nums);
    
    for (int i: result) cout << i << " ";
    
    return 0;
}
