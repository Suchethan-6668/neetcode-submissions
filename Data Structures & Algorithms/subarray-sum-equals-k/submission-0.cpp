class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int cnt =0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0;i < n;i++) {
            sum += nums[i];
            int comp = sum - k;
            if(mp.find(comp) != mp.end()){
                cnt+= mp[comp];
            }
            mp[sum]++;
        }
        return cnt;
    }
};