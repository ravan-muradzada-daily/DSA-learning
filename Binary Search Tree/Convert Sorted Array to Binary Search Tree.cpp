#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int>& nums, int left, int right){
    if (left > right) return nullptr;
    
    int mid = (left + right) / 2;
    
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid-1);
    root->right = helper(nums, mid+1, right);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    int n = nums.size();
    
    TreeNode* root = helper(nums, 0, n-1);
    
    return root;
}

int main(){

    return 0;
}
