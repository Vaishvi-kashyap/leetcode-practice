class Solution {
public:
    int minInsertions(string s) {
        int m = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return m - dp[m][m];
    }
};