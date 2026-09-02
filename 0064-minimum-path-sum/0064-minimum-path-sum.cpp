class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j] = grid[0][0];
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0) up += prev[j];
                    else up += 1e9;
                    if(j>0) left += curr[j-1];
                    else left += 1e9;
                    curr[j] = min(up,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};