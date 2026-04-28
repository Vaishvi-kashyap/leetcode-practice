class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int row,
             int col) {
        int m = board.size();
        int n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] ||
            board[row][col] != 'O')
            return;

        vis[row][col] = true;

        dfs(board, vis, row + 1, col);
        dfs(board, vis, row - 1, col);
        dfs(board, vis, row, col + 1);
        dfs(board, vis, row, col - 1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, (vector<bool>(n, false)));

        // left & right boundaries
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(board, vis, i, 0);
            if (!vis[i][n - 1] && board[i][n - 1] == 'O')
                dfs(board, vis, i, n - 1);
        }

        // top & bottom boundaries
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(board, vis, 0, j);
            if (!vis[m - 1][j] && board[m - 1][j] == 'O')
                dfs(board, vis, m - 1, j);
        }

        // convert surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};