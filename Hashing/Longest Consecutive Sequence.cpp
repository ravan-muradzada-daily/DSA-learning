#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    if (n <= 1) return n;
    
    unordered_set<int> st;
    int size = 1, maxSize = INT_MIN;
    for (int i = 0; i < n; ++i) st.insert(nums[i]);
    
    for (int i: st){
        if (st.find(i - 1) == st.end()){
            int startingNum = i;
            size = 1;
            while (st.find(startingNum + 1) != st.end()){
                startingNum++; size++;
            }
        }
        maxSize = max(maxSize, size);
    }
    return maxSize;
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    int maxSize = longestConsecutive(nums);
    
    cout << maxSize;
    
    return 0;
}
