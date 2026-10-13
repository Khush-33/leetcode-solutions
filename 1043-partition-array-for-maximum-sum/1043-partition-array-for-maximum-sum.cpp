class Solution {
public:
    // int f(int ind, vector<int>& arr, int k, vector<int>& dp){
    //     int n=arr.size();
    //     if(ind == n) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int len=0;
    //     int maxi=INT_MIN, maxAns=INT_MIN;
    //     for(int j = ind; j < min(n, ind+k);j++){
    //         len++;
    //         maxi = max(maxi, arr[j]);
    //         int ans = maxi*len + f(j+1,arr,k,dp);
    //         maxAns = max(maxAns,ans);
    //     }
    //     return dp[ind] = maxAns;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int len=0;
            int maxi=INT_MIN, maxAns=INT_MIN;
            for(int j = ind; j < min(n, ind+k);j++){
                len++;
                maxi = max(maxi, arr[j]);
                int ans = maxi*len + dp[j+1];
                maxAns = max(maxAns,ans);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};