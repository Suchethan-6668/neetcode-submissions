class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n-2;i++) {
            if(i > 0 && nums[i] == nums[i-1])continue;
            int sum = nums[i];

            int j = i+1,k = n-1;
            int nsum = 0;
            while(j < k){
                nsum = sum +nums[j]+nums[k];
                if(nsum== 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1])j++;
                    while(j < k && nums[k] == nums[k-1])k--;
                    j++;
                    k--;
                }
                if(nsum > 0)k--;
                if(nsum < 0)j++;
            }
        }
        
        return res;
    }
};
