#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1, mid;
    int lPart;
    int res;
    while (left <= right){
        mid = (left + right) / 2;

        if (mid != n-1 && nums[mid] == nums[mid + 1]){
            lPart = mid - left;
        }else if (mid != 0 && nums[mid] == nums[mid - 1]){
            lPart = mid - 1 - left;
        }else{
            res = nums[mid];
        }

        if (lPart % 2 == 1){
            if (mid != 0 && nums[mid] == nums[mid - 1]){
                right = mid - 2;
            }else{
                right = mid - 1;
            }
        }else{
            if (mid != n-1 && nums[mid] == nums[mid + 1]){
                left = mid + 2;
            }else{
                left = mid + 1;
            }
        }
    }

    return res;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    
    cout << singleNonDuplicate(nums) << endl;
    
    
    return 0;
}
