class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; //{word, index}
        int left = 0, right = 0, maximum = 0;
        for (char ch : s) {
            if (mp.find(ch) != mp.end() && mp[ch] >= left) {
                left = mp[ch] + 1;
            }
            mp[ch] = right;
            maximum = max(maximum, right - left + 1);
            right++;
        }
        return maximum;
    }
};