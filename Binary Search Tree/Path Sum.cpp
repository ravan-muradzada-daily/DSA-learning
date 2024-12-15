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

bool helper(TreeNode* root, int target, int sum){
    if (!root) return false;
    sum += root->val;

    if (!root->left && !root->right){
        if (target == sum) return true;
        return false;
    }

    return helper(root->left, target, sum) || helper(root->right, target, sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return helper(root, targetSum, 0);        
}

int main(){
    
    return 0;
}
