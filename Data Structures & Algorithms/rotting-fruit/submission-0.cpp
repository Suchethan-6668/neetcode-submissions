class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int tot = 0,onecnt = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 2){q.push({i,j});}
                 if(grid[i][j] != 0)tot++;
                 if(grid[i][j] == 1)onecnt++;
            }
        }
        //if(onecnt == 0)return 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int time = 0;
        int cnt = 0;
        //vector<vector<bool>> vis(m,vector<bool>(n,0));
        while(!q.empty()) {
            int k = q.size();
            cnt += k;
            while(k--) {
                auto [x,y] = q.front();
                q.pop();
                //int nx = 0,ny = 0;
                for(int i = 0;i < 4;i++) {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())time++;
        }


        return tot==cnt?time:-1;
    }
};
