class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //{target,indices}
        for (int i = 0; i < nums.size(); i++) {
            int ans = target - nums[i];
            if (m.find(ans) != m.end())
                return {m[ans], i};
            m[nums[i]] = i;
        }
        return {};
    }
};