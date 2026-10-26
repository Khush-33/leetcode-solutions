class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[magazine[i]]++;
        }
        for(char c : ransomNote){
            if(mpp[c]<=0) return false;
            else{
                mpp[c]--;
            }
        }
        return true;
    }
};