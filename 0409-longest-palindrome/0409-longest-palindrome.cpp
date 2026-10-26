class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++) mpp[s[i]]++;
        int res=0;
        bool odd=false;
        for(auto i:mpp){
            int val = i.second;
            if(val%2==0) res+=val;
            else odd = true;
        }
        if(odd == false) return res;
        for(auto i:mpp){
            int val = i.second;
            if(val%2==1) res += val-1;
        }
        return res+1;
    }
};