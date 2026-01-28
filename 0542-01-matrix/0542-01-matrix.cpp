class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dirRow[] = {-1, 0, +1, 0};
        int dirCol[] = {0, -1, 0, +1};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nrow = row + dirRow[j];
                    int ncol = col + dirCol[j];

                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                        continue;

                    if (ans[nrow][ncol] == INT_MAX) {
                        ans[nrow][ncol] = ans[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return ans;
    }
};