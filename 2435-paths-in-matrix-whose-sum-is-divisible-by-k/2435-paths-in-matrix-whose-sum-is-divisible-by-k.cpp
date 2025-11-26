class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n, k;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int mod, vector<vector<int>>& grid) {
        // If reached bottom-right
        if (i == m - 1 && j == n - 1) {
            return ((mod + grid[i][j]) % k == 0) ? 1 : 0;
        }

        if (dp[i][j][mod] != -1)
            return dp[i][j][mod];

        long long ways = 0;
        int newMod = (mod + grid[i][j]) % k;

        // Move down
        if (i + 1 < m)
            ways = (ways + solve(i + 1, j, newMod, grid)) % MOD;

        // Move right
        if (j + 1 < n)
            ways = (ways + solve(i, j + 1, newMod, grid)) % MOD;

        return dp[i][j][mod] = ways;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = k;

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid);
    }
};