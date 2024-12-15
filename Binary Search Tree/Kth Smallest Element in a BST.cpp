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

void InOrder_helper(TreeNode* root, int& k, int& result){
    if (!root) return;
    
    InOrder_helper(root->left, k, result);
    k--;
    if (k == 0){
        result = root->val; return;
    }
    InOrder_helper(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k){
    int result;
    InOrder_helper(root, k, result);
    
    return result;
}

int main(){
    
    return 0;
}
