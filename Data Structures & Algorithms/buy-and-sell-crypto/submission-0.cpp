class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxi = 0;

        int j = 0;
        for(int i = 1;i < n;i++) {
            if(prices[i] < prices[j]) {
                j = i;
            } else {
                maxi = max(maxi , (prices[i]-prices[j]));
            }
        }
        return maxi;
    }
};
