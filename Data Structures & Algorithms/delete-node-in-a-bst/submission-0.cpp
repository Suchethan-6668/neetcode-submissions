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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* mini = root->right;
            while(mini->left) {
                mini = mini->left;
            }
            root->val = mini->val;
            root->right = deleteNode(root->right,mini->val);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left,key);
        }else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};