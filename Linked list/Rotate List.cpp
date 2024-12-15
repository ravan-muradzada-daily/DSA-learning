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

ListNode* rotateRight(ListNode* head, int k){
    if (!head || k == 0) return head;
    ListNode* counter = head, *tail = head;
    int n = 0;
    
    while (counter){
        if (counter->next) tail = tail->next;
        counter = counter->next;
        n++;
    }
    
    k = k % n;
    if (k == 0) return head;
    
    ListNode* ptr = head;
    
    for (int i = 0; i < (n - k - 1); ++i){
        ptr = ptr->next;
    }
    
    tail->next = head;
    head = ptr->next;
    ptr->next = nullptr;
    return head;
}

int main(){
    
    return 0;
}
