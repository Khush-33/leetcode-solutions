class Solution {
public:
    void f(int n, vector<string> &ans, int open, int close, string curr){
        if(curr.size()==n*2){
            ans.push_back(curr);
            return;
        }
        if(open<n) f(n,ans,open+1,close,curr+"(");
        if(close<open) f(n,ans,open,close+1,curr+")"); 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        f(n,ans,0,0,"");
        return ans;
    }
};