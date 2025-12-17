class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int val : set) {
            if (set.find(val - 1) == set.end()) {
                int count = 1, current = val;
                while (set.find(current + 1) != set.end()) {
                    count++;
                    current++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};