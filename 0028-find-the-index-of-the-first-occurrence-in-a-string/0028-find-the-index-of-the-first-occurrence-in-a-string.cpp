class Solution {
public:
    void getLPSLength(vector<int>& lps, string& s) {
        int pre = 0, suff = 1;
        while (suff < s.size()) {
            if (s[pre] == s[suff]) {
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if (pre == 0) {
                    lps[suff] = 0;
                    suff++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        getLPSLength(lps, needle);
        int first = 0, second = 0;
        while (first < haystack.size() && second < needle.size()) {
            // if matched
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            }
            // not matched
            else {
                if (second == 0)
                    first++;
                else {
                    second = lps[second - 1];
                }
            }
        }
        if (second == needle.size())
            return first - second;
        return -1;
    }
};