class Solution {
public:
    void getAllCombinations(vector<int>& nums, vector<int>& ans, int i,
                            int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (i == nums.size() || target < 0) {
            return;
        }

        ans.push_back(nums[i]);
        // getAllCombinations(nums, ans, i + 1, target - nums[i], res);
        getAllCombinations(nums, ans, i, target - nums[i], res);
        ans.pop_back();
        getAllCombinations(nums, ans, i + 1, target, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        getAllCombinations(nums, ans, 0, target, res);
        return res;
    }
};