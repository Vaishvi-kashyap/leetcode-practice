class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,
             int originalColor) {
        // Boundary check and same color check
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] != originalColor)
            return;

        image[i][j] = newColor; // Fill with new color

        // 4-directional movement
        dfs(image, i + 1, j, newColor, originalColor);
        dfs(image, i - 1, j, newColor, originalColor);
        dfs(image, i, j + 1, newColor, originalColor);
        dfs(image, i, j - 1, newColor, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image; // avoid infinite loop

        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};