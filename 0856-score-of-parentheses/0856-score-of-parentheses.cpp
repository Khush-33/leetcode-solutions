class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0;
        int score=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') depth++;
            else{
                depth--;

                //check prev char for () condtn
                if(s[i-1]=='(') score += 1 << depth; // 2^depth
            }
        }
        return score;
    }
};