class NumMatrix {
public:
    vector<int> pres;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        

          m = matrix.size();
          n = matrix[0].size();

        pres.resize(m*n);
        int val = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++) {
                val = matrix[i][j];
                int top = (i > 0) ? pres[(i - 1) * n + j] : 0;
                int left = (j > 0) ? pres[i * n + (j - 1)] : 0;
                int topLeft = (i > 0 && j > 0) ? pres[(i - 1) * n + (j - 1)] : 0;
                
                pres[i*n+j] = val+top+left-topLeft;
            }
        }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = pres[row2*n+col2];
        
        int top = (row1>0)?pres[(row1-1)*n+col2]:0;
        int left = (col1 > 0)? pres[row2*n+(col1-1)]:0;
        int topLeft = (row1 > 0 && col1 > 0)? pres[(row1-1)*n+(col1-1)]:0;

        return total-top-left+topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */