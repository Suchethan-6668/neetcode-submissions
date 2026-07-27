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
    void solve(int ind,int n,vector<int> &nums,vector<int> & curr,vector<vector<int>> &ans) {
        if(ind == n){ans.push_back(nums);return;}//ans.push_back(curr);return;}
        for(int i = ind;i < n;i++) {
            //if(vis[i])continue;
            // vis[i] = 1;
            // curr.push_back(nums[i]);
            swap(nums[i],nums[ind]);
            solve(ind+1,n,nums,curr,ans);
            // curr.pop_back();
            // vis[i] = 0;
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        vector<int> curr;
        vector<int> vis(n,0);
        // solve(n,nums,vis,curr,ans);
        solve(0,n,nums,curr,ans);
        return ans;
    }
};
