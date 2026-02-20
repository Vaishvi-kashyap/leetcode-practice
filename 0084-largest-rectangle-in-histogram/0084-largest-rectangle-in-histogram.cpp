class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > currHeight) {
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, h * (right - left - 1));
            }

            st.push(i);
        }
        return maxArea;
    }
};