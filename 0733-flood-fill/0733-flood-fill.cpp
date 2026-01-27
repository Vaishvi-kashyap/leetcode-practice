class Solution {
public:
    // TC:O(m*n),SC:O(m*n)
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor,
             int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
            image[sr][sc] != oldColor || image[sr][sc] == newColor)
            return;
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int oldColor = image[sr][sc];
        if (image[sr][sc] == newColor)
            return image;
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};