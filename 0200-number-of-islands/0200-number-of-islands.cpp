class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row,
             int col) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vis[row][col] = true;
        q.push({row, col});

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};
        while (!q.empty()) {
            int row1 = q.front().first;
            int col1 = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = delrow[i] + row1;
                int ncol = delcol[i] + col1;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
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
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};