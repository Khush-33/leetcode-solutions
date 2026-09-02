class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m, vector<int>(m,0));
        for(int k=0;k<m;k++){
            dp[m-1][k] = triangle[m-1][k];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = dp[i+1][j] + triangle[i][j];
                int dg = dp[i+1][j+1] + triangle[i][j];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};