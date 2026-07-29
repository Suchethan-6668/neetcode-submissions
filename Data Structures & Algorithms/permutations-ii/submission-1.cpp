class Solution {
public:

    void solve(int ind,int n,vector<int> &nums,vector<int> &vis,vector<int> &curr,vector<vector<int>> &ans) {
        if(n == curr.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i = 0;i < n;i++) {
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1]))continue;
            //You are only allowed to pick $1_b$ if $1_a$ has ALREADY been picked in the current path.
            vis[i] = 1;
            curr.push_back(nums[i]);
            solve(ind+1,n,nums,vis,curr,ans);
            curr.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        int n = nums.size();
        vector<int> vis(n,0);
        sort(nums.begin(),nums.end());
        solve(0,n,nums,vis,curr,ans);
        return ans;

    }
};