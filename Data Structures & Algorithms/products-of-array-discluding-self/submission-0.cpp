class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,0);
        int pre = 1;
        for(int i = 0;i < n;i++) {
            p[i] = pre;
            pre *= nums[i];
        }
        vector<int> s(n,0);
        int suff = 1;
        for(int i = n-1;i >= 0;i--) {
            s[i] = suff;
            suff *= nums[i];
        }
        vector<int> res(n,0);
        for(int i = 0;i < n;i++){
            res[i]=(p[i]*s[i]);
        }
        return res;
    }
};
