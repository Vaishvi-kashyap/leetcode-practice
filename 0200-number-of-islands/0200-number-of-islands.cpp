class Solution {
public:
    void numIslandsDFS(vector<vector<char>>& grid, vector<vector<bool>>& vis,
                       int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] ||
            grid[i][j] != '1') {
            return;
        }
        vis[i][j] = true;
        numIslandsDFS(grid, vis, i - 1, j, m, n);
        numIslandsDFS(grid, vis, i + 1, j, m, n);
        numIslandsDFS(grid, vis, i, j - 1, m, n);
        numIslandsDFS(grid, vis, i, j + 1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && (!vis[i][j])) {
                    numIslandsDFS(grid, vis, i, j, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
};