#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums){
    int low = 0, mid = 0, end = nums.size()-1;
    
    while (mid <= end){
        switch (nums[mid]){
            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            default:
                swap(nums[mid], nums[end]);
                end--;
        }
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    
    for (int i: nums) cout << i << " ";
    
    return 0;
}
