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
    int maxH(TreeNode* root,bool &res) {
        if(root == NULL) return 0;

        int left = maxH(root->left,res);
        int right = maxH(root->right,res);
        res = res&&(abs(left-right) <= 1);
        return max(1+left,1+right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool res = true;
        int yo = maxH(root,res);
        return res;
    }
};
