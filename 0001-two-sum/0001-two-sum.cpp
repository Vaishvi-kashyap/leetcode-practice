class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //{value,index}
        for (int i = 0; i < nums.size(); i++) {
            int ans = target - nums[i];
            if (mp.find(ans) != mp.end()) {
                return {mp[ans], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};