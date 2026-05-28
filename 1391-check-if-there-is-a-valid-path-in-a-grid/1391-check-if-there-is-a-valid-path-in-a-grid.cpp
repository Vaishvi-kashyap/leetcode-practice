class Solution {
public:
    // directions:
    // up, down, left, right
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // valid directions for each street type
    vector<vector<int>> streets = {
        {},     // dummy for 0-index
        {2, 3}, // type 1 -> left, right
        {0, 1}, // type 2 -> up, down
        {2, 1}, // type 3 -> left, down
        {3, 1}, // type 4 -> right, down
        {2, 0}, // type 5 -> left, up
        {3, 0}  // type 6 -> right, up
    };

    bool dfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        // reached destination
        if (x == m - 1 && y == n - 1)
            return true;

        vis[x][y] = 1;

        int type = grid[x][y];

        // try all allowed directions
        for (int d : streets[type]) {

            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            // boundary check
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            if (vis[nx][ny])
                continue;

            int nextType = grid[nx][ny];

            // opposite direction
            int opposite;

            if (d == 0)
                opposite = 1;
            else if (d == 1)
                opposite = 0;
            else if (d == 2)
                opposite = 3;
            else
                opposite = 2;

            // check if neighbor connects back
            bool valid = false;

            for (int nd : streets[nextType]) {
                if (nd == opposite) {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                if (dfs(nx, ny, grid, vis))
                    return true;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        return dfs(0, 0, grid, vis);
    }
};