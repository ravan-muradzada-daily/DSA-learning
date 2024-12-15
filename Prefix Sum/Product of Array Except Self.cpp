#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size(), curr;
    vector<int> res(n, 1);
    
    curr = 1;
    
    for (int i = 0; i < n; ++i){
        res[i] *= curr;
        curr *= nums[i];
    }
    
    curr = 1;
    
    for (int i = n-1; i >= 0; --i){
        res[i] *= curr;
        curr *= nums[i];
    }
    
    return res;
}

/*
    We should use the prefix product and suffix product to solve this problem.
    So, the result for each index is equal to the product of prefix product up to this index (except self)
    and product of suffix product up to this index (except self).
    So, we can express the equality like that: result[i] = prefixPr[i-1] * suffixPr[i+1].
    We can handle this problem without creating two arrays like in the code spinnet.
*/
int main(){
    vector<int> nums = {1, 2, 3, 4};
    
    auto result = productExceptSelf(nums);
    
    for (int i: result){
        cout << i << " ";
    }
    
    return 0;
}
