class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        // Smallest two nums % 3 == 1
        int a1 = INT_MAX, a2 = INT_MAX;

        // Smallest two nums % 3 == 2
        int b1 = INT_MAX, b2 = INT_MAX;

        for (int x : nums) {
            sum += x;
            int r = x % 3;

            if (r == 1) {
                if (x < a1) {
                    a2 = a1;
                    a1 = x;
                } else if (x < a2) {
                    a2 = x;
                }
            } else if (r == 2) {
                if (x < b1) {
                    b2 = b1;
                    b1 = x;
                } else if (x < b2) {
                    b2 = x;
                }
            }
        }

        if (sum % 3 == 0)
            return sum;

        int ans = 0;

        // Case sum % 3 == 1:
        // remove smallest 1 (a1) OR smallest two (b1+b2)
        if (sum % 3 == 1) {
            int option1 = (a1 == INT_MAX ? INT_MIN : sum - a1);
            int option2 = (b2 == INT_MAX ? INT_MIN : sum - (b1 + b2));
            ans = max(option1, option2);
        }

        // Case sum % 3 == 2:
        // remove smallest 1 (b1) OR smallest two (a1+a2)
        else {
            int option1 = (b1 == INT_MAX ? INT_MIN : sum - b1);
            int option2 = (a2 == INT_MAX ? INT_MIN : sum - (a1 + a2));
            ans = max(option1, option2);
        }

        return ans;
    }
};