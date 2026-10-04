class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;

        for(int i = 1; i < prices.size(); i++) {
            int prevBuy = buy;
            int prevSell = sell;

            // Buy / continue holding
            buy = max(prevBuy, prevSell - prices[i]);

            // Sell / continue not holding
            sell = max(prevSell, prevBuy + prices[i] - fee);
        }

        return sell;
    }
};