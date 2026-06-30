class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        int pair = 0;
        for(char ch : s){
            if(ch == '|') pair++;
            if(ch == '*' && pair%2==0) ans++;
        }
        return ans;
    }
};