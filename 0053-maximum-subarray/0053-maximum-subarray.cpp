class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int val : nums) {
            sum += val;
            res = max(res, sum);
            if (sum < 0)
                sum = 0;
        }
        return res;
    }
};