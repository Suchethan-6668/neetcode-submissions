class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto x: prerequisites) {
            adj[x[1]].push_back(x[0]);
        }

        vector<int> indeg(numCourses,0);

        for(int i = 0;i < numCourses;i++) {
            for(auto x: adj[i]) {
                indeg[x]++;
            }
        }

        queue<int> q;

        for(int i = 0;i < numCourses;i++) {
            if(indeg[i] == 0)q.push(i);
        }
        int cnt = 0;
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            topo.push_back(node);
            for(auto nei: adj[node]) {
                indeg[nei]--;
                if(indeg[nei] == 0)q.push(nei);
            }
        }
        return cnt == numCourses?topo:vector<int>{};
    }
};
