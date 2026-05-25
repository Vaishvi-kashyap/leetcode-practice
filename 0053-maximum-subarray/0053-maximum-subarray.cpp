class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for (auto val : nums) {
            sum += val;
            maxSum = max(maxSum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};