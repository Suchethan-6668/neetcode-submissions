class Solution {
public:
    void solve(int ind,int n,string &digits,string k,vector<string> &ans,unordered_map<char,string> &mp) {
        if(k.size() == n) {
            ans.push_back(k);
            return;
        }
        for(int i = ind;i < n;i++) {
            for(char &c: mp[digits[i]]) {
                solve(i+1,n,digits,k+c,ans,mp);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        vector<string> ans;
        if(digits.empty())return ans;
        string k = "";


        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(0,n,digits,k,ans,mp);
        return ans;
    }
};
