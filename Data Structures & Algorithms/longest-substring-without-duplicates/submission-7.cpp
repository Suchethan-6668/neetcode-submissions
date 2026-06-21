class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;
        int j = 0;
        unordered_map<char,int> mp;
        mp[s[0]] = 0;
        int maxi = 1;
        for(int i = 1;i < n;i++) {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= j) {
                j = mp[s[i]] + 1;
                

            }
            mp[s[i]] = i;
            maxi = max(maxi,(i-j+1));
        }
        return maxi;
    }
};
