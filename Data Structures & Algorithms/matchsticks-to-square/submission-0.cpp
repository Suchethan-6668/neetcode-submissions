class Solution {
public:
    bool solve(int ind,int n,vector<int> &nums,vector<int> &sides,int tar) {
        
        if(ind == n) {
            return sides[0] == tar && sides[1] == tar && sides[2] == tar && sides[3] == tar;
        }


        for(int i = 0;i < 4;i++) {
            if(nums[ind] + sides[i] > tar)continue;

            sides[i] += nums[ind];
            if(solve(ind+1,n,nums,sides,tar))return true;

            sides[i] -= nums[ind];
            if(sides[i] == 0)break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        int tot = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(tot%4 != 0)return false;
        int target = tot/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0] > target)return false;
        vector<int> sides(4,0);
        return solve(0,n,matchsticks,sides,target);





    }
};