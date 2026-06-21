class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int j = 0;
        for(int i = 0;i < n;i++) {
            if(i > k) {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }
                j++;
            }
            if(mp.find(nums[i]) != mp.end()) {
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};