#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int target){
    int n = arr.size();
    int left = 0, right = n - 1, mid;
    
    while (left <= right){
        mid = (left + right) / 2;
        
        if (arr[mid] == target) return true;
        
        if (arr[mid] == arr[left] && arr[mid] == arr[right]){
            left++;
            right--;
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
    
    return false;
}

int main(){
    vector<int> arr = {2,5,6,0,0,1,2};
    int target = 0;
    
    cout << boolalpha << search(arr, target);
    
    
    return 0;
}
