class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // if k still left → remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build result string
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;

        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};