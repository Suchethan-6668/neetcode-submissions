class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));

        

        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]);
                if(dp[i][j] == INT_MAX)dp[i][j] = grid[i-1][j-1];
                else dp[i][j] += grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};