#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k){
    int n = nums.size();
    int sum = 0, maxSum = INT_MIN, left = 0;
    
    for (int right = 0; right < n; ++right){
        sum += nums[right];
        if (right >= (k-1)){
            maxSum = max(maxSum, sum);
            sum -= nums[left++];
        }
    }
    
    return (double)maxSum / k;
}

int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    
    cout << findMaxAverage(nums, k) << endl;
    
    return 0;
}
