class Solution {
public:
    int f(int ind, int n,int buy, vector<int>& prices, int cap, vector<vector<vector<int>>>& dp){
        if(ind == n || cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            int t = -prices[ind] + f(ind+1,n,0,prices,cap,dp);
            int nt = 0+f(ind+1,n,1,prices,cap,dp);
            return dp[ind][buy][cap] = max(t,nt);
        }
        else{
            int t = prices[ind] + f(ind+1,n,1,prices,cap-1,dp);
            int nt = f(ind+1,n,0,prices,cap,dp);
            return dp[ind][buy][cap] = max(t,nt);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> ahead(2, vector<int>(3,0)), curr(2, vector<int>(3,0));
        // for(int ind=0;ind<prices.size();ind++){
        //     for(int buy=0;buy<2;buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // for(int buy = 0;buy<2;buy++){
        //     for(int cap=0;cap<3;cap++){
        //         dp[prices.size()-1][buy][cap] = 0;
        //     }
        // }
        for(int ind = prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        int t = -prices[ind] + ahead[0][cap];
                        int nt = 0+ahead[1][cap];
                        curr[buy][cap] = max(t,nt);
                    }
                    else{
                        int t = prices[ind] + ahead[1][cap-1];
                        int nt = ahead[0][cap];
                        curr[buy][cap] = max(t,nt);
                    }
                }
            }
            ahead =curr;
        }

        return ahead[1][2];
    }
};