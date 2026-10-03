class Solution {
public:
    int f(int ind, int k1, int k, vector<int>& prices,
          vector<vector<int>>& dp) {
        if (ind == prices.size() || k1 == k * 2)
            return 0;
        if (dp[ind][k1] != -1)
            return dp[ind][k1];
        if (k1 % 2 == 0) {
            return dp[ind][k1] =
                       max(-prices[ind] + f(ind + 1, k1 + 1, k, prices, dp),
                           f(ind + 1, k1, k, prices, dp));
        } else {
            return dp[ind][k1] =
                       max(prices[ind] + f(ind + 1, k1 + 1, k, prices, dp),
                           f(ind + 1, k1, k, prices, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2*k+1,0);
        vector<int> curr(2*k+1,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int k1=2*k-1;k1>=0;k1--){
                if (k1 % 2 == 0) {
                    curr[k1]=max(-prices[ind] + ahead[k1+1],ahead[k1]);
                } else {
                    curr[k1]=max(prices[ind] + ahead[k1+1],ahead[k1]);
                }
            }
            ahead = curr;
        }
        return ahead[0];
    }
};