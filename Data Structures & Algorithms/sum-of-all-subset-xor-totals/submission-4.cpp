class Solution {
public:
    void solve(int ind,int &sum,int curr,vector<int> &nums,int n) {
        if(ind == n){sum += curr;return;}
        solve(ind+1,sum,curr,nums,n);
        
        solve(ind+1,sum,curr^nums[ind],nums,n);

    }
    // int solve(int ind,int curr,vector<int> &nums,int n) {
    //     if(ind == n){return curr;}
    //     return solve(ind+1,curr,nums,n)+solve(ind+1,curr^nums[ind],nums,n);

    // }
    int solve(int ind,int curr,vector<int> &nums,int n) {
        int total = curr;
        for(int i = ind;i < n;i++) {
            total += solve(i+1,curr^nums[i],nums,n);
        }
        return total;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        //solve(0,sum,0,nums,n);
        return solve(0,0,nums,n);
        return sum;


    }
};