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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        // int temp = root->left->val;
        // root->left->val = root->right->val;
        // root->right->val = temp;
        swap(root->left,root->right);
        TreeNode* leftI = invertTree(root->left);
        TreeNode* rightI = invertTree(root->right);
        
        return root;
    }
};
