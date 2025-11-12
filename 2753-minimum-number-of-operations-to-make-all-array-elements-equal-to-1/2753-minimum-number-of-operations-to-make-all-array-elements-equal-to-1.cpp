class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        // Case 1: Already has ones
        if (ones > 0)
            return n - ones;

        int ans = INT_MAX;

        // Case 2: Try to find subarray with gcd = 1
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i); // length-1 operations
                    break;                 // No need to go further
                }
            }
        }

        if (ans == INT_MAX)
            return -1;

        // Total = steps to make first 1 + (n - 1)
        return ans + (n - 1);
    }
};