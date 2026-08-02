class Solution {
public:
    int dfs(int row,int col,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &vis) {
        vis[row][col] = 1;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int sum = 1;
        for(int i = 0;i < 4;i++) {
            int nr = row+dx[i];
            int nc = col+dy[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] == 0 ||vis[nr][nc])continue;
            //if(vis[nr][nc])return 1;
            sum += (dfs(nr,nc,m,n,grid,vis));
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int maxi = INT_MIN;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    maxi = max(maxi,dfs(i,j,m,n,grid,vis));
                }
            }
        }
        return maxi == INT_MIN?0:maxi;
    }
};
