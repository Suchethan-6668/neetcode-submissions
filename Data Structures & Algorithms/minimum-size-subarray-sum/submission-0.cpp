class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int j = 0;
        int mini = 1e9;
        int sum = 0;
        for(int i = 0;i < n;i++) {
            sum += nums[i];

            while(sum >= target) {
                sum -= nums[j];
                mini = min(mini,(i-j+1));
                j++;
            }

            
        }
        return mini<1e9?mini:0;
    }
};