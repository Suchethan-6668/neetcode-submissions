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
    bool solve(TreeNode* root,int &k,int &ans) {
        if(root == NULL)return false;

        
        if(solve(root->left,k,ans))return true;
        
        k--;
        if(k == 0) {
            ans = root->val;
            return true;
        }

        return solve(root->right,k,ans);
    }
    //changing void solve to bool reduces the time complexity
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root,k,ans);
        return ans;
        
    }
};
