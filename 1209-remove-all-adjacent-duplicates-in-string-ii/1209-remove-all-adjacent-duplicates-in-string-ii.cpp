class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(st.empty()){
                st.push({ch,1});
            }
            else if(st.top().first != ch){
                st.push({ch,1});
            }
            else if(st.top().second<k-1){
                st.top().second++;
            }
            else st.pop();
        }
        string res="";
        while (!st.empty()) {
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};