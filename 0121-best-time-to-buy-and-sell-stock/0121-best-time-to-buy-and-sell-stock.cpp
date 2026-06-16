class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], ans = 0;
        for (int val : prices) {
            bestBuy = min(bestBuy, val);
            if (val > bestBuy)
                ans = max(ans, val - bestBuy);
        }
        return ans;
    }
};