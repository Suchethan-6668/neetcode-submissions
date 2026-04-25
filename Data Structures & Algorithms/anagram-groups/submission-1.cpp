class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        //vector<string> r1 = strs;
        map<map<char,int>,vector<string>> m;
        
        for(auto &s: strs) {
            map<char,int> m1;
            for(auto &c: s){
                m1[c]++;
            }
            m[m1].push_back(s);
        }

        for(auto x: m) {
            res.push_back(x.second);

        }
        return res;
    }
};
