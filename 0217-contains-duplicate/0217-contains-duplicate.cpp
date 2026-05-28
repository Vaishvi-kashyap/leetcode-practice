class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m; // value,freq
        for (int val : nums)
            m[val]++;

        for (auto it : m) {
            int value = it.first;
            int freq = it.second;

            if (freq > 1)
                return true;
        }
        return false;
    }
};