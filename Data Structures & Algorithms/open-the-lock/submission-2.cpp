class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();

        unordered_set<string> vis(deadends.begin(),deadends.end());
        if(vis.count("0000"))return -1;
        unordered_map<string,int> mp;

        queue<pair<string,int>> q;
        q.push({"0000",0});
        vis.insert("0000");
        int cnt = -1;
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                auto [curr,steps] = q.front();
                q.pop();
                if(curr == target)return steps;
                
                for(int i = 0;i < curr.length();i++) {
                    char ori = curr[i];
                    curr[i] = (ori== '9')?'0':(ori+1);
                    if(!vis.count(curr)) {
                        vis.insert(curr);
                        q.push({curr,steps+1});
                    }

                    curr[i] = (ori == '0') ? '9' : ori - 1;
                    if (!vis.count(curr)) {
                        vis.insert(curr);
                        q.push({curr, steps + 1});
                    }
                    
                    
                    curr[i] = ori;
                }
            }
            
        }
        return -1;
    }
};