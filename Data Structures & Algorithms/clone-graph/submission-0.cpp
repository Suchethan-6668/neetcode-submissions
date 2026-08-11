/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clonedfs(Node* node,unordered_map<Node*,Node*> &vis) {
        if(node == NULL)return NULL;


        if(vis.count(node))return vis[node];

        Node* clone = new Node(node->val);
        vis[node] = clone;
        for(auto neigh: node->neighbors) {
            clone->neighbors.push_back(clonedfs(neigh,vis));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        
        unordered_map<Node*,Node*> vis;


        return clonedfs(node,vis);
    }
};
