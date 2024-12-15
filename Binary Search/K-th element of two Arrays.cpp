#include <bits/stdc++.h>
using namespace std;

int kthElement(int k, vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    
    if (n1 > n2) return kthElement(k, arr2, arr1);
    
    int leftPart = k;
    
    int minTake = max(0, k - n2), maxTake = min(k, n1);
    int l1, l2, r1, r2;
    
    while (minTake <= maxTake){
        int mid1 = (minTake + maxTake) / 2;
        int mid2 = leftPart - mid1;
        
        l1 = l2 = INT_MIN;
        r1 = r2 = INT_MAX;
        
        if (mid1 > 0) l1 = arr1[mid1 - 1];
        if (mid2 > 0) l2 = arr2[mid2 - 1];
        
        if (mid1 < n1) r1 = arr1[mid1];
        if (mid2 < n2) r2 = arr2[mid2];
        
        if (r1 >= l2 && r2 >= l1){
            break;
        }else if (l1 > r2){
            maxTake = mid1 - 1;
        }else{
            minTake = mid1 + 1;
        }
    }
    
    return max(l1, l2);
}

int main(){
    vector<int> arr1 = {100, 112, 256, 349, 770}, 
                arr2 = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    
    cout << kthElement(k, arr1, arr2) << endl;
    
    return 0;
}
