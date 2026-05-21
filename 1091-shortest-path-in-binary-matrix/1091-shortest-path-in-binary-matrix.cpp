class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q; // {dis,{row,col}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        // 8 directions
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};