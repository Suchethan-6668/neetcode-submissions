class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
        for(int i = 0;i <= n;i++) {
            dp[i][0] = 0;
        }

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= amount;j++) {
                int take = 1e9;
                if(j >= coins[i-1]) {take = 1+dp[i][j-coins[i-1]];}
                dp[i][j] = min(dp[i-1][j] ,take);
            }
        }

        return dp[n][amount]!= 1e9?dp[n][amount]:-1;
    }
};
