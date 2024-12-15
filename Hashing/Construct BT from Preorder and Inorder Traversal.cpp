// According to preorder and inorder traversal arrays, construct binary tree.
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

class TreeNode{
public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data): left(nullptr), right(nullptr), data(data){}
};

TreeNode* recur(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    int Root_In = mp[preorder[preStart]];
    int nums_In_Left = Root_In - inStart;
    
    root->left = recur(preorder, preStart + 1, preStart + nums_In_Left, inorder, inStart, Root_In - 1);
    root->right = recur(preorder, preStart + nums_In_Left + 1, preEnd, inorder, Root_In + 1, inEnd);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    int n = inorder.size();
    
    for (int i = 0; i < n; ++i) mp[inorder[i]] = i;
    
    TreeNode* root = recur(preorder, 0, n - 1, inorder, 0, n - 1);
    return root;
}

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder);
    // It is possible to write some code for checking it..
    
    return 0;
}
