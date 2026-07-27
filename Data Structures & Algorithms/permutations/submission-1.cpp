class Solution {
public:
    void solve(int n,vector<int> &nums,vector<int> &vis,vector<int> & curr,vector<vector<int>> &ans) {
        if(n == curr.size()){ans.push_back(curr);return;}
        for(int i = 0;i < n;i++) {
            if(vis[i])continue;
            vis[i] = 1;
            curr.push_back(nums[i]);
            solve(n,nums,vis,curr,ans);
            curr.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        vector<int> curr;
        vector<int> vis(n,0);
        solve(n,nums,vis,curr,ans);
        return ans;
    }
};
