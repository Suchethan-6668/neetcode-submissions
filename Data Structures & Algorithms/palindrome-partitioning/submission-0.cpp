class Solution {
public:
    bool isPal(string s,int l,int r) {

        while(l < r) {
            if(s[l++] != s[r--])return false;
        }
        return true;
    }
    void solve(int ind,int n,string &s,vector<string> &curr,vector<vector<string>> &ans) {
        if(ind == n) {
            ans.push_back(curr);
            return;
        }

        for(int i = ind;i < n;i++) {
            if(isPal(s,ind,i)) {
                curr.push_back(s.substr(ind,i-ind+1));
                solve(i+1,n,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<string>> ans;

        vector<string> curr;
        solve(0,n,s,curr,ans);
        return ans;
    }
};
