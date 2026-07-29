class Solution {
public:
    bool solve(int i,int j,int m,int n,int p,vector<vector<char>>& board,string word) {
        if(p == word.size())return true;
        if(i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[p])return false;
        

        char temp = board[i][j];
        board[i][j] = '#';

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        //bool found = false;
        for(int k = 0;k < 4;k++) {
            if(solve(i+dx[k],j+dy[k],m,n,p+1,board,word)){
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    } 

    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        //return solve(0,0,m,n,0,board,word);

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(solve(i,j,m,n,0,board,word))return true;
            }
        }
        return false;

    }
};
