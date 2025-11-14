class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // TC:O(n), SC:O(n)
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (int val : set) {
            if (set.find(val - 1) == set.end()) {
                int current = val;
                int count = 1;

                while (set.find(current + 1) != set.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};