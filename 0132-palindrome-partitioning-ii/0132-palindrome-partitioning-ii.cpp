class Solution {
public:
    bool isPalindrome(int i,int j,string& temp){
        while(i<j){
            if(temp[i++]!=temp[j--]) return false;
        }
        return true;
    }
    // int f(int i, string& s, vector<int>& dp){
    //     if(i == s.size()) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int min_cost = INT_MAX;
    //     for(int j=i;j<s.size();j++){
    //         if(isPalindrome(i,j,s)){
    //             int cost = 1+f(j+1,s,dp);
    //             min_cost = min(min_cost,cost);
    //         }
    //     }
    //     return dp[i] = min_cost;
    // }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int min_cost = INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost = 1+dp[j+1];
                    min_cost = min(min_cost,cost);
                }
            }
            dp[i] = min_cost;
        }
        return dp[0] - 1;
    }
};