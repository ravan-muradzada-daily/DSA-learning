#include <bits/stdc++.h>
using namespace std;
    
void findMinMax(vector<int>& nums, int& left, int& right){
    left = right = nums[0];

    for (int i = 1; i < nums.size(); ++i){
        left = max(left, nums[i]);
        right += nums[i];
    }
}

bool determine(vector<int>& nums, int m, int mid){
    int count = 1, sum = 0;

    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] > mid) return false;
        if (sum + nums[i] > mid){
            count++;
            sum = 0;
        }
        sum += nums[i];
    }

    return (m >= count); 
}

int findPages(vector<int>& arr, int m){
    int n = arr.size();
    if (m > n) return -1;
    int left, right;
    findMinMax(arr, left, right);
    int res = -1, mid;

    while (left <= right){
        mid = (left + right) / 2;

        if (determine(arr, m, mid)){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    
    cout << findPages(nums, m) << endl;
    
    return 0;
}
