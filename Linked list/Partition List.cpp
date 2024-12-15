#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x){
    if (!head) return head;
    ListNode* leftHead = new ListNode(0), *rightHead = new ListNode(0);
    ListNode* left = leftHead, *right = rightHead;
    
    while (head){
        if (head->val < x){
            left->next = head;
            left = left->next;
        }else{
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }
    left->next = rightHead->next;
    right->next = nullptr;
    return leftHead->next;
}

int main(){
    
    return 0;
}
