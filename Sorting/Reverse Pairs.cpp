#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int high, int mid){
    int left = low, right = mid + 1, k = 0;
    vector<int> temp(high-low+1);
        
    while (left <= mid && right <= high){
        if (nums[left] <= nums[right]){
            temp[k++] = nums[left++];
        }else{
            temp[k++] = nums[right++];
        }
    }

    while (left <= mid) temp[k++] = nums[left++];
    while (right <= high) temp[k++] = nums[right++];

    for (int i = low; i <= high; ++i){
        nums[i] = temp[i-low];
    }
}

int countPairs(vector<int>& nums, int low, int high, int mid){
    int j = mid + 1;
    int count = 0;
    
    for (int i = low; i <= mid; ++i){
        while (j <= high && nums[i] > (long long) 2 * nums[j]){
            j++;
        }
        
        count += (j - (mid + 1));
    }
    
    return count;
}

int mergeSort(vector<int>& nums, int low, int high){
    if (low >= high) return 0;
    
    int mid = (low + high) / 2, count = 0;
    
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, high, mid);
    merge(nums, low, high, mid);
    
    return count;
}


int reversePairs(vector<int>& nums){
    int n = nums.size();
    int result = mergeSort(nums, 0, n - 1);
    
    return result;
}

int main(){
    vector<int> nums = {2,4,3,5,1};
    
    cout << reversePairs(nums) << endl;
    
    return 0;
}
