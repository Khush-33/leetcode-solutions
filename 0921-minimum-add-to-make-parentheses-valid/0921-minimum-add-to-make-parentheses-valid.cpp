class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top()==')'){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='(') st.push(s[i]);
            else{
                if(st.top()=='(') st.pop();
            }
        }
        int cnt=0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};