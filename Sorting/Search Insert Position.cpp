#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target){
  int n = nums.size();
  int left = 0, right = n - 1, mid;
  
  while (left <= right){
    mid = (left + right) / 2;
    if (nums[mid] == target) return mid;
    
    if (nums[mid] > target)
      right = mid - 1;
    else left = mid + 1;
  }
  
  return left;
}


int main(){
  vector<int> nums = {1,3,5,6};
  int target = 2;
  
  cout << searchInsert(nums, target) << endl;
  
  return 0;
}
