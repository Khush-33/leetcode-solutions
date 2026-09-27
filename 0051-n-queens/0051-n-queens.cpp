class Solution {
public:
    
    void solveQ(int col, vector<string>& board,  vector<int>& l,vector<int>& ud,vector<int>& ld, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(l[row]==0 && ud[n-1 + col - row]==0 && ld[row+col] == 0){
                board[row][col] = 'Q';
                l[row] = 1;
                ud[n-1+col-row] = 1;
                ld[row+col] = 1;
                solveQ(col+1,board,l,ud,ld,ans,n);
                board[row][col] = '.';
                l[row] = 0;
                ud[n-1+col-row] = 0;
                ld[row+col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> l(n,0), ud(2*n-1,0), ld(2*n-1);
        solveQ(0, board,l,ud,ld, ans, n);
        return ans;
    }
};