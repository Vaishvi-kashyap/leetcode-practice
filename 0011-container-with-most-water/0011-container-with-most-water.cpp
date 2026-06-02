class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() - 1;
        int lmax = 0, rmax = n, maximum = 0;
        while (lmax <= rmax) {
            int width = rmax - lmax;
            int ht = min(height[lmax], height[rmax]);
            int area = width * ht;
            maximum = max(maximum, area);
            if (height[lmax] < height[rmax])
                lmax++;
            else
                rmax--;
        }
        return maximum;
    }
};