class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //int i = 0,j = n-1;
        unordered_map<int,int> m;
        m[nums[0]] = 0;
        for(int i = 1;i < n;i++) {
            int comp = target - nums[i];
            if(m.find(comp)!= m.end()) {
                return {m[comp],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
