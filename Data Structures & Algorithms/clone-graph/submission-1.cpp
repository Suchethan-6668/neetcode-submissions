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
        if(node == NULL)return NULL;
        unordered_map<Node*,Node*> vis;

        queue<Node*> q;
       
        q.push(node);
        vis[node] =  new Node(node->val);

        while(!q.empty()) {
            Node* tc = q.front();
            q.pop();

            for(auto nei: tc->neighbors) {
                if(!vis.count(nei)) {
                    vis[nei] = new Node(nei->val);
                    q.push(nei);
                }
                vis[tc]->neighbors.push_back(vis[nei]);
            }
        }
        //return clonedfs(node,vis);
        return vis[node];
    }
};
