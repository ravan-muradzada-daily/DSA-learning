#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& arr){
    int n = arr.size();
    if (n == 1 || arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;
    
    int left = 0, right = n - 1, mid;
    int res = 0;
    
    for (int i = 0; i < n; ++i){
        mid = (left + right) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
            res = mid; break;
        }
        
        if (arr[mid] > arr[mid - 1]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> arr = {1,2,3,1};
    
    cout << findPeakElement(arr) << endl;
    
    return 0;
}
