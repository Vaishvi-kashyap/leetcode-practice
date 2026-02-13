class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                s1.push(s[i]);
            } else {
                if (s1.empty())
                    return false;
                char top = s1.top();
                s1.pop();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') || (s[i] == ']' && top != '['))
                    return false;
            }
        }
        return s1.empty();
    }
};