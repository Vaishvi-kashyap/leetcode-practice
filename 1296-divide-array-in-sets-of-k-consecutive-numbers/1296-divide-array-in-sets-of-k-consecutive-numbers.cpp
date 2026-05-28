class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        map<int, int> mp; // {value,freq}
        for (int val : nums)
            mp[val]++;

        for (auto it : mp) {
            int start = it.first;
            int freq = it.second;

            if (freq == 0)
                continue;

            for (int i = 0; i < k; i++) {
                int card = start + i;

                if (mp[card] < freq)
                    return false;

                mp[card] -= freq;
            }
        }
        return true;
    }
};