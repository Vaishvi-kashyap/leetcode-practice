class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row,
             int col) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] ||
            grid[row][col] != 1)
            return;

        vis[row][col] = true;

        dfs(grid, vis, row + 1, col);
        dfs(grid, vis, row - 1, col);
        dfs(grid, vis, row, col + 1);
        dfs(grid, vis, row, col - 1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m, (vector<bool>(n, false)));

        // left & right boundaries
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(grid, vis, i, 0);
            if (!vis[i][n - 1] && grid[i][n - 1] == 1)
                dfs(grid, vis, i, n - 1);
        }

        // top & bottom boundaries
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(grid, vis, 0, j);
            if (!vis[m - 1][j] && grid[m - 1][j] == 1)
                dfs(grid, vis, m - 1, j);
        }

        // convert surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};