class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int inf = 2147483647;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(mat[i][j] == 0){q.push({i,j});vis[i][j] = 1;}
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int cnt = 1;
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                
                auto [x,y] = q.front();
                
                //vis[x][y] = 1;
                q.pop();
                for(int i = 0;i < 4;i++) {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] || mat[nx][ny] == -1)continue;
                    vis[nx][ny] = 1;
                    mat[nx][ny] = cnt;
                    q.push({nx,ny});

                }
            }
            if(!q.empty())cnt++;
        }
        
    }
};
