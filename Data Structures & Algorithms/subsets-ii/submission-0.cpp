class Solution {
public:
    void solve(int ind,int n,vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans) {
       
            ans.push_back(curr);
            

        for(int i = ind;i < n;i++) {
            if(i > ind && nums[i] == nums[i-1])continue;
            curr.push_back(nums[i]);
            solve(i+1,n,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> curr;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        solve(0,n,nums,curr,ans);
        return ans;


    }
};
