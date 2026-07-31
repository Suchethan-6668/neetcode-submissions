class Solution {
public:
    int dfs(int row,int col,int m,int n,vector<vector<int>>& grid,vector<vector<int>> & vis) {
        
        

        vis[row][col] = 1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int sum = 0;
        for(int i = 0;i < 4;i++) {
            int nx = row+dx[i];
            int ny = col+dy[i];
            if(nx  < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == 0){sum++;continue;}
            if(vis[nx][ny])continue;
            sum += dfs(nx,ny,m,n,grid,vis);
        }

        //vis[row][col] = 0;
        return sum;


    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        //return dfs(0,0,m,n,grid,vis);

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(!vis[i][j] && grid[i][j])return dfs(i,j,m,n,grid,vis);
            }
        }
        return 0;
    }
};