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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // if(root == NULL) return NULL;
        // if(root == p || root == q) return root;
        // //if(root == q)return root;

        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right= lowestCommonAncestor(root->right,p,q);
        // if(left && right)return root;
        // return left ? left:right;
        // //return root;

        // This is a BST
        if(root == NULL)return NULL;
        if(root == p || root == q) return root;

        if(max(p->val,q->val) < root->val)return lowestCommonAncestor(root->left,p,q);
        else if(min(p->val,q->val) > root->val)return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
