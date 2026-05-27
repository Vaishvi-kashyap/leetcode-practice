class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int n = words.size();

        while (i < n) {
            int j = i;
            int lineLength = 0;
            // Greedily take maximum words
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            int gaps = j - i - 1;
            string line = "";

            // LAST LINE or SINGLE WORD
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                // remaining spaces at end
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                int totalSpaces = maxWidth - lineLength;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int spaces = evenSpaces;
                        // left gaps get extra spaces
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }
                        line += string(spaces, ' ');
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};