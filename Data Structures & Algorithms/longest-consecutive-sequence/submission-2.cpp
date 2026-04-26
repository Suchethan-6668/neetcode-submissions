class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int lcs = 0;
        int cs = 0;

        unordered_set<int> mp(nums.begin(),nums.end());


        for(int num:mp){
            if(mp.find(num-1) == mp.end()){
                cs = 1;
                while(mp.find(num+cs)!=mp.end()){
                    cs++;
                }
                lcs = max(lcs,cs);
            }
        }
        return lcs;
    }
};
