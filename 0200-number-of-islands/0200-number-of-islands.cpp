class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row,
             int col) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n ||
            grid[row][col] == '0' || vis[row][col])
            return;

        vis[row][col] = true;

        dfs(grid, vis, row + 1, col);
        dfs(grid, vis, row - 1, col);
        dfs(grid, vis, row, col + 1);
        dfs(grid, vis, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};