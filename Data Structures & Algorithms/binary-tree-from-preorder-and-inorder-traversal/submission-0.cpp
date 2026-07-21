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
    TreeNode* solve(int ps,int pe,int is,int ie,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp) {

        if(ps > pe || is > ie)return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        int inroot = mp[root->val];
        int left = inroot-is;
        root->left = solve(ps+1,ps+left,is,inroot-1,preorder,inorder,mp);
        root->right = solve(ps+left+1,pe,inroot+1,ie,preorder,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i = 0;i < n;i++) {
            mp[inorder[i]] = i;
        }
        return solve(0,n-1,0,n-1,preorder,inorder,mp);
        
    }
};
