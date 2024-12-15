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

long curr = LONG_MIN;
bool isCorrect = true;
void inOrderHelper(TreeNode* root){
    if (!root) return;
    
    inOrderHelper(root->left);
    if (curr >= root->val){
        isCorrect = false; return;
    }
    curr = root->val;
    inOrderHelper(root->right);
}

bool isValidBST(TreeNode* root){
    inOrderHelper(root);
    return isCorrect;
}


int main(){

    return 0;
}
