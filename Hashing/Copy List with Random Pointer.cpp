#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next, *random;
    Node(int _val): val(_val), next(nullptr), random(nullptr) {}
};

Node* firstSolution(Node* head);

Node* secondSolution(Node* head);

Node* copyRandomList(Node* head){ // Major function
    if (!head) return nullptr;
    
    return secondSolution(head);
}


int main(){
    
    return 0;
}

Node* firstSolution(Node* head){
    unordered_map<Node*, Node*> mp;
    Node* node = head;
    
    while (node){
        mp[node] = new Node(node->val);
        node = node->next;
    }
    
    node = head;
    
    while (node){
        mp[node]->next = mp[node->next];
        mp[node]->random = mp[node->random];
        node = node->next;
    }
    return mp[head];
}

Node* secondSolution(Node* head){
    if (!head) return head;
    Node* temp = head, *node = nullptr;
    
    while (temp){
        node = new Node(temp->val);
        node->next = temp->next;
        temp->next = node;
        temp = temp->next->next;
    }
    temp = head;
    
    while (temp){
    if (temp->random)
        temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    node = head->next;
    Node* result = node;
    while (temp){
        if (node)
            temp->next = node->next;
        if (node->next)
            node->next = node->next->next;
        temp = temp->next;
        node = node->next;
    }
    return result;
}
