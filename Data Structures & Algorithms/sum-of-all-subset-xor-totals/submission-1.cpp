class Solution {
public:
    void solve(int ind,int &sum,int curr,vector<int> &nums,int n) {
        if(ind == n){sum += curr;return;}
        solve(ind+1,sum,curr,nums,n);
        
        solve(ind+1,sum,curr^nums[ind],nums,n);

    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        solve(0,sum,0,nums,n);
        return sum;


    }
};