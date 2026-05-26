class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // odd length
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }

                l--;
                r++;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }

                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};