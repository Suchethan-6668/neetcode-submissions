class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minS = 1e9;
        int n = strs.size();
        //unordered_set<char> st;
        for(int i = 0;i < n;i++) {
            minS = min(minS,(int)strs[i].size());
        }
        int j = 0;
        string s = "";
        for( j = 0;j < minS;j++) {
            char ch = strs[0][j];
            for(int i = 1;i < n;i++) {
                if(strs[i][j] != ch)return s;
            }
            s += ch;
        }
        return s;

    }
};