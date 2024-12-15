#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int low, int high, int mid){
  int left = low, right = mid + 1, k = 0;
  vector<int> temp (high - low + 1);
  int count = 0;
  
  while (left <= mid && right <= high){
    if (nums[left] <= nums[right]){
      temp[k++] = nums[left++];
    }else{
      temp[k++] = nums[right++];
      count += (mid - left + 1);
    }
  }
  
  while (left <= mid) temp[k++] = nums[left++];
  while (right <= high) temp[k++] = nums[right++];
  
  for (int i = low; i <= high; ++i){
    nums[i] = temp[i-low];
  }
  
  return count;
}


int mergeSort(vector<int>& nums, int low, int high){
  if (low >= high) return 0;
  int count = 0;
  int mid = (low + high) / 2;
  count += mergeSort(nums, low, mid);
  count += mergeSort(nums, mid + 1, high);
  count += merge(nums, low, high, mid);
  
  return count;
}

int numberOfInversions(vector<int>& nums){
  int n = nums.size();
  return mergeSort(nums, 0, n-1);
}



int main(){
  vector<int> nums = {5, 3, 2, 1, 4};
  
  cout << numberOfInversions(nums);
    
    return 0;
}
