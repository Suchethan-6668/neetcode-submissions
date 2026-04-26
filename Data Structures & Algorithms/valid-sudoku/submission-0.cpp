class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i < m;i++) {
            unordered_map<char,int> mp;
            for(int j = 0;j < n;j++) {
                if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()){
                    return false;
                }
                mp[board[i][j]]++;
            }
        }

        for(int j = 0;j < n;j++) {
            unordered_map<char,int> mp;
            for(int i = 0;i < m;i++) {
                if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()){
                    return false;
                }
                mp[board[i][j]]++;
            }
        }

        for (int row_offset = 0; row_offset < 9; row_offset += 3) {
        for (int col_offset = 0; col_offset < 9; col_offset += 3) {
            unordered_map<char, int> mp;
            
            // Loop through the 3x3 cells in the current box
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char current_char = board[row_offset + i][col_offset + j];
                    
                    if (current_char != '.') {
                        if (mp.find(current_char) != mp.end()) {
                            return false;
                        }
                        mp[current_char]++;
                    }
                }
            }
        }
    }
        return true;
    }
};
