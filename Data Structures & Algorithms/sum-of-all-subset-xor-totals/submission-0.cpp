class Solution {
public:
    void solve(int ind,int &sum,int prev,vector<int> &nums,int n) {
        if(ind == n)return;
        solve(ind+1,sum,prev,nums,n);
        int curr = prev ^ nums[ind];
        sum += curr;
        solve(ind+1,sum,curr,nums,n);

    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        solve(0,sum,0,nums,n);
        return sum;


    }
};