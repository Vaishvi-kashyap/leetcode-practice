class Solution {
public:
    double myPow(double x, int n) {
        long biForm = n;
        double ans = 1;

        if (n < 0) {
            x = 1 / x;
            biForm = -biForm;
        }

        while (biForm > 0) {
            if (biForm % 2 == 1) {
                ans *= x;
            }
            x *= x;
            biForm /= 2;
        }
        return ans;
    }
};