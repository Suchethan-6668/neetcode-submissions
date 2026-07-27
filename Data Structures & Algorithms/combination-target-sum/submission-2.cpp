class Solution {
public:
    void solve(int ind,int n,vector<int> &nums,int sum,vector<int> & curr,int target,vector<vector<int>> &ans) {
        if(ind == n) {
            if(sum == target) {
                ans.push_back(curr);
            }
            return;
        }
        solve(ind+1,n,nums,sum,curr,target,ans);
        if(sum + nums[ind] <= target) {
            curr.push_back(nums[ind]);
            //sum += nums[ind];
            solve(ind,n,nums,sum+nums[ind],curr,target,ans);
            //sum -= nums[ind];
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        int n = nums.size();
        solve(0,n,nums,sum,curr,target,ans);
        return ans;
    }
};
