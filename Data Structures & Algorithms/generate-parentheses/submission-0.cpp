class Solution {
public:
    void solve(int open,int close,int n,string k,vector<string> &ans) {
        if(k.size() == 2*n) {
            ans.push_back(k);
            return;
        }
        if(open < n) {
            solve(open+1,close,n,k+'(',ans);
        }
        if(open > close) {
            solve(open,close+1,n,k+')',ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string k = "";
        solve(0,0,n,k,ans);
        return ans;
    }
};
