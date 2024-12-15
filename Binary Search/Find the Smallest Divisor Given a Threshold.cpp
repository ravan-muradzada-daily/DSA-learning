#include <bits/stdc++.h>
using namespace std;


int sumDivisors(vector<int>& nums, int currDivisor, int threshold){
    int res = 0;
    
    for (int i = 0; i < nums.size(); ++i){
        if (res > threshold) break;
        res += ceil((double) nums[i] / (double) currDivisor);
    }
    
    return res;
}

int smallestDivisor(vector<int>& nums, int threshold){
    int n = nums.size();
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int mid, currSum, res;
    
    while (left <= right){
        mid = (left + right) / 2;
        currSum = sumDivisors(nums, mid, threshold);
        
        if (currSum <= threshold){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;
    
    cout << smallestDivisor(nums, threshold) << endl;
    
    
    return 0;
}
