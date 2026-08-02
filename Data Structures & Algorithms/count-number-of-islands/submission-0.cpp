class Solution {
public:
    void dfs(int row,int col,int m,int n,vector<vector<char>> &grid,vector<vector<int>> &vis) {

        vis[row][col] = 1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        for(int i = 0;i < 4;i++) {
            int nr = row+dx[i];
            int nc = col+dy[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] == '0' || vis[nr][nc])continue;
            dfs(nr,nc,m,n,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i,j,m,n,grid,vis);
                }
            }
        }
        return cnt;
    }
};
