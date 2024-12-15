#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k){
    long n = nums.size(), sum, result, left;
    sum = result = left = 0;
    
    for (int right = 0; right < n; ++right){
        sum += nums[right];
        
        while (((right - left + 1) * nums[right]) > (sum + k)) sum -= nums[left++];
        result = max(result, right - left + 1);
    }
    
    return result;
}

/*
    We try to find out more proper solution up to the current index.
    So if the number in the current index is 4. That refers, from the beginning, we
    need to figure out whether we can flip all nums to 4. If not, we just slide it to right.
*/

int main(){
    vector<int> nums = {1,4,8,13};
    int k = 5;
    
    cout << maxFrequency(nums, k) << endl;
    
    return 0;
}
