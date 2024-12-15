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

unordered_set<int> st;

bool findTarget(TreeNode* root, int k){
    if (!root) return false;
    
    if (findTarget(root->left, k)){
        return true;
    }
    
    int val = root->val;
    
    if (st.find(k-val) != st.end()){
        return true;
    }
    st.insert(val);
    
    if (findTarget(root->right, k)){
        return true;
    }
    
    return false;
}

int main(){

    return 0;
}
