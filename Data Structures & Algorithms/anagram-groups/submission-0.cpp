class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        vector<string> r1 = strs;
        unordered_map<string,vector<int>> m;
        int i = 0;
        for(auto &s: r1) {
            sort(s.begin(),s.end());
            m[s].push_back(i);
            i++;
        }

        for(auto x: m) {
            vector<int> temp = x.second;
            vector<string> t1;
            for(int y:temp) {
                t1.push_back(strs[y]);
            }
            res.push_back(t1);

        }
        return res;
    }
};
