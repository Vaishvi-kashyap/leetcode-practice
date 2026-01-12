class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, left = 0, right = n - 1;
        int lmax = 0, rmax = 0;
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