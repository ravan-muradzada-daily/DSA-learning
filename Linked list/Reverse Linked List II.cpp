#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    ListNode* next;
    int val;
    ListNode(): next(nullptr), val(0){}
    ListNode(int val): next(nullptr), val(val) {}
};

class List{
public:
    ListNode* head, *tail;
    List(){
        head = nullptr; tail = nullptr;
    }
    
    void append(int val){
        if (!head){
            head = new ListNode(val);
            tail = head;
        }else{
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    void print(){
        ListNode* temp = head;
        while (temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

ListNode* reverseBetween(ListNode* head, int left, int right){
    if (!head || !head->next) return head;
    ListNode* dummyNode = new ListNode(0), *curr = head, *before = nullptr;
    dummyNode->next = head;
    before = dummyNode;
    
    for (int i = 0; i < (left - 1); ++i){
        before = before->next;
        curr = curr->next;
    }
    ListNode* start = curr;
    ListNode* prev = nullptr, *after = nullptr;
    
    for (int i = 0; i < (right - left + 1); ++i){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    before->next = prev;
    start->next = curr;
    
    return dummyNode->next;
}

int main(){
    int arr[] = {4, 1, 2, 6, 12, 8};
    int left = 2, right = 4;
    List l;
    for (int i: arr) l.append(i);
    l.print();
    reverseBetween(l.head, left, right);
    l.print();
    
    return 0;
}
