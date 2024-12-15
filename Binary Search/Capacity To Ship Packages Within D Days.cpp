#include <bits/stdc++.h>
using namespace std;

void findMinMax(vector<int>& nums, int& left, int& right){
    left = nums[0];
    right = 0;
    for (int i = 0; i < nums.size(); ++i){
        left = max(left, nums[i]);
        right += nums[i];
    }
}

bool isPossible(vector<int>& nums, int days, int cap){
    int curDay = 0, curWeight = 0;
    
    for (int i = 0; i < nums.size(); ++i){
        if (curDay > days || nums[i] > cap)
            return false;
        if (curWeight + nums[i] > cap){
            curDay++;
            curWeight = nums[i];
        }else{
            curWeight += nums[i];
        }
    }
    
    if (curWeight > 0) curDay++;
    
    return curDay <= days;
}


int shipWithinDays(vector<int>& weights, int days){
    int n = weights.size();
    int left, right, mid, res;
    findMinMax(weights, left, right);
    
    while (left <= right){
        mid = (left + right) / 2;
        
        if (isPossible(weights, days, mid)){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    
    cout << shipWithinDays(weights, days) << endl;
    
    
    return 0;
}
