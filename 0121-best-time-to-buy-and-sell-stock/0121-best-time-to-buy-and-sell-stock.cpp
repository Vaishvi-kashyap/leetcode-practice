class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], maxSum = 0;
        for (int val : prices) {
            bestBuy = min(bestBuy, val);
            if (val > bestBuy)
                maxSum = max(maxSum, val - bestBuy);
        }
        return maxSum;
    }
};