class Solution {
public:
    string add(string num1, string num2) {
        string ans;
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
        int sum, carry = 0;
        while (idx2 >= 0) {
            sum = (num1[idx1] - '0') + (num2[idx2] - '0') + carry;
            carry = sum / 10;
            char c = sum % 10 + '0';
            ans += c;
            idx1--;
            idx2--;
        }
        while (idx1 >= 0) {
            sum = (num1[idx1] - '0') + carry;
            carry = sum / 10;
            char c = sum % 10 + '0';
            ans += c;
            idx1--;
        }
        if (carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        if (num2.size() > num1.size())
            return add(num2, num1);
        else
            return add(num1, num2);
    }
};