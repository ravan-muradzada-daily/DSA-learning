#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBst(ListNode* head, ListNode* tail){
    if (head == tail) return nullptr;
    
    ListNode* slow = head, *fast = head;
    
    while (fast != tail && fast->next != tail){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* node = new TreeNode(slow->val);
    
    node->left = createBst(head, slow);
    node->right = createBst(slow->next, tail);
    
    return node;
}

TreeNode* sortedListToBST(ListNode* head){
    if (!head) return nullptr;
    
    return createBst(head, nullptr);
}

int main(){
    
    return 0;
}
