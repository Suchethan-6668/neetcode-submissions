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
    int maxD(TreeNode* root,int &dia) {

        if(root == NULL)return 0;

        int left = maxD(root->left,dia);
        int right = maxD(root->right,dia);
        dia = max(dia,left+right);
        return max(1+left,1+right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int dia = 0;

        int maxH =  maxD(root,dia);
        return dia;
    }
};
