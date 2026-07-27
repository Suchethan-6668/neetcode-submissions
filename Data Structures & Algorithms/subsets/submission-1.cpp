class Solution {
public:
    void solve(int ind,int n,vector<int> & nums,vector<vector<int>> & ans,vector<int> &prev) {
        if(ind == n) {
            ans.push_back(prev);
            return;
        }

        solve(ind +1 ,n,nums,ans,prev);
        prev.push_back(nums[ind]);
    
        
        solve(ind+1,n,nums,ans,prev);
        prev.pop_back();//impp  backtracking step
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> prev;

        solve(0,n,nums,ans,prev);
        return ans;

    }
};
