class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, lmax = 0, rmax = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);
            if (lmax < rmax) {
                ans += lmax - height[left];
                left++;
            } else {
                ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};