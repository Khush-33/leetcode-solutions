class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int open=0, close=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==')') close++;
            if(s[i]=='(') open++;
            if(open == close){
                ans = max(ans,close*2);
            }
            if(close>open){
                open=0;
                close=0;
            }
        }
        open = close = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') close++;
            if(s[i]=='(') open++;
            if(open == close){
                ans = max(ans,close*2);
            }
            if(close<open){
                open=0;
                close=0;
            }
        }
        return ans;
    }
};