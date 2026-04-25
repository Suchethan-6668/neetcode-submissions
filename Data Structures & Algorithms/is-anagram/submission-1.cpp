class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        int n = s.size();
        int k = t.size();
        for(int i = 0;i < n;i++) {
            m[s[i]]++;
        }
        for(int i = 0;i < k;i++) {
            if(m.find(t[i]) == m.end())return false;
            else {
                if(m[t[i]] == 1)m.erase(t[i]);
                else m[t[i]]--;
            }
        }
        return m.empty();
    }
};
