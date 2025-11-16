class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q; //(i,j),time

        // pushing all sources in queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // bfs
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;

            q.pop();
            res = max(res, time);

            if ((i - 1) >= 0 && (!vis[i - 1][j]) && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }
            if ((i + 1) < m && (!vis[i + 1][j]) && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }
            if ((j - 1) >= 0 && (!vis[i][j - 1]) && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
            if ((j + 1) < n && (!vis[i][j + 1]) && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
        }

        // check for fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (!vis[i][j])) {
                    return -1;
                }
            }
        }
        return res;
    }
};