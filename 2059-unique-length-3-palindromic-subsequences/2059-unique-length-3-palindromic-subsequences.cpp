class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int left = s.find(c);
            int right = s.rfind(c);

            if (left < right) {
                unordered_set<char> mid;
                for (int i = left + 1; i < right; i++)
                    mid.insert(s[i]);

                ans += mid.size(); // Each unique middle character forms a
                                   // palindrome
            }
        }
        return ans;
    }
};