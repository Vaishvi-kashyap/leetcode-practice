class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC:O(n),SC:O(1)
        int n = nums.size();
        vector<int> ans(n, 1);

        // To calculate prefix
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        // To calculate suffix
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};