class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], maxProfit = 0;
        for (int val : prices) {
            if (val > bestBuy)
                maxProfit = max(maxProfit, val - bestBuy);
            bestBuy = min(bestBuy, val);
        }
        return maxProfit;
    }
};