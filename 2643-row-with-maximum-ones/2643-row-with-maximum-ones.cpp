class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxones=-1;
        int idx=0;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(auto x:mat[i]){
                cnt+=x;
            }
            if(cnt>maxones){
                maxones=cnt;
                idx=i;
            }
        }
        return { idx,maxones};
        
    }
};