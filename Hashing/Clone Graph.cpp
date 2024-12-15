// Given a reference of a node in a connected undirected graph. 
// Return a deep copy (clone) of the graph.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(): val(0), neighbors(vector<Node*>())  {}
    Node(int _val): val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors): val(_val), neighbors(_neighbors)  {}
};

unordered_map<Node*, Node*> alreadyCloned;

Node* cloneDFS(Node* node);
Node* cloneBFS(Node* node);

Node* cloneGraph(Node* node) { // The major function
    if (!node) return nullptr;
    return cloneDFS(node);
}


int main(){
    // Some code to check...
    return 0;
}

Node* cloneDFS(Node* node){
    if (alreadyCloned.find(node) != alreadyCloned.end()) return alreadyCloned[node];
    
    Node* copy = new Node(node->val);
    alreadyCloned[node] = copy;
    
    for (Node* neig: node->neighbors){
        copy->neighbors.push_back(cloneDFS(neig));
    }
    return copy;
}
Node* cloneBFS(Node* node){
    queue<Node*> q;
    q.push(node);
    alreadyCloned[node] = new Node(node->val);
    
    while (!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        for (Node* neig: curr->neighbors){
            if (alreadyCloned.find(neig) == alreadyCloned.end()){
                alreadyCloned[neig] = new Node(neig->val);
                q.push(neig);
            }
            alreadyCloned[curr]->neighbors.push_back(alreadyCloned[neig]);
        }
    }
    return alreadyCloned[node];
}
