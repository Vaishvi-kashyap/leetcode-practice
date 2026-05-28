class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp; // char,freq
        for (auto ch : s)
            mp[ch]++;
        for (auto ch : t)
            mp[ch]--;

        for (auto it : mp) {
            if (it.second != 0)
                return false;
        }
        return true;
    }
};