class Solution {
public:
    bool solve(int ind,int n,int k,vector<int> &nums,vector<int> &sides,int target) {
        if(ind == n) {
            for(int i = 0;i < k;i++) {
                if(sides[i] != target)return false;
            }
            return true;
        }

        for(int i =0;i < k;i++) {
            if(sides[i] + nums[ind] > target)continue;

            sides[i] += nums[ind];
            if(solve(ind+1,n,k,nums,sides,target))return true;
            sides[i] -= nums[ind];
            if(sides[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sides(k,0);
    
        int tot = accumulate(nums.begin(),nums.end(),0);
        if(tot%k != 0)return false;
        sort(nums.rbegin(),nums.rend());

        int target = tot/k;
        if(nums[0] > target)return false;
        return solve(0,n,k,nums,sides,target);





    }
};