class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int second = target - nums[i];

            if (m.find(second) != m.end()) {
                return {m[second], i}; // directly return
            }

            m[nums[i]] = i;
        }

        return {}; // if no solution (safety)
    }
};