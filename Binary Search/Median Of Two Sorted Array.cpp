#include <bits/stdc++.h>
using namespace std;

double solution_1(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    vector<int> arr(n);
    
    for (int i = 0; i < n1; ++i){
        arr[i] = arr1[i];
    }
    
    for (int i = n1; i < n; ++i){
        arr[i] = arr2[i-n1];
    }

    sort(arr.begin(), arr.end());
    if (n % 2 == 1) return arr[n/2];
    
    return (double)(arr[n/2] + arr[(n/2)-1]) / 2.0;
}

double solution_2(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    vector<int> arr(n);
    
    int left = 0, right = 0, ptr = 0;
    
    while (left < n1 && right < n2){
        if (arr1[left] > arr2[right]){
            arr[ptr++] = arr2[right++]; 
        }else{
            arr[ptr++] = arr1[left++];
        }
    }
    
    while (left < n1) arr[ptr++] = arr1[left++];
    while (right < n2) arr[ptr++] = arr2[right++];

    if (n % 2 == 1) return arr[n/2];
    
    return (double)(arr[n/2] + arr[(n/2)-1]) / 2.0;
}

double solution_3(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    
    int leftPtr = 0, rightPtr = 0, cnt = 0;
    int mid1 = (n/2)-1, mid2 = n/2;
    int ind1 = -1, ind2 = -1;
    
    
    while (leftPtr < n1 && rightPtr < n2){
        if (arr1[leftPtr] > arr2[rightPtr]){
            if (cnt == mid1) ind1 = arr2[rightPtr];
            if (cnt == mid2) ind2 = arr2[rightPtr];
            rightPtr++;
        }else{
            if (cnt == mid1) ind1 = arr1[leftPtr];
            if (cnt == mid2) ind2 = arr1[leftPtr];
            leftPtr++;
        }
        cnt++;
    }
    
    while (leftPtr < n1){
        if (cnt == mid1) ind1 = arr1[leftPtr];
        if (cnt == mid2) ind2 = arr1[leftPtr];
        cnt++; leftPtr++;
    }
    
    while (rightPtr < n2){
        if (cnt == mid1) ind1 = arr2[rightPtr];
        if (cnt == mid2) ind2 = arr2[rightPtr];
        cnt++; rightPtr++;
    }
    
    if (n % 2 == 1) return ind2;
    
    return (double)(ind1 + ind2) / 2.0;
}

double solution_4(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2) return solution_4(arr2, arr1);
    
    int n = n1 + n2;
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int l1, l2, r1, r2;
    
    while (low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        l1 = l2 = INT_MIN;
        r1 = r2 = INT_MAX;
        
        if (mid1 < n1) r1 = arr1[mid1];
        if (mid2 < n2) r2 = arr2[mid2];
        
        if (mid1 - 1 >= 0) l1 = arr1[mid1-1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2-1];
        
        if (l1 <= r2 && l2 <= r1){
            break;
        }else if (l1 > r2){
            high = mid1 - 1;
        }else{
            low = mid1 + 1;
        }
    }
    
    return (n % 2 == 1)? (max(l1, l2)): ((double)(max(l1,l2)+min(r1, r2))/2.0);
}

int main(){
    vector<int> arr1 = {1, 3, 7, 11}, arr2 = {2, 4, 9};
    int res1 = solution_1(arr1, arr2);
    cout << res1 << "\n\n";

    int res2 = solution_2(arr1, arr2);
    cout << res2 << "\n\n";
    
    int res3 = solution_3(arr1, arr2);
    cout << res3 << "\n\n";
    
    int res4 = solution_4(arr1, arr2);
    cout << res4 << "\n\n";
    
    return 0;
}
