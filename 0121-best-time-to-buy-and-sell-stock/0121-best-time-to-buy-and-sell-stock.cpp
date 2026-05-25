class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], maximum = 0;
        for (int val : prices) {
            bestBuy = min(bestBuy, val);
            if (val > bestBuy)
                maximum = max(maximum, val - bestBuy);
        }
        return maximum;
    }
};