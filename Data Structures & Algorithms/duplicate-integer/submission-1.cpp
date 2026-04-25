class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0;i < n;i++) {
            //if(nums[i] == nums[i+1])return true;
            s.insert(nums[i]);
        }
        return s.size() != n;
    }
};