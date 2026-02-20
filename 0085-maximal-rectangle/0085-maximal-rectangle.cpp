class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > currHeight) {
                int element = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1')
                    heights[i] += 1;
                else
                    heights[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};