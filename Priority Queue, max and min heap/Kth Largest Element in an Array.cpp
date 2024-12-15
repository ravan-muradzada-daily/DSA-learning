#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k){
    priority_queue<int> pq;
    
    for (int i: nums){
        pq.push(i);
    }
    
    for (int i = 0; i < k-1; ++i){
        pq.pop();
    }
    
    return pq.top();
}

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    cout << findKthLargest(nums, k) << endl;
    
    return 0;
}
