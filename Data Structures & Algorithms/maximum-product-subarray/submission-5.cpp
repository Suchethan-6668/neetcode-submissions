class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxi = 1;
        int mini = 1;
        for(int &k: nums) {
            // if(k == 0) {
            //     mini = 1;
            //     maxi = 1;
            //     continue;
            // }
            int tmp = k*maxi;
            maxi = max({k*maxi,k*mini,k});
            mini = min({tmp,k*mini,k});
            ans = max(ans,maxi);
        }
        return ans;
    }
};
