/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        string s = "";
        

        while(!q.empty()) {
            
            TreeNode* temp = q.front();
            if(temp == NULL) {s += "# ";q.pop();}
            else {
                s += to_string(temp->val)+ " ";
                q.pop();

                
                q.push(temp->left);
            
            
                q.push(temp->right);
            }
            
            
            
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
        
        stringstream ss(data);
        string val;

        ss >> val;
        if(val == "#")return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(ss >> val) {
                if(val != "#") {
                    temp->left = new TreeNode(stoi(val));
                    q.push(temp->left);
                }
            }
            if(ss >> val) {
                if(val != "#") {
                    temp->right = new TreeNode(stoi(val));
                    q.push(temp->right);
                }
            }
        }

        return root;

    }
};
