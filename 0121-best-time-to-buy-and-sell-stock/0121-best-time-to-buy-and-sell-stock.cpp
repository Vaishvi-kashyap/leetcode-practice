class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = prices[0], ans = 0;
        for (int val : prices) {
            bestbuy = min(bestbuy, val);
            if (val > bestbuy)
                ans = max(ans, val - bestbuy);
        }
        return ans;
    }
};