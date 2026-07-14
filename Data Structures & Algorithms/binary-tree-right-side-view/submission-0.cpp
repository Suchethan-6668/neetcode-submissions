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
    void solve(TreeNode* root,vector<int> &ans,int lcnt) {
        if(root == NULL) return;

        if(ans.size() == lcnt) ans.push_back(root->val);
        if(root->right)solve(root->right,ans,lcnt+1);
        solve(root->left,ans,lcnt+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;//one per level
        solve(root,ans,0);
        return ans;
    }
};
