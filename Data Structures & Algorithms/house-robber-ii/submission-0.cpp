class Solution {
public:
    int solve(vector<int> &nums,int s,int e) {
        int n = e-s+1;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[s];
        for(int i = 2;i <= n;i++) {
            dp[i] = max(dp[i-1] , nums[s+i-1]+ dp[i-2]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
