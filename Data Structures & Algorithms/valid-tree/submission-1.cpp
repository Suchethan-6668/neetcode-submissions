class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        if(edges.size() != n-1)return false;
        for(auto &x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        //int cnt = 0;
        vector<int> vis(n,0);;
        queue<pair<int,int>> q;

        vis[0] = 1;
        q.push({0,-1});
        int cnt = 1;

        while(!q.empty()) {
            auto x = q.front();
            q.pop();

            int node = x.first;
            int par = x.second;

            for(int nei: adj[node]) {
                if(!vis[nei]) {
                    cnt++;
                    vis[nei] = 1;
                    q.push({nei,node});
                }else {
                    if(nei != par)return false;
                }
            }
        }

        return cnt == n;



    }
};
