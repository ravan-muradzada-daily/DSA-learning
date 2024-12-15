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

int currSum = 0;

TreeNode* convertBST(TreeNode* root){
    if (root){
        convertBST(root->right);
        currSum += root->val;
        root->val = currSum;
        convertBST(root->left);
    }
    
    return root;
}

int main(){

    return 0;
}
