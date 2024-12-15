#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

class TreeNode{
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int val): left(nullptr), right(nullptr), val(val){}    
};

TreeNode* recur(vector<int>& inorder, int InSt, int InEnd, vector<int>& postorder,int PSt, int PEnd){
    if (InSt > InEnd || PSt > PEnd) return nullptr;
        
    TreeNode* root = new TreeNode(postorder[PEnd]);
    int Root_In = mp[root->val];
    int numsLeft = Root_In - InSt;
        
    root->left = recur(inorder, InSt, Root_In - 1, postorder,
    PSt, PSt + numsLeft - 1);
    root->right = recur(inorder, Root_In + 1, InEnd, postorder,
    PSt + numsLeft, PEnd - 1);
        
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    int n = inorder.size();
    for (int i = 0; i < n; ++i) mp[inorder[i]] = i;
    
    TreeNode* root = recur(inorder, 0, n - 1, postorder,
    0, n - 1);
    return root;
}

int main(){
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    buildTree(inorder, postorder);
    // It is possible to write code to check functions
    
    return 0;
}
