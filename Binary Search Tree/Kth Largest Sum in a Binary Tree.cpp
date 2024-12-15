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

long long kthLargestLevelSum(TreeNode* root, int k){
    priority_queue<long long> Sums;    
    queue<TreeNode*> q; 
    q.push(root);
    int size;
    TreeNode* node = nullptr;
    
    while (!q.empty()){
        size = q.size();
        long long sum = 0;
        for (int i = 0; i < size; ++i){
            node = q.front();
            q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        Sums.push(sum);
    }
    
    if (Sums.size() < k) return -1;
    
    for (int i = 0; i < k; ++i) Sums.pop();
    
    return Sums.top();
}

int main(){
    
    return 0;
}
