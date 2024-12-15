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

pair<int, int> helper(TreeNode* node){ // [with, without]
    if (!node) return {0, 0};
    
    pair<int, int> leftSide = helper(node->left);
    pair<int, int> rightSide = helper(node->right);
    
    int with = node->val + leftSide.second + rightSide.second;
    int without = max(leftSide.first, leftSide.second) + max(rightSide.first, rightSide.second);

    return {with, without};    
}


int rob(TreeNode* root){
    if (!root) return 0;
    if (root && !root->left && !root->right) return root->val;
    
    pair<int, int> result = helper(root);
    
    return max(result.first, result.second);
}

int main(){

    return 0;
}
