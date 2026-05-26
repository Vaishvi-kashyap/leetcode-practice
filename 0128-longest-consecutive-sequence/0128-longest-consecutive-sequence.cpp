class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int start = num;
                int count = 1;
                while (st.find(start + 1) != st.end()) {
                    start++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};