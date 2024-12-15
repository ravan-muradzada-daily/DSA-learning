#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, mid;
    while (left <= right){
        mid = left + (right - left)/2;
        if (arr[mid] == target) return mid;
        if (arr[right] >= arr[left]){
            if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }else if (arr[mid] >= arr[left]){
            if (target >= arr[left] && target <= arr[mid]){
                right = mid - 1;
            }else left = mid + 1;
        }else{
            if (target >= arr[mid] && target <= arr[right]){
                left = mid + 1;
            }else right = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    
    cout << search(arr, target);
    
    
    return 0;
}
