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
    void solve(TreeNode* root,int &cnt,int pmaxi) {
        if(root == NULL) return;
        if(root->val >= pmaxi) {
            cnt++;
            pmaxi = root->val;
        }
        solve(root->right,cnt,pmaxi);
        solve(root->left,cnt,pmaxi);

       
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;

        int cnt = 0;
        solve(root,cnt,INT_MIN);
        return cnt;
        
    }
};
