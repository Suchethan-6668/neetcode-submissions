class Solution {
public:
    int solve(int row,int n,vector<int> &colu,vector<int> &diag1,vector<int> &diag2) {
        if(row == n)return 1;

        int tot = 0;

        for(int col = 0;col < n;col++) {
            int d1 = row+col;
            int d2 = row + n-1-col;

            if(colu[col] ||diag1[d1] || diag2[d2])continue;

            colu[col] =diag1[d1] = diag2[d2] = 1;
            tot += solve(row+1,n,colu,diag1,diag2);
            colu[col] =diag1[d1] = diag2[d2] = 0;

        }
        return tot;
        
    }
    int totalNQueens(int n) {
        vector<int> col(n,0);
        vector<int> diag1(2*n,0);
        vector<int> diag2(n*2,0);

        return solve(0,n,col,diag1,diag2);
    }
};