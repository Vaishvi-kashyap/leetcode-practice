class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // dummy height to empty stack
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            // maintain increasing stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i; // no smaller on left
                else
                    width = i - st.top() - 1; // between smaller elements

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }
        return maxArea;
    }
};