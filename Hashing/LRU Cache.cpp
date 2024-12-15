#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val, key;
    Node* next, *prev;
    Node(): val(0), next(nullptr), prev(nullptr) {}
    Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int cap, len;
    Node* head, *tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        this->cap = capacity; this->len = 0;
        head = new Node(); tail = new Node();
        head->next = tail; tail->prev = head;
    }
    
    void addNode(int key, int val){
        Node* temp = head->next;
        Node* n = new Node(key, val);
        head->next = n; n->prev = head;
        n->next = temp; temp->prev = n;
        mp[key] = n; len++;
    }
    void deleteNode(int key){
        Node* temp = (mp[key])->prev;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        mp.erase(key); len--;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        int val = (mp[key])->val;
        deleteNode(key);
        addNode(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            deleteNode(key);
            addNode(key, value);
        }else{
            if (len >= cap){
                deleteNode(tail->prev->key);
            }
            addNode(key, value);
        }
    }
};

int main(){
    
    return 0;
}
