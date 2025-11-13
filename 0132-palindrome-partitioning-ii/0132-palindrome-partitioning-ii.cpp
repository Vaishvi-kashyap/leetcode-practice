class Solution {
public:
    int minPartition(string s, int i, int j, vector<vector<int>>& dp,
                     vector<vector<bool>>& pal) {
        if (i >= j || pal[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (pal[i][k]) { // only cut if left part is palindrome
                int right;
                if (dp[k + 1][j] != -1)
                    right = dp[k + 1][j];
                else
                    right = minPartition(s, k + 1, j, dp, pal);
                ans = min(ans, 1 + right);
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
                    pal[i][j] = true;
            }
        }

        return minPartition(s, 0, n - 1, dp, pal);
    }
};