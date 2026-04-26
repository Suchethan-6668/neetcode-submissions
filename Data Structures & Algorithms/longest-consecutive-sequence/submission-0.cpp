class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int lcs = 0;
        int cs = 0;

        unordered_map<int,int> mp;
        
        for(int num:nums) {
            if(!mp[num]){
                mp[num] = mp[num-1]+mp[num+1]+1;
                mp[num-mp[num-1]] = mp[num];
                mp[num+mp[num+1]] = mp[num];
                lcs = max(lcs,mp[num]);
            }
        }
        return lcs;
    }
};
