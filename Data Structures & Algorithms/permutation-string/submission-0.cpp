class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int j = 0;
        map<char,int> mp1;
        for(char &c : s1) {
            mp1[c]++;
        }
        map<char,int> mp2;
        for(int i = 0;i < n2;i++) {
            if(i >= n1) {
                mp2[s2[j]]--;
                if(mp2[s2[j]] == 0)mp2.erase(s2[j]);
                j++;
            }
            mp2[s2[i]]++;
            if((i-j+1) == n1) {
                if(mp1 == mp2) {
                    return true;
                }
            }
            
        }
        return false;
    }
};
