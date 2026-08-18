class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& board,int m,int n,vector<vector<int>>& vis,int dx[],int dy[]){
        vis[x][y] = 1;

        for(int i = 0;i < 4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
           if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == 'O') dfs(x+dx[i],y+dy[i],board,m,n,vis,dx,dy);
        }
    }
    void solve(vector<vector<char>>& board) {
         int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        for(int i = 0;i < n;i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,board,m,n,vis,dx,dy);
            }
            if(!vis[m-1][i] && board[m-1][i] == 'O'){
                dfs(m-1,i,board,m,n,vis,dx,dy);
            }
        }

        for(int i = 0;i < m;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,m,n,vis,dx,dy);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,board,m,n,vis,dx,dy);
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && board[i][j] == 'O')board[i][j] = 'X';
            }
        }
    }
};
