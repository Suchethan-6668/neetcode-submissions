class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Base case: Out of bounds, already visited, or water cannot flow uphill/flat from prev cell
        // if (r < 0 || r >= m || c < 0 || c >= n || ocean[r][c] || heights[r][c] < prevHeight) {
        //     return;
        // }
        
        ocean[r][c] = true;
        
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c+dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || ocean[nr][nc] || heights[nr][nc] < heights[r][c]) {
            continue;
        }
            dfs(nr, nc, ocean, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS along left/right boundaries
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific,  heights);          // Left (Pacific)
            dfs(i, n - 1, atlantic, heights); // Right (Atlantic)
        }
        
        // DFS along top/bottom boundaries
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific,  heights);          // Top (Pacific)
            dfs(m - 1, j, atlantic,  heights); // Bottom (Atlantic)
        }
        
        // Find cells reachable by both oceans
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
        


    }
};
