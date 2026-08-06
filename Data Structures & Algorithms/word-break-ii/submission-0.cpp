class Solution {
public:
    void solve(int ind,int n,string p,string s,unordered_set<string> & wordDict,vector<string> &ans) {

        if(ind == n) {
            ans.push_back(p);
        }

        for(int i = ind+1;i <= n;i++) {
            string pre = s.substr(ind,i-ind);
            if(wordDict.count(pre)) {
                string nxt = (p.empty())?pre:p+" "+pre;
                solve(i,n,nxt,s,wordDict,ans);
            }

        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;

        int n = s.length();

        //vector<bool> dp(n+1,false);
        unordered_set<string> st(wordDict.begin(),wordDict.end());

        
        solve(0,n,"",s,st,ans);
        return ans;


    }
};